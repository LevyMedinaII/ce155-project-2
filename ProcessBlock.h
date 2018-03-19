#include <iostream>
#include <vector>
#include <string>
#include "Process.h"

class ProcessBlock {
  int processCount;
  std::string command;
  std::vector<Process> processes;
  std::vector<Process> readyQueue;
  std::vector<Process> waitingQueue;
  Process runningProcess;
  
  public:
    // Constructors
    ProcessBlock(int, std::string);

    // Getters and Setters
    int getProcessCount();
    std::string getCommand();

    // Misc Methods
    void addProcessToBlock(Process);
    void pushAllToReady();
    void pushAllApplicableToReady(int);
    void moveProcess(std::vector<Process>, std::vector<Process>, int);
    Process getEarliestArrivalProcess();
    Process popEarliestArrivalProcessFromReady();
    Process popLeastBurstTimeProcessFromReady();
    std::string doFirstComeFirstServe();
    std::string doShortestJobFirst();
    void execute();

    void printBlock();
};