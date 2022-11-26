(*)
right初始化, 可以是right = nums.size(),或right = nums.size()-1;
left初始化, left = 0;

left進一個step永遠是 left = m+1;
right進一個step是right = m 或 right = m-1; 

返回 left, right或right-1

(*)
while(left<=right)  對應right = nums.size()-1; 對應 right = m-1;
解在左邊界, 因為right=m-1; 所以left會在right的右邊(left>right)=>跳出迴圈
   =>在right=m條件下, 若搜尋的解發生在左邊界; 且target不存在左邊界時, 運算會跳不出迴圈
解在右邊界, 因為left =m+1; 所以left會在right的右邊(left>right)=>跳出迴圈

(*)
while(left<right) 對應right = nums.size();  對應right = m;  
解在左邊界, 因為right=m, 所以(left==right)=>跳出迴圈
    => 每次計算m, 因為元素奇偶數, 所以m會自動往前移一格 
解在右邊界, 因為left=m+1, 所以(left==right)=>跳出迴圈


(*)當target不存在sorting array中, 且要求出插入的位址, 則上述兩點必須牢記


(*)===== 找不到,回傳-1 ======
int binarySearch(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){//用nums.size()-1, 則要用l<=r, 才能找到邊界(最左邊),(最右邊)
        int m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;//會觸發while break
        }else if(nums[m]>target){
            r = m-1;//會觸發while break
        }else{
            return m;
        }
    }
    return -1;//找不到,回傳-1
}

(*)===== 若找不到,要回傳一個位置 ======
int binarySearch(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int m;
//while(l<=r); 最後l可能會大於r, r可能會小於l    
    while(l<=r){
        m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;
        }else if(nums[m]>target){
            r = m-1;
        }else{
            return m;
        }
    }
    return m;//找不到,回傳-1
}

//==============================================================
int binarySearch(vector<int>& nums, int target){//用在最靠近的element
    int l = 0;  
//    int r = nums.size()-1;
    int r = nums.size();
    int m = 0;
    
    while(l<r){//最後l超過r, 不能回傳l或r; 最後l會等於r
        m = l + (r-l)/2;
        if(nums[m]<target){
            l = m+1;
        }else{//nums[m]>=target=> r移動可以不用減1, 因為個數的會造成m移動
            r = m;//等於放在nums[m]> target區間
        }
    }
    return r;//return r就是靠近 right的那一個index
}



//==============================================================
找到第一個(>=)不小於target的數值=> return r, 找到最後一個小於目標值的數=> return r-1
因為 (nums[m]>=target){r = m;}=> 遇到target, 或大於target; 所以 ">="
int binarySearch(vector<int>& nums, int target){//用在最靠近的element
    int l = 0;  
    int r = nums.size()-1;
    int m = 0;
    
// while(l<=r) 無法跳出迴圈    
    while(l<r){//最後l超過r, 不能回傳l或r; 最後l會等於r
        m = l + (r-l)/2;
//        if(nums[m]<=target){//等於的時候, l 不能(m+1)
        if(nums[m]<target){
            l = m+1;
//            cout<<"l="<<l<<" r="<<r<<" m="<<m<<endl;
        }else{//nums[m]>=target=> r移動可以不用減1, 因為個數的會造成m移動
            r = m;//等於放在nums[m]> target區間
//            cout<<"l "<<l<<" r="<<r<<" m="<<m<<endl;
        }
    }
    return r;//return r就是靠近 right的那一個index
}

查找第一個大於目標值的數值 return r; 可變形為查找最後一個部大於目標值的數 return r-1; 
因為if(nums[m]<=target) left = m+1; 即使遇到等於target, left還是要m+1; 所以會找到第一個大於target的數值

int binarySearch(vector<int>& nums, int target){
   int left=0, right = nums.size();
   while(left<right){
      int m = left + (right-left)/2;
      if(nums[m]<=target) left = m+1;
      else right = m;
   }
   return r;
}



