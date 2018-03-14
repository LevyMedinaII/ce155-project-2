#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

// Function declarations
string* parseLine(string line);
string* parseProcessInfo(string line);

int cursorIndex = 0, blockIndex = 0, processIndex = 0;


int main(int argc, char * argv[]) {
  ifstream infile(argv[1]);
  string line;
  int blockNumbers;  

  while (getline(infile, line)) {
    if (cursorIndex < 1) {
      blockNumbers = stoi(line);
    } else {

    }

    



    cout << "Line: " << line << endl;
    parseLine(line);

    cursorIndex++;
  }

  return 1;
}

// Function definitions
string* parseLine(string line) {
  string delimiter = " ";
  string token;
  size_t pos = 0;
  
  while ((pos = line.find(delimiter)) != string::npos) {
      token = line.substr(0, pos);
      cout << token << endl;
      line.erase(0, pos + delimiter.length());
  }
  cout << line << endl;
}

