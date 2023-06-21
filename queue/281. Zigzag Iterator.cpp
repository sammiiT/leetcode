//===類似題===

//===思路===
依據其使用方式
(*)使用前必須呼叫 hasNext()
(*)若haxNext()為真, 代表有next; 可呼叫next()
1.將兩個vector加入到vector<vector<int>> 物件中
2.設定i,j ; i for v1, j for v2
3.如果i<=j 則取v1陣列, 反之,取 v2陣列
4. 當超出範圍時, 將i或j設定為INT_MAX, 這樣就會排除超出範圍的陣列
//=====
vector<vector<int>> v;
int i=0,j=0;

iterator(vector<int>& v1, vector<int>& v2){
  v.push_back(v1);
  v.push_back(v2);
  i=j=0;
}
int next(){
  return (i<=j)? v[0][i++]:v[1][j++];
}
bool hasNext(){
  if(i>=v1.size()) i=INT_MAX;
  if(j>=v2.size()) j=INT_MAX;
  return (i<v[0].size())||(j<v[1].size());
}

//===思路2====
(*)用queue, 並推廣到k個array
1.先將k個array的每一個row, 放到vector<queue<int>>中,並記錄
2.每次pop完之後,update新的值要在同一個函式裡面;全部放在next(); 如果分開;放在next和hasNext會出錯

//========
vector<queue<int>> vq;
int i;//選取的陣列
int n;//陣列總數
void zigzagIterator(vector<vector<int>>& vec){
    for(int x=0; x<vec.size(); x++){//
        queue<int> q;
        for(int y=0; y<vec[x].size(); y++){
                cout<<vec[x][y]<<" ";
                q.push(vec[x][y]);//將陣列的每一個值放入queue
        }
        vq.push_back(q);
    }
    i=0;
    n=vec.size();
}

int next(){//update要放在 執行當下的next, 放在hasNext會出錯
    int ret = vq[i].front();
    vq[i].pop();
    
    if(vq[i].empty() && i==(n-1)) {//(1)最後一個是empty 
        vq.erase(vq.begin()+i);//移除當下的queue
        n-=1;
        i=0;//從頭開始
    }
    else if(vq[i].empty() && i<(n-1)){//(2)非最後一個empty
        vq.erase(vq.begin()+i);//移除當下的queue
        n-=1;
    }else{
        i=i+1;//update i
        i%=n;    
    }
    return ret;
}
bool hasNext(){//先執行
    return n?true:false; //如果n個陣列都pop完 n==0   
}
int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6,7},{8,9}};
    zigzagIterator(mat);
    while(hasNext()){
        cout<<next()<<" ";
    }
    return 0;
}
//====思路3====
(*)也是用queue
//=====
ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
}
int next() {
        auto it = q.front().first, end = q.front().second;
        q.pop();
        if (it + 1 != end) q.push(make_pair(it + 1, end));
        return *it;
}
bool hasNext() {
        return !q.empty();
}
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;

//===思路4====
1. zigzag遍歷, 加入queue<int>中

O O O    => v1
O O O O  => v2 
O O      => v3

將v1,v2,v3皆push到matrix中,再縱向遍歷


class ZigzagIterator {
public:
  ZigzagIterator(vector<vector<int>>& v) {
    int m=0;
    for(vector<int> arr:v){
      m = max(m,(int)arr.size());
      mat.push_back(arr);
    }
    for(int j=0;j<m;++j){//縱向遍歷
        for(int i = 0; i<mat.size(); ++i){
          if(j<mat[i].size()){ q.push(mat[i][j]); }
      }
    }
  }

  int next() {
    int ret = q.front();
    q.pop();
    return ret;
  }

  bool hasNext() {
        return !q.empty();
  }
private:
    vector<vector<int>> mat;
    queue<int> q;
    
};




