//===類似題===
2239. Find Closest Number to Zero
999. Available Captures for Rook
1594. Maximum Non Negative Product in a Matrix

//===思路===
(*) list component 可以視為一個set
1. 用unordered_map<int,int>  紀錄nums中出現的直
2. 用unordered_set<int> 紀錄連續出現的數值:   
- 遍歷linked_list並與unordered_map<int,int>中出現的值做比較, 如果出現,則屬於component的一部分, 記錄到unordered_set<int>中
- 如果list node數值沒有出現在unordered_map中, 表示unorered_set<int>中的數值可以形成一個component , 將component數加一 

3. 回傳最後的component數
//===
int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> ump;
        unordered_set<int> st;
        int res = 0;
        ListNode* cur;
        
        for(int i:nums){
            ump[i]=1;        
        }   

        cur = head;
        while(cur){
            if(ump.count(cur->val)){
                st.insert(cur->val);//出現數值, 記錄在set中
            }else{//
                if(st.size()){//沒有出現在map中, 則將component數目加一
                   res+=1; 
                }
                st.clear();//將set做reset動作
            }
            cur = cur->next;//繼續遍歷linked-list
        }
	
        if(st.size()) res+=1;//如果set中還有數值, 要再將component數目加1
        return res;
}

//===寫法2===
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
						//兩個數列做比較
        unordered_map<int,int> m;
        int res=0;
        for(int i=0; i<G.size(); ++i){
            m[G[i]]++;
        }
        
        ListNode *cur = head;
        while(cur){
            if(!m.count(cur->val)){//cur->val不存在 G vector中
                cur=cur->next;
                continue;
            }
            res++;
            
            while(cur && m.count(cur->val)){//移動到下一個不存在的點(node)
                cur = cur->next;
            }
        }
        return res;
    }
};


Input:
head: 0->1->2->3
	G = [0, 1, 3]
	Output : 2
	Explanation :
	0 and 1 are connected, so[0, 1] and [3] are the two connected components.


Input :
	head : 0->1->2->3->4
	G = [0, 3, 1, 4]
	Output : 2
	Explanation :
	0 and 1 are connected, 3 and 4 are connected, so[0, 1] and [3, 4] are the two connected components.


