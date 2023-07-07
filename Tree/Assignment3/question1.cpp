#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convertToDLL(TreeNode* node, TreeNode*& prev, TreeNode*& head) {
    if (node == nullptr) {
        return;
    }
    
    convertToDLL(node->left, prev, head);
    
    if (prev == nullptr) {
        head = node;  // Set the head of the DLL
    } else {
        prev->right = node;  // Set the next pointer of the previous node
        node->left = prev;  // Set the previous pointer of the current node
    }
    
    prev = node;  // Update the previous node
    
    convertToDLL(node->right, prev, head);
}

void printDLL(TreeNode* head) {
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
    
    // Convert the binary tree to a DLL
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    convertToDLL(root, prev, head);
    
    // Print the DLL
    printDLL(head);
    
    return 0;
}