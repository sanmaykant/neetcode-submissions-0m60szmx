class MedianFinder {
public:
    MedianFinder() = default;

    void addNum(int num) {
        if (m_MaxHeap.empty() && m_MinHeap.empty()) {
            m_MaxHeap.push(num);
            return; 
        } else if (!m_MaxHeap.empty() && m_MinHeap.empty()) {
            if (num > m_MaxHeap.top())
                m_MinHeap.push(num);
            else {
                m_MinHeap.push(m_MaxHeap.top());
                m_MaxHeap.pop();
                m_MaxHeap.push(num);
            }
            return;
        }

        if (m_MaxHeap.size() == m_MinHeap.size()) {
            if (num < m_MinHeap.top())
                m_MaxHeap.push(num);
            else {
                m_MaxHeap.push(m_MinHeap.top());
                m_MinHeap.pop();
                m_MinHeap.push(num);
            }
        } else if (m_MaxHeap.size() == m_MinHeap.size() + 1) {
            if (num > m_MaxHeap.top())
                m_MinHeap.push(num);
            else {
                m_MinHeap.push(m_MaxHeap.top());
                m_MaxHeap.pop();
                m_MaxHeap.push(num);
            }
        }
    }

    double findMedian() {
        if (m_MaxHeap.size() == m_MinHeap.size())
            return static_cast<double>(m_MaxHeap.top() + m_MinHeap.top()) / 2.;
        else
            return static_cast<double>(m_MaxHeap.top());
    }

private:
    std::priority_queue<int, std::vector<int>, std::less<int>>    m_MaxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_MinHeap;
};
