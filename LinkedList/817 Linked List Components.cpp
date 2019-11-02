class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        unordered_map<int,int> m;
        int res=0;
        for(int i=0; i<G.size(); ++i){
            m[G[i]]++;
        }
        
        ListNode *cur = head;
        while(cur){
            if(!m.count(cur->val)){
                cur=cur->next;
                continue;
            }
            res++;
            
            while(cur && m.count(cur->val)){
                cur = cur->next;
            }
        }
        return res;
        
    }
};