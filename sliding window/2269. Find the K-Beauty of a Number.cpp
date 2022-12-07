    int helper0(int num, int k){
        string s = to_string(num);
        int n = s.size();
        int res = 0;

        for(int i=k,j=0; i<=n; i++,j++){
            string tmp = s.substr(j,i-j);
            if(stoi(tmp) > 0) {//會遇到0的情況, 造成除數為0
                res += (num%stoi(tmp)==0);
            }
//            if(num % stoi(tmp) ==0) res++;
        }
        return res;
    }

    int divisorSubstrings(int num, int k) {
        return helper0(num,k);
    }
