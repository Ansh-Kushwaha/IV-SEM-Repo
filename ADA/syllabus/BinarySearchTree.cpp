#include <iostream>
#include <queue>
#include <cmath>
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

    node* search(int x, node* node) {
        if(node == NULL)
            return NULL;
        else if(x < node->data)
            return search(x, node->left);
        else if(x > node->data)
            return search(x, node->right);
        else return node;
    }

    node* findInorderSuccessor(node* root) {
        // Finding min value node in the right subtree of root
        root = root->right;
        while(root != NULL && root->left != NULL)
            root = root->left;
        return root;
    }

    int heightOfTree(node* root) {
        if (root == NULL)
            return 0;
        return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
    }

    void preorder(node* root) {
        if(root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(node* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(node* root) {
        if(root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
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

    void printSpace(double n, node* removed) {
        for(; n > 0; n--)
            cout << "\t";
        if(removed == NULL)
            cout << " ";
        else
            cout << removed->data;
    }   

    void printBinaryTree(node* root) {
        queue<node*> treeLevel, temp;
        treeLevel.push(root);
        int counter = 0;
        int height = heightOfTree(root) - 1;
        double numberOfElements = pow(2, (height + 1)) - 1;
        while(counter <= height) {
            node* removed = treeLevel.front();
            treeLevel.pop();
            if(temp.empty()) {
                printSpace(numberOfElements / pow(2, counter + 1), removed);
            }
            else {
                printSpace(numberOfElements / pow(2, counter), removed);
            }
            if (removed == NULL) {
                temp.push(NULL);
                temp.push(NULL);
            }
            else {
                temp.push(removed->left);
                temp.push(removed->right);
            }
            if(treeLevel.empty()) {
                cout << endl << endl;
                treeLevel = temp;
                while (!temp.empty())
                    temp.pop();
                counter++;
            }
        }
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
        if(temp == NULL)
            return false;
        return true;
    }

    void deleteNode(int key) {
        deleteNode(key, root);
    }    

    int getHeight() {
        return heightOfTree(root);
    }

    void preorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << "\n";
    }

    void inorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << "\n";
    }

    void postorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << "\n";
    }

    void levelorder() {
        cout << "Levelorder: ";
        queue<node*> q;
        q.push(root);
        while(!q.empty()) {
            node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }

    void showTree() {
        printBinaryTree(root);
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

    tree.preorder();
    tree.inorder();
    tree.postorder();
    cout << "\n";
    tree.showTree();
    tree.deleteNode(45);

    tree.preorder();
    tree.inorder();
    tree.postorder();
    if(tree.search(8))
        cout << 8 << " is present in the tree\n";
    else   
        cout << 8 << " is not present in the tree\n";
    tree.showTree();
    tree.levelorder();

    return 0;
}