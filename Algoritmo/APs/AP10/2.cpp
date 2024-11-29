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

    }

    void setEdge(int u, int v){

        adjlist[u].push_back(v);
        numEdge++;
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

    void checar (int v, stack<int>& s){
        setMark(v,true);

        for (auto i : adjlist[v]){
            if (!getMark(i)){
                checar(i,s);
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
    
};

int main(){

    int n,m;
    cin >> n >> m;

    Grafo grafo(n);

    for (int i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;

        grafo.setEdge(u,v);

    }

    grafo.toposort();

    return 0;
}