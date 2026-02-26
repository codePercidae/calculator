#ifndef NODE_H

#define NODE_H

class node
{
public:
    int value;
    node *left, *right;
    int (*op)(int, int);
    node();
    int get_value();
};

class parsetree
{
public:
    node root;
    parsetree();
    void add_node();
    int compute();
};

#endif