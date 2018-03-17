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
  std::vector<Process> runningQueue;
  
  public:
    ProcessBlock(int, std::string);

    int getProcessCount();
    std::string getCommand();
    Process getEarliestArrivalProcess();
    int getEarliestArrivalProcessIndex();

    void setProcessCount(int);
    void setCommand(std::string);
    void pushProcess(Process);

    std::string doFirstComeFirstServe();

    void execute();
};