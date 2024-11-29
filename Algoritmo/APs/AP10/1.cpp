#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Grafo{
private:
    int** matrix;       //adjacency matrix
    int numEdge;        //nº de arestas
    int* Mark;          //lista de visitados
    int size;
public:
    Grafo (int n){
        matrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[n]();
        }
        numEdge = 0;
        Mark = new int[n];
        size = n;

    }

    int first (int v){
        for (int i = 0 ; i < size ; i++){
            if (matrix[v][i] != 0){
                return i;
            }
        }
        return size;
    }

    int next (int u, int v){
        for (int i = v+1 ; i < size ; i++){
            if (matrix[u][i] != 0){
                return i;
            }
        }
        return size;
    }

    void setEdge(int i, int j){
        if (matrix[i][j] == 0){
           numEdge++;
        }
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

    void setMark (int v, bool visitado){
        if (visitado == true){
            Mark[v] = 1; 
        }
        else{
            Mark[v] = 0; 
        }
    }

    bool getMark (int v){
        if (Mark[v] == 0){
            return false;
        }
        else if (Mark[v] == 1){
            return true;
        }
    }

    void preVisit(int v){
        cout << v << " "; 
    }

    void posVisit (int v){
        cout << v << " ";
    }

    void DFS (int v){
        stack<int> s;

        preVisit(v);
        setMark(v,true);
        s.push(v);

        int w = first(v);

        while (w < size){
            if (getMark(w) == false){
                DFS(w);
            }
            posVisit(w);
            w = next(v,w);
        }
    }
 
    void BFS (int start){
        queue<int> Q;

        Q.push(start);
        setMark(start,true);

        while (Q.size() > 0){
            int v = Q.front();
            Q.pop();

            preVisit(v);

            int w = first(v);

            while (w < size){
                if (getMark(w) == false){
                    setMark(w,true);

                    Q.push(w);
                }
                w = next(v,w);
            }
        }
        cout << endl;
    }
 
};

int main(){

    int n,q;
    cin >> n >> q;

    Grafo grafo(n);

    for (int i = 0 ; i < q ; i++){
        string operacao;
        cin >> operacao;

        if (operacao == "add"){
            int u,v;
            cin >> u >> v;
            grafo.setEdge(u, v);
        }
        else if (operacao == "BFS"){
            int v;
            cin >> v;
            grafo.BFS(v);
        }
        else if (operacao == "DFS"){
            int v;
            cin >> v;
            grafo.DFS(v);
        }
    }

    return 0;
}