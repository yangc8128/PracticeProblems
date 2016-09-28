#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "HTMLSplicer.h"

void formatBMK(const char* output) {
  string out(output);
  ifstream outFile(out);
  if(!outFile) {
    cout << "Could not find output file, now creating output file" << endl;
  }
}

// The cmd line application param require files name to take from / output to
// First file will be the output file, if it does not exist it will create then
// write to it, otherwise it will append to it.
int main(int argc, char *argv[]) {
  if(argc < 2) return 1;
  // to convert a char* to string --> string(char* var)

  // Format (if needed) output file


  // Individual operations on current file
  //  copy to output file
}
