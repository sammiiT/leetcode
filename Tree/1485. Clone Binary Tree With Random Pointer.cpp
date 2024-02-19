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


//===思路2(check)===

(1)從old_node找到對應的old_node_random
(2)old_node_random再從map中找到對應的new_node

//map<Node*,Node*>//old_node,new_node
Node* helper(Node* node, 
            map<Node*,Node*>& mp){
    
    if(!node) return NULL;
    
    Node* n = new Node(node->key);
    mp[node] = n;
    
    if(node->left) n->left  = helper(node->left,mp);
    if(node->right) n->right = helper(node->right,mp);

    return n;                
}

Node* cloneTree(Node* tree){
    Node* node = NULL;
    map<Node*,Node*> mp;
    
    node = helper(tree,mp);
    
    for(audo it:mp){
/*        //it.first  = old_node
        //it.second = new_node
        
        //old_node_random
        it.first->random 
    
        //old_node_random to new_node
        mp[it.first->random]
        
        //old_node to new_node
        mp[it.first]*/
        
        Node* new_node = mp[it.first];
        Node* new_node_random = mp[it.first->random];
        new_node->random = new_node_random;
    }
    return node;    
}


