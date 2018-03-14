#include <iostream>
#include <cstdlib>

using namespace std;

class Process {
  int arrivalTime, burstTime, priority;
  public:
    Process(int, int, int);
    int getArrivalTime();
    int getBurstTime();
    int getPriority();
};

Process::Process (int arrival, int burst, int p) {
  arrivalTime = arrival;
  burstTime = burst;
  priority = p;
}

int Process::getArrivalTime() { return arrivalTime; }
int Process::getBurstTime() { return burstTime; }
int Process::getPriority() { return priority; }

