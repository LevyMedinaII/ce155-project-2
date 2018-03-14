#include "Process.h"

using namespace std;

Process::Process() {
  arrivalTime = 0;
  burstTime = 0;
  priority = 0;
}
Process::Process (int arrival, int burst, int p) {
  arrivalTime = arrival;
  burstTime = burst;
  priority = p;
}

int Process::getArrivalTime() { return arrivalTime; }
int Process::getBurstTime() { return burstTime; }
int Process::getPriority() { return priority; }

void Process::setArrivalTime(int arrival) { arrivalTime = arrival; }
void Process::setBurstTime(int burst) { burstTime = burst; }
void Process::setPriority(int p) { priority = p; }