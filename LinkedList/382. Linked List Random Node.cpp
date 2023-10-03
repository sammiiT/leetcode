//===類似題===
1474. Delete N Nodes After M Nodes of a Linked List
2289. Steps to Make Array Non-decreasing
2169. Count Operations to Obtain Zero

//===思路===

class Solution {
public:
    Solution(ListNode* head) {
        ListNode* cur = head;
        total = 0;
        hdr = head;
        while(cur){
            total+=1;
            cur = cur->next;
        }
    }
    
    int getRandom() {
        int i= rand()%total;
        ListNode *tmp = hdr;

        while(i--){
            tmp = tmp->next;
        }
        return tmp->val;
    }

private:
int total;
ListNode* hdr;
};
