bool isConsonant(char &ch)
{
    ch = tolower(ch);
    return isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int countConsonants(string &str)
{
    int cnt = 0;
    for (auto ch : str)
    {
        if (isConsonant(ch))
        {
            cnt++;
        }
    }
    return cnt;
}