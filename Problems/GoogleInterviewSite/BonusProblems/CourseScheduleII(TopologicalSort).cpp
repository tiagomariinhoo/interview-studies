class Solution {
public:
    // Using topological sort idea
    /**
        Takes linear auxiliary space and O(N + M) time complexity

        Basically the idea here is push the nodes into a queue when they have degree == 0
        We can define degree as the number of nodes linked directly to a node
        So, if A -> B, then degree[B] == 1 and degree[A] == 0

        We start with some Nodes in the queue, since we need our start nodes with Degree == 0 
        And we can start from somewhere 

        After that, we just need to run a normal BFS and everytime that we find a new node in the bfs
        we decrease its degree by 1, if the degree becomes 0, we just need to push this node into a queue
        since we don't have any dependencies for that node anymore. 

        To store the answer, we just need to count the number of nodes that had degree == 0 and check if
        its == num Courses
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int degree[numCourses];
        int vis[numCourses];
        vector<int> vec[numCourses];
        memset(degree, 0, sizeof degree);
        memset(vis, 0, sizeof vis);
        queue<int> q;
        int count = 0;

        for (auto i : prerequisites) {
            degree[i[1]]++;
            vec[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) q.push(i), count++;
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            for (auto i : vec[u]) {
                degree[i]--;
                if (!degree[i]) q.push(i), count++;
            }
        }

        return (count == numCourses);
    }
};