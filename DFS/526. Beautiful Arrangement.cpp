//===類似題===
667. Beautiful Arrangement II
2616. Minimize the Maximum Difference of Pairs
518. Coin Change II
1970. Last Day Where You Can Still Cross

//===思路===
[1,2] => 從1再2
1  1/1
2  2/2


[2,1] => 從2再1
2  2/1
1  2/1

(*)visit過的數字不能再被使用
(*)每次進入下一層,都從頭開始
(*)如果i滿足題意 perm[i]%i==0   或 i%perm[i], 則繼續, 往下一層執行
- 直到count==n, 代表beautitul arrangement
-如果中途有一個不滿足, 則return. 


//=====
void helper(int choose,//perm[level]
            int level,//level
            int n,
            vector<int>& visited, 
            int count, 
            int& res){
    if((choose!=0 && level!=0) && (choose%level!=0 && level%choose!=0)) return;
    if(count==n) {
        res++;
        return;
    }
    for(int i=1; i<=n; ++i){
        if(visited[i]) continue;  
        visited[i]=1;
        helper(i, level+1, n, visited, count+1, res);
        visited[i]=0;
    }
}

int countArrangement(int n) {
    vector<int> visited(n+1,0);
    int res = 0;
    helper(0,0, n, visited, 0, res);
    return res;        
}

//====思路2===
int helper1(int perm, int i, vector<int>& visited){
    if(i==(visited.size()-1)) return 1;
    int count = 0;
    for(int j=1; j<visited.size(); ++j){
        if(visited[j]) continue;
        visited[j] = 1;
        
        if(j%(i+1)==0 || (i+1)%j==0) //再同一層中做判斷,不要放到下一層;放到下一層會有初始值問題,如同思路1
            count += helper1(j,i+1,visited);
        visited[j] = 0;
    }
    return count;
}

int countArrangement(int n) {
    vector<int> visited(n+1,0);
    return helper1(0,0,visited);
}
