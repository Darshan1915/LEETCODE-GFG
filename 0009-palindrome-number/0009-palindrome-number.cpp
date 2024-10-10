class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int ans = 0, temp = x;
        while(x!=0){

            int digit = x%10;
            ans = ans*10 + digit; // Append the digit to the reversed number
            x = x/10; //Remove the last digit;

        }
        if(temp == ans){
            return true;
        }else{
            return false;
        }   
    }
};