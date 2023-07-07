#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printRootToLeafPaths(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    std::vector<TreeNode*> path;
    
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        
        path.push_back(curr);  // Add the current node to the path
        
        if (curr->left == nullptr && curr->right == nullptr) {
            // If the current node is a leaf node, print the path
            for (int i = 0; i < path.size(); i++) {
                std::cout << path[i]->val;
                if (i < path.size() - 1) {
                    std::cout << "->";
                }
            }
            std::cout << std::endl;
        }
        
        if (curr->left != nullptr) {
            // If the current node has a left child, enqueue it
            q.push(curr->left);
        }
        
        if (curr->right != nullptr) {
            // If the current node has a right child, enqueue it
            q.push(curr->right);
        }
        
        if (curr->left == nullptr && curr->right == nullptr) {
            // If the current node is a leaf node, remove it from the path
            path.pop_back();
        }
    }
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->right = new TreeNode(4);
    
    // Print all root-to-leaf paths of the binary tree
    printRootToLeafPaths(root);
    
    return 0;
}