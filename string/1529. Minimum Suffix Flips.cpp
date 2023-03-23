//===類似題===
1530. Number of Good Leaf Nodes Pairs
1154. Day of the Year
266. Palindrome Permutation
1181. Before and After Puzzle

//===思路===
(*)題目說將s="00000" 轉化為 target="10111" 需要幾次
- 可以反思為, 從target="10111"轉變為 "00000" 需要幾次步驟

1. 宣告一變數flip紀錄翻轉的總次數
2. 取當下的值target[i]
3. target[i]與之前"flip總和"做判斷; 因為要轉成0,所以出現1要將flip累加 

target[i]=0 , flip奇數 => target[i]會變成1, 所以必須再flip一次 => flip++
target[i]=1 , flip奇數 => target[i]會變成0, 所以不用flip => 繼續往下一個遍歷
target[i]=0 , flip偶數 => target[i]會變成0, 所以不用flip => 繼續往下一個遍歷
target[i]=1 , flip偶數 => target[i]會變成1, 所以必須再flip一次 => flip++

取會"變成1"的情況:
if((target[i]==0 && flip%2==1)||(target[i]==1 && flip%2==0)) flip ++;


(*)因為"相同的1"和"相同的0"會連續出現, 所以將每一個character擴展為區塊來看
- 1110011000011 => 一共有五個區塊 [111] [00] [11] [0000][11] 
- 再簡化為10101用上述思路來解題
  
  
//===

int minFlips(string target) {
    int flip = 0;
    int i,j;
    for( j=0, i=0;i<=target.size();i++){
        if(i==target.size()) break;
        if(target[j]==target[i]) continue;//連續相同的character, 繼續遍歷
        if((target[j]-'0'==0 && flip%2==1)||(target[j]-'0'==1 && flip%2==0)) ++flip;//遇到不同的character, 判斷是否要做flip
        j = i;//更新下一個區塊的起始值
    }
    
    //最後一個區段
    if((target[j]-'0'==0 && flip%2==1)||(target[j]-'0'==1 && flip%2==0)) ++flip;
    return flip;
}
