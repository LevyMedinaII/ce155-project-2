#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "ProcessBlock.h"

// Function declarations
std::vector<std::string> parseLine(std::string line);
std::string* parseProcessInfo(std::string line);

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
      blockCount = v_line.at(0)
    } else if (v_line.size() < 3) {
      blocks.push_back(new ProcessBlock(v_line.at(0), v_line.at(1)));
      currentProcessIndex = 1;
      currentBlockIndex++ ;
    } else if (v_line.size() < 4) {
      blocks.at(currentBlockIndex).addProcessToBlock(
        new Process(currentProcessIndex, v_line.at(0), v_line.at(1), v_line.at(2))
      );
      currentProcessIndex++;
    }
  }

  for (int i = 0; i < blocks.size(); i++) {
    cout << i + 1 << endl;
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

