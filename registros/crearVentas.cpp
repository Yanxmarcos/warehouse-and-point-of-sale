//escribir y leer un archivo
#include<iostream>
#include<string.h>
using namespace std;

struct Ventas {
	int num; //Orden de venta
	char fecha[11];
	int idProducto;
	int idEmpleado;
	char unidadVenta[20]; //Pack, unidad, kilogramo, etc
	int cantidad;
	float dinero; 
	char tipoPago[20];
	char titular[40]; //de la cuenta pago móvil
};
Ventas vent;

//GLOBALES
FILE* fv; //Creamos archivo
int lv = sizeof(struct Ventas); //Cantidad de almacenamiento en bytes

int main(){
	
	if((fv = fopen("Ventas.txt", "wt"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	fflush(stdin);
		
		vent.num = 1;
		strcpy(vent.fecha,"21/12/2022"); //En el programa se guarda automáticamente
		vent.idProducto = 2;
		vent.idEmpleado = 1;
		strcpy(vent.unidadVenta,"Lata 400g"); //Pack, unidad, kilogramo, etc
		vent.cantidad = 3;
		vent.dinero = 12;
		strcpy(vent.tipoPago,"Efectivo");
		strcpy(vent.titular,"NULL"); //de la cuenta pago móvil
		
		fwrite(&vent, lv, 1, fv);
		fclose(fv);
}