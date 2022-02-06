#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[40];

typedef struct nodo {
	int codProduc;
	string descripcion;
	float precioUnit;
	struct nodo *siguiente;
}tListaProductos;


tListaProductos * lista;

void menuPrincipal();
void inicializarLista(tListaProductos *plista);
bool listaVacia(tListaProductos *plista);
void menuIngresar();
void insertarPrimero();
void insertarAdelante();
void eliminarPrimero();
void insertarK(int);
void eliminarK(int);
void visualizarElementos(tListaProductos *plista);

int main() {
	inicializarLista(lista);
	menuPrincipal();
	system("pause");
	return 0;
}

void menuPrincipal() {
	int res, g, f;
	printf("\n\t\tMenu Principal\n");
	printf("\n\t\t1.Agregar Producto\n");
	printf("\n\t\t2. Visualizar Productos\n");
	printf("\n\t\t3. Eliminar Productos en la posicion K\n");
	printf("\n\t\t4. Eliminar el primer Producto\n");
	printf("\n\t\t5. Insertar en la posicion K Productos\n");
	printf("\n\t\t0. Salir\n");
	scanf("%d", &res);
	
	while(res != 0) {
		switch(res){
			case 1: menuIngresar();
							break;
			case 2: visualizarElementos(lista);
							break;
			case 3: 
							printf("\nIngrese la posicion k: ");
							scanf("%d", &g);
							eliminarK(g);
							break;
			case 4: eliminarPrimero();
							break;
			case 5:
							printf("\nIngrese la posicion K: ");
							scanf("%d", &f);
							insertarK(f);
							break;
		}
		printf("\n\t\tMenu Principal\n");
		printf("\n\t\t1.Agregar Producto\n");
		printf("\n\t\t2. Visualizar Productos\n");
		printf("\n\t\t3. Eliminar Productos en la posicion K\n");
		printf("\n\t\t4. Eliminar el primer Producto\n");
		printf("\n\t\t5. Insertar en la posicion K Productos\n");
		printf("\n\t\t0. Salir\n");
		scanf("%d", &res);
	}
	
}

void menuIngresar(){
	if(listaVacia(lista)) {
		insertarPrimero();
	}else{
		insertarAdelante();
	}
}

void inicializarLista(tListaProductos *plista) {
	plista = NULL;
	printf("Lista iniciada");
}

bool listaVacia(tListaProductos *plista) {
	return (plista == NULL);
}

void insertarPrimero() {
	tListaProductos * nuevoNodo;
	
	nuevoNodo = (tListaProductos * ) malloc(sizeof(tListaProductos));
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d", &nuevoNodo->codProduc);
	fflush(stdin);
	printf("\nIngrese la descripcion del producto: ");
	scanf("%[^\n]s", &nuevoNodo->descripcion);
	fflush(stdin);
	printf("\nIngrese el precio del Producto: ");
	scanf("%f", &nuevoNodo->precioUnit);
	
	nuevoNodo->siguiente = NULL;
	
	lista = nuevoNodo;
	
	printf("\nPrimer elemento insertado");
}

void insertarAdelante() {
	
	tListaProductos *nuevoNodo;
	
	nuevoNodo = (tListaProductos * ) malloc(sizeof(tListaProductos));
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d", &nuevoNodo->codProduc);
	fflush(stdin);
	printf("\nIngrese la descripcion del producto: ");
	scanf("%[^\n]s", &nuevoNodo->descripcion);
	fflush(stdin);
	printf("\nIngrese el precio del Producto: ");
	scanf("%f", &nuevoNodo->precioUnit);

	nuevoNodo->siguiente = lista;
	
	lista = nuevoNodo;
	printf("\nElemento insertado");
}


void eliminarPrimero() {
	tListaProductos *nodoSuprimir;
	nodoSuprimir = lista;
	
	lista = lista->siguiente;
	
	printf("\nPrimer Elemento Eliminado: %d, %s, %.2f", nodoSuprimir->codProduc, nodoSuprimir->descripcion,nodoSuprimir->precioUnit);
	
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
}

void insertarK(int k) {
	tListaProductos *aux;
	tListaProductos *nuevoNodo;
	int i;
	
	aux = lista;
	
	for(i = 1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	
	nuevoNodo = (tListaProductos *) malloc(sizeof(tListaProductos));
	
	printf("\nIngrese el codigo del producto: ");
	scanf("%d", &nuevoNodo->codProduc);
	fflush(stdin);
	printf("\nIngrese la descripcion del producto: ");
	scanf("%[^\n]s", &nuevoNodo->descripcion);
	fflush(stdin);
	printf("\nIngrese el precio del Producto: ");
	scanf("%f", &nuevoNodo->precioUnit);
	
	nuevoNodo->siguiente = aux->siguiente;
	
	aux->siguiente = nuevoNodo;
	
	printf("Elemento insertado en la posicion %d", k);
}

void eliminarK(int k) {
	tListaProductos *aux;
	tListaProductos *nodoSuprimir;
	int i;

	aux = lista;
	
	for ( i=1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	
	nodoSuprimir = aux->siguiente;
	
	aux->siguiente = nodoSuprimir->siguiente;
	
	printf("\nElemento Elimando");
	
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
}

void visualizarElementos(tListaProductos *plista) {
	tListaProductos *aux;
	
	aux = plista;
	
	if( listaVacia(aux) ) {
		printf("\nNo hay elementos en la lista!\n" );
	}else {
		printf("\nElementos de la lista: ");
		while(aux != NULL) {
			printf("\nCodigo del producto: %d", aux->codProduc);
			printf("\nDescripcion del producto: %s",aux->descripcion);
			printf("\nPrecio del Producto: %.2f", aux->precioUnit);
			aux = aux->siguiente;
			printf("\n");
		}
		printf("\n");
	}
}

