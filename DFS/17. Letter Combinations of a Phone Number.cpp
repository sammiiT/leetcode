//===類似題===
18. 4Sum
401. Binary Watch
2266. Count Number of Texts

//===思路===
(*)DFS 算法
- 每一個節點都是root, 每一個root的child都是一種"解"

(*)string中的每一個digit都要被羅列在"解"中, 所以不會有節點"跳躍"選擇
ex: 1,2,3,4,5 (以每一個節點作為root,用dfs運算;   當以"1"為root會有如下情況)
1,2,3,4,5
1,3,4,5
1,4,5  
1,5
  
-陣列總數會越來越少
(*)此題不能用上述邏輯去運算  

1.建立每一個digit對應的列表
'2' = 3 =>[a,b,c]
'3' = 3 =>[d,e,f]
'4' = 3 =>[g,h,i]
'5' = 3 =>[j,k,l]
'6' = 3 =>[m,n,o]
'7' = 4 =>[p,q,r,s]
'8' = 3 =>[t,u,v]
'9' = 4 =>[w,x,y,z]

2.總共有n個digits,所以配對中一定要有n個
- n=digits.size();
- digist order=> "sequence"; 依據digits的排列,有序(sequence) 

3.每進入一個level,就對應到一個新的root節點
-level初始值為0, 當level==n時代表沒有多餘的節點; 將其中的一個string帶入res
-每一個level對應到digit的letter陣列; 會有不同的解
ex: 2,3
(a,b,c) (d,e,f)   
 |       | \  |---下一個level的第三個節點(a,f) 
選定      \  下一個level的第二個節點(a,e)  
           下一個level的第一個節點(a,b)

4.dfs遍歷完,即為解  
//====  
class Solution {
public:

void dfs(string& digits, int level, string& out, vector<string>& res){
//    if(digits.size()==0) return;
    if(level==digits.size()){
        res.push_back(out);
        return;
    }
    
    vector<char> vec = phone[digits[level]-'2'];//每一個level對應到digit的所有letter
    for(int i=0; i<vec.size(); ++i){
        out.push_back(vec[i]);
        dfs(digits,level+1,out,res);//進入下一個節點
        out.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string out;
        if(digits.size()==0) return res;
        dfs(digits,0,out,res);
        return res;   
    }

private:
vector<vector<char>> phone ={
    {'a','b','c'},  //2 ....index 0
    {'d','e','f'},  //3 ....index 1 
    {'g','h','i'},  //4 ....index 2
    {'j','k','l'},  //5 ....index 3
    {'m','n','o'},  //6 ....index 4
    {'p','q','r','s'},//7 ..index 5
    {'t','u','v'},  //8 ....index 6
    {'w','x','y','z'},//9 ..index 7
};
};
