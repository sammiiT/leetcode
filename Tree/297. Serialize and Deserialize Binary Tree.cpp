//===類似題====
298. Binary Tree Longest Consecutive Sequence
271. Encode and Decode Strings
449. Serialize and Deserialize BST
428. Serialize and Deserialize N-ary Tree
//===思路===
(*)用istringstream和ostringstream
1.建立字串時,用space將每一個"數字字串"隔開
- 因為在istringstream取字串時, 會以space為依據,自動以空格隔開的內容提取出來
2.
ostringstream 是以 << 做運算, 有push_back的概念
istringstream 是以 >> 做運算, 有pop_front的概念
//=====
class Codec {
public:

    // Encodes a tree to a single string.
/*    string serialize(TreeNode* root) {
        ostringstream out;
        serial_helper(root,out);
        return out.str();
    }*/

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserial_helper(in);
    }

void serial_helper(TreeNode* root, string& s){
    if(!root) {
        s+="# ";
        return;
    }
    s+=(to_string(root->val)+' ');
    serial_helper(root->left, s);
    serial_helper(root->right,s);
}
string serialize(TreeNode* root){
    string s;
    serial_helper(root,s);
    return s;
}

private:
    void serial_helper(TreeNode* root, ostringstream& out){
        if(root){
            out<<root->val<<' ';
            serial_helper(root->left, out);
            serial_helper(root->right,out);
        }else{
            out<<"# ";
        }    
    }
    TreeNode* deserial_helper(istringstream& in){
        string val;
        in >> val;
        if(val=="#") return NULL;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserial_helper(in);
        node->right = deserial_helper(in);
        return node;
    }
};
