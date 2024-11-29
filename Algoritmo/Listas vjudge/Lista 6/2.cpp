#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.second > b.second;
    }
};  

class Grafo {
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
    }

    void setEdge(int u, int v, int wt){
        adjlist[u].push_back({wt,v});
        adjlist[v].push_back({wt,u});
        numEdge++;
    }

    void setMark (int v, int valor){
        Mark[v] = valor;
    }

    bool getMark (int v){
        return Mark[v] == 1;
    }

    int Prim (vector<int>& Distance, vector<int>& V){
        for (int i = 0 ; i < size ; i++){
            Distance[i] = INT_MAX;
            V[i] = -1;
            setMark(i,0);
        }

        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,Compare> heap;
        heap.push({{0,0},0});
        Distance[0] = 0;
        int maioredge = 0;

        while (!heap.empty()){

            int p = heap.top().first.first;
            int v = heap.top().first.second;
            heap.pop();

            if (v == -1){
                return -1;
            }

            if (getMark(v)){
                continue;
            }

            setMark(v,1);
            V[v] = p;

            maioredge = max(maioredge,Distance[v]);

            for (auto edge : adjlist[v]){
                int w = edge.second;
                int weight = edge.first;

                if (!getMark(w) && Distance[w] > weight){
                    Distance[w] = weight;
                    heap.push({{v,w}, Distance[w]});
                }
            }
        }
        for (int i = 0; i < size ; i++){
            if(!getMark(i)){
                return -1;
            }
        }
        return maioredge;
    }
};

int main(){
    bool continuar = true;

    while (continuar){
        int n,m;
        cin >> n >> m;

        if (n == 0 && m == 0){
            break;
        }

        Grafo g(n);

        for (int i = 0 ; i < m ; i++){  

            int a,b,w;
            cin >> a >> b >> w;

            g.setEdge(a,b,w);
            
        }

        vector<int> distancias(n);
        vector<int> vertices(n);
        int resultado = g.Prim(distancias,vertices);

        if (resultado == -1){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << resultado << endl;
        }
    }

    return 0;
}