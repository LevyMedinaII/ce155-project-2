#include <iostream>
#include <cstdlib>

using namespace std;

class ProcessBlock {
  int processCount;
  string command;
  public:
    ProcessBlock(int, string);
    void setProcessCount(int);
    void setCommand(string);
    int getProcessCount();
    string getCommand();
};

ProcessBlock::ProcessBlock (int n, string c) {
  processCount = n;
  command = c;
}

void ProcessBlock::setProcessCount(int n) { processCount = n; }
void ProcessBlock::setCommand(string c) { command = c; }
int ProcessBlock::getProcessCount() { return processCount; }
string ProcessBlock::getCommand() { return command; }

