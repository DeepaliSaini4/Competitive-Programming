# Tree Applications: Finding Centers and Counting Diameters

## Key Concepts:

### Centers of a Tree:
1. **Definition**:
   - A **center** is the midpoint of a tree's diameter (longest path between any two nodes).
   - A tree can have **1 or 2 centers**, never more.

2. **Properties**:
   - The center is a property of the tree, **not the diameter**.
   - **Fixed for the tree**: All diameters share the same center.
   - The center ensures the farthest nodes do not increase the diameter.

3. **Finding the Center**:
   - Perform a DFS to determine parent-child relationships.
   - Use the depth of nodes to find the center.

---

## Counting Diameters: Two Cases

### Case 1: Single Center

1. **Root the Tree**:
   - Choose the center as the root for analysis.
   - Focus on leaf nodes at distance **d/2** (where *d* is the diameter length).

2. **Steps**:
   - Perform a DFS starting at the center.
   - Count the number of nodes at a distance of **d/2 - 1** from the center in each branch.
   - Find all pair product:
     
     **Formula**:
     
     ∑ (nodes in branch 1) × (nodes in branch 2) ... (pairwise products).

3. **Implementation Tip**:
   - During DFS, pass the parent node as the root to prevent traversal back to it.
   - Push the count of nodes at **d/2 - 1** distance into a vector, reset the count, and repeat for each subtree.

---

### Case 2: Two Centers

1. **Choose Centers (C1 and C2)**:
   - For two centers, identify the two midpoint nodes of the diameter.
   - Any path passing through the centers forms part of the diameter.

2. **Steps**:
   - Perform a DFS starting at **C1** with **C2** as the blocked parent:
     - Count nodes at distance ⌊*d/2⌋ in the subtree of **C1**.
   - Repeat the DFS for **C2** with **C1** as the blocked parent.

3. **Final Calculation**:
   - Multiply the counts of nodes at distance ⌊*d/2⌋ from both **C1** and **C2**.

---

## Implementation Notes:
- In a single DFS, you can efficiently calculate distances and node counts.
- Use a vector to store counts for each branch, and reset it for every subtree.
- For two-center cases, leverage the "block parent" trick to isolate subtrees during DFS.



