class Solution {
public:

    bool is_symmetric (int x) {
        string value = to_string (x);
        int left = 0;
        int right = 0;
                if(value.size () %2 == 1) return false;  // if the length of the string is odd return false

        for (int i = 0; i < value.size () / 2; i++) {
                left += value[i] - '0';
                right += value[value.size () - 1 - i] - '0';
        }
        return left == right;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (is_symmetric (i))
                count++;
        }
        return count;
    }
};