#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convertToDoublyLinkedList(TreeNode* root, TreeNode*& prev, TreeNode*& head) {
    if (root == nullptr) {
        return;
    }
    
    convertToDoublyLinkedList(root->left, prev, head);
    
    if (prev == nullptr) {
        head = root; // Set the head of the doubly linked list
    } else {
        prev->right = root;   // Set the right pointer of the previous node
        root->left = prev;    // Set the left pointer of the current node
    }
    
    prev = root;    // Update the previous node
    
    convertToDoublyLinkedList(root->right, prev, head);
}

void printDoublyLinkedList(TreeNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);
    
    // Convert the binary tree to a doubly linked list
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    convertToDoublyLinkedList(root, prev, head);
    
    // Print the doubly linked list
    printDoublyLinkedList(head);
    
    return 0;
}