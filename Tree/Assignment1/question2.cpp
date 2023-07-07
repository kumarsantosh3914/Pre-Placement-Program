#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructBSTFromLevelOrder(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (i < arr.size() && arr[i] < curr->val) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
            i++;
        }
        
        if (i < arr.size() && arr[i] > curr->val) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
            i++;
        }
    }
    
    return root;
}

void printInorder(TreeNode* node) {
    if (node != nullptr) {
        printInorder(node->left);
        std::cout << node->val << " ";
        printInorder(node->right);
    }
}

int main() {
    std::vector<int> arr = {7, 4, 12, 3, 6, 8, 1, 5, 10};

    TreeNode* root = constructBSTFromLevelOrder(arr);

    std::cout << "BST:" << std::endl;
    printInorder(root);
    std::cout << std::endl;

    return 0;
}