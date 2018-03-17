#include "Process.h"

using namespace std;

Process::Process (int i, int arrival, int burst, int p) {
  index = i;
  arrivalTime = arrival;
  burstTime = burst;
  priority = p;
}

int Process::getIndex() { return index; }
int Process::getArrivalTime() { return arrivalTime; }
int Process::getBurstTime() { return burstTime; }
int Process::getPriority() { return priority; }

void Process::setIndex(int i) { index = i; }
void Process::setArrivalTime(int arrival) { arrivalTime = arrival; }
void Process::setBurstTime(int burst) { burstTime = burst; }
void Process::setPriority(int p) { priority = p; }