using namespace std;
typedef pair<int, int> pii;
class RatOfMaze{


public:

    void dfs(int &min_t, int a[5][5], int m, int n, int i, int j, vector<pii> tmp, vector<vector<int>> visited, vector<vector<pii>> &res)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || a[i][j] == 1 || visited[i][j]) return;

        if (!visited[i][j]) tmp.push_back(make_pair(i, j));

        visited[i][j] = true;

        if (i == m - 1 && j == n - 1)
        {
            res.push_back(tmp);
            if (tmp.size() < min_t)
                min_t = tmp.size();
            return;
        }
        dfs(min_t,a, m, n, i + 1, j, tmp, visited, res);
        dfs(min_t,a, m, n, i - 1, j, tmp, visited, res);
        dfs(min_t,a, m, n, i, j + 1, tmp, visited, res);
        dfs(min_t,a, m, n, i, j - 1, tmp, visited, res);
    }
};
