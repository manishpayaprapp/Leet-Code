# 2674.Split a Circular Linked List

## 📝 Problem

You are given a circular linked list containing positive integers. A circular linked list is like a regular linked list, except the last node points back to the first node, forming a circle.

Your task is to split this circular linked list into two separate circular linked lists:

1. **First circular linked list** — Should contain the first half of the nodes, which is exactly `ceil(list.length / 2)` nodes. For example, if the original list has 5 nodes, the first list gets 3 nodes. If it has 6 nodes, the first list gets 3 nodes.
2. **Second circular linked list** — Should contain all the remaining nodes.

Both resulting lists must:

- Maintain the original order of nodes as they appeared in the input list
- Be circular (the last node of each list should point back to its own first node)

The function should return an array of length 2, where:

- The first element is the head of the first circular linked list
- The second element is the head of the second circular linked list

### Example

```text
Input:  1 -> 2 -> 3 -> 4 -> 5 -> (back to 1)

Output:
First list:  1 -> 2 -> 3 -> (back to 1)
Second list: 4 -> 5 -> (back to 4)
```

---

## 📚 Prerequisites

Before attempting this problem, you should be comfortable with:

- **Linked Lists** — Traversing and manipulating `next` pointers
- **Circular Linked Lists** — Detecting cycles and handling lists with no natural end
- **Fast & Slow Pointers** — Using two pointers moving at different speeds to find a midpoint

---

## 💡 Approach

### Fast & Slow Pointer to Find the Midpoint

Since the list is circular, there is no `nullptr` to signal the end — the standard fast/slow pointer termination condition must instead check for a return to `head`.

Start `slow` at `head` and `fast` at `head->next`. Advance `slow` by one node and `fast` by two nodes per iteration, stopping once `fast` (or its next node) reaches back around to `head`. When the pointers stop, `slow` sits at the last node of the first half — exactly `ceil(n / 2)` nodes in.

Once the midpoint is found:

1. Rewire the tail of the second half (`fast`) to point back to the second half's own start (`slow->next`), closing that list into its own circle.
2. Rewire `slow->next` to point back to `head`, closing the first half into its own circle.
3. Return `{head, fast->next}` as the two new circular list heads.

### Why `fast` Starts at `head->next`

Starting `fast` one step ahead (rather than at `head`) ensures the split lands on the correct boundary so the first list ends up with `ceil(n / 2)` nodes rather than `floor(n / 2)`.

---

## 💻 Solution

```cpp
class Solution {
public:
    pair<Node*, Node*> splitList(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != head && fast->next != head) {
            slow = slow->next;

            fast = fast->next;

            if (fast->next != head) {
                fast = fast->next;
            }
        }

        fast->next = slow->next;
        slow->next = head;

        return {head, fast->next};
    }
};
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(N)
```

The fast and slow pointers each traverse the list once to find the midpoint.

### Space Complexity

```text
O(1)
```

Only a constant number of pointers are used — the split is done by rewiring existing nodes in place.

where `N` is the number of nodes in the original circular linked list.

---

## ⚠️ Common Pitfalls

### Wrong Loop Termination Condition

Because the list is circular, the loop must check `fast != head` and `fast->next != head` instead of the usual `fast != nullptr` checks used in linear linked lists. Forgetting this causes an infinite loop.

### Off-by-One in Node Distribution

Starting `fast` at `head->next` instead of `head` is what guarantees the first list receives `ceil(n / 2)` nodes. Starting both pointers at `head` shifts the split point and produces the wrong distribution for odd-length lists.

### Forgetting to Re-Close Both Circles

Both resulting lists must independently point back to their own heads. It's easy to fix one list's circularity (`slow->next = head`) and forget the other (`fast->next = slow->next`), leaving the second list broken or still linked into the first.

### Not Handling Small Lists

Lists with only 1 or 2 nodes are edge cases worth tracing through by hand — with very few nodes, `slow` and `fast` can end up pointing to the same or adjacent nodes almost immediately.

---

## 🎯 Key Takeaway

Adapt the classic **fast & slow pointer midpoint-finding technique** to circular lists by replacing null checks with "back to head" checks, then rewire just two `next` pointers to split one circle into two:

```text
1. Find the midpoint with fast/slow pointers (circular termination)
2. Close the second half into its own circle
3. Close the first half into its own circle
```
