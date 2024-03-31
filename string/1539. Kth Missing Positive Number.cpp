//===more challenage===

//===思路====

int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int lost =0;
        if(arr[0]!=1){
            lost = arr[0]-1;
        }
        if(lost>=k){
            return k;
        }
        
        for(int i=1; i<arr.size(); ++i){
            if(arr[i]==arr[i-1]) continue;
            int previous_lost = lost;
            lost+=(arr[i]-arr[i-1]-1);
            if(lost>=k){
                return arr[i-1] + (k-previous_lost);
            }
        }
        return arr[size-1]+(k-lost);
}
