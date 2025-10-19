#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Manacher {
public: 

    // p[i] = radius of longest palindrome centered at i 
    // in transformed string
    vector<int> p;    
    
    // transformed string with # and sentinels
    string ms;        

    // preprocess the string and run the algorithm
    Manacher(string &s) {
        
        // left sentinel
        ms = "@"; 
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        
        // right sentinel
        ms += "#$"; 

        // run Manacher’s algorithm
        runManacher();
    }

    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i) {
            
            // mirror of i around center (l + r)/2
            int mirror = l + r - i;

            // initialize p[i] based on its mirror 
            // if within bounds
            if (i < r)
                p[i] = min(r - i, p[mirror]);

            // expand palindrome centered at i
            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]){
                ++p[i];
            }

            // update [l, r] if the palindrome expands 
            // beyond current r
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    // returns length of longest palindrome centered 
    // at 'cen' in original string
    // 'odd' = 1 → check for odd-length, 'odd' = 0 → even-length
    int getLongest(int cen, int odd) {
        
        // map original index to transformed string index
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    // checks if s[l..r] is a palindrome in O(1)
    bool check(int l, int r) {
        int len = r - l + 1;
        int cen = (l + r) / 2;
        return len <= getLongest(cen, len % 2);
    }
};