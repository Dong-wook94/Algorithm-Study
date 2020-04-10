#include <cstdio>
#include <cstring>
int char_to_index(char c) {
	return c - '0';
}

struct Trie {

	bool is_terminal;
	Trie * next[10];

	//생성자
	Trie() : is_terminal(false) {
		memset(next, 0, sizeof(next));
	}

	//소멸자
	~Trie() {
		for (int i = 0; i < 10; ++i) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	bool insert(const char * key) {

		//끝이면
		if (*key == '\0') {
			is_terminal = true;
			return true;
		}
		else {
			if (is_terminal == true) return false; 

			int index = char_to_index(*key);

			if (next[index] == 0)
				next[index] = new Trie();

			// If next node is already exists and current's next is end of string then there is a prefix match
			else if (next[index] != 0 && *(key + 1) == '\0') {
				return false;
			}
			return next[index]->insert(key + 1);
		}
	}
};

int main() {

	int t;
	char phonNumber[11];
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		Trie * root = new Trie();

		bool ret = true;

		for (int i = 0; i < n; ++i) {
			scanf("%s", &phonNumber);

			if (ret == false) continue;

			ret = root->insert(phonNumber);

		}

		delete root;
		printf("%s\n", ret ? "YES" : "NO");
	}
	return 0;
}