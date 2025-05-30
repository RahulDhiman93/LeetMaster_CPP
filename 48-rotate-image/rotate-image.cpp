class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        map<pair<int, int>, int> hmap;
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                hmap[{i, j}] = matrix[i][j];
            }
        }

        int m = n-1;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                matrix[i][j] = hmap[{m, i}];
            }
            m--;
        }
    }
};