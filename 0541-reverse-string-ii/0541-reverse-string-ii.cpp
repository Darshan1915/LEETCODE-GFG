class Solution {
public:
    string reverseStr(string s, int k) {

        int st,ed,i,n=s.size();
        if(n<k)
        {
        reverse(s.begin(),s.end());
        return s;
        }
        for(i=0;i<s.size();i=i+2*k)
        {
        st=i;
        ed=i+(k-1);
        if(ed>n-1) // to handle one test case 
        ed=n-1;
        while(st<ed)
        {
            swap(s[st],s[ed]);
            st++,ed--;
        } 
        }
        return s;
        
    }
};