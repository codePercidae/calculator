#ifndef COMPILER_H

#define COMPILER_H

using namespace std;
#include <queue>
#include <string>
#include <stack>
#include <map>

class compiler
{
private:
    string operands;
    string currentN;
    string currentOp;
    bool opAllowed;
    bool numAllowed;
    bool openPAllowe;
    bool closedPallowed;
    map <string, int> precedences;
    stack<string> operand_st;
    queue<string> output;
public:
    queue<string> parse;
};

#endif