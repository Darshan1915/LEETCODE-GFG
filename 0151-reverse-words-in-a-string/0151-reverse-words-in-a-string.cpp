class Solution {
public:
    string reverseWords(string s) {
     int i=0;
     vector<string>ans;
     string st="";
     while(i<s.length()){
      char ch=s[i];
      if(s[i]==' '){
       if(!st.empty()){
        ans.push_back(st);
        st="";
       }
       i++;
      } 
      else{
        st.push_back(ch);
        i++;
        if(i==s.length()){
            ans.push_back(st);
        }
      } 
     }
     reverse(ans.begin(),ans.end());
     string result="";
     for(int i=0;i<ans.size();i++){
        result+=ans[i];
        result+=" ";
       
     }
     result.pop_back();
     return result;
    }
};