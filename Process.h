#include <iostream>
#include <vector>
#include <string>

class Process {
  std::vector<int> resourcesCount;
  std::vector<int> resourcesRequested;
  
  public:
    Process();
    Process(std::vector<int>);
    
    int getResourceAtIndex(int);
    void setResourceAtIndex(int, int);

    int getResourceRequestedAtIndex(int);
    void setResourcesRequested(std::vector<int>);

    void printProcess();
    void printProcessRequests();
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