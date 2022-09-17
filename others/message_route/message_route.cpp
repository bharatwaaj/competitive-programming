/*
 * @Author Bharatwaaj Shankaranarayanan
 * @Description Message Route 
 * @Date 17 Sept, 2022
 * @Category Graph
 */

#include<bits/stdc++.h>
using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define sc             set <char>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mci            map <char, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b) {
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// Graph Class
class Graph{

	int V;
	list<int> *l;

	public:

		Graph(int v) {
			V = v;
			l = new list<int>[V];
		}

		void addEdge(int i, int j, bool undirected = true){
			l[i].push_back(j);
			if(undirected){
				l[j].push_back(i);
			}
		}

		int bfs(int source, int destination){
			queue<int> q;
			bool *visited = new bool[V]{0};
			vector<int>dist(V+1,1e9);
		
			q.push(source);
			visited[source] = true;
			dist[source] = 1;

			while(!q.empty()){

				int f = q.front();
				q.pop();

				for(auto nbr : l[f]){
					if(!visited[nbr]){
						q.push(nbr);
						visited[nbr] = true;
					}
					if(dist[nbr]>dist[f]+1){
						dist[nbr]=dist[f]+1;
					}
				}
			}

			if(dist[destination]==(int)1e9)
			{
	    		return -1;
			}
			return dist[destination];
		}

		void printAdjList(){

			for(int i=0; i<V; i++){
				cout<<i<<" -> ";
				for(auto node:l[i]){
					cout<<node<<",";
				}
				cout<<endl;
			}

		}
};


// Main method 
int messageRoute(int n, vector<vector<int>>edges){

	// Create a graph of size n+1
    Graph G(n+1);

    // Loop through all the elements in the graph
    for(int i=0; i<edges.size(); i++){
    	G.addEdge(edges[i][0], edges[i][1]);
    }

    // Return the bfs response as BFS guarantees the shortest path to any node from root
    return G.bfs(1, n);
}

void solve() {

	// N is Bob's computer
	int N;
	cin>>N;
	
	// K is the number of edges
	int K;
	cin>>K;

	// Adjacency list of size (K,2)
	vector<vector<int>>edges(K, vector<int>(2));

	// Taking K pairs of adjacency lists
	for(int i=0; i<K; i++){
		cin>>edges[i][0]>>edges[i][1];
	}

	// Return the response for messageRoute method
	cout<<messageRoute(N, edges)<<endl;
}

int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	clock_t z = clock();

	int t = 1;
	cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;

}