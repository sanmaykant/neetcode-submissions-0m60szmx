class LRUCache {
public:
  LRUCache(int capacity) : m_Capacity(capacity) {}

  int get(int key) {
    if (!m_Map.count(key))
      return -1;

    m_Lru.erase(m_Map[key].second);
    m_Lru.push_back(key);
    m_Map[key].second = std::prev(m_Lru.end());
    return m_Map[key].first;
  }

  void put(int key, int value) {
    if (m_Map.count(key)) {
      m_Lru.erase(m_Map[key].second);
      m_Lru.push_back(key);
      m_Map[key] = {value, std::prev(m_Lru.end())};
    } else if (!m_Map.count(key) && m_Map.size() < m_Capacity) {
      m_Lru.push_back(key);
      m_Map[key] = {value, std::prev(m_Lru.end())};
    } else if (!m_Map.count(key) && m_Map.size() == m_Capacity) {
      m_Map.erase(m_Lru.front());
      m_Lru.pop_front();
      m_Lru.push_back(key);
      m_Map[key] = {value, std::prev(m_Lru.end())};
    }
  }

private:
  int m_Capacity;
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> m_Map;
  std::list<int> m_Lru;
};
