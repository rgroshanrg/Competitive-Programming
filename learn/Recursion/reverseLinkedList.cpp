#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
        int data;
        Node *next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

Node* insert(Node *root, int data) {
    
    Node *newNode = new Node(data);
    if(root == NULL) {
        root = newNode; return root;
    }
    Node *temp = root;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    
    return root;
}

Node* reverse(Node *root) {
    if(root == NULL)
        return NULL;
    if(root->next == NULL) {
        return root;
    }
    Node *temp = reverse(root->next);
    temp->next = root;
    // root->next = NULL;
    return root;
}

Node* reverse(Node *curr, Node *next, Node **root) {
    
}

int main() {

    Node *root = NULL;

    root = insert(root, 2);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 9);
    root = reverse(root);
    Node *temp = root;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}