//===運算概念====
string s = "1234,5";
for(int i=0; i<s.size(); i++)
  if(s[i]=="1"){//要用雙引號
  } 


//======
str.insert(str.begin(),'A');//插入character
                            str.insert(str.begin(),"hello");//不能插入一個string, 會有錯誤

str.insert(0,"hello");//插入一個string

str.erase(str.begin()+(str.size()-1));//移除最後一個character
