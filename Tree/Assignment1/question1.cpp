#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxSubtreeSum(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = maxSubtreeSum(root->left, maxSum);
    int rightSum = maxSubtreeSum(root->right, maxSum);
    
    int subtreeSum = leftSum + rightSum + root->val;
    maxSum = std::max(maxSum, subtreeSum);
    
    return subtreeSum;
}

int findMaxSubtreeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int maxSum = std::numeric_limits<int>::min();
    maxSubtreeSum(root, maxSum);
    
    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);

    int maxSum = findMaxSubtreeSum(root);
    std::cout << "Maximum subtree sum: " << maxSum << std::endl;

    return 0;
}