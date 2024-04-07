//=== more challenge ===


//====
(*)Celebrity 條件
Celebrity不知道所有人, 但所有人都知道Celebrity 

bool know(int a,int b);
int findCelebrity(int n){
  vector<bool> candidate(n,true);

  for(int i=0;i<n;++i){
    for(int j=0; j<n; ++j){
        //knows(i,j) || !knows(j,i)
        if(knows(i,j)){
            candidate[i]=false;
            break;
        }else if(!knows(j,i)){
            candidate[i]=false;
            break;
        }else if(knows(j,i)){
            candidate[j]=false;
        }
    }
    if(candidate[i]) return i;
  }
  return -1;
}
