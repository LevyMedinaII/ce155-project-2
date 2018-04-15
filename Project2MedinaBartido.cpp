#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "Process.h"

// Function declarations
std::vector<std::string> parseLine(std::string line);

int main(int argc, char * argv[]) {
  std::ifstream infile(argv[1]);
  std::string line;

  int blockCount = 0;
  int currentBlockIndex = -1;
  int currentProcessIndex = 1;

  int testCases;
  int processCount;
  int resourceTypes;
  std::vector<int> allotableResources;

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

    /* == ALLOTABLE RESOURCES ROW ==*/
    getline(infile, line);
    v_line = parseLine(line);
    for (int i = 0; i < v_line.size(); i++) {
      int num = atoi(v_line.at(i).c_str());
      v_line_int.push_back(num);
    }

    allotableResources = v_line_int;

    v_line_int.clear();

    /* == HANDLE PROCESS PRE-ALLOCATION == */
    // for each process...
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
    // for (int processCursor = 0; processCursor < processCount; processCursor++) {
    //   getline(infile, line);
    //   v_line = parseLine(line);
    //   for (int i = 0; i < v_line.size(); i++) {
    //     int num = atoi(v_line.at(i).c_str());
    //     v_line_int.push_back(num);
    //   }

    //   // create Processes
    //   processBlock.push_back(Process(v_line_int));
    //   v_line_int.clear();
    // }

    // for(const int& v_line_value: v_line_int) {
    //   processCount = 
    // }
    
    v_line_int.clear();
  }



  //   if (v_line.size() < 2) {
  //     std::stringstream pnum(v_line.at(0));
  //     pnum >> blockCount;
  //     std::cout << blockCount << std::endl;
  //   } else if (v_line.size() < 3) {
  //     std::stringstream processCount(v_line.at(0));
  //     int processN;
  //     processCount >> processN;

  //     ProcessBlock block(processN, v_line.at(1));
  //     blocks.push_back(block);
      
  //     currentProcessIndex = 1;
  //     currentBlockIndex++ ;
  //   } else if (v_line.size() < 4) {
  //     int aTime, bTime, prio;

  //     int quantumTime;
  //     std::string quantumCmd;
  //     int processN;

  //     std::stringstream arrival(v_line.at(0));
  //     std::stringstream burst(v_line.at(1));
  //     std::stringstream p(v_line.at(2));

  //     if (v_line.at(1) == "RR") {
  //       arrival >> processN;
  //       burst >> quantumCmd;
  //       p >> quantumTime;

  //       ProcessBlock block(processN, quantumCmd);
  //       block.setQuantumTime(quantumTime);
  //       blocks.push_back(block);

  //       currentProcessIndex = 1;
  //       currentBlockIndex++ ;
  //     } else {
  //       burst >> bTime;
  //       arrival >> aTime;
  //       p >> prio;

  //       Process process(currentProcessIndex, aTime, bTime, prio,0,aTime);
  //       blocks.at(currentBlockIndex).addProcessToBlock(process);
  //       currentProcessIndex++;
  //     }
  // }

  // for (int i = 0; i < blocks.size(); i++) {
  //   blocks.at(i).printBlock();
  // }
  
  // std::cout << "==================" << std::endl;
  // std::cout << "|     OUTPUT     |" << std::endl;
  // std::cout << "==================" << std::endl;
  
  // for (int i = 0; i < blocks.size(); i++) {
  //   blocks.at(i).execute();
  // }
  // return 1;
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

