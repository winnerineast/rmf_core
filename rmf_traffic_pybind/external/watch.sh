#!/bin/bash
trigger_func()
{
    cd /home/bhan/dev/rmf_core && colcon build --packages-select rmf_traffic_pybind && pytest rmf_traffic_pybind/test
}

if [ -z "$1" ]
  then
    echo "Enter path of file to watch!"
    exit
fi

while :
do
    inotifywait -e close_write $1 |  trigger_func
done