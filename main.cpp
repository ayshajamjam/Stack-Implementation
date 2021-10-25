#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

using namespace std;

int main(int argc, char * argv[]) {
    
    Stack <int> stk;
    string filename = argv[1];
    string wordRead;
    string numOfLines;
    int wordCount = 0;
    
    ifstream inputFile;
    inputFile.open(filename.c_str());
    
    if(!inputFile){
        cerr << "Unable to open file" << endl;
    }
    
    inputFile >> numOfLines;
    
    while (inputFile >> wordRead){
        wordCount++;
        if(inputFile.peek() == '\n'){
            stk.push(wordCount);
            wordCount = 0;
        }
        
    }
    
    inputFile.close();
    
    while(stk.empty() == false){
        cout << stk.pop() << endl;
    }
    
    /*for(int i = 0; i < stk.size(); i++){
     stk.pop();
     cout << endl;
     }*/
    
    return 0;
}



