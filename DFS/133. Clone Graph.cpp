//===類似題===
1490. Clone N-ary Tree
1485. Clone Binary Tree With Random Pointer
1490. Clone N-ary Tree

//===思路====
(*)DFS

Node* helper(Node* node,unordered_map<Node*,Node*>& mp){
    if(!node) return NULL;
    if(m.count(node)) return m[node];
    Node* clone = new Node(node->val);
    mp[node]==clone;
    for(Node* n:node->neighbors){
        clone->neighbors.push_back(helper(n,mp));
    }
    return  clone;
}

Node* cloneGraph(Node* node) {
  unordered_map<Node*,Node*> mp;//curNode, newNode
  return helper(node,mp);
}

//==== 輔助函式helper 改寫 ===

Node* helper(Node* node, unordered_map<Node*,Node*>& ump){
    if(!node) return NULL;
    if(ump.count(node)){
        return ump[node];
    }
    Node* clone = new Node(node->val);
    ump[node]=clone;
    for(int i=0; i<node->neighbor.size(); ++i){
        clone->neighbors.push_back(helper(node->neighbor[i],ump));
    }
    return clone;
}
