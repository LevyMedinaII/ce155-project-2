#include <iostream>
#include <vector>
#include <string>

class Process {
  std::vector<int> resourcesCount;
  
  public:
    Process();
    Process(std::vector<int>);
    
    int getResourceAtIndex(int);
    int setResourceAtIndex(int, int);
    void printProcess();
    // int getArrivalTime();
    // int getBurstTime();
    // int getPriority();
    // int getElapsedTime();
    // int getLastExecuteTime();

    // void setIndex(int);
    // void setArrivalTime(int);
    // void setBurstTime(int);
    // void setPriority(int);
    // void setElapsedTime(int);
    // void setLastExecuteTime(int);
};