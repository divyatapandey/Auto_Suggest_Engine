// User function template for C++
#include<iostream>
#include<vector>
using namespace std;
class Trie {
    Trie* root[26];
    bool flag; //for telling if any word ens here
  public:

    Trie() {
        // implement Trie
        for(int i=0;i<26;i++){
            this->root[i]=NULL;
        }
        this->flag=false;
    }

    void insert(string &word) {
        // insert word into Trie
        Trie* ptr=this;
        for(auto ch:word){
            int idx=ch-'a';
            if(ptr->root[idx]!=NULL){
                ptr=ptr->root[idx];
            }
            else{
            Trie* node=new Trie;
            ptr->root[idx]=node;
            ptr=node;
            }
        }
        ptr->flag=true;
        
    }
 void getWordsStartingFrom(string word,Trie* p,vector<string>&ans){
    if(p->flag==true){
        ans.push_back(word);
    }
    
    for(int i=0;i<26;i++){
        if(p->root[i]!=NULL){
            char c='a'+i;
            word.push_back(c);
            getWordsStartingFrom(word,p->root[i],ans);
            word.pop_back();
        }
    }
}

vector<string> getSuggestions(string& prefix) {
        Trie* ptr = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (ptr->root[idx]==NULL)
                return {}; // no suggestions
            ptr = ptr->root[idx];
        }

        vector<string> suggestions;
        getWordsStartingFrom(prefix,ptr, suggestions); // gather all words from here
        return suggestions;
    }
    
    ~Trie() {
    for (int i = 0; i < 26; i++) {
        if (root[i] != NULL) {
            delete root[i];
            root[i] = NULL;
        }
    }
}

  
};

int main() {
    Trie* trie = new Trie();

    // Insert a diverse list of words into the Trie
    vector<string> words = {
        "apple", "app", "application", "apt", "banana",
        "bat", "batch", "bath", "batman", "ball", "cat", "cap", "cape"
    };

    for (const string& word : words) {
        trie->insert(const_cast<string&>(word));  // Insert each word
    }

    // Test different prefixes and display suggestions
    vector<string> prefixes = {"app", "ba", "bat", "ca", "z"};

    for (const string& prefix : prefixes) {
        vector<string> results = trie->getSuggestions(const_cast<string&>(prefix));
        cout << "Suggestions for prefix \"" << prefix << "\":" << endl;

        if (results.empty()) {
            cout << "  No suggestions found." << endl;
        } else {
            for (const string& suggestion : results) {
                cout << "  " << suggestion << endl;
            }
        }
        cout << endl;
    }

    delete trie;  // Clean up
    return 0;
}
