class DisjointSet {
    public:
        DisjointSet(int n)
            : m_Rank(n, 0), m_Parent(n) {
                for (int i = 0; i < n; i++)
                    m_Parent[i] = i;
            }

        int findUParent(int node) {
            if (m_Parent[node] == node)
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
        std::vector<int> m_Parent, m_Rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size() + 1);
        for (std::vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int ulPu = ds.findUParent(u);
            int ulPv = ds.findUParent(v);

            std::cout << u << " ";
            std::cout << v << " ";
            std::cout << ulPu << " ";
            std::cout << ulPv << "\n";

            if (ulPu == ulPv)
                return edge;

            ds.unionByRank(u, v);
        }

        return {};
    }
};
