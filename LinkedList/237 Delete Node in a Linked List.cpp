class Solution {
public:
    void deleteNode(ListNode* node) {
        //將node節點的數值更換為下一個節點的數值, delete下一個節點
        
        ListNode *tmp=node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
 
    void deleteNode_OK(ListNode* node) {
        if(node&&node->next){//two node
            ListNode *tmp = node->next;
            node->val = node->next->val;
            node->next = node->next->next;
            delete tmp;
        }else{//only one node
            delete node;
            node = NULL;
        }
    }
     
};
