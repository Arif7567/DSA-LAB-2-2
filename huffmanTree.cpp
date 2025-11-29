#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    class Node
    {
    public:
        int freq;
        char c;
        Node *left, *right;

        Node(int f, char name)
        {
            freq = f;
            c = name;
            left = right = NULL;
        }
    };

    class comp
    {
    public:
        bool operator()(Node *a, Node *b)
        {
            return a->freq > b->freq; // min-heap
        }
    };

    void preorder(Node *root, string &temp, vector<string> &ans)
    {
        if (!root)
            return;

        // leaf node
        if (!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back('0');
        preorder(root->left, temp, ans);
        temp.pop_back();

        temp.push_back('1');
        preorder(root->right, temp, ans);
        temp.pop_back();
    }

public:
    vector<string> huffmanCode(string s, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, comp> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(new Node(f[i], s[i]));
        }

        while (pq.size() > 1)
        {
            Node *first = pq.top();
            pq.pop();
            Node *second = pq.top();
            pq.pop();

            Node *root = new Node(first->freq + second->freq, '$');
            root->left = first;
            root->right = second;
            pq.push(root);
        }

        Node *root = pq.top();
        pq.pop();

        vector<string> ans;
        string temp;
        preorder(root, temp, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "abc";
    vector<int> freq = {2,3,4};
    int n = s.size();

    vector<string> codes = obj.huffmanCode(s, freq, n);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << ": " << codes[i] << "\n";
    }

    return 0;
}

