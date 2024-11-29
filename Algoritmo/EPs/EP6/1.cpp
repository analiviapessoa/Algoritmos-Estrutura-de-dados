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

    int first (int v){ 
        if (!adjlist.empty()){
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

    int weight(int u, int v){
        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                return edge.first;
            }
        }
        return INT_MAX;
    }

    void Prim (vector<int>& Distance, vector<int>& V){
        for (int i = 0 ; i < size ; i++){
            Distance[i] = INT_MAX;
            V[i] = -1;
            setMark(i,0);
        }

        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,Compare> heap;
        heap.push({{0,0},0});
        Distance[0] = 0;

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
            V[v] = p;

            int w_chave = 0;
            int w = first(v);

            while (w != -1){
                if (!getMark(w) && Distance[w] > weight(v,w)){
                    Distance[w] = weight(v,w);
                    heap.push({{v,w}, Distance[w]});
                }
                w = next(v,w_chave);
                w_chave++;
            }
        }
    }
};

int main(){

    int c,o,cont=0;    //nº de cidades, nº de obras, contador

    while(cin >> c >> o){

        if (c == 0 and o == 0){
            break;
        }

        cont++;

        for (int a = 0 ; a < o ; a++){

            int i,j,p;      //cidade i, cidade j, preço p
            cin >> i >> j >> p;     //grafo não dirigido


        }

        cout << "Caso " << cont << ":" << " " << /*valor <<*/ endl;
    }

    return 0;
}



















/*


};

int main(){

    Grafo g(5);

   g.setEdge(0,1,10);
   g.setEdge(0,2,3);
   g.setEdge(0,3,20);
   g.setEdge(1,3,5);
   g.setEdge(1,2,2);
   g.setEdge(2,4,15);
   g.setEdge(3,4,11);

    vector<int> distancias(5);
    vector<int> vertices(5);
    g.Prim(distancias, vertices);
    
    for(int i = 0 ; i < 5 ; i++){
        if (distancias[i] == INT_MAX) {
            cout << "INFINITO ";
        } 
        else{
            cout << distancias[i] << " ";
        } 
    }

    return 0;
}*/