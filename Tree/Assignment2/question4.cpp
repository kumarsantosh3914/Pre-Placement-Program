#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNodesAtSameLevel(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (i < size - 1) {
                curr->next = q.front();
            }
            
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }
}

void printNextPointers(TreeNode* root) {
    while (root != nullptr) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            std::cout << curr->val;
            if (curr->next != nullptr) {
                std::cout << " -> ";
            } else {
                std::cout << " -> -1";
            }
            curr = curr->next;
        }
        std::cout << std::endl;
        root = root->left;
    }
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    // Connect nodes at the same level
    connectNodesAtSameLevel(root);
    
    // Print the "next" pointers
    printNextPointers(root);
    
    return 0;
}