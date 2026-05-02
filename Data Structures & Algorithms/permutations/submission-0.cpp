class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> perms(1);

        for (int num : nums) {
            std::vector<std::vector<int>> newPerms;
            for (std::vector<int>& v : perms) {
                for (int i = 0; i <= v.size(); i++) {
                    std::vector<int> newPerm = v;
                    newPerm.insert(newPerm.begin() + i, num);
                    newPerms.push_back(newPerm);
                }
            }
            perms.clear();
            perms = newPerms;
        }
        
        return perms;
    }
};
