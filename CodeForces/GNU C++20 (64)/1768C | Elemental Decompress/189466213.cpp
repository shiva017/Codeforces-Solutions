#include <iostream>
#include <vector>
#include <utility>
#include<bits/stdc++.h>
void solve() {
int n;
std::cin >> n;
std::vector<int> a(n);
for (int i = 0; i < n; i++) {
std::cin >> a[i];
a[i]--;
}
std::vector<int> cnt(n);
for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
}
 
for (int i = 0; i < n; i++) {
    if (cnt[i] > 2) {
        std::cout << "NO\n";
        return;
    }
}
 
std::vector<int> cand;
std::vector<std::vector<int>> adj(n);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 - cnt[i]; j++) {
        cand.push_back(i);
    }
    for (int j = 0; j < cnt[i]; j++) {
        if (cand.empty()) {
            std::cout << "NO\n";
            return;
        }
        adj[i].push_back(cand.back());
        adj[cand.back()].push_back(i);
        cand.pop_back();
    }
}
 
std::vector<std::vector<std::pair<int, int>>> pairs(n);
std::vector<int> vis(n);
for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
 
    int x = i, y = adj[x][0];
    while (!vis[x]) {
        vis[x] = 1;
        pairs[std::max(x, y)].emplace_back(x, y);
        std::tie(x, y) = std::pair(y, x ^ adj[y][0] ^ adj[y][1]);
    }
}
 
std::cout << "YES\n";
 
std::vector<int> p(n), q(n);
for (int i = 0; i < n; i++) {
    std::tie(p[i], q[i]) = pairs[a[i]].back();
    pairs[a[i]].pop_back();
}
for (int i = 0; i < n; i++) {
    std::cout << p[i] + 1 << " \n"[i == n - 1];
}
for (int i = 0; i < n; i++) {
    std::cout << q[i] + 1 << " \n"[i == n - 1];
}
}
 
signed main() {
std::ios::sync_with_stdio(false);
std::cin.tie(nullptr);
int T;
std::cin >> T;
while (T -- ) {
solve();
}
return 0;
}