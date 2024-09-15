class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> coord = {0, 0}; // x, y
        for (char move : moves){
            if (move == 'U')
                coord.first += 1;
            else if (move == 'D')
                coord.first -= 1;
            else if (move == 'L')
                coord.second += 1;
            else if (move == 'R')
                coord.second -= 1;
        }
        return coord.first == 0 && coord.second == 0;
    }
};