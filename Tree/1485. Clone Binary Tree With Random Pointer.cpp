//==類似題===

//===思路===


//=======
struct Node{
    int key;
    struct Node* left, *right, *random;
};

Node* helper(Node* tree, unordered_map<Node*,Node*>& ump_r, unordered_map<Node*,Node*>& ump_n){
    if(!tree) return tree;
    Node* clone = new Node(tree->key);
    ump_r[tree]=tree->random;
    ump_n[tree]=clone;
    if(tree->left)  clone->left = helper(tree->left,ump_r,ump_n);
    if(tree->right) clone->right = helper(tree->right,ump_r,ump_n);
    return clone;
}

Node* cloneTree(Node* tree){
  unordered_map<Node*,Node*>& ump_r; 
  unordered_map<Node*,Node*>& ump_n;

  Node* node = helper(tree,ump_r,ump_n);

  for(auto it: ump_r){
//      it.first   => old node
//      it.second  => old random
      ump_n[it.first]->random = ump_n[ump_r[it.second]]  
  }
  return node;  
}
