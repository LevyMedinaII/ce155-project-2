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

Process ProcessBlock::getEarliestArrivalProcess() {
  Process earliestProcess = processes.at(0);
  int earliestTime = processes.at(0).getArrivalTime();

  for (int i = 1; i < processes.size(); i++ ) {
    if (processes.at(i).getArrivalTime() < earliestTime) {
      earliestTime = processes.at(i).getArrivalTime();
      earliestProcess = processes.at(i);
    }
  }

  return earliestProcess;
}

int ProcessBlock::getEarliestArrivalProcessIndex() {
  int earliestTime = processes.at(0).getArrivalTime();
  int earliestProcessIndex = 0;
  for (int i = 1; i < processes.size(); i++ ) {
    if (processes.at(i).getArrivalTime() < earliestTime) {
      earliestTime = processes.at(i).getArrivalTime();
      earliestProcessIndex = i;
    }
  }
  return earliestProcessIndex + 1;
}

std::string ProcessBlock::doFirstComeFirstServe() {
  std::string output = "";
  Process currentProcess;
  int currentRunTime;
  int currentProcessIndex;
  std::string execution;

  while (processes.size() > 0 ) {
    currentProcess = getEarliestArrivalProcess();
    currentRunTime = currentProcess.getArrivalTime();
    currentProcessIndex = getEarliestArrivalProcessIndex();

    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(currentProcessIndex);

  }


  return output;
}


void ProcessBlock::execute() {
  if (command == "FCFS") {

  }
}