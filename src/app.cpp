#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <vector>
#include "node.h"

using namespace std;

class operation{
    public:
        char symbol;
        int (*op)(int, int);
        int precedence; 
};

int add(int a, int b){
    return a + b;
}

int subs(int a, int b){
    return a - b;
}

int multpl(int a, int b){
    return a*b;
}

int dvde(int a, int b){
    return a/b;
}

map<char, operation> opTable;

string input(){
    string expression;
    getline(cin, expression);
    return expression;
}

inline void trimS(string &s){
    s.erase(
        s.begin(), find_if(s. begin(), s.end(), [](unsigned char ch) {
                return !isspace(ch);
            }
        )
    );
}

int main(){

    /*Declare mathematical operations*/
    char ch1{ '+' };
    char ch2{ '-' };
    char ch3{ '*' };
    char ch4{ '/' };

    operation addition;
    addition.symbol = ch1;
    addition.op = &add;

    operation substract;
    substract.symbol = ch2;
    substract.op = &subs;

    operation multiply;
    multiply.symbol = ch3;
    multiply.op = &multpl;

    operation divide;
    divide.symbol = ch4;
    divide.op = &dvde;

    opTable[ch1] = addition;
    opTable[ch2] = substract;
    opTable[ch3] = multiply;
    opTable[ch4] = divide;

    while (true)
    {
        string expression = input();
        trimS(expression);
    }
}