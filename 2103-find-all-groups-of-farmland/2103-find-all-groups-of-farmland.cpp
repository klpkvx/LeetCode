class Solution {
public:

    void dfs (vector<vector<int>> &land, int i, int j, vector<int> &coords)
    {
        if (i < 0 || j < 0 || i >= land.size () || j >= land[0].size () || land[i][j] == 0)
            return;
        land[i][j] = 0;
        
        if (i > coords[2]){
            coords[2] = i;
            coords[3] = j;
        }
        else if (i == coords[2] && j > coords[3])
            coords[3] = j;


        dfs (land, i + 1, j, coords);
        dfs (land, i - 1, j, coords);
        dfs (land, i, j + 1, coords);
        dfs (land, i, j - 1, coords);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        for (int i = 0; i < land.size (); i++)
        {
            for (int j = 0; j < land[0].size (); j++)
            {
                if (land[i][j]){
                    vector<int> coords = {i, j, i, j};
                    dfs (land, i, j, coords);
                    result.push_back (coords);
                }
            }
        }
        return result;
    }
};