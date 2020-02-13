/*
When the number are 1,2,3...,n, the binary tree can be categorized by
with node i as root, the left subtree must be constructed by [1,2,...,i-1], and the right subtree must be constructed by [i+1, ..., n]

Thus, let f(i) denote the number of possible trees using [1,...,i]
if the tree is empty, f(0) = 1
if the tree has one node, f(1) = 1
f(2) = f(0) * f(1) + f(1) * f(0)
f(3) = f(0) * f(2) + f(1) * f(1) + f(2) * f(0)
and f(i) = \sum_{i}^{i} f(k-1) * f(i-k)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0] = 1;
        f[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                f[i] += f[j-1] * f[i-j];
            }
        }
        return f[n];
    }
};
