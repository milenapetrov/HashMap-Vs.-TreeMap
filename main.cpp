#include <iostream>
#include <random>
#include <chrono>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std::chrono;
using namespace std;

int InsertO(map<int, int> &mp, set<int> rands){
    auto start = high_resolution_clock::now();
    int k = 0;
    for(auto i : rands){
        mp[k] = i;
        k++;
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    return time.count();
};

int InsertU(unordered_map<int, int> &mp, set<int> rands){
    auto start= high_resolution_clock::now();
    int k = 0;
    for(auto i: rands){
        mp[k] = i;
        k++;
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    return time.count();
};

int findO(map<int, int> mp){
    auto start = high_resolution_clock::now();
    for(auto i: mp){
        mp.find(i.second);
    }
    auto stop = high_resolution_clock::now();
    auto time= duration_cast<microseconds>(stop-start);
    return time.count();
}

int findU(unordered_map<int, int> mp){
    auto start = high_resolution_clock::now();
    for(auto i: mp){
        mp.find(i.second);
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    return time.count();
}

int ClearO(map<int, int> &mp){
    auto start = high_resolution_clock::now();
    int i = 0;
    while(mp.size() > 0){
        mp.erase(i);
        i++;
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    return time.count();
};

int ClearU(unordered_map<int, int> &mp){
    auto start = high_resolution_clock::now();
    int i = 0;
    while(mp.size() > 0){
        mp.erase(i);
        i++;
    }
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    return time.count();
};


int main() {
    set<int> first;
    while(first.size() < 10000){
        first.insert(rand());
    }

    set<int> second;
    while(second.size() < 100000){
        second.insert(rand());
    }

    //First set operations: 10,000
    unordered_map<int, int> Umap1;
    map<int,int> map1;

    cout << "\033[35mMaps with 10,000 elements\033[0m" << endl;

    cout << "Time to insert Ordered Map --> ";
    cout << InsertO(map1, first) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << InsertU(Umap1, first) << " microseconds" << endl;

    cout << "Time to find index of value in Ordered Map --> ";
    cout << findO(map1) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << findU(Umap1) << " microseconds" << endl;

    cout << "Time to delete all elements in Ordered Map--> ";
    cout << ClearO(map1) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << ClearU(Umap1) << " microseconds" << endl << endl;

    map<int, int> map2;
    unordered_map<int, int> Umap2;

    cout << "\033[36mMaps with 100,000 elements\033[0m" << endl;
    cout << "Time to insert Ordered Map --> ";
    cout << InsertO(map2, second) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << InsertU(Umap2, second) << " microseconds" << endl;

    cout << "Time to find index of value in Ordered Map --> ";
    cout << findO(map2) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << findU(Umap2) << " microseconds" << endl;

    cout << "Time to delete all elements in Ordered Map--> ";
    cout << ClearO(map2) << " microseconds" << endl;
    cout << "Unordered Map: ";
    cout << ClearU(Umap2) << " microseconds" << endl;
}
