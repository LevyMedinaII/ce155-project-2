#include "Process.h"

Process::Process() {
  
}
Process::Process (int i, int arrival, int burst, int p, int elapsed, int last) {
  index = i;
  arrivalTime = arrival;
  burstTime = burst;
  priority = p;
  elapsedTime = elapsed;
  lastExecuteTime = last;
}

int Process::getIndex() { return index; }
int Process::getArrivalTime() { return arrivalTime; }
int Process::getBurstTime() { return burstTime; }
int Process::getPriority() { return priority; }
int Process::getElapsedTime() { return elapsedTime; }
int Process::getLastExecuteTime() { return lastExecuteTime; }

void Process::setIndex(int i) { index = i; }
void Process::setArrivalTime(int arrival) { arrivalTime = arrival; }
void Process::setBurstTime(int burst) { burstTime = burst; }
void Process::setPriority(int p) { priority = p; }
void Process::setElapsedTime(int el) { elapsedTime = el; }
void Process::setLastExecuteTime(int ex) { lastExecuteTime = ex; }
