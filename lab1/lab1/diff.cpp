//
//  diff.cpp
//  lab1
//
//  Created by Donny Jones on 1/27/21.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char* argv[]){

  if(argc != 3){
    std::cout << "Error: Incorrect # of files." << std::endl;
    return 0;
  }
  else{
    std::string line1;
    std::string line2;
      
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);
      
    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

      //to count line numbers
    int lineNumber = -1;

    //check files are open
    if (!file1.is_open() || !file2.is_open()) {
            std::cout << "Could not open files" << std::endl;
            return 0;
          }
    
    while(!file1.eof() || !file2.eof()){
        //if file1 ends
    if(!file2.eof() && file1.eof()){
        ++lineNumber;
        std::getline(file2, line2);
        if(line2 == ""){
          continue;
      }

      //print out lines
      std::cout << argv[1] << ": " << lineNumber << ": " << std::endl;
      std::cout << argv[2] << ": " << lineNumber << ": " << line2 << std::endl;

      int spaces = (lineNumber > 9) ? (strlen(argv[1]) + 6) : (strlen(argv[1]) + 5);
      for(int i = 0; i < spaces; ++i){
          std::cout << " ";
      }
      std::cout << "^" << std::endl;
    }
    //if file2 has ended
        else if(!file1.eof() && file2.eof()){
                ++lineNumber;
                std::getline(file1, line1);
            if(line1 == ""){
                continue;
                }
        std::cout << argv[1] << ": " << lineNumber << ": " << line1 << std::endl;
        std::cout << argv[2] << ": " << lineNumber << ": " << std::endl;

      int spaces = (lineNumber > 9) ? (strlen(argv[1]) + 6) : (strlen(argv[1]) + 5);
      for(int i = 0; i < spaces; ++i){
          std::cout << " ";
      }
        std::cout << "^" << std::endl;

    }
    //if files don't end
      else{
        ++lineNumber;
        std::getline(file1, line1);
        std::getline(file2, line2);
        bool diff = false;

        int max_length = (line1.length() < line2.length()) ? line1.length() : line2.length();
        for(int i = 0; i < max_length; ++i){
              if(line1[i] != line2[i]){

                std::cout << argv[1] << ": " << lineNumber << ": " << line1 << std::endl;
                std::cout << argv[2] << ": " << lineNumber << ": " << line2 << std::endl;

                int spaces = (lineNumber > 9) ? (strlen(argv[1]) + i + 6) : (strlen(argv[1]) + i + 5);
                for(int j = 0; j < spaces; ++j){
                      std::cout << " ";
                }
                std::cout << "^" << std::endl;
                diff = true;
                break;
              }
        }
          //if length is different
        if(!diff && (line1.length() != line2.length())){

            
            std::cout << argv[1] << ": " << lineNumber << ": " << line1 << std::endl;
            std::cout << argv[2] << ": " << lineNumber << ": " << line2 << std::endl;

            int spaces = (lineNumber > 9) ? (strlen(argv[1]) + max_length + 6) : (strlen(argv[1]) + max_length + 5);
            for(int j = 0; j < spaces; ++j){
                  std::cout << " ";
            }
            std::cout << "^" << std::endl;
        }
      }
}

}
}

