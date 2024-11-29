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

    int n (){
        return size;
    }

    int first (int l){
        for (int i = 0 ; i < size ; i++){
            if (matrix[l][i] != 0){
                return i;
            }
        }
        return size;
    }

    int next (int l, int c){
        for (int i = c+1 ; i < size ; i++){
            if (matrix[l][i] != 0){
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
    }

    void delEdge(int i, int j){

        if (matrix[i][j] != 0){
            numEdge--;
        }
        matrix[i][j] = 0;
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
        cout << "Pre: "; 
        for (int i = 0 ; i < size ; i++){
            cout << Mark[i] << " ";
        }
        cout << endl;
    }

    void posVisit(int v){
        cout << "Pos: ";
        for (int i = 0 ; i < size; i++){
            cout << Mark[i] << " ";
        }
        cout << endl;
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
            w = next(v,w);
        }
        posVisit(v);
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
            posVisit(v);
        }
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

    void toposort (int v, stack<int>& s){
        setMark(v,true);

        int w = first(v);

        while (w < size){
            if (getMark(w) == false){
                toposort(w,s);
            }
            w = next(v,w);
        }
        s.push(v);
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

    Grafo grafo(6);
    
    //linha,coluna,weight
    //weight = 1 -> not weighted
    grafo.setEdge(0, 1, 1);
    grafo.setEdge(0, 2, 1);
    grafo.setEdge(1, 3, 1);
    grafo.setEdge(2, 3, 1);
    grafo.setEdge(3, 4, 1);
    grafo.setEdge(4, 5, 1);

    cout << "Adjacency matrix: " << endl;
    grafo.printMatrix();

    cout << "DFS: " << endl;
    grafo.graphTraverseDFS();
    
    cout << "BFS: " << endl;
    grafo.graphTraverseBFS();

    stack<int> s;

    for (int v = 0; v < grafo.n(); v++) {
        grafo.setMark(v, false);
    }
    for (int v = 0; v < grafo.n(); v++) {
        if (grafo.getMark(v) == false) {
            grafo.toposort(v, s);
        }
    }
    
    cout << "Topological Sort: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}