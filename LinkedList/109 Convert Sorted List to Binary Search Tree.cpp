//===類似題=====
110. Balanced Binary Tree
2196. Create Binary Tree From Descriptions

//===思路====
(*)同Convert Sorted Array to Binary Search Tree
-用post-order + pre-order
-每次都找second-middle
(*)每次都要找second-middle, second-middle的前一個節點,second-middle的後一節點
(*)如果遞迴帶入
-沒有節點:回傳NULL
-只有一個節點:建立一個TreeNode節點,回傳
//=====

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head){
        if(head==NULL) return NULL;
         if(head->next ==NULL) return new TreeNode(head->val);
        
        ListNode *f,*s,*pre;
        f=s=pre=head;
        while(f && f->next){//中點的second
            pre=s;
            s=s->next;
            f=f->next->next;
        }
        pre->next = NULL;
        
        TreeNode *cur = new TreeNode(s->val);
        cur->left = sortedListToBST(head);
        cur->right= sortedListToBST(s->next);
        
        return cur;
    }
     TreeNode* sortedListToBST_fail2(ListNode* head){
           if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
            
        ListNode hdr(-1);
        ListNode *f,*s;
        hdr.next=head;
        f=s=&hdr;
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        
        ListNode* mid;
        ListNode* left;
        ListNode* right;
        if(f){
            mid = s->next; 
            left=head;
            right=mid->next;
            s->next=NULL;
        }else{
            mid = s;
            left = head;
            right = mid->next;
            s=NULL;
        }
        
        TreeNode* cur = new TreeNode(mid->val);
        cur->left=sortedListToBST(left);
        cur->right=sortedListToBST(right);
        
        return cur;
    }
    
    //此方法不balance,終點要回傳second
    TreeNode* sortedListToBST_fail(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
            
        ListNode hdr(-1);
        ListNode *f,*s;
        hdr.next=head;
        f=s=&hdr;
        
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        TreeNode *cur = new TreeNode(s->next->val);
        
        ListNode* left = head;
        ListNode* right = s->next->next;
        s->next = NULL;
        
        cur->left = sortedListToBST(left);
        cur->right = sortedListToBST(right);
        return cur;
            
    }
};
