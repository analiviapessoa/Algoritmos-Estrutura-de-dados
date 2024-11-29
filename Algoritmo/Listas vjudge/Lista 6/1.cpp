#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};  

class Grafo{
private:
    vector<vector<pair<int,int>>> adjlist;     
    int numEdge;     
    int* Mark;         
    int size;

public:
    Grafo (int n){
        adjlist.resize(n);
        numEdge = 0;
        Mark = new int[n];
        size = n;

        for (int i = 0 ; i < size ; i++){
            Mark[i] = 0;
        }

    }

    void setEdge(int u, int v, int wt){
        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                edge.first = wt;
                return; 
            }
        }
        adjlist[u].push_back({wt,v});

        for (auto& edge : adjlist[v]){
            if (edge.second == u){
                edge.first = wt;
                return; 
            }
        }
        adjlist[v].push_back({wt,u});
        numEdge++;
    }

    void setMark (int v, int valor){
        Mark[v] = valor;
    }

    bool getMark (int v){
        return Mark[v] == 1;
    }

    int first (int v){ 
        if (!adjlist[v].empty()){
            return adjlist[v].front().second;
        }
        return -1;
    }

   int next(int u, int v) {
        if (v + 1 < adjlist[u].size()) {
            return adjlist[u][v + 1].second;
        }
        return -1;
    }

    int weight(int u, int v){
        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                return edge.first;
            }
        }
        return INT_MAX;
    }

    void Dijkstra (int source, vector<int>& Distance){
        vector<int> Parent(size,-1);

        for (int i = 0 ; i < size ; i++){
            Distance[i] = INT_MAX;
            setMark(i,0);
        }

        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,Compare> heap;
        heap.push({{source, source}, 0});
        Distance[source] = 0;

        while (!heap.empty()){

            int p = heap.top().first.first;
            int v = heap.top().first.second;
            heap.pop();

            if (v == -1){
                return;
            }

            if (getMark(v)){
                continue;
            }

            setMark(v,1);
            Parent[v] = p;

            int w_chave = 0;
            int w = first(v);

            while (w != -1){
                if (!getMark(w) && Distance[w] > Distance[v] + weight(v,w)){
                    Distance[w] = Distance[v] + weight(v,w);
                    heap.push({{v, w}, Distance[w]});
                }
                w = next(v, w_chave);
                w_chave++;
            }
        }
    }
};

int main(){

    int N; 
    cin >> N;

    for (int i = 1 ; i <=  N ; i++){

        int n,m,S,T;
        cin >> n >> m >> S >> T;

        Grafo g(n);

        for (int j = 0 ; j < m ; j++){
            int a,b,w;
            cin >> a >> b >> w;
            
            g.setEdge(a,b,w);
        }

        vector<int> distancias(n);
        g.Dijkstra(S, distancias);

        cout << "Case #" << i << ": ";
        if (distancias[T] != INT_MAX) {
            cout << distancias[T] << endl;
        } 
        else {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}