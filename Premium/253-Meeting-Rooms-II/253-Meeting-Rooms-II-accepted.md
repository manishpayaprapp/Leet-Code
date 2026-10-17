# 253. Meeting Rooms II

**Problem:** [https://leetcode.com/problems/meeting-rooms-ii/](https://leetcode.com/problems/meeting-rooms-ii/)

**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Greedy, Sorting, Heap (Priority Queue), Prefix Sum, Sweep Line  
**Language:** cpp  
**Status:** Accepted

## Solution

```cpp
class Solution {
public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {
        map<int, int> mp;

        int bookings = 0;
        int maxBookings = 0;

        for (int i = 0; i < start.size(); i++) {
            mp[start[i]]++;
            mp[end[i]]--;
        }

        for (auto entry : mp) {
            bookings += entry.second;
            maxBookings = max(maxBookings, bookings);
        }

        return maxBookings;
    }
};
