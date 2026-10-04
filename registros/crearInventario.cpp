#include<iostream>
#include<string.h>
using namespace std;

// ESTRUCTURA PRODUCTOS
struct Producto {
	int id;
	char nombre[20];
	char tipo[20];
	char marca[15];
	char unidadBase[20];
	float cantidad;
	float precio;
};
Producto prod;

// ARCHIVO INVENTARIO
FILE* fr;
int lf = sizeof(struct Producto);
int pos;

void s(){
	prod.id = 0;
	strcpy(prod.nombre,"                                           ");
	strcpy(prod.tipo,"                                            ");
	strcpy(prod.marca,"                                           ");
	strcpy(prod.unidadBase,"                                       ");
	prod.cantidad = 0;
	prod.precio = 0;
}





int main(){
	
	
	if((fr = fopen("Inventario.txt", "wt"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	fflush(stdin);
	prod.id = 1;
	strcpy(prod.nombre,"Aceite");
	strcpy(prod.tipo,"Abarrotes");
	strcpy(prod.marca,"Sao");
	strcpy(prod.unidadBase,"Botella 1L");
	prod.cantidad = 10;
	prod.precio = 9;
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	///////////////////////2///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 2;
	strcpy(prod.nombre,"Leche");
	strcpy(prod.tipo,"Lacteos");
	strcpy(prod.marca,"Gloria");
	strcpy(prod.unidadBase,"Lata 400g");
	prod.cantidad =20;
	prod.precio = 4;
	pos = (2 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	
	s();
	////////////////////////3///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 3;
	strcpy(prod.nombre,"Huevo Pardo");
	strcpy(prod.tipo,"Huevos");
	strcpy(prod.marca,"La Calera");
	strcpy(prod.unidadBase,"1 Unidad");
	prod.cantidad = 30;
	prod.precio = 0.8;
	pos = (3 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	////////////////////////4///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 4;
	strcpy(prod.nombre,"Yogurt");
	strcpy(prod.tipo,"Lacteos");
	strcpy(prod.marca,"Laive");
	strcpy(prod.unidadBase,"Botella 1Kg");
	prod.cantidad = 40;
	prod.precio = 11;
	pos = (4 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	////////////////////////5///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 5;
	strcpy(prod.nombre,"Gaseosa");
	strcpy(prod.tipo,"Bebidas");
	strcpy(prod.marca,"Coca Cola");
	strcpy(prod.unidadBase,"Botella 2L");
	prod.cantidad = 50;
	prod.precio = 6;
	pos = (5 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	////////////////////////6///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 6;
	strcpy(prod.nombre,"Agua");
	strcpy(prod.tipo,"Bebidas");
	strcpy(prod.marca,"San Luis");
	strcpy(prod.unidadBase,"Botella 625ml");
	prod.cantidad = 60;
	prod.precio = 2;
	pos = (6 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	////////////////////////7///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 7;
	strcpy(prod.nombre,"Escoba");
	strcpy(prod.tipo,"Limpieza");
	strcpy(prod.marca,"Virutex");
	strcpy(prod.unidadBase,"1 Unidad");
	prod.cantidad = 70;
	prod.precio = 8;
	pos = (7 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	s();
	////////////////////////8///////////////////////
	
	if((fr = fopen("Inventario.txt", "r+t"))==NULL){
		cout<<"No se puede abrir el archivo. "<<endl;
	}
	prod.id = 8;
	strcpy(prod.nombre,"Leche Condensada");
	strcpy(prod.tipo,"Lacteos");
	strcpy(prod.marca,"Nestle");
	strcpy(prod.unidadBase,"Lata 100g");
	prod.cantidad = 80;
	prod.precio = 7.5;
	pos = (8 - 1) * lf;
	fseek(fr, pos, 0);
	fwrite(&prod, lf, 1, fr);
	fclose(fr);
	
	
	
	
	
}