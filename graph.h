#define vertex int

//Representação por adjacência foi escolhida pela maior eficiência em grafos esparsos. Checar se o grafo de DNA é mais esparso.

/* A lista de adjacência de um vértice v é composta por nós do tipo node. 
Cada nó da lista corresponde a um arco e contém um vizinho w de v e o
endereço do nó seguinte da lista. Um link é um ponteiro para um node. */
typedef struct node *link;
struct node { 
   vertex w; 
   link next; 
};

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura graph representa um grafo. 
O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém 
o número de vértices e o campo A contém o número de arcos do grafo. */
struct graph {
   int V; 
   int A; 
   link *adj; 
};
typedef struct graph *Graph;
/* Um Graph é um ponteiro para um graph. */


