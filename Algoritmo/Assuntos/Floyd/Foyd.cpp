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
        if (wt==0) return;

        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                edge.first = wt;
                return; 
            }
        }
        adjlist[u].push_back({wt,v});
        numEdge++;
    }

    int weight(int u, int v){
        for (auto& edge : adjlist[u]){
            if (edge.second == v){
                return edge.first;
            }
        }
        return INT_MAX;
    }

    void Floyd (vector<vector<int>>& Distance){
        for (int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                if (i == j){
                    Distance[i][j] = 0;
                }
                else if (weight(i,j) != 0){
                    Distance[i][j] = weight(i,j);
                }
                else{
                    Distance[i][j] = INT_MAX;
                }
            }
        }

        for (int k = 0 ; k < size ; k++){
            for (int i = 0 ; i < size ; i++){
                for (int j = 0 ; j < size ; j++){
                    if (Distance[i][k] != INT_MAX && Distance[k][j] != INT_MAX && Distance[i][j] > Distance[i][k] + Distance[k][j]){
                        Distance[i][j] = Distance[i][k] + Distance[k][j];
                    }
                }
            }
        }
    }
};

int main(){

    Grafo grafo(4);

    grafo.setEdge(0, 2, 3);
    grafo.setEdge(1, 0, 2);
    grafo.setEdge(2, 1, 7);
    grafo.setEdge(2, 3, 1);
    grafo.setEdge(3, 0, 6);

    vector<vector<int>> distancias(4, vector<int>(4,INT_MAX));
    grafo.Floyd(distancias);
    
    for(int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 4 ; j++){
            if (distancias[i][j] == INT_MAX) {
            cout << "INF ";
            } 
            else{
                cout << " " << distancias[i][j] << " ";
            } 
        }
        cout << endl;
    }

    return 0;
}