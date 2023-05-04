#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

typedef struct BST {
    node *root;

    BST() {
        root = NULL;
    }

    void insert(int x) {
        root = insertNode(x);
    }

    node* insertNode(int x) {
        if(root == NULL)
            return new node(x);
        if(x < root->data)
            root->left = insertNode(x);
        if(x > root->data)
            root->right = insertNode(x);
    }

    node* search(int x, node* root) {
        if(root->data == x || root == NULL)
            return root;
        else if(x < root->data)
            return search(x, root->left);
        else
            return search(x, root->right);
    }
};

int main() {

}