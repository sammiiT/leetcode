
string helper(string s, int k){
    int cnt =0;
    string tmp;
    string res;
    int j=0;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&& s[i]<='9'){
            cnt = cnt*10 + (s[i]-'0');
            
        }else{//character
            if(tmp.size() && cnt>0){
                j+=tmp.size()*cnt;
                if((k-1)<j){
                //do something....
                   // cout<<tmp<<endl;
                    int back_step = (j-1)-(k-1)+1;
                    res=tmp[tmp.size()-back_step];
                    break;        
                }else{//(k-1)>=j
                    tmp.clear();
                    cnt = 0;
                }
            }
            tmp+=s[i];
            cout<<tmp<<endl;
        }
    }
    return res;
}
