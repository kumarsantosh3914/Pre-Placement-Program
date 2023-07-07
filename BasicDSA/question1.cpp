int romanToInt(string str) {
    map<char,int> m;
    m.insert({'I',1});
    m.insert({'V',5});
    m.insert({'X',10});
    m.insert({'L',50});
    m.insert({'C',100});
    m.insert({'D',500});
    m.insert({'M',1000});
       
    int n=str.size();
    char ch=str[n-1];
     int sum=m[ch];
     int prev=sum;
     for(int i=str.size()-2;i>=0;i--)
     {
         char ch=str[i];
         if(m[ch]>=prev)
         {
             sum+=m[ch];
         }
         else
         {
             sum-=m[ch];
         }
         prev=m[ch];
     }
    return sum;
}