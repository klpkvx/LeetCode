class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char move : moves){
            switch (move){
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x++; break;
                case 'R': x--; break;
                default: continue;
            }
        }
        return x == 0 && y == 0;
    }
};