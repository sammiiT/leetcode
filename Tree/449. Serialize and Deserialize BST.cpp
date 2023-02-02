//===類似題===
450. Delete Node in a BST
428. Serialize and Deserialize N-ary Tree
//===思路===
(*)
用ostringstream代表serialize的string; 記錄所以的節點, 連NULL節點紀錄,當遇到NULL節點, 用"#"來代表.
用istringstream來拆解string, string的拆解,是藉由" "(空格)來區分.

(*)在serialize過程, 需要在每一個節點後面加上" "(空格), 因為在deserialze時,用空格做區分每一個字元

//=====

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize_helper(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize_helper(in);
    }

private:
void serialize_helper(TreeNode* root, ostringstream& out){
    if(!root) {
        out<<"# ";
        return;
    }
    out<<root->val<<" ";
    serialize_helper(root->left,out);
    serialize_helper(root->right,out);
}
TreeNode* deserialize_helper(istringstream& in){
//    istringstream in(data);
    string val;
    in>>val;
    if(val=="#"){
        return NULL;
    }else{
        TreeNode* node = new TreeNode(stoi(val));
        TreeNode* l = deserialize_helper(in);
        TreeNode* r = deserialize_helper(in);
        node->left = l;
        node->right = r;
        return node;
    }
}

};
