using namespace std;

#include <iostream>
#include <node.h>
#include <string>
#include <stack>
#include <queue>
#include <map>

class compiler
{
    public:
        queue<string> parse(string &expr){
        string operands = "+*-/";
        string currentN = "";
        string currentOp = "";
        bool opAllowed = false;
        bool numAllowed = true;
        bool openPAllowe = true;
        bool closedPallowed = false;
        map <string, int> precedences = {{"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}};
        
        stack<string> operand_st;
        queue<string> output;

        /*
        Loop the argument and turn it into Reverse Polish Notation, using Dijkstra's
        shunting yard algorithm.
        Then POSSIBLY turn created queue into expression tree
        */
        for (int i = 0; i < expr.size(); i++){

            if (isdigit(expr[i]) && numAllowed){
                opAllowed = true;
                currentN += expr[i];
            }

            else if (operands.find(expr[i]) && opAllowed){
                opAllowed = false;
                currentOp = expr[i];

                if (currentN != ""){
                    output.push(currentN);
                    currentN = "";
                    while (!operand_st.empty() && (precedences[currentOp] <= precedences[operand_st.top()])){
                        output.push(operand_st.top());
                        operand_st.pop();
                    }
                    operand_st.push(currentOp);
                numAllowed = true;
                }

                else {
                    cout << "Unsupported syntax!";
                    exception;
                }
                opAllowed = false;
            }
        }
        return output;
    }
};

int main(){}