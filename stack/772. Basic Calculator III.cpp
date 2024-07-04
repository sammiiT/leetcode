//=== more challenge ===


//=== 思路 ====
(*) stack + dfs
-遇到 '(' 開始往下一層計算
-在同一層的計算, 用stack紀錄
-遇到 ')' 將同一層的stack數值做累加, 並回傳給上一層.


int calculator(string& s, int& index){
    vector<long> nums;
    long val = 0;
    char op = '+';

    while(index < s.size()){
        if(s[index]>='0' && s[index]<='9'){
            val = val*10 + s[index]-'0';
        }else if(s[index]==' '){
        }else if(s[index]=='('){//遇到 '(' 開始往下一層計算
            int brk = calculator(s,++index);                
            if(op=='+'){ nums.push_back(brk);    
            }else if(op=='-'){ nums.push_back(brk*(-1));
            }else if(op=='*'){ nums.back() = nums.back()*brk;
            }else if(op=='/'){ nums.back() = nums.back()/brk; }
            val = 0;//每次運算完,要重新定義 val和operator, 
            //op = '+';//'+'是push_back(), val=0是push_back(0),所以最後運算不影像總數值. ==> 這一個會有問題
            op = s[index];//從stack回上層時, 會將index做update
            
        }else if(s[index]==')'){//遇到 ')' 將同一層的stack數值做累加, 並回傳給上一層.
            if(op=='+'){ nums.push_back(val);
            }else if(op=='-'){ nums.push_back(val*(-1));
            }else if(op=='*'){ nums.back() = nums.back()*val;
            }else if(op=='/'){ nums.back() = nums.back()/val; }
            val = 0;
            while(!nums.empty()){
                val = val + nums.back();
                nums.pop_back();
            }
            ++index;
            return val;
            
        } else {//+,-,*,/  在同一層的計算, 用stack紀錄
            if(op=='+'){ nums.push_back(val);
            }else if(op=='-'){ nums.push_back(val*(-1));
            }else if(op=='*'){ nums.back() = nums.back()*val;
            }else if(op=='/'){ nums.back() = nums.back()/val; }
            val = 0;
            op = s[index];
        }
        ++index;
    }
    
    if(op=='+'){ nums.push_back(val);
    }else if(op=='-'){ nums.push_back(val*(-1));
    }else if(op=='*'){ nums.back() = nums.back()*val;
    }else if(op=='/'){ nums.back() = nums.back()/val; }
    
    val = 0;    
    while(!nums.empty()){
        val = val + nums.back();
        nums.pop_back();
    }
    return val;
}

int calculate(string s) {
    int index = 0; 
    return calculator(s,index);           
}
