// Source : https://leetcode.cn/problems/find-median-from-data-stream/ 
// Author : Yanan Wang
// Date   : 2023-10-14

/**
 * 本题用一个大根堆、一个小根堆
 *      大根堆 -- 保存较小的一半，数量为N/2（N为偶数）或(N+1)/2（N为奇数）
 *      小根堆 -- 保存较大的一半，数量为N/2（N为偶数）或(N-1)/2（N为奇数）
 *    -----------------------
 *       大根堆   |   小根堆
 * 返回结果时，若大根堆数量==小根堆数量，就分别取top求和/2
 *           若大根堆数量!=小根堆数量，就取大根堆top
 * 细节在于addNum函数：
 *      要在addNum的同时，不断的维护大根堆和小根堆的数量关系
 *      当大根堆数量 == 小根堆数量时，由于本次要插入数据，所以，必须要形成大根堆数量 == 小根堆数量 + 1
 *          1、若num <= 大根堆top或者大根堆为空，就往大根堆push
 *          2、若num > 大根堆top，就往小根堆push，然后把小根堆的top push进大根堆
 *          以上两种情况可以合并起来，直接往小根堆push，然后把小根堆的top push进大根堆
 *      当大根堆数量 != 小根堆数量（大根堆数量 > 小根堆数量）时
 *          1、若num >= 小根堆top或者小根堆为空时，就往小根堆push
 *          2、若num < 小根堆top，就往大根堆push，然后把大根堆的top push进小根堆
 *          以上两种情况可以合并起来，直接往大根堆push，然后把大根堆的top push进小根堆
 */

class MedianFinder {
private:
    priority_queue<int> A; //大根堆
    priority_queue<int, vector<int>, greater<int>> B; // 小根堆
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (A.size() == B.size()) {
            B.push(num);
            A.push(B.top());
            B.pop();
        } else {
            A.push(num);
            B.push(A.top());
            A.pop();         
        }     
    }
    
    double findMedian() {
        return A.size() == B.size() ? ((A.top() + B.top()) / 2.0) : A.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */