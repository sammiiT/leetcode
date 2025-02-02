//=== more challeng ===
684. Redundant Connection
734. Sentence Similarity
737. Sentence Similarity II

//=== 思路 ====
(*) union find
-定義共同的root
-每一個節點的最後root, 都會在同一個
-若不同的root, 卻有相同子集, 則此兩個group是同一個group, 要將此兩個root做對應

  

string getRoot(string str, unordered_map<string,string>& ump){
    if(!ump.count(str)) ump[str]=str;
    return (ump[str]==str)?str:getRoot(ump[str],ump);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ret;
    unordered_map<string,string> rmp;//child-node, root-node
    unordered_map<string,set<string>> smp;
    unordered_map<string,bool> chkmp;//root-node exist
    
    for(vector<string> vstr:accounts){
        string root = getRoot(vstr[1],rmp);
        for(int i=2;i<vstr.size();++i){
            string r = getRoot(vstr[i],rmp);
            if(root!=r){
                    rmp[r]=root;
            }
        }
    }
    
    for(auto it:rmp){
        smp[getRoot(it.second,rmp)].insert(it.first);
    }
    
    for(vector<string> vstr:accounts){
        vector<string> res;
        string root = getRoot(vstr[1],rmp);
        if(chkmp.count(root)) continue;
        chkmp[root]=true;
        res.push_back(vstr[0]);
        
        for(string str:smp[root]){
            res.push_back(str);        
        }
        ret.push_back(res);
    }
    return ret;
}
