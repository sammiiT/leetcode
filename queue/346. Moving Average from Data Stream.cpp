//===類似題====

//===思路

//===
class MovingAverage{
public:
    MovingAverage(){}
    MovingAverage(int size){
        n=size;
    }
    double next(int val){
        int res =0;
//        if(arr.size()<=n){
        if(arr.size()<n){//arr.size從0開始, 所以要用<n => for(int i=0;i<n;i++)
            arr.push_back(val);
        }else {//arr.size()>n
            arr.erase(arr.begin()+0);
            arr.push_back(val);
        }
    
        for(int i=0;i<arr.size();i++){
            res+=arr[i];
        }
        return (double)res/arr.size();        
    }
private:
    vector<int> arr;
    int n;
};


int main()
{
    MovingAverage* m = new MovingAverage(3);
    
    cout<<m->next(1)<<endl;
    cout<<m->next(10)<<endl;
    cout<<m->next(3)<<endl;
    cout<<m->next(5)<<endl;
    cout<<m->next(6)<<endl;
    
    cout<<endl;

    return 0;
}
