# Reverse Words in a String II

## 📝 Problem

Given an array of characters `s` representing a sentence, reverse the order of the words **in place**.

A word is defined as a sequence of non-space characters. The words in `s` are separated by a single space, and `s` does not contain leading or trailing spaces.

### Example

```text
Input:  s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

Input:  s = ["a"]
Output: ["a"]
```

---

## 📚 Prerequisites

Before attempting this problem, you should be comfortable with:

- **Two Pointers** — Using left and right pointers to swap elements in place
- **In-place Array Manipulation** — Modifying arrays without using extra space
- **String Reversal** — Reversing a sequence of characters using two pointers

---

## 💡 Approach

### Reverse the Whole String, Then Reverse Each Word

Reversing the word order might seem complex, but there is a clever trick: reverse the **entire string first**, then reverse **each individual word**.

When the whole string is reversed, the words end up in the correct order, but each word itself is spelled backward. Reversing each word individually fixes the spelling while preserving the new word order. This two-pass approach elegantly solves the problem in place.

### Algorithm

1. Reverse the entire character array using two pointers that swap characters from both ends moving inward.
2. Iterate through the array to find each word (delimited by spaces).
3. For each word found, reverse just that segment using the same two-pointer swap technique.
4. Continue until all words have been reversed.

### Example: `["t","h","e"," ","s","k","y"]`

```text
Step 1 — Reverse whole string: "yks eht"
Step 2 — Reverse each word:    "sky the"
```

---

## 💻 Solution

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        // 'start' points to the beginning of the current word
        // 'end' points to the position just after the current word
        int start = 0, end = 0;
        int n = s.size();

        while (start < n) {

            // Move 'end' to the position just after the current word
            while (end < n && s[end] != ' ')
                end++;

            // Note: in C++, reverse() operates on [start, end)
            // The leftmost element is included, the rightmost is not
            reverse(s.begin() + start, s.begin() + end);

            // Move 'start' and 'end' to the beginning of the next word
            end++;
            start = end;
        }
    }
};
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(N)
```

Two passes are made along the string — one to reverse the whole thing, and one to reverse each word.

### Space Complexity

```text
O(1)
```

The reversal is done in place, using only a constant amount of extra space.

where `N` is the length of the input `s`.

---

## ⚠️ Common Pitfalls

### Reversing in the Wrong Order

The two-step process must be done in the correct order: first reverse the entire string, then reverse each individual word. Doing it in reverse order (reversing each word first, then the whole string) produces the same result, but the logic is less intuitive when thinking about word order reversal.

### Incorrect Word Boundary Detection

When finding word boundaries, ensure you correctly handle the transition between words and spaces. Off-by-one errors when determining where a word ends can cause characters to be included in the wrong word or skipped entirely.

### Not Handling Edge Cases

Edge cases like a single word with no spaces, or strings that start or end with a space, need careful handling. The algorithm should work correctly regardless of word count or spacing patterns in the input.

---

## 🎯 Key Takeaway

Instead of directly rearranging words with extra storage, use a **reverse-then-reverse** trick:

```text
1. Reverse the whole array
2. Reverse each word segment individually
```

This converts the problem into a simple **Two-Pointer + In-place Reversal** problem.
