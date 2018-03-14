#include <iostream>
#include <cstdlib>

using namespace std;

class processBlock {
  int processCount;
  string command;
  public:
    void setProcessCount(int);
    void setCommand(string);
    int getProcessCount();
    string getCommand();
};


