//====類似題====

//===思路====
(*) inorder概念:
以a為起始點,           以a為開始點,                 以c為起始點                 以c為起始點  
遍歷順序是a,b,c        遍歷順序是a,b,c,d,e          遍歷順序是c,d,e             遍歷順序是c,d,e,f 
    b                   b                            b                           f                   
   / \                 / \                          / \                         / 
  a   c               a   c                        a   c                       b
                           \                            \                     / \ 
                            d                            d                   a   c
                             \                            \                       \
                              e                            e                       d
                                                                                    \
                                                                                     e

struct Node {
  int val;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};

(*) 不管如何, successor節點一定都是right節點:

如果有right節點, 則從right節點的left節點一直找下去
if(node->right) {
  res = node->right; 
  while(res && res->left) res = res->left;
}

如果沒有right節點;判斷是left節點或是right節點, 從parent往上找
res = node->parent;//parent node
(res && res->val < node->val) res = res->parent;

   2         1節點(是left節點): parent節點是2; (2 > 1), 不滿足 (res->val < node->val); 不繼續往parent找                                      
  / \        3節點(是right節點): parent節點是2; (2<3), 滿足(res->val < node->val), 繼續往parent找 
1    3

Node* inorderSuccessor(Node* node){
  if(!node) return NULL;
  if(node->right){
      Node* res = node->left;
      while(res && res->left) res = res->left;
  }else{//!node->right
      Node* res = node->parent;
      while(res &&  res->val < node->val) res = res->parent;
  }
  return res;
}   

(*)follow-up:如果不提供節點數值進行比較
struct Node{
  struct Node* left;
  struct Node* right;
  struct Node* parent;
private:
  int val;
}

Node* inorderSuccessor(Node* node){
  if(!node) return NULL;
  
  if(node->right){
    Node* res = node->right;
    while(res && res->left) res = res->left;
    return res;
  } 
  //沒有right節點
  Node* res = node->parent;
  if(res && res->left==node) return res;//是parent的left節點
      
  while(res){//parent存在; 是parent的right節點
      if(res->parent && (res->parent->left == res)) return res->parent;
      res = res->parent;//往上層找,因為是parent的right節點
  }  
  return res;
}
//============================
上面的優化:
Node* res = node->parent;
while(res){
  if(res->left==node) return res;
  node = res;
  res = res->parent;
}
return res;

//============================
上面描述再優化
while(node){
  if(!node->parent) return NULL;
  if(node->parent->left==node) return node->parent;
  node = node->parent;
}
//====改進===
Node* inorderSuccessor(Node* node){
  if(!node) return NULL;
  if(node->right){
    Node* res = node->right;
    while(res && res->left) res = res->left;
    return res;
  } 

  //!node->right 沒有右節點
  while(node){
    if(node->parent && node->parent->left==node) return node->parent;
    node = node->parent;
  }
  return node;
}





