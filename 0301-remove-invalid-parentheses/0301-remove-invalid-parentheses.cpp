class Solution {
public:
    void solve(string&s,unordered_set<string>&ans,int open,int close,int bal,int index,string&output){
        if(index>=s.length()){
            if(open==0 && close==0 && bal==0)
                ans.insert(output);
            return ;
        }
        //include exclude
        if(s[index]!='(' && s[index]!=')'){
            output.push_back(s[index]);
            solve(s,ans,open,close,bal,index+1,output);
            output.pop_back();
        }
        else{
            //brackets
            if(s[index]=='('){
                //include exclude
                //remove 
                if(open>0)
                    solve(s,ans,open-1,close,bal,index+1,output);
                //dont remove
                output.push_back('(');
                solve(s,ans,open,close,bal+1,index+1,output);
                output.pop_back();
            }
            else if(s[index]==')'){
                //remove
                if(close>0){
                    solve(s,ans,open,close-1,bal,index+1,output);
                }
                //dont remove
                //we are at a closing bracket and previously no open bracket was there
                if(bal>0){
                    output.push_back(')');
                    solve(s,ans,open,close,bal-1,index+1,output);
                    output.pop_back();
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int invalidOpen=0;
        int invalidClose=0;
        int balance=0;
        int index=0;
        string output="";
        for(auto ch:s){
            if(ch=='(') invalidOpen++;
            else if(ch==')'){
            if(invalidOpen>0)
                invalidOpen--;
            else invalidClose++;
            }
        }
        solve(s,ans,invalidOpen,invalidClose,balance,index,output);
        return vector<string>(ans.begin(),ans.end());
    }
};