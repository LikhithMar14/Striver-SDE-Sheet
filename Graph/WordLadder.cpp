#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //SIMPLE BFS FOR SHORTEST AND OPTMAL
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0; 

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, l] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (temp == endWord) return l + 1;

                    if (st.find(temp) != st.end()) {
                        q.push({temp, l + 1});
                        st.erase(temp); 
                    }
                }
            }
        }

        return 0; 
    }
};
