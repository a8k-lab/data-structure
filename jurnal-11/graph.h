#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define firstVertex(G) G.firstVertex
#define firstEdge(V) V->firstEdge
#define nextVertex(V) V->nextVertex
#define nextEdge(E) E->nextEdge
#define nil NULL

typedef struct vertex* adrVertex;
typedef struct edge* adrEdge;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertexId;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

/**
 * I.S. Terdefinisi ID untuk vertex/simpul baru.
 * F.S. Telah dialokasi sebuah simpul baru v dengan idVertex(v)=newVertexID, nextVertex(v)=nil, firstEdge(v)=nil
 */
void createVertex_103042310065(char newVertexID, adrVertex &v);

/**
 * I.S. -
 * F.S. terdefinisi sebuah graph G dimana firstVertex(G)=nil
 */
void initGraph_103042310065(graph &G);

/**
 * I.S. Terdefinisi sebuah graf, G, dan sebuah ID vertex/simpul yang akan ditambahkan ke dalam G.
 * F.S. Simpul baru dengan ID=newVertexID sudah ditambahkan ke dalam graf G
 */
void addVertex_103042310065(graph &G, char newVertexID);

/**
 * I.S. -
 * Proses: menerima ID vertex/simpul baru dari piranti masukan, kemudian menambahkan simpul baru itu ke dalam graf G. ID vertex adalah huruf (A..Z).
 * Proses dilakukan berulang sampai diterima character yang bukan huruf.
 * F.S. Terbentuk sebuah graf G yang setiap simpulnya mempunyai ID yang unik (tidak ada yang sama satu sama lain. Graf G belum mempunyai busur
 */
void buildGraph_103042310065(graph &G);

/**
 * Mengembalikan true jika graf G sudah memiliki sebuah simpul dengan id simpulID.
 */
bool hasVertex_103042310065(graph G, char simpulID);

/**
 * Fungsi akan mencari vertex yang berisi IDsimpul. Fungsi akan mengirimkan alamat elemen vertex tersebut jika ditemukan atau NIL jika tidak ditemukan.
 */
adrVertex searchVertex_103042310065(graph G, char simpulID);

/**
 * I.S. Terdefinisi ID simpul tujuan.
 * F.S. Telah dialokasi sebuah elemen edge baru bernama e, dimana destVertexID(e)=IDsimpulTujuan,weight(e)= bobot, dan nextEdge (e)=nil.
 */
void createEdge_103042310065(char simpulID, int weight, adrEdge &e);

/**
 * I.S. Terdefinisi sebuah graf, G. Juga diketahui ID simpul asal dan tujuan sebuah edge beserta bobotnya.
 * Proses: Cari elemen vertex dengan ID=IDsimpulAsal. Kemudian, tambahkan busur baru yang menghubungkan simpul asal dan simpul tujuan.
 * F.S. Sebuah edge baru dari telah ditambahkan, dimana destVertexID(e)=IDsimpulTujuan, weight(e)=bobot, dan nextEdge (e)=nil.
 */
void addEdge_103042310065(graph &G, char simpulIDAsal, char simpulIDTujuan, int weight);

/**
 * Fungsi akan mengirimkan derajat keluar (out-degree) untuk simpul dengan ID = simpulID.
 */
int outDegree_103042310065(graph G, char simpulID);

/**
 * Fungsi akan mengirimkan derajat masuk (in-degree) untuk simpul dengan ID = simpulID.
 */
int inDegree_103042310065(graph G, char simpulID);

/**
 * Fungsi akan mengirimkan derajat  untuk simpul dengan ID = simpulID.
 */
int degree_103042310065(graph G, char simpulID);

#endif // GRAPH_H_INCLUDED
