bool checkValidString(string s)
{
    int Cmax = 0, Cmin = 0;
    for (auto &it : s)
    {
        if (it == '(')
        {
            Cmax++;
            Cmin++;
        }
        else if (it == ')')
        {
            Cmax--;
            Cmin--;
        }
        else if (it == '*')
        {
            Cmax++;
            Cmin--;
        }

        if (Cmax < 0)
            return false;
        Cmin = max(0, Cmin);
    }
    return Cmin == 0;
}