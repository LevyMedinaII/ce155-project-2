class Process {
  int index, arrivalTime, burstTime, priority, elapsedTime, lastExecuteTime;
  
  public:
    Process();
    Process(int, int, int, int, int, int);
    
    int getIndex();
    int getArrivalTime();
    int getBurstTime();
    int getPriority();
    int getElapsedTime();
    int getLastExecuteTime();

    void setIndex(int);
    void setArrivalTime(int);
    void setBurstTime(int);
    void setPriority(int);
    void setElapsedTime(int);
    void setLastExecuteTime(int);
};