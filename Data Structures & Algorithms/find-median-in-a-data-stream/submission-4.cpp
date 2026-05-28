#include <queue>
#include <vector>
#include <iostream>

class MedianFinder {
public:
    MedianFinder() = default;

    void addNum(int num) {
        m_MaxHeap.push(num);
        m_MinHeap.push(m_MaxHeap.top());
        m_MaxHeap.pop();

        if (m_MaxHeap.size() < m_MinHeap.size()) {
            m_MaxHeap.push(m_MinHeap.top());
            m_MinHeap.pop();
        }
    }

    double findMedian() {
        if (m_MaxHeap.size() > m_MinHeap.size()) {
            return static_cast<double>(m_MaxHeap.top());
        }
        return (static_cast<double>(m_MaxHeap.top()) + static_cast<double>(m_MinHeap.top())) / 2.0;
    }

private:
    std::priority_queue<int, std::vector<int>, std::less<int>>    m_MaxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_MinHeap;
};