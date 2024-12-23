//Original:

// class Solution {
// public:
//     int countGoodNumbers(long long n) {
        
//     }
// };


//Answer :

/*

    Time Complexity : O(logN).

    Space Complexity : O(logN), Recursion stack space.

*/

#define mod 1000000007
class Solution {
private:
    long long power(long long x, long long n){

        // double ans = 1.0;
        // long long nn = n;
        // if (nn < 0) nn = -1 * nn;
        // while (nn) {
        //     if (nn % 2) {
        //     ans = ans * x;
        //     nn = nn - 1;
        //     } else {
        //     x = x * x;
        //     nn = nn / 2;
        //     }
        // }
        // if (n < 0) ans = (double)(1.0) / (double)(ans);
        // return ans;

        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n/2 + n%2;
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces))%mod;
    }
};