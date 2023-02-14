//===類似題===
169. Majority Element
2194. Cells in a Range on an Excel Sheet
//===思路===
(*)數值轉string ,另外一題是string轉數值
//===
string convertToTitle(int columnNumber) {
    string ans;
    int n = columnNumber;
    do {
        n--;//減一, 做平移; A跟Z差25, 餘數0~25
        ans += 'A' + (char)(n % 26);
        n /= 26;
    } while (n);
//算出來是由"低位"到"高位"
//所以要將string做reverse
    reverse(begin(ans), end(ans));
    return ans;     
}
