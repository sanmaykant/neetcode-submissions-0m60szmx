class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++)
                maxArea = Math.max(maxArea, exploreIsland(grid, i, j));
        return maxArea;
    }

    private int exploreIsland(int[][] grid, int x, int y) {
        boolean validX = x >= 0 && x < grid.length;
        boolean validY = y >= 0 && y < grid[0].length;
        if (!validX || !validY)
            return 0;

        boolean isWater = grid[x][y] == 0;
        if (isWater)
            return 0;

        grid[x][y] = 0;
        int area = 1;

        area += exploreIsland(grid, x, y + 1);
        area += exploreIsland(grid, x + 1, y);
        area += exploreIsland(grid, x, y - 1);
        area += exploreIsland(grid, x - 1, y);

        return area;
    }
}
