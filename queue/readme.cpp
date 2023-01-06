//====Queue=====
/*
1.f==r =>queue =0
2.f先移動,再賦值 or 先賦值,再移動
  r先移動,再賦值 or 先賦值,再移動

先移動,再賦值; 用在一開始index的初始值不在陣列上, f=-1(初始值)
先賦值,再移動: 一開始index初始位置在陣列上,在index = 0上  
  
3.基本操作:
int push(int val);
int pop();
int getFront();
int getBack();
int getSize();
bool isEmpty();
bool isFull();
*/
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
    ++f;
}
bool isFull(struct queue* qu){
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
    return r-f;//f是已經pop的位置
}
void queue_init(struct queue* qu, int capacity){
    f = -1;
    r = -1;
    qu->capacity = capacity;
    qu->q = new int[capacity];
}
//====Queue 改良上述做法


//=== circular queue (Ring buffer)=====

