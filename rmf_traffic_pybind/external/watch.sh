#!/bin/bash
trigger_func()
{
    cd /home/bhan/dev/rmf_core && colcon build --packages-select rmf_traffic_pybind && pytest install/rmf_traffic_pybind/test
}

if [ -z "$1" ]
  then
    echo "Enter path of file to watch!"
    exit
fi

### Initialize environment variables here ###
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/bhan/dev/rmf_core/install/rmf_traffic/lib
### Initialize environment variables here ###
while :
do
    inotifywait -e close_write $1 |  trigger_func
done