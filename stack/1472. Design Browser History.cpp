//===類似題====
1473. Paint House III
2254. Design Video Sharing Platform

//===思路====
(*)用stack來做
(*)用vector<T> 來模擬stack, 因為vector有clear功能, 能滿足題目visit定義

//====
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        cur_page = homepage;
    }
    void visit(string url) {
        bstk.push_back(cur_page);
        fstk.clear();
        cur_page = url;
    }
    string back(int steps) {
        int mov;
        if(steps<=bstk.size()){ mov = steps;}
        else{ mov = bstk.size();}//steps > bstk.size()
        if(mov){
            fstk.push_back(cur_page);
            for(int i=0;i<mov-1;i++){
                  fstk.push_back(bstk.back());
                  bstk.pop_back();
            }
            cur_page = bstk.back();
            bstk.pop_back();
        }
        return cur_page;
    }
    string forward(int steps) {
        int mov;
        if(steps<=fstk.size()){mov = steps; }
        else{mov = fstk.size();}//steps>fstk.size() 
        if(mov){
            bstk.push_back(cur_page);
            for(int i=0;i<mov-1;i++){
                bstk.push_back(fstk.back());
                fstk.pop_back();
            }
            cur_page = fstk.back();
            fstk.pop_back();
        }
        return cur_page;
    }
    
private:
    vector<string> fstk;
    vector<string> bstk;
    string cur_page;    
};
