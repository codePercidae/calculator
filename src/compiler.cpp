using namespace std;

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

class compiler
{
    private:
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

    public:
        queue<string> parse(string &expr){

        /*
        Loop the argument and turn it into Reverse Polish Notation, using Dijkstra's
        shunting yard algorithm.
        */

        for (int i = 0; i < expr.size(); i++){

            if (isdigit(expr[i]) && numAllowed){
                opAllowed = true;
                currentN += expr[i];
                if (i+1 == expr.size()){
                    output.push(currentN);
                }
            }

            else if (operands.find(expr[i], expr.size()) && opAllowed){
                opAllowed = false;
                currentOp = expr[i];

                if (currentN != ""){
                    output.push(currentN);
                    currentN = "";
                    while (!operand_st.empty() && precedences[currentOp] <= precedences[operand_st.top()]){
                        output.push(operand_st.top());
                        operand_st.pop();
                    }
                    operand_st.push(currentOp);
                numAllowed = true;
                opAllowed = false;
                }
            }

            else {
                cout << "Unsupported syntax!\n";
                return output;
            }
        }
        while (!operand_st.empty()){
            output.push(operand_st.top());
            operand_st.pop();
        
        }
        return output;
    }
};

int main(){
    /*for testing purposes*/
    compiler c;
    string expression = "3+4*2";
    queue<string> q = c.parse(expression);
    cout << "Result: ";
    for (; !q.empty(); q.pop()){
        cout << q.front() << " ";
    }
    cout << "\n";
}