const vector<int> new_node = vector<int>(26, -1);
class Trie
{
    public:
        vector<vector<int>> adj;
        vector<int> max_depth;
        vector<bool> str_terms;

        Trie()
        {
            adj.pb(new_node);
            str_terms.pb(false);
        }

        void add_str(string &s)
        {
            int idx = 0, no = 0;

            while (idx < s.size())
            {
                if (adj[no][s[idx] - 'a'] != -1) no = adj[no][s[idx] - 'a'];
                else
                {
                    adj[no][s[idx] - 'a'] = adj.size();
                    no = adj.size();
                    adj.pb(new_node);
                    str_terms.pb(false);
                }

                idx++;
            }

            str_terms[no] = true;
        }

        void process_depth()
        {
            max_depth = vector<int>(adj.size(), 0);
            vector<vector<int>> depth(adj.size(), new_node);

            for(int no = adj.size()-1; no >= 0; no--)
            {
                int mai = 0;
                for(int i = 0;i < 26; i++)
                {
                    if (adj[no][i] == -1) depth[no][i] = 0;
                    else depth[no][i] = 1 + max_depth[adj[no][i]]; 

                    mai = max(mai, depth[no][i]);
                }

                max_depth[no] = mai;
            }
        }
};
