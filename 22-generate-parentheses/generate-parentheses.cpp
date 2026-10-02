class Solution {
public:
   void generate(int open,int close , string s,vector<string>&v){
    if(open==0 && close ==0){
        v.push_back(s);
        return;
    }
   if(open>0){
        generate(open-1,close , s+'(',v);

    }
    if(open<close){

        generate(open,close-1 , s+')',v);

    }
  
   }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        generate(n,n,s,ans);
        return ans;        
        
    }
};