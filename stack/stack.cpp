(*)
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
