// The Strategy:

//1. We must ensure the heaps are balanced. The Max-Heap can either be the exact same size as the Min-Heap, or it can have exactly one more element than the Min-Heap.

//2. When a new number arrives, we first push it to the Max-Heap.

//3. To guarantee that all elements in the Max-Heap are smaller than those in the Min-Heap, we take the largest element from the Max-Heap (its top) and push it into the Min-Heap.

//4. Finally, if the Min-Heap becomes larger than the Max-Heap, we move the top of the Min-Heap back to the Max-Heap to restore our size constraint.

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Stores the smaller half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // Stores the larger half

public:
    MedianFinder() {}
    
    void addNum(int num) 
    {
        // 1. Add to maxHeap
        maxHeap.push(num);
        
        // 2. Balance the values (ensure maxHeap values <= minHeap values)
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // 3. Balance the sizes (maxHeap should always be >= minHeap in size)
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If sizes are unequal, the extra element is in maxHeap
        if (maxHeap.size() > minHeap.size()) 
            return maxHeap.top();
        
        // If sizes are equal, average the two middle elements
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};