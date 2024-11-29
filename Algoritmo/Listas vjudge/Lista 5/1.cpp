#include <bits/stdc++.h>
using namespace std;

class Grafo{
private:
    vector<vector<int>> adjlist;      
    int numEdge;  
    int* Mark;        
    int size;

    map<string,int> chave_do_nome;
    vector<string> nome_da_chave;
    int proxchave;

public:
    Grafo (int n){
        adjlist.resize(n);
        numEdge = 0;
        Mark = new int[n];
        size = n;

        nome_da_chave.resize(n);
        proxchave = 0;

        for (int i = 0 ; i < size ; i++){
            Mark[i] = -1;
        }
    }

    int adicionarnome (string& nome){
        if(chave_do_nome.find(nome) == chave_do_nome.end()){
            chave_do_nome[nome] = proxchave;
            nome_da_chave[proxchave] = nome;
            proxchave++;
        }
        return chave_do_nome[nome];
    }

    void setEdge(int u, int v){
        if (u==v) return;

        for (int edge : adjlist[u]){
            if (edge == v){
                return; 
            }
        }

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        numEdge++;
    }

    int first (int v){ 
        if (!adjlist.empty()){
            return adjlist[v].front();
        }
        return -1;
    }

    int next (int u, int v){ 
        for (int i = 0 ; i < adjlist[u].size() ; i++){
            if (adjlist[u][i] == v){
                ++i;
                if(i < adjlist[u].size()){
                    return adjlist[u][i];
                }
                break;
            }
        }
        return -1;
    }

    void BFS (string nome){   
        queue<int> Q;     
        int start = chave_do_nome[nome];
        
        Q.push(start);
        Mark[start] = 0;

        while(!Q.empty()){
            int v = Q.front();
            Q.pop();

            int w = first(v);

            while(w != -1){

                if (Mark[w] == -1){
                    Mark[w] = Mark[v] + 1;
                    Q.push(w);
                }
                w = next(v,w);
            }
        }
    } 

    void printarranking (){
        vector<pair<int,string>> alunos_defined;
        vector<string> alunos_undefined;

        for (int i = 0 ; i < proxchave ; i++){
            if (Mark[i] != -1){
                alunos_defined.push_back({Mark[i], nome_da_chave[i]});
            }
            else{
                alunos_undefined.push_back(nome_da_chave[i]);
            }
        }

        sort(alunos_defined.begin(), alunos_defined.end(), [](pair<int,string>& a, pair<int,string>& b){
            if (a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        sort(alunos_undefined.begin(), alunos_undefined.end());

        cout << alunos_defined.size() + alunos_undefined.size()<< endl;

        for (auto alunos : alunos_defined){
            cout << alunos.second << " " << alunos.first << endl;
        }

        for (auto alunos : alunos_undefined){
            cout << alunos << " undefined" << endl;
        }
    } 

};

int main(){

    int t;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
        int n;
        cin >> n;

        Grafo g(n*3);

        for (int j = 0 ; j < n ; j++){
            string nome1, nome2, nome3;
            cin >> nome1 >> nome2 >> nome3;

            int chave1 = g.adicionarnome(nome1);
            int chave2 = g.adicionarnome(nome2);
            int chave3 = g.adicionarnome(nome3);
            
            g.setEdge(chave1,chave2);
            g.setEdge(chave1,chave3);
            g.setEdge(chave2,chave3);
        }

        g.BFS("Ahmad");
        g.printarranking();

    }

    return 0;
}