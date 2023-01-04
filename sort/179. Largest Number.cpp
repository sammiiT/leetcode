//====類似題===
186. Reverse Words in a String II
2165. Smallest Value of the Rearranged Number
//===思路===
(*)
to_string的比大小需要string的size()相等,比較出來才正確
    ab > ba
比如9和34，由于934>349
30和3，由于303<330


//=========
string helper0(vector<int>& nums){
  string res="";
  sort(nums.begin(),nums.end(),
       [](int a, int b){ return to_string(a)+to_string(b)>to_string(b)+to_string(a);});
  
  for(int i=0; i<nums.size(); i++){
    res = res+to_string(nums[i]);
  } 
  return res[0]=='0'?"0":res;
}

string largestNumber(vector<int>& nums){
  return helper0(nums);
}
