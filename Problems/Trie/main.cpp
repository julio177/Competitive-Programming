#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node {
    public:
    	unordered_map<char, Node*> map;
   		int count;
   		Node();
};

Node::Node() {
	count = 0;
}

class Trie {
    Node* root;
    public: 
        void add(string s);
        int find(string s);
        Trie();
};

Trie::Trie() {
	root = new Node();
}

int Trie::find(string s) {
    Node *aux = root;
    for(int i = 0; i < s.length(); ++i) {
        auto it = aux->map.find(s[i]);
        if(it == aux->map.end()) {
            return 0;
        }
        aux = it->second;
    }
    return aux->count;
}

void Trie::add(string s) {
    Node* aux = root;
    for(int i = 0; i < s.length(); i++) {
        auto it = aux->map.find(s[i]);
        if(it != aux->map.end()) {
            it->second->count++;
            aux = it->second;
        }
        else {
            Node* nuevo = new Node;
            nuevo->count = 1;
            aux->map.insert({s[i], nuevo});
            aux = nuevo;
        }
    }
}

int main(){
    int n, aux;
    Trie trie;
    vector<int> res;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add") {
            trie.add(contact);
        }
        if(op == "find") {
        	aux = trie.find(contact);
        	res.push_back(aux);
        }
    }
    for(int i = 0; i < res.size(); ++i) {
    	cout << res[i] << endl;
    }
    return 0;
}
