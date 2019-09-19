#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include<iostream>
using namespace std;
//using namespace stdext;


typedef struct Song {
	int index;
	int play;
	Song() {}
	Song(int i, int p) {
		index = i;
		play = p;
	}
}Song;
vector<string> genre_list;

class Genre {

public:
	struct cmp {
		bool operator()(const Song &t, const Song &u) {
			if (t.play == u.play)
				return t.index < u.index;
			return t.play > u.play;
		}
	};
	priority_queue<Song,vector<Song>,cmp> play;
	int total_play = 0;
	Genre() {}
	void push_song(Song s, vector<int> plays) {
		play.push(s);
		this->total_play += s.play;
	}

};

map<string, Genre> h_map;


bool cmp2(string a, string b) {
	return h_map[a].total_play > h_map[b].total_play;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	for (int i = 0; i < genres.size(); i++) {
		Genre temp = h_map[genres[i]];
		temp.push_song(Song(i, plays[i]), plays);
		//play_map[i] = plays[i];
		h_map.erase(h_map.find(genres[i]));
		h_map[genres[i]] = temp;
	}

	map<string, Genre>::iterator itr;
	for (itr = h_map.begin(); itr != h_map.end(); itr++) {
		genre_list.push_back(itr->first);
	}
	sort(genre_list.begin(), genre_list.end(), cmp2);
	for (int i = 0; i < genre_list.size(); i++) {
		cout << genre_list[i] << endl;
		cout << h_map[genre_list[i]].play.size() << endl;
		answer.push_back(h_map[genre_list[i]].play.top().index);
		h_map[genre_list[i]].play.pop();
		answer.push_back(h_map[genre_list[i]].play.top().index);
		h_map[genre_list[i]].play.pop();
	}


	return answer;
}

int main() {
	vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> p = { 500, 600, 150, 800, 2500 };
	for (int i = 0; i < g.size(); i++) {
		cout << solution(g,p)[i] << endl;
	}
}