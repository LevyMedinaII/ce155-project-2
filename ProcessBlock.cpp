#include "ProcessBlock.h"

ProcessBlock::ProcessBlock (int n, std::string c) {
  processCount = n;
  command = c;
}

void ProcessBlock::setProcessCount(int n) { processCount = n; }
void ProcessBlock::setCommand(std::string c) { command = c; }

int ProcessBlock::getProcessCount() { return processCount; }
std::string ProcessBlock::getCommand() { return command; }


void ProcessBlock::pushProcess(Process p) {
  if (processes.size() < processCount ) {
    processes.push_back(p);
  } else {
    std::cout << "Error: Maximum allowable processes for block already reached." << std::endl;
  }
}