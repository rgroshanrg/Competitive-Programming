#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

class Node {
    public :
        int data;
        Node *left;
        Node *right;
    
        Node(int n) {
            this->data = n;
            this->left = nullptr;
            this->right = nullptr;
        }
        Node(int n, Node *left, Node *right) {
            this->data = n;
            this->left = left;
            this->right = right;
        }
};

int diameter(Node *root, int &res) {
    if(root == NULL)
        return 0;

    int l = diameter(root->left, res);
    int r = diameter(root->right, res);

    int temp = max(l,r) + 1;
    int ans = max(temp, l+r+1);
    res = max(res, ans);

    return temp;
}

void preorder(Node *root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    Node *root = nullptr;
        /*

                    1
                   / \
                  2   7
                 / \   \
                3   4   8
                   / \   \
                  5   6   9
                         / \
                        11  10
                       / 
                      12
            

        */

    // Bullding the tree
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);
    root->right->right->right->left = new Node(11);
    root->right->right->right->left->left = new Node(12);


    int res = INT_MIN;
    diameter(root, res);
    cout << res << "\n";

    return 0;
}
