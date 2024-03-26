#!/bin/bash

declare -a pids=()

add_command() {
    $1 &
    pids+=("$!")
}

wait_for_completion() {
    for pid in "${pids[@]}"; do
        wait "$pid"
    done
    exit 0
}

add_command "wget https://code.jquery.com/jquery-3.6.0.min.js"
add_command "ping -c 5 enauczanie.pg.edu.pl"
add_command "ls -lrA"
add_command "sleep 10"

wait_for_completion
