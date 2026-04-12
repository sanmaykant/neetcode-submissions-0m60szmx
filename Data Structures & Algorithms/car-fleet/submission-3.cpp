using car = std::pair<int, int>;

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<car> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({ position[i], speed[i] });
        std::sort(cars.begin(), cars.end(), [](car& c1, car& c2) {
                return c1.first > c2.first; });

        std::vector<float> stack;
        for (auto& [position, speed] : cars) {
            int distance = target - position;
            float time = (float) distance / (float) speed;
            if (stack.empty() || time >= (float) stack.back())
                stack.push_back(time);
        }

        std::unordered_set<float> reqTimes;
        for (float& time : stack)
            reqTimes.insert(time);

        return reqTimes.size();
    }
};