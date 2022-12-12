//=====類似題=====
1333. Filter Restaurants by Vegan-Friendly, Price and Distance
412. Fizz Buzz
2130. Maximum Twin Sum of a Linked List
68. Text Justification


int helper1(string s){
	if(s.empty()) return 0;
	if( s==string(rbegin(s),rend(s)) ) return 1;
	return 2;
}

int removePalindromeSub(string s) {
        return helper1(s);
}
