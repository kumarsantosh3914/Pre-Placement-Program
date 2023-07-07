#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* node, std::vector<int>& values) {
    if (node != nullptr) {
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
}

void constructBST(TreeNode* node, std::vector<int>& values, int& index) {
    if (node != nullptr) {
        constructBST(node->left, values, index);
        
        node->val = values[index];
        index++;
        
        constructBST(node->right, values, index);
    }
}

void convertToBST(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    std::vector<int> values;
    inorderTraversal(root, values);
    
    int index = 0;
    constructBST(root, values, index);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(4);

    // Convert the binary tree into a binary search tree
    convertToBST(root);

    // Print the inorder traversal of the transformed tree (should be sorted)
    inorderTraversal(root);

    return 0;
}