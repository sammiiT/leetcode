//=== more challenge ===
813. Largest Sum of Averages
2247. Maximum Cost of Trip With K Highways
678. Valid Parenthesis String
//===
1. 用pow(2,i)計算
2.每次求出離n最近的power_of_2 差值, 再將此"差值"再帶入計算,  差值等於零時即為運算的最少次數; 如
n=10
=>pow(2,3)=8   => abs(10-8)=2   => 取差值2帶入,再計算, => abs(2-pow(2,1)) =0 (差值為零) => 共計算兩次
=>pow(2,4)=16  => abs(10-16)=6


int minimum_abs(int n){ //距離power_of_2最近的差值
    int num=0,i=0,res = INT_MAX;
    do{
        num = pow(2,i);
        if(abs(n-num) <= res){
            res = abs(n-num);
        }
        ++i;
    }while(num<n);
    return res;
}

int minOperations(int n) {
    int count = 0;
    int mi;
    do{
        n = minimum_abs(n);
        ++count;//每季算一次差值, 即累加次數一次
    }while(n>0);//若差值為"0",跳出迴圈,  總計算次數即為"解"
    return count;        
}
