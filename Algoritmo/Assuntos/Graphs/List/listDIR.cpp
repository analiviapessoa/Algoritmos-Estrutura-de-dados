#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Grafo{
//pair<weight,element>
private:
    vector<vector<pair<int,int>>> adjlist;      //adjacency list (vizinho,weight)
    int numEdge;        //nº de arestas
    int* Mark;          //lista de visitados
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

    int first (int v){ //acessa o primeiro elemento da lista de adjacência do vértice v
        if (!adjlist.empty()){
            return adjlist[v].front().second;
        }
        return -1;
    }

    int next (int u, int v){   //acessa o segundo vizinho de u
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

    void delEdge(int u, int v){
        for (auto it = adjlist[u].begin() ; it != adjlist[u].end() ; it++){
            if (it -> second == v){
                adjlist[u].erase(it);
                numEdge--;
                break;
            }
        }
    }

    void setMark (int v, int valor){
        Mark[v] = valor;
    }

    bool getMark (int v){
        return Mark[v] == 1;
    }

    void checar (int v, stack<int>& s){
        setMark(v,1);

        for (auto i : adjlist[v]){
            if (!getMark(i.second)){
                checar(i.second,s);
            }

        }
        s.push(v);//v só entra na stack depois que todos os seus sucessores já entraram
    }

    void toposort (){
        stack<int> s;

        for (int i = 0; i < size ; i++) {
            if (!getMark(i)) {
                checar(i, s);
            }
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void printList(){
        for (int i = 0 ; i < size ; i++){
            cout << i << " : ";
            for (auto v:adjlist[i]){
                cout << "(" << v.second << ", " << v.first << ") ";
            }
            cout << endl;
        }
    }

    vector<int> menorDist (int start){
        vector<int> dist(size,-1);  //-1 = não visitado
        queue<int> Q;

        Q.push(start);
        dist[start] = 0;

        while (!Q.empty()){
            int topelement = Q.front();

            Q.pop();

            for (auto it : adjlist[topelement]){
                if (dist[it.second] == -1){
                    dist[it.second] = dist[topelement] + 1;
                    Q.push(it.second);
                }
            }
        }
    return dist;
    }
    
    void preVisit(int v) {
        cout << "Pre visit: " << v << endl;
    }

    void posVisit(int v) {
        cout << "Post visit: " << v << endl;
    }

    void DFS(int v) {
        stack<int> s;

        preVisit(v);
        setMark(v, true);
        s.push(v);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            int w = first(current);

            while (w != -1) { // Corrigido aqui
                if (!getMark(w)) {
                    preVisit(w);
                    setMark(w, true);
                    s.push(current); 
                    s.push(w); 
                    break;
                }
                w = next(current, w);
            }
            if (w == -1) {
                posVisit(current);
            }
        }
    }

    void graphTraverseDFS() {
        for (int v = 0; v < size; v++) {
            setMark(v, 0);
        }
        for (int v = 0; v < size; v++) {
            if (!getMark(v)) {
                DFS(v);
            }
        }
    }

    void BFS (int start){
        queue<int> Q;

        Q.push(start);
        setMark(start,1);

        while (!Q.empty()){
            int v = Q.front();
            Q.pop();

            preVisit(v);

            int w = first(v);

            while (w != -1){
                if (!getMark(w)){
                    setMark(w,1);

                    Q.push(w);
                }
                w = next(v,w);
            }
            posVisit(v);
        }
    }

    void graphTraverseBFS (){
        for (int v = 0 ; v < size ; v++){
            setMark(v,0);
        }
        for (int v = 0 ; v < size ; v++){
            if (!getMark(v)){
                BFS(v);
            }
        }
    }

};

int main(){

    Grafo grafo(6);

    //weight = 1 -> not weighted
    grafo.setEdge(0, 1, 1);
    grafo.setEdge(0, 2, 1);
    grafo.setEdge(1, 3, 1);
    grafo.setEdge(2, 3, 1);
    grafo.setEdge(3, 4, 1);
    grafo.setEdge(4, 5, 1);

    cout << "Adjacency list: " << endl;
    grafo.printList();

    cout << "Topological sort: " << endl;
    grafo.toposort();
    
    cout << "Menor distancia: " << endl;
    vector<int> distancias = grafo.menorDist(0);
    for (int i = 0; i < distancias.size(); ++i) {
        cout << "Distancia do vertice 0 para o vertice " << i << " : " << distancias[i] << endl;
    }

    cout << "BFS: " << endl;
    grafo.graphTraverseBFS();

    cout << "DFS: " << endl;
    grafo.graphTraverseDFS();

    return 0;
}