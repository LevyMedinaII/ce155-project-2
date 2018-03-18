#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "ProcessBlock.h"

// Function declarations
std::vector<std::string> parseLine(std::string line);

int main(int argc, char * argv[]) {
  std::ifstream infile(argv[1]);
  std::string line;
  int blockCount = 0;
  int currentBlockIndex = -1;
  int currentProcessIndex = 1;

  std::vector<ProcessBlock> blocks;
  std::vector<std::string> v_line;
  // each line of the input file is accessible here via <line>
  while (getline(infile, line)) {
    v_line = parseLine(line);
    if (v_line.size() < 2) {
      std::stringstream pnum(v_line.at(0));
      pnum >> blockCount;
    } else if (v_line.size() < 3) {
      std::stringstream processCount(v_line.at(0));
      int processN;

      ProcessBlock block(processN, v_line.at(1));
      blocks.push_back(block);
      
      currentProcessIndex = 1;
      currentBlockIndex++ ;
    } else if (v_line.size() < 4) {
      int aTime, bTime, prio;

      std::stringstream arrival(v_line.at(0));
      std::stringstream burst(v_line.at(1));
      std::stringstream p(v_line.at(2));

      arrival >> aTime;
      burst >> bTime;
      p >> prio;

      Process process(currentProcessIndex, aTime, bTime, prio);
      blocks.at(currentBlockIndex).addProcessToBlock(process);
      currentProcessIndex++;
    }
  }

  for (int i = 0; i < blocks.size(); i++) {
    std::cout << i + 1 << std::endl;
    blocks.at(i).printBlock();
  }
  
  return 1;
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
      std::cout << token << std::endl;
      line.erase(0, pos + delimiter.length());
      output.push_back(token);
  }
  std::cout << line << std::endl;
  output.push_back(line);
  return output;
}

