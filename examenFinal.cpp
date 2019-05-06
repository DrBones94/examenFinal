#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T>
class Heap {
  vector<T> list;

  void bubbleUp();
  void bubbleDown();
  void swap(int child, int parent);
  int getLeftChild(int parent);
  int getRightChild(int parent);
  int getParent(int child);
public:
  Heap();
  void insert(T );
  T remove();
  int getSize();
  bool search(T );
  void arrayGraph();

};

template <class T>
Heap<T> :: Heap(){
  
}

template <class T>
int Heap<T> :: getSize(){
  return list.size();
}

template <class T>
void Heap<T>::swap(int child, int parent) {
  T temp;
  temp = list[child];
  list[child] = list[parent];
  list[parent] = temp;
}

template <class T>
int Heap<T> :: getParent(int child) {
  if (child % 2 == 0)
	return (child /2 ) -1;
  else 
	return child/2;
  
}

template <class T>
int Heap<T> :: getLeftChild(int parent){
  return 2*parent +1;
}

template <class T>
int Heap<T> :: getRightChild(int parent){
  return 2 * parent + 2;
}

template <class T>
void Heap<T> :: insert(T value) {

  list.push_back(value);
  bubbleUp();

}

template <class T>
void Heap <T>:: bubbleUp() {
  int child = list.size() - 1;
  int parent = getParent(child);
  
  while (list[child] > list[parent] && child >=0 && parent >= 0) {
	
	swap(child, parent);
	child = parent;
	parent = getParent(child);

  }
  
  
}


template <class T>
T Heap<T> :: remove() {
  int child = list.size()  - 1;
  swap(child, 0);
  
  T value = list.back();
  list.pop_back();
  
  bubbleDown();
  
  return value;
}


template <class T>
void Heap<T> :: bubbleDown() {
  int parent = 0;

  while (1) {
	int left = getLeftChild(parent);
	int right = getRightChild(parent);
	int length = list.size();
	int largest = parent;

	if (left < length && list[left] > list[largest])
	  largest = left;

	if (right < length && list[right] > list[largest])
	  largest = right;

	if (largest != parent) {
	  swap(largest, parent);
	  parent = largest;
	}
	else 
	  break;
  }

}

template <class T>
bool Heap<T> :: search(T value){
	bool result = false;

	for(int i = 0; i < list.size(); i++){
		if(list[i] == value){
			result = true;
			break;
		}
	}

	return result;
}

template <class T>
void Heap<T> :: arrayGraph(){
	FILE *fp;
	fp = fopen("ARRAY.dot", "w");
	fprintf(fp, "%s", "digraph ARRAY{\n");
	fprintf(fp, "%s", "node [shape=record];\n");
	fprintf(fp, "%s", "node0[label=\"");
	for(int i = 0; i < list.size(); i++){
		fprintf(fp, "%s%d%s %d%s", "<f", i, ">", list[i], "|");
	}
	fprintf(fp, "%s", "\"]; \n");
	fprintf(fp, "%s", "}");
	fclose(fp);

	system("dot -Tpng ARRAY.dot -o ARRAY.png");
	
}

template <class T>
void Heap<T> :: treeGraph(){
	int izq, der;
	FILE *fp;
	fp = fopen("TREE.dot", "w");
	fprintf(fp, "%s", "digraph TREE{\n");
	fprintf(fp, "%s", "node [shape=record];\n");
	fprintf(fp, "%s", "node0[label=\"");
	for(int i = 0; i < list.size(); i++){
		if(i*2 > list.size()){
			izq = 0;
		}else{
			izq = list[2*i];
		}

		if((2*i) + 1 > list.size()){
			der = 0;
		}else{
			der = list[(2*i)+ 1];
		}
		fprintf(fp, "%s%d%s%d%s%d%s", "<f0>", izq, "|", list[i], "|", der, "<fi");
	}
	fprintf(fp, "%s", "\"]; \n");
	fprintf(fp, "%s", "}");
	fclose(fp);

	system("dot -Tpng TREE.dot -o TREE.png");
}

int main(){
	Heap<int> heap;
	
  //**********MENU**********
  	int opcion, contador_A, contador_C, contador_E, contador_P, valor;
   int n[10];

 
   do
   {
		printf( "\n   1. Insertar");
		printf( "\n   2. Eliminar");
		printf( "\n   3. Buscar");
		printf( "\n   4. Graficar Arbol");
		printf( "\n   5. Graficar Arreglo");
		printf( "\n   6. Salir");

		printf( "\n\n   Introduzca opcion (1-6): ");

		scanf( "%d", &opcion );

		/* Inicio del anidamiento */

		switch ( opcion )
		{
			case 1: printf( "\n Inserte un valor: ");
				scanf( "%d ", &valor );
				heap.insert(valor);
				printf("El numero a sido ingresado con exito! %d \n", valor);
				break;
			case 2: printf( "\n Eliminar un valor: ");
				scanf( "%d", &valor);
				heap.remove();
				break;
			case 3: printf( "\n Buscar un valor: ");
				scanf("%d", &valor);

				if(heap.search(valor)){
					printf("El valor %d a sido encontrado", valor);
					break;
				}

				printf("El valor %d no a sido encontrado", valor);
				break;
			case 4: 
				break;
			case 5:
				heap.arrayGraph();
				break;
			default:
				break;
		}



  } while ( opcion < 6 );
  //**********MENU**********

//   int len = sizeof(a) /sizeof(int);
//   int i =0;
//   for (i = 0; i < len; i++)
// 	{
// 	  heap.insert(a[i]);
// 	}

  while(heap.getSize() > 0)
	cout<<"Heap Max\t"<< heap.remove()<<endl;
  return 0;

}