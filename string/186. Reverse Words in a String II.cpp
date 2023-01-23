//===類似題====

//===思路===
Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

vector<char> str = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};

1.先將str做一次反轉
2.再將每一個單詞作反轉, 遇到space(' ')的時候, 就將substr反轉
3.因為會有邊界值問題, 所以最後必須再對最後一個單詞作反轉
//==========
void reverse_word(vector<char>& str, int start, int end){
    reverse(str.begin()+start,str.begin()+end);
}

void reverseWords(vector<char>& str) {
    int i=0,j=0;
    reverse(str.begin(),str.end());
    
    for(i=0,j=0; i<str.size(); i++){
        if(str[i]==' '){
            reverse_word(str,j,i);
            j=i+1;
        }
    }
    reverse_word(str,j,i); 
}

//===思路2===
void reverse_word(vector<char>& str, int start, int end){
    reverse(str.begin()+start,str.begin()+end);
}

void reverseWords(vector<char>& str) {
    int i=0,j=0;
    reverse(str.begin(),str.end());
    
    for(i=0,j=0; i<=str.size(); i++){
        if(i==str.size()||str[i]==' '){//在迴圈中直接判斷,不用在回圈之外再做一次
            reverse_word(str,j,i);
            j=i+1;
        }
    } 
}
