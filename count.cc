
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


int main1(int argc, char * argv[])
{
    ifstream t("test.txt");
    stringstream buffer;
    buffer << t.rdbuf();
   
    string tmp = buffer.str();

    int numChars = countChar(tmp);
    int numLines = countLine(tmp);
    cout << numChars << endl << numLines;



    return 0;
}

int countChar(string inputString){
    int charCount = 0;
    int i = 0;
    char tmp2;


    while (i < inputString.size())
    {
         tmp2 = inputString[i];
        if (tmp2 >= 'a' && tmp2 <= 'z' || tmp2 >= 'A' && tmp2 <= 'Z')
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

     while (i < inputString.size())
    {
        tmp2 = inputString[i];
        if (tmp2 == '\n')
        {
            lineNum++;
        }
        i++;
    }
    return lineNum;
}


TEST_CASE("test", "test")
{
    string st = "\n";
    REQUIRE(countLine(st) == 1);


}
