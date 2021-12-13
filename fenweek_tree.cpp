#include <bits/stdc++.h>
#include <iostream>
#define INF 1000000007
#define ll long long int
using namespace std;

class fenweek_tree
{
private:
    ll size;
    vector<ll> tree;
    void update(ll i, ll x)
    {
        if (i <= size + 1)
        {
            tree[i] += x;
            update(i + (i & (-i)), x);
        }
    }
    ll sum(ll n)
    {
        if (n == 0)
        {
            return 0;
        }
        return tree[n] + sum(n - (n & (-n)));
    }

public:
    fenweek_tree(ll n, vector<ll> &vec)
    {
        tree.resize(n + 1, 0);

        size = n;
        for (ll i = 1; i <= n; i++)
        {
            update(i, vec[i - 1]);
        }
    }
    ll prifix_sum(ll n)
    {
        return sum(n + 1);
    }
    ll add(ll i, ll val)
    {
        update(i + 1, val);
    }
};

ll main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        cout << vec[i] << " ";
    }

    class fenweek_tree A(n, vec);

    cout << A.prifix_sum(4);

    return 0;
}