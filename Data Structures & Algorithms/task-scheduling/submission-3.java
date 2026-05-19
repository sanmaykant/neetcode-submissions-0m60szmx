public record Pair(Integer freq, Integer avail) {}

class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> freqs = new HashMap<>();
        for (char task : tasks) {
            if (!freqs.containsKey(task))
                freqs.put(task, 0);
            freqs.put(task, freqs.get(task) + 1);
        }

        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(
            (i, j) -> Integer.compare(j, i));
        for (Integer freq : freqs.values())
            maxHeap.add(freq);

        Queue<Pair> fifo = new LinkedList<>();

        int t = 0;
        while (!maxHeap.isEmpty() || !fifo.isEmpty()) {
            while (!fifo.isEmpty() && fifo.peek().avail <= t)
                maxHeap.add(fifo.poll().freq);

            if (!maxHeap.isEmpty()) {
                Integer freq = maxHeap.poll();
                if (freq > 1)
                    fifo.add(new Pair(freq - 1, t + n + 1)); 
            }
            t++;
        }

        return t;
    }
}
