
// Dach sach lan can
#include <iostream>
#include <vector>
using namespace std;
#define MAX 120
vector<int> graph[MAX];
int main() {
    int V, E, u, v;
    cout << "Nhap so dinh V va so canh E: ";
    cin >> V >> E;
    cout << "Nhap cac canh (u v):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    cout << "Danh sach ke cua do thi:" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int v : graph[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}

// Ma tra lan can
#include <iostream>
using namespace std;

#define MAX 120
int adjMatrix[MAX][MAX] = { 0 };

int main() {
    int V, E, u, v;
    cout << "Nhap so dinh V va so canh E: ";
    cin >> V >> E;
    cout << "Nhap cac canh (u v):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    cout << "Ma tran ke cua do thi:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
