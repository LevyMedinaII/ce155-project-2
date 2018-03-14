#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Process.h"
#include "ProcessBlock.h"

// Function declarations
std::string* parseLine(std::string line);
std::string* parseProcessInfo(std::string line);

int main(int argc, char * argv[]) {
  std::ifstream infile(argv[1]);
  std::string line;
  std::vector<ProcessBlock> commandBlocks;
  int blockCount = 0;

  // each line of the input file is accessible here via <line>
  while (getline(infile, line)) {
    // sets the number of process blocks
    if (blockCount == 0) {
      blockCount = std::stoi(line);
    }
  }

  return 1;
}

// Function definitions
std::string* parseLine(std::string line) {
  /*
   * Given a line of n elements,
   * The 1st to the n-1th element can be obtained by iterating <token>
   * the nth element can be obtained from <line> after the <token> loop
   */
  std::string delimiter = " ";
  std::string token;
  size_t pos = 0;
  
  while ((pos = line.find(delimiter)) != std::string::npos) {
      token = line.substr(0, pos);
      std::cout << token << std::endl;
      line.erase(0, pos + delimiter.length());
  }
  std::cout << line << std::endl;
}

