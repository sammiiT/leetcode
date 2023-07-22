//====類似題===
607. Sales Person
855. Exam Room
2365. Task Scheduler II

//===思路===
(*)由計算0的個數,來判斷距離
    
1.兩邊為1的情況    
奇數個=> (n/2)+1 =>3/2+1=1+1=2
偶數個=> n/2 => 4/2=2

    
2. 判斷邊界0情況
如果邊界為0, 則不由兩邊1的情況做判斷

000010000
    
int maxDistToClosest(vector<int>& seats) {
    int i,j;
    int res = 0;
    int count = 0;

    for(j=0,i=0; i<seats.size(); ++i){
        if(seats[i]==0) {//遇到"0",計算0的個數
            count++;        
        }else{//遇到"1"
            if(seats[j]==0){//如果邊界index_0為0;
                res = max(res,count);
            }else{
                res=max(res,(count%2)?(count/2+1):(count/2));
            }
            count=0;//重新reset 0個數
            j=i;//update j, 不再是index0    
        }
    }
    res = max(res,count);
    return res;
}
//===思路2===
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
