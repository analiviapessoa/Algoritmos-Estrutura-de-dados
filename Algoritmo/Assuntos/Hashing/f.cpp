#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

typedef int (*Hash) (string);

struct entrada {
    string key;
    string element;
    entrada(string chave, string elemento) : key(chave), element(elemento) {} // construtor
};

struct dicionario {
    int m;
    int cnt;
    vector<list<entrada>> H;
    Hash h;
};

int hfold(string key, int m) {
    int s = key.length();
    int soma = 0;
    for (int i = 0; i < s; i++) {
        soma += key[i];
    }
    return abs(soma) % m;
}

int hsfold(string key, int m) {
    int s = key.length() / 4;
    int soma = 0;
    for (int i = 0; i < s; i++) {
        string sub = key.substr(i * 4, 4);
        int mult = 1;
        for (int j = 0; j <= 3; j++) {
            soma += sub[j] * mult;
            mult *= 256;
        }
    }
    string sub = key.substr(s * 4);
    int mult = 1;
    int sub_len = sub.length();
    for (int j = 0; j < sub_len; j++) {
        soma += sub[j] * mult;
        mult *= 256;
    }
    return abs(soma) % m;
}

dicionario create_dict(int size, Hash hash_function) {
    dicionario d;
    d.m = size;
    d.cnt = 0;
    d.H = vector<list<entrada>>(size);
    d.h = hash_function;
    return d;
}

void clear(dicionario& d) {
    for (int i = 0; i < d.m; i++) {
        d.H[i].clear();
    }
    d.cnt = 0;
}

void insert(dicionario& d, string chave, string elemento) {
    if (find(d, chave) == nullptr) {
        int pos = d.h(chave);
        d.H[pos].emplace_back(chave, elemento);
        d.cnt++;
    }
}

string remove(dicionario& d, string chave) {
    int pos = d.h(chave);
    auto& entradas = d.H[pos];
    for (auto it = entradas.begin(); it != entradas.end(); it++) {
        if (it->key == chave) {
            string elemento = it->element;
            entradas.erase(it);
            d.cnt--;
            return elemento;
        }
    }
    return "";
}

string remove_any(dicionario& d) {
    for (int i = 0; i < d.m; i++) {
        if (!d.H[i].empty()) {
            string elemento = d.H[i].front().element;
            d.H[i].pop_front();
            d.cnt--;
            return elemento;
        }
    }
    return "";
}

entrada* find(dicionario& d, string chave) {
    int pos = d.h(chave);
    for (auto& entry : d.H[pos]) {
        if (entry.key == chave) {
            return &entry;
        }
    }
    return nullptr;
}

int size(const dicionario& d) {
    return d.cnt;
}

int main() {
    dicionario d = create_dict(10, hfold());

    insert(d, "KEY1", "Value1");
    insert(d, "KEY2", "Value2");
    insert(d, "KEY3", "Value3");

    // Teste de busca
    entrada* result = find(d, "KEY1");
    if (result != nullptr) {
        cout << "Found: " << result->key << " -> " << result->value << endl;
    } else {
        cout << "Not found: KEY1" << endl;
    }

    result = find(d, "KEY2");
    if (result != nullptr) {
        cout << "Found: " << result->key << " -> " << result->value << endl;
    } else {
        cout << "Not found: KEY2" << endl;
    }

    result = find(d, "KEY4");
    if (result != nullptr) {
        cout << "Found: " << result->key << " -> " << result->value << endl;
    } else {
        cout << "Not found: KEY4" << endl;
    }

    // Teste de remoção
    cout << "Removing KEY2: " << remove(d, "KEY2") << endl;

    result = find(d, "KEY2");
    if (result != nullptr) {
        cout << "Found: " << result->key << " -> " << result->value << endl;
    } else {
        cout << "Not found: KEY2" << endl;
    }

    return 0;
}
