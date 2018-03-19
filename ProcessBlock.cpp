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
// Used in SJF
void ProcessBlock::pushAllApplicableToReady(int time) {
  for (int i = 0; i < processes.size(); i++) {
    if (processes.at(i).getArrivalTime() <= time) {
      readyQueue.push_back(processes.at(i));
      processes.erase(processes.begin()+i);
      i--;
    }
  }
}

// Get the earliest arrival process from processes
Process ProcessBlock::getEarliestArrivalProcess() {
  Process earliestProcess = processes.at(0);
  int earliestTime = processes.at(0).getArrivalTime();
  int index = 0;

  for (int i = 1; i < processes.size(); i++ ) {
    if (processes.at(i).getArrivalTime() < earliestTime) {
      earliestTime = processes.at(i).getArrivalTime();
      earliestProcess = processes.at(i);
      index = i;
    }
  }
  return earliestProcess;
}

// Pop the earliest process from the readyQueue
Process ProcessBlock::popEarliestArrivalProcessFromReady() {
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

// Pop the process with the least burst time from the readyQueue
Process ProcessBlock::popLeastBurstTimeProcessFromReady() {
  Process leastBurstTimeProcess = readyQueue.at(0);
  int leastBurstTime = readyQueue.at(0).getBurstTime();
  int index = 0;
  
  for (int i = 0; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getBurstTime() < leastBurstTime) {
      leastBurstTime = readyQueue.at(i).getBurstTime();
      leastBurstTimeProcess = readyQueue.at(i);
      index = i;
    }
  }

  readyQueue.erase(readyQueue.begin() + index);
  return leastBurstTimeProcess;
}

// Perform FCFS
std::string ProcessBlock::doFirstComeFirstServe() {
  std::string output = "";
  pushAllToReady();
  runningProcess = popEarliestArrivalProcessFromReady();
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
    runningProcess = popEarliestArrivalProcessFromReady();
    if (currentRunTime < runningProcess.getArrivalTime()) {
      currentRunTime = runningProcess.getArrivalTime();
    }
  }

  std::cout << output;

  return output;
}

// Perform SJF
std::string ProcessBlock::doShortestJobFirst() {
  std::string output = "";

  int currentRunTime = getEarliestArrivalProcess().getArrivalTime();
  pushAllApplicableToReady(currentRunTime);
  runningProcess = popLeastBurstTimeProcessFromReady();
  
  while (processes.size() >= 0 || readyQueue.size() > 0) {
    std::cout << "Current Run Time: " << currentRunTime << std::endl;
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getBurstTime()) + "X";
    output += "\n";

    currentRunTime += runningProcess.getBurstTime();

    // If run time is less than the earliest arrival time in processes
    if (processes.size() > 0) {
      if (currentRunTime < getEarliestArrivalProcess().getArrivalTime() && readyQueue.size() == 0) {
        // Set Current Run Time to earliest available process
        currentRunTime = getEarliestArrivalProcess().getArrivalTime();
      }
      pushAllApplicableToReady(currentRunTime);
    }
    
    if (processes.size() == 0 && readyQueue.size() == 0) {
      break;
    }
    
    runningProcess = popLeastBurstTimeProcessFromReady();
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
    std::cout << "SJF:" << std::endl;
    doShortestJobFirst();
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