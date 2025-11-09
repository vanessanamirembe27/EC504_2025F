#ifndef SHORTPATH_H_
#define SHORTPATH_H_

#include <queue>  // standard queue for Bellman-Ford 
#include "myHeap.h"  // your heap file from HW 2.  Request copy if needed.
#define LARGE1 9999999

using namespace std;


struct arc{
  struct arc *next; // next arc out of same start node in linked list
  int length;  // length of arc 
  int end; // end node 
  };

typedef struct node{
   struct arc *first; /* first arc out of node in linked list */
   int id;
   int distance;  /* Distance estimate, named distance to reuse heap code*/
   int P;  /* Predecessor node in shortest path */
   int position;  /* Position of node in heap, from 0 to Nm, where 0 is best */
   } nodeitem;

void BellmanFord(nodeitem N[], int Or, int Nm)
{
      struct arc *edge;
      int v,dv;  
      N[Or].distance = 0; 
      bool stop; 
      for (int k = 1; k <= Nm; k++){ // outer loop 
        stop = true; // optimization: exit if no distances change.
        for (int id = 1; id <= Nm; id++){ //scan all edges out of nodes
            edge = N[id].first;
            while (edge != NULL){ /* explore the outgoing arcs of id */
                 v = edge->end;
                 dv = N[id].distance+edge->length;
                 if (N[v].distance > dv){
                     N[v].distance = dv;
                     N[v].P = id;
                     stop = false;
                 }
                 edge = edge->next;
            }
        }
        if (stop) break;
     }
}/* end Bellman-Ford */
/* ---------------*/


void BellmanFord_Queue(nodeitem N[], int Or, int Nm)
{
  // you implement this. See the next algorithm, and replace the standard queue
  // with your own implementation of a queue 


}/* end Bellman-Ford2 */
/* ---------------*/

void BellmanFord_stdQueue(nodeitem N[], int Or, int Nm)
{
   int u;
   struct arc *edge;
   int v,dv;  
   queue<int> myQueue;  
   N[Or].distance = 0; 
   myQueue.push(Or); 
   while (!myQueue.empty()){
        u = myQueue.front();
        myQueue.pop();
        N[u].position = -1; // out of the queue
        edge = N[u].first;
        while (edge != NULL){ /* explore the outgoing arcs of u */
            v = edge->end;
            dv = N[u].distance+edge->length;
            if (N[v].distance > dv){
                N[v].distance = dv;
                N[v].P = u;
                if (N[v].position < 0 ){/* Node not in queue, add... */
                    myQueue.push(v); 
                    N[v].position = 1; // added to queue
                }/* if not in queue */
            }/* if D > dv */
            edge = edge->next;
        }/* while edge */
   }
}/* end Bellman-Ford_stdQueue */
/* ---------------*/

void Dijkstra(nodeitem N[], int Or, int Nm)
{
    int Mark[Nm+1];
    struct arc *edge;
    int v, dv, min_d, min_v, finished;
    for (int i=1; i<=Nm; i++){
        Mark[i]=-1;
    }
    N[Or].distance = 0;
    Mark[Or] = 1;
    finished = 1;
    min_v = Or;
    min_d = 0;
    while (finished < Nm){
        edge = N[min_v].first;  //update distances
        while (edge != NULL){ // explore the outgoing arcs of u 
            v = edge->end;
            dv = min_d + edge->length;
            if (N[v].distance > dv){
                N[v].distance = dv;
                N[v].P = min_v;
            }//if D > dv 
            edge = edge->next;
        }// while edge           
        
        min_d = LARGE1;
        for (int j = 0; j <= Nm; j++){
            if (Mark[j] < 1){
                if (N[j].distance < min_d){
                    min_d = N[j].distance;
                    min_v = j;
                }
            }
        } 
        Mark[min_v]=1;
        finished++;
    } 
} /* end Dijkstra */


void DijkstraHeap(nodeitem N[], int Or, int Nm)
{
   Heap<nodeitem> *thisHeap;

   // YOu fill out this algorithm, to implement Dijkstra's algorithm using 
   // a priority heap. Hopefully, your priority heap from HW 2. 



  } /* end DijkstraHeap */ 






#endif
