//===類似題===

//===思路===
(*)概念有點像 兩個string刪除k個以內可以變成palindrome........
- 現在除了刪除, 還多了insert,replase
- 操作有 delete, insert, replace; 對這三種操作分別做dfs

(*)DFS 運算會造成Time Limit Exceeded, 但思考邏輯不錯
如果相等:
word1[i]==word2[j]=>繼續比較下一個 (i+1)和(j+1)

如果不相等:下列都是一種路徑 
-word1[i]可以insert => i位置insert j位置; insert之後, 原本的位置i變成位置(i+1), j要跳下一個位置,即運算j+1

+---- index 0 insert "O"      insert  +----原本的index0 仍然是從下一個比較的index  
|                         =>    |   /      所以i的index不用update,只要更改j的index; (j+1)
x x x x                         O  x  x  x  x  
                                   

-word1[i]可以delete => i位置delete, i+1, 比較j

+-----index0 delete      +---下一個跟j比較的是index_1; j的index不用update
|                   =>   |          
x x x x                  x  x  x      
 

-word1[i]可以replace => 繼續比較下一個, (i+1)和(j+1)

(*)過程中會記錄minmap[i][j],為minimum
先insert,再delete,再replace, 過程中,insert的路徑會先將minmap結果填入, 所以遇到replace可能會有minmap[i][j]的結果
  
note:
(1-index) -(0-index)
s.size() - index4 = 剩下的個數
index4=>[0,1,2,3,4]=>在位置4前面有4個
s.size()-index4, 並沒有把index4的那一個減去; 只減去index4前面的個數, 就是4個
  
//===Time Limited Exceeded===
int helper(string& word1, int i, string& word2, int j, vector<vector<int>> minmap){
    if(i==word1.size()) return word2.size()-j;//remain word2
    if(j==word2.size()) return word1.size()-i;//remain word1
    if(minmap[i][j]>0) return minmap[i][j];

    int res = 0;
    if(word1[i]==word2[j]){
        return helper(word1,i+1,word2,j+1,minmap);
    }else{//word1[i]!=word2[j]
        int insert_cnt = helper(word1,i,word2,j+1,minmap);
        int delete_cnt = helper(word1,i+1,word2,j,minmap);
        int replace_cnt = helper(word1,i+1,word2,j+1,minmap);
        res = min(insert_cnt,min(delete_cnt,replace_cnt))+1;
    }
    return minmap[i][j] = res;
    //return res;
}    
    int minDistance(string word1, string word2) {
        vector<vector<int>> minmap(word1.size(),vector<int>(word2.size()));
        return helper(word1,0,word2,0,minmap);
    }
