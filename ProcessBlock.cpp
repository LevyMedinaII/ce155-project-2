#include "ProcessBlock.h"

// Constructor
ProcessBlock::ProcessBlock (int n, std::string c) {
  processCount = n;
  command = c;
}

// Getters
int ProcessBlock::getProcessCount() { return processCount; }
std::string ProcessBlock::getCommand() { return command; }

// Add a process to the processes vector
void ProcessBlock::addProcessToBlock(Process p) {
  if (processes.size() < processCount ) {
    processes.push_back(p);
  } else {
    std::cout << "Error: Maximum allowable readyQueue for block already reached." << std::endl;
  }
}

// Push all processes in block to the ready queue
// Used in FCFS
void ProcessBlock::pushAllToReady() {
  for (int i = 0; i < processes.size(); i++) {
    readyQueue.push_back(processes.at(i));
  }
  processes.clear();
}

// Push all processes given elapsed time to the ready queue
// Used in SRTF
void ProcessBlock::pushAllApplicableToReady(int time) {
  for (int i = 0; i < processes.size(); i++) {
    if (readyQueue.at(i).getArrivalTime() <= time) {
      readyQueue.push_back(processes.at(i));
      processes.erase(processes.begin()+i);
      i--;
    }
  }
}

// Pop the earliest process from the queue
Process ProcessBlock::popEarliestArrivalProcess() {
  Process earliestProcess = readyQueue.at(0);
  int earliestTime = readyQueue.at(0).getArrivalTime();
  int index = 0;

  for (int i = 1; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getArrivalTime() < earliestTime) {
      earliestTime = readyQueue.at(i).getArrivalTime();
      earliestProcess = readyQueue.at(i);
      index = i;
    }
  }
  readyQueue.erase(readyQueue.begin() + index);
  return earliestProcess;
}

// Perform FCFS
std::string ProcessBlock::doFirstComeFirstServe() {
  std::string output = "";
  pushAllToReady();
  runningProcess = popEarliestArrivalProcess();
  int currentRunTime = runningProcess.getArrivalTime();
  
  while (readyQueue.size() >= 0 ) {
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getBurstTime()) + "X";
    output += "\n";

    currentRunTime += runningProcess.getBurstTime();

    if (readyQueue.size() == 0) {
      break;
    }
    runningProcess = popEarliestArrivalProcess();
    if (currentRunTime < runningProcess.getArrivalTime()) {
      currentRunTime = runningProcess.getArrivalTime();
    }
  }

  std::cout << output;

  return output;
}

// execute based on innate command
void ProcessBlock::execute() {
  if (command == "FCFS") {
    std::cout << "FCFS:" << std::endl;
    doFirstComeFirstServe();
  } else if (command == "SJF") {
    std::cout << "FCFS:" << std::endl;
    
  } else if (command == "SRTF") {
    std::cout << "SRTF:" << std::endl;
  }
  std::cout << "------------------" << std::endl;
}

//Print Process Block
void ProcessBlock::printBlock() {
  std::cout << "==================" << std::endl;
  std::cout << "#: " << processCount << std::endl << "CMD: " << command << std::endl;
  std::cout << "------------------" << std::endl;
  for (int i = 0; i < processes.size(); i++) {
    std::cout
      << processes.at(i).getArrivalTime() << "\t"
      << processes.at(i).getBurstTime() << "\t"
      << processes.at(i).getPriority() << std::endl;
  }
}