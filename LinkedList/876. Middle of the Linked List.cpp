//===類似題
877. Stone Game
1498. Number of Subsequences That Satisfy the Given Sum Condition
986. Interval List Intersections
2300. Successful Pairs of Spells and Potions

//===思路===
(*)while(cur&&cur->next)代表: 
1. 至少有一個節點
2. cur可以走兩步

(*)cur一次走兩步, pre一次走一步

(*)根據提議搜尋second middle
first middle:
*->o->o->o->o->x
hdr.next = head;
pre = cur =hdr;

second middle:
*->o->o->o->o->x
pre = cur= head;

//====
ListNode* helper0(ListNode* head){
  LIstNode* pre,*cur;
  pre=cur=head;
  while(cur&&cur->next){
    pre=pre->next;
    cur=cur->next->next;
  }
  return pre;
}


ListNode* middleNode(ListNode* head) {
     return helper0(head);   
}
