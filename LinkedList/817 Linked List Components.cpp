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


