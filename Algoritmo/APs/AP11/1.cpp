#include <bits/stdc++.h>
#define INFINITO 10000000
using namespace std;

class Grafo{
private:
    struct Compare {
        bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            return a.second > b.second;
        }
    };  

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
        if (wt==0) return;

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

    int next (int u, int v){  
        for (int i = 0 ; i < adjlist[u].size() ; i++){
            if (adjlist[u][i].second == v){
                ++i;
                if(i < adjlist[u].size()){
                    return adjlist[u][i].second;
                }
                break;
            }
        }
        return -1;
    }

    int weight(int u, int v){
        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                return edge.first;
            }
        }
        return INFINITO;
    }

    void Dijkstra (int source, vector<int>& Distance){
        vector<int> Parent(size,-1);

        for (int i = 0 ; i < size ; i++){
            Distance[i] = INFINITO;
            setMark(i,0);
        }

        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,Compare> heap;
        heap.emplace(make_pair(source,source),0);
        Distance[source] = 0;

        while (!heap.empty()){

            int p = heap.top().first.first;
            int v = heap.top().first.second;
            heap.pop();

            if (getMark(v)){
                continue;
            }

            setMark(v,1);
            Parent[v] = p;
            int w = first(v);

            while (w != -1){
                if (!getMark(w) && Distance[w] > Distance[v] + weight(v,w)){
                    Distance[w] = Distance[v] + weight(v,w);
                    heap.emplace(make_pair(v,w), Distance[w]);
                }
                w = next(v,w);
            }
        }
    }
};

int main(){

    int n, m, v;
    cin >> n >> m >> v;

    Grafo g(n);

    for (int i = 0 ; i < m ; i++){
        int a, b, w;
        cin >> a >> b >> w;

        g.setEdge(a,b,w);
    }

    vector<int> distancias(n);
    g.Dijkstra(v,distancias);

    for(int i = 0 ; i < n ; i++){
        if (distancias[i] == INFINITO) {
            cout << -1 << " ";
        } 
        else{
            cout << distancias[i] << " ";
        } 
    }

    return 0;
}