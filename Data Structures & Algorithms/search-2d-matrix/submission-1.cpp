class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0;
        int j = rows * cols - 1;

        while (i <= j) {
            int mid = (i + j) / 2;
            int r = std::floor(mid / cols);
            int c = mid - r * cols;

            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                j = mid - 1;
            else if (matrix[r][c] < target)
                i = mid + 1;
        }
        return false;
    }
};
