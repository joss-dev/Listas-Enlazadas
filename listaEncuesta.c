#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef char string[40];


typedef struct {
	string codSexo;
	string imc;
	int rangEdad;
	float peso;
	float altura;
}tPersona;

typedef struct nodo {
	tPersona persona;
	struct nodo *siguiente;
}tEncuesta;

/*peso ÷ altura2 (2,7225) = 24,98?*/


void iniciarLista(tEncuesta *);
float calcularImc(float, float);
void insertarPrimero();
void menuIngresar();
void menuPrincipal();
bool listaVacia(tEncuesta *);
void insertarAdelante();
void eliminarPrimero();
void insertarK(tEncuesta *);
void eliminarK(tEncuesta *);
void visualizarDatos(tEncuesta *);
int cantidadEncuestados(tEncuesta *);

tEncuesta *lista;

int main() {
	iniciarLista(lista);
	menuPrincipal();
	return 0;
}
void menuPrincipal() {
	int res;
	printf("\n\t\tMenu Principal\n");
	printf("\n\t\t1.Agregar Encuesta\n");
	printf("\n\t\t2. Visualizar Datos\n");
	printf("\n\t\t4. Eliminar la primer encuesta\n");
	printf("\n\t\t6. Mostrar cantidad de encuestados en lista\n");
	printf("\n\t\t0. Salir\n");
	scanf("%d", &res);

	while(res != 0) {
		switch(res){
			case 1: menuIngresar();
							break;
			case 2: visualizarDatos(lista);
							break;
			case 4: eliminarPrimero();
							break;
			case 6: printf("\nLa cantidad de encuestas en lista es: %d", cantidadEncuestados(lista));
							break;
		}
		printf("\n\t\tMenu Principal\n");
		printf("\n\t\t1.Agregar Producto\n");
		printf("\n\t\t2. Visualizar Encuestas\n");
		printf("\n\t\t4. Eliminar La primer encuesta\n");
		printf("\n\t\t6. Mostrar cantidad de encuestas en lista\n");
		printf("\n\t\t0. Salir\n");
		scanf("%d", &res);
	}

}
void iniciarLista(tEncuesta *pLista) {
	pLista = NULL;
	printf("\nLista iniciada");
}

bool listaVacia(tEncuesta *pLista) {
	return (pLista == NULL);
}

void insertarPrimero() {
	tEncuesta *nuevoNodo;
	float imc;
	
	nuevoNodo = (tEncuesta *) malloc(sizeof(tEncuesta));

	printf("\nIngrese el Peso: ");
	scanf("%f", &nuevoNodo->persona.peso);
	fflush(stdin);
	printf("\nIngrese la altura (mts): ");
	scanf("%f", &nuevoNodo->persona.altura);
	fflush(stdin);
	printf("\nIngrese el codigo de sexo F.Femenino M.Masculino: ");
	scanf("%[^\n]s", &nuevoNodo->persona.codSexo);
	fflush(stdin);
	printf("\nIngrese el rango de edad 01. Menor de 15 años, 02. Entre 15 y 30 años, 03. Más de 30 años: ");
	scanf("%d", &nuevoNodo->persona.rangEdad);
	fflush(stdin);
	
	imc = calcularImc(nuevoNodo->persona.peso, nuevoNodo->persona.altura);

	if(imc < 20 || imc < 19) {
		strcpy(nuevoNodo->persona.imc, "Peso bajo");
	}else if(imc > 20 && imc < 25 || imc > 19 && imc < 24) {
		strcpy(nuevoNodo->persona.imc, "Peso Normal");
	}else if(imc > 25 || imc > 24) {
		strcpy(nuevoNodo->persona.imc, "Sobrepeso");
	}

	nuevoNodo->siguiente = NULL;

	lista = nuevoNodo;

	printf("\nAlumno Insertado");
}

void insertarAdelante() {
	tEncuesta *nuevoNodo;
	float imc;
	nuevoNodo = (tEncuesta *) malloc(sizeof(tEncuesta));

	printf("\nIngrese el Peso: ");
	scanf("%f", &nuevoNodo->persona.peso);
	fflush(stdin);
	printf("\nIngrese la altura (mts): ");
	scanf("%f", &nuevoNodo->persona.altura);
	fflush(stdin);
	printf("\nIngrese el codigo de sexo F.Femenino M.Masculino: ");
	scanf("%[^\n]s", &nuevoNodo->persona.codSexo);
	fflush(stdin);
	printf("\nIngrese el rango de edad 01. Menor de 15 edad, 02. Entre 15 y 30 edad, 03. Mas de 30 edad: ");
	scanf("%d", &nuevoNodo->persona.rangEdad);
	fflush(stdin);

	imc = calcularImc(nuevoNodo->persona.peso, nuevoNodo->persona.altura);

	if(imc < 20 || imc < 19) {
		 strcpy(nuevoNodo->persona.imc, "Peso bajo");
	}else if(imc > 20 && imc < 25 || imc > 19 && imc < 24) {
		strcpy(nuevoNodo->persona.imc, "Peso Normal");
	}else if(imc > 25 || imc > 24) {
		strcpy(nuevoNodo->persona.imc, "Sobrepeso");
	}
	
	nuevoNodo->siguiente = lista;

	lista = nuevoNodo;

	printf("\nEncuesta guardado");
}

void menuIngresar() {
	if(listaVacia(lista)) {
		insertarPrimero();
	}else{
		insertarAdelante();
	}
}

void eliminarPrimero() {
	tEncuesta *nodoSuprimir;

	nodoSuprimir = lista;

	lista = lista->siguiente;

	printf("\nElemento Eliminado");

	free(nodoSuprimir);

	nodoSuprimir = NULL;
}


int cantidadEncuestados(tEncuesta *pLista) {
	int cantEncuestados;
	tEncuesta *aux;
	aux = pLista;

	while(aux != NULL) {
			cantEncuestados++;
			aux = aux->siguiente;
	}
	return cantEncuestados;
}

float calcularImc(float pPeso, float pAltura) {
	float altCuadrado, imc;
	
	altCuadrado = pow(2,pAltura);
	
	imc = pPeso / altCuadrado;
	
	return imc;
}

void visualizarDatos(tEncuesta *pLista) {
	tEncuesta *aux;

	aux = pLista;

	if(listaVacia(aux)) {
		printf("\nNo hay elementos para mostrar");
	}else {
		while(aux != NULL) {
			printf("\nSexo: %s", aux->persona.codSexo);
			printf("\nImc: %s", aux->persona.imc);
			printf("\nRango Edad: %d", aux->persona.rangEdad);
			printf("\nAltura: %.2fmts", aux->persona.altura);
			printf("\nPeso: %.2fkg", aux->persona.peso);
			aux = aux->siguiente;
			printf("\n");
			printf("\n");
		}
	}
}
