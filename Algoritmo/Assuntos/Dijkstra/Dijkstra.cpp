#include <bits/stdc++.h>
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
    }

    void setEdge(int u, int v, int wt){
        //if (wt==0) return;

        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                edge.first = wt;
                return; 
            }
        }
        adjlist[u].push_back({wt,v});
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
                    heap.push({{v,w}, Distance[w]});
                }
                w = next(v,w_chave);
                w_chave++;
            }
        }
    }
};

int main(){

    Grafo grafo(5);

    grafo.setEdge(0, 1, 10);
    grafo.setEdge(0, 2, 3);
    grafo.setEdge(0, 3, 20);
    grafo.setEdge(1, 3, 5);
    grafo.setEdge(2, 1, 2);
    grafo.setEdge(2, 4, 15);
    grafo.setEdge(3, 4, 11);

    vector<int> distancias(5);
    grafo.Dijkstra(0, distancias);
    
    for(int i = 0 ; i < 5 ; i++){
        if (distancias[i] == INT_MAX){
            cout << "INFINITO ";
        } 
        else{
            cout << distancias[i] << " ";
        } 
    }

    return 0;
}