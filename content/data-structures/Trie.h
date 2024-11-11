/**
 * Author: Vuong Nguyen
 * Date: 2016-03-22
 * License: CC0
 * Description: A data structure for dealing with prefix of string
 * Time: O(|s|) for each method
 * Memory: O(|s| \times k)
 */
struct Trie{
    struct Node{
        Node* child[26];
        int exist, cnt;
        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            exist = cnt = 0;
        }
    };
    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };
    void add_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == nullptr) p->child[c] = new Node();

            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }
    bool delete_string_recursive(Node* p, string& s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(p->child[c], s, i + 1);
            if (isChildDeleted) p->child[c] = nullptr;
        }
        else p->exist--;
        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p); 
                return true;
            }
        }
        return false;
    }
    void delete_string(string s) {
        if (find_string(s) == false) return;
        delete_string_recursive(root, s, 0);
    }
    bool find_string(string s) {
        Node* p = root;
        for (auto f : s) {
            int c = f - 'a';
            if (p->child[c] == nullptr) return false;
            p = p->child[c];
        }
        return (p->exist != 0);
    }
};
