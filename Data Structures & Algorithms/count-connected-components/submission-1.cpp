class DisjointSet {
    public:
        DisjointSet(int n)
            : m_Rank(n, 0), m_Parent(n) {
                for (int i = 0; i < n; i++)
                    m_Parent[i] = i;
            }
    
        int findUParent(int node) {
            if (node == m_Parent[node])
                return node;
            return m_Parent[node] = findUParent(m_Parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulPu = findUParent(u);
            int ulPv = findUParent(v);
            if (ulPu == ulPv)
                return;

            if (m_Rank[ulPu] > m_Rank[ulPv])
                m_Parent[ulPv] = ulPu;
            else if (m_Rank[ulPu] < m_Rank[ulPv])
                m_Parent[ulPu] = ulPv;
            else {
                m_Parent[ulPu] = ulPv;
                m_Rank[ulPv]++;
            }
        }

    private:
        std::vector<int> m_Rank, m_Parent;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (std::vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ds.unionByRank(u, v);
        }

        std::unordered_set<int> ulPs;
        for (int i = 0; i < n; i++)
            ulPs.insert(ds.findUParent(i));
        return ulPs.size();
    }
};
