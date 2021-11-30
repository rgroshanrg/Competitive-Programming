#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
        }
        Node(int data, Node *left, Node *right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

int max_path_sum(Node *root, int &res) {
    if(root == nullptr) return 0;
    int left = max_path_sum(root->left, res);
    int right = max_path_sum(root->right, res);

    int temp = max( left, right ) + root->data;
    int ans = max(temp, left+right+root->data);
    res = max(res, ans);

    return temp;
}

int main() {
    Node * root = NULL;
    
    root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);

    int res = INT_MIN;

    max_path_sum(root, res);

    cout << res << "\n";

    return 0;
}