class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1)
            return std::ceil((double) piles[0] / (double) h);

        int max = piles[0];
        int min = 1;
        for (int& n : piles)
            max = std::max(max, n);

        int k = max;
        while (min <= max) {
            int mid = (max + min) / 2;
            int hrs = 0;
            for (int& n : piles)
                hrs += std::ceil((double) n / (double) mid);

            if (hrs > h)
                min = mid + 1;
            else if (hrs <= h) {
                k = std::min(mid, k);
                max = mid - 1;
            }
        }

        return k;
    }
};
