#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct State {
    int len, link;
    std::map<char, int> next;
    long long freq;
    int pos; // End position of the first occurrence of the longest string in this state
};

std::vector<State> st;
int sz, last;

void sam_init() {
    st.clear();
    st.resize(2 * 100005);
    st[0].len = 0;
    st[0].link = -1;
    st[0].freq = 0;
    st[0].pos = -1;
    sz = 1;
    last = 0;
}

void sam_extend(char c, int current_pos) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].freq = 1;
    st[cur].pos = current_pos;

    int p = last;
    while (p != -1 && st[p].next.find(c) == st[p].next.end()) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[q].len == st[p].len + 1) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].freq = 0; // Cloned states don't correspond to a new end position
            st[clone].pos = st[q].pos; // Inherit pos

            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = clone;
            st[cur].link = clone;
        }
    }
    last = cur;
}

void solve() {
    int l;
    std::cin >> l;
    std::string s;
    std::cin >> s;

    sam_init();
    for (int i = 0; i < s.length(); ++i) {
        sam_extend(s[i], i);
    }

    std::vector<std::pair<int, int>> states_by_len(sz);
    for (int i = 0; i < sz; ++i) {
        states_by_len[i] = {st[i].len, i};
    }
    std::sort(states_by_len.rbegin(), states_by_len.rend());

    for (const auto& p : states_by_len) {
        int u = p.second;
        if (st[u].link != -1) {
            st[st[u].link].freq += st[u].freq;
        }
    }

    long long max_freq = 0;
    for (int i = 1; i < sz; ++i) {
        if (st[i].len >= l) {
            if (st[i].freq > max_freq) {
                max_freq = st[i].freq;
            }
        }
    }

    if (max_freq == 0) { // Should only happen if no substring has length >= L
        // But problem statement says L <= |S|, so at least freq=1 substrings exist.
        // If all such substrings have freq 1, this finds the first one of length L.
        max_freq = 1;
    }

    int max_len = 0;
    for (int i = 1; i < sz; ++i) {
        if (st[i].freq == max_freq && st[i].len >= l) {
             if (st[i].len > max_len) {
                max_len = st[i].len;
            }
        }
    }

    int best_start_pos = s.length();
    for (int i = 1; i < sz; ++i) {
        // Any state `st` with len(st) >= max_len and freq(st) == max_freq
        // contains the substring of length max_len with that frequency.
        // Its first appearance ends at st.pos.
        if (st[i].freq == max_freq && st[i].len >= max_len) {
            int start_pos = st[i].pos - max_len + 1;
            if (start_pos < best_start_pos) {
                best_start_pos = start_pos;
            }
        }
    }
    
    std::cout << s.substr(best_start_pos, max_len) << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
