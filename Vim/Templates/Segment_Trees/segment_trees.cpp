/*COMPETITIVE PROGRAMMING SEGMENT TREES TEMPLATE */
 
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// Sum Segment Tree
struct sum_seg_tree {

    int size = 1;
    vector<ll> tree;

    void construct(vector<int> &arr, int n)
    {
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<ll>(2 * size, 0LL);

        construct(arr, 0, 0, size, n);
    }

    void construct(vector<int> &arr, int node, int lx, int rx, int n)
    {
        if(rx - lx == 1)
        {
            if(lx < n)
            {
                tree[node] = arr[lx];
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;

        construct(arr, 2 * node + 1, lx, mid, n);
        construct(arr, 2 * node + 2, mid, rx, n);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int pos, int val)
    {
        update(pos, val, 0, 0, size);
    }

    void update(int pos, int val, int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            tree[node] = val;
            return;
        }

        int mid = lx + (rx - lx) / 2;

        if(pos < mid)
        {
            update(pos, val, 2 * node + 1, lx, mid);
        }
        else {
            update(pos, val, 2 * node + 2, mid, rx);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll get_sum(int l, int r)
    {
        return get_sum(l, r, 0, 0, size);
    }

    ll get_sum(int l, int r, int node, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[node];
        }

        if(lx >= r || l >= rx)
        {
            return 0;
        }

        int mid = lx + (rx - lx) / 2;

        ll sum_left = get_sum(l, r, 2 * node + 1, lx, mid);
        ll sum_right = get_sum(l, r, 2 * node + 2, mid, rx);

        return sum_left + sum_right;
    }
};

// Min Segment tree
struct min_seg_tree {

    int size = 1;
    vector<ll> tree;

    void construct(vector<int> &arr, int n)
    {
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<ll>(2 * size, LLONG_MAX);

        construct(arr, 0, 0, size, n);
    }

    void construct(vector<int> &arr, int node, int lx, int rx, int n)
    {
        if(rx - lx == 1)
        {
            if(lx < n)
            {
                tree[node] = arr[lx];
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;

        construct(arr, 2 * node + 1, lx, mid, n);
        construct(arr, 2 * node + 2, mid, rx, n);

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int pos, int val)
    {
        update(pos, val, 0, 0, size);
    }

    void update(int pos, int val, int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            tree[node] = val;
            return;
        }

        int mid = lx + (rx - lx) / 2;

        if(pos < mid)
        {
            update(pos, val, 2 * node + 1, lx, mid);
        }
        else {
            update(pos, val, 2 * node + 2, mid, rx);
        }

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    ll get_min(int l, int r)
    {
        return get_min(l, r, 0, 0, size);
    }

    ll get_min(int l, int r, int node, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[node];
        }

        if(lx >= r || l >= rx)
        {
            return LLONG_MAX;
        }

        int mid = lx + (rx - lx) / 2;

        ll min_left = get_min(l, r, 2 * node + 1, lx, mid);
        ll min_right = get_min(l, r, 2 * node + 2, mid, rx);

        return min(min_left, min_right);
    }
};

// Max Segment tree
struct max_seg_tree {

    int size = 1;
    vector<ll> tree;

    void construct(vector<int> &arr, int n)
    {
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<ll>(2 * size, LLONG_MIN);

        construct(arr, 0, 0, size, n);
    }

    void construct(vector<int> &arr, int node, int lx, int rx, int n)
    {
        if(rx - lx == 1)
        {
            if(lx < n)
            {
                tree[node] = arr[lx];
            }
            return;
        }

        int mid = lx + (rx - lx) / 2;

        construct(arr, 2 * node + 1, lx, mid, n);
        construct(arr, 2 * node + 2, mid, rx, n);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int pos, int val)
    {
        update(pos, val, 0, 0, size);
    }

    void update(int pos, int val, int node, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            tree[node] = val;
            return;
        }

        int mid = lx + (rx - lx) / 2;

        if(pos < mid)
        {
            update(pos, val, 2 * node + 1, lx, mid);
        }
        else {
            update(pos, val, 2 * node + 2, mid, rx);
        }

        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    ll get_max(int l, int r)
    {
        return get_max(l, r, 0, 0, size);
    }

    ll get_max(int l, int r, int node, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[node];
        }

        if(lx >= r || l >= rx)
        {
            return LLONG_MIN;
        }

        int mid = lx + (rx - lx) / 2;

        ll max_left = get_max(l, r, 2 * node + 1, lx, mid);
        ll max_right = get_max(l, r, 2 * node + 2, mid, rx);

        return max(max_left, max_right);
    }
};

// min_count segment tree
struct node {
    int val;
    int count;
};

struct min_count_seg_tree {

    int size;
    vector<node> tree;

    void construct(vector<int> &a, int n)
    {
        size = 1;
        while(size < n)
        {
            size *= 2;
        }

        tree = vector<node>(2 * size, {INT_MAX, 1});

        construct(a, n, 0, 0, size);
    }

    void merge_children(int x)
    {
        int min1 = tree[2 * x + 1].val;
        int min2 = tree[2 * x + 2].val;
        int count1 = tree[2 * x + 1].count;
        int count2 = tree[2 * x + 2].count;

        if(min1 == min2)
        {
            tree[x].val = min1;
            tree[x].count = count1 + count2;
        }

        if(min1 < min2)
        {
            tree[x].val = min1;
            tree[x].count = count1;
        }

        if(min2 < min1)
        {
            tree[x].val = min2;
            tree[x].count = count2;
        }
    }

    void construct(vector<int> &a, int n, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < n)
            {
                tree[x].val = a[lx];
                tree[x].count = 1;
            }
            return;
        }

        int m = lx + (rx - lx) / 2;

        construct(a, n, 2 * x + 1, lx, m);
        construct(a, n, 2 * x + 2, m, rx);

        merge_children(x);
    }

    void update(int i, int v)
    {
        update(i, v, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            tree[x].val = v;
            tree[x].count = 1;
            return;
        }

        int mid = lx + (rx - lx) / 2;

        if(i < mid)
        {
            update(i, v, 2 * x + 1, lx, mid);
        }
        else {
            update(i, v, 2 * x + 2, mid, rx);
        }

        merge_children(x);
    }

    node get_min_count(int l, int r)
    {
        return get_min_count(l, r, 0, 0, size);
    }

    node get_min_count(int l, int r, int x, int lx, int rx)
    {
        if(l <= lx && rx <= r)
        {
            return tree[x];
        }

        if(l >= rx || lx >= r)
        {
            return {INT_MAX, 1}; 
        }

        int mid = lx + (rx - lx) / 2;

        node node1 = get_min_count(l, r, 2 * x + 1, lx, mid);
        node node2 = get_min_count(l, r, 2 * x + 2, mid, rx);

        if(node1.val > node2.val)
        {
            return node2;
        }

        if(node1.val < node2.val)
        {
            return node1;
        }

        return {node1.val, node1.count + node2.count};
        
    }
};

int main()
{
    return 0;
}

