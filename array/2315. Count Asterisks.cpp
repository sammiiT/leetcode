//===類似題===
2751. Robot Collisions
1023. Camelcase Matching
1554. Strings Differ by One Character
2730. Find the Longest Semi-Repetitive Substring

//===思路===

//====
int countAsterisks(string s) {
    int flag=0;
    int res = 0;

    for(int i=0; i<s.size(); ++i){
        if(s[i]=='|') flag++;
        
        if(flag%2) continue;
        else {//flag%2==0
            res+=(s[i]=='*');
        }
    }
    return res;
}

