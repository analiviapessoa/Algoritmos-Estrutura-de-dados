#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> foods;
    foods = {"grapes","carrots","lemons"};
    foods.push_back("tortillas");
    foods.push_back("tortillas");

    for (int i = 0 ; i < foods.size() ; i++){
        cout << foods[i] << endl;
    }

    for (auto i = foods.begin() ; i != foods.end() ; i++){
        cout << *i << endl;
    }

    return 0;
}