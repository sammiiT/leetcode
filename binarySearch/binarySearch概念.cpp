/****************************
*回傳是否有找到target  
*沒找到target,回傳-1
*有找到回傳index; 判斷式中的等於選項獨立出來.
*****************************/
(*)===== 找不到,回傳-1 ======
int binarySearch(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;

//找不到的時候, (l>r)跳出迴圈
    while(l<=r){//用nums.size()-1, 則要用l<=r, 才能找到邊界(最左邊),(最右邊)
        int m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;//會觸發while break
        }else if(nums[m]>target){
            r = m-1;//會觸發while break
        }else{
            return m;//一個跳出迴圈
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
    return m;//回傳一個位址, 
}

/******************************************************
* 討論計算條件邊界:
* 目的: 跳出迴圈的最後數值,和此數值的意義 
* left=0, right=nums.size(), while(left<right) => 最後求出的值是lower_bound
* left=0, right=nums.size()-1, while(left<=right)=> 最後求出的值是lower_bound
*******************************************************/
(*)----- left=0, right=nums.size()-1, while(left<=right) -----
while(left<=right)  對應right = nums.size()-1; 對應 right = m-1;
解在左邊界, 如果right=m-1; 所以left會在right的右邊(left>right)=>跳出迴圈
           如果right=m, 若搜尋的解發生在左邊界; 且target不存在左邊界時, 運算會跳不出迴圈
解在右邊界, 因為left =m+1; 所以left會在right的右邊(left>right)=>跳出迴圈

- 此判斷條件是用來搜尋target是否存在於數列中,會一併搜尋(left==right)的情況是不是target 
- 如果用(left<right), 則一定會有一個解, 此解是lower_bound, 而且不會判斷到left==right的情況

(*)---- left=0, right = nums.size(), while(left<right) -----
while(left<right) 對應right = nums.size();  對應right = m;  
解在左邊界, 因為right=m, 所以(left==right)=>跳出迴圈
          => 每次計算m, 因為元素奇偶數, 所以m會自動往前移一格 
解在右邊界, 因為left=m+1, 所以(left==right)=>跳出迴圈

(*)當target不存在sorting array中, 且要求出插入的位址, 則上述兩點必須牢記

//=======分析==============
=>解有可能存在,有可能不存在陣列中
=>左極限(左邊界) index=0;  右極限(右邊界) index=nums.size()-1, 最大的index
=>運算描述句為
if(nums[m]<target) l=m+1;
else r=m;

(*) r = nums.size();   while(l<r)
--當target超出右極限, 給l移到右極限的機會;
最後l==r, 且值為nums.size() ; 此解為lower_bounded描述 


(*) r= nums.size(); while(l<=r)  =======>有風險的描述
--當target超出右極限, 運算會出錯(1); 會有segmentation fault存在
當l==r時, 已經超出了 [num.size()-1]索引範圍; 所以要修正上面條件範圍 => r= nums.size()-1
--當target存在, 運算會出錯(2)
找到target, l會等於r, 接下來求出的m會一直在同一個數值, 導致跳不出迴圈


(*)r= nums.size()-1; while(l<=r) =======>有風險的描述
--當target超出右極限, l==r時會, 再運算一次, 若沒找到 最後 l>r, 跳出回圈
--當target存在, 運算出錯, l==r時, m會一直在同一個數值,導致跳不出迴圈
  ex:  if(nums[m]<target) l=m+1; 
       else //nums[m]>=r 
           r=m;  

(*) r = nums.size()-1; while(l<r) =======> 有風險的描述
--當 target剛好在右極限, 可以找到解, 剛好在l==r的時候
--當target超出右極限,找到的解,是右極限的位址, 但是錯誤的

r=nums.size()會有超出索引範圍的狀況
while(l<=r)會有跳不出迴圈的狀況;要搭配break敘述或在每次r和l的遷移都要做+1或-1的運算

//===討論 0-index和1-index的 數字中點====
(*)計算中點(0-index); 用first_middle => m=l+(r-l)/2;
index [0], [1], [2], [3], [4], [5], [6], [7], [8], [9]
value  1,   2,   3,   4,   5,   6,   7,   8,   9,   10
middle = 0+(9-0)/2 = 4 (index) => first_middle index
                               => first_middle value = [4] = 5

(*)計算中點(1-index); 用first_middle => m=l+(r-l)/2;
index [1], [2], [3], [4], [5], [6], [7], [8], [9], [10]
value  1,   2,   3,   4,   5,   6,   7,   8,   9,   10
1+(10-1)/2 = 5 (index) => first_middle index
                       => first_middle value = [5] = 5

//===討論 r=nums.size()-1 和 r=nums.size()的陣列中點====
(*)r=nums.size()-1 => 求得的, 是first_middle
index [0], [1], [2], [3], [4], [5], [6], [7], [8], [9]
value  1,   2,   3,   4,   5,   6,   7,   8,   9,   10
middle = 0+(9-0)/2=4, first_middle index
    
(*)r=nums.size() => 求得的, 是second_middle
index [0], [1], [2], [3], [4], [5], [6], [7], [8], [9]
value  1,   2,   3,   4,   5,   6,   7,   8,   9,   10
middle = 0+(10-0)/2=5, second_middle index
    

/***********************************************
* 分析 first_middle和second_middle對運算的影響
* first_middle:  m = l + (r-l)/2;
用first_middle做運算, 對l的更新,必須是 l=m+1 ;多位移一個位置
因為如果l和r相差1的狀況,first_middle的更新會一直停在原l位置,導致陷入無窮迴圈, 沒辦法從while(l<r)中跳出來.
*
* second_middle: m = l + (r-l+1)/2;
*
************************************************/                      
int binarySearch(vector<int>& nums, int target){//用在最靠近的element
    int l = 0;  
//    int r = nums.size()-1;
    int r = nums.size();
    int m = 0;
    while(l<r){//最後l超過r, 不能回傳l或r; 最後l會等於r , lower_bounded element
        m = l + (r-l)/2;
        if(nums[m]<target){//[m]在target左邊, 所以要往右邊移動
            l = m+1;//m+1原因: 偶數個,m會永遠落在first middle, 不會往下一個跳; 所以要m+1 
        }else{//[m]在target右邊, 所以要往左邊移動
               //nums[m]>=target=> r移動可以不用減1, 因為個數的會造成m移動
              //由(>=)的條件, 解有可能落在索引m上, 所以r=m;=> lower_bounded
              //或,因為r不會因為first middle而停在同一個位置, 在奇數或偶數求出的m, r都可以往前移動
            r = m;//等於放在nums[m]> target區間
        }
    }
    return r;//return r就是靠近 right的那一個index
}

(*)左極限,右極限來看邏輯=> 左極限 idx=0, 右極限 idx=(n-1); 
r = nums.size(); 搭配 while(l<r)
--跳出迴圈, 當(l==r); 最後 (l==r) =>不管怎樣, 都會算到(l==r)才停止

(*)first_middle或second_middle 
l = m+1 , r = m 是因為m的運算式為first_middle運算式 => m = l+(r-l)/2;
所以才會遇到 l = m的時候,有可能會跳不出迴圈, 一定要是 l = m+1;

如果是用second_middle運算, 則可以用l=m; 不會發生跳不出迴圈, 因為l都會被update
m = l+(r-l+1)/2; //second_middle, 此時對l和r的更新式如下
l = m;   ([i]<=target) => 有等於的符號不用+1或-1,但在l取解會有跳不出迴圈的問題
r = m-1; ([i]>target)  
???? 用此方法求不出lower_bounded 


//=== first_middle來解題目 ====
(*)lower_bounded (假設有可能沒有"解")
int r = nums.size();
while(l<r) { ...
=> {1,3,4,6,7,9}; target = 10    
=> 回傳 6
           
(*)類lower_bounded(須先假設題目一定有"解")=>因為下列描述不會讓l跳出(nums.size()-1)
int r = nums.size()-1;
while(l<r) {
=> {1,3,4,6,7,9}; target = 10    
=> 回傳 5 =>因為r最大到[5], 所以當l==r==5的時候,就跳出迴圈
=>修正: 將 r=nums.size();              
=>若 r=nums.size()-1; while(l<=r) 還是會出錯, 因為最後不滿足條件 (l=6)>=(r=5)           
  最後回傳還是r, r並沒有改變;所以錯誤.

//===用seconde_middle來求 解===             
 int binarySearch(vector<int>& nums, int target){
    int l = 0, r = nums.size();
    int m =0;
    while(l<r){
        m = l+(r-l+1)/2;
        if(nums[m]<=target) l = m;
        else //nums[m]>target
            r=m-1;
    }
    return l;
}

/***********************
first_middle , second_middle 運算定義, 由最後的index來定義
************************/
0 1 2 3 4 5
6,5,7,4,9,3


first_middle: r是剛好在(size-1) ... 0-index
m =l+(r-l)/2 => 0+(5-0)/2 = 2 ...first_middle


second_middle: r剛好在(size) .... 0-index
m =l+(r-l)/2 =>  0+(6-0)/2 =3 ...second_middle



/***********************
* 討論 left 或 right 更新 計算式:
* if( f(m) >= target)// target在m的左邊, 所以要更新right; 因為first_middle算法, 所以right更新直接等於m 
*     right = m;     //要靠近target, 要更新right 
*
* if( f(m) < target) // target在m的右邊,所以要更新left; 且first_middle算法,所以left更新要+1
*     left=m+1;      //要越來越靠近target, 所以要更新left
*
* first_middle運算時,判斷式的"等號"放在 right=m 的更新上; 
* -這樣"解"才會落在right位置,如果等號放在 left = m+1; 最後的"解"會落在(m+1)上
* -因為first_middle運算會自動將right更新一個單位, 但left在(right-left=1)時, left不會自動更新一個單位
*/

//==== 降冪排列,用上述觀念 定義 right和left的更新
int binarySearchDescend(vector<int>& nums, int target){
    int l=0,r=nums.size();
    while(l<r){
        int m = l+(r-l)/2;
        if(nums[m]<=target) r = m; //等於判斷式放在 r=m是因為在firste_middle運算中會自動update一個單位
        else//>=target (x) => >target
            l=m+1;
    }
    return r;
}

//==============================================================
(*)找到第一個(>=)不小於target的數值=> return r, 找到最後一個小於目標值的數=> return r-1
因為 (nums[m]>=target){r = m;}=> 遇到target, 或大於target; 所以 ">="

(*) (nums[m]>=target) r = m;    return right;   
1. 中間值會落在r 或 大於中間值的數會落在r
2. 回傳 r; 會滿足(1)的描述

=>第一個不小於target的的位址
=>最後一個小於target的位址

int binarySearch(vector<int>& nums, int target){//用在最靠近的element
    int l = 0;  
//    int r = nums.size()-1;//配上while(l<r)會有錯誤, 因為如果target發生在右邊界, 會導致找不到"解"?==>還是可以, 因為r初始值就是nums.size()-1
    int r = nums.size();
    int m = 0;
    
// while(l<=r) 無法跳出迴圈    
    while(l<r){//最後l超過r, 不能回傳l或r; 最後l會等於r
        m = l + (r-l)/2;
//        if(nums[m]<=target){//等於的時候, l 不能(m+1)
        if(nums[m]<target){//在target左邊, 所以要往右邊移動 
            l = m+1;//+1 是因為 first_middle
//            cout<<"l="<<l<<" r="<<r<<" m="<<m<<endl;
        }else{//nums[m]>=target=> r移動可以不用減1, 因為個數的會造成m移動
              //在target右邊, 所以要往左邊移動
            r = m;//等於放在nums[m]> target區間
//            cout<<"l "<<l<<" r="<<r<<" m="<<m<<endl;
        }
    }
    return r;//return r就是靠近 right的那一個index
}
此binary search的回傳值 => lower_bound(v.begin(),v.end(), target);
lower_bound = 找出(>=)大於或等於target的最小值的位置                         

//==========================================================
(*)查找第一個大於目標值的數值 return r; 可變形為查找最後一個不大於目標值的數 return r-1; 
因為if(nums[m]<=target) left = m+1; 即使遇到等於target, left還是要m+1; 所以會找到第一個大於target的數值

(*)(nums[m]<=target) l = m+1; return r;
1.中間值不會落在 r, 也不會落在 l(因為 l=m+1;l超過m)
2.回傳r, 會滿足(1)的描述.
 
 =>第一個大於target的數
 =>最後一個不大於target的數
   
int upper_bounded(vector<int>& nums, int target){
   int left=0, right = nums.size();
   while(left<right){
      int m = left + (right-left)/2;
      if(nums[m]<=target) left = m+1;//當target發生在m,但left=m+1,會造成找到>target的最小位址
                                     //跳出"等於"的位置
      else right = m;                //用在upper_bound
   }
   return r;//可以用 return left;????
}

int upper_bounded(vector<int>& nums, int target){
   int left=0, right = nums.size();
   while(left<right){
      int m = left + (right-left)/2;
      if(nums[m]<target) left = m+1;
      else if(nums[m]>target) right = m;
      else { 
           right = m+1;
           break;
      }                
   }
   return right;
}     
           
此binary search的回傳值 => upper_bound(v.begin(),v.end(),target)
upper_bound = 找出(>)大於target的最小值的位置

/****************************
 binary search 的 middle 選擇之討論
*****************************/
leetcode 378 Kth Smallest Element in a Sorted Matrix
(*)若以 binary-search計算, middle選擇用數值,而非index
(*)用upper_bound是因為, kth是以1st-index概念作計算, 第一個為1th, 第二為2nd.... 第k個為kth

int kthSmallest(vector<vector<int>>& matrix, int k){
     int l = matrix[0][0],r = matrix.back().back();//l和r都是以陣列的數值為依據,而非索引
     while(l<r){
        int m = l+(r-l)/2;//middle也以陣列數值為依據
        int cnt = 0;
        for(int i=0; i<matrix.size(); i++){
            //每一列的 upper_bound全部加起來, 就是所有的upper_bound=> supper position概念
            cnt = cnt + upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
        }
        if(cnt<k) l=m+1; // k是 target       
        else// cnt>=k
            r = m;
    }
    return r;
}
    
    
