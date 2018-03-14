#include <iostream>
#include <vector>
#include "Process.h"

class ProcessBlock {
  int processCount;
  std::string command;
  std::vector<Process> processes;
  public:
    ProcessBlock(int, std::string);

    int getProcessCount();
    std::string getCommand();

    void setProcessCount(int);
    void setCommand(std::string);
    void pushProcess(Process);
};