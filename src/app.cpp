#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Operation{
    public:
        string symbol;
        int (*op)(int, int);
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

int main(){

    /*Declare all mathematical operations*/

    Operation addition;
    addition.symbol = "+";
    addition.op = &add;

    Operation substract;
    substract.symbol = "-";
    substract.op = &subs;

    Operation multiply;
    multiply.symbol = "*";
    multiply.op = &multpl;

    Operation divide;
    divide.symbol = "/";
    divide.op = &dvde;

    map<string, Operation> table;
    table["+"] = addition;
    table["-"] = substract;
    table["*"] = multiply;
    table["/"] = divide;
}

string input(){
    
}

void parse(){

}
