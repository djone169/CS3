//
//  main.cpp
//  word count
//
//  Created by Donny Jones on 2/5/21.
//

#include "word_count.hpp"
#include <iostream>
#include <fstream>
int main(int argc, char* argv[]){
    
    std::ifstream input_file(argv[1]);

    WordList wordlist;
    std::string line;

    while(!input_file.eof()){
        std::getline(input_file, line);
        int check = 0;
      //indicate if delimeter
        for(int indic = 0; indic < line.length(); ++indic){
            if(isalnum(line[indic])){
                check = indic;
                while(isalnum(line[check]) && check < line.length()){
                    ++check;
                }
                std::string word = line.substr(indic, check - indic);
                wordlist.addWord(word);
                indic = check - 1;
            }
        }
    }
    wordlist.sortArray();
    wordlist.print();
    input_file.close();
    return 0;
}
