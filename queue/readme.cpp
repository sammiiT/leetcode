//====Queue=====
1.f==r =>queue =0
2.f先移動,再賦值 or 先賦值,再移動
  r先移動,再賦值 or 先賦值,再移動

(*)先移動,再賦值; 用在一開始index的初始值不在陣列上, f=-1(初始值)
(*)先賦值,再移動: 一開始index初始位置在陣列上,在index = 0上  
  
3.基本操作:
/* push(),pop(),front(),back(),size(),empty() */  
int push(int val);
int pop();
int getFront();
int getBack();
int getSize();
bool isEmpty();
bool isFull();

4.實作
struct queue{
    int f;
    int r;
    int capacity;
    int *q;//陣列
}
//===以下實作方法,會造成push和pop的次數固定, 不能重複使用
void push(struct queue* qu, int x){
    if(isFull(qu)){
      return;
    }
    qu->q[++r]=x;
}
void pop(struct queue* qu){
    if(isEmpty(qu)){
      return;
    }
    ++(qu->f);
}
bool isFull(struct queue* qu){
//index從0~capacity-1
    return ((qu->r+1)==(qu->capacity));
}
void isEmpty(struct queue* qu){
    return (f==r);
}
int getFront(struct queue* qu){
    if(isEmpty(qu)){
        return -1;
    }
    return (qu->q[f+1]);
}
int getBack(struct queue* qu){
    if(isEmpty(qu)){
        return -1;
    }
    return qu->q[r];
}
int getSize(struct queue* qu){
    return qu->r-qu->f;//f是已經pop的位置
}
void queue_init(struct queue* qu, int capacity){
    qu->f = -1;
    qu->r = -1;
    qu->capacity = capacity;
    qu->q = new int[capacity];
}
//====Queue 改良上述做法(線性Queue) ====
1. 線性queue用linklist 來表示
2. 實作
3. 以此線性quque實作stack

struct queue {
  ListNode* f, *r;
}
void queue_init(struct queue* q){
  q->f=NULL;
  q->r=NULL;
}

void push(struct queue* q,int val){
    if(q->f==NULL && q->r==NULL){
      ListNode* tmp = new ListNode(val);
      q->f = tmp;
      q->r = tmp;
      //initial (f==r)
    }else{
      ListNode* tmp = new ListNode(val);
      q->r->next = tmp;
      q->r = q->r->next;
    }
}
void pop(struct queue* q){
    //chk empty
    if(q->f==NULL && q->r==NULL) return;
   
    if(q->f==q->r){//only one element
      ListNode* tmp = q->f;
      delete tmp;
      q->f = NULL;
      q->r = NULL;
    }else{
      ListNode *tmp = q->f;
      q->f = q->f->next;
      delete tmp;
    }
}

int front(struct queue* q, int* ret){
    //chk empty: chk initial 用c++ constructor, 再宣告時就會自動執行
    if(q->f==NULL && q->r==NULL) return 0;  
    *ret = q->f->val;    
    return 1;
}

int back(struct queue* q, int* ret){
    //chk empty
    if(q->f==NULL && q->r==NULL) return 0;
    *ret = q->r->val;
    return 1;
}


//=== circular queue (Ring buffer)=====
1. f==r => buffer empty
2. (r+1)%n==f => buffer full
3.一開始 f和r在array的0位置, 以上述的概念,用"先賦值,再移動"
3.1先賦值,再移動=> r的所在位址,一開始沒有給值 
4.因為當r的下一個為f的話, 代表buffer full, 所以r不能做update; r不能update, 表示r的位置上沒有新的值(3.1)
5.由4, 可知, 用circular buffer, 滿buffer時會空一格沒有用到的空間
6.實作(依據之前的struct queue):

void queue_init(struct queue* qu, int capacity){
  qu->f=qu->r=0;
  qu->capacity = capacity;
  qu->q = new int[capacity];
}
int push(struct queue* qu, int val){
  if(isFull(qu)){ return -1;}
  qu->q[r]=val;
  r=(r+1)%(qu->capacity);
}
void pop(struct queue* qu){
  if(isEmpty(qu)){return;}
  ++(qu->f);
}
int getFront(struct queue* qu){
  if(isEmpty(qu)){return -1;}
  return qu->q[f];
}
int getBack(struct queue* qu){
  if(isEmpty(qu)){ return -1;}
  return (r-1)<0?qu->q[qu->capacity-1]:qu->q[r-1];
}
int getSize(struct queue* qu){
  int res = 0;
  if(isEmpty()){return 0;}
  if(qu->f > qu->r){
    res = qu->capacity - (qu->f - qu->r); // 大減小(f-r), 再用capacity-(f-r);
                                          //r的位址沒有插入新值, f的位址有舊值; 相減就是"空的"沒有插入的位址
  }else if(qu->f < qu->r){                 
      res =  qu->r-qu->f;//大減小 (r-f)
  }
  return res;
}
bool isEmpty(struct queue* qu){
  return (qu->f==qu->r);
}
bool isFull(struct queue* qu){
  return ((r+1)%n==f);
}

//===利用ring buffer實作stack



//===筆記===
struct ListNode{
  int val;
  struct ListNode* next;
};

struct queue {
  int size;
  //struct ListNode* node,*f,*r;
  struct ListNode** f;
  struct ListNode** r;
}

void queue_init(sturct queue* q){
    q->size = 0;
    q->f = NULL;
    q->r = NULL;
} 

void queue_push(struct queue* q, int val){
    if(q->f==NULL && q->r==NULL){
        ListNode* node = new ListNode(val);
        q->r = &node;//local 變數, 會形成dangling pointer;函式執行完會被回收,有可能會被其他程式變數覆蓋
/*
指標的指標計算, 要有一個中間的位址去承接
如:
int a = 1;
int *ptr = &a;
int **ptr_to_ptr = &ptr; //中間的位址,就是 int *ptr的位址
*/    
    }else{
        
        ListNode* node = new ListNode(val);
        ListNode
        ListNode* tmp = *(q->r);
        tmp->next = node;
        tmp = node;        
    }
}
void queue_pop(struct queue* q){
  //if(q->r==NULL) return;
  if(q->f==NULL && q->r==NULL) return;//empty
  //
}

int queue_front(struct queue* q, int* val){
  
}

int isEmpty(struct queue* q){
  
}

int isFull(struct queue* q){

  
}



