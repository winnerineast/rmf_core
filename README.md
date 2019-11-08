# rmf\_core bindings
An attempt to create python bindings for `rmf_core`.

## How to develop on this repo using Box.cpp as example
* `git clone` this repo into the `add_bindings` branch
* `cd rmf_core`
* `git submodule init && git submodule update` to download dependencies
* `colcon build --packages-up-to rmf_traffic_pybind`, remember to source ROS2
* Modify `LD_LIBRARY_PATH` in `rmf_traffic_pybind/external/watch.sh` to the path of `librmf_traffic.so`
* `./rmf_traffic_pybind/external/watch.sh ./rmf_traffic_pybind/src/geometry/Box.cpp`
* Modify `Box.cpp` in another terminal
* Save `Box.cpp`. This will trigger a rebuild and run all tests in `rmf_traffic_pybind/test`