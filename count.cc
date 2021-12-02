#define CONFIG_CATCH_MAIN
#include "catch.hpp"


#include <iostream>
#include <fstream>
#include <string>

#include <cstring>
#include <iomanip>
using namespace std;

int Charcount(string inputString);
int LineCount(string inputString);
/*
TEST_CASE("test", "test")
{
    string st = "\n";
    REQUIRE(LineCount(st) == 1);


}
*/



int main()
{
    ifstream t("test.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    
    string tmp = buffer.str();

    int numChars = Charcount(tmp);
    int numLines = LineCount(tmp);
    cout << numChars << endl << numLines;



    return 0;
}

int Charcount(string inputString){
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
int LineCount(string inputString){
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


