class Process {
  int index, arrivalTime, burstTime, priority;
  
  public:
    Process(int, int, int, int);
    
    int getIndex();
    int getArrivalTime();
    int getBurstTime();
    int getPriority();

    void setIndex(int);
    void setArrivalTime(int);
    void setBurstTime(int);
    void setPriority(int);
};