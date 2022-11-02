class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists,0,lists.size()-1);//use recursive
    }
    
    ListNode* helper(vector<ListNode*>& lists, int start, int end){
        if(start>end) return NULL;
        if(start==end)return lists[start];
        
        int mid = start + (end - start)/2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right= helper(lists,mid+1,end);
        return mergeTwoList(left,right);
    }
    //merge sort
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        //如果兩個都為NULL,則return l1, l2都一樣
		if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoList(l1->next,l2);
            return l1;
        }else{//l1->val>=l2->val
            l2->next = mergeTwoList(l1,l2->next);
            return l2;
        }
    } 
};
        
ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = 0;
        int ref = INT_MAX;
        int min_idx = 0;
        int flag = 0; 
        ListNode **tmp;                                                                                
        
        ListNode vnode(-1);        
        ListNode *iter;                                                                   
        iter = &vnode;                                                                    
        n = lists.size();                                                                         
        if(!n) return NULL;
        
        tmp = (ListNode**)malloc(sizeof(ListNode*)*n);/*tmp[0],..., tmp[n-1]*/ 
        for(int i=0; i<n; i++){
            tmp[i] = lists.at(i);//記錄每一個list的第一個node位址    
        }
        
        do { 
            flag = 0;  
            for(int i=0; i<n; i++){//搜尋最小值
                if(tmp[i]){//check existance 
                    flag = 1; 
                    if(tmp[i]->val<=ref){//check value
                        ref = tmp[i]->val; 
                        min_idx = i;                  
                    }
                }
            }   
            if(flag){//連結最小值的節點
                iter->next = tmp[min_idx];            
                iter = iter->next;                    
                tmp[min_idx] = tmp[min_idx]->next;    
                ref = INT_MAX;                        
            }
        } while(flag);//如果所有的節點都是NULL,則跳出迴圈
	
        return vnode.next;    
 }




Input:
[
	1->4->5,
	1->3->4,
	2->6
]
Output : 1->1->2->3->4->4->5->6
