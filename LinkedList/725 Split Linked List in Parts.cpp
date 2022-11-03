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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret;
        int n = 0;
    
        for(ListNode* t = head; t; t=t->next) n++;
    
        if(n/k){//每一個partition有(n/k) node
            if(n%k){//沒有整除
                ListNode *start,*move,*nstart;
                start = move = nstart = head;
                int remain = 1;//整除下來剩下的node, 要平均分配在不同的list
                int j = 1;//平均分配, 每一次分一個

                while(start){
                    for(int i=0; i<(n/k)-1+j; i++){
                        move = move->next;
                    }
                    nstart = move->next;
                    move->next = NULL;
                    ret.push_back(start);
                    start = nstart;
                    move = nstart;
                    remain++;
                    if(remain>(n%k)){
                        j = 0;
                    }
                }
            }else{//整除
                ListNode *start,*move,*nstart;
                start = move = nstart = head;

                while(start){
                    for(int i=0; i<(n/k)-1; i++){
                        move = move->next;
                    }
                    nstart = move->next;
                    move->next = NULL;
                    ret.push_back(start);
                    start = nstart;
                    move = nstart;
                }
            }

        } else {
            ListNode *t;
            ListNode *cur = head;
            for(int i =0; i<k; i++){
                if(cur){
                    t = cur->next;
                    cur->next = NULL;
                    ret.push_back(cur);
                    cur = t;
                }else{//cur = NULL;
                    ret.push_back(NULL);
                }
            }
        }

        return ret;        
    }

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
