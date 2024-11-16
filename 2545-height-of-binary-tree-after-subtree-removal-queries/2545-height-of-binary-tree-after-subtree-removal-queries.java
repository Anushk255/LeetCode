/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int[] heights;  // Stores heights of leaf nodes in order of traversal
    private int[] d;        // Stores depth/height of each node by its value
    private int[] l;        // Stores left boundary index for each node value
    private int[] r;        // Stores right boundary index for each node value
    private int lenLeaves;
    public int[] treeQueries(TreeNode root, int[] queries) {
        heights = new int[50000];    // For storing leaf heights
        d = new int[100001];         // For storing node depths
        l = new int[100001];         // For storing left boundaries
        r = new int[100001];         // For storing right boundaries
        lenLeaves = 0;               // Initialize leaf counter
        
        // DFS to process the tree and fill arrays
        search(root, 0);
        
        int n = lenLeaves;
        // Arrays to store maximum heights from left and right
        int[] maxl = new int[n];     // Prefix maximums
        int[] maxr = new int[n];     // Suffix maximums
        
        // Build prefix maximum array (left to right)
        // At each position i, stores max height of all leaves to the left
        for (int i = 1; i < n; i++) {
            maxl[i] = Math.max(maxl[i-1], heights[i-1]);
        }
        
        // Build suffix maximum array (right to left)
        // At each position i, stores max height of all leaves to the right
        for (int i = n-2; i >= 0; i--) {
            maxr[i] = Math.max(maxr[i+1], heights[i+1]);
        }
        
        // Process each query
        int[] ret = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int query = queries[i]; 
            int maxxl = maxl[l[query]];   
            int maxxr = maxr[r[query]];
            ret[i] = Math.max(Math.max(maxxl, maxxr), d[query]-1);
        }
        
        return ret;
    }
    private void search(TreeNode p, int h) {
        d[p.val] = h; 
        
    
        if (p.left == null && p.right == null) {
            heights[lenLeaves] = h;   
            l[p.val] = r[p.val] = lenLeaves;  
            lenLeaves++; 
            return;
        }
        
        l[p.val] = lenLeaves; 
        
        
        if (p.left != null) {
            search(p.left, h + 1);
        }
        if (p.right != null) {
            search(p.right, h + 1);
        }
        
        r[p.val] = lenLeaves - 1;
        
    }
}