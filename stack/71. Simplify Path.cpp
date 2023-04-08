//===類似題===
72. Edit Distance
72. Edit Distance
1762. Buildings With an Ocean View
1629. Slowest Key
//===思路===
(*)宣告vector<string>, 內容放directory字串
(*)如果遇到".",就不放入vector<string>
   如果遇到"..", 代表要回到上一個路徑, 所以要將vector<string>的back()移除

(*)遍歷陣列, 如果遇到'/', 則++i
   在遍歷陣列, 如果不是'/', 將字串的index update
   最後用開始和結束index, 取 substring

(*)substring如果是"..",代表要回到上一個路徑, 所以要將vector<string>的back()移除
   substring如果是".",就不放入vector<string>
 
(*)最後將vector<string>的元素做串接, 即為解  
//====
string helper(string path) {
    int i = 0, start=0, end=0;
    vector<string> res;
    string ret;
    while(i<path.size()){
        while(i<path.size() && path[i]=='/') ++i;
        if(i==path.size()) break;
        start = i;
        while(i<path.size() && path[i]!='/') ++i;
        end = i-1;

        string s = path.substr(start,end-start+1);
        if(s==".."){
            if(!res.empty()) res.pop_back(); 
        }else if(s!="."){
            res.push_back(s);
        }
    }
    if(res.empty()) return "/";
    for(int i=0;i<res.size();++i){
        ret+='/'+res[i];
    }
    return ret;
}
