#include <iostream>
#include "node.h"

using namespace std;

class node
{
    public:
        int value;
        int (*op)(int, int);
        node *left, *right;
        node(){
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

class parsetree
{
public:
    node root;
    parsetree(node r){
        this->root = r;
    }
    int compute(){
        int res = this->root.get_value();
        return res;
    }
};