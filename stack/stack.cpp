(*)運算概念:
index = top
top一開始等於0, 則先賦值(更新),再位移
top一開始等於-1, 則先位移, 再賦值(更新)

(*)
void push(int)
void pop()
int top()
bool isEmpty()
int getSize()
//==================  
struct stack{
    int top;//top index
    int size;//stack capacity
    int* arr;//建立的array 來模擬 stack
};

/***************************************************
先位移,再賦值, 比較好算=>因為每次top都在最新數值的位置上
****************************************************/
void stack_init(struct stack* stk, int size){
    stk->top = -1;//先位移,再賦值
    stk->arr = new int[size];
    stk->size = size;
}
void stack_remove(struct stack *stk){
    delete stk->arr;    
}
void push(struct stack* stk, int val){
    if(stk->top==(stk->size-1)) return;//stack full
    stk->arr[++(stk->top)] = val;
}
bool isEmpty(struct stack* stk){
    return (stk->top==-1);
}
void pop(struct stack* stk){
    if(isEmpty(stk)) return;
    --(stk->top);
}
int top(struct stack* stk){
    if(isEmpty(stk)) return -1;
    return stk->arr[stk->top];
}
int getSize(struct stack* stk){
    return stk->top-(-1);
}
(*)上述做法缺陷,不能push進negative數值,因為 top()函式會有機會回傳(-1)
除非每次在執行top()之前, 先執行一次isEmpty(),判斷是否為空,再做top的動作 
    
(*)在一對stack的遍歷, 之前都會執行stk.empty(),判斷是否可以從stack中取值; 如果沒有先做判斷,就直接執行top動作,會出錯
while(!stk.empty()){
    int t = stk.top();
    stk.pop();
}
//如果stk已經是empty()狀態, 
int t = stk.top(); //執行會出錯
    
/****************************************************
 先賦值,再位移 => 不好算,因為top的位址都沒有新的數值 
****************************************************/
void stack_init(struct stack* stk, int size){
    stk->top = 0;//賦值,再位移
    stk->arr = new int[size];
    stk->size = size;
}
void stack_remove(struct stack *stk){
    delete stk->arr;    
}
void push(struct stack* stk, int val){
    if(stk->top==(stk->size)) return;//stack full
    stk->arr[(stk->top)++] = val;
}
bool isEmpty(struct stack* stk){
    return (stk->top==0);
}
void pop(struct stack* stk){
    if(isEmpty(stk)) return;
    --(stk->top);
}
int top(struct stack* stk){
    if(isEmpty(stk)) return -1;
    return stk->arr[stk->top-1];//top位置沒有最新的數值, 要找前一個位置的數值
}
/*
int top(struct stack* stk, int* val){
    if(isEmpty(stk)) return 0;
    *val=stk->arr[stk->top-1];
    return 1;
}
*/

int getSize(struct stack* stk){
    return stk->top-(0);
}
//==== 測試 ======
int main()
{
    struct stack stk;
    stack_init(&stk, 5);
    push(&stk,1);
    push(&stk,2);
    push(&stk,3);
    push(&stk,4);
    push(&stk,5);
    push(&stk,6);//stack full, won't be pushed in.
    while(!isEmpty(&stk)){
        int val = top(&stk);
        cout<<val<<" ";
        pop(&stk);
    }
    stack_remove(&stk);    
    return 0;
}

/*********************************
*   利用linked-list實作 stack
**********************************/
struct stack {
    ListNode* head;
    ListNode* top;
};
void init(struct stack* stk){
    stk->head=NULL;
    stk->top=NULL;
}
void push(struct stack* stk, int val){
    if(stk->head==NULL && stk->top==NULL) {
        ListNode* tmp = new ListNode(val);
        stk->head = tmp;
        stk->top = tmp;
    }else{
        ListNode* tmp = new ListNode(val);
        stk->top->next = tmp;
        tmp->prev = stk->top;
        stk->top = stk->top->next;
    }
}
int top(struct stack* stk, int* ret){
    if(stk->head==NULL && stk->top==NULL) return 0;
    *ret = stk->top->val;
    return 1;
}
void pop(struct stack* stk){
    if(stk->head==NULL && stk->top==NULL) return;
    
    if(stk->head==stk->top){//only one
        delete stk->head;
        stk->head=NULL;
        stk->top=NULL;
    } else {
        ListNode* tmp = stk->top->prev;
        tmp->next = NULL;
        delete stk->top;
        stk->top = tmp;
    }
}
bool isEmpty(struct stack* stk){
    return (stk->head==NULL && stk->top==NULL);
}
//===以stack來實作queue===
struct queue{
    stack stk;    
};

void q_init(struct queue* q){
    init(&q->stk);
}

void q_push(struct queue* q, int val){
    push(&q->stk,val);    
}

int q_front(struct queue* q, int* ret){
    struct stack stmp;
    int res;
    
    if(isEmpty(&q->stk)) return 0;//stack is empty
    
    init(&stmp);
    
    while(!isEmpty(&q->stk)){
        if(top(&q->stk,&res)){
            pop(&q->stk);
            push(&stmp,res);        
        }
    } 
    *ret = res;
   // cout<<"res="<<res<<endl;
    
    while(!isEmpty(&stmp)){
        int val;
        if(top(&stmp,&val)){
            pop(&stmp);
            push(&q->stk,val);
        }
    }
    return 1;
}

int q_back(struct queue* q, int* ret){
    if(isEmpty(&q->stk)) return 0;
    if(top(&q->stk,ret)) return 1;
    return 0;
}

void q_pop(struct queue* q){
    struct stack stmp;
    int res;
    if(isEmpty(&q->stk)) return;//stack is empty
    
    init(&stmp);
    while(!isEmpty(&q->stk)){
        if(top(&q->stk,&res)){
            pop(&q->stk);
            push(&stmp,res);        
        }
    }
    pop(&stmp);
    
    while(!isEmpty(&stmp)){
        int val;
        if(top(&stmp,&val)){
            pop(&stmp);
            push(&q->stk,val);
        }
    }
}

bool q_isEmpty(struct queue* q){
    return isEmpty(&q->stk);
}



/****************************************************
以stack來實作queue; 參考leetcode實作
****************************************************/
struct queue{
    stack stk;    
};

void q_init(struct queue* q){
    init(&q->stk);
}

void q_push(struct queue* q, int val){
    push(&q->stk,val);    
}

int q_front(struct queue* q, int* ret){
    struct stack stmp;
    int res;
    
    if(isEmpty(&q->stk)) return 0;//stack is empty
    
    init(&stmp);
    
    while(!isEmpty(&q->stk)){
        if(top(&q->stk,&res)){
            pop(&q->stk);
            push(&stmp,res);        
        }
    } 
    *ret = res;
   // cout<<"res="<<res<<endl;
    
    while(!isEmpty(&stmp)){
        int val;
        if(top(&stmp,&val)){
            pop(&stmp);
            push(&q->stk,val);
        }
    }
    return 1;
}

int q_back(struct queue* q, int* ret){
    if(isEmpty(&q->stk)) return 0;
    if(top(&q->stk,ret)) return 1;
    return 0;
}

void q_pop(struct queue* q){
    struct stack stmp;
    int res;
    if(isEmpty(&q->stk)) return;//stack is empty
    
    init(&stmp);
    while(!isEmpty(&q->stk)){
        if(top(&q->stk,&res)){
            pop(&q->stk);
            push(&stmp,res);        
        }
    }
    pop(&stmp);
    
    while(!isEmpty(&stmp)){
        int val;
        if(top(&stmp,&val)){
            pop(&stmp);
            push(&q->stk,val);
        }
    }
}

bool q_isEmpty(struct queue* q){
    return isEmpty(&q->stk);
}


//===================
(*)stack操作
void stack_init(struct stack* stk, int size);
void stack_remove(struct stack *stk);
void push(struct stack* stk, int val);
bool isEmpty(struct stack* stk);
void pop(struct stack* stk);
int top(struct stack* stk);
int getSize(struct stack* stk);

(*)queue操作

void queue_init(struct stack* stk, int size){
    stack_init(stk,size);
}
int push(struct stack* stk, int val){
    struct stack tmp;   
    stack_init(&tmp,)
}
int pop();
int getFront();
int getBack();
int getSize();
bool isEmpty();
bool isFull();





