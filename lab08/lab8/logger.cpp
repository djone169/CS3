#include <iostream>
#include <fstream>
#include <string>


using std::cout; using std::endl; using std::string;

class Logger{
public:

  // returns pointer to single instance
  static Logger *instance();
  static void report(const string& );
  // example functions manipulating singleton object
  int getI() const {return i_;}
  void setI(int i) {i_=i;}

private:

  Logger(); // defined later
  // to register behavior at destruction
  // copying prohibited
  Logger(const Logger&){}
  //Logger& operator=(const Logger&){}

  static void cleanUp(); // correct object destruction
  static Logger* onlyInstanceInt_; // pointer to its instance
  int i_; // payload
};

// initializing pointer to its instance
Logger* Logger::onlyInstanceInt_ = nullptr;

// returns pointer to instance of singleton
Logger* Logger::instance(){
  if(onlyInstanceInt_ == nullptr)
    // constructor is invoked here
    onlyInstanceInt_ = new Logger;
  return onlyInstanceInt_;
}

void Logger::report(const string& str){
  std::ofstream fout;
  fout.open("log.txt", std::fstream::out | std::fstream::app);
  fout << str  << std::endl;
  fout.close();
  //return str;
}

// registering behavior at program shutdown
Logger::Logger(){atexit(cleanUp);}

// deallocate instance, re-set pointer
void Logger::cleanUp(){
  cout << "cleaning stuff up" << endl;
  delete onlyInstanceInt_;
  onlyInstanceInt_ = nullptr;
}

// demonstration of singleton usage

int main(){
  string str = "End of text file";
  Logger::report(str);
}
