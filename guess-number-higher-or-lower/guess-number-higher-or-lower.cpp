/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int num=n;
        int low=1, high=n , mid;
        while(low<=high){
             mid=low+(high-low)/2;
            int x=guess(mid);
            if(x==0) break;
            else if(x==1) low=mid+1;
            else high=mid-1;
        }
        return mid;
    }
};