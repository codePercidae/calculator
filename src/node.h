#ifndef NODE_H

#define NODE_H

class Node
{
public:
    int value;
    Node *left, *right;
    int (*op)(int, int);
    Node();
    int get_value();
};

class ParseTree
{
public:
    Node root;
    ParseTree();
    void add_node();
    int compute();
};

#endif