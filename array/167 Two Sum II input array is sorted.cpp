class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> res;
            if(numbers.empty()) return res;
            
            unordered_map<int,int> m;
            res.push_back(0);
            res.push_back(0);
            for(int i=0; i<numbers.size(); ++i){
                
                
                if(m.count(target-numbers[i])){
                    res[0] = m[target-numbers[i]]+1;
                    res[1]= i+1;
                }
                m[numbers[i]]=i;
            }
            return res;
        
    }
};