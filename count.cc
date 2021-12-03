/// \file count.cc
/// \brief This is the count.cc file for the Hands on Final portion of the exam
#include <iostream>
#include <fstream>
#include <string>

#include <cstring>
#include <iomanip>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

int countChar(string inputString);
int countLine(string inputString);

/// \brief main function
/// @param argc parameter to main
/// @param argv parameter to main
int main1(int argc, char * argv[])
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
/// \brief function that takes an input string and counts the number of characters
/// @param inputString The inputString we are counting
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
/// \brief function that counts the lines in a given string
/// @param inputString a string that we are counting how many new lines there are
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

TEST_CASE("CountChar", "Char"){
    string tmp1 = " ";
    string tmp2 = "abc def ";
    string tmp3 = "abc!123def";

    REQUIRE(countChar(tmp1) == 0);
    REQUIRE(countChar(tmp2) == 6);
    REQUIRE(countChar(tmp3) == 6);


}