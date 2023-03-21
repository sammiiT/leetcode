//===類似題===
623. Add One Row to Tree
358. Rearrange String k Distance Apart
1953. Maximum Number of Weeks for Which You Can Work
2323. Find Minimum Time to Finish All Jobs II
//===思路===

//======
int helper0(vector<char>& tasks, int n) {
    vector<int> cnt(26,0);
    int mx;
    int len = tasks.size();
    for(char a: tasks){
        cnt[a-'A']++;
    }    
    sort(cnt.begin(),cnt.end());
    mx = cnt[25];
    int i=25;
    while(i>=0 && cnt[i]==mx) --i;
    //for(int i=25; i>=0&&cnt[i]==mx;) --i;
    return max(len,(mx-1)*(n+1)+25-i);
}

int helper1(vector<char>& tasks, int n){
    vector<int> cnt(26,0);
    for(char a:tasks) cnt[a-'A']++;
    sort(cnt.rbegin(),cnt.rend());
    int idle = (cnt[0]-1)*n;
    for(int i=1; i<26; i++){
        idle = idle - min(cnt[0]-1,cnt[i]);
    }
    return tasks.size() + max(idle,0);
}

int leastInterval(vector<char>& tasks, int n) {
    return helper1(tasks,n);
}
