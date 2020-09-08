#include <vector>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    vector<int> v;

    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = v.begin();
        for (; it != v.end(); ++it) {
            if (num > *it) {
                v.insert(it, num);
                return;
            }
        }
        //case where it's the biggest element (failed to insert during the for loop)
        v.push_back(num);
    }
    
    double findMedian() {
        //even - need the two middle numbers
        int size = v.size();
        if (size == 0) {
            return 0.0;
        } else if (size == 1) {
            return static_cast<double>(v[0]);
        }
        else if (size % 2 == 0) {
            int n2 = size / 2;
            int n1 = n2 - 1;
            return (static_cast<double>(v[n1]) + static_cast<double>(v[n2])) / 2.0;
        } else { // odd - round down from the halfway point
            int n = size / 2;
            return static_cast<double>(v[n]);
        }
    }
};

int main(void) {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << "Added 1 and 2, current median: " << mf.findMedian() << "\n";
    mf.addNum(3);
    cout << "Added 3, current median: " << mf.findMedian() << "\n";
}