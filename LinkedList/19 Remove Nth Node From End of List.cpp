//===類似題===
20. Valid Parentheses
1474. Delete N Nodes After M Nodes of a Linked List
//===思路===
(*)用兩個stack,這兩個stack將list分成兩部分; "被刪除節點的左半段","被刪除節點的右半段"
(*)將刪除的節點從兩個stack中刪除, 連結兩個stack的top, 即為解
-左半段在push至stack前,要多加一個hdr節點, 因為會遇到將原head節點刪除的情況
-右半段在push至stack前, 要多加一個NULLr節點m 因為會遇到刪除最後一個節點的情況
//===
ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> stkf,stkb;
    ListNode hdr(-1);
    ListNode* cur;
    cur = &hdr;
    hdr.next = head;

    while(cur){
        stkf.push(cur);
        cur=cur->next;
    }

    int i=0;
    stkb.push(NULL);
    while(i<n){
        ListNode* t = stkf.top();
        stkf.pop();
        stkb.push(t);
        i++;
    }
    stkb.pop();//remove node
    ListNode* f = stkf.top();
    ListNode* b = stkb.top();
    f->next = b;//connect 
    return hdr.next;
}
//===思路2===
(*)用兩個index,此兩個index距離n個節點
(*)用第三個index紀錄被刪除節點的前一個節點
(*)假設 n = 3

            前一個  被刪除節點    其中一個節點(距離被刪除節點有3) 
              |       /                  |
hdr -> o  ->  o  ->  o  ->  o ->   o ->  x	
	
(*)遍歷一次,只需將pre根被刪除節點的下一個節點做連結, 即可	
//=====
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL||head->next==NULL) return NULL;
    ListNode hdr(-1);
    ListNode *f,*s;
    f=s=&hdr;
    hdr.next=head;

    for(int i=0; i<n; ++i){
        f = f->next;
    }
    if(f->next==NULL) return head->next;

    //是要確認f->next存不存在    
    while(f&&f->next){//引申:f存在的話,再確認f->next是否存在; 不然f->next會發生segmentfault
        f=f->next;    
        s=s->next;//要被remove的前一個
    }
    ListNode *tmp = s->next;
    s->next = tmp->next;
    delete tmp;
    return hdr.next;
        
    }
    
    
    ListNode* removeNthFromEnd_3(ListNode* head, int n) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode hdr(-1);
        ListNode *cur,*prev;
        hdr.next=head;
        cur=prev=&hdr;
        for(int i=0;i<n;++i){
            cur = cur->next;
        }
        if(cur&&cur->next==NULL) return head->next;
        while(cur->next!=NULL){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;
        
    }
    
    ListNode *removeNthFromEnd_2(ListNode *head,int n){
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *cur,*prev;
        
        cur=prev=head;
        
        for(int i=0; i<n; ++i){
            cur=cur->next;
        }
        if(cur==NULL) return head->next;//最後一個節點被remove
        
        while(cur->next!=NULL){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
    
     ListNode* removeNthFromEnd_3(ListNode* head, int n) {
        ListNode *f,*s;
	    ListNode *p;//s前一個node;
        ListNode *hdr;//第一個node
        
	    hdr=p=s=f=head;	
	    for(int i=0; i<n; i++){
	        if(!f) return NULL;
	        f=f->next;
	    }	
	    if(f==NULL) return p->next;//移除第一個節點,回傳第二個節點
//	    while(f&&f->next){//f->next存在(不是NULL);就執行以下描述=>用此描述會錯誤, 最後一個節點不會變成NULL   
        while(f!=NULL){
            p=s;
            s=s->next; 
            f=f->next;
    	}
	    p->next = s->next;//移除s節點	
	    return hdr;        
/*
樹3格2
n=4
x
o
1 2 3 4 5 6 5 4 3 2 0 2 4 1  null
o       x                  
                  o       x 
                    o         x
*/

         
     }
};
