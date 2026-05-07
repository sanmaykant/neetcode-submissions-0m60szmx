struct VectorHasher {
    size_t operator()(const std::vector<std::string>& v) const {
        size_t seed = 0;
        for (const std::string& s : v) {
            seed ^= std::hash<std::string>{}(s) + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0)
            return {{}};
        
        std::vector<std::vector<std::string>> out;
        std::unordered_set<std::vector<std::string>, VectorHasher> visited;

        std::vector<int> p;
        std::function<void()> backtrack = [&]() -> void {
            bool valid = true;
            std::vector<std::string> views = partitions(s, p);
            if (visited.count(views))
                return;
            
            std::vector<std::string> candidate;

            for (std::string& view : views) {
                valid &= isPalindrome(view);
                candidate.push_back(std::string(view));
            }
            if (valid)
                out.push_back(candidate);
            visited.insert(candidate);

            for (int i = 0; i < p.size(); i++) {
                if (i + 1 < p.size() && p[i+1] > 1) {
                    p[i]++;
                    p[i+1]--;
                    backtrack();
                    p[i]--;
                    p[i+1]++;
                }
            }
        };

        for (int i = 1; i <= s.size(); i++) {
            p.clear();
            p = std::vector<int>(i - 1, 1);
            p.push_back(s.size() - (i - 1));
            backtrack();
        }

        return out;
    }

private:
    std::vector<std::string> partitions(std::string s, const std::vector<int>& p) {
        std::vector<std::string> ps;
        int b = 0;
        for (int i : p) {
            ps.push_back(s.substr(b, i));
            b = b + i;
        }
        return ps;
    }

    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
