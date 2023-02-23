//===類似題===
3. Longest Substring Without Repeating Characters
989. Add to Array-Form of Integer
1634. Add Two Polynomials Represented as Linked Lists
//===思路===
(*)while迴圈
(*)每次l1和l2運算過後都要移動一步(next)
-如果l1, l2最後等於NULL, 則每一次運算取出的val=0
(*)每次運算都要計算進位數值 sum = (l1->val+l2->val+carry);
 carry = sum/10;
//===
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode hdr(-1);
    ListNode* cur;

    cur = &hdr;
    int carry = 0;
    while(l1||l2){
        int val1=l1?l1->val:0;
        int val2=l2?l2->val:0;
        int sum = val1+val2+carry;
        carry = sum/10;
        cur->next = new ListNode(sum%10);
        cur = cur->next;
        l1=l1?l1->next:NULL;
        l2=l2?l2->next:NULL;
    }
    if(carry) cur->next = new ListNode(1);
    return hdr.next;
 }
