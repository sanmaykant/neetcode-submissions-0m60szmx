using point = std::vector<int>;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::function<bool(const point& p1, const point& p2)> cmp =
                [](const point& p1, const point& p2) -> bool {
            float d1 = std::sqrt((float) (p1[0] * p1[0] + p1[1] * p1[1]));
            float d2 = std::sqrt((float) (p2[0] * p2[0] + p2[1] * p2[1]));
            return d1 < d2; 
        };

        std::vector<point> out; 
        for (point& point : points) {
            if (out.size() < k) {
                out.push_back(point);
                std::push_heap(out.begin(), out.end(), cmp);
            }
            else {
                out.push_back(point);
                std::push_heap(out.begin(), out.end(), cmp);

                std::pop_heap(out.begin(), out.end(), cmp);
                out.pop_back();
            }
        }

        return out;
    }
}; 