class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> data; // score[i] -> i
        for (int i = 0; i < (int)score.size (); i++)
            data.push ({score[i], i});
    
        vector<string> answer (score.size ());
        int count = 1;
        while (!data.empty ()){
            auto &human_data = data.top ();
            string value;
            if (count == 1)
                value = "Gold Medal";
            else if (count == 2)
                value = "Silver Medal";
            else if (count == 3)
                value = "Bronze Medal";
            else
                value = to_string (count);
            count++;
            answer[human_data.second] = std::move (value);
            data.pop ();
        }
        return answer;
    }
};