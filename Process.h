class Process {
  int arrivalTime, burstTime, priority;
  public:
    Process();
    Process(int, int, int);
    
    int getArrivalTime();
    int getBurstTime();
    int getPriority();

    void setArrivalTime(int);
    void setBurstTime(int);
    void setPriority(int);
};