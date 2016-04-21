// Copyright 2016 Robot Locomotion Group @ CSAIL. All rights reserved.
// This file is generated by a script.  Do not edit!
// See drake/examples/SimpleCar/lcm_vector_gen.py.
#pragma once

#include <stdexcept>
#include <string>
#include <Eigen/Core>

#include "lcmtypes/drake/lcmt_simple_car_state_t.hpp"

namespace Drake {

template <typename ScalarType = double>
class SimpleCarState {  // models the Drake::LCMVector concept
 public:
  typedef drake::lcmt_simple_car_state_t LCMMessageType;
  static std::string channel() { return "SIMPLE_CAR_STATE"; }
  static const int RowsAtCompileTime = 4;
  typedef Eigen::Matrix<ScalarType, RowsAtCompileTime, 1> EigenType;

  SimpleCarState() {}

  template <typename Derived>
  // NOLINTNEXTLINE(runtime/explicit)
  SimpleCarState(const Eigen::MatrixBase<Derived>& initial)
      : x(initial(0)),        // BR
        y(initial(1)),        // BR
        heading(initial(2)),  // BR
        velocity(initial(3)) {}

  template <typename Derived>
  SimpleCarState& operator=(const Eigen::MatrixBase<Derived>& rhs) {
    x = rhs(0);
    y = rhs(1);
    heading = rhs(2);
    velocity = rhs(3);
    return *this;
  }

  friend EigenType toEigen(const SimpleCarState<ScalarType>& vec) {
    EigenType result;
    result << vec.x, vec.y, vec.heading, vec.velocity;
    return result;
  }

  friend std::string getCoordinateName(const SimpleCarState<ScalarType>& vec,
                                       unsigned int index) {
    switch (index) {
      case 0:
        return "x";
      case 1:
        return "y";
      case 2:
        return "heading";
      case 3:
        return "velocity";
    }
    throw std::domain_error("unknown coordinate index");
  }

  ScalarType x = 0;
  ScalarType y = 0;
  ScalarType heading = 0;
  ScalarType velocity = 0;
};

template <typename ScalarType>
bool encode(const double& t, const SimpleCarState<ScalarType>& wrap,
            // NOLINTNEXTLINE(runtime/references)
            drake::lcmt_simple_car_state_t& msg) {
  msg.timestamp = static_cast<int64_t>(t * 1000);
  msg.x = wrap.x;
  msg.y = wrap.y;
  msg.heading = wrap.heading;
  msg.velocity = wrap.velocity;
  return true;
}

template <typename ScalarType>
bool decode(const drake::lcmt_simple_car_state_t& msg,
            // NOLINTNEXTLINE(runtime/references)
            double& t,
            // NOLINTNEXTLINE(runtime/references)
            SimpleCarState<ScalarType>& wrap) {
  t = static_cast<double>(msg.timestamp) / 1000.0;
  wrap.x = msg.x;
  wrap.y = msg.y;
  wrap.heading = msg.heading;
  wrap.velocity = msg.velocity;
  return true;
}

}  // namespace Drake