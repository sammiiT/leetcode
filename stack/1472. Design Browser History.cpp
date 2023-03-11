//===類似題====
1473. Paint House III
2254. Design Video Sharing Platform

//===思路====
(*)用stack來做
(*)用vector<T> 來模擬stack, 因為vector有clear功能, 能滿足題目visit定義

//=====
string cur;
vector<string> b;
vector<string> f;

BrowserHistory(string homepage) {
        cur = homepage;
    }
    void visit(string url) {
        b.push_back(cur);
        f.clear();//while(!f.empty()) f.pop();
        cur = url;
    }
    
string back(int steps) {
    if(b.size()){//要先判斷b stack是否有元素,如果沒有此判斷會錯誤
        f.push_back(cur);
        if(b.size()<=steps) {
            while(b.size()>1){
                //string t = b.back();
                //f.push_back(t);
                f.push_back(b.back());
                b.pop_back();
            }
        }else{
            while(--steps){
                //string t = b.back();
                //f.push_back(t);
                f.push_back(b.back());
                b.pop_back();
            }
        }
        cur = b.back();b.pop_back();
    }    
    return cur;   
}
    
string forward(int steps) {
    if(f.size()){//要先判斷f stack是否有元素,如果沒有此判斷會錯誤
        b.push_back(cur);
        if(f.size()<=steps){
            while(f.size()>1){
                //string t = f.back();
                //b.push_back(t);
                b.push_back(f.back());
                f.pop_back();
            }
        }else{
            while(--steps){
                //string t = f.back();
                //b.push_back(t);
                b.push_back(f.back());
                f.pop_back();
            }
        }
        cur = f.back();f.pop_back();
    }
        return cur;   
}
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


//===思路2====
class BrowserHistory {
public:
  BrowserHistory(string homepage) : 
    index_(0) {
    urls_.push_back(std::move(homepage));    
  }
 
  void visit(string url) {
    while (urls_.size() > index_ + 1)
      urls_.pop_back();
    ++index_;
    urls_.push_back(std::move(url));
  }
 
  string back(int steps) {    
    index_ = max(index_ - steps, 0);
    return urls_[index_];
  }
 
  string forward(int steps) {
    index_ = min(index_ + steps, static_cast<int>(urls_.size()) - 1);  
    return urls_[index_];
  }
private:
  int index_;
  vector<string> urls_;
};
