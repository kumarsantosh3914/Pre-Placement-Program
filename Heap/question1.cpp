#include <iostream>
#include <stack>
using namespace std;

int calculateDepth(string preorder) {
    stack<char> stk;
    int depth = 0;
    for (char ch : preorder) {
        if (ch == 'n') {
            stk.push(ch);
        } else if (ch == 'l') {
            while (!stk.empty() && stk.top() == 'l') {
                stk.pop();
            }
            if (!stk.empty()) {
                stk.pop();
                stk.push('l');
                depth = max(depth, (int)stk.size());
            } else {
                stk.push('l');
                depth = max(depth, 1);
            }
        }
    }
    
    return depth;
}

int main() {
    string preorder = "nlnll";
    int depth = calculateDepth(preorder);
    cout << "Depth: " << depth << endl;
    
    return 0;
}