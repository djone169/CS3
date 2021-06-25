//
//  word_count.cpp
//  word count
//
//  Created by Donny Jones on 2/5/21.
//

#include "word_count.hpp"

WordOccurrence::WordOccurrence(const std::string& word , int num){
  word_= word;
  num_= num;
}

bool WordOccurrence::matchWord(const std::string &word){
  if(word_== word){
    return true;
  }
  else{
    return false;
  }
}

void WordOccurrence::increment(){
  num_= num_ + 1;
}

std::string WordOccurrence::getWord()const{
    return word_;
}

int WordOccurrence::getNum()const{
    return num_;
}

//=====================================

//destructor
WordList::~WordList(){
    if(wordArray_ != nullptr){
        delete[] wordArray_;
    }
}
//copy
WordList::WordList(const WordList& original){
    size_ = original.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < size_; ++i){
        wordArray_[i] = original.wordArray_[i];
    }
}
//assignment
WordList& WordList::operator=(const WordList& rhs){
    size_ = rhs.size_;
    if(wordArray_ != nullptr){
        delete[] wordArray_;
    }
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < size_; ++i){
        wordArray_[i] = rhs.wordArray_[i];
    }
    return *this;
}
//comp
bool equal(const WordList &lhs, const WordList &rhs){
    bool result = true;
    if(lhs.size_ == rhs.size_){
        for(int i = 0; i < lhs.size_; ++i){
            if(!lhs.wordArray_[i].matchWord(rhs.wordArray_[i].getWord())){
                result = false;
            }
        }
    }else{
        result = false;
    }

    return result;
}

void WordList::sortArray(){
    for(int i = 0; i < size_; ++i){
        int min = i;
        for(int j = i + 1; j < size_; ++j){
            if(wordArray_[min].getNum() > wordArray_[j].getNum()){
                min = j;
            }
        }
       
        WordOccurrence temp = wordArray_[i];
        wordArray_[i] = wordArray_[min];
        wordArray_[min] = temp;
    }
}

void WordList::addWord(const std::string &w){
    int index = -1;
    for(int i = 0; i < size_; ++i){
        if(wordArray_[i].getWord() == w){
            index = i;
            break;
        }
    }
    if(index > -1){
        wordArray_[index].increment();
    }
    else{
        WordOccurrence *tmp = new WordOccurrence[size_ + 1];
        for(int i = 0; i < size_; ++i){
            tmp[i] = wordArray_[i];
        }
        WordOccurrence wo(w, 1);
        tmp[size_] = wo;
        if(wordArray_ != nullptr){
            delete[] wordArray_;
        }
        wordArray_ = tmp;
        ++size_;
    }
}

void WordList::print(){
    for(int i = 0; i < size_; ++i){
        std::cout << i << ") ";
        std::cout << wordArray_[i].getWord() << " : " << wordArray_[i].getNum() << std::endl;
    }
}
