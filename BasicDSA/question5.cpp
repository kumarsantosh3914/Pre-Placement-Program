bool isUgly(int n) {
        if(n <= 0) return false;
        while(n > 1) {
            if(n % 2 == 0) n /= 2;
            else if(n % 3 == 0) n /= 3;
            else if(n % 5 == 0) n /= 5;
            else break;
        }
        // cout<<n<<endl;
        return (n == 1);
    }