#include <iostream>
using namespace std;
struct Node
{
 int data;
 Node*left;
 Node*right;
};

Node * create(int data)
{
    Node* newNode= new Node();
    newNode->data=data;
    newNode->left=newNode->right=nullptr;
    return newNode;
}


Node* insert(Node* root, int data)
{
    if (root == nullptr) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}


Node* searchNode(Node* root, int key)
{
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return searchNode(root->right, key);
    }
    return searchNode(root->left, key);
}


Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}


Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{

    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Inorder traversal of the given Binary Search "
            "Tree is: ";
    inorderTraversal(root);
    cout << endl;
    
    root = deleteNode(root, 20);
    cout << "After deletion of 20: ";
    inorderTraversal(root);
    cout << endl;
    
    root = insert(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;
    
    Node* found = searchNode(root, 25);
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }
    return 0;
}