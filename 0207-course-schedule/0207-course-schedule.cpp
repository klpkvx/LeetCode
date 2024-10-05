class Solution {
public:

    vector<vector<int>> build_graph (int n, vector<vector<int>> &data) {
        vector<vector<int>> graph (n);
        for (const vector<int> &curr : data) {
            graph[curr[1]].push_back (curr[0]);
        }
        return graph;
    }

    vector<int> get_degrees (vector<vector<int>> &graph) {
        vector<int> degrees (graph.size (), 0);
        for (int i = 0; i < graph.size (); i++) {
            for (int j = 0; j < graph[i].size (); j++) {
                degrees[graph[i][j]]++;
            }
        }
        return degrees;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = build_graph (numCourses, prerequisites);
        vector<int> degrees = get_degrees (graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            while (j < numCourses) {
                if (!degrees[j]) {
                    break;
                }
                j++;

            }

            if (j == numCourses)
                return false;
            degrees[j]--;
            for (int v : graph[j])
                degrees[v]--;
        }
        return true;
    }
};