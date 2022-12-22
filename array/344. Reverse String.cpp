//===類似題====
345. Reverse Vowels of a String
345. Reverse Vowels of a String
541. Reverse String II

//===思路===

       ___ > t ------------------- 
     /                           |
    /  /---------------------\   |
    | V                       |  V
  +-----+-----+-----+-----+--------+ 
  |  l  |     |     |     |  r     |
  +-----+-----+-----+-----+--------+

//====

  void helper0(vector<char>& s){
    int l=0,r=s.size()-1;
    while(l<r){
        char t = s[l];
        s[l]=s[r];
        s[r]=t;
        ++l;
        --r;
    }
}

void reverseString(vector<char>& s) {
    helper0(s);
}
