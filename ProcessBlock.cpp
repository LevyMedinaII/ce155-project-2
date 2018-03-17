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
  if (readyQueue.size() < processCount ) {
    processes.push_back(p);
  } else {
    std::cout << "Error: Maximum allowable readyQueue for block already reached." << std::endl;
  }
}

// Push all processes in block to the ready queue
void ProcessBlock::pushAllToReady() {
  for (int i = 0; i < processes.size(); i++) {
    readyQueue.push_back(processes.at(i));
  }
}

// Pop the earliest process from the queue
Process ProcessBlock::popEarliestArrivalProcess(std::vector<Process> queue) {
  Process earliestProcess = queue.at(0);
  int earliestTime = queue.at(0).getArrivalTime();
  int index = 0;

  for (int i = 1; i < queue.size(); i++ ) {
    if (queue.at(i).getArrivalTime() < earliestTime) {
      earliestTime = queue.at(i).getArrivalTime();
      earliestProcess = queue.at(i);
      index = i;
    }
  }
  queue.erase(queue.begin() + i);
  return earliestProcess;
}

// Perform FCFS
std::string ProcessBlock::doFirstComeFirstServe() {
  std::string output = "";
  runningProcess = popEarliestArrivalProcess(readyQueue);
  int currentRunTime = runningProcess.getArrivalTime();

  while (readyQueue.size() >= 0 ) {
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getBurstTime()) + "X";
    output += "\n";

    currentRunTime += runningProcess.getBurstTime();
    currentProcess = getEarliestArrivalProcess();
    if (currentRunTime < currentProcess.getArrivalTime()) {
      currentRunTime = currentProcess.getArrivalTime();
    }

    runningProcess = popEarliestArrivalProcess(readyQueue);
  }

  std::cout << output << std::endl;

  return output;
}

// execute based on innate command
void ProcessBlock::execute() {
  if (command == "FCFS") {
    doFirstComeFirstServe();
  } else if (command == "SJP") {
    
  }
}

//Print Process Block
void ProcessBlock::printBlock() {
  cout << "#: " << processCount << " | CMD: " << command;
  for (int i = 0; i < processes.size(); i++) {
    cout
      << processes.at(i).getArrivalTime() << "\t"
      << processes.at(i).getBurstTime() << "\t"
      << processes.at(i).getPriority() << endl;
  }
}