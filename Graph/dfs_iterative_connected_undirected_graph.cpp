class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>res;
        stack<int> st;
        int V = adj.size();
        vector<bool> visited(V, false);
        int s = 0;
        st.push(s);
        
        while(st.empty() == false){
            int current = st.top();
            st.pop();
            
            if(!visited[current]){
                res.push_back(current);
                visited[current] = true;
                for(auto it = adj[current].rbegin(); it != adj[current].rend(); it++) {
                    if(!visited[*it])
                        st.push(*it);
                }
            }
        }
        return res;
    }
};
