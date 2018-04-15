#include "Process.h"

Process::Process() {
  
}
Process::Process (std::vector<int> input) {
  resourcesCount = input;
}

bool Process::isExecutable(std::vector<int> allottableProcesses) {
  for(int i = 0; i < resourcesCount.size(); i++) {
    if (allottableProcesses.at(i) < resourcesRequested.at(i)) {
      break;
    }
    if (i + 1 == resourcesCount.size()) {
      return true;
    }
  }
  return false;
}

int Process::getResourceAtIndex(int index) { return resourcesCount.at(index); }
void Process::setResourceAtIndex(int index, int value) { resourcesCount.at(index) = value; }

int Process::getResourceRequestedAtIndex(int index) { return resourcesRequested.at(index); }
void Process::setResourcesRequested(std::vector<int> requests) { resourcesRequested = requests; }

void Process::printProcess() {
  for (int i = 0; i < resourcesCount.size(); i++) {
    std::cout << resourcesCount.at(i) << " ";
  }
  std::cout << std::endl;
}

void Process::printProcessRequests() {
  for (int i = 0; i < resourcesRequested.size(); i++) {
    std::cout << resourcesRequested.at(i) << " ";
  }
  std::cout << std::endl;
}