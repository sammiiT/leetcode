//===類似題===
797. All Paths From Source to Target
1189. Maximum Number of Balloons
1507. Reformat Date
2483. Minimum Penalty for a Shop

//===思路===


//=========
bool helper0(string s, string goal){
    int i = 0;
    while(i<s.size()){//有n個, rotate n次, 最後一次會rotate成原來的排列方式
        char p = s[0];
        s.erase(s.begin());
        s.push_back(p);
        if(s==goal) return true;
        ++i;
    }
    return false;
}

bool rotateString(string s, string goal) {
    return helper0(s,goal);
}




//=====
bool rotateString(string s, string goal) {
       
    if(s.length()!=goal.length())
          return false;
    string temp= s + s;
    int index=temp.find(goal);
    if(index>=temp.size()-1){
        return false;
    }
        return true;
}
