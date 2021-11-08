// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

void doSomeComputation() {   
 throw runtime_error("failure during doing some computation");
}

void example() {
 FILE* logfile = fopen("logfile.txt", "w+");
 try{
 if (!logfile) {
   throw runtime_error("failed to open file");
 }

 fputs("log - 1", logfile);
 
 }
 catch(const std::runtime_error& error){
     cout << error.what() << endl;
     fclose(logfile);
 }
 // Call a function that performs some computation and may throw 
 // an exception
  try{
    doSomeComputation();
  }
   catch(const std::runtime_error& error){
     cout << error.what() << endl;
     fclose(logfile);
    }

  try{
 if (!logfile) {
   throw runtime_error("failed to open file");
 }

 fputs("log - 2", logfile);
 
 }
 catch(const std::runtime_error& error){
     cout << error.what() << endl;
     fclose(logfile);
 }
    
 cout << "closing logfile" << endl;
 fclose(logfile);
}

int main(void) {
  cout << "Calling example()" << endl;

  try{
    example();
  }catch(const std::runtime_error& error){
    cout << error.what() << endl;
  }

  cout << "After calling example()" << endl;
  return 0;
}