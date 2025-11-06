#include <bits/stdc++.h>
using namespace std;


class Point {
public:
    long long x, y;
    Point(long long x, long long y) {
        this->x = x;
        this->y = y;
    }
};

int ccw(Point A, Point B, Point C) {
    long long ccw = (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x);

    if (ccw > 0) return 1;
    else if(ccw < 0) return -1;
    else if(ccw == 0) return 0;
}

bool isIntersect(Point A, Point B, Point C, Point D) {
    int ccw1 = ccw(A,B,C)*ccw(A,B,D);
    int ccw2 = ccw(C,D,A)*ccw(C,D,B);

    if (ccw1 <= 0 && ccw2 <= 0) {
        if (ccw1 == 0 && ccw2 ==0) {
            // All 4 points are collinear.
            // Check if they overlap
            return min(A.x, B.x) <= max(C.x, D.x) &&
                 min(C.x, D.x) <= max(A.x, B.x) &&
                 min(A.y, B.y) <= max(C.y, D.y) &&
                 min(C.y, D.y) <= max(A.y, B.y);
        }				
        return true;
    }

    return false;
}