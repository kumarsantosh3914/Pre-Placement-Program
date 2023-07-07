#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->val > n1 && root->val > n2) {
        return findLCA(root->left, n1, n2);
    } else if (root->val < n1 && root->val < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int findDistance(TreeNode* root, int key, int dist) {
    if (root == nullptr) {
        return -1;
    }

    if (root->val == key) {
        return dist;
    }

    int leftDist = findDistance(root->left, key, dist + 1);
    if (leftDist != -1) {
        return leftDist;
    }

    int rightDist = findDistance(root->right, key, dist + 1);
    return rightDist;
}

int findDistanceBetweenNodes(TreeNode* root, int n1, int n2) {
    TreeNode* lca = findLCA(root, n1, n2);

    int dist1 = findDistance(lca, n1, 0);
    int dist2 = findDistance(lca, n2, 0);

    return dist1 + dist2;
}

int main() {
    // Create the Binary Search Tree
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // Find the distance between two nodes
    int node1 = 6;
    int node2 = 14;

    int distance = findDistanceBetweenNodes(root, node1, node2);

    // Print the distance
    std::cout << "The distance between the two nodes: " << distance << std::endl;

    return 0;
}