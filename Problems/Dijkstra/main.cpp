/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
#include <vector>
#include <climits>

void dijkstra(int graph[MAX][MAX], int s,int V)
{   
   //Arreglos para visitados y no visitados 
   vector<int> visited;
   
   //Incluye nodo inicial
   vector<int> distances(V, 0);
   vector<int> results(V);
   
   int min = 0;
   int index;
   index = s;
   
   //Valores por nodo inicial
   distances[index] = -1;
   visited.push_back(index);
   
   while(visited.size() != V) {
        
        //Actualizar valores de distancias
        for(int i = 0; i < V; i++) {
            if(graph[index][i] != 0) {
                if(graph[index][i] + min < distances[i] || distances[i] == 0) {
                    distances[i] = graph[index][i] + min;
                }
            }
        }
       
        min = INT_MAX;
        //Encontrar siguiente nodo a visitar dependiendo las distancias
        for(int i = 0; i < V; i++) {
            if(distances[i] < min && distances[i] > 0) {
                min = distances[i];
                index = i;
            }
        }
       
        results[index] = min;
        //Asigna -1 a arreglo de distancias en subindice de nodos visitados
        distances[index] = -1;
        //Agrega
        visited.push_back(index);
    }
    
    for(int i = 0; i < V; i++) {
        cout << results[i];
        if(i != V - 1) {
            cout << " ";
        }
    }
}