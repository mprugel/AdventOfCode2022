#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>
#include <exception>
#include <map>

enum eToken
{
    Rock = 1, Paper = 2, Scissors = 3
};

void extractColumns(std::string input, char &a, char &b)
{
    size_t pos = input.find(" ");
    a = input.substr(0, pos).at(0);
    input.erase(0, pos + 1);
    b = input.at(0);
}

uint32_t scoreRound(eToken own, eToken opponent)
{
    int res = opponent + own;
    int ret = 0;

    if(own == eToken::Paper && opponent == eToken::Rock ||
       own == eToken::Rock && opponent == eToken::Scissors ||
       own == eToken::Scissors && opponent == eToken::Paper )
    {
        // Won the round:
        ret = own + 6;
    }
    if(own == eToken::Paper && opponent == eToken::Paper ||
       own == eToken::Rock && opponent == eToken::Rock ||
       own == eToken::Scissors && opponent == eToken::Scissors)
    {
        ret = own + 3;
    }
    if( own == eToken::Paper && opponent == eToken::Scissors ||
       own == eToken::Rock && opponent == eToken::Paper ||
       own == eToken::Scissors && opponent == eToken::Rock)
    {
        // Lost:
        ret = own;
    }
    return ret;
}

// A: Rock , B: Paper, C: Scissors
// X: Rock , Y: Paper, Z: Scissors




int main(int argc, char** args)
{
    std::map<char, eToken> opponentAction = { {'A', eToken::Rock}, {'B',eToken::Paper}, {'C', eToken::Scissors} };
    std::map<char, eToken> ownAction = { {'X',eToken::Rock}, {'Y',eToken::Paper}, {'Z', eToken::Scissors} };
    
    std::ifstream inputStream(args[1]);
    std::string sline;

    uint32_t u32Score = 0U;
    uint32_t u32i = 0U;
    char a, b;

    while(std::getline(inputStream, sline))
    {
        if(sline.size() > 0)
        {
            extractColumns(sline,a,b);
            u32Score += scoreRound(ownAction.at(b), opponentAction.at(a));
        }
        else
        {
            std::cout << "ERROR" <<  std::endl;
        }
        
    }
    std::cout << "Score: " << u32Score << std::endl;

    return 0;
}