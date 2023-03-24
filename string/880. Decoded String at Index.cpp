
//===類似題===
881. Boats to Save People
1574. Shortest Subarray to be Removed to Make Array Sorted
85. Maximal Rectangle
140. Word Break II

//===思路===
1.遍歷string, 累加所有character的總數, 如;

s="leet2code3"
=> leetleetcode,leetleetcode,leetleetcode =>共36個, index=36  
  
2. 字串"從後到前遍歷"   
-如果遇到數字,就將index/(s[i]-'0')  
-如果遇到字元,就將index-=1;
           
          /--遇到數字3
leet2code3
=> 36/3 = 12
=> leetleetcode,leetleetcode,leetleetcode / 3 = leetleetcode 有12個
       
         /---遇到字元
leet2code 
=> 12-1=11; 
=> leetleetcode-1字元 => leetleetcod
  
3.當k對index(所有的字元數目)取餘數等於零, 代表k整除index, k就落在這個字元上
k= k%index =0
k=10, index =10,  取餘數會等於0  

leetleetco
          \---減去de兩個字元之後, 剩10個, 第10個為'o' 即為解

//===
string decodeAtIndex(string s, int k) {
    long index =0;//記錄總character數
    for(char a:s) index = isdigit(a)?index*(a-'0'): index+1;
    
    for(int i=s.size()-1; i>=0; --i){
        k%=index;
        if(k==0 && isalpha(s[i])) return string(1,s[i]);
        index = isdigit(s[i])?index/(s[i]-'0'):index-1;
    }
    return "";
}
