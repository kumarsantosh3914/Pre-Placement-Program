bool validMountainArray(vector<int> &arr)
{
    if (arr.size() < 3)
        return false;
    int left = 0;
    int right = arr.size() - 1;
    while (left < arr.size() - 1 && arr[left] < arr[left + 1])
        left++;
    while (right > 0 && arr[right] < arr[right - 1])
        right--;
    if (left == right && left != 0 && right != arr.size() - 1)
        return true;
    return false;
}