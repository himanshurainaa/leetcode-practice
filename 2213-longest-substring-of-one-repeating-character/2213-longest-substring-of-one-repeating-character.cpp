#include <vector>
#include <string>
#include <algorithm>

struct Node {
    int max_len = 0;
    int prefix_len = 0;
    int suffix_len = 0;
    char left_char = 0;
    char right_char = 0;
    int range_len = 0;
};

class SegmentTree {
    int n;
    std::string s;
    std::vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.range_len = left.range_len + right.range_len;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        res.prefix_len = left.prefix_len;
        if (left.prefix_len == left.range_len && left.right_char == right.left_char) {
            res.prefix_len += right.prefix_len;
        }

        res.suffix_len = right.suffix_len;
        if (right.suffix_len == right.range_len && left.right_char == right.left_char) {
            res.suffix_len += left.suffix_len;
        }

        res.max_len = std::max(left.max_len, right.max_len);
        if (left.right_char == right.left_char) {
            res.max_len = std::max(res.max_len, left.suffix_len + right.prefix_len);
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            s[idx] = ch;
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const std::string& str) : s(str), n(str.size()) {
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMax() const {
        return tree[1].max_len;
    }
};

class Solution {
public:
    std::vector<int> longestRepeating(std::string s, std::string queryCharacters, std::vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        std::vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};