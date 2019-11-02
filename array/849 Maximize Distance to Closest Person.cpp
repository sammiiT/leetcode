class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
     
        int start=0,n=seats.size();
        int res=0;
        
        for(int i=0; i<n; ++i){
            if(seats[i]!=1) continue;
            //seats[i]=1
            if(start==0){
                res = max(res,i-start);
            }else{//start !=0;
                res = max(res,(i-start+1)/2);
            }
            start = i+1;
        }
        // res = max(res,n-start);
        // return res;
        return max(res,n-start);
    }
};