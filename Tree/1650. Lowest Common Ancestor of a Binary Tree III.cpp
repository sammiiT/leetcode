//====

class Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
}

(*)用set做題
Node* lowestCommonAncestor(Node* p, Node * q) {
    set<TreeNode*> stp;
    Node* n = p;
    Node* ret = NULL;
    if(p==q) return p;
    
    while(n){
        set.insert(n);
        n=n->parent;
    }

    n = q;
    while(n){
        if(set.count(n)){
            ret = n;
            break;
        }
        n=n->parent;
    }
    return ret;        
}

(*)用linked-list intersection概念做題
Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* a=p;
    Node* b=q;
    
    if(a==b) return a;
    
    while(a!=b){
        a=a?a->parent:q;
        b=b?b->parant:p;
    }
    return a;
    
}
