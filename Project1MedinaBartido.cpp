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
  std::vector<ProcessBlock> commandBlocks;
  int blockCount = 0;
  std::vector<std::string> v_line;
  // each line of the input file is accessible here via <line>
  while (getline(infile, line)) {
    v_line = parseLine(line);
    if (v_line.size < 2) {

    }
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

