
#include <iostream>
#include <fstream>
#include <string>

#include <cstring>
#include <iomanip>

//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

using namespace std;

int countChar(string inputString);
int countLine(string inputString);


int main(int argc, char * argv[])
{
    

    int numChars;
    int numLines;

    if(argc == 1){
        numChars = countLine("Ohio University");
        numLines = countChar("Athens");
        cout << numLines << " Lines" << endl;
        cout << numChars << " Characters" << endl;

    }else if(argc == 2){
    
    
    string tmp = argv[1];
    ifstream t(tmp);
    stringstream buffer;
    buffer << t.rdbuf();
    string file = buffer.str();
     numChars = countChar(file);
     numLines = countLine(file);
    cout << numLines << " Lines" << endl;
    cout << numChars << " Characters" << endl;

    }else{
        cout << "ERROR" << endl;
    }
        
    return 0;
}

int countChar(string inputString){
    int charCount = 0;
    int i = 0;
    char tmp2;
    int j = inputString.size();

    while (i < j)
    {
         tmp2 = inputString[i];
        if ((tmp2 >= 'a' && tmp2 <= 'z') || (tmp2 >= 'A' && tmp2 <= 'Z'))
        {
            charCount++;
        }
        i++;
    }
    return charCount;
}
int countLine(string inputString){
    int lineNum = 0;
    int i = 0;
    char tmp2;
    int j = inputString.size();
     while (i < j)
    {
        tmp2 = inputString[i];
        if (tmp2 == '\n')
        {
            lineNum++;
        }
        i++;
    }
    return lineNum + 1;
}

