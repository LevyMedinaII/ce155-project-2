#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "Process.h"

// Function declarations
std::vector<std::string> parseLine(std::string line);
int findExecutableProcessIndexAndExecute(std::vector<int> &, std::vector<Process>, std::vector<int> &);
void searchForDeadlock(int, std::vector<int>, std::vector<Process>);

int main(int argc, char * argv[]) {
  std::ifstream infile(argv[1]);
  std::string line;

  int testCases;
  int processCount;
  int resourceTypes;

  std::vector<int> allottableResources;
  std::vector<Process> processBlock;
  std::vector<std::string> v_line;
  std::vector<int> v_line_int;

  // each line of the input file is accessible here via <line>
  getline(infile, line);
  testCases = atoi(line.c_str());
  std::cout << "TEST CASES: " << testCases << std::endl;

  // loop for every testcase
  for(int lineCursor = 0; lineCursor < testCases; lineCursor++) {
    /* == STORE PROCESS COUNT AND RESOURCE TYPE  ==*/
    getline(infile, line);
    v_line = parseLine(line);

    // create integer vector for line input
    for (int i = 0; i < v_line.size(); i++) {
      int num = atoi(v_line.at(i).c_str());
      v_line_int.push_back(num);
    }
    
    processCount = v_line_int.at(0);
    resourceTypes = v_line_int.at(1);
    std::cout << "PROCESS COUNT: " << processCount << std::endl;
    std::cout << "RESOURCE TYPES: " << resourceTypes << std::endl;
    v_line_int.clear();

    /* == allottable RESOURCES ROW ==*/
    getline(infile, line);
    v_line = parseLine(line);
    for (int i = 0; i < v_line.size(); i++) {
      int num = atoi(v_line.at(i).c_str());
      v_line_int.push_back(num);
    }

    allottableResources = v_line_int;
    std::cout << "ALLOTABLE RESOURCES: " << std::endl;
    for(int i = 0; i < allottableResources.size(); i++)
      std::cout << allottableResources.at(i) << " ";

    v_line_int.clear();

    /* == HANDLE PROCESS PRE-ALLOCATION == */
    // for each process...
    std::cout << "HELD RESOURCES:" << std::endl;
    for (int processCursor = 0; processCursor < processCount; processCursor++) {
      getline(infile, line);
      v_line = parseLine(line);
      for (int i = 0; i < v_line.size(); i++) {
        int num = atoi(v_line.at(i).c_str());
        v_line_int.push_back(num);
      }

      // create Processes
      processBlock.push_back(Process(v_line_int));
      processBlock.at(processCursor).printProcess();
      v_line_int.clear();
    }

    /* == HANDLE PROCESS REQUESTS == */
    // for each process...
    std::cout << "REQUESTED RESOURCES:" << std::endl;
    for (int processCursor = 0; processCursor < processCount; processCursor++) {
      getline(infile, line);
      v_line = parseLine(line);
      for (int i = 0; i < v_line.size(); i++) {
        int num = atoi(v_line.at(i).c_str());
        v_line_int.push_back(num);
      }

      // create Processes
      processBlock.at(processCursor).setResourcesRequested(v_line_int);
      processBlock.at(processCursor).printProcessRequests();
      v_line_int.clear();
    }

    // for(const int& v_line_value: v_line_int) {
    //   processCount = 
    // }
    
    v_line_int.clear();
  }

  // deadlock findloop
  std::cout << "RESULT:" << std::endl;
  searchForDeadlock(processCount, allottableResources, processBlock);
}

// Function definitions
std::vector<std::string> parseLine(std::string line) {
  /*
   * Given a line of n elements,
   * The 1st to the n-1th element can be obtained by iterating <token>
   * the nth element can be obtained from <line> after the <token> loop
   */
  std::vector<std::string> output;
  std::string delimiter = " ";
  std::string token;
  size_t pos = 0;
  
  while ((pos = line.find(delimiter)) != std::string::npos) {
      token = line.substr(0, pos);
      line.erase(0, pos + delimiter.length());
      output.push_back(token);
  }
  output.push_back(line);
  return output;
}

int findExecutableProcessIndexAndExecute(
  std::vector<int> &allottableResources,
  std::vector<Process> processBlock,
  std::vector<int> &tracker) {
  
  Process currentProcess;
  for (int i = 0; i < processBlock.size(); i++) {
    bool isInTracker = false;
    currentProcess = processBlock.at(i);
    if (currentProcess.isExecutable(allottableResources)) {
      // Check if currentProcess already finished
      for (int trackerIndex = 0; trackerIndex < tracker.size(); trackerIndex++) {
        if (i == tracker.at(trackerIndex)) {
          isInTracker = true;
          break;
        }
      }

      // If not yet finished, return process
      if (!isInTracker) {
        for (int resourceIndex = 0; resourceIndex < allottableResources.size(); resourceIndex++)
          allottableResources.at(resourceIndex) += currentProcess.getResourceAtIndex(resourceIndex);
        tracker.push_back(i);
        return i;
      }
    }
  }
  return -1;
}

void searchForDeadlock(
  int processCount,
  std::vector<int> allottableResources,
  std::vector<Process> processBlock) {
    std::vector<int> tracker;
    int index;
    for(int i = 0; i < processCount; i++) {
      index = findExecutableProcessIndexAndExecute(allottableResources, processBlock, tracker);
      if (index == -1) {
        std::cout << "!!!DEADLOCK!!!" << std::endl;
        break;
      } else {
        std::cout << index;
        if (i < processCount-1)
          std::cout << "-";
        else
          std::cout << std::endl;
      }
    }
    
    std:: cout << std:: endl;
}
