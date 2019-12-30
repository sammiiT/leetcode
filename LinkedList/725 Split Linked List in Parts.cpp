class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int n = 0;
        ListNode *tmp = root;
        while(tmp!=NULL){
            n+=1;
            tmp=tmp->next;
        }
        
        
        int group = n/k;
        int remain = n%k;
        
        vector<ListNode*> res;
        if(n==0) {
            for(int i=0; i<k; ++i){
                res.push_back(NULL);
            }
            return res;
        }
        
       // ListNode hdr(-1);
        ListNode *pre,*cur,*s;
        //pre=&hdr;
        pre = s = cur = root;
        //pre->next = root;
        
        // for(int i=0; i<group; ++i){
        //     for(int j=0; i<k+(remain>0); ++j){
        for(int i=0; i<k; ++i){
            for(int j=0; j<group+(remain>0) && cur!=NULL; ++j){
                s = cur;//下一個node的前一個節點
                cur = cur->next;//下一個節點
            }
            res.push_back(pre);
            s->next = NULL;//截斷
            pre = cur;//重新設定新partition的頭
            remain--;//remain減一
        }
        
        // if(group<1){
        //     for(int i=0;i<k;++i){
        //         if(remain){
        //             s=cur;
        //             cur= cur->next;
        //             res.push_back(pre->next);
        //             pre = s;
        //             pre->next = NULL;
        //             remain--;
        //         }else{
        //             res.push_back(NULL);
        //         }
        //     }
        // }
        return res;
    }
};


// for(int i=0;i<k;++i){
//                 if(remain){
//                     cur= cur->next;
//                     res.push_back(cur);
//                     pre = cur;
//                     cur=cur->next;
//                     pre->next = NULL;
//                     remain--;
//                 }else{
//                     res.push_back(NULL);
//                 }
//             }