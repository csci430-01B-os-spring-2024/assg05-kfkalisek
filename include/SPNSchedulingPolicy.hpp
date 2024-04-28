/** @file SPNSchedulingPolicy.hpp
 * @brief SPNSchedulingPolicy class API/Includes
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Fall 2019
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for our SPNSchedulingPolicy class.
 * This is a concrete child class implementation of a
 * SchedulingPolicy strategy.
 */
#ifndef SPNSCHEDULING_POLICY_HPP
#define SPNSCHEDULING_POLICY_HPP

#include "SchedulingPolicy.hpp"
#include <queue>
#include <string>

// forward declaration needed for circular references
class SchedulingSystem;

using namespace std;

/// @brief More descriptive name for things that hold process
///   identifiers.  We use int values for our processes identifiers
///   in this simulation.
typedef int Pid;

/** @class SPNSchedulingPolicy
 * @brief SPNSchedulingPolicy abstract base class
 *
 * This class defines the interface or API for the SPN (Shortest Process Next)
 * scheduling policy. A concrete subclass of this class is expected to implement
 * the defined interface.
 */
class SPNSchedulingPolicy : public SchedulingPolicy
{
private:
  /// @brief The ready queue for the FCFS policy, keeps track of
  ///   which process arrived first for dispatching.
  queue<Pid> readyQueue;
  Pid shortestProcess;
  double shortestTime;

public:
  SPNSchedulingPolicy();

  // virtual function, concrete subclasses can override if needed
  virtual ~SPNSchedulingPolicy();

  // virtual functions, concrete subclasses must implement
  void newProcess(Pid pid);
  Pid dispatch();
  bool preempt();
  void resetPolicy();
  double getExpectedProcessingTime(Pid pid);
};

#endif // SPNSCHEDULING_POLICY_HPP
