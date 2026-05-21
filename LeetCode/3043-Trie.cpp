// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/

class Trie
{
public:
    struct Node
    {
        Node* next[10]={nullptr};
    };

    Trie()
    {
        root=new Node();
    }

    void insert(string str)
    {
        auto curr=root;
        for(char& c:str)
        {
            if(!curr->next[c-'0'])
                curr->next[c-'0']=new Node();
            curr=curr->next[c-'0'];
        }
    }

    int get_prefix_len(string str)
    {
        auto curr=root;
        int len=0;
        for(char& c:str)
        {
            if(!curr->next[c-'0'])
                return len;
            curr=curr->next[c-'0'];
            len++;
        }
        return len;
    }
private:
    Node* root;
};

class Solution 
{
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        Trie trie;
        for(int& val:arr1)
            trie.insert(to_string(val));
        
        int res=0;
        for(int& val:arr2)
        {
            int prefix=trie.get_prefix_len(to_string(val));
            res=max(res,prefix);
        }
        return res;
    }
};