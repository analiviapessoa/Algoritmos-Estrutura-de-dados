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

    void setEdge(int i, int j, int wt){
        if (wt==0) return;

        if (matrix[i][j] == 0){
           numEdge++;
        }
        matrix[i][j] = wt;
        matrix[j][i] = wt;
    }

    void delEdge(int i, int j){

        if (matrix[i][j] != 0){
            numEdge--;
        }
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }

    void setMark (int v, bool visitado){
        if (visitado){
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

    void posVisit(int v){
        cout << v << " ";
    }
 
    void DFS (int v){
        stack<int> s;

        preVisit(v);
        setMark(v,true);
        s.push(v);

        int w = first(v);

        while (w < size){
            if (!getMark(w)){
                DFS(w);
            }
            posVisit(w);
            w = next(v,w);
        }
    }

    void graphTraverseDFS(){
        for (int v = 0 ; v < size ; v++){
            setMark(v,false);
        }
        for (int v = 0 ; v < size ; v++){
            if (getMark(v) == false){
                DFS(v);
            }
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

    void graphTraverseBFS (){
        for (int v = 0 ; v < size ; v++){
            setMark(v,false);
        }
        for (int v = 0 ; v < size ; v++){
            if (getMark(v) == false){
                BFS(v);
            }
        }
    }

    void printMatrix(){
        for (int i = 0 ; i < size ; i++){
            for (int j = 0 ; j < size ; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){

    Grafo grafo(5);

    //linha,coluna,weight
    //weight = 1 -> not weighted
    grafo.setEdge(0, 1, 1);
    grafo.setEdge(1, 3, 1);
    grafo.setEdge(0, 3, 1);
    grafo.setEdge(3, 4, 1);
    grafo.setEdge(3, 2, 1);
    grafo.setEdge(2, 4, 1);

    cout << "Adjacency matrix: " << endl;
    grafo.printMatrix();

    cout << "BFS: " << endl;
    grafo.BFS(0);
    cout << endl;
    grafo.graphTraverseBFS();

    cout << "DFS: " << endl;
    grafo.DFS(3);
    cout << endl;
    grafo.graphTraverseDFS();
    
    return 0;
}