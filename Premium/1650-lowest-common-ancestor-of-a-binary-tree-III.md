# 1650. Lowest Common Ancestor of a Binary Tree III

## 📝 Problem

You are given two nodes `p` and `q` in a binary tree.

Each node contains a reference to its **parent** node.

Return the **Lowest Common Ancestor (LCA)** of nodes `p` and `q`.

The Lowest Common Ancestor is the lowest node in the tree that has both `p` and `q` as descendants.

A node can also be considered a descendant of itself.

### Node Structure

```cpp
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
```

### Example 1

```text
Input:
p = 1
q = 2

Tree:

        5
       /
      3
     / \
    2   4
   /
  1

Output:
3
```

### Example 2

```text
Input:
p = 3
q = 12

Output:
3
```

### Constraints

* `2 <= number of nodes <= 100,000`
* `-1,000,000,000 <= Node.val <= 1,000,000,000`
* All `Node.val` are unique.
* `p != q`
* Both `p` and `q` exist in the tree.

---

## 💡 Approach

Since every node has a pointer to its **parent**, we can move upward from both nodes.

The main challenge is that `p` and `q` may be at **different depths**.

Instead of calculating the depth of each node, we can use a **Two-Pointer Technique**.

Create two pointers:

```cpp
Node* p1 = p;
Node* q1 = q;
```

Then move both pointers toward their parents.

When a pointer reaches `nullptr`, redirect it to the **other starting node**.

```cpp
p1 = (p1 == nullptr) ? q : p1->parent;
q1 = (q1 == nullptr) ? p : q1->parent;
```

This makes both pointers travel the same total distance.

---

## 🔄 How the Two-Pointer Technique Works

Suppose the paths are:

```text
p → A → B → C
q → D → C
```

The pointers will eventually travel:

```text
p1:
p → A → B → C → D → C

q1:
q → D → C → p → A → B → C
```

Because both pointers switch to the other starting node after reaching `nullptr`, they eventually meet at:

```text
C
```

Therefore, `C` is the Lowest Common Ancestor.

---

## 🔍 Dry Run

Consider:

```text
        5
       /
      3
     / \
    2   4
   /
  1
```

Let:

```text
p = 1
q = 4
```

Initially:

```text
p1 = 1
q1 = 4
```

### Step 1

```text
p1 → 2
q1 → 3
```

### Step 2

```text
p1 → 3
q1 → 5
```

### Step 3

```text
p1 → 5
q1 → nullptr
```

`q1` is now `nullptr`, so we redirect it to `p`:

```text
q1 → 1
```

### Step 4

```text
p1 → nullptr
q1 → 2
```

`p1` is now `nullptr`, so we redirect it to `q`:

```text
p1 → 4
```

### Step 5

```text
p1 → 3
q1 → 3
```

Now:

```text
p1 == q1
```

Therefore:

```text
LCA = 3
```

---

## 💻 Solution

```cpp
/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* left;
     Node* right;
     Node* parent;
 };
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {

        Node* p1 = p;
        Node* q1 = q;

        while (p1 != q1) {

            p1 = (p1 == nullptr) ? q : p1->parent;
            q1 = (q1 == nullptr) ? p : q1->parent;
        }

        return q1;
    }
};
```

---

## 🧠 Why Does This Work?

The two nodes can be at different depths.

For example:

```text
p → A → B → LCA
q → LCA
```

Here, `p` is farther from the LCA than `q`.

Instead of calculating the depths, we let each pointer traverse its own path and then switch to the other node's path.

So both pointers cover the same total distance.

Eventually:

```text
p1 == q1
```

The first common node they reach is the **Lowest Common Ancestor**.

The important logic is:

```cpp
p1 = (p1 == nullptr) ? q : p1->parent;
q1 = (q1 == nullptr) ? p : q1->parent;
```

---

## ⏱️ Complexity

### Time Complexity

```text
O(h)
```

where `h` is the height of the tree.

Each pointer traverses the parent paths at most twice.

### Space Complexity

```text
O(1)
```

Only two pointer variables are used.

---

## 🎯 Key Takeaway

When every node has a **parent pointer**, we can find the LCA without traversing the entire tree.

Use two pointers:

```text
p1 → parent → parent → ...
q1 → parent → parent → ...
```

When a pointer reaches `nullptr`, switch it to the **other starting node**:

```cpp
p1 = (p1 == nullptr) ? q : p1->parent;
q1 = (q1 == nullptr) ? p : q1->parent;
```

Eventually:

```text
p1 == q1
```

and that node is the **Lowest Common Ancestor**.

**Pattern Used:** Two Pointers + Parent Pointers
