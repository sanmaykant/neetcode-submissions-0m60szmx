class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            Comparator.comparingDouble((int[] p) -> distance(p)).reversed());

        for (var p : points) {
            maxHeap.add(p);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }

        int[][] out = new int[k][2];
        int i = 0;
        while (!maxHeap.isEmpty()) {
            out[i++] = maxHeap.remove();
        }
        return out;
    }

    double distance(int[] point) {
        return Math.sqrt((double) (point[0] * point[0] + point[1] * point[1]));
    }
}
