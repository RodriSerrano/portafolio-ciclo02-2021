#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

//permite crear un tipo de datos
struct node {
	int key_value;
	node *left; //Puntero a la derecha
	node *right; //Puntero de arbol izquierdo
};     

class btree{
	
	public:
		btree(); //Constructor
		~btree(); //destructor
		void insert(int key); //funcion insertar
		node *search(int key); // funcion para buscar un arbol
		void destroy_tree();
		node *root_retriever();
		void mostrarArbol(string prefijo, node *arbol, bool ladoDerecho);
		void imprimirArbol();
		
	private:
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		node *root; //puntero tipo nodo root
		
		
};


// Implementando constructor
btree::btree(){
	root = NULL;
}

// Implementando destructor
btree::~btree(){
	destroy_tree();
}

//destruyendo el arbol
void btree::destroy_tree(node *leaf){
	
	if(leaf != NULL){
		
		// Funciones recursivas para destruir el arbol mediante nodos izquierdos y derechos
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf; //elimina el puntero
	}
}

//Insertando un nodo al arbol
void btree::insert(int key, node *leaf){
	
	if(key < leaf->key_value){
		
		if(leaf->left != NULL)
		insert(key, leaf->left);
		else{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	} else if(key >= leaf->key_value){
		
		if(leaf->right != NULL)
		insert(key, leaf->right);
		else{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}


node *btree::search(int key, node *leaf){
	
	if(leaf != NULL){
		
		if(key == leaf->key_value)
			return leaf;
		if(key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	} 
	else
		return NULL;
}


void btree::insert(int key){
	
	if(root != NULL)
		insert(key, root);
	else{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key){
	return search(key, root);
}

void btree::destroy_tree(){
	destroy_tree(root);
}

node *btree::root_retriever(){
	
	return root;
}

void btree::mostrarArbol(string prefijo, node *arbol, bool ladoDerecho){
	
	if(arbol != NULL){
		
		cout << prefijo;
		
		cout << (ladoDerecho ? "|--" : "|--");
		
		cout << arbol->key_value << endl;
		
		mostrarArbol(prefijo + (ladoDerecho ? "|   " : "    "), arbol->left, true);
		mostrarArbol(prefijo + (ladoDerecho ? "|   " : "    "), arbol->right, false);
	}
}

void btree::imprimirArbol(){
	
	mostrarArbol("", root, false);
}


int main(){
	
	btree arbol; //Punterrio tipo arbol
	
	arbol.insert(8);
	arbol.insert(5);
	arbol.insert(6);
	arbol.insert(2);	
	arbol.insert(10);
	arbol.insert(11);
	arbol.insert(9);
	arbol.insert(20);
	arbol.insert(23);
	
	arbol.imprimirArbol();
	
	return 0; 
}
