#ifndef BST_node_header
#define BST_node_header

class BST_node
{
public:
    BST_node(void);
    BST_node *left;
    BST_node *right;
    int info;

public:
    BST_node(int Info);
};

BST_node::BST_node(void)
{
    left = 0;
    right = 0;
}

BST_node::BST_node(int Info)
{
    info = Info;
    left = 0;
    right = 0;
}
#endif