string helper(string &str, int &idx)
{
    string ans;
    while (idx < str.size() && str[idx] != ']')
    {
        if (!isdigit(str[idx]))
            ans += str[idx++];
        else
        {
            int k = 0;
            while (idx < str.size() && isdigit(str[idx]))
                k = k * 10 + str[idx++] - '0';
            // because digit always accompained by '['
            idx++;
            string decode = helper(str, idx);
            // and accompanied by closing ']' too
            idx++;
            while (k-- > 0)
                ans += decode;
        }
    }
    return ans;
}

string decodeString(string s)
{
    int idx = 0;
    return helper(s, idx);
}