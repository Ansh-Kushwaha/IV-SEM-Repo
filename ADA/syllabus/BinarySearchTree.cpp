#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BST {
    private:
    node *root;

    node* search(int x, node* root) {
        if(root->data == x || root == NULL)
            return root;
        else if(x < root->data)
            return search(x, root->left);
        else
            return search(x, root->right);
    }

    node* findInorderSuccessor(node* root) {
        // Finding min value node in the right subtree of root
        root = root->right;
        while(root != NULL && root->left != NULL)
            root = root->left;
        return root;
    }

    void inorder(node* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    node* insertNode(node* curr, int x) {
        if(curr == NULL) {
            return new node(x);
        }
        if(x < curr->data)
            curr->left = insertNode(curr->left, x);
        else
            curr->right = insertNode(curr->right, x);
        
        return curr;
    }

    node* deleteNode(int key, node* root) {
        if(root == NULL)
            return root;
        else if(key < root->data)
            root->left =  deleteNode(key, root->left);
        else if(key > root->data)
            root->right = deleteNode(key, root->right);
        else {
            // No child
            if(root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            // One child
            else if(root->left == NULL) {
                node* temp = root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL) {
                node* temp = root->left;
                free(root);
                return temp;
            }
            // Two childs
            node *successor = findInorderSuccessor(root);
            root->data = successor->data;
            root->right = deleteNode(successor->data, root->right);
        }
        return root;
    }

    public:
    BST() {
        root = NULL;
    }

    void insert(int x) {
        root = insertNode(root, x);
    }

    bool search(int key) {
        node* temp = search(key, root);
        return true;
    }

    void deleteNode(int key) {
        deleteNode(key, root);
    }    

    void inorder() {
        inorder(root);
    }
};

int main() {
    BST tree;
    tree.insert(45);
    tree.insert(15);
    tree.insert(79);
    tree.insert(90);
    tree.insert(10);
    tree.insert(55);
    tree.insert(12);
    tree.insert(20);
    tree.insert(50);

    tree.inorder();
    cout << "\n";
    tree.deleteNode(45);
    tree.inorder();
    cout << "\n";
    tree.search(9);

    return 0;
}