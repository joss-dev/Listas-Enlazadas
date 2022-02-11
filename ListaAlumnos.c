#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char string[40];

typedef struct nodo {
	int libUni;
	string apeYNom;
	struct nodo *siguiente;
}tAlumno;

void iniciarLista(tAlumno *);
void insertarPrimero();
void menuIngresar();
void menuPrincipal();
bool listaVacia(tAlumno *);
void insertarAdelante();
void eliminarPrimero();
void insertarK(tAlumno *);
void eliminarK(tAlumno *);
void visualizarDatos(tAlumno *);
int cantidadAlumnos(tAlumno *);

tAlumno *lista;

int main() {
	iniciarLista(lista);
	menuPrincipal();
	return 0;
}
void menuPrincipal() {
	int res;
	printf("\n\t\tMenu Principal\n");
	printf("\n\t\t1.Agregar Alumno\n");
	printf("\n\t\t2. Visualizar Alumnos\n");
	printf("\n\t\t3. Eliminar Alumno en la posicion K\n");
	printf("\n\t\t4. Eliminar el primer Alumno\n");
	printf("\n\t\t5. Insertar en la posicion K\n");
	printf("\n\t\t6. Mostrar cantidad de alumnos en lista\n");
	printf("\n\t\t0. Salir\n");
	scanf("%d", &res);

	while(res != 0) {
		switch(res){
			case 1: menuIngresar();
							break;
			case 2: visualizarDatos(lista);
							break;
			case 3: eliminarK(lista);
							break;
			case 4: eliminarPrimero();
							break;
			case 5: insertarK(lista);
							break;
			case 6: printf("\nLa cantidad de alumnos en lista es: %d", cantidadAlumnos(lista));
							break;
		}
		printf("\n\t\tMenu Principal\n");
		printf("\n\t\t1.Agregar Producto\n");
		printf("\n\t\t2. Visualizar Productos\n");
		printf("\n\t\t3. Eliminar Productos en la posicion K\n");
		printf("\n\t\t4. Eliminar el primer Producto\n");
		printf("\n\t\t5. Insertar en la posicion K Productos\n");
		printf("\n\t\t6. Mostrar cantidad de alumnos en lista\n");
		printf("\n\t\t0. Salir\n");
		scanf("%d", &res);
	}

}
void iniciarLista(tAlumno *pLista) {
	pLista = NULL;
	printf("\nLista iniciada");
}

bool listaVacia(tAlumno *pLista) {
	return (pLista == NULL);
}

void insertarPrimero() {
	tAlumno *nuevoNodo;
	
	nuevoNodo = (tAlumno *) malloc(sizeof(tAlumno));
	
	printf("\nIngrese el numero de libreta: ");
	scanf("%d", &nuevoNodo->libUni);
	fflush(stdin);
	printf("\nIngrese el nombre del alumno: ");
	scanf("%[^\n]s", &nuevoNodo->apeYNom);
	
	nuevoNodo->siguiente = NULL;
	

	lista = nuevoNodo;
	
	printf("\nAlumno Insertado");
}

void insertarAdelante() {
	tAlumno *nuevoNodo;
	
	nuevoNodo = (tAlumno *) malloc(sizeof(tAlumno));
	
	printf("\nIngrese el numero de libreta: ");
	scanf("%d", &nuevoNodo->libUni);
	fflush(stdin);
	printf("\nIngrese el nombre del alumno: ");
	scanf("%[^\n]s", &nuevoNodo->apeYNom);
	
	nuevoNodo->siguiente = lista;
	
	lista = nuevoNodo;
	
	printf("\nALumno guardado");
}

void menuIngresar() {
	if(listaVacia(lista)) {
		insertarPrimero();
	}else{
		insertarAdelante();
	}
}

void eliminarPrimero() {
	tAlumno *nodoSuprimir;
	
	nodoSuprimir = lista;
	
	lista = lista->siguiente;
	
	printf("\nElemento Eliminado");
	
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
}

void insertarK(tAlumno *pLista) {
	tAlumno *nuevoNodo;
	tAlumno *aux;
	int k, i;
	printf("\nIngrese la posicion a ingresar: ");
	scanf("%d", &k);
	
	aux = pLista;
	
	for(i = 1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	
	nuevoNodo = (tAlumno *) malloc(sizeof(tAlumno));
	
	printf("\nIngrese el numero de libreta: ");
	scanf("%d", &nuevoNodo->libUni);
	fflush(stdin);
	printf("\nIngrese el nombre del alumno: ");
	scanf("%[^\n]s", &nuevoNodo->apeYNom);
	
	nuevoNodo->siguiente = aux->siguiente;
	
	aux->siguiente = nuevoNodo;
	
	printf("\nElemento Insertado en la posicion k: %d", k);
}

void eliminarK(tAlumno *pLista) {
	tAlumno *nodoSuprimir;
	tAlumno *aux;
	int i, k;
	printf("\nIngrese la posicion a elimnar: ");
	scanf("%d", &k);
	
	aux = pLista;
	
	for(i = 1; i < k-1; i++) {
		aux = aux->siguiente;
	}
	
	nodoSuprimir = aux->siguiente;
	
	aux->siguiente = nodoSuprimir->siguiente;
	
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
}

int cantidadAlumnos(tAlumno *pLista) {
	int cantAlumnos;
	tAlumno *aux;
	aux = pLista;
	
	if(listaVacia(aux)) {
		printf("\nNo hay elementos para mostrar");
	}else {
		while(aux != NULL) {
			cantAlumnos++;
			aux = aux->siguiente;
		}
	}
	return cantAlumnos;
}


void visualizarDatos(tAlumno *pLista) {
	tAlumno *aux;
	
	aux = pLista;
	
	if(listaVacia(aux)) {
		printf("\nNo hay elementos para mostrar");
	}else {
		while(aux != NULL) {
			printf("\nLibreta uni: %d", aux->libUni);
			printf("\nNombre y apellido: %s", aux->apeYNom);
			aux = aux->siguiente;
			printf("\n");
			printf("\n");
		}
	}
}
