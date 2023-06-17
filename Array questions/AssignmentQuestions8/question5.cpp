int compress(vector<char> &chars)
{
    if (chars.size() == 1)
    {
        return 1;
    }
    int i = 0, j = 0;
    while (i < chars.size())
    {
        int count = 1;
        while (i < chars.size() - 1 && chars[i] == chars[i + 1])
        {
            count++;
            i++;
        }
        chars[j++] = chars[i++];
        if (count > 1)
        {
            string counterStr = to_string(count);
            for (char ch : counterStr)
            {
                chars[j++] = ch;
            }
        }
    }
    return j;
}