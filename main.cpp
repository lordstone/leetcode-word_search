class trie {
public:
    // Initialize your data structure here.
    trie() {
        count = 0;
        for(int i = 0; i < 26; i ++)
            children[i] = NULL;
    }
    trie *children[26];
    int count;
};


class Solution {
public:
/*
    struct trie{
        trie * children[26];
        int count; // number of words reside in (1 for one uncovered word, 0 for )
        char myChar;
        //trie(char chr) :  count(0) , myChar(chr) {}
        
    };
    */
    void DFS(vector<vector<char>>& board, trie * cur, vector<string>& res, string out, int i, int j){

        if(cur == NULL) {
            return;
        }
        
        if(cur -> count >= 1){// if reaches to a word in 
            res.push_back(out); 
            cur -> count --; // switched to already covered mode
        }
        /*
        if(cur -> count == 0) {
            //res.push_back("jiji");
            return; // if reached to the end, terminate this path search
        }
        */
        // up 
        
        if(i > 0){//if up has sth
            if(board[i-1][j] != '!'){//if not yet go over
                if(cur -> children[board[i-1][j] - 'a'] != NULL){//if up matches
                    trie * tmpcur = cur;
                    tmpcur = tmpcur -> children[board[i-1][j] - 'a']; // move cur
                    out += board[i-1][j]; // add the new found char
                    char tmpStore = board[i-1][j]; board[i-1][j] = '!';
                    DFS(board, tmpcur, res, out, i-1, j);
                    board[i-1][j] = tmpStore;
                    out.pop_back();
                }
            }
        }
        
        // Down
        if(i < board.size() - 1){//if up has sth
            if(board[i+1][j] != '!'){//if not yet go over
                if(cur -> children[board[i+1][j] - 'a'] != NULL){//if up matches
                    trie * tmpcur = cur;
                    tmpcur = tmpcur -> children[board[i+1][j] - 'a']; // move cur
                    out += board[i+1][j]; // add the new found char
                    char tmpStore = board[i+1][j]; board[i+1][j] = '!';
                    DFS(board, tmpcur, res, out, i+1, j);
                    board[i+1][j] = tmpStore;
                    out.pop_back();
                }
            }
        }
        
        //left
        if(j > 0){//if up has sth
            if(board[i][j - 1] != '!'){//if not yet go over
                if(cur -> children[board[i][j-1] - 'a'] != NULL){//if up matches
                    trie * tmpcur = cur;
                    tmpcur = tmpcur -> children[board[i][j-1] - 'a']; // move cur
                    out += board[i][j-1]; // add the new found char
                    char tmpStore = board[i][j-1]; board[i][j-1] = '!';
                    DFS(board, tmpcur, res, out, i, j-1);
                    board[i][j-1] = tmpStore;
                    out.pop_back();
                }
            }
        }
        
        //right
        if(j < board[0].size() - 1){//if up has sth
            if(board[i][j + 1] != '!'){//if not yet go over
                if(cur -> children[board[i][j + 1] - 'a'] != NULL){//if up matches
                    trie * tmpcur = cur;
                    tmpcur = tmpcur -> children[board[i][j + 1] - 'a']; // move cur
                    out += board[i][j + 1]; // add the new found char
                    char tmpStore = board[i][j + 1]; board[i][j + 1] = '!';
                    DFS(board, tmpcur, res, out, i, j + 1);
                    board[i][j + 1] = tmpStore;
                    out.pop_back();
                }
            }
        }
        
    }//end of DFS
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.size() == 0) return res;
        if(words[0].size() == 0) return res;
        //trie anchor ('a'); //  anchor
        trie * anchor = new trie ();
        trie * cur;// pointing to anchor
        
        for(int i = 0; i < words.size(); i ++){
            if(words[i].length() == 0) continue;
            cur = anchor;
            for(int j = 0; j < words[i].length(); j ++){
                cur -> children[(int)(words[i][j] - 'a')] = new trie(); // forward cur
                cur = cur -> children[(int)(words[i][j] - 'a')];
            }//end for j
            //cur = new trie();
            cur -> count ++;// increment the val count for a word
            //return res;
        }//end for i
        
        //end of init trie
        int m = board.size(); 
        int n = board[0].size();
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                //cur = anchor;
                if(anchor -> children[(int)(board[i][j] - 'a')] != NULL){
                    //res.push_back(to_string(anchor -> children[(int)(board[i][j] - 'a')] -> count));
                    char tmp = board[i][j];
                    board[i][j] = '!';
                    trie * mycur = anchor -> children[(int)(tmp - 'a')];  // cur pointing to anchor;
                    string out = ""; 
                    out += tmp; // add the tmp to out string
                    DFS(board, mycur, res, out, i, j); // do DFS on the one that is possible
                    board[i][j] = tmp; // return back the val
                }//end if
            }//end for j
        }//end for i
        return res;
    }//end of main
};
