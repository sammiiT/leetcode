//===more challenge===
1436. Destination City
1153. String Transforms Into Another String
869. Reordered Power of 2

//===思路===
class DataStream {
public:
    DataStream(int value, int k) {
        _value = value;
        _k = k;
    }    
    bool consec(int num) {
        dq.push_back(num);
        ++ump[num];
        if(dq.size()==_k){
            if(ump.count(_value) && ump[_value]==_k) return true;
            else return false;
        } else if(dq.size()<_k){
            return false;
        }

        //dq.size()>_k
        int dqf = dq.front();
        dq.pop_front();
        if(--ump[dqf]==0) ump.erase(dqf);
        if(ump.size()==1 && ump.count(_value)) return true;
        
        return false;
    }
private:
int _value;
int _k;//window_size
deque<int> dq;
unordered_map<int,int> ump;//value, count
};

//===寫法2===
class DataStream {
public:
    DataStream(int value, int k) {
        _value = value;
        _k = k;
        cnt = 0;
    }
    
    bool consec(int num) {
        if(num==_value){
            cnt++;    
        }else{
            cnt = 0;
        }
        if(cnt<_k) return false;
        return true;
    }

private:
int _value;
int _k;//window_size
int cnt;
};
