#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Dictionary {
    private:
    vector<pair<int,int>> data;
    int binarySearch(int key) {
        int lo = 0, hi = (int)data.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (data[mid].first == key) return mid;
            else if (data[mid].first < key) lo = mid + 1;
            else hi = mid - 1;}
        return -1;}
    public:
    void insert(int key, int value) {
        int idx = binarySearch(key);
        if (idx != -1) {
            data[idx].second = value;
            return;}
        auto it = lower_bound(data.begin(), data.end(), make_pair(key, -1000000000));
        data.insert(it, {key, value});}
    void del(int key) {
        int idx = binarySearch(key);
        if (idx == -1) {
            cout << "Not Found\n";
            return;}
        data.erase(data.begin() + idx);
        cout << "Deleted\n";}
    void search(int key) {
        int idx = binarySearch(key);
        if (idx == -1) {
            cout << "Not Found\n";
            return;}
        cout << data[idx].second << "\n";}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    Dictionary dict;
    while (Q--) {
        string op;
        cin >> op;
        if (op == "INSERT") {
            int k, v;
            cin >> k >> v;
            dict.insert(k, v);} 
        else if (op == "DELETE") {
            int k;
            cin >> k;
            dict.del(k);} 
        else if (op == "SEARCH") {
            int k;
            cin >> k;
            dict.search(k);}}
    return 0;}
        
    