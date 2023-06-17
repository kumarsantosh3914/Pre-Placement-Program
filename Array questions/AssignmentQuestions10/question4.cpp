int calculateLength(string str)
{
    // Base case: an empty string has length 0
    if (str.empty())
    {
        return 0;
    }
    return 1 + calculateLength(str.substr(1));
}