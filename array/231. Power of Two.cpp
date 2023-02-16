//===類似題===
232. Implement Queue using Stacks
326. Power of Three
342. Power of Four
//===思路===

//====
bool isPowerOfTwo(int n) {
  while(n>1){
    if(n%2==0) n/=2;//如果整除
    else break;//沒有整除
  }
}
