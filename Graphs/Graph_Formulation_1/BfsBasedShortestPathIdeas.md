# BFS and Shortest Path Concepts

## Properties of BFS:
1. BFS explores all nodes layer by layer.
2. Once a node is touched, all adjacent nodes are processed next.

## Single Source Shortest Path (SSSP):
- **Types of Problems:**
  1. Single-pair shortest path.
  2. All-pairs shortest path.

## BFS Characteristics:
- BFS inherently guarantees the shortest path upon first visit.
- No need for edge relaxation because nodes are visited level by level.

## Key BFS Variations and Concepts:

### Grid Question Example:
**Grid:**
```
S . # . .
. . . . .
# # # # .
. . . . .
F . # . .
```

### Questions Asked:
1. **Number of shortest paths:**
   - Use the logic: "The total number of shortest paths to a node is the sum of all identical shortest paths leading to it."

2. **State Formation:**
   - Create state space to represent position and additional constraints.

3. **Multi-Source Variation:**
   - Start BFS from multiple nodes simultaneously.

4. **Algorithm Tweaking:**
   - Modify BFS to handle additional constraints or custom costs.

## Creative Problem: Minimizing Walls Destroyed
**Question:**
Find the minimum number of walls to destroy and the shortest path length to reach `F` from `S`, given you can destroy up to `K` walls (using `K` bombs).

### Solution Approach:
1. **State Space Formulation:**
   - Augment BFS state to include:
     - **Cost:** Total path cost.
     - **Constraint:** Remaining walls that can be destroyed.
   - Example state: `dis((i, j), k)` where `k` represents walls left to destroy.

2. **Cost Minimization:**
   - Treat crossing a wall as a cost of `1`.
   - Use **0/1 BFS** (deque) because weights are either `0` or `1`.

3. **3D Graph Representation:**
   - Each state is represented in a 3D graph:
     - Nodes in 2D grid form the base.
     - Destroying a wall transitions the node to a new plane (another graph layer).
   - Transitioning between planes represents using bombs to destroy walls.
   - Cannot return to a previous plane after transitioning.

### BFS Augmentation:
1. Augment **per-edge cost**:
   - Base cost depends on minimizing distance or walls destroyed.

2. Handle additional constraints:
   - Add constraints like remaining bombs to the state.

### Key Logic:
- Formulate states to track both path and constraints.
- Explore layer by layer, transitioning planes as constraints are used.

## Summary:
- BFS ensures shortest path through level-by-level exploration.
- State augmentation allows BFS to handle complex constraints.
- 3D graph representation is crucial for multi-constraint problems like minimizing walls destroyed.

