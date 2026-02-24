#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        int (*op)(int, int);
        Node *left, *right;
        Node(){
            this->value = NULL;
            this->op = NULL;
            this->left = nullptr;
            this->right = nullptr;
        }
        int get_value(){
            if (this->value != NULL){
                return this->value;
            }
            else {
                int a = left -> get_value();
                int b = right -> get_value();
                this->value = this->op(a, b);
                return this->value;
            }
        }
};

class ParseTree
{
public:
    Node root;
    ParseTree(Node r){
        this->root = r;
    }
    void add_node(Node n){

    }
    int compute(){
        int res = this->root.get_value();
        return res;
    }
};