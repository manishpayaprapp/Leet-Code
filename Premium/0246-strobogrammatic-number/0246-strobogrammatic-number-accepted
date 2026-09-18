# 🔄 246. Strobogrammatic Number

## 📝 Problem

Given a string `num` representing a number, return `true` if the number is **strobogrammatic**.

A strobogrammatic number is a number that looks the same when rotated **180 degrees**.

### Valid Rotational Pairs

```text
0 → 0
1 → 1
6 → 9
8 → 8
9 → 6
```

### Example

```text
Input:  num = "69"
Output: true

Input:  num = "88"
Output: true

Input:  num = "962"
Output: false
```

---

## 💡 Approach

Use the **Two-Pointer Technique**.

Place one pointer at the beginning and another at the end:

```text
left →       ← right
```

For every pair of digits:

1. Check whether the left digit is a valid strobogrammatic digit.
2. Find the digit obtained by rotating the left digit by 180°.
3. Compare it with the digit at the `right` pointer.
4. If they don't match, return `false`.
5. Move both pointers toward the center.
6. If all pairs match, return `true`.

The required mappings are:

```text
0 ↔ 0
1 ↔ 1
6 ↔ 9
8 ↔ 8
9 ↔ 6
```

### Example: `619`

```text
6 → 9 ✅
1 → 1 ✅
```

Therefore, `"619"` is strobogrammatic.

---

## 💻 Solution

```cpp
class Solution {
public:
    bool isStrobogrammatic(string num) {

        unordered_map<char, char> mp = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        int left = 0;
        int right = num.size() - 1;

        while (left <= right) {

            // Check if the left digit is valid
            if (mp.find(num[left]) == mp.end()) {
                return false;
            }

            // Check the rotated value
            // against the right digit
            if (mp[num[left]] != num[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(n)
```

We check each digit at most once.

### Space Complexity

```text
O(1)
```

The map contains only 5 fixed digit mappings, so the extra space is constant.

---

## 🎯 Key Takeaway

Instead of actually rotating the number, simply compare the digits from both ends using the rotation mapping:

```text
0 → 0
1 → 1
6 → 9
8 → 8
9 → 6
```

This converts the problem into a simple **Two-Pointer + Hash Map** problem.
