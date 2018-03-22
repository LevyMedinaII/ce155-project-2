#include <iostream>
#include <vector>
#include <string>
#include "Process.h"

class ProcessBlock {
  int processCount;
  std::string command;
  std::vector<Process> processes;
  std::vector<Process> readyQueue;
  std::vector<Process> preemptedQueue;
  std::vector<Process> waitingQueue;
  Process runningProcess;
  int currentRunTime;
  float cpuUtilizationSlack;
  float cpuUtilization;
  float thoroughput;
  float waitingTime;
  float turnaroundTime;

  int quantumTime;
  
  public:
    // Constructors
    ProcessBlock(int, std::string);

    // Getters and Setters
    int getProcessCount();
    int getNextArrivalTimeJob(int, int);
    int getNextArrivalTimePriority(int, int);
    int getEarliestArrivalTimeFromReady();
    std::string getCommand();
    int getQuantumTime();
    void setQuantumTime(int);

    // Misc Methods
    void addProcessToBlock(Process);
    void pushAllToReady();
    void pushAllApplicableToReady(int);
    void moveProcess(std::vector<Process>, std::vector<Process>, int);
    void printSummary(int, int, int, double, int);
    Process getEarliestArrivalProcess();
    Process popEarliestArrivalProcessFromReady();
    Process popLeastBurstTimeProcessFromReady();
    Process popHighestPriorityProcessFromReady(int);
    Process executeLeastTimeProcessFromReady(int);
    Process findLeastTimeProcessFromReady();
    Process executeRoundRobin(int);
    std::string doRoundRobin();
    Process getHighestPriority();
    std::string doFirstComeFirstServe();
    std::string doShortestJobFirst();
    std::string doPriority();
    std::string doShortestRemainingTimeFirst();
    void execute();

    void printBlock();
};