#include "ProcessBlock.h"

// Constructor
ProcessBlock::ProcessBlock (int n, std::string c) {
  processCount = n;
  command = c;
  quantumTime = 0;
}

// Getters
int ProcessBlock::getProcessCount() { return processCount; }
std::string ProcessBlock::getCommand() { return command; }
int ProcessBlock::getQuantumTime() { return quantumTime; }

// Setters
void ProcessBlock::setQuantumTime(int time) { quantumTime = time; }

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

int ProcessBlock::getEarliestArrivalTimeFromReady() {
  Process earliestProcess = processes.at(0);
  int earliestTime = readyQueue.at(0).getArrivalTime();
  int index = 0;

  for (int i = 1; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getArrivalTime() < earliestTime) {
      earliestTime = readyQueue.at(i).getArrivalTime();

    }
  }
  currentRunTime = earliestTime;
  return earliestTime;
}

int ProcessBlock::getNextArrivalTimePriority(int currTime, int prio ) {
  int index = 0;
  int nextTime = 2000; 
  for (int i = 1; i < processes.size(); i++ ) {
    if (processes.at(i).getArrivalTime() > currTime) {
      if((processes.at(i).getArrivalTime() < nextTime)&&(processes.at(i).getPriority()<prio))
      {
        nextTime=processes.at(i).getArrivalTime();
        std::cout<<"nexttime"<<nextTime<<"With "<<prio<<" VS "<<processes.at(i).getPriority()<<std::endl;
        index = i;
      }

    }
  }
  if(nextTime==2000)
  {
    nextTime=0;
  }

  return nextTime;
}

int ProcessBlock::getNextArrivalTimeJob(int currTime,int finishJob) {
  int index = 0;
  int jobTime, arriveTime;
  int finalTime=0;
  for (int i = 0; i < processes.size(); i++ ) {
    arriveTime = processes.at(i).getArrivalTime()-currentRunTime;
    jobTime = arriveTime + processes.at(i).getBurstTime();
    std::cout<<std::endl<<jobTime<<"VS "<<finishJob<<std::endl;
    if(jobTime<finishJob ) {
      finalTime=arriveTime;
    }
  }
  
  return finalTime;
}



// Get the highrdt priotity process from processes
Process ProcessBlock::getHighestPriority() {
  Process firstProcess = processes.at(0);
  int firstPriority = processes.at(0).getPriority();
  int index = 0;

  for (int i = 1; i < processes.size(); i++ ) {
    if (processes.at(i).getPriority() < firstPriority) {
      firstPriority = processes.at(i).getPriority();
      firstProcess = processes.at(i);
      index = i;
    }
  }
  return firstProcess;
}

Process ProcessBlock::getHighestPriorityFromReady() {
  Process firstProcess = readyQueue.at(0);
  int firstPriority = readyQueue.at(0).getPriority();
  int index = 0;

  for (int i = 1; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getPriority() < firstPriority) {
      firstPriority = readyQueue.at(i).getPriority();
      firstProcess = readyQueue.at(i);
      index = i;
    }
  }
  return firstProcess;
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
  readyQueue.at(index).setLastExecuteTime(currentRunTime);
  readyQueue.erase(readyQueue.begin() + index);
  return leastBurstTimeProcess;
}

Process ProcessBlock::findLeastTimeProcessFromReady() {
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
  return leastBurstTimeProcess;
}

Process ProcessBlock::executeLeastTimeProcessFromReady(int time) {
  Process leastBurstTimeProcess = readyQueue.at(0);
  int leastBurstTime = readyQueue.at(0).getBurstTime();
  int index = 0;
  int currBurst, currElapse;

  
  for (int i = 0; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getBurstTime() < leastBurstTime) {
      leastBurstTime = readyQueue.at(i).getBurstTime();
      leastBurstTimeProcess = readyQueue.at(i);
      index = i;
    }
  }
  currBurst = readyQueue.at(index).getBurstTime();
  currElapse = readyQueue.at(index).getElapsedTime();
  waitingTime+=currentRunTime-readyQueue.at(index).getLastExecuteTime();
  readyQueue.at(index).setLastExecuteTime(currentRunTime+currBurst);


  if(time!=0)
  {
    readyQueue.at(index).setBurstTime(currBurst-time);
    readyQueue.at(index).setElapsedTime(time);
    leastBurstTimeProcess=readyQueue.at(index);
  }
  else
  {
    readyQueue.at(index).setBurstTime(0);
    readyQueue.at(index).setElapsedTime(currBurst);
    leastBurstTimeProcess=readyQueue.at(index);
    readyQueue.erase(readyQueue.begin() + index);
  }

  return leastBurstTimeProcess;
}

Process ProcessBlock::executeRoundRobin(int time) {
  Process leastBurstTimeProcess;
  //int leastBurstTime = readyQueue.at(0);
  int currBurst, currElapse, lastExecute;
  if(readyQueue.size()>0)
  {
    waitingTime+=currentRunTime-readyQueue.at(0).getLastExecuteTime();
    currBurst = readyQueue.at(0).getBurstTime();
    readyQueue.at(0).setLastExecuteTime(currentRunTime+currBurst);
    currElapse = readyQueue.at(0).getElapsedTime();
    readyQueue.at(0).setElapsedTime(time);
    readyQueue.at(0).setBurstTime(currBurst-time);
    currBurst = readyQueue.at(0).getBurstTime();
    
    

    if(currBurst>0)
    {
      leastBurstTimeProcess=readyQueue.at(0);
      readyQueue.erase(readyQueue.begin()); 
      preemptedQueue.push_back(leastBurstTimeProcess);
    }
    else
    {
      readyQueue.at(0).setBurstTime(0);
      readyQueue.at(0).setElapsedTime(time);
      leastBurstTimeProcess=readyQueue.at(0);
      readyQueue.erase(readyQueue.begin() + 0);
    }
  }
  else
  {
    waitingTime+=currentRunTime-preemptedQueue.at(0).getLastExecuteTime();
    currBurst = preemptedQueue.at(0).getBurstTime();
    preemptedQueue.at(0).setLastExecuteTime(currentRunTime+currBurst);
    currElapse = preemptedQueue.at(0).getElapsedTime();
    preemptedQueue.at(0).setElapsedTime(time);
    preemptedQueue.at(0).setBurstTime(currBurst-time);
    currBurst = preemptedQueue.at(0).getBurstTime();
    if(currBurst>0)
    {
      leastBurstTimeProcess=preemptedQueue.at(0);
      preemptedQueue.erase(preemptedQueue.begin());
      preemptedQueue.push_back(leastBurstTimeProcess);
    }
    else
    {
      preemptedQueue.at(0).setBurstTime(0);
      preemptedQueue.at(0).setElapsedTime(time);
      leastBurstTimeProcess=preemptedQueue.at(0);
      preemptedQueue.erase(preemptedQueue.begin() + 0);
    }

  }


  return leastBurstTimeProcess;
}


Process ProcessBlock::popHighestPriorityProcessFromReady(int time) {
  Process highestPriorityProcess = readyQueue.at(0);
  int highestPriority = readyQueue.at(0).getPriority();
  int index = 0;
  int currBurst;
  int currElapse;
  
  for (int i = 0; i < readyQueue.size(); i++ ) {
    if (readyQueue.at(i).getPriority() < highestPriority) {
      highestPriority = readyQueue.at(i).getPriority();
      highestPriorityProcess = readyQueue.at(i);
      index = i;
    }
  }
  waitingTime+=currentRunTime-readyQueue.at(index).getLastExecuteTime();

  readyQueue.at(index).setLastExecuteTime(currentRunTime+readyQueue.at(index).getBurstTime());
  
  if((highestPriorityProcess.getBurstTime()>time)&&(time!=0))
  {
    currBurst = readyQueue.at(index).getBurstTime();
    currElapse = readyQueue.at(index).getElapsedTime();
    readyQueue.at(index).setBurstTime(currBurst-time);
    readyQueue.at(index).setElapsedTime(currElapse+time);
    currBurst = readyQueue.at(index).getBurstTime();

    highestPriorityProcess = readyQueue.at(index);
    if(currBurst<=0)
    {
      readyQueue.at(index).setBurstTime(0);
      readyQueue.erase(readyQueue.begin() + index); 
    }
  }
  else
  {
    readyQueue.erase(readyQueue.begin() + index); 
    highestPriorityProcess.setElapsedTime(highestPriorityProcess.getBurstTime());
  }

  return highestPriorityProcess;
}

void ProcessBlock::printSummary(int waitingTime, int responseTime, int turnaroundTime, double cpuOptimization, int throughputUnit) {
  std::string output = "";
  output += "*******************\n";
  output += "Avg waiting time: ";
  output += std::to_string(waitingTime);
  output += "\n";
  output += "Avg response time: ";
  output += std::to_string(responseTime);
  output += "\n";
  output += "Avg turnaround time: ";
  output += std::to_string(turnaroundTime);
  output += "\n";
  output += "CPU Optimization: ";
  output += std::to_string(cpuOptimization);
  output += "\n";
  output += "Throughput: 1 process per ";
  output += std::to_string(throughputUnit);
  output += " clock cycles";
  output += "\n";
  std::cout << output;
}

// Perform Priority
std::string ProcessBlock::doPriority() {
  std::string output = "";
  currentRunTime = getEarliestArrivalProcess().getArrivalTime();

  
  
  pushAllApplicableToReady(currentRunTime);
  int nextTime = getNextArrivalTimePriority(currentRunTime, getHighestPriorityFromReady().getPriority());
  runningProcess = popHighestPriorityProcessFromReady(nextTime);
  currentRunTime = runningProcess.getArrivalTime();
  while (readyQueue.size() >= 0 ) {
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getElapsedTime() );
    if(runningProcess.getBurstTime()==0)
    {
      output += 'X';
    }
    output += "\n";

    currentRunTime += runningProcess.getElapsedTime();
    pushAllApplicableToReady(currentRunTime);

    if ((readyQueue.size() == 0) && (processes.size()==0)) {
      break;
    }
    if(processes.size()>0)
    {
      runningProcess = popHighestPriorityProcessFromReady(getNextArrivalTimePriority(currentRunTime,runningProcess.getPriority()));
    }
    else
    {
      runningProcess = popHighestPriorityProcessFromReady(0);
    }

    
    if (currentRunTime < runningProcess.getArrivalTime()) {
      currentRunTime = runningProcess.getArrivalTime();
    }
  }

  std::cout << output;

  std::cout <<std::endl<<"Waiting: "<<waitingTime;
  std::cout <<std::endl<<"CPU: "<<cpuUtilization;

  return output;
}

// Perform FCFS
std::string ProcessBlock::doFirstComeFirstServe() {
  std::string output = "";
  int cpuWaiting, cpuInUse;
  double cpuOptimization;
  int waitingTime, throughput, responseTime, turnaroundTime;
  int throughputUnit = 0;
  int processesCount = processes.size();
  
  waitingTime = 0;
  responseTime = 0;
  cpuInUse = 0;
  cpuWaiting = 0;
  throughput = 0;
  turnaroundTime =  0;

  pushAllToReady();

  runningProcess = popEarliestArrivalProcessFromReady();
  currentRunTime = runningProcess.getArrivalTime();

  waitingTime += currentRunTime;
  turnaroundTime += waitingTime;
  cpuInUse += runningProcess.getBurstTime();
  
  while (readyQueue.size() >= 0 ) {
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getBurstTime()) + "X";
    output += "\n";

    currentRunTime += runningProcess.getBurstTime();
    turnaroundTime += runningProcess.getBurstTime();
    
    throughput++;
    if (throughput == 1) {
      throughputUnit = currentRunTime;
    }

    if (readyQueue.size() == 0) {
      break;
    }
    runningProcess = popEarliestArrivalProcessFromReady();
    if (currentRunTime < runningProcess.getArrivalTime()) {
      turnaroundTime += (runningProcess.getArrivalTime() - currentRunTime);
      currentRunTime = runningProcess.getArrivalTime();
      waitingTime += (currentRunTime - waitingTime);
    }
  }

  cpuWaiting = waitingTime;
  cpuOptimization = ((double)cpuInUse/(double)(cpuWaiting + cpuInUse))*100;

  waitingTime /= processCount;
  responseTime = waitingTime;
  turnaroundTime /= processCount;

  std::cout << output;
  printSummary(waitingTime, responseTime, turnaroundTime, cpuOptimization, throughputUnit);

  return output;
}

// Perform SJF
std::string ProcessBlock::doShortestJobFirst() {
  std::string output = "";

  currentRunTime = getEarliestArrivalProcess().getArrivalTime();
  pushAllApplicableToReady(currentRunTime);
  runningProcess = popLeastBurstTimeProcessFromReady();
  
  while (processes.size() >= 0 || readyQueue.size() > 0) {
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

// Perform RoundRobin
std::string ProcessBlock::doRoundRobin() {
  std::string output = "";
  currentRunTime = getEarliestArrivalProcess().getArrivalTime();
  pushAllApplicableToReady(currentRunTime);
  runningProcess = executeRoundRobin(quantumTime);
  currentRunTime = runningProcess.getArrivalTime();
  
  while ((readyQueue.size() >= 0 ) || (preemptedQueue.size() >=0)){
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getElapsedTime());
    if(runningProcess.getBurstTime()==0)
    {
      output += 'X';
    }
    output += "\n";

    currentRunTime += runningProcess.getElapsedTime();
    pushAllApplicableToReady(currentRunTime);
    if ((readyQueue.size() == 0)&&(preemptedQueue.size() ==0)) {
      break;
    }
    runningProcess = executeRoundRobin(quantumTime);
    if (currentRunTime < runningProcess.getArrivalTime()) {
      currentRunTime = runningProcess.getArrivalTime();
    }
  }

  std::cout << output;

  return output;
}


// Perform SRTF
std::string ProcessBlock::doShortestRemainingTimeFirst() {
  std::string output = "";
  
  currentRunTime = getEarliestArrivalProcess().getArrivalTime();
  pushAllApplicableToReady(currentRunTime);
  Process checker = findLeastTimeProcessFromReady();
  
  int nextTime = getNextArrivalTimeJob(currentRunTime, checker.getBurstTime());
  runningProcess = executeLeastTimeProcessFromReady(nextTime);
  
  while (processes.size() >= 0 || readyQueue.size() > 0) {
    output += std::to_string(currentRunTime);
    output += " ";
    output += std::to_string(runningProcess.getIndex());
    output += " ";
    output += std::to_string(runningProcess.getElapsedTime());
    if(runningProcess.getBurstTime()==0)
    {
      output += 'X';
    }
    output += "\n";

    currentRunTime += runningProcess.getElapsedTime();
    if (processes.size() == 0 && readyQueue.size() == 0) {
      cpuUtilization = (currentRunTime - cpuUtilizationSlack)/currentRunTime;
      std::cout<<"wow you used this shit "<<cpuUtilization*100;
      break;
    }
    
    // If run time is less than the earliest arrival time in processes
    if (processes.size() > 0) {
      if (currentRunTime < getEarliestArrivalProcess().getArrivalTime() && readyQueue.size() == 0) {
        // Set Current Run Time to earliest available process
        cpuUtilizationSlack += getEarliestArrivalProcess().getArrivalTime()-currentRunTime;
        std::cout<<"wow you just lost "<<cpuUtilizationSlack<< " seconds"<<std::endl;
        currentRunTime = getEarliestArrivalProcess().getArrivalTime();

      }
      
      
      pushAllApplicableToReady(currentRunTime);
      std::cout << std::endl<<"PUSHED AT: "<<currentRunTime;
      checker = findLeastTimeProcessFromReady();
      nextTime = getNextArrivalTimeJob(currentRunTime, checker.getBurstTime());
      runningProcess = executeLeastTimeProcessFromReady(nextTime);
      
    }
    else
    {
      std::cout<<"WOWOWOW "<<std::endl;
      runningProcess = executeLeastTimeProcessFromReady(0);
      std::cout<<"WOWOWOW "<<runningProcess.getElapsedTime()<<std::endl;
    }
    std::cout << std::endl<<"RSize: "<< readyQueue.size();
    std::cout << std::endl<<"PSize: "<< processes.size();
    

  
    
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
    doShortestRemainingTimeFirst();
  } else if (command == "P") {
    std::cout<< "P:" << std::endl;
    doPriority();
  } else if (command == "RR") {
    std::cout<< "RR:" << std::endl;
    doRoundRobin();
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