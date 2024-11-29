#include <iostream>
#include <list>
using namespace std;

/*++it ; --it ; 
*it: Access the value at the current iterator position;
it->: Access a member of the element pointed to by the iterator;
it == it2 and it != it2: Compare two iterators for equality or inequality*/

bool par(const int& valor){
    return ((valor%2) == 0);
}

int main(){

    list<int> lista7;               //lista vazia
    list<int> lista8(10,0);         //lita com o elemento 0 aparecendo 10 vezes
    list<int> lista9(lista8);       //lista igual a outra
    list<int> lista10 = {1,2,3,4};   //lista com os 4 elementos

    /*for (auto it = lista10.begin() ; it != lista4.end() ; it++){
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Tamanho: " << lista10.size() << endl;
    cout << "Capacidade maxima: " << lista10.max_size() << endl;
    cout << "Primeiro elemento: " << lista10.front() << endl;
    cout << "Ultimo elemento: " << lista10.back() << endl;
    cout << "Lista esta vazia: " << lista10.empty() << endl; //0 = false ; 1 = true
    */

    list<int> lista5 = {1,2,3,4};
    list<int> lista6;
    list<int>::iterator it;

    lista6.assign(10,0);
    lista6.assign(lista5.begin(),lista5.end());

    lista5.pop_back();
    lista5.pop_front();

    lista5.push_back(8);
    lista5.push_front(9);

    it = lista5.begin();
    it++;
    lista5.insert(it,7);
    lista5.erase(it);

    /*for(auto x:lista5){
        cout << x << " ";
    }*/


   list<int> lista3 = {1,2,3,4,5};
   list<int> lista4 = {6,7,8,9,10};

   lista3.swap(lista4);     //troca o conteúdo das listas
   lista4.resize(3);        //reduz a lista para 3 elementos

   /*for (auto x:lista3){
    cout << x << " ";
   }

   cout<<endl;
   
   for (auto x:lista4){
    cout << x << " ";
   }*/

    list<int> lista1 = {1,2,3,4,5};

    lista1.emplace(++ ++lista1.begin(),9);
    lista1.emplace_back(8);
    lista1.emplace_front(0);

    /*for(auto x:lista1){
        cout << x << " ";
    }*/

   list<int>lista = {9,9,0,8,8,0,7,7,0,6,6,0,5,5,0,4,4,0,3,3,0,2,2,0,1,1,0};

   lista.remove(0);
   lista.remove_if(par);

    lista.sort();
    lista.unique();

    for(auto x:lista){
        cout << x << " ";
    }
    cout<< endl;

    list<int> listaa = {2,4,6,8,10};

    lista.merge(listaa);
    lista.reverse();

    for(auto x:lista){
        cout << x << " ";
    }

    return 0;
}