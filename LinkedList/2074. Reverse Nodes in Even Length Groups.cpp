//===類似題===
432. All O`one Data Structure
2807. Insert Greatest Common Divisors in Linked List
426. Convert Binary Search Tree to Sorted Doubly Linked List

//===思路===
(*) 參考reverse in k group
變數 total: 節點總數
變數 remain: 剩下的節點數
變數 reverse: 當下group的節點個數, 如果reverse == 2n, 則做reverse; 如果reverse == 2n+1, 則不做reverse

(*)最後一個group: 
-reverse > remain 數目 => 不會在loop中計算 ; 如果remain==2n, 則要做reverse
-也有可能 reverse==remain => 會在loop中計算
//====
ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* pre;
        ListNode* cur;
        ListNode hdr(-1);
        int total = 0;
        int remain = 0;
        int reverse = 0;

        cur = head;
        while(cur){//計算list node數目
            total+=1;
            cur=cur->next;
        }

        hdr.next = head;
        pre = &hdr;
        cur = head;
        remain = total;
        reverse = 1;

        while(reverse<=remain){
            if(reverse%2==0){//reverse count = 2n (even) =>偶數個, 做reverse
                for(int i=0; i<(reverse-1); ++i){
                    ListNode* tmp = cur->next;
                    cur->next = tmp->next;
                    tmp->next = pre->next;
                    pre->next = tmp;        
                }
                pre = cur;
                cur = pre->next;
            }else{//reverse count = odd => 奇數個, 不做reverse
                for(int i=0;i<reverse;++i){
                    pre = pre->next;
                    cur = cur->next;
                }
            }
            remain-=reverse;
            reverse+=1;
        }
        //最後一個group, 如果是偶數個, 做reverse
        if(remain>0 && remain%2==0){//last group even exist and number of node count is even.
            for(int i=0; i<(remain-1); ++i){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;        
            }
        }

        return hdr.next;
    }
