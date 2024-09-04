/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long left = 0;
        long right = n;
        while (left <= right)
        {
            long candidate = (left + right) / 2;
            long result = guess (candidate);
            if (result == 0)
                return candidate;
            else if (result == -1)
                right = candidate - 1;
            else
                left = candidate + 1;
        }

        return 1337;        
    }
};