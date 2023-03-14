//===類似題===
951. Flip Equivalent Binary Trees
1697. Checking Existence of Edge Length Limited Paths
844. Backspace String Compare
1962. Remove Stones to Minimize the Total
//===思路===
 0 1 2 3  4  5  6
[2,3,5,7,11,13,17]

1,2,3, 4,5, 6
res[0] = deck[0] => 2 o o o o o o
2,3, 4,5, 6,1

3, 4,5, 6,1  
res[2]= deck[1] => 2 o 3 o o o o
4,5, 6,1,3

5, 6,1,3  
res[4]= deck[2] => 2 o 3 o 5 o o
6,1,3,5

1,3,5  
res[6]= deck[3] => 2 o 3 o 5 o 7 
3,5,1
  
5,1
res[3]= deck[4] => 2 o 3 11 5 o 7
1,5  
  
5
res[1]= deck[5] => 2 13 3 11 5 o 7
5  
  
res[5]= deck[6] => 2 13 3 11 5 17 7

=> [2,13,3,11,5,17,7]


//====
vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        queue<int> q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++) q.push(i);

        for(int i=0;i<n;i++){
            res[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
}
