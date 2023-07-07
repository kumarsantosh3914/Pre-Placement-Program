#include <iostream>
#include <queue>
using namespace std;

bool isLevelOrderBST(int arr[], int n) {
    if (n == 0) {
        return true;
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push({arr[0], {INT_MIN, INT_MAX}});
    
    int i = 1;
    while (!q.empty() && i < n) {
        int curr = q.front().first;
        int minValue = q.front().second.first;
        int maxValue = q.front().second.second;
        q.pop();
        
        if (arr[i] < curr && arr[i] > minValue) {
            q.push({arr[i], {minValue, curr}});
            i++;
        }
        
        if (arr[i] > curr && arr[i] < maxValue) {
            q.push({arr[i], {curr, maxValue}});
            i++;
        }
    }
    
    return i == n;
}

int main() {
    int arr1[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    if (isLevelOrderBST(arr1, n1)) {
        cout << "Output1 : Yes" << endl;
    } else {
        cout << "Output1 : No" << endl;
    }
    
    int arr2[] = {11, 6, 13, 5, 12, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    if (isLevelOrderBST(arr2, n2)) {
        cout << "Output2 : Yes" << endl;
    } else {
        cout << "Output2 : No" << endl;
    }
    
    return 0;
}