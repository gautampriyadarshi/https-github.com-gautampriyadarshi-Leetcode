/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return {};
        
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<Node*> level;
            for(int i = 0; i < size; i++)
            {
                Node* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                level.push_back(node);
            }
            
            if(level.size() == 1)
                level[0]->next = NULL;
            
            Node* nd = level[0];
            for(int i = 1; i < level.size(); i++)
            {
                nd->next = level[i];
                nd = nd->next;
            }
            nd->next = NULL;
            level.clear();
        }
        return root;
    }
};