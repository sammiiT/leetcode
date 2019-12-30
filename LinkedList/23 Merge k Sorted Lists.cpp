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

Input:
[
	1->4->5,
	1->3->4,
	2->6
]
Output : 1->1->2->3->4->4->5->6