//escribir y leer un archivo
#include<iostream>
#include<string.h>
using namespace std;

struct Empleado {
	int id;
	char nombres[30];
	char apellidoPaterno[20];
	char apellidoMaterno[20];
	char dni[13];
	char nacimiento[11];
	char direccion[40];
	char telefono[10];
	char usuario[11];
	char password[11];
	char tipo_usuario[14];
	
	int numVentas;
	float dinero;
	char estado[2];
};
Empleado var;

//GLOBALES
FILE* fd; //Creamos archivo
int lr = sizeof(struct Empleado); //Cantidad de almacenamiento en bytes
string tipoUser;

int main(){
	
	if((fd = fopen("Empleados.txt", "wt"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
		fflush(stdin);
		var.id=1;
		strcpy(var.nombres,"Franco Jordano");
		strcpy(var.apellidoPaterno,"Rosales");
		strcpy(var.apellidoMaterno,"Verde");
		strcpy(var.dni,"65656565");
		strcpy(var.nacimiento, "10/11/1995");
		strcpy(var.direccion, "Mz A Lt 31 Antenor Orrego");
		strcpy(var.telefono, "123456789");
		strcpy(var.usuario, "FrancoJord");
		strcpy(var.password, "1234567890");
		strcpy(var.tipo_usuario, "Administrador");
		
		var.numVentas = 2;
		var.dinero = 5.0f;
		strcpy(var.estado, "s");
		
		fwrite(&var, lr, 1, fd);
		fclose(fd);
			
	
}