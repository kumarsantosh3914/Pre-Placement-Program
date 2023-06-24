string reverseWord(string str)
{
    // Your code here
    int n = str.length();
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
    return str;
}