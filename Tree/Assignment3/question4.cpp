#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areTraversalsSame(vector<int> inorder, vector<int> preorder, vector<int> postorder) {
    if (preorder.size() == 0 || postorder.size() == 0 || inorder.size() == 0)
        return true;

    // Create a map to store the index of each element in the inorder traversal
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }

    // Check if the given traversals are valid
    function<bool(int, int, int, int)> isValid = [&](int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd || postStart > postEnd)
            return true;

        // The first element in the preorder traversal is the root of the tree
        int root = preorder[preStart];

        // Find the index of the root in the inorder traversal
        int rootIndex = inorderMap[root];

        // Check if the elements in the left subtree are valid
        bool leftValid = isValid(preStart + 1, preStart + (rootIndex - postStart) + 1, postStart, rootIndex);

        // Check if the elements in the right subtree are valid
        bool rightValid = isValid(preStart + (rootIndex - postStart) + 2, preEnd, rootIndex + 1, postEnd - 1);

        return leftValid && rightValid;
    };
    return isValid(0, preorder.size() - 1, 0, postorder.size() - 1);
}

int main() {
    vector<int> inorder1 = {4, 2, 5, 1, 3};
    vector<int> preorder1 = {1, 2, 4, 5, 3};
    vector<int> postorder1 = {4, 5, 2, 3, 1};

    vector<int> inorder2 = {4, 2, 5, 1, 3};
    vector<int> preorder2 = {1, 5, 4, 2, 3};
    vector<int> postorder2 = {4, 1, 2, 3, 5};

    if (areTraversalsSame(inorder1, preorder1, postorder1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (areTraversalsSame(inorder2, preorder2, postorder2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}