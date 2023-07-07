#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* flipBinaryTree(Node* root) {
    // Base case: If the root is null or it is a leaf node, return the root
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return root;
    }
    
    // Recursively flip the left and right subtrees
    Node* flippedLeft = flipBinaryTree(root->left);
    Node* flippedRight = flipBinaryTree(root->right);
    
    // Flip the current root by swapping its left and right pointers
    root->left = flippedRight;
    root->right = flippedLeft;
    
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    // Print the original binary tree
    std::cout << "Original binary tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;
    
    // Flip the binary tree
    Node* flippedRoot = flipBinaryTree(root);
    
    // Print the flipped binary tree
    std::cout << "Flipped binary tree: ";
    inOrderTraversal(flippedRoot);
    std::cout << std::endl;
    
    return 0;
}