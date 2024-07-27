#!/bin/bash
export PATH=/home/timo/omnet/omnetpp-6.0.2/bin:$PATH

# Function to run scavetool
run_scavetool() {
    local filter="$1"
    local time="$2"
    local outfile="$3"
    local filefilter="$4"

    command="opp_scavetool export -F JSON "

    $command -f "$filter" $time -o $outfile "$filefilter*.sca" "$filefilter*.vec"
}

# Function to export one statistics with scavetool
export_stat() {
    local module="$1"
    local stat="$2"
    local start_time="$3"
    local end_time="$4"
    local outfile="$5"
    local filefilter="$6"

    time="--start-time $start_time --end-time $end_time"
    filter='module=~ "'$module'" AND name=~ "'$stat'"'
    run_scavetool "$filter" "$time" "$outfile" "$filefilter"
}

# Function to get file filter
getFileFilter() {
    local isScheme="$1"
    local ctScheme="$2"
    local results_dir="$3"

    seperator="-"
    # check if isScheme is "NC"
    if [ "$isScheme" == "NC" ]; then
        seperator="_"
    fi
    filefilter="$results_dir/Study_${isScheme}_${ctScheme}${seperator}IL"
    echo $filefilter
}

# Function to export all needed statistics for one scenario
export_stats_for_scenario() {
    local isScheme="$1"
    local ctScheme="$2"
    local results_dir="$3"
    local outdir="$4"

    # Time parameters
    MIN_TIME_INIT=0
    MAX_TIME_INIT=0.2
    MIN_TIME_SCENARIO=0.1
    MAX_TIME_SCENARIO=0.3

    # Statistic names
    STAT_IDLESLOPE="reservedBandwidth:vector"
    STAT_DELAY="delay:vector"
    STAT_LENGTH="length:vector"
    STAT_LATENCY="rxLatency:vector"
    STAT_REMOTES="connectedRemotes:vector"
    STAT_EP_CREATED="endpointCreatedAt:sum" ## scalar!!

    # Module filters
    MODULE_AGG_TSA="**.aggregateSwitch.etherMAC[0].**.transmissionSelectionAlgorithm[7]"
    MODULE_STAGE_TSA="**.stageSwitch[*].etherMAC[1].**.transmissionSelectionAlgorithm[7]"
    MODULE_AGG_QUEUE="**.aggregateSwitch.etherMAC[0].**.queue[7]"
    MODULE_SINK="**.sink.services[*]"
    MODULE_PUB_EP="**.talkerSrc[*].middleware.publisherEndpoints[*]"
    MODULE_SUB_EP="**.sink.middleware.subscriberEndpoints[*]"

    # Outfile Suffix
    OUT_AGG_IDLESLOPE="_AggregateIdleSlopes.json"
    OUT_STAGE_IDLESLOPE="_StageIdleSlopes.json"
    OUT_SINK_CREATED="_SinkCreated.json"
    OUT_TALKER_CREATED="_TalkerCreated.json"
    OUT_TALKER_REMOTES="_TalkerRemotes.json"
    OUT_AGG_DELAY="_AggregateDelay.json"
    OUT_AGG_QUEUE="_AggregateQueue.json"
    OUT_SINK_DELAY="_SinkDelay.json"

    
    study=$isScheme"_"$ctScheme
    filefilter=$(getFileFilter "$isScheme" "$ctScheme" "$results_dir")

    # Export statistics
    # aggregate switch reserved bandwidth
    export_stat "$MODULE_AGG_TSA" "$STAT_IDLESLOPE" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_AGG_IDLESLOPE" "$filefilter"
    # stage switch reserved bandwidth
    export_stat "$MODULE_STAGE_TSA" "$STAT_IDLESLOPE" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_STAGE_IDLESLOPE" "$filefilter"
    # sink created
    export_stat "$MODULE_SUB_EP" "$STAT_EP_CREATED" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_SINK_CREATED" "$filefilter"
    # talker created
    export_stat "$MODULE_PUB_EP" "$STAT_EP_CREATED" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_TALKER_CREATED" "$filefilter"
    # talker remotes
    export_stat "$MODULE_PUB_EP" "$STAT_REMOTES" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_TALKER_REMOTES" "$filefilter"
    # aggregate switch queue delay
    export_stat "$MODULE_AGG_QUEUE" "$STAT_DELAY" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_AGG_DELAY" "$filefilter"
    # aggregate switch queue length
    export_stat "$MODULE_AGG_QUEUE" "$STAT_LENGTH" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_AGG_QUEUE" "$filefilter"
    # sink delay
    export_stat "$MODULE_SINK" "$STAT_LATENCY" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_SINK_DELAY" "$filefilter"

}

base_dir=$(pwd)
results_dir="resultsFix"
outdir="analysis/simScave"
# list with is schemes: 'Static', 'CMI', 'SI', 'NC'
# isSchmes=("Static" "CMI" "SI" "NC")
isSchmes=("CMI" "SI" "NC")
# list with ct schemes: 'NoCT', 'BECT', 'PCT', 'NoCT_NoPCTRes', 'BECT_NoPCTRes'
# ctSchemes=("NoCT" "BECT" "PCT" "NoCT_NoPCTRes" "BECT_NoPCTRes")
ctSchemes=("NoCT" "BECT" "PCT")

# iterate over is schemes
for isScheme in "${isSchmes[@]}" ; do
    # iterate over ct schemes
    for ctScheme in "${ctSchemes[@]}" ; do
        # check if a file containing the scenario string in the filename in the input directory
        count=$(ls $results_dir | grep "Study_${isScheme}_${ctScheme}" | wc -l)
        if [ $count -eq 0 ]; then
            echo skipping $isScheme $ctScheme
            continue
        fi            
        export_stats_for_scenario "$isScheme" "$ctScheme" "$results_dir" "$outdir" &
    done
done

# wait for all background processes to finish
wait

