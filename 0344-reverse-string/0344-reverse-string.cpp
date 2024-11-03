class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int a= 0, z = (size-1);
        // for (int i=0; i!='\0';i++){
        //     swap()
        // }
        while(a<z){
            swap(s[a++],s[z--]);
        }
    }
};