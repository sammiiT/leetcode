//===more challange===
466. Count The Repetitions
292. Nim Game
2938. Separate Black and White Balls
//===思路===


int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        string substr;
        int res = 0;

        for(int i=0;i<=str.size()-k; ++i){
            substr = str.substr(i,k);
            int val = stoi(substr);
            if(val){
                res+=(num%val)?0:1;
            }
        }
        return res;
}
