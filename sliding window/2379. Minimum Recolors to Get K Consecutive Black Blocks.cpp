int countW(string s){
        int res = 0;
        for(int i=0;i<s.size();i++){
            res+=(s[i]=='W');
        }
        return res;
}

int helper0(string blocks, int k){
        string s(k,'B'); 
        int n = blocks.size();
        int res = INT_MAX;

        for(int i=k,j=0; i<=n; i++,j++){
            string tmp = blocks.substr(j,i-j);
            if(s==tmp){
                return 0;
            }else{
                res = min(res,countW(tmp));            
            }        
        }
        return res;
}

int minimumRecolors(string blocks, int k) {
  return helper0(blocks,k);      
}
