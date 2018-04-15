#include "Process.h"

Process::Process() {
  
}
Process::Process (std::vector<int> input) {
  resourcesCount = input;
}


int Process::getResourceAtIndex(int index) { return resourcesCount.at(index); }
int Process::setResourceAtIndex(int index, int value) { resourcesCount.at(index) = value; }
void Process::printProcess() {
  for (int i = 0; i < resourcesCount.size(); i++) {
    std::cout << resourcesCount.at(i) << " ";
  }
  std::cout << std::endl;
}
// int Process::getArrivalTime() { return arrivalTime; }
// int Process::getBurstTime() { return burstTime; }
// int Process::getPriority() { return priority; }
// int Process::getElapsedTime() { return elapsedTime; }
// int Process::getLastExecuteTime() { return lastExecuteTime; }

// void Process::setIndex(int i) { index = i; }
// void Process::setArrivalTime(int arrival) { arrivalTime = arrival; }
// void Process::setBurstTime(int burst) { burstTime = burst; }
// void Process::setPriority(int p) { priority = p; }
// void Process::setElapsedTime(int el) { elapsedTime = el; }
// void Process::setLastExecuteTime(int ex) { lastExecuteTime = ex; }
