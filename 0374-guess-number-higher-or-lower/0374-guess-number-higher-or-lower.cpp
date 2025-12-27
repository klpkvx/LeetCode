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
        long long int result = guess (n);

        if (result == 0)
          return n;
        
        if (result == 1)
          return guessNumber (n + 1);
        else
          return guessNumber (n - 1);  
    }
};