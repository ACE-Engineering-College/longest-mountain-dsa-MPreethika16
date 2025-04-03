#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestMountain(int arr[], int n)
    {
        // write code for Longest 
       
        if (n < 3) return 0;  // A mountain needs at least 3 elements

        vector<int> up(n, 0), down(n, 0);
        int maxLength = 0;

        // Compute increasing sequences (left to right)
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                up[i] = up[i - 1] + 1;
            }
        }

        // Compute decreasing sequences (right to left)
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                down[i] = down[i + 1] + 1;
            }
        }

        // Find the longest mountain
        for (int i = 1; i < n - 1; i++) {
            if (up[i] > 0 && down[i] > 0) {  // It must be a peak
                maxLength = max(maxLength, up[i] + down[i] + 1);
            }
        }

        return maxLength;
    }
};
