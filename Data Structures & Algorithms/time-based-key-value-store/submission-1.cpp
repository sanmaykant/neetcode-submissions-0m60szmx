using entry = std::pair<std::string, int>;
using entries = std::vector<entry>;

class TimeMap {
public:
    TimeMap() = default;

    void set(std::string key, std::string value, int timestamp) {
        map.try_emplace(key, entries{});
        map[key].push_back({ value, timestamp });
    }

    std::string get(std::string key, int timestamp) {
        map.try_emplace(key, entries{});
        entries& entries = map[key];

        if (entries.size() == 0)
            return "";
        if (entries.size() == 1)
            return entries[0].second <= timestamp ? entries[0].first : "";
        if (entries.size() == 2) {
            if (entries[1].second <= timestamp)
                return entries[1].first;
            else if (entries[0].second <= timestamp)
                return entries[0].first;
            else
                return "";
        }

        int i = 0;
        int j = entries.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;

            if (i == j)
                return entries[i].second <= timestamp ? entries[i].first : "";
            else if (i + 1 == j) {
                if (entries[j].second <= timestamp)
                    return entries[j].first;
                else if (entries[i].second <= timestamp)
                    return entries[i].first;
                else
                    break;
            }

            if (entries[mid].second < timestamp) 
                i = mid;
            else if (entries[mid].second > timestamp)
                j = mid;
            else if (entries[mid].second == timestamp)
                return entries[mid].first;
        }

        return "";
    }

public:
    std::unordered_map<std::string, entries> map;
};
