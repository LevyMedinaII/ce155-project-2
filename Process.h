class Process {
  int arrivalTime, burstTime, priority;
  int remainingDuration;
  bool isFinished;

  public:
    Process();
    Process(int, int, int);
    
    int getArrivalTime();
    int getBurstTime();
    int getPriority();
    int getRemainingDuration();
    bool getFinishedStatus();

    void setArrivalTime(int);
    void setBurstTime(int);
    void setPriority(int);
    void setRemainingDuration(int);
    void setFinishedStatus(bool);
};