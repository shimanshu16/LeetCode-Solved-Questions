 class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> wordQueue;
        wordQueue.push(beginWord);

        int distance = 1;

        while (!wordQueue.empty()) {
            int levelSize = wordQueue.size();

            for (int i = 0; i < levelSize; ++i) {
                string currentWord = wordQueue.front();
                wordQueue.pop();
                if (currentWord == endWord) {
                    return distance;
                }

                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue; 

                        currentWord[j] = c;

                        if (wordSet.find(currentWord) != wordSet.end()) {
                            wordQueue.push(currentWord);
                            wordSet.erase(currentWord); 
                        }
                    }
                    currentWord[j] = originalChar;
                }
            }
            distance++;
        }
        return 0;
    }
};