#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    int dp_value; // Length of the longest chain ending at the word represented by this node

    TrieNode() {
        dp_value = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i])
                delete children[i];
        }
    }
};


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    TrieNode* root = new TrieNode();
    int overall_max_len = 0;

    for (const std::string& word : words) {
        TrieNode* current_node = root;
        int max_prefix_dp = 0;
        
        // Find the dp value of the longest proper prefix of the current word
        // which is also in the dictionary.
        for (size_t i = 0; i < word.length() - 1; ++i) {
             int index = word[i] - 'a';
             if (!current_node->children[index]) {
                 // This should not happen if prefixes are guaranteed to exist,
                 // but as a safeguard.
                 current_node = nullptr;
                 break;
             }
             current_node = current_node->children[index];
             max_prefix_dp = std::max(max_prefix_dp, current_node->dp_value);
        }
        
        // Now, find/create the node for the full word
        current_node = root;
         for (char ch : word) {
            int index = ch - 'a';
            if (!current_node->children[index]) {
                current_node->children[index] = new TrieNode();
            }
            current_node = current_node->children[index];
        }

        int current_dp = 1;
        // The above loop to find max_prefix_dp is not quite right.
        // Let's re-think. The DP should be on the words themselves,
        // and the Trie helps us find the right predecessor.
        // A simple map might be easier to reason about and implement.
    }
    
    delete root; // Clean up memory

    // Let's use a simpler map-based DP, which is easier to get right.
    std::map<std::string, int> dp;
    int max_len = 0;

    for (const std::string& word : words) {
        int current_max = 0;
        // A word can only be a prefix of another if it's shorter.
        // Since words are sorted by length, we only need to check its own prefixes.
        for (int i = 1; i < word.length(); ++i) {
            std::string prefix = word.substr(0, i);
            if (dp.count(prefix)) {
                current_max = std::max(current_max, dp[prefix]);
            }
        }
        dp[word] = current_max + 1;
        max_len = std::max(max_len, dp[word]);
    }

    if (n > 0 && max_len == 0) {
        max_len = 1;
    }

    std::cout << max_len << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
