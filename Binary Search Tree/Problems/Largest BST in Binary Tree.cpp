#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int maxNode, int minNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(Node* root) {
        if (root == NULL) {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        if (root->data > left.maxNode && root->data < right.minNode) {
            return NodeValue(max(right.maxNode, root->data), min(left.minNode, root->data), left.maxSize + right.maxSize + 1);
        } else {
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
    }

public:
    int largestBSTSubtree(Node* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    Solution sol;
    cout << "Size of the largest BST is: " << sol.largestBSTSubtree(root) << endl;

    return 0;
}