class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> pref_squares;
        vector<int> cnt_perf_sqaures(n);
        
        for (int i = 1; i*i <= n; i++)
        {
            pref_squares.push_back(i*i);
            cnt_perf_sqaures[i*i - 1] = 1;
        }
        
        if (pref_squares.back() == n)
            return 1;
        
        queue<int> searchQ;
        for (auto& i : pref_squares) {
            searchQ.push(i);
        }
        
        int curr_cnt_perf_squares = 1;
        while (!searchQ.empty()) {
            curr_cnt_perf_squares++;
            int searchQSize = searchQ.size();
            for (int i = 0; i < searchQSize; i++) {
                int tmp = searchQ.front();
                for (auto& j : pref_squares) {
                    if (tmp + j == n) {
                        // We have reached node n.
                        return curr_cnt_perf_squares;
                    }
                    else if ((tmp + j < n) && (cnt_perf_sqaures[tmp + j - 1] == 0)) {
                        cnt_perf_sqaures[tmp + j - 1] = curr_cnt_perf_squares;
                        searchQ.push(tmp + j);
                    }
                    else if (tmp + j > n) {
                        break;
                    }
                }       
                searchQ.pop();
            }
        }      
        return 0;
    }
};