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
    local scenario="$1"
    local results_dir="$2"
    filefilter="$results_dir/Study_WFullShaping_${scenario}"
    echo $filefilter
}

# Function to export all needed statistics for one scenario
export_stats_for_scenario() {
    local scenario="$1"
    local results_dir="$2"
    local outdir="$3"

    # Time parameters
    MIN_TIME_INIT=0
    MAX_TIME_INIT=0.2
    MIN_TIME_SCENARIO=0
    MAX_TIME_SCENARIO=10

    # Statistic names
    STAT_IDLESLOPE="reservedBandwidth:vector"
    STAT_DELAY="delay:vector"
    STAT_LENGTH="length:vector"
    STAT_LATENCY="rxLatency:vector"
    STAT_REMOTES="connectedRemotes:vector"
    STAT_EP_CREATED="endpointCreatedAt:sum" ## scalar!!

    # Module filters
    MODULE_Switch="**switch**"
    MODULE_Service="**services[*]**"
    MODULE_PUB_EP="**.middleware.publisherEndpoints[*]"
    MODULE_SUB_EP="**.middleware.subscriberEndpoints[*]"

    # Outfile Suffix
    OUT_IDLESLOPE="_SwitchIdleSlopes.json"
    OUT_SUB_CREATED="_SubCreated.json"
    OUT_PUB_CREATED="_PubCreated.json"
    OUT_PUB_REMOTES="_PubRemotes.json"
    OUT_SUB_REMOTES="_SubRemotes.json"
    OUT_QUEUE_DELAY="_SwitchQueueDelay.json"
    OUT_QUEUE_LEN="_SwitchQueueLength.json"
    OUT_E2E_DELAY="_E2EDelay.json"

    study="$scenario"
    filefilter=$(getFileFilter "$scenario" "$results_dir")

    # Export statistics
    # switch idle slopes
    export_stat "$MODULE_Switch" "$STAT_IDLESLOPE" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_IDLESLOPE" "$filefilter"
    # pub created at
    export_stat "$MODULE_PUB_EP" "$STAT_EP_CREATED" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_PUB_CREATED" "$filefilter"
    # pub remotes
    export_stat "$MODULE_PUB_EP" "$STAT_REMOTES" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_PUB_REMOTES" "$filefilter"
    # sub created at
    export_stat "$MODULE_SUB_EP" "$STAT_EP_CREATED" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_SUB_CREATED" "$filefilter"
    # sub remotes
    export_stat "$MODULE_SUB_EP" "$STAT_REMOTES" "$MIN_TIME_INIT" "$MAX_TIME_INIT" "$outdir/$study$OUT_SUB_REMOTES" "$filefilter"
    # switch queue delay
    export_stat "$MODULE_Switch" "$STAT_DELAY" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_QUEUE_DELAY" "$filefilter"
    # switch queue length
    export_stat "$MODULE_Switch" "$STAT_LENGTH" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_QUEUE_LEN" "$filefilter"
    # e2e delay
    export_stat "$MODULE_Service" "$STAT_LATENCY" "$MIN_TIME_SCENARIO" "$MAX_TIME_SCENARIO" "$outdir/$study$OUT_E2E_DELAY" "$filefilter"
}

base_dir=$(pwd)
results_dir="results"
outdir="analysis"
scenarios=("SI_NoSDScatter" "CMI_B250" "CMI_B500" "CMI_B1000" "SI-" "Dyrectsn")

# iterate over is schemes
for scenario in "${scenarios[@]}" ; do
    # check if a file containing the scenario string in the filename in the input directory
    filefilter=$(getFileFilter "$scenario" "$results_dir")
    count=$(ls $results_dir | grep "$scenario" | wc -l)
    if [ $count -eq 0 ]; then
        echo skipping $scenario
        continue
    fi            
    export_stats_for_scenario "$scenario" "$results_dir" "$outdir" &
done

# wait for all background processes to finish
wait

