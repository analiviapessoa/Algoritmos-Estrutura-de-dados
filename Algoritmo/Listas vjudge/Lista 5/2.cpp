#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Grafo{
private:
    vector<vector<int>> adjlist;
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

    void setEdge(int u, int v){
        adjlist[u].push_back(v);
        numEdge++;
    }

    void toposort (){

        vector<int> grau (size);
        for (int i = 0 ; i < size ; i++){
            for (auto it : adjlist[i]){
                grau[it]++;
            }
        }

        priority_queue<int, vector<int>, greater<int>> fila;
        for (int i = 0 ; i < size ; i++){
            if (grau[i] == 0){
                fila.push(i);
            }
        }
        
        vector<int> resultado;
        while(!fila.empty()){
            int no = fila.top();

            fila.pop();
            resultado.push_back(no);

            for (auto it : adjlist[no]){
                grau[it]--;

                if (grau[it] == 0){
                    fila.push(it);
                }
            }
        }

        if ((int)resultado.size() != size){
            cout << "Sandro fails." << endl;
            return;
        }

        for (int i = 1 ; i < (int)resultado.size() ; i++){
            cout << resultado[i] << " ";
        }

    }

};

int main(){

    int n,m;
    cin >> n >> m;

    Grafo g(n+1);
    
    for (int i = 0 ; i < m ; i++){
        int x,y;
        cin >> x >> y;  //job x needs to be done before y

        g.setEdge(x,y);
    }

    g.toposort();

    return 0;
}