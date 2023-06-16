bool backspaceCompare(string s, string t)
{
    int n = s.length() - 1;
    int m = t.length() - 1;
    int sSkip = 0, tSkip = 0;
    while (n >= 0 || m >= 0)
    {
        while (n >= 0)
        {
            if (s[n] == '#')
            {
                sSkip++;
                n--;
            }
            else if (n > 0)
            {
                sSkip--, n--;
            }
            else
            {
                break;
            }
        }

        while (m >= 0)
        {
            if (t[m] == '#')
            {
                sSkip++, m--;
            }
            else if (m > 0)
            {
                sSkip--, m--;
            }
            else
            {
                break;
            }
        }

        if (n >= 0 && m >= 0 && s[n] != t[m])
            return false;
        if ((n >= 0) != (m >= 0))
            return false;
        n--;
        m--;
    }
    return true;
}