/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef INCLUDE__RMF_WORKCELL_ROS2__WORKCELLADAPTER_HPP
#define INCLUDE__RMF_WORKCELL_ROS2__WORKCELLADAPTER_HPP

#include <deque>
#include <mutex>
#include <atomic>
#include <chrono>
#include <future>
#include <memory>
#include <thread>
#include <iostream>
#include <functional>
#include <unordered_map>

#include <rclcpp/rclcpp.hpp>
#include <rmf_workcell_msgs/msg/workcell_state.hpp>
#include <rmf_workcell_msgs/msg/workcell_configuration.hpp>
#include <rmf_workcell_msgs/msg/workcell_result_header.hpp>
#include <rmf_workcell_msgs/msg/workcell_request_header.hpp>

namespace rmf_workcell
{
namespace adapter
{

struct WorkcellAdapterConfig
{
  std::string node_name;
  std::string guid;
  std::string type;
  std::string state_topic;
  std::string config_topic;
  std::string request_topic;
  std::string result_topic;
  rmf_workcell_msgs::msg::WorkcellConfiguration config;
  rmw_qos_profile_t qos = rmw_qos_profile_default;
};

template<
    typename RequestMsg,
    typename ResultMsg,
    typename BlockingReturnType = bool>
class WorkcellAdapter : public rclcpp::Node
{
public:

  using SharedPtr = std::shared_ptr<WorkcellAdapter>;

  static SharedPtr make(const WorkcellAdapterConfig& _config)
  {
    SharedPtr adapter(_config);

    return adapter;
  }

  ~WorkcellAdapter()
  {}

  void start(WorkcellAdapterComponents _components)
  {
    
  }

  struct WorkcellAdapterComponents
  {
    rclcpp::
  };

private:

  WorkcellAdapterConfig config;

  rclcpp::Clock ros_clock;
  rclcpp::TimerBase::SharedPtr workcell_state_pub_timer;
  rclcpp::TimerBase::SharedPtr workcell_config_pub_timer;
  rclcpp::Publisher<rmf_msgs::msg::WorkcellState>::SharedPtr 
      workcell_state_pub;
  rclcpp::Publisher<rmf_msgs::msg::WorkcellConfiguration>::SharedPtr 
      workcell_config_pub;

  void 


  WorkcellAdapter(const WorkcellAdapterConfig& _config) :
    config(_config)
  {
    ros_clock = rclcpp::Clock();

    using namespace std::chrono_literals;

    workcell_state_pub_timer = create_wall_timer(
        30000ms, std::bind(&WorkcellAdapter::publish_state, this));

    workcell_config_pub_timer = create_wall_timer(
        30000ms, std::bind(&WorkcellAdapter::publish_config, this));

    workcell_state_pub_timer = this->create_wall_timer

  }

};

} // namespace adapter
} // namespace rmf_workcell

#endif // INCLUDE__RMF_WORKCELL_ROS2__WORKCELLADAPTER_HPP
