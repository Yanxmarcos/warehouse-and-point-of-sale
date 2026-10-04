#pragma once
#include <string>
#include <cstdio>
#include <stdlib.h>
using namespace std;

// ESTRUCTURA EMPLEADO
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

	int numVentas; //ventas
	float dinero; //cant dinero
	char estado[2]; //para eliminar después
};
Empleado var;

//GLOBALES
FILE* fd; //Creamos archivo
int lr = sizeof(struct Empleado); //Cantidad de almacenamiento en bytes
string tipoUser; int IDusuarioActual; //<- para registro de ventas


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
float SumaGlobal=0; //<- para registro de ventas
// ARCHIVO INVENTARIO
FILE* fr;
int lf = sizeof(struct Producto);
int pos;

//ESTRUCTURA VENTAS
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

//AUXILIAR
int aux_idprod[30];
float aux_cant[30];
int xyz = -1; 


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

		//ELEMENTOS PANTALLA LOGIN
	protected:

	private: System::Windows::Forms::Panel^ login;
	private: System::Windows::Forms::Label^ titlelogin;
	private: System::Windows::Forms::PictureBox^ logo;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ getpassword;

	private: System::Windows::Forms::Button^ buttonlogin;
	private: System::Windows::Forms::TextBox^ getusuario;
	private: System::Windows::Forms::Panel^ panel_main;

		   //ELEMENTOS PANTALLA MENU PRINCIPAL
	private: System::Windows::Forms::Panel^ panel_main2;
	private: System::Windows::Forms::Panel^ header;
	private: System::Windows::Forms::Label^ tittle_menu;

	protected:

	protected:



	private: System::Windows::Forms::Button^ button_menu;
	private: System::Windows::Forms::PictureBox^ img_user;

	private: System::Windows::Forms::Button^ menu_main;

	private: System::Windows::Forms::Label^ usuario;
	private: System::Windows::Forms::Panel^ panel_operaciones;
	private: System::Windows::Forms::LinkLabel^ lk_verempleados;


	private: System::Windows::Forms::LinkLabel^ lk_registroventas;
	private: System::Windows::Forms::LinkLabel^ lk_registroempleados;


	private: System::Windows::Forms::Button^ bttn_operaciones;
	private: System::Windows::Forms::Button^ bttn_salir;



	private: System::Windows::Forms::Button^ bttn_reportes;

	private: System::Windows::Forms::Button^ bttn_inventario;
	private: System::Windows::Forms::Panel^ panel_interfaces;
	private: System::Windows::Forms::Label^ mensaje_bienvenida;

		   //ELEMENTOS TIPO EMPLEADOS
	private: System::Windows::Forms::Panel^ panel_tipo_empleados;
	protected:

	private: System::Windows::Forms::CheckBox^ tipo_limpieza;
	protected:

	private: System::Windows::Forms::CheckBox^ tipo_seguridad;

	private: System::Windows::Forms::CheckBox^ tipo_inventario;

	private: System::Windows::Forms::CheckBox^ tipo_vendedor;

	private: System::Windows::Forms::CheckBox^ tipo_administrador;

	private: System::Windows::Forms::Label^ consejo_empleado;


	private: System::Windows::Forms::Label^ title_opc_empleado1;
	private: System::Windows::Forms::Label^ title_opc_empleado2;
	private: System::Windows::Forms::Button^ bttn_cancelar_1;


	private: System::Windows::Forms::Button^ bttn_sgte_1;

		   //ELEMENTOS REGISTRAR EMPLEADOS
	private: System::Windows::Forms::Panel^ panel_registrar_empleado;
	private: System::Windows::Forms::TextBox^ txt_reg_nombres;
	private: System::Windows::Forms::Label^ lbl_nombre;
	private: System::Windows::Forms::Label^ lbl_registro_empleados;
		   
	private: System::Windows::Forms::TextBox^ txt_reg_dni;
	private: System::Windows::Forms::Label^ lbl_dni;

	private: System::Windows::Forms::TextBox^ txt_reg_apellidomaterno;
	private: System::Windows::Forms::Label^ lbl_apellidomaterno;
	private: System::Windows::Forms::TextBox^ txt_reg_apellidopaterno;
	private: System::Windows::Forms::Label^ lbl_reg_apellidopaterno;
	private: System::Windows::Forms::DateTimePicker^ date_reg_fechanacimiento;

	private: System::Windows::Forms::Label^ lbl_fecha;
	private: System::Windows::Forms::Button^ btn_cancelar_regEmpleado;
	private: System::Windows::Forms::Button^ btn_guardar_regEmpleado;




	private: System::Windows::Forms::TextBox^ txt_reg_contra;

	private: System::Windows::Forms::Label^ lbl_contraseña;

	private: System::Windows::Forms::Label^ lbl_usuario;
	private: System::Windows::Forms::TextBox^ txt_reg_usuario;


	private: System::Windows::Forms::TextBox^ txt_reg_numeroTel;

	private: System::Windows::Forms::Label^ lbl_numero;

	private: System::Windows::Forms::TextBox^ txt_reg_domicilio;

	private: System::Windows::Forms::Label^ lbl_domicilio;

	//ELEMENTOS VER EMPLEADOS 
	private: System::Windows::Forms::Panel^ panel_verEmpleados;
	private: System::Windows::Forms::Label^ tittle_verEmpleados;
	private: System::Windows::Forms::DataGridView^ tabla_verEmpleados;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NOMBRES_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PATERNO_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MATERNO_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NACIMIENTO_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TELEFONO_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DOMICILIO_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TIPOUSER_tabla;


	//ELEMENTOS INVENTARIO
	private: System::Windows::Forms::Panel^ panel_Inventario;
	protected:
	private: System::Windows::Forms::GroupBox^ caja_addProd;
	private: System::Windows::Forms::Label^ id_prod;
	private: System::Windows::Forms::RadioButton^ select_modificar;
	private: System::Windows::Forms::RadioButton^ select_agregar;
	private: System::Windows::Forms::DataGridView^ tabla_Inventario;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PRODUCTO_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TPROD_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MARCA_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ UnidadBase_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CANTIDAD_tableInventario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Precio_tableInventario;
	private: System::Windows::Forms::Label^ tittle_Inventario;
	private: System::Windows::Forms::Button^ bttn_cancelar_inventario;
	private: System::Windows::Forms::Button^ bttn_confirmar_inventario;
	private: System::Windows::Forms::Label^ label_simbolo;
	private: System::Windows::Forms::TextBox^ get_precioprod;
	private: System::Windows::Forms::Label^ label_precioprod;
	private: System::Windows::Forms::TextBox^ get_cantidadprod;
	private: System::Windows::Forms::Label^ label_cantidad;
	private: System::Windows::Forms::ComboBox^ get_tipoprod;
	private: System::Windows::Forms::Label^ label_tipoprod;
	private: System::Windows::Forms::TextBox^ get_nombreprod;
	private: System::Windows::Forms::Label^ label_nameprod;
	private: System::Windows::Forms::ComboBox^ select_id;
	private: System::Windows::Forms::Button^ bttn_cargar;

		   
		   //ELEMENTOS REGISTRO DE VENTAS
	private: System::Windows::Forms::Panel^ panel_reg_ventas;
	private: System::Windows::Forms::Label^ lbl_reg_ventas;
	private: System::Windows::Forms::Button^ btn_cancelar_compra;



	private: System::Windows::Forms::Button^ btn_confirmar_compra;

	private: System::Windows::Forms::GroupBox^ groupBox_ventas;
	private: System::Windows::Forms::Button^ btn_agregar_a_lista;



	private: System::Windows::Forms::Label^ lbl_precio_producto;


	private: System::Windows::Forms::Label^ lbl_soles;

	private: System::Windows::Forms::Label^ lbl_nombre_precio;
	private: System::Windows::Forms::ComboBox^ cbox_tipo_pago;


	private: System::Windows::Forms::Label^ lbl_tipo_pag;
	private: System::Windows::Forms::TextBox^ txt_cant_prod;


	private: System::Windows::Forms::Label^ lbl_cant;

	private: System::Windows::Forms::Label^ lbl_sel_prod;
	private: System::Windows::Forms::ComboBox^ cbox_selec_categoria;
	private: System::Windows::Forms::DataGridView^ dataGridView_ventas;
	private: System::Windows::Forms::Label^ lbl_precioTotal;




	private: System::Windows::Forms::Label^ lbl_nombre_precioTotal;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ producto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ marca_dataGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tipo_unidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ precio;

	private: System::Windows::Forms::Label^ lbl_sel_producto2;
	private: System::Windows::Forms::ComboBox^ cbox_selec_producto;
	private: System::Windows::Forms::Label^ lbl_cantidad_actual;
	private: System::Windows::Forms::Label^ lbl_nombre_cantidad_actual;
	private: System::Windows::Forms::TextBox^ txt_titular_pago;
	private: System::Windows::Forms::Label^ lbl_titular_pago;

	private: System::Windows::Forms::TextBox^ txt_precio_semitotal;
	private: System::Windows::Forms::Label^ lbl_precio_semitotal;
	private: System::Windows::Forms::ComboBox^ cbox_unidadVenta;
	private: System::Windows::Forms::Label^ lbl_unidadVenta;
	private: System::Windows::Forms::ComboBox^ cbox_marca_modelo;
	private: System::Windows::Forms::Label^ lbl_marca_modelo;
	private: System::Windows::Forms::GroupBox^ groupBox_Stock;

	private: System::Windows::Forms::Label^ lbl_marca_modelo_stock;
	private: System::Windows::Forms::Label^ lbl_unidad_base_stock_si;

	private: System::Windows::Forms::Label^ lbl_unidad_base_stock;
	private: System::Windows::Forms::Label^ lbl_marca_modelo_stock_si;
	private: System::Windows::Forms::Button^ btn_ver_stock;
	private: System::Windows::Forms::Panel^ panel_borrar_stock;
	private: System::Windows::Forms::Label^ lbl_borrar_stock;

	



	//ELEMENTOS REPORTE POR EMPLEADO
	private: System::Windows::Forms::Panel^ panel_reporte_porEmpleado;
	private: System::Windows::Forms::Label^ lbl_titulo_reporte_porEmpleado;
	private: System::Windows::Forms::Label^ lbl_seleccion_id_porEmpleado;
	private: System::Windows::Forms::ComboBox^ cbox_sel_id_porEmpleado;
	private: System::Windows::Forms::DataGridView^ dataGridView_reporte_porEmpleado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_fechaConsulta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_nombres;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_apellidoP;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_apellidoM;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_dni;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_cantidad_ventas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ porEmpleado_cantidad_dinero;
	private: System::Windows::Forms::Label^ lbl_ventas_respectoMesAnterior_porEmpleado;
	private: System::Windows::Forms::Label^ lbl_nombre_ventas_respectoMesAnterior_porEmpleado;
	private: System::Windows::Forms::DataGridView^ dataGridView_reporte_porEmpleado_ventas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_fechaDeVenta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_producto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_marca;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_tipo_unidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_cantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ventas_porEmpleado_pago;
	private: System::Windows::Forms::Label^ lbl_productos_vendidos_porEmpleado;



	protected:




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			//LOGIN PRINCIPAL PANTALLA
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->login = (gcnew System::Windows::Forms::Panel());
			this->buttonlogin = (gcnew System::Windows::Forms::Button());
			this->getusuario = (gcnew System::Windows::Forms::TextBox());
			this->getpassword = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->titlelogin = (gcnew System::Windows::Forms::Label());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->panel_main = (gcnew System::Windows::Forms::Panel());
			this->login->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
			this->panel_main->SuspendLayout();
			this->SuspendLayout();
			// 
			// login
			// 
			this->login->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->login->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->login->Controls->Add(this->buttonlogin);
			this->login->Controls->Add(this->getusuario);
			this->login->Controls->Add(this->getpassword);
			this->login->Controls->Add(this->label2);
			this->login->Controls->Add(this->label1);
			this->login->Controls->Add(this->titlelogin);
			this->login->Controls->Add(this->logo);
			this->login->Location = System::Drawing::Point(285, 98);
			this->login->Name = L"login";
			this->login->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->login->Size = System::Drawing::Size(351, 274);
			this->login->TabIndex = 1;
			// 
			// buttonlogin
			// 
			this->buttonlogin->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 10));
			this->buttonlogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonlogin->Location = System::Drawing::Point(182, 235);
			this->buttonlogin->Name = L"buttonlogin";
			this->buttonlogin->Size = System::Drawing::Size(131, 31);
			this->buttonlogin->TabIndex = 2;
			this->buttonlogin->Text = L"Iniciar sesión";
			this->buttonlogin->UseVisualStyleBackColor = true;
			this->buttonlogin->Click += gcnew System::EventHandler(this, &Form1::buttonlogin_Click);
			// 
			// getusuario
			// 
			this->getusuario->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 13));
			this->getusuario->Location = System::Drawing::Point(36, 133);
			this->getusuario->Name = L"getusuario";
			this->getusuario->Size = System::Drawing::Size(277, 28);
			this->getusuario->TabIndex = 0;
			// 
			// getpassword
			// 
			this->getpassword->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 13));
			this->getpassword->Location = System::Drawing::Point(36, 198);
			this->getpassword->Name = L"getpassword";
			this->getpassword->Size = System::Drawing::Size(277, 28);
			this->getpassword->TabIndex = 0;
			this->getpassword->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(21, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Contraseña:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(21, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Usuario:";
			// 
			// titlelogin
			// 
			this->titlelogin->AutoSize = true;
			this->titlelogin->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titlelogin->Location = System::Drawing::Point(3, 21);
			this->titlelogin->Name = L"titlelogin";
			this->titlelogin->Size = System::Drawing::Size(271, 35);
			this->titlelogin->TabIndex = 0;
			this->titlelogin->Text = L"INICIO DE SESIÓN";
			// 
			// logo
			// 
			//this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Image = Image::FromFile(L"./img/logo.png");
			this->logo->Location = System::Drawing::Point(258, -1);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(92, 74);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logo->TabIndex = 1;
			this->logo->TabStop = false;
			// 
			// panel_main
			// 
			//this->panel_main->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_main.BackgroundImage")));
			this->panel_main->BackgroundImage = Image::FromFile(L"./img/fondo.jpg");
			this->panel_main->Controls->Add(this->login);
			this->panel_main->Location = System::Drawing::Point(0, -1);
			this->panel_main->Name = L"panel_main";
			this->panel_main->Size = System::Drawing::Size(943, 511);
			this->panel_main->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 508);
			this->Controls->Add(this->panel_main);
			this->MaximumSize = System::Drawing::Size(957, 547);
			this->MinimumSize = System::Drawing::Size(957, 547);
			this->Name = L"Form1";
			this->Text = L"La Bodega de Don Wlan";
			this->login->ResumeLayout(false);
			this->login->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->panel_main->ResumeLayout(false);
			this->ResumeLayout(false);



			//MENU MAIN PANTALLA
			this->panel_main2 = (gcnew System::Windows::Forms::Panel());
			this->panel_interfaces = (gcnew System::Windows::Forms::Panel());
			this->mensaje_bienvenida = (gcnew System::Windows::Forms::Label());
			this->bttn_salir = (gcnew System::Windows::Forms::Button());
			this->bttn_reportes = (gcnew System::Windows::Forms::Button());
			this->bttn_inventario = (gcnew System::Windows::Forms::Button());
			this->panel_operaciones = (gcnew System::Windows::Forms::Panel());
			this->lk_verempleados = (gcnew System::Windows::Forms::LinkLabel());
			this->lk_registroventas = (gcnew System::Windows::Forms::LinkLabel());
			this->lk_registroempleados = (gcnew System::Windows::Forms::LinkLabel());
			this->bttn_operaciones = (gcnew System::Windows::Forms::Button());
			this->menu_main = (gcnew System::Windows::Forms::Button());
			this->header = (gcnew System::Windows::Forms::Panel());
			this->usuario = (gcnew System::Windows::Forms::Label());
			this->img_user = (gcnew System::Windows::Forms::PictureBox());
			this->button_menu = (gcnew System::Windows::Forms::Button());
			this->tittle_menu = (gcnew System::Windows::Forms::Label());
			this->panel_main2->SuspendLayout();
			this->panel_interfaces->SuspendLayout();
			this->panel_operaciones->SuspendLayout();
			this->header->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_user))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_main2
			// 
			//this->panel_main2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_main2.BackgroundImage")));
			this->panel_main2->BackgroundImage = Image::FromFile(L"./img/fondo.jpg");
			this->panel_main2->Controls->Add(this->panel_interfaces);
			this->panel_main2->Controls->Add(this->bttn_salir);
			this->panel_main2->Controls->Add(this->bttn_reportes);
			this->panel_main2->Controls->Add(this->bttn_inventario);
			this->panel_main2->Controls->Add(this->panel_operaciones);
			this->panel_main2->Controls->Add(this->bttn_operaciones);
			this->panel_main2->Controls->Add(this->menu_main);
			this->panel_main2->Controls->Add(this->header);
			this->panel_main2->Location = System::Drawing::Point(0, 0);
			this->panel_main2->Name = L"panel_main2";
			this->panel_main2->Size = System::Drawing::Size(945, 514);
			this->panel_main2->TabIndex = 0;
			// 
			// panel_interfaces
			// 
			this->panel_interfaces->Controls->Add(this->mensaje_bienvenida);
			this->panel_interfaces->Location = System::Drawing::Point(262, 85);
			this->panel_interfaces->Name = L"panel_interfaces";
			this->panel_interfaces->Size = System::Drawing::Size(672, 420);
			this->panel_interfaces->TabIndex = 14;
			// 
			// mensaje_bienvenida
			// 
			this->mensaje_bienvenida->AutoSize = true;
			this->mensaje_bienvenida->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiLight", 12.25F));
			this->mensaje_bienvenida->Location = System::Drawing::Point(57, 159);
			this->mensaje_bienvenida->Name = L"mensaje_bienvenida";
			this->mensaje_bienvenida->Size = System::Drawing::Size(550, 44);
			this->mensaje_bienvenida->TabIndex = 0;
			// 
			// bttn_salir
			// 
			this->bttn_salir->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 16.25F, System::Drawing::FontStyle::Bold));
			this->bttn_salir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bttn_salir->Location = System::Drawing::Point(3, 460);
			this->bttn_salir->Name = L"bttn_salir";
			this->bttn_salir->Size = System::Drawing::Size(248, 45);
			this->bttn_salir->TabIndex = 13;
			this->bttn_salir->Text = L"Salir";
			this->bttn_salir->UseVisualStyleBackColor = true;
			this->bttn_salir->Click += gcnew System::EventHandler(this, &Form1::bttn_salir_Click);
			// 
			// bttn_reportes
			// 
			this->bttn_reportes->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 16.25F, System::Drawing::FontStyle::Bold));
			this->bttn_reportes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bttn_reportes->Location = System::Drawing::Point(3, 339);
			this->bttn_reportes->Name = L"bttn_reportes";
			this->bttn_reportes->Size = System::Drawing::Size(248, 45);
			this->bttn_reportes->TabIndex = 11;
			this->bttn_reportes->Text = L"Reportes";
			this->bttn_reportes->UseVisualStyleBackColor = true;
			this->bttn_reportes->Click += gcnew System::EventHandler(this, &Form1::bttn_reportes_Click);
			// 
			// bttn_inventario
			// 
			this->bttn_inventario->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 16.25F, System::Drawing::FontStyle::Bold));
			this->bttn_inventario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bttn_inventario->Location = System::Drawing::Point(3, 284);
			this->bttn_inventario->Name = L"bttn_inventario";
			this->bttn_inventario->Size = System::Drawing::Size(248, 45);
			this->bttn_inventario->TabIndex = 10;
			this->bttn_inventario->Text = L"Inventario";
			this->bttn_inventario->UseVisualStyleBackColor = true;
			this->bttn_inventario->Click += gcnew System::EventHandler(this, &Form1::bttn_inventario_Click);
			// 
			// panel_operaciones
			// 
			this->panel_operaciones->Controls->Add(this->lk_verempleados);
			this->panel_operaciones->Controls->Add(this->lk_registroventas);
			this->panel_operaciones->Controls->Add(this->lk_registroempleados);
			this->panel_operaciones->Location = System::Drawing::Point(10, 182);
			this->panel_operaciones->Name = L"panel_operaciones";
			this->panel_operaciones->Size = System::Drawing::Size(235, 88);
			this->panel_operaciones->TabIndex = 9;
			// 
			// lk_verempleados
			// 
			this->lk_verempleados->AutoSize = true;
			this->lk_verempleados->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lk_verempleados->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 9.75F));
			this->lk_verempleados->LinkColor = System::Drawing::Color::Black;
			this->lk_verempleados->Location = System::Drawing::Point(36, 62);
			this->lk_verempleados->Name = L"lk_verempleados";
			this->lk_verempleados->Size = System::Drawing::Size(112, 17);
			this->lk_verempleados->TabIndex = 3;
			this->lk_verempleados->TabStop = true;
			this->lk_verempleados->Text = L"Ver empleados";
			this->lk_verempleados->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::lk_verempleados_LinkClicked);
			// 
			// lk_registroventas
			// 
			this->lk_registroventas->AutoSize = true;
			this->lk_registroventas->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lk_registroventas->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lk_registroventas->LinkColor = System::Drawing::Color::Black;
			this->lk_registroventas->Location = System::Drawing::Point(36, 5);
			this->lk_registroventas->Name = L"lk_registroventas";
			this->lk_registroventas->Size = System::Drawing::Size(136, 17);
			this->lk_registroventas->TabIndex = 2;
			this->lk_registroventas->TabStop = true;
			this->lk_registroventas->Text = L"Registrar ventas";
			this->lk_registroventas->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::lk_registroventas_LinkClicked);
			// 
			// lk_registroempleados
			// 
			this->lk_registroempleados->AutoSize = true;
			this->lk_registroempleados->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lk_registroempleados->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 9.75F));
			this->lk_registroempleados->LinkColor = System::Drawing::Color::Black;
			this->lk_registroempleados->Location = System::Drawing::Point(36, 33);
			this->lk_registroempleados->Name = L"lk_registroempleados";
			this->lk_registroempleados->Size = System::Drawing::Size(160, 17);
			this->lk_registroempleados->TabIndex = 1;
			this->lk_registroempleados->TabStop = true;
			this->lk_registroempleados->Text = L"Registrar empleados";
			this->lk_registroempleados->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::lk_registroempleados_LinkClicked);
			// 
			// bttn_operaciones
			// 
			this->bttn_operaciones->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 16.25F, System::Drawing::FontStyle::Bold));
			this->bttn_operaciones->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bttn_operaciones->Location = System::Drawing::Point(3, 138);
			this->bttn_operaciones->Name = L"bttn_operaciones";
			this->bttn_operaciones->Size = System::Drawing::Size(248, 45);
			this->bttn_operaciones->TabIndex = 8;
			this->bttn_operaciones->Text = L"Operaciones";
			this->bttn_operaciones->UseVisualStyleBackColor = true;
			// 
			// menu_main
			// 
			this->menu_main->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 16.25F, System::Drawing::FontStyle::Bold));
			this->menu_main->Cursor = System::Windows::Forms::Cursors::Hand;
			this->menu_main->Location = System::Drawing::Point(3, 85);
			this->menu_main->Name = L"menu_main";
			this->menu_main->Size = System::Drawing::Size(248, 45);
			this->menu_main->TabIndex = 7;
			this->menu_main->Text = L"Menú Principal";
			this->menu_main->UseVisualStyleBackColor = true;
			this->menu_main->Click += gcnew System::EventHandler(this, &Form1::menu_main_Click);
			// 
			// header
			// 
			this->header->BackColor = System::Drawing::Color::DarkCyan;
			this->header->Controls->Add(this->usuario);
			this->header->Controls->Add(this->img_user);
			this->header->Controls->Add(this->button_menu);
			this->header->Controls->Add(this->tittle_menu);
			this->header->Location = System::Drawing::Point(3, 3);
			this->header->Name = L"header";
			this->header->Size = System::Drawing::Size(936, 74);
			this->header->TabIndex = 0;
			// 
			// usuario
			// 
			this->usuario->AutoSize = true;
			this->usuario->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usuario->Location = System::Drawing::Point(807, 25);
			this->usuario->Name = L"usuario";
			this->usuario->Size = System::Drawing::Size(55, 21);
			this->usuario->TabIndex = 4;

			// 
			// img_user
			// 
			//this->img_user->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"img_user.Image")));
			this->img_user->Image = Image::FromFile(L"./img/usuario.png");
			this->img_user->Location = System::Drawing::Point(741, 5);
			this->img_user->Name = L"img_user";
			this->img_user->Size = System::Drawing::Size(63, 63);
			this->img_user->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->img_user->TabIndex = 3;
			this->img_user->TabStop = false;
			// 
			// button_menu
			// 
			this->button_menu->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button_menu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_menu->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_menu->ForeColor = System::Drawing::SystemColors::ControlText;
			//this->button_menu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_menu.Image")));
			this->button_menu->Image = Image::FromFile(L"./img/casa.png");
			this->button_menu->Location = System::Drawing::Point(29, 3);
			this->button_menu->Name = L"button_menu";
			this->button_menu->Size = System::Drawing::Size(87, 68);
			this->button_menu->TabIndex = 2;
			this->button_menu->UseVisualStyleBackColor = false;
			// 
			// tittle_menu
			// 
			this->tittle_menu->AutoSize = true;
			this->tittle_menu->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tittle_menu->Location = System::Drawing::Point(298, 13);
			this->tittle_menu->Name = L"tittle_menu";
			this->tittle_menu->Size = System::Drawing::Size(255, 39);
			this->tittle_menu->TabIndex = 1;
			this->tittle_menu->Text = L"MENÚ PRINCIPAL";


			//
			//TIPOS DE EMPLEADOS
			//
			this->panel_tipo_empleados = (gcnew System::Windows::Forms::Panel());
			this->bttn_cancelar_1 = (gcnew System::Windows::Forms::Button());
			this->bttn_sgte_1 = (gcnew System::Windows::Forms::Button());
			this->consejo_empleado = (gcnew System::Windows::Forms::Label());
			this->title_opc_empleado1 = (gcnew System::Windows::Forms::Label());
			this->title_opc_empleado2 = (gcnew System::Windows::Forms::Label());
			this->tipo_limpieza = (gcnew System::Windows::Forms::CheckBox());
			this->tipo_seguridad = (gcnew System::Windows::Forms::CheckBox());
			this->tipo_inventario = (gcnew System::Windows::Forms::CheckBox());
			this->tipo_vendedor = (gcnew System::Windows::Forms::CheckBox());
			this->tipo_administrador = (gcnew System::Windows::Forms::CheckBox());
			this->panel_tipo_empleados->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_tipo_empleados
			// 
			this->panel_tipo_empleados->Controls->Add(this->bttn_cancelar_1);
			this->panel_tipo_empleados->Controls->Add(this->bttn_sgte_1);
			this->panel_tipo_empleados->Controls->Add(this->consejo_empleado);
			this->panel_tipo_empleados->Controls->Add(this->title_opc_empleado1);
			this->panel_tipo_empleados->Controls->Add(this->title_opc_empleado2);
			this->panel_tipo_empleados->Controls->Add(this->tipo_limpieza);
			this->panel_tipo_empleados->Controls->Add(this->tipo_seguridad);
			this->panel_tipo_empleados->Controls->Add(this->tipo_inventario);
			this->panel_tipo_empleados->Controls->Add(this->tipo_vendedor);
			this->panel_tipo_empleados->Controls->Add(this->tipo_administrador);
			this->panel_tipo_empleados->Location = System::Drawing::Point(0, 0);
			this->panel_tipo_empleados->Name = L"panel_tipo_empleados";
			this->panel_tipo_empleados->Size = System::Drawing::Size(675, 420);
			this->panel_tipo_empleados->TabIndex = 0;
			// 
			// bttn_cancelar_1
			// 
			this->bttn_cancelar_1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bttn_cancelar_1->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_cancelar_1->Location = System::Drawing::Point(526, 345);
			this->bttn_cancelar_1->Name = L"bttn_cancelar_1";
			this->bttn_cancelar_1->Size = System::Drawing::Size(121, 36);
			this->bttn_cancelar_1->TabIndex = 9;
			this->bttn_cancelar_1->Text = L"CANCELAR";
			this->bttn_cancelar_1->UseVisualStyleBackColor = false;
			this->bttn_cancelar_1->Click += gcnew System::EventHandler(this, &Form1::bttn_cancelar_1_Click);
			// 
			// bttn_sgte_1
			// 
			this->bttn_sgte_1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bttn_sgte_1->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_sgte_1->Location = System::Drawing::Point(399, 345);
			this->bttn_sgte_1->Name = L"bttn_sgte_1";
			this->bttn_sgte_1->Size = System::Drawing::Size(121, 36);
			this->bttn_sgte_1->TabIndex = 7;
			this->bttn_sgte_1->Text = L"SIGUIENTE";
			this->bttn_sgte_1->UseVisualStyleBackColor = false;
			this->bttn_sgte_1->Click += gcnew System::EventHandler(this, &Form1::bttn_sgte_1_Click);
			// 
			// consejo_empleado
			// 
			this->consejo_empleado->AutoSize = true;
			this->consejo_empleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->consejo_empleado->Location = System::Drawing::Point(268, 107);
			this->consejo_empleado->Name = L"consejo_empleado";
			this->consejo_empleado->Size = System::Drawing::Size(151, 15);
			this->consejo_empleado->TabIndex = 6;
			this->consejo_empleado->Text = L"(Solo marque una opción)";
			// 
			// title_opc_empleado1
			// 
			this->title_opc_empleado1->AutoSize = true;
			this->title_opc_empleado1->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 20, System::Drawing::FontStyle::Bold));
			this->title_opc_empleado1->Location = System::Drawing::Point(110, 43);
			this->title_opc_empleado1->Name = L"title_opc_empleado1";
			this->title_opc_empleado1->Size = System::Drawing::Size(479, 35);
			this->title_opc_empleado1->TabIndex = 5;
			this->title_opc_empleado1->Text = L"SELECCIONE EL TIPO DE USUARIO";
			// 
			// title_opc_empleado2
			// 
			this->title_opc_empleado2->AutoSize = true;
			this->title_opc_empleado2->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 20, System::Drawing::FontStyle::Bold));
			this->title_opc_empleado2->Location = System::Drawing::Point(251, 78);
			this->title_opc_empleado2->Name = L"title_opc_empleado2";
			this->title_opc_empleado2->Size = System::Drawing::Size(191, 35);
			this->title_opc_empleado2->TabIndex = 10;
			this->title_opc_empleado2->Text = L"A REGISTRAR";
			// 
			// tipo_limpieza
			// 
			this->tipo_limpieza->AutoSize = true;
			this->tipo_limpieza->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F));
			this->tipo_limpieza->Location = System::Drawing::Point(271, 289);
			this->tipo_limpieza->Name = L"tipo_limpieza";
			this->tipo_limpieza->Size = System::Drawing::Size(100, 24);
			this->tipo_limpieza->TabIndex = 4;
			this->tipo_limpieza->Text = L"Limpieza";
			this->tipo_limpieza->UseVisualStyleBackColor = true;
			// 
			// tipo_seguridad
			// 
			this->tipo_seguridad->AutoSize = true;
			this->tipo_seguridad->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F));
			this->tipo_seguridad->Location = System::Drawing::Point(271, 259);
			this->tipo_seguridad->Name = L"tipo_seguridad";
			this->tipo_seguridad->Size = System::Drawing::Size(109, 24);
			this->tipo_seguridad->TabIndex = 3;
			this->tipo_seguridad->Text = L"Seguridad";
			this->tipo_seguridad->UseVisualStyleBackColor = true;
			// 
			// tipo_inventario
			// 
			this->tipo_inventario->AutoSize = true;
			this->tipo_inventario->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F));
			this->tipo_inventario->Location = System::Drawing::Point(271, 229);
			this->tipo_inventario->Name = L"tipo_inventario";
			this->tipo_inventario->Size = System::Drawing::Size(118, 24);
			this->tipo_inventario->TabIndex = 2;
			this->tipo_inventario->Text = L"Inventario";
			this->tipo_inventario->UseVisualStyleBackColor = true;
			// 
			// tipo_vendedor
			// 
			this->tipo_vendedor->AutoSize = true;
			this->tipo_vendedor->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F));
			this->tipo_vendedor->Location = System::Drawing::Point(271, 199);
			this->tipo_vendedor->Name = L"tipo_vendedor";
			this->tipo_vendedor->Size = System::Drawing::Size(100, 24);
			this->tipo_vendedor->TabIndex = 1;
			this->tipo_vendedor->Text = L"Vendedor";
			this->tipo_vendedor->UseVisualStyleBackColor = true;
			// 
			// tipo_administrador
			// 
			this->tipo_administrador->AutoSize = true;
			this->tipo_administrador->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tipo_administrador->Location = System::Drawing::Point(271, 169);
			this->tipo_administrador->Name = L"tipo_administrador";
			this->tipo_administrador->Size = System::Drawing::Size(145, 24);
			this->tipo_administrador->TabIndex = 0;
			this->tipo_administrador->Text = L"Administrador";
			this->tipo_administrador->UseVisualStyleBackColor = true;


			//
			//REGISTRO DE EMPLEADOS
			//
			this->panel_registrar_empleado = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar_regEmpleado = (gcnew System::Windows::Forms::Button());
			this->btn_guardar_regEmpleado = (gcnew System::Windows::Forms::Button());
			this->txt_reg_contra = (gcnew System::Windows::Forms::TextBox());
			this->lbl_contraseña = (gcnew System::Windows::Forms::Label());
			this->lbl_usuario = (gcnew System::Windows::Forms::Label());
			this->txt_reg_usuario = (gcnew System::Windows::Forms::TextBox());
			this->txt_reg_numeroTel = (gcnew System::Windows::Forms::TextBox());
			this->lbl_numero = (gcnew System::Windows::Forms::Label());
			this->txt_reg_domicilio = (gcnew System::Windows::Forms::TextBox());
			this->lbl_domicilio = (gcnew System::Windows::Forms::Label());
			this->date_reg_fechanacimiento = (gcnew System::Windows::Forms::DateTimePicker());
			this->lbl_fecha = (gcnew System::Windows::Forms::Label());
			this->lbl_dni = (gcnew System::Windows::Forms::Label());
			this->txt_reg_dni = (gcnew System::Windows::Forms::TextBox());
			this->txt_reg_apellidomaterno = (gcnew System::Windows::Forms::TextBox());
			this->lbl_apellidomaterno = (gcnew System::Windows::Forms::Label());
			this->txt_reg_apellidopaterno = (gcnew System::Windows::Forms::TextBox());
			this->lbl_reg_apellidopaterno = (gcnew System::Windows::Forms::Label());
			this->txt_reg_nombres = (gcnew System::Windows::Forms::TextBox());
			this->lbl_nombre = (gcnew System::Windows::Forms::Label());
			this->lbl_registro_empleados = (gcnew System::Windows::Forms::Label());
			// 
			// panel_registrar_empleado
			// 
			this->panel_registrar_empleado->Controls->Add(this->btn_cancelar_regEmpleado);
			this->panel_registrar_empleado->Controls->Add(this->btn_guardar_regEmpleado);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_contra);
			this->panel_registrar_empleado->Controls->Add(this->lbl_contraseña);
			this->panel_registrar_empleado->Controls->Add(this->lbl_usuario);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_usuario);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_numeroTel);
			this->panel_registrar_empleado->Controls->Add(this->lbl_numero);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_domicilio);
			this->panel_registrar_empleado->Controls->Add(this->lbl_domicilio);
			this->panel_registrar_empleado->Controls->Add(this->date_reg_fechanacimiento);
			this->panel_registrar_empleado->Controls->Add(this->lbl_fecha);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_dni);
			this->panel_registrar_empleado->Controls->Add(this->lbl_dni);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_apellidomaterno);
			this->panel_registrar_empleado->Controls->Add(this->lbl_apellidomaterno);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_apellidopaterno);
			this->panel_registrar_empleado->Controls->Add(this->lbl_reg_apellidopaterno);
			this->panel_registrar_empleado->Controls->Add(this->txt_reg_nombres);
			this->panel_registrar_empleado->Controls->Add(this->lbl_nombre);
			this->panel_registrar_empleado->Controls->Add(this->lbl_registro_empleados);
			this->panel_registrar_empleado->Location = System::Drawing::Point(0, 0);
			this->panel_registrar_empleado->Name = L"panel_registrar_empleado";
			this->panel_registrar_empleado->Size = System::Drawing::Size(672, 420);
			this->panel_registrar_empleado->TabIndex = 15;
			// 
			// btn_cancelar_regEmpleado
			// 
			this->btn_cancelar_regEmpleado->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_cancelar_regEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancelar_regEmpleado->Location = System::Drawing::Point(498, 333);
			this->btn_cancelar_regEmpleado->Name = L"btn_cancelar_regEmpleado";
			this->btn_cancelar_regEmpleado->Size = System::Drawing::Size(120, 43);
			this->btn_cancelar_regEmpleado->TabIndex = 21;
			this->btn_cancelar_regEmpleado->Text = L"CANCELAR";
			this->btn_cancelar_regEmpleado->UseVisualStyleBackColor = false;
			this->btn_cancelar_regEmpleado->Click += gcnew System::EventHandler(this, &Form1::btn_cancelar_regEmpleado_Click);
			// 
			// btn_guardar_regEmpleado
			// 
			this->btn_guardar_regEmpleado->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_guardar_regEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_guardar_regEmpleado->Location = System::Drawing::Point(360, 333);
			this->btn_guardar_regEmpleado->Name = L"btn_guardar_regEmpleado";
			this->btn_guardar_regEmpleado->Size = System::Drawing::Size(120, 43);
			this->btn_guardar_regEmpleado->TabIndex = 20;
			this->btn_guardar_regEmpleado->Text = L"GUARDAR";
			this->btn_guardar_regEmpleado->UseVisualStyleBackColor = false;
			this->btn_guardar_regEmpleado->Click += gcnew System::EventHandler(this, &Form1::btn_guardar_regEmpleado_Click);
			// 
			// txt_reg_contra
			// 
			this->txt_reg_contra->Location = System::Drawing::Point(379, 267);
			this->txt_reg_contra->Name = L"txt_reg_contra";
			this->txt_reg_contra->Size = System::Drawing::Size(228, 20);
			this->txt_reg_contra->TabIndex = 19;
			this->txt_reg_contra->UseSystemPasswordChar = true;
			// 
			// lbl_contraseña
			// 
			this->lbl_contraseña->AutoSize = true;
			this->lbl_contraseña->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_contraseña->Location = System::Drawing::Point(353, 234);
			this->lbl_contraseña->Name = L"lbl_contraseña";
			this->lbl_contraseña->Size = System::Drawing::Size(109, 21);
			this->lbl_contraseña->TabIndex = 18;
			this->lbl_contraseña->Text = L"Contraseña:";
			// 
			// lbl_usuario
			// 
			this->lbl_usuario->AutoSize = true;
			this->lbl_usuario->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_usuario->Location = System::Drawing::Point(353, 167);
			this->lbl_usuario->Name = L"lbl_usuario";
			this->lbl_usuario->Size = System::Drawing::Size(82, 21);
			this->lbl_usuario->TabIndex = 17;
			this->lbl_usuario->Text = L"Usuario:";
			// 
			// txt_reg_usuario
			// 
			this->txt_reg_usuario->Location = System::Drawing::Point(379, 201);
			this->txt_reg_usuario->Name = L"txt_reg_usuario";
			this->txt_reg_usuario->Size = System::Drawing::Size(228, 20);
			this->txt_reg_usuario->TabIndex = 16;
			// 
			// txt_reg_numeroTel
			// 
			this->txt_reg_numeroTel->Location = System::Drawing::Point(379, 137);
			this->txt_reg_numeroTel->Name = L"txt_reg_numeroTel";
			this->txt_reg_numeroTel->Size = System::Drawing::Size(228, 20);
			this->txt_reg_numeroTel->TabIndex = 15;
			// 
			// lbl_numero
			// 
			this->lbl_numero->AutoSize = true;
			this->lbl_numero->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numero->Location = System::Drawing::Point(353, 106);
			this->lbl_numero->Name = L"lbl_numero";
			this->lbl_numero->Size = System::Drawing::Size(181, 21);
			this->lbl_numero->TabIndex = 14;
			this->lbl_numero->Text = L"Número de teléfono:";
			// 
			// txt_reg_domicilio
			// 
			this->txt_reg_domicilio->Location = System::Drawing::Point(379, 74);
			this->txt_reg_domicilio->Name = L"txt_reg_domicilio";
			this->txt_reg_domicilio->Size = System::Drawing::Size(228, 20);
			this->txt_reg_domicilio->TabIndex = 13;
			// 
			// lbl_domicilio
			// 
			this->lbl_domicilio->AutoSize = true;
			this->lbl_domicilio->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_domicilio->Location = System::Drawing::Point(353, 45);
			this->lbl_domicilio->Name = L"lbl_domicilio";
			this->lbl_domicilio->Size = System::Drawing::Size(100, 21);
			this->lbl_domicilio->TabIndex = 12;
			this->lbl_domicilio->Text = L"Domicilio:";
			// 
			// date_reg_fechanacimiento
			// 
			this->date_reg_fechanacimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->date_reg_fechanacimiento->Location = System::Drawing::Point(46, 341);
			this->date_reg_fechanacimiento->Name = L"date_reg_fechanacimiento";
			this->date_reg_fechanacimiento->Size = System::Drawing::Size(127, 20);
			this->date_reg_fechanacimiento->TabIndex = 11;
			// 
			// lbl_fecha
			// 
			this->lbl_fecha->AutoSize = true;
			this->lbl_fecha->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fecha->Location = System::Drawing::Point(19, 305);
			this->lbl_fecha->Name = L"lbl_fecha";
			this->lbl_fecha->Size = System::Drawing::Size(190, 21);
			this->lbl_fecha->TabIndex = 9;
			this->lbl_fecha->Text = L"Fecha de nacimiento:";
			// 
			// lbl_dni
			// 
			this->lbl_dni->AutoSize = true;
			this->lbl_dni->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dni->Location = System::Drawing::Point(19, 234);
			this->lbl_dni->Name = L"lbl_dni";
			this->lbl_dni->Size = System::Drawing::Size(46, 21);
			this->lbl_dni->TabIndex = 22;
			this->lbl_dni->Text = L"DNI:";
			// 
			// txt_reg_dni
			// 
			this->txt_reg_dni->Location = System::Drawing::Point(46, 267);
			this->txt_reg_dni->Name = L"txt_reg_dni";
			this->txt_reg_dni->Size = System::Drawing::Size(198, 20);
			this->txt_reg_dni->TabIndex = 23;
			// 
			// txt_reg_apellidomaterno
			// 
			this->txt_reg_apellidomaterno->Location = System::Drawing::Point(46, 203);
			this->txt_reg_apellidomaterno->Name = L"txt_reg_apellidomaterno";
			this->txt_reg_apellidomaterno->Size = System::Drawing::Size(198, 20);
			this->txt_reg_apellidomaterno->TabIndex = 6;
			// 
			// lbl_apellidomaterno
			// 
			this->lbl_apellidomaterno->AutoSize = true;
			this->lbl_apellidomaterno->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_apellidomaterno->Location = System::Drawing::Point(19, 168);
			this->lbl_apellidomaterno->Name = L"lbl_apellidomaterno";
			this->lbl_apellidomaterno->Size = System::Drawing::Size(163, 21);
			this->lbl_apellidomaterno->TabIndex = 5;
			this->lbl_apellidomaterno->Text = L"Apellido Materno:";
			// 
			// txt_reg_apellidopaterno
			// 
			this->txt_reg_apellidopaterno->Location = System::Drawing::Point(46, 136);
			this->txt_reg_apellidopaterno->Name = L"txt_reg_apellidopaterno";
			this->txt_reg_apellidopaterno->Size = System::Drawing::Size(198, 20);
			this->txt_reg_apellidopaterno->TabIndex = 4;
			// 
			// lbl_reg_apellidopaterno
			// 
			this->lbl_reg_apellidopaterno->AutoSize = true;
			this->lbl_reg_apellidopaterno->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_reg_apellidopaterno->Location = System::Drawing::Point(19, 106);
			this->lbl_reg_apellidopaterno->Name = L"lbl_reg_apellidopaterno";
			this->lbl_reg_apellidopaterno->Size = System::Drawing::Size(163, 21);
			this->lbl_reg_apellidopaterno->TabIndex = 3;
			this->lbl_reg_apellidopaterno->Text = L"Apellido Paterno:";
			// 
			// txt_reg_nombres
			// 
			this->txt_reg_nombres->Location = System::Drawing::Point(46, 75);
			this->txt_reg_nombres->Name = L"txt_reg_nombres";
			this->txt_reg_nombres->Size = System::Drawing::Size(198, 20);
			this->txt_reg_nombres->TabIndex = 2;
			// 
			// lbl_nombre
			// 
			this->lbl_nombre->AutoSize = true;
			this->lbl_nombre->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nombre->Location = System::Drawing::Point(19, 45);
			this->lbl_nombre->Name = L"lbl_nombre";
			this->lbl_nombre->Size = System::Drawing::Size(82, 21);
			this->lbl_nombre->TabIndex = 1;
			this->lbl_nombre->Text = L"Nombres:";
			// 
			// lbl_registro_empleados
			// 
			this->lbl_registro_empleados->AutoSize = true;
			this->lbl_registro_empleados->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_registro_empleados->Location = System::Drawing::Point(208, 9);
			this->lbl_registro_empleados->Name = L"lbl_registro_empleados";
			this->lbl_registro_empleados->Size = System::Drawing::Size(243, 25);
			this->lbl_registro_empleados->TabIndex = 0;
			this->lbl_registro_empleados->Text = L"REGISTRO DE EMPLEADOS";


			//
			//PANTALLA PANEL VER EMPLEADOS
			//
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_verEmpleados = (gcnew System::Windows::Forms::Panel());
			this->tittle_verEmpleados = (gcnew System::Windows::Forms::Label());
			this->tabla_verEmpleados = (gcnew System::Windows::Forms::DataGridView());
			this->ID_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NOMBRES_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PATERNO_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MATERNO_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NACIMIENTO_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TELEFONO_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DOMICILIO_table = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TIPOUSER_tabla = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_verEmpleados->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabla_verEmpleados))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_verEmpleados
			// 
			this->panel_verEmpleados->Controls->Add(this->tabla_verEmpleados);
			this->panel_verEmpleados->Controls->Add(this->tittle_verEmpleados);
			this->panel_verEmpleados->Location = System::Drawing::Point(0, 0);
			this->panel_verEmpleados->Name = L"panel_verEmpleados";
			this->panel_verEmpleados->Size = System::Drawing::Size(675, 420);
			this->panel_verEmpleados->TabIndex = 0;
			// 
			// tittle_verEmpleados
			// 
			this->tittle_verEmpleados->AutoSize = true;
			this->tittle_verEmpleados->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 20, System::Drawing::FontStyle::Bold));
			this->tittle_verEmpleados->Location = System::Drawing::Point(225, 9);
			this->tittle_verEmpleados->Name = L"tittle_verEmpleados";
			this->tittle_verEmpleados->Size = System::Drawing::Size(223, 35);
			this->tittle_verEmpleados->TabIndex = 0;
			this->tittle_verEmpleados->Text = L"VER EMPLEADOS";
			// 
			// tabla_verEmpleados
			// 
			this->tabla_verEmpleados->AllowUserToAddRows = false;
			this->tabla_verEmpleados->AllowUserToDeleteRows = false;
			this->tabla_verEmpleados->AllowUserToResizeColumns = false;
			this->tabla_verEmpleados->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->tabla_verEmpleados->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->tabla_verEmpleados->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tabla_verEmpleados->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->ID_table,
					this->NOMBRES_table, this->PATERNO_table, this->MATERNO_table, this->NACIMIENTO_table, this->TELEFONO_table, this->DOMICILIO_table,
					this->TIPOUSER_tabla
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->tabla_verEmpleados->DefaultCellStyle = dataGridViewCellStyle4;
			this->tabla_verEmpleados->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->tabla_verEmpleados->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->tabla_verEmpleados->Location = System::Drawing::Point(12, 47);
			this->tabla_verEmpleados->Name = L"tabla_verEmpleados";
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->tabla_verEmpleados->RowHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->tabla_verEmpleados->RowHeadersVisible = false;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabla_verEmpleados->RowsDefaultCellStyle = dataGridViewCellStyle6;
			this->tabla_verEmpleados->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			this->tabla_verEmpleados->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tabla_verEmpleados->Size = System::Drawing::Size(648, 361);
			this->tabla_verEmpleados->TabIndex = 1;
			// 
			// ID_table
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ID_table->DefaultCellStyle = dataGridViewCellStyle2;
			this->ID_table->HeaderText = L"ID";
			this->ID_table->Name = L"ID_table";
			this->ID_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ID_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ID_table->Width = 31;
			// 
			// NOMBRES_table
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NOMBRES_table->DefaultCellStyle = dataGridViewCellStyle3;
			this->NOMBRES_table->HeaderText = L"NOMBRES";
			this->NOMBRES_table->Name = L"NOMBRES_table";
			this->NOMBRES_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->NOMBRES_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->NOMBRES_table->Width = 180;
			// 
			// PATERNO_table
			// 
			this->PATERNO_table->HeaderText = L"A.PATERNO";
			this->PATERNO_table->Name = L"PATERNO_table";
			this->PATERNO_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->PATERNO_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->PATERNO_table->Width = 120;
			// 
			// MATERNO_table
			// 
			this->MATERNO_table->HeaderText = L"A.MATERNO";
			this->MATERNO_table->Name = L"MATERNO_table";
			this->MATERNO_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->MATERNO_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->MATERNO_table->Width = 120;
			// 
			// NACIMIENTO_table
			// 
			this->NACIMIENTO_table->HeaderText = L"F.NACIMIENTO";
			this->NACIMIENTO_table->Name = L"NACIMIENTO_table";
			this->NACIMIENTO_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->NACIMIENTO_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->NACIMIENTO_table->Width = 120;
			// 
			// TELEFONO_table
			// 
			this->TELEFONO_table->HeaderText = L"TELÉFONO";
			this->TELEFONO_table->Name = L"TELEFONO_table";
			this->TELEFONO_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TELEFONO_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// DOMICILIO_table
			// 
			this->DOMICILIO_table->HeaderText = L"DOMICILIO";
			this->DOMICILIO_table->Name = L"DOMICILIO_table";
			this->DOMICILIO_table->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->DOMICILIO_table->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->DOMICILIO_table->Width = 200;
			// 
			// TIPOUSER_tabla
			// 
			this->TIPOUSER_tabla->HeaderText = L"T.USUARIO";
			this->TIPOUSER_tabla->Name = L"TIPOUSER_tabla";
			this->TIPOUSER_tabla->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TIPOUSER_tabla->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->TIPOUSER_tabla->Width = 120;
			//
			//LLENAR TABLA
			//
			int num, i = 0, n_fila;
			num = revisarUltimoId();

			while (i <= num) {
				if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
					MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
				}
				while (fread(&var, lr, 1, fd)) {
					if (i == var.id) {
						//Creamos nueva fila
						n_fila = tabla_verEmpleados->Rows->Add();

						//Agregamos la información
						tabla_verEmpleados->Rows[n_fila]->Cells[0]->Value = var.id;
						tabla_verEmpleados->Rows[n_fila]->Cells[1]->Value = toSystemString(var.nombres);
						tabla_verEmpleados->Rows[n_fila]->Cells[2]->Value = toSystemString(var.apellidoPaterno);
						tabla_verEmpleados->Rows[n_fila]->Cells[3]->Value = toSystemString(var.apellidoMaterno);
						tabla_verEmpleados->Rows[n_fila]->Cells[4]->Value = toSystemString(var.nacimiento);
						tabla_verEmpleados->Rows[n_fila]->Cells[5]->Value = toSystemString(var.telefono);
						tabla_verEmpleados->Rows[n_fila]->Cells[6]->Value = toSystemString(var.direccion);
						tabla_verEmpleados->Rows[n_fila]->Cells[7]->Value = toSystemString(var.tipo_usuario);
					}
				}
				fclose(fd);
				i++;
			}

			//
			// PANTALLA INVENTARIO
			//
			
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle44 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle55 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle66 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_Inventario = (gcnew System::Windows::Forms::Panel());
			this->tabla_Inventario = (gcnew System::Windows::Forms::DataGridView());
			this->tittle_Inventario = (gcnew System::Windows::Forms::Label());
			this->ID_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PRODUCTO_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TPROD_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MARCA_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->UnidadBase_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CANTIDAD_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Precio_tableInventario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->caja_addProd = (gcnew System::Windows::Forms::GroupBox());
			this->select_agregar = (gcnew System::Windows::Forms::RadioButton());
			this->select_modificar = (gcnew System::Windows::Forms::RadioButton());
			this->id_prod = (gcnew System::Windows::Forms::Label());
			this->select_id = (gcnew System::Windows::Forms::ComboBox());
			this->label_nameprod = (gcnew System::Windows::Forms::Label());
			this->get_nombreprod = (gcnew System::Windows::Forms::TextBox());
			this->label_tipoprod = (gcnew System::Windows::Forms::Label());
			this->get_tipoprod = (gcnew System::Windows::Forms::ComboBox());
			this->label_cantidad = (gcnew System::Windows::Forms::Label());
			this->get_cantidadprod = (gcnew System::Windows::Forms::TextBox());
			this->label_precioprod = (gcnew System::Windows::Forms::Label());
			this->get_precioprod = (gcnew System::Windows::Forms::TextBox());
			this->label_simbolo = (gcnew System::Windows::Forms::Label());
			this->bttn_confirmar_inventario = (gcnew System::Windows::Forms::Button());
			this->bttn_cargar = (gcnew System::Windows::Forms::Button());
			this->bttn_cancelar_inventario = (gcnew System::Windows::Forms::Button());
			this->panel_Inventario->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabla_Inventario))->BeginInit();
			this->caja_addProd->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_Inventario
			// 
			this->panel_Inventario->Controls->Add(this->bttn_cancelar_inventario);
			this->panel_Inventario->Controls->Add(this->bttn_confirmar_inventario);
			this->panel_Inventario->Controls->Add(this->caja_addProd);
			this->panel_Inventario->Controls->Add(this->tabla_Inventario);
			this->panel_Inventario->Controls->Add(this->tittle_Inventario);
			this->panel_Inventario->Location = System::Drawing::Point(-1, 0);
			this->panel_Inventario->Name = L"panel_Inventario";
			this->panel_Inventario->Size = System::Drawing::Size(675, 420);
			this->panel_Inventario->TabIndex = 1;
			// 
			// tabla_Inventario
			// 
			this->tabla_Inventario->AllowUserToAddRows = false;
			this->tabla_Inventario->AllowUserToDeleteRows = false;
			this->tabla_Inventario->AllowUserToResizeColumns = false;
			this->tabla_Inventario->AllowUserToResizeRows = false;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->tabla_Inventario->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle11;
			this->tabla_Inventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tabla_Inventario->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ID_tableInventario,
					this->PRODUCTO_tableInventario, this->TPROD_tableInventario, this->MARCA_tableInventario, this->UnidadBase_tableInventario, this->CANTIDAD_tableInventario,
					this->Precio_tableInventario
			});
			dataGridViewCellStyle44->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle44->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle44->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle44->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle44->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle44->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle44->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->tabla_Inventario->DefaultCellStyle = dataGridViewCellStyle44;
			this->tabla_Inventario->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->tabla_Inventario->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->tabla_Inventario->Location = System::Drawing::Point(12, 47);
			this->tabla_Inventario->Name = L"tabla_Inventario";
			dataGridViewCellStyle55->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle55->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle55->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle55->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle55->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle55->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle55->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->tabla_Inventario->RowHeadersDefaultCellStyle = dataGridViewCellStyle55;
			this->tabla_Inventario->RowHeadersVisible = false;
			dataGridViewCellStyle66->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle66->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabla_Inventario->RowsDefaultCellStyle = dataGridViewCellStyle66;
			this->tabla_Inventario->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			this->tabla_Inventario->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tabla_Inventario->Size = System::Drawing::Size(649, 158);
			this->tabla_Inventario->TabIndex = 1;
			// 
			// tittle_Inventario
			// 
			this->tittle_Inventario->AutoSize = true;
			this->tittle_Inventario->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 20, System::Drawing::FontStyle::Bold));
			this->tittle_Inventario->Location = System::Drawing::Point(225, 9);
			this->tittle_Inventario->Name = L"tittle_Inventario";
			this->tittle_Inventario->Size = System::Drawing::Size(175, 35);
			this->tittle_Inventario->TabIndex = 0;
			this->tittle_Inventario->Text = L"INVENTARIO";
			// 
			// ID_tableInventario
			// 
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ID_tableInventario->DefaultCellStyle = dataGridViewCellStyle22;
			this->ID_tableInventario->HeaderText = L"ID";
			this->ID_tableInventario->Name = L"ID_tableInventario";
			this->ID_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ID_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ID_tableInventario->Width = 31;
			// 
			// PRODUCTO_tableInventario
			// 
			dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle33->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PRODUCTO_tableInventario->DefaultCellStyle = dataGridViewCellStyle33;
			this->PRODUCTO_tableInventario->HeaderText = L"PRODUCTO";
			this->PRODUCTO_tableInventario->Name = L"PRODUCTO_tableInventario";
			this->PRODUCTO_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->PRODUCTO_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->PRODUCTO_tableInventario->Width = 180;
			// 
			// TPROD_tableInventario
			// 
			this->TPROD_tableInventario->HeaderText = L"CATEGORIA";
			this->TPROD_tableInventario->Name = L"TPROD_tableInventario";
			this->TPROD_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TPROD_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->TPROD_tableInventario->Width = 170;
			// 
			// MARCA_tableInventario
			// 
			this->MARCA_tableInventario->HeaderText = L"MARCA/MODELO";
			this->MARCA_tableInventario->Name = L"MARCA_tableInventario";
			this->MARCA_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->MARCA_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->MARCA_tableInventario->Width = 130;
			// 
			// UnidadBase_tableInventario
			// 
			this->UnidadBase_tableInventario->HeaderText = L"UNIDAD BASE";
			this->UnidadBase_tableInventario->Name = L"UnidadBase_tableInventario";
			this->UnidadBase_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->UnidadBase_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->UnidadBase_tableInventario->Width = 130;
			// 
			// CANTIDAD_tableInventario
			// 
			this->CANTIDAD_tableInventario->HeaderText = L"CANTIDAD";
			this->CANTIDAD_tableInventario->Name = L"CANTIDAD_tableInventario";
			this->CANTIDAD_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->CANTIDAD_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->CANTIDAD_tableInventario->Width = 120;
			// 
			// Precio_tableInventario
			// 
			this->Precio_tableInventario->HeaderText = L"PRECIO UNITARIO";
			this->Precio_tableInventario->Name = L"Precio_tableInventario";
			this->Precio_tableInventario->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Precio_tableInventario->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Precio_tableInventario->Width = 140;
			// 
			// caja_addProd
			// 
			this->caja_addProd->Controls->Add(this->label_simbolo);
			this->caja_addProd->Controls->Add(this->get_precioprod);
			this->caja_addProd->Controls->Add(this->label_precioprod);
			this->caja_addProd->Controls->Add(this->get_cantidadprod);
			this->caja_addProd->Controls->Add(this->label_cantidad);
			this->caja_addProd->Controls->Add(this->get_tipoprod);
			this->caja_addProd->Controls->Add(this->label_tipoprod);
			this->caja_addProd->Controls->Add(this->get_nombreprod);
			this->caja_addProd->Controls->Add(this->label_nameprod);
			this->caja_addProd->Controls->Add(this->select_id);
			this->caja_addProd->Controls->Add(this->id_prod);
			this->caja_addProd->Controls->Add(this->select_modificar);
			this->caja_addProd->Controls->Add(this->select_agregar);
			this->caja_addProd->Controls->Add(this->bttn_cargar);
			this->caja_addProd->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->caja_addProd->Location = System::Drawing::Point(12, 221);
			this->caja_addProd->Name = L"caja_addProd";
			this->caja_addProd->Size = System::Drawing::Size(649, 117);
			this->caja_addProd->TabIndex = 2;
			this->caja_addProd->TabStop = false;
			this->caja_addProd->Text = L"Agregar / Modificar Producto";
			// 
			// select_agregar
			// 
			this->select_agregar->AutoSize = true;
			this->select_agregar->Location = System::Drawing::Point(18, 19);
			this->select_agregar->Name = L"select_agregar";
			this->select_agregar->Size = System::Drawing::Size(67, 19);
			this->select_agregar->TabIndex = 0;
			this->select_agregar->TabStop = true;
			this->select_agregar->Text = L"Agregar";
			this->select_agregar->UseVisualStyleBackColor = true;
			this->select_agregar->CheckedChanged += gcnew System::EventHandler(this, &Form1::select_agregar_CheckedChanged);
			// 
			// select_modificar
			// 
			this->select_modificar->AutoSize = true;
			this->select_modificar->Location = System::Drawing::Point(91, 19);
			this->select_modificar->Name = L"select_modificar";
			this->select_modificar->Size = System::Drawing::Size(79, 19);
			this->select_modificar->TabIndex = 1;
			this->select_modificar->TabStop = true;
			this->select_modificar->Text = L"Modificar";
			this->select_modificar->UseVisualStyleBackColor = true;
			this->select_modificar->CheckedChanged += gcnew System::EventHandler(this, &Form1::select_modificar_CheckedChanged);
			// 
			// id_prod
			// 
			this->id_prod->AutoSize = true;
			this->id_prod->Location = System::Drawing::Point(15, 54);
			this->id_prod->Name = L"id_prod";
			this->id_prod->Size = System::Drawing::Size(25, 15);
			this->id_prod->TabIndex = 2;
			this->id_prod->Text = L"ID:";
			// 
			// select_id
			// 
			this->select_id->FormattingEnabled = true;
			this->select_id->Location = System::Drawing::Point(18, 72);
			this->select_id->Name = L"select_id";
			this->select_id->Size = System::Drawing::Size(44, 23);
			this->select_id->TabIndex = 3;
			// 
			// label_nameprod
			// 
			this->label_nameprod->AutoSize = true;
			this->label_nameprod->Location = System::Drawing::Point(91, 54);
			this->label_nameprod->Name = L"label_nameprod";
			this->label_nameprod->Size = System::Drawing::Size(61, 15);
			this->label_nameprod->TabIndex = 4;
			this->label_nameprod->Text = L"Producto:";
			// 
			// get_nombreprod
			// 
			this->get_nombreprod->Location = System::Drawing::Point(94, 74);
			this->get_nombreprod->Name = L"get_nombreprod";
			this->get_nombreprod->Size = System::Drawing::Size(151, 20);
			this->get_nombreprod->TabIndex = 5;
			// 
			// label_tipoprod
			// 
			this->label_tipoprod->AutoSize = true;
			this->label_tipoprod->Location = System::Drawing::Point(263, 54);
			this->label_tipoprod->Name = L"label_tipoprod";
			this->label_tipoprod->Size = System::Drawing::Size(109, 15);
			this->label_tipoprod->TabIndex = 6;
			this->label_tipoprod->Text = L"Categoria:";
			// 
			// get_tipoprod
			// 
			this->get_tipoprod->FormattingEnabled = true;
			this->get_tipoprod->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Abarrotes", L"Lácteos", L"Huevos", L"Bebidas",
					L"Cuidado Personal", L"Limpieza"
			});
			this->get_tipoprod->Location = System::Drawing::Point(266, 74);
			this->get_tipoprod->Name = L"get_tipoprod";
			this->get_tipoprod->Size = System::Drawing::Size(170, 23);
			this->get_tipoprod->TabIndex = 7;
			// 
			// label_cantidad
			// 
			this->label_cantidad->AutoSize = true;
			this->label_cantidad->Location = System::Drawing::Point(450, 55);
			this->label_cantidad->Name = L"label_cantidad";
			this->label_cantidad->Size = System::Drawing::Size(61, 15);
			this->label_cantidad->TabIndex = 8;
			this->label_cantidad->Text = L"Cantidad:";
			// 
			// get_cantidadprod
			// 
			this->get_cantidadprod->Location = System::Drawing::Point(453, 76);
			this->get_cantidadprod->Name = L"get_cantidadprod";
			this->get_cantidadprod->Size = System::Drawing::Size(58, 20);
			this->get_cantidadprod->TabIndex = 9;
			// 
			// label_precioprod
			// 
			this->label_precioprod->AutoSize = true;
			this->label_precioprod->Location = System::Drawing::Point(550, 55);
			this->label_precioprod->Name = L"label_precioprod";
			this->label_precioprod->Size = System::Drawing::Size(49, 15);
			this->label_precioprod->TabIndex = 10;
			this->label_precioprod->Text = L"Precio:";
			// 
			// get_precioprod
			// 
			this->get_precioprod->Location = System::Drawing::Point(553, 76);
			this->get_precioprod->Name = L"get_precioprod";
			this->get_precioprod->Size = System::Drawing::Size(78, 20);
			this->get_precioprod->TabIndex = 11;
			// 
			// label_simbolo
			// 
			this->label_simbolo->AutoSize = true;
			this->label_simbolo->Location = System::Drawing::Point(526, 79);
			this->label_simbolo->Name = L"label_simbolo";
			this->label_simbolo->Size = System::Drawing::Size(25, 15);
			this->label_simbolo->TabIndex = 12;
			this->label_simbolo->Text = L"S/.";
			// 
			// bttn_confirmar_inventario
			// 
			this->bttn_confirmar_inventario->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bttn_confirmar_inventario->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bttn_confirmar_inventario->Location = System::Drawing::Point(368, 359);
			this->bttn_confirmar_inventario->Name = L"bttn_confirmar_inventario";
			this->bttn_confirmar_inventario->Size = System::Drawing::Size(123, 40);
			this->bttn_confirmar_inventario->TabIndex = 3;
			this->bttn_confirmar_inventario->Text = L"CONFIRMAR";
			this->bttn_confirmar_inventario->UseVisualStyleBackColor = false;
			this->bttn_confirmar_inventario->Click += gcnew System::EventHandler(this, &Form1::bttn_confirmar_inventario_Click);
			// 
			// bttn_cancelar_inventario
			// 
			this->bttn_cancelar_inventario->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bttn_cancelar_inventario->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bttn_cancelar_inventario->Location = System::Drawing::Point(520, 359);
			this->bttn_cancelar_inventario->Name = L"bttn_cancelar_inventario";
			this->bttn_cancelar_inventario->Size = System::Drawing::Size(123, 40);
			this->bttn_cancelar_inventario->TabIndex = 4;
			this->bttn_cancelar_inventario->Text = L"CANCELAR";
			this->bttn_cancelar_inventario->UseVisualStyleBackColor = false;
			this->bttn_cancelar_inventario->Click += gcnew System::EventHandler(this, &Form1::bttn_cancelar_inventario_Click);
			// 
			// bttn_cargar
			// 
			this->bttn_cargar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bttn_cargar->Image = Image::FromFile(L"./img/bttn_carga.png");
			this->bttn_cargar->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->bttn_cargar->Location = System::Drawing::Point(604, 17);
			this->bttn_cargar->Margin = System::Windows::Forms::Padding(0);
			this->bttn_cargar->Name = L"bttn_cargar";
			this->bttn_cargar->Size = System::Drawing::Size(27, 23);
			this->bttn_cargar->TabIndex = 13;
			this->bttn_cargar->UseVisualStyleBackColor = true;
			this->bttn_cargar->Visible = false;
			this->bttn_cargar->Click += gcnew System::EventHandler(this, &Form1::bttn_cargar_Click);
			//
			//LLENAR TABLA INVENTARIO
			//
			int num1, i1 = 0, n_fila1;
			num1 = revisarUltimoId2();

			while (i1 <= num1) {
				if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
					MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
				}
				while (fread(&prod, lf, 1, fr)) {
					if ((i1 == prod.id)&&(i1 != 0)) {
						//Creamos nueva fila
						n_fila1 = tabla_Inventario->Rows->Add();

						//Agregamos la información
						tabla_Inventario->Rows[n_fila1]->Cells[0]->Value = prod.id;
						tabla_Inventario->Rows[n_fila1]->Cells[1]->Value = toSystemString(prod.nombre);
						tabla_Inventario->Rows[n_fila1]->Cells[2]->Value = toSystemString(prod.tipo);
						tabla_Inventario->Rows[n_fila1]->Cells[3]->Value = toSystemString(prod.marca);
						tabla_Inventario->Rows[n_fila1]->Cells[4]->Value = toSystemString(prod.unidadBase);
						tabla_Inventario->Rows[n_fila1]->Cells[5]->Value = prod.cantidad;
						tabla_Inventario->Rows[n_fila1]->Cells[6]->Value = L"S/ " + prod.precio;
					}
				}
				fclose(fr);
				i1++;
			}
			
			
			
			
			
			
			//
			//PANTALLA REGISTRO DE VENTAS
			//
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle000 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle111 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle222 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle333 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle444 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle555 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_reg_ventas = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar_compra = (gcnew System::Windows::Forms::Button());
			this->btn_confirmar_compra = (gcnew System::Windows::Forms::Button());
			this->groupBox_ventas = (gcnew System::Windows::Forms::GroupBox());
			this->btn_agregar_a_lista = (gcnew System::Windows::Forms::Button());
			this->lbl_precio_producto = (gcnew System::Windows::Forms::Label());
			this->lbl_soles = (gcnew System::Windows::Forms::Label());
			this->lbl_nombre_precio = (gcnew System::Windows::Forms::Label());
			this->cbox_tipo_pago = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_tipo_pag = (gcnew System::Windows::Forms::Label());
			this->txt_cant_prod = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cant = (gcnew System::Windows::Forms::Label());
			this->lbl_sel_prod = (gcnew System::Windows::Forms::Label());
			this->cbox_selec_categoria = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_reg_ventas = (gcnew System::Windows::Forms::Label());
			this->dataGridView_ventas = (gcnew System::Windows::Forms::DataGridView());
			this->num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->producto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->precio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->marca_dataGrid = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tipo_unidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbl_nombre_precioTotal = (gcnew System::Windows::Forms::Label());
			this->lbl_precioTotal = (gcnew System::Windows::Forms::Label());
			this->lbl_nombre_cantidad_actual = (gcnew System::Windows::Forms::Label());
			this->lbl_cantidad_actual = (gcnew System::Windows::Forms::Label());
			this->cbox_selec_producto = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_sel_producto2 = (gcnew System::Windows::Forms::Label());
			this->lbl_titular_pago = (gcnew System::Windows::Forms::Label());
			this->txt_titular_pago = (gcnew System::Windows::Forms::TextBox());
			
			this->lbl_marca_modelo = (gcnew System::Windows::Forms::Label());
			this->cbox_marca_modelo = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_unidadVenta = (gcnew System::Windows::Forms::Label());
			this->cbox_unidadVenta = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_precio_semitotal = (gcnew System::Windows::Forms::Label());
			this->txt_precio_semitotal = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_Stock = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_unidad_base_stock = (gcnew System::Windows::Forms::Label());
			this->lbl_unidad_base_stock_si = (gcnew System::Windows::Forms::Label());
			this->lbl_marca_modelo_stock = (gcnew System::Windows::Forms::Label());
			this->lbl_marca_modelo_stock_si = (gcnew System::Windows::Forms::Label());
			this->btn_ver_stock = (gcnew System::Windows::Forms::Button());
			this->panel_borrar_stock = (gcnew System::Windows::Forms::Panel());
			this->lbl_borrar_stock = (gcnew System::Windows::Forms::Label());

			this->panel_reg_ventas->SuspendLayout();
			this->groupBox_ventas->SuspendLayout();
			this->panel_borrar_stock->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_ventas))->BeginInit();
			this->SuspendLayout();


			// 
			// panel_reg_ventas
			// 
			this->panel_reg_ventas->BackColor = System::Drawing::SystemColors::Control;
			this->panel_reg_ventas->Controls->Add(this->lbl_precioTotal);
			this->panel_reg_ventas->Controls->Add(this->lbl_nombre_precioTotal);
			this->panel_reg_ventas->Controls->Add(this->dataGridView_ventas);
			this->panel_reg_ventas->Controls->Add(this->btn_cancelar_compra);
			this->panel_reg_ventas->Controls->Add(this->btn_confirmar_compra);
			this->panel_reg_ventas->Controls->Add(this->groupBox_ventas);
			this->panel_reg_ventas->Controls->Add(this->lbl_reg_ventas);
			this->panel_reg_ventas->Controls->Add(this->cbox_tipo_pago);
			this->panel_reg_ventas->Controls->Add(this->lbl_tipo_pag);
			this->panel_reg_ventas->Controls->Add(this->txt_titular_pago);
			this->panel_reg_ventas->Controls->Add(this->lbl_titular_pago);
			this->panel_reg_ventas->Location = System::Drawing::Point(0, 0);
			this->panel_reg_ventas->Name = L"panel_reg_ventas";
			this->panel_reg_ventas->Size = System::Drawing::Size(672, 420);
			this->panel_reg_ventas->TabIndex = 16;
			// 
			// btn_cancelar_compra
			// 
			this->btn_cancelar_compra->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_cancelar_compra->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancelar_compra->Location = System::Drawing::Point(531, 363);
			this->btn_cancelar_compra->Name = L"btn_cancelar_compra";
			this->btn_cancelar_compra->Size = System::Drawing::Size(120, 43);
			this->btn_cancelar_compra->TabIndex = 22;
			this->btn_cancelar_compra->Text = L"CANCELAR";
			this->btn_cancelar_compra->UseVisualStyleBackColor = false;
			this->btn_cancelar_compra->Click += gcnew System::EventHandler(this, &Form1::btn_cancelar_compra_Click);
			// 
			// btn_confirmar_compra
			// 
			this->btn_confirmar_compra->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_confirmar_compra->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_confirmar_compra->Location = System::Drawing::Point(405, 363);
			this->btn_confirmar_compra->Name = L"btn_confirmar_compra";
			this->btn_confirmar_compra->Size = System::Drawing::Size(120, 43);
			this->btn_confirmar_compra->TabIndex = 21;
			this->btn_confirmar_compra->Text = L"CONFIRMAR";
			this->btn_confirmar_compra->UseVisualStyleBackColor = false;
			this->btn_confirmar_compra->Click += gcnew System::EventHandler(this, &Form1::btn_confirmar_compra_Click);
			// 
			// groupBox_ventas
			// 
			this->groupBox_ventas->Controls->Add(this->btn_agregar_a_lista);
			this->groupBox_ventas->Controls->Add(this->lbl_precio_producto);
			this->groupBox_ventas->Controls->Add(this->lbl_soles);
			this->groupBox_ventas->Controls->Add(this->lbl_nombre_precio);
			this->groupBox_ventas->Controls->Add(this->txt_cant_prod);
			this->groupBox_ventas->Controls->Add(this->lbl_cant);
			this->groupBox_ventas->Controls->Add(this->lbl_sel_prod);
			this->groupBox_ventas->Controls->Add(this->cbox_selec_categoria);
			this->groupBox_ventas->Controls->Add(this->lbl_sel_producto2);
			this->groupBox_ventas->Controls->Add(this->cbox_selec_producto);
			this->groupBox_ventas->Controls->Add(this->lbl_cantidad_actual);
			this->groupBox_ventas->Controls->Add(this->lbl_nombre_cantidad_actual);
			this->groupBox_ventas->Controls->Add(this->groupBox_Stock);
			this->groupBox_ventas->Controls->Add(this->txt_precio_semitotal);
			this->groupBox_ventas->Controls->Add(this->lbl_precio_semitotal);
			this->groupBox_ventas->Controls->Add(this->cbox_unidadVenta);
			this->groupBox_ventas->Controls->Add(this->lbl_unidadVenta);
			this->groupBox_ventas->Controls->Add(this->cbox_marca_modelo);
			this->groupBox_ventas->Controls->Add(this->lbl_marca_modelo);
			this->groupBox_ventas->Location = System::Drawing::Point(21, 37);
			this->groupBox_ventas->Name = L"groupBox_ventas";
			this->groupBox_ventas->Size = System::Drawing::Size(630, 153);
			this->groupBox_ventas->TabIndex = 2;
			this->groupBox_ventas->TabStop = false;
			this->groupBox_ventas->Text = L"Agregar producto";
			// 
			// btn_agregar_a_lista
			// 
			this->btn_agregar_a_lista->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btn_agregar_a_lista->Image = Image::FromFile(L"./img/mas.png");
			this->btn_agregar_a_lista->Location = System::Drawing::Point(387, 73);
			this->btn_agregar_a_lista->Name = L"btn_agregar_a_lista";
			this->btn_agregar_a_lista->Size = System::Drawing::Size(23, 23);
			this->btn_agregar_a_lista->TabIndex = 18;
			this->btn_agregar_a_lista->UseVisualStyleBackColor = false;
			this->btn_agregar_a_lista->Click += gcnew System::EventHandler(this, &Form1::btn_agregar_a_lista_Click);
			// 
			// lbl_precio_producto
			// 
			this->lbl_precio_producto->AutoSize = true;
			this->lbl_precio_producto->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_precio_producto->Location = System::Drawing::Point(104, 56);
			this->lbl_precio_producto->Name = L"lbl_precio_producto";
			this->lbl_precio_producto->Size = System::Drawing::Size(14, 16);
			this->lbl_precio_producto->TabIndex = 17;
			this->lbl_precio_producto->Text = L"0";
			// 
			// lbl_soles
			// 
			this->lbl_soles->AutoSize = true;
			this->lbl_soles->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_soles->Location = System::Drawing::Point(95, 55);
			this->lbl_soles->Name = L"lbl_soles";
			this->lbl_soles->Size = System::Drawing::Size(26, 19);
			this->lbl_soles->TabIndex = 16;
			this->lbl_soles->Text = L"";//Aquí iba el (s/.)
			// 
			// lbl_nombre_precio
			// 
			this->lbl_nombre_precio->AutoSize = true;
			this->lbl_nombre_precio->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nombre_precio->Location = System::Drawing::Point(7, 56);
			this->lbl_nombre_precio->Name = L"lbl_nombre_precio";
			this->lbl_nombre_precio->Size = System::Drawing::Size(100, 18);
			this->lbl_nombre_precio->TabIndex = 15;
			this->lbl_nombre_precio->Text = L"Precio Unitario:";
			// 
			// cbox_tipo_pago
			// 
			this->cbox_tipo_pago->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_tipo_pago->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbox_tipo_pago->FormattingEnabled = true;
			this->cbox_tipo_pago->Location = System::Drawing::Point(23, 369);
			this->cbox_tipo_pago->Name = L"cbox_tipo_pago";
			this->cbox_tipo_pago->Size = System::Drawing::Size(120, 17);
			this->cbox_tipo_pago->TabIndex = 14;
			this->cbox_tipo_pago->Tag = L"";
			cbox_tipo_pago->Items->Add("Efectivo");
			cbox_tipo_pago->Items->Add("Pago móvil");
			this->cbox_tipo_pago->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbox_tipo_pago_SelectedIndexChanged);
			// 
			// lbl_tipo_pag
			// 
			this->lbl_tipo_pag->AutoSize = true;
			this->lbl_tipo_pag->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_tipo_pag->Location = System::Drawing::Point(19, 338);
			this->lbl_tipo_pag->Name = L"lbl_tipo_pag";
			this->lbl_tipo_pag->Size = System::Drawing::Size(127, 21);
			this->lbl_tipo_pag->TabIndex = 13;
			this->lbl_tipo_pag->Text = L"Tipo de pago:";
			// 
			// txt_cant_prod
			// 
			this->txt_cant_prod->Location = System::Drawing::Point(286, 53);
			this->txt_cant_prod->Name = L"txt_cant_prod";
			this->txt_cant_prod->Size = System::Drawing::Size(71, 20);
			this->txt_cant_prod->TabIndex = 12;
			// 
			// lbl_cant
			// 
			this->lbl_cant->AutoSize = true;
			this->lbl_cant->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_cant->Location = System::Drawing::Point(281, 24);
			this->lbl_cant->Name = L"lbl_cant";
			this->lbl_cant->Size = System::Drawing::Size(91, 21);
			this->lbl_cant->TabIndex = 11;
			this->lbl_cant->Text = L"Cantidad:";
			// 
			// lbl_sel_prod
			// 
			this->lbl_sel_prod->AutoSize = true;
			this->lbl_sel_prod->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sel_prod->Location = System::Drawing::Point(6, 24);
			this->lbl_sel_prod->Name = L"lbl_sel_prod";
			this->lbl_sel_prod->Size = System::Drawing::Size(100, 21);
			this->lbl_sel_prod->TabIndex = 10;
			this->lbl_sel_prod->Text = L"Categoría:";
			// 
			// cbox_selec_categoria
			// 
			this->cbox_selec_categoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_selec_categoria->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbox_selec_categoria->FormattingEnabled = true;
			this->cbox_selec_categoria->Location = System::Drawing::Point(10, 51);
			this->cbox_selec_categoria->Name = L"cbox_selec_categoria";
			this->cbox_selec_categoria->Size = System::Drawing::Size(125, 23);
			this->cbox_selec_categoria->TabIndex = 9;
			this->cbox_selec_categoria->Tag = L"";
			cbox_selec_categoria->Items->Add("Abarrotes");
			cbox_selec_categoria->Items->Add("Lacteos");
			cbox_selec_categoria->Items->Add("Huevos");
			cbox_selec_categoria->Items->Add("Bebidas");
			cbox_selec_categoria->Items->Add("Limpieza");
			this->cbox_selec_categoria->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbox_selec_categoria_SelectedIndexChanged);
			// 
			// lbl_reg_ventas
			// 
			this->lbl_reg_ventas->AutoSize = true;
			this->lbl_reg_ventas->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_reg_ventas->Location = System::Drawing::Point(239, 11);
			this->lbl_reg_ventas->Name = L"lbl_reg_ventas";
			this->lbl_reg_ventas->Size = System::Drawing::Size(210, 25);
			this->lbl_reg_ventas->TabIndex = 1;
			this->lbl_reg_ventas->Text = L"REGISTRO DE VENTAS";
			// 
			// dataGridView_ventas
			// 
			this->dataGridView_ventas->AllowUserToAddRows = false;
			this->dataGridView_ventas->AllowUserToDeleteRows = false;
			this->dataGridView_ventas->AllowUserToResizeColumns = false;
			this->dataGridView_ventas->AllowUserToResizeRows = false;
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_ventas->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle11;
	
			this->dataGridView_ventas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_ventas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->num,
					this->producto, this->marca_dataGrid, this->tipo_unidad, this->cantidad, this->precio
			});
			dataGridViewCellStyle44->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle44->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle44->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle44->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle44->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle44->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle44->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_ventas->DefaultCellStyle = dataGridViewCellStyle44;
			this->dataGridView_ventas->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView_ventas->ImeMode = System::Windows::Forms::ImeMode::Off;

			this->dataGridView_ventas->Location = System::Drawing::Point(21, 199);
			this->dataGridView_ventas->Name = L"dataGridView_ventas";
			this->dataGridView_ventas->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView_ventas->RowHeadersVisible = false;

			dataGridViewCellStyle55->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle55->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle55->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle55->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle55->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle55->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle55->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_ventas->RowHeadersDefaultCellStyle = dataGridViewCellStyle55;
			this->dataGridView_ventas->RowHeadersVisible = false;
			dataGridViewCellStyle66->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle66->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataGridView_ventas->RowsDefaultCellStyle = dataGridViewCellStyle66;
			this->dataGridView_ventas->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			this->dataGridView_ventas->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));

			this->dataGridView_ventas->Size = System::Drawing::Size(630, 122);
			this->dataGridView_ventas->TabIndex = 23;
			// 
			// num
			// 
			dataGridViewCellStyle000->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle000->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle000->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->num->DefaultCellStyle = dataGridViewCellStyle000;
			this->num->HeaderText = L"N°";
			this->num->Name = L"num";
			this->num->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->num->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->num->ReadOnly = true;
			this->num->Width = 39;
			// 
			// producto
			// 
			dataGridViewCellStyle111->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle111->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle111->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->producto->DefaultCellStyle = dataGridViewCellStyle111;
			this->producto->HeaderText = L"PRODUCTO";
			this->producto->Name = L"producto";
			this->producto->ReadOnly = true;
			this->producto->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->producto->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->producto->Width = 140;
			// 
			// cantidad
			// 
			dataGridViewCellStyle222->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle222->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle222->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->cantidad->DefaultCellStyle = dataGridViewCellStyle222;
			this->cantidad->HeaderText = L"CANTIDAD";
			this->cantidad->Name = L"cantidad";
			this->cantidad->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->cantidad->ReadOnly = true;
			this->cantidad->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->cantidad->Width = 150;
			// 
			// precio
			// 
			dataGridViewCellStyle333->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle333->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle333->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->precio->DefaultCellStyle = dataGridViewCellStyle333;
			this->precio->HeaderText = L"PRECIO S/";
			this->precio->Name = L"precio";
			this->precio->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->precio->ReadOnly = true;
			this->precio->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->precio->Width = 140;
			// 
			// marca_dataGrid
			// 
			dataGridViewCellStyle555->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle555->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle555->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->marca_dataGrid->DefaultCellStyle = dataGridViewCellStyle555;
			this->marca_dataGrid->HeaderText = L"MARCA";
			this->marca_dataGrid->Name = L"marca_dataGrid";
			this->marca_dataGrid->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->marca_dataGrid->ReadOnly = true;
			this->marca_dataGrid->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->marca_dataGrid->Width = 140;
			// 
			// tipo_unidad
			// 
			dataGridViewCellStyle444->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle444->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle444->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->tipo_unidad->DefaultCellStyle = dataGridViewCellStyle444;
			this->tipo_unidad->HeaderText = L"UNIDAD";
			this->tipo_unidad->MinimumWidth = 10;
			this->tipo_unidad->Name = L"tipo_unidad";
			this->tipo_unidad->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->tipo_unidad->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tipo_unidad->ReadOnly = true;
			this->tipo_unidad->Width = 140;
			// 
			// lbl_nombre_precioTotal
			// 
			this->lbl_nombre_precioTotal->AutoSize = true;
			this->lbl_nombre_precioTotal->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_nombre_precioTotal->Location = System::Drawing::Point(408, 327);
			this->lbl_nombre_precioTotal->Name = L"lbl_nombre_precioTotal";
			this->lbl_nombre_precioTotal->Size = System::Drawing::Size(172, 21);
			this->lbl_nombre_precioTotal->TabIndex = 24;
			this->lbl_nombre_precioTotal->Text = L"Precio total:  S/.";
			// 
			// lbl_precioTotal
			// 
			this->lbl_precioTotal->AutoSize = true;
			this->lbl_precioTotal->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_precioTotal->Location = System::Drawing::Point(577, 327);
			this->lbl_precioTotal->Name = L"lbl_precioTotal";
			this->lbl_precioTotal->Size = System::Drawing::Size(46, 21);
			this->lbl_precioTotal->TabIndex = 25;
			this->lbl_precioTotal->Text = L"0";
			// 
			// lbl_nombre_cantidad_actual
			// 
			this->lbl_nombre_cantidad_actual->AutoSize = true;
			this->lbl_nombre_cantidad_actual->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nombre_cantidad_actual->Location = System::Drawing::Point(7, 17);
			this->lbl_nombre_cantidad_actual->Name = L"lbl_nombre_cantidad_actual";
			this->lbl_nombre_cantidad_actual->Size = System::Drawing::Size(63, 18);
			this->lbl_nombre_cantidad_actual->TabIndex = 19;
			this->lbl_nombre_cantidad_actual->Text = L"Cantidad:";

			// 
			// lbl_cantidad_actual
			// 
			this->lbl_cantidad_actual->AutoSize = true;
			this->lbl_cantidad_actual->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_cantidad_actual->Location = System::Drawing::Point(104, 17);
			this->lbl_cantidad_actual->Name = L"lbl_cantidad_actual_stock_si";
			this->lbl_cantidad_actual->Size = System::Drawing::Size(14, 16);
			this->lbl_cantidad_actual->TabIndex = 20;
			this->lbl_cantidad_actual->Text = L"0";
			// 
			// cbox_selec_producto
			// 
			this->cbox_selec_producto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_selec_producto->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbox_selec_producto->FormattingEnabled = true;
			this->cbox_selec_producto->Location = System::Drawing::Point(10, 110);
			this->cbox_selec_producto->Name = L"cbox_selec_producto";
			this->cbox_selec_producto->Size = System::Drawing::Size(125, 23);
			this->cbox_selec_producto->TabIndex = 21;
			this->cbox_selec_producto->Tag = L"";
			this->cbox_selec_producto->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbox_selec_producto_SelectedIndexChanged);
			// 
			// lbl_sel_producto2
			// 
			this->lbl_sel_producto2->AutoSize = true;
			this->lbl_sel_producto2->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sel_producto2->Location = System::Drawing::Point(6, 85);
			this->lbl_sel_producto2->Name = L"lbl_sel_producto2";
			this->lbl_sel_producto2->Size = System::Drawing::Size(91, 21);
			this->lbl_sel_producto2->TabIndex = 22;
			this->lbl_sel_producto2->Text = L"Producto:";
			// 
			// lbl_titular_pago
			// 
			this->lbl_titular_pago->AutoSize = true;
			this->lbl_titular_pago->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_titular_pago->Location = System::Drawing::Point(160, 339);
			this->lbl_titular_pago->Name = L"lbl_titular_pago";
			this->lbl_titular_pago->Size = System::Drawing::Size(82, 21);
			this->lbl_titular_pago->TabIndex = 26;
			this->lbl_titular_pago->Text = L"Titular:";
			this->lbl_titular_pago->Visible = false;
			// 
			// txt_titular_pago
			// 
			this->txt_titular_pago->Location = System::Drawing::Point(162, 371);
			this->txt_titular_pago->Name = L"txt_titular_pago";
			this->txt_titular_pago->Size = System::Drawing::Size(203, 20);
			this->txt_titular_pago->TabIndex = 27;
			this->txt_titular_pago->Visible = false;
			// 
			// lbl_marca_modelo
			// 
			this->lbl_marca_modelo->AutoSize = true;
			this->lbl_marca_modelo->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_marca_modelo->Location = System::Drawing::Point(143, 24);
			this->lbl_marca_modelo->Name = L"lbl_marca_modelo";
			this->lbl_marca_modelo->Size = System::Drawing::Size(127, 21);
			this->lbl_marca_modelo->TabIndex = 23;
			this->lbl_marca_modelo->Text = L"Marca/Modelo:";
			// 
			// cbox_marca_modelo
			// 
			this->cbox_marca_modelo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_marca_modelo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbox_marca_modelo->FormattingEnabled = true;
			this->cbox_marca_modelo->Location = System::Drawing::Point(147, 51);
			this->cbox_marca_modelo->Name = L"cbox_marca_modelo";
			this->cbox_marca_modelo->Size = System::Drawing::Size(124, 23);
			this->cbox_marca_modelo->TabIndex = 24;
			this->cbox_marca_modelo->Tag = L"";
			this->cbox_marca_modelo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbox_marca_modelo_SelectedIndexChanged);
			// 
			// lbl_unidadVenta
			// 
			this->lbl_unidadVenta->AutoSize = true;
			this->lbl_unidadVenta->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_unidadVenta->Location = System::Drawing::Point(143, 86);
			this->lbl_unidadVenta->Name = L"lbl_unidadVenta";
			this->lbl_unidadVenta->Size = System::Drawing::Size(73, 21);
			this->lbl_unidadVenta->TabIndex = 25;
			this->lbl_unidadVenta->Text = L"Unidad venta:";
			// 
			// cbox_unidadVenta
			// 
			this->cbox_unidadVenta->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_unidadVenta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbox_unidadVenta->FormattingEnabled = true;
			this->cbox_unidadVenta->Location = System::Drawing::Point(147, 110);
			this->cbox_unidadVenta->Name = L"cbox_unidadVenta";
			this->cbox_unidadVenta->Size = System::Drawing::Size(124, 23);
			this->cbox_unidadVenta->TabIndex = 25;
			this->cbox_unidadVenta->Tag = L"";
			this->cbox_unidadVenta->Items->Add("Unidad base");
			this->cbox_unidadVenta->Items->Add("SixPack");
			this->cbox_unidadVenta->Items->Add("12Pack");
			this->cbox_unidadVenta->Items->Add("Caja Mediana");
			this->cbox_unidadVenta->Items->Add("Caja Grande");
			this->cbox_unidadVenta->Items->Add("Kg.");
			// 
			// lbl_precio_semitotal
			// 
			this->lbl_precio_semitotal->AutoSize = true;
			this->lbl_precio_semitotal->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_precio_semitotal->Location = System::Drawing::Point(282, 85);
			this->lbl_precio_semitotal->Name = L"lbl_precio_semitotal";
			this->lbl_precio_semitotal->Size = System::Drawing::Size(73, 21);
			this->lbl_precio_semitotal->TabIndex = 26;
			this->lbl_precio_semitotal->Text = L"Precio:";
			// 
			// txt_precio_semitotal
			// 
			this->txt_precio_semitotal->Location = System::Drawing::Point(286, 112);
			this->txt_precio_semitotal->Name = L"txt_precio_semitotal";
			this->txt_precio_semitotal->Size = System::Drawing::Size(71, 20);
			this->txt_precio_semitotal->TabIndex = 27;
			// 
			// groupBox_Stock
			// 
			this->groupBox_Stock->Controls->Add(this->panel_borrar_stock);
			this->groupBox_Stock->Controls->Add(this->btn_ver_stock);
			this->groupBox_Stock->Controls->Add(this->lbl_marca_modelo_stock_si);
			this->groupBox_Stock->Controls->Add(this->lbl_marca_modelo_stock);
			this->groupBox_Stock->Controls->Add(this->lbl_unidad_base_stock_si);
			this->groupBox_Stock->Controls->Add(this->lbl_unidad_base_stock);
			this->groupBox_Stock->Controls->Add(this->lbl_nombre_cantidad_actual);
			this->groupBox_Stock->Controls->Add(this->lbl_cantidad_actual);
			this->groupBox_Stock->Controls->Add(this->lbl_nombre_precio);
			this->groupBox_Stock->Controls->Add(this->lbl_precio_producto);
			this->groupBox_Stock->Controls->Add(this->lbl_soles);
			this->groupBox_Stock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox_Stock->Location = System::Drawing::Point(439, 13);
			this->groupBox_Stock->Name = L"groupBox_Stock";
			this->groupBox_Stock->Size = System::Drawing::Size(181, 127);
			this->groupBox_Stock->TabIndex = 28;
			this->groupBox_Stock->TabStop = false;
			this->groupBox_Stock->Text = L"STOCK";
			// 
			// lbl_unidad_base_stock
			// 
			this->lbl_unidad_base_stock->AutoSize = true;
			this->lbl_unidad_base_stock->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_unidad_base_stock->Location = System::Drawing::Point(6, 37);
			this->lbl_unidad_base_stock->Name = L"lbl_unidad_base_stock";
			this->lbl_unidad_base_stock->Size = System::Drawing::Size(84, 18);
			this->lbl_unidad_base_stock->TabIndex = 20;
			this->lbl_unidad_base_stock->Text = L"Unidad Base:";
			// 
			// lbl_unidad_base_stock_si
			// 
			this->lbl_unidad_base_stock_si->AutoSize = true;
			this->lbl_unidad_base_stock_si->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_unidad_base_stock_si->Location = System::Drawing::Point(104, 37);
			this->lbl_unidad_base_stock_si->Name = L"lbl_unidad_base_stock_si";
			this->lbl_unidad_base_stock_si->Size = System::Drawing::Size(25, 15);
			this->lbl_unidad_base_stock_si->TabIndex = 21;
			this->lbl_unidad_base_stock_si->Text = L"- - -";
			// 
			// lbl_marca_modelo_stock
			// 
			this->lbl_marca_modelo_stock->AutoSize = true;
			this->lbl_marca_modelo_stock->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_marca_modelo_stock->Location = System::Drawing::Point(6, 76);
			this->lbl_marca_modelo_stock->Name = L"lbl_marca_modelo_stock";
			this->lbl_marca_modelo_stock->Size = System::Drawing::Size(95, 18);
			this->lbl_marca_modelo_stock->TabIndex = 16;
			this->lbl_marca_modelo_stock->Text = L"Marca/Modelo:";
			// 
			// lbl_marca_modelo_stock_si
			// 
			this->lbl_marca_modelo_stock_si->AutoSize = true;
			this->lbl_marca_modelo_stock_si->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_marca_modelo_stock_si->Location = System::Drawing::Point(104, 76);
			this->lbl_marca_modelo_stock_si->Name = L"lbl_marca_modelo_stock_si";
			this->lbl_marca_modelo_stock_si->Size = System::Drawing::Size(22, 13);
			this->lbl_marca_modelo_stock_si->TabIndex = 22;
			this->lbl_marca_modelo_stock_si->Text = L"- - -";
			// 
			// btn_ver_stock
			// 
			this->btn_ver_stock->BackColor = System::Drawing::SystemColors::ControlLight;
			this->btn_ver_stock->Image = Image::FromFile(L"./img/bttn_carga.png");
			this->btn_ver_stock->Location = System::Drawing::Point(80, 98);
			this->btn_ver_stock->Name = L"btn_ver_stock";
			this->btn_ver_stock->Size = System::Drawing::Size(28, 23);
			this->btn_ver_stock->TabIndex = 28;
			this->btn_ver_stock->UseVisualStyleBackColor = false;
			this->btn_ver_stock->Click += gcnew System::EventHandler(this, &Form1::btn_ver_stock_Click);
			// 
			// panel_borrar_stock
			// 
			this->panel_borrar_stock->Controls->Add(this->lbl_borrar_stock);
			this->panel_borrar_stock->Location = System::Drawing::Point(6, 17);
			this->panel_borrar_stock->Name = L"panel_borrar_stock";
			this->panel_borrar_stock->Size = System::Drawing::Size(169, 78);
			this->panel_borrar_stock->TabIndex = 1;
			// 
			// lbl_borrar_stock
			// 
			this->lbl_borrar_stock->AutoSize = true;
			this->lbl_borrar_stock->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_borrar_stock->Location = System::Drawing::Point(29, 21);
			this->lbl_borrar_stock->Name = L"lbl_borrar_stock";
			this->lbl_borrar_stock->Size = System::Drawing::Size(115, 30);
			this->lbl_borrar_stock->TabIndex = 0;
			this->lbl_borrar_stock->Text = L" Stock de producto\r\n    seleccionado.\r\n";
		


			//==============================================================================================================
			//
			//PANTALLA REPORTE POR EMPLEADO
			//
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5555 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6666 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7777 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8888 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1111 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2222 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3333 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4444 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel_reporte_porEmpleado = (gcnew System::Windows::Forms::Panel());
			this->lbl_titulo_reporte_porEmpleado = (gcnew System::Windows::Forms::Label());
			this->lbl_seleccion_id_porEmpleado = (gcnew System::Windows::Forms::Label());
			this->cbox_sel_id_porEmpleado = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView_reporte_porEmpleado = (gcnew System::Windows::Forms::DataGridView());
			this->porEmpleado_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_fechaConsulta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_nombres = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_apellidoP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_apellidoM = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_dni = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_cantidad_ventas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->porEmpleado_cantidad_dinero = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbl_productos_vendidos_porEmpleado = (gcnew System::Windows::Forms::Label());
			this->dataGridView_reporte_porEmpleado_ventas = (gcnew System::Windows::Forms::DataGridView());
			this->ventas_porEmpleado_fechaDeVenta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ventas_porEmpleado_producto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ventas_porEmpleado_marca = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ventas_porEmpleado_tipo_unidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ventas_porEmpleado_cantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ventas_porEmpleado_pago = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado = (gcnew System::Windows::Forms::Label());
			this->lbl_ventas_respectoMesAnterior_porEmpleado = (gcnew System::Windows::Forms::Label());
			this->panel_reporte_porEmpleado->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_reporte_porEmpleado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_reporte_porEmpleado_ventas))->BeginInit();
			this->SuspendLayout();
			// 
			// panel_reporte_porEmpleado
			// 
			this->panel_reporte_porEmpleado->BackColor = System::Drawing::SystemColors::Control;
			this->panel_reporte_porEmpleado->Controls->Add(this->lbl_ventas_respectoMesAnterior_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->dataGridView_reporte_porEmpleado_ventas);
			this->panel_reporte_porEmpleado->Controls->Add(this->lbl_productos_vendidos_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->dataGridView_reporte_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->cbox_sel_id_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->lbl_seleccion_id_porEmpleado);
			this->panel_reporte_porEmpleado->Controls->Add(this->lbl_titulo_reporte_porEmpleado);
			this->panel_reporte_porEmpleado->Location = System::Drawing::Point(1, 0);
			this->panel_reporte_porEmpleado->Name = L"panel_reporte_porEmpleado";
			this->panel_reporte_porEmpleado->Size = System::Drawing::Size(672, 420);
			this->panel_reporte_porEmpleado->TabIndex = 0;
			// 
			// lbl_titulo_reporte_porEmpleado
			// 
			this->lbl_titulo_reporte_porEmpleado->AutoSize = true;
			this->lbl_titulo_reporte_porEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_titulo_reporte_porEmpleado->Location = System::Drawing::Point(258, 12);
			this->lbl_titulo_reporte_porEmpleado->Name = L"lbl_titulo_reporte_porEmpleado";
			this->lbl_titulo_reporte_porEmpleado->Size = System::Drawing::Size(144, 25);
			this->lbl_titulo_reporte_porEmpleado->TabIndex = 2;
			this->lbl_titulo_reporte_porEmpleado->Text = L"POR EMPLEADO";
			// 
			// lbl_seleccion_id_porEmpleado
			// 
			this->lbl_seleccion_id_porEmpleado->AutoSize = true;
			this->lbl_seleccion_id_porEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_seleccion_id_porEmpleado->Location = System::Drawing::Point(309, 55);
			this->lbl_seleccion_id_porEmpleado->Name = L"lbl_seleccion_id_porEmpleado";
			this->lbl_seleccion_id_porEmpleado->Size = System::Drawing::Size(37, 21);
			this->lbl_seleccion_id_porEmpleado->TabIndex = 11;
			this->lbl_seleccion_id_porEmpleado->Text = L"ID:";
			// 
			// cbox_sel_id_porEmpleado
			// 
			this->cbox_sel_id_porEmpleado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbox_sel_id_porEmpleado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cbox_sel_id_porEmpleado->FormattingEnabled = true;
			this->cbox_sel_id_porEmpleado->Location = System::Drawing::Point(302, 80);
			this->cbox_sel_id_porEmpleado->Name = L"cbox_sel_id_porEmpleado";
			this->cbox_sel_id_porEmpleado->Size = System::Drawing::Size(45, 23);
			this->cbox_sel_id_porEmpleado->TabIndex = 12;
			this->cbox_sel_id_porEmpleado->Tag = L"";
			this->cbox_sel_id_porEmpleado->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbox_sel_id_porEmpleado_SelectedIndexChanged);

			// 
			// dataGridView_reporte_porEmpleado
			// 
			this->dataGridView_reporte_porEmpleado->AllowUserToAddRows = false;
			this->dataGridView_reporte_porEmpleado->AllowUserToDeleteRows = false;
			this->dataGridView_reporte_porEmpleado->AllowUserToResizeColumns = false;
			this->dataGridView_reporte_porEmpleado->AllowUserToResizeRows = false;
			dataGridViewCellStyle1111->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1111->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1111->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1111->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1111->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1111->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1111->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_reporte_porEmpleado->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1111;
			this->dataGridView_reporte_porEmpleado->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView_reporte_porEmpleado->ImeMode = System::Windows::Forms::ImeMode::Off;
			
			///////////////////////////defecto
			this->dataGridView_reporte_porEmpleado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_reporte_porEmpleado->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->porEmpleado_id,
					this->porEmpleado_fechaConsulta, this->porEmpleado_nombres, this->porEmpleado_apellidoP, this->porEmpleado_apellidoM, this->porEmpleado_dni,
					this->porEmpleado_cantidad_ventas, this->porEmpleado_cantidad_dinero
			});
			//-------
			dataGridViewCellStyle4444->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4444->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4444->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4444->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4444->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4444->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4444->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_reporte_porEmpleado->DefaultCellStyle = dataGridViewCellStyle4444;
			this->dataGridView_reporte_porEmpleado->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView_reporte_porEmpleado->ImeMode = System::Windows::Forms::ImeMode::Off;
			
			//////////////////////////defecto
			this->dataGridView_reporte_porEmpleado->Location = System::Drawing::Point(20, 124);
			this->dataGridView_reporte_porEmpleado->Name = L"dataGridView_reporte_porEmpleado";
			this->dataGridView_reporte_porEmpleado->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView_reporte_porEmpleado->RowHeadersVisible = false;
			//------

			dataGridViewCellStyle5555->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5555->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5555->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5555->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5555->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5555->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5555->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_reporte_porEmpleado->RowHeadersDefaultCellStyle = dataGridViewCellStyle5555;
			this->dataGridView_reporte_porEmpleado->RowHeadersVisible = false;
			dataGridViewCellStyle6666->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle6666->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataGridView_reporte_porEmpleado->RowsDefaultCellStyle = dataGridViewCellStyle6666;
			this->dataGridView_reporte_porEmpleado->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			this->dataGridView_reporte_porEmpleado->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));

			///////////////////////////////defecto
			this->dataGridView_reporte_porEmpleado->Size = System::Drawing::Size(630, 68);
			this->dataGridView_reporte_porEmpleado->TabIndex = 24;
			//-----

			// 
			// porEmpleado_id
			// 
			this->porEmpleado_id->HeaderText = L"ID";
			this->porEmpleado_id->Name = L"porEmpleado_id";
			this->porEmpleado_id->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->porEmpleado_id->Width = 39;
			// 
			// porEmpleado_fechaConsulta
			// 
			dataGridViewCellStyle5555->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->porEmpleado_fechaConsulta->DefaultCellStyle = dataGridViewCellStyle5555;
			this->porEmpleado_fechaConsulta->HeaderText = L"FECHA DE CONSULTA";
			this->porEmpleado_fechaConsulta->Name = L"porEmpleado_fechaConsulta";
			this->porEmpleado_fechaConsulta->ReadOnly = true;
			this->porEmpleado_fechaConsulta->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->porEmpleado_fechaConsulta->Width = 150;
			// 
			// porEmpleado_nombres
			// 
			this->porEmpleado_nombres->HeaderText = L"NOMBRES";
			this->porEmpleado_nombres->Name = L"porEmpleado_nombres";
			this->porEmpleado_nombres->Width = 140;
			// 
			// porEmpleado_apellidoP
			// 
			dataGridViewCellStyle6666->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->porEmpleado_apellidoP->DefaultCellStyle = dataGridViewCellStyle6666;
			this->porEmpleado_apellidoP->HeaderText = L"A. PATERNO";
			this->porEmpleado_apellidoP->MinimumWidth = 10;
			this->porEmpleado_apellidoP->Name = L"porEmpleado_apellidoP";
			this->porEmpleado_apellidoP->ReadOnly = true;
			this->porEmpleado_apellidoP->Width = 140;
			// 
			// porEmpleado_apellidoM
			// 
			dataGridViewCellStyle7777->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->porEmpleado_apellidoM->DefaultCellStyle = dataGridViewCellStyle7777;
			this->porEmpleado_apellidoM->HeaderText = L"A. MATERNO";
			this->porEmpleado_apellidoM->Name = L"porEmpleado_apellidoM";
			this->porEmpleado_apellidoM->ReadOnly = true;
			this->porEmpleado_apellidoM->Width = 150;
			// 
			// porEmpleado_dni
			// 
			dataGridViewCellStyle8888->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->porEmpleado_dni->DefaultCellStyle = dataGridViewCellStyle8888;
			this->porEmpleado_dni->HeaderText = L"DNI";
			this->porEmpleado_dni->Name = L"porEmpleado_dni";
			this->porEmpleado_dni->ReadOnly = true;
			this->porEmpleado_dni->Width = 140;
			// 
			// porEmpleado_cantidad_ventas
			// 
			this->porEmpleado_cantidad_ventas->HeaderText = L"CANT. VENTAS";
			this->porEmpleado_cantidad_ventas->Name = L"porEmpleado_cantidad_ventas";
			this->porEmpleado_cantidad_ventas->Width = 130;
			// 
			// porEmpleado_cantidad_dinero
			// 
			this->porEmpleado_cantidad_dinero->HeaderText = L"CANT. DINERO (S/)";
			this->porEmpleado_cantidad_dinero->Name = L"porEmpleado_cantidad_dinero";
			this->porEmpleado_cantidad_dinero->Width = 140;
			// 
			// lbl_productos_vendidos_porEmpleado
			// 
			this->lbl_productos_vendidos_porEmpleado->AutoSize = true;
			this->lbl_productos_vendidos_porEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_productos_vendidos_porEmpleado->Location = System::Drawing::Point(16, 210);
			this->lbl_productos_vendidos_porEmpleado->Name = L"lbl_productos_vendidos_porEmpleado";
			this->lbl_productos_vendidos_porEmpleado->Size = System::Drawing::Size(181, 21);
			this->lbl_productos_vendidos_porEmpleado->TabIndex = 25;
			this->lbl_productos_vendidos_porEmpleado->Text = L"Productos vendidos:";
			// 
			// dataGridView_reporte_porEmpleado_ventas
			// 
			this->dataGridView_reporte_porEmpleado_ventas->AllowUserToAddRows = false;
			this->dataGridView_reporte_porEmpleado_ventas->AllowUserToDeleteRows = false;
			this->dataGridView_reporte_porEmpleado_ventas->AllowUserToResizeColumns = false;
			this->dataGridView_reporte_porEmpleado_ventas->AllowUserToResizeRows = false;
			dataGridViewCellStyle1111->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1111->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1111->Font = (gcnew System::Drawing::Font(L"Cascadia Mono", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1111->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1111->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1111->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1111->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_reporte_porEmpleado_ventas->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1111;
			this->dataGridView_reporte_porEmpleado_ventas->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView_reporte_porEmpleado_ventas->ImeMode = System::Windows::Forms::ImeMode::Off;

			this->dataGridView_reporte_porEmpleado_ventas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_reporte_porEmpleado_ventas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ventas_porEmpleado_fechaDeVenta,
					this->ventas_porEmpleado_producto, this->ventas_porEmpleado_marca, this->ventas_porEmpleado_tipo_unidad, this->ventas_porEmpleado_cantidad,
					this->ventas_porEmpleado_pago
			});
			this->dataGridView_reporte_porEmpleado_ventas->Location = System::Drawing::Point(20, 239);
			this->dataGridView_reporte_porEmpleado_ventas->Name = L"dataGridView_reporte_porEmpleado_ventas";
			this->dataGridView_reporte_porEmpleado_ventas->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView_reporte_porEmpleado_ventas->RowHeadersVisible = false;

			dataGridViewCellStyle5555->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5555->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5555->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5555->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5555->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5555->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5555->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_reporte_porEmpleado_ventas->RowHeadersDefaultCellStyle = dataGridViewCellStyle5555;
			this->dataGridView_reporte_porEmpleado_ventas->RowHeadersVisible = false;
			dataGridViewCellStyle6666->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle6666->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataGridView_reporte_porEmpleado_ventas->RowsDefaultCellStyle = dataGridViewCellStyle6666;
			this->dataGridView_reporte_porEmpleado_ventas->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			this->dataGridView_reporte_porEmpleado_ventas->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));

			this->dataGridView_reporte_porEmpleado_ventas->Size = System::Drawing::Size(630, 104);
			this->dataGridView_reporte_porEmpleado_ventas->TabIndex = 26;
			// 
			// ventas_porEmpleado_fechaDeVenta
			// 
			this->ventas_porEmpleado_fechaDeVenta->HeaderText = L"FECHA DE VENTA";
			this->ventas_porEmpleado_fechaDeVenta->Name = L"ventas_porEmpleado_fechaDeVenta";
			this->ventas_porEmpleado_fechaDeVenta->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ventas_porEmpleado_fechaDeVenta->Width = 130;
			// 
			// ventas_porEmpleado_producto
			// 
			dataGridViewCellStyle1111->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ventas_porEmpleado_producto->DefaultCellStyle = dataGridViewCellStyle1111;
			this->ventas_porEmpleado_producto->HeaderText = L"ID PRODUCTO";
			this->ventas_porEmpleado_producto->Name = L"ventas_porEmpleado_producto";
			this->ventas_porEmpleado_producto->ReadOnly = true;
			this->ventas_porEmpleado_producto->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ventas_porEmpleado_producto->Width = 140;
			// 
			// ventas_porEmpleado_marca
			// 
			this->ventas_porEmpleado_marca->HeaderText = L"TIPO PAGO";
			this->ventas_porEmpleado_marca->Name = L"ventas_porEmpleado_marca";
			this->ventas_porEmpleado_marca->Width = 140;
			// 
			// ventas_porEmpleado_tipo_unidad
			// 
			dataGridViewCellStyle2222->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ventas_porEmpleado_tipo_unidad->DefaultCellStyle = dataGridViewCellStyle2222;
			this->ventas_porEmpleado_tipo_unidad->HeaderText = L"UNIDAD";
			this->ventas_porEmpleado_tipo_unidad->MinimumWidth = 10;
			this->ventas_porEmpleado_tipo_unidad->Name = L"ventas_porEmpleado_tipo_unidad";
			this->ventas_porEmpleado_tipo_unidad->ReadOnly = true;
			this->ventas_porEmpleado_tipo_unidad->Width = 140;
			// 
			// ventas_porEmpleado_cantidad
			// 
			dataGridViewCellStyle3333->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ventas_porEmpleado_cantidad->DefaultCellStyle = dataGridViewCellStyle3333;
			this->ventas_porEmpleado_cantidad->HeaderText = L"CANTIDAD";
			this->ventas_porEmpleado_cantidad->Name = L"ventas_porEmpleado_cantidad";
			this->ventas_porEmpleado_cantidad->ReadOnly = true;
			this->ventas_porEmpleado_cantidad->Width = 150;
			// 
			// ventas_porEmpleado_pago
			// 
			dataGridViewCellStyle4444->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ventas_porEmpleado_pago->DefaultCellStyle = dataGridViewCellStyle4444;
			this->ventas_porEmpleado_pago->HeaderText = L"PAGO (S/)";
			this->ventas_porEmpleado_pago->Name = L"ventas_porEmpleado_pago";
			this->ventas_porEmpleado_pago->ReadOnly = true;
			this->ventas_porEmpleado_pago->Width = 140;
			// 
			// lbl_nombre_ventas_respectoMesAnterior_porEmpleado
			// 
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->AutoSize = true;
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code SemiBold", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->Location = System::Drawing::Point(67, 372);
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->Name = L"lbl_nombre_ventas_respectoMesAnterior_porEmpleado";
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->Size = System::Drawing::Size(460, 21);
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->TabIndex = 27;
			this->lbl_nombre_ventas_respectoMesAnterior_porEmpleado->Text = L"VENTAS TOTALES (DINERO) DE LA EMPRESA: S/.\r\n";
			// 
			// lbl_ventas_respectoMesAnterior_porEmpleado
			// 
			this->lbl_ventas_respectoMesAnterior_porEmpleado->AutoSize = true;
			this->lbl_ventas_respectoMesAnterior_porEmpleado->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_ventas_respectoMesAnterior_porEmpleado->Location = System::Drawing::Point(524, 368);
			this->lbl_ventas_respectoMesAnterior_porEmpleado->Name = L"lbl_ventas_respectoMesAnterior_porEmpleado";
			this->lbl_ventas_respectoMesAnterior_porEmpleado->Size = System::Drawing::Size(34, 25);
			this->lbl_ventas_respectoMesAnterior_porEmpleado->TabIndex = 28;
			this->lbl_ventas_respectoMesAnterior_porEmpleado->Text = L"##";





}

#pragma endregion


		//CLICK BOTON DE LOGIN
	private: System::Void buttonlogin_Click(System::Object^ sender, System::EventArgs^ e) {
		string usuario = this->toStandardString(this->getusuario->Text);
		string password = this->toStandardString(this->getpassword->Text);
		int i = 0; 	char user[10]{ "         " }, pass[10]{ "         " };
		if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
			MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
		}
		while (fread(&var, lr, 1, fd)) {
			if ((strcmp(var.usuario, "NULL") == 0) && (strcmp(var.password, "NULL") == 0)) {
				i = 0;
			}
			else {
				if ((strcmp(var.usuario, usuario.c_str()) == 0) && strcmp(var.password, password.c_str()) == 0) {
					fclose(fd); i++; IDusuarioActual = var.id;
					this->panel_main->Controls->RemoveAt(0);
					this->panel_main->Controls->Add(this->panel_main2);
					this->usuario->Text = this->getusuario->Text;
					if (strcmp(var.tipo_usuario, "Administrador") == 0) { 
						this->mensaje_bienvenida->Text = L"Bienvenido " + this->getusuario->Text + "\ncomo " + "Administrador tienes acceso a todas las opciones."; 
					}
					if (strcmp(var.tipo_usuario, "Vendedor") == 0) {
						this->mensaje_bienvenida->Text = L"Bienvenido " + this->getusuario->Text + "\ncomo " + "Vendedor tienes acceso solo a Registrar Ventas" + "\ny a su Reporte por Empleado";
						this->lk_registroempleados->Enabled = false;
						this->lk_verempleados->Enabled = false;
						this->bttn_inventario->Enabled = false;
					}
					if (strcmp(var.tipo_usuario, "Inventario") == 0) {
						this->mensaje_bienvenida->Text = L"Bienvenido " + this->getusuario->Text + "\ncomo " + "Encargado del Inventario tienes acceso solo \nal Inventario";
						this->lk_registroempleados->Enabled = false;
						this->lk_verempleados->Enabled = false;
						this->lk_registroventas->Enabled = false;
					}
					this->mensaje_bienvenida->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					break;
				}
			}
		}
		if (i < 1) {
			MessageBox::Show(L"El usuario y/o la contraseña es incorrecta.");
		}
		limpiarStruct();
	}

		   //CONVERTIR DE SYSTEMSTRING A STANDARSTRING
	private: static string toStandardString(System::String^ string) {
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}

		   //CONVERTIR DE STANDARSTRING A SYSTEMSTRING
	private: static String^ toSystemString(string str) {
		return gcnew String(str.c_str());
	}

		   //FUNCIONES MENU PRINCIPAL
		   //BOTÓN SALIR
	private: System::Void bttn_salir_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(1);
	}

		   //FUNCIONES TIPO EMPLEADOS
		   //BOTON SIGUIENTE
	private: System::Void bttn_sgte_1_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = 0;
		if (tipo_administrador->Checked == true) {
			i++;
		}
		if (tipo_vendedor->Checked == true) {
			i++;
		}
		if (tipo_inventario->Checked == true) {
			i++;
		}
		if (tipo_seguridad->Checked == true) {
			i++;
		}
		if (tipo_limpieza->Checked == true) {
			i++;
		}
		if (i > 1) {
			MessageBox::Show(L"Solo debe marcar una opción");
		}
		else {
			if (i == 0) {
				MessageBox::Show(L"No ha seleccionado ninguna opción");
			}
			else {
				if (tipo_administrador->Checked == true) {
					tipo_administrador->Checked = false; tipoUser = "Administrador";
					this->panel_interfaces->Controls->RemoveAt(0);
					this->panel_interfaces->Controls->Add(this->panel_registrar_empleado);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_usuario);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_contra);
					this->panel_registrar_empleado->Controls->Add(this->lbl_usuario);
					this->panel_registrar_empleado->Controls->Add(this->lbl_contraseña);
				}
				if (tipo_vendedor->Checked == true) {
					tipo_vendedor->Checked = false;	tipoUser = "Vendedor";
					this->panel_interfaces->Controls->RemoveAt(0);
					this->panel_interfaces->Controls->Add(this->panel_registrar_empleado);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_usuario);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_contra);
					this->panel_registrar_empleado->Controls->Add(this->lbl_usuario);
					this->panel_registrar_empleado->Controls->Add(this->lbl_contraseña);
				}
				if (tipo_inventario->Checked == true) {
					tipo_inventario->Checked = false; tipoUser = "Inventario";
					this->panel_interfaces->Controls->RemoveAt(0);
					this->panel_interfaces->Controls->Add(this->panel_registrar_empleado);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_usuario);
					this->panel_registrar_empleado->Controls->Add(this->txt_reg_contra);
					this->panel_registrar_empleado->Controls->Add(this->lbl_usuario);
					this->panel_registrar_empleado->Controls->Add(this->lbl_contraseña);
				}
				if (tipo_seguridad->Checked == true) {
					tipo_seguridad->Checked = false; tipoUser = "Seguridad";
					this->panel_interfaces->Controls->RemoveAt(0);
					this->panel_interfaces->Controls->Add(this->panel_registrar_empleado);
					this->panel_registrar_empleado->Controls->Remove(this->txt_reg_usuario);
					this->panel_registrar_empleado->Controls->Remove(this->txt_reg_contra);
					this->panel_registrar_empleado->Controls->Remove(this->lbl_usuario);
					this->panel_registrar_empleado->Controls->Remove(this->lbl_contraseña);

				}
				if (tipo_limpieza->Checked == true) {
					tipo_limpieza->Checked = false; tipoUser = "Limpieza";
					this->panel_interfaces->Controls->RemoveAt(0);
					this->panel_interfaces->Controls->Add(this->panel_registrar_empleado);
					this->panel_registrar_empleado->Controls->Remove(this->txt_reg_usuario);
					this->panel_registrar_empleado->Controls->Remove(this->txt_reg_contra);
					this->panel_registrar_empleado->Controls->Remove(this->lbl_usuario);
					this->panel_registrar_empleado->Controls->Remove(this->lbl_contraseña);

				}
			}
		}

	}

		   //BOTON CANCELAR
	private: System::Void bttn_cancelar_1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->panel_interfaces->Controls->Add(this->mensaje_bienvenida);
	}

		   //FUNCIONES REGISTRAR EMPLEADOS
		   //BOTÓN MENÚ PRINCIPAL
	private: System::Void menu_main_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->tittle_menu->Text = L"MENÚ PRINCIPAL";
		this->panel_interfaces->Controls->Add(this->mensaje_bienvenida);
		txt_reg_nombres->Clear(); txt_reg_apellidopaterno->Clear();
		txt_reg_apellidomaterno->Clear(); txt_reg_dni->Clear();
		date_reg_fechanacimiento->ResetText(); txt_reg_domicilio->Clear();
		txt_reg_numeroTel->Clear(); txt_reg_usuario->Clear();
		txt_reg_contra->Clear();
	}

		   //BOTÓN REGISTRAR EMPLEADOS
	private: System::Void lk_registroempleados_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->tittle_menu->Text = L"OPERACIONES";
		this->panel_interfaces->Controls->Add(this->panel_tipo_empleados);
	}
		   //BOTÓN GUARDAR - REGISTRO EMPLEADO
	private: System::Void btn_guardar_regEmpleado_Click(System::Object^ sender, System::EventArgs^ e) {

		if (tipoUser == "Administrador" || tipoUser == "Vendedor" || tipoUser == "Inventario") {
			if (txt_reg_nombres->Text == "" || txt_reg_apellidopaterno->Text == "" ||
				txt_reg_apellidomaterno->Text == "" || txt_reg_dni->Text == "" ||
				txt_reg_domicilio->Text == "" || txt_reg_numeroTel->Text == "" || txt_reg_usuario->Text == "" ||
				txt_reg_contra->Text == "") {
				MessageBox::Show(L"No se ha completado todos los campos."); //Validamos
				return;
			}
		}
		else {
			if (txt_reg_nombres->Text == "" || txt_reg_apellidopaterno->Text == "" ||
				txt_reg_apellidomaterno->Text == "" || txt_reg_dni->Text == "" ||
				txt_reg_domicilio->Text == "" || txt_reg_numeroTel->Text == "") {
				MessageBox::Show(L"No se ha completado todos los campos."); //Validamos
				return;
			}
			txt_reg_usuario->Text = "NULL"; txt_reg_contra->Text = "NULL";
		}

		registrarEmpleado();

		//AGREGAR FILA A LA TABLA
		int n_fila;
		n_fila = revisarUltimoId();

			if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
				MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
			}
			while (fread(&var, lr, 1, fd)) {
				if (n_fila == var.id) {
					//Creamos nueva fila
					n_fila = tabla_verEmpleados->Rows->Add();

					//Agregamos la información
					tabla_verEmpleados->Rows[n_fila]->Cells[0]->Value = var.id;
					tabla_verEmpleados->Rows[n_fila]->Cells[1]->Value = toSystemString(var.nombres);
					tabla_verEmpleados->Rows[n_fila]->Cells[2]->Value = toSystemString(var.apellidoPaterno);
					tabla_verEmpleados->Rows[n_fila]->Cells[3]->Value = toSystemString(var.apellidoMaterno);
					tabla_verEmpleados->Rows[n_fila]->Cells[4]->Value = toSystemString(var.nacimiento);
					tabla_verEmpleados->Rows[n_fila]->Cells[5]->Value = toSystemString(var.telefono);
					tabla_verEmpleados->Rows[n_fila]->Cells[6]->Value = toSystemString(var.direccion);
					tabla_verEmpleados->Rows[n_fila]->Cells[7]->Value = toSystemString(var.tipo_usuario);
				}
			}
			fclose(fd);
		
		MessageBox::Show(L"Empleado registrado correctamente.");
		txt_reg_nombres->Clear(); txt_reg_apellidopaterno->Clear();
		txt_reg_apellidomaterno->Clear(); txt_reg_dni->Clear();
		date_reg_fechanacimiento->ResetText(); txt_reg_domicilio->Clear();
		txt_reg_numeroTel->Clear(); txt_reg_usuario->Clear();
		txt_reg_contra->Clear();
		this->panel_interfaces->Controls->RemoveAt(0);
		this->panel_interfaces->Controls->Add(this->panel_tipo_empleados);
	}

		   //BOTÓN CANCELAR - REGISTRO EMPLEADO
	private: System::Void btn_cancelar_regEmpleado_Click(System::Object^ sender, System::EventArgs^ e) {
		txt_reg_nombres->Clear(); txt_reg_apellidopaterno->Clear();
		txt_reg_apellidomaterno->Clear(); txt_reg_dni->Clear();
		date_reg_fechanacimiento->ResetText(); txt_reg_domicilio->Clear();
		date_reg_fechanacimiento->ResetText(); txt_reg_domicilio->Clear();
		txt_reg_numeroTel->Clear(); txt_reg_usuario->Clear();
		txt_reg_contra->Clear();
		this->panel_interfaces->Controls->RemoveAt(0);
		this->panel_interfaces->Controls->Add(this->mensaje_bienvenida);
	}

		   //Registrar empleado con archivo con datos
		   void registrarEmpleado() {
			   int pos, num = revisarUltimoId();
			   if ((fd = fopen("./registros/Empleados.txt", "r+t")) == NULL) {
				   exit(1);
			   }
			   num++;
			   var.id = num;
			   strcpy(var.nombres, this->toStandardString(this->txt_reg_nombres->Text).c_str());
			   strcpy(var.apellidoPaterno, this->toStandardString(this->txt_reg_apellidopaterno->Text).c_str());
			   strcpy(var.apellidoMaterno, this->toStandardString(this->txt_reg_apellidomaterno->Text).c_str());
			   strcpy(var.dni, this->toStandardString(this->txt_reg_dni->Text).c_str());
			   strcpy(var.nacimiento, this->toStandardString(this->date_reg_fechanacimiento->Text).c_str());
			   strcpy(var.direccion, this->toStandardString(this->txt_reg_domicilio->Text).c_str());
			   strcpy(var.telefono, this->toStandardString(this->txt_reg_numeroTel->Text).c_str());
			   strcpy(var.usuario, this->toStandardString(this->txt_reg_usuario->Text).c_str());
			   strcpy(var.password, this->toStandardString(this->txt_reg_contra->Text).c_str());
			   strcpy(var.tipo_usuario, tipoUser.c_str());
			   
			   var.numVentas = 0;
			   var.dinero = 0.0f;
			   strcpy(var.estado, "s");
			   
			   pos = (num - 1) * lr;
			   fseek(fd, pos, 0);
			   fwrite(&var, lr, 1, fd);
			   fclose(fd);
			   limpiarStruct();
		   }

		   //Limpiar espacios en blanco
		   void limpiarStruct() {
			   strcpy(var.apellidoMaterno, "          ");
			   strcpy(var.apellidoPaterno, "          ");
			   strcpy(var.password, "               ");
			   strcpy(var.direccion, "                              ");
			   strcpy(var.nacimiento, "          ");
			   strcpy(var.nombres, "                    ");
			   strcpy(var.telefono, "         ");
			   strcpy(var.dni, "         ");
			   strcpy(var.usuario, "          ");
			   strcpy(var.tipo_usuario, "            ");
		   }

		   //Para revisar el último ID del registro de empleados
		   int revisarUltimoId() {
			   if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
				   exit(1);
			   }
			   int numero;
			   while (fread(&var, lr, 1, fd)) {
				   numero = var.id;
			   }
			   fclose(fd); //Cerrar archivo
			   limpiarStruct();
			   return numero;
		   }


	//FUNCIONES VER EMPLEADOS
			//CLICK VER EMPLEADOS
	private: System::Void lk_verempleados_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->tittle_menu->Text = L"OPERACIONES";
		this->panel_interfaces->Controls->RemoveAt(0);
		this->panel_interfaces->Controls->Add(this->panel_verEmpleados);
	}
	//FUNCIONES INVENTARIO
		//CLICK BOTÓN INVENTARIO
	private: System::Void bttn_inventario_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->panel_interfaces->Controls->Add(this->panel_Inventario);
		this->tittle_menu->Text = L"INVENTARIO";
	}

	   //Para revisar el último ID del registro de inventario
    int revisarUltimoId2() {
	   if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
		   exit(1);
	   }
	   int numero;
	   while (fread(&prod, lf, 1, fr)) {
		   numero = prod.id;
	   }
	   fclose(fr); //Cerrar archivo
	   return numero;
    }

		// MARCAR AGREGAR
	private: System::Void select_agregar_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		
		if (select_agregar->Checked == true) {
			this->select_id->Enabled = false;
			this->get_nombreprod->Enabled = true;
			this->get_tipoprod->Enabled = true;
			this->bttn_cargar->Visible = false;
			this->get_nombreprod->Clear();
			this->get_tipoprod->Text = L"";
			this->get_cantidadprod->Clear();
			this->get_precioprod->Clear();
			int num = revisarUltimoId2();
			num++;
			this->select_id->Items->Clear();
			this->select_id->Text = L"" + num;
		}
		
	}
		//MARCAR MODIFICAR
	private: System::Void select_modificar_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (select_modificar->Checked == true) {
			this->select_id->Enabled = true;
			this->get_nombreprod->Enabled = false;
			this->get_tipoprod->Enabled = false;
			this->get_nombreprod->Clear();
			this->get_tipoprod->Text = L"";
			this->get_cantidadprod->Clear();
			this->get_precioprod->Clear();
			this->bttn_cargar->Visible = true;
			int num = revisarUltimoId2(), i = 0;
			this->select_id->Items->Clear();
			this->select_id->Text = "";
			while (i <= num) {
				if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
					MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
				}
				while (fread(&prod, lf, 1, fr)) {
					if ((i == prod.id) && (i != 0)) {
						this->select_id->Items->Add(L"" + i);
					}
				}
				fclose(fr);
				i++;
			}
		}
	}


		//Limpiar espacios en blanco
    void limpiarStruct2() {
	   strcpy(prod.nombre, "                    ");
	   strcpy(prod.tipo, "                    ");
	}

	//	CLICK EN BOTÓN CARGAR
	private: System::Void bttn_cargar_Click(System::Object^ sender, System::EventArgs^ e) {
		int aux = revisarUltimoId2();
		if ((strcmp(toStandardString(select_id->Text).c_str(), "") != 0) && (atoi(this->toStandardString(this->select_id->Text).c_str()) <= aux) && (atoi(this->toStandardString(this->select_id->Text).c_str()) > 0)) {
			if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
				MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
			}
			while (fread(&prod, lf, 1, fr)) {
				if (atoi(this->toStandardString(this->select_id->Text).c_str()) == prod.id) {
					this->get_cantidadprod->Text = L"" + prod.cantidad;
					this->get_precioprod->Text = L"" + prod.precio;
					this->get_nombreprod->Text = L"" + this->toSystemString(prod.nombre);
					this->get_tipoprod->Text = L"" + this->toSystemString(prod.tipo);
				}
			}
		}
		else {
			MessageBox::Show(L"El ID no ha sido encontrado.");
		}
	}

		//CLICK EN CONFIMAR
	private: System::Void bttn_confirmar_inventario_Click(System::Object^ sender, System::EventArgs^ e) {

		if ((select_agregar->Checked == false) && (select_modificar->Checked == false)) {
			MessageBox::Show(L"No se ha marcado ninguna opción."); //Validamos
			return;
		}

		if (select_id->Text == "" || get_nombreprod->Text == "" ||
			get_tipoprod->Text == "" || get_cantidadprod->Text == "" ||
			get_precioprod->Text == "") {
			MessageBox::Show(L"No se ha completado todos los campos."); //Validamos
			return;
		}

		//SI SE MARCA AGREGAR
		if (select_agregar->Checked == true) {
			int pos, num = revisarUltimoId2();
			if ((fr = fopen("./registros/Inventario.txt", "r+t")) == NULL) {
				exit(1);
			}
			num++;
			prod.id = atoi(this->toStandardString(this->select_id->Text).c_str());
			strcpy(prod.nombre, this->toStandardString(this->get_nombreprod->Text).c_str());
			strcpy(prod.tipo, this->toStandardString(this->get_tipoprod->Text).c_str());
			prod.cantidad = atof(this->toStandardString(this->get_cantidadprod->Text).c_str());
			prod.precio = atof(this->toStandardString(this->get_precioprod->Text).c_str());
			pos = (num - 1) * lf;
			fseek(fr, pos, 0);
			fwrite(&prod, lf, 1, fr);
			fclose(fr);
			limpiarStruct2();
			MessageBox::Show(L"Producto registrado correctamente.");
			select_id->Text = "";
			get_nombreprod->Clear();
			get_tipoprod->Text = "";
			get_cantidadprod->Clear();
			get_precioprod->Clear();

			//AGREGAR FILA A LA TABLA
			int n_fila;
			n_fila = revisarUltimoId2();

			if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
				MessageBox::Show(L"Se produjo un error al leer el archivo."); exit(1);
			}
			while (fread(&prod, lf, 1, fr)) {
				if (n_fila == prod.id) {
					//Creamos nueva fila
					n_fila = tabla_Inventario->Rows->Add();

					//Agregamos la información
					tabla_Inventario->Rows[n_fila]->Cells[0]->Value = prod.id;
					tabla_Inventario->Rows[n_fila]->Cells[1]->Value = toSystemString(prod.nombre);
					tabla_Inventario->Rows[n_fila]->Cells[2]->Value = toSystemString(prod.tipo);
					tabla_Inventario->Rows[n_fila]->Cells[3]->Value = prod.cantidad;
					tabla_Inventario->Rows[n_fila]->Cells[4]->Value = L"S/ " + prod.precio;
				}
			}
			fclose(fr);
		}

		//SI SE MARCA MODIFICAR
		if (select_modificar->Checked == true) {
			int pos, aux = atoi(this->toStandardString(this->select_id->Text).c_str());
			if ((fr = fopen("./registros/Inventario.txt", "r+t")) == NULL) {
				exit(1);
			}
			while (fread(&prod, lf, 1, fr)) {
				if (aux == prod.id) {
					//MODIFICAR EN EL ARCHIVO
					prod.cantidad = atof(this->toStandardString(this->get_cantidadprod->Text).c_str());
					prod.precio = atof(this->toStandardString(this->get_precioprod->Text).c_str());
					pos = (prod.id-1) * lf;
					fseek(fr, pos, 0);
					fwrite(&prod, lf, 1, fr);
					fclose(fr);
					//MODIFICAR TABLA
					tabla_Inventario->Rows[aux-1]->Cells[3]->Value = prod.cantidad;
					tabla_Inventario->Rows[aux-1]->Cells[4]->Value = L"S/ " + prod.precio;
				}
			}
			
			MessageBox::Show(L"Producto modificado correctamente.");
			select_id->Text = "";
			get_nombreprod->Clear();
			get_tipoprod->Text = "";
			get_cantidadprod->Clear();
			get_precioprod->Clear();
		}
		
		select_modificar->Checked = false;
		select_agregar->Checked = false;
	}

		//CLICK EN CANCELAR
	private: System::Void bttn_cancelar_inventario_Click(System::Object^ sender, System::EventArgs^ e) {
		select_id->Text = "";
		get_nombreprod->Clear();
		get_tipoprod->Text = "";
		get_cantidadprod->Clear();
		get_precioprod->Clear();
		select_modificar->Checked = false;
		select_agregar->Checked = false;
	}


	
		   
		   
		   
		   
		   
	//CLICK REGISTRAR VENTA 
		private: System::Void lk_registroventas_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->tittle_menu->Text = L"OPERACIONES";
		this->panel_interfaces->Controls->Add(this->panel_reg_ventas);
		
		//Limpiamos
		this->cbox_selec_categoria->SelectedIndex = -1;
		this->cbox_selec_producto->SelectedIndex = -1;
		this->cbox_tipo_pago->SelectedIndex = -1;
		this->cbox_selec_producto->Items->Clear(); 
		this->lbl_precioTotal->Text = L"0"; 
		SumaGlobal = 0;
		dataGridView_ventas->Rows->Clear();
		this->btn_confirmar_compra->Enabled = false;
		this->lbl_titular_pago->Visible = false;
		this->txt_titular_pago->Visible = false;
		this->txt_titular_pago->Clear();

		this->cbox_marca_modelo->SelectedIndex = -1;
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->txt_precio_semitotal->Clear();
		this->txt_cant_prod->Clear();
		//Stock
		this->lbl_cantidad_actual->Text = L"0";
		this->lbl_unidad_base_stock_si->Text = L"- - -";
		this->lbl_precio_producto->Text = L"0";
		this->lbl_marca_modelo_stock_si->Text = L"- - -";
		this->panel_borrar_stock->Visible = true;
		xyz = -1;

	}

	//SELECCIONADOR CATEGORIA - REGISTRAR VENTA
	private: System::Void cbox_selec_categoria_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		this->cbox_selec_producto->Items->Clear(); //borramos
		this->cbox_marca_modelo->Items->Clear(); //borramos
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->panel_borrar_stock->Visible = true;

		if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&prod, lf, 1, fr)) { //leemos y cambiamos las opciones para elegir producto según la categoría elegida
			if (strcmp(prod.tipo, this->toStandardString(this->cbox_selec_categoria->Text).c_str()) == 0) {
				cbox_selec_producto->Items->Add(this->toSystemString(prod.nombre)); //Agrega opción en productos
			}
		}
		fclose(fr); //Cerrar archivo
		limpiarStruct2();
	}

	//SELECCIONADOR PRODUCTO - REGISTRO VENTAS
	private: System::Void cbox_selec_producto_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		this->cbox_marca_modelo->Items->Clear(); //borramos
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->panel_borrar_stock->Visible = true;
		
		if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&prod, lf, 1, fr)) {
			if (strcmp(prod.nombre, this->toStandardString(this->cbox_selec_producto->Text).c_str()) == 0) {
				cbox_marca_modelo->Items->Add(this->toSystemString(prod.marca)); //Agrega opción en marcas
			}
		}
		fclose(fr); //Cerrar archivo
		limpiarStruct2();
	}

	//SELECCIONADOR DE MARCA - REGISTRO VENTA
	private: System::Void cbox_marca_modelo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->cbox_unidadVenta->Items->RemoveAt(0);
		this->panel_borrar_stock->Visible = true;

		if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&prod, lf, 1, fr)) {
			if (strcmp(prod.nombre, this->toStandardString(this->cbox_selec_producto->Text).c_str()) == 0 &&
				strcmp(prod.marca, this->toStandardString(this->cbox_marca_modelo->Text).c_str()) == 0) {
				
				this->cbox_unidadVenta->Items->Insert(0, this->toSystemString(prod.unidadBase));
				break;
			}
		}
		fclose(fr); //Cerrar archivo
		limpiarStruct2();
	}



	//BOTÓN AGREGAR A LISTA DE COMPRA [+]- REGISTRO VENTAS
	private: System::Void btn_agregar_a_lista_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cbox_selec_categoria->Text == "" || cbox_selec_producto->Text == "" ||
			cbox_marca_modelo->Text == "" || cbox_unidadVenta->Text == "" || txt_cant_prod->Text == ""
			|| txt_precio_semitotal->Text == "") {
			MessageBox::Show(L"Faltan completar campos."); return;
		}
		if (atoi(this->toStandardString(this->txt_cant_prod->Text).c_str()) >
			atoi(this->toStandardString(this->lbl_cantidad_actual->Text).c_str()) ||
			atoi(this->toStandardString(this->txt_cant_prod->Text).c_str()) < 1) { //rango válido
			MessageBox::Show(L"Cantidad no válida. Verifique la cantidad actual del producto."); return;
		}

		//AGREGAR FILA A LA LISTA
		int n_fila;
		//Creamos nueva fila
		n_fila = dataGridView_ventas->Rows->Add();
		//Agregamos la información
		dataGridView_ventas->Rows[n_fila]->Cells[0]->Value = n_fila + 1;
		dataGridView_ventas->Rows[n_fila]->Cells[1]->Value = cbox_selec_producto->Text;
		dataGridView_ventas->Rows[n_fila]->Cells[2]->Value = cbox_marca_modelo->Text;
		dataGridView_ventas->Rows[n_fila]->Cells[3]->Value = cbox_unidadVenta->Text;
		dataGridView_ventas->Rows[n_fila]->Cells[4]->Value = txt_cant_prod->Text;
		dataGridView_ventas->Rows[n_fila]->Cells[5]->Value = txt_precio_semitotal->Text;

		//Leemos id de producto y cantidad
		xyz = xyz + 1;
		if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&prod, lf, 1, fr)) {
			if (strcmp(prod.nombre, this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[n_fila]->Cells[1]->Value)).c_str()) == 0) {
				aux_idprod[xyz] = prod.id;
				aux_cant[xyz] = atof(this->toStandardString(txt_cant_prod->Text).c_str());
			}
		}
		fclose(fr); 


		//Precio total
		SumaGlobal = atoi(this->toStandardString(this->txt_precio_semitotal->Text).c_str()) + SumaGlobal;
		this->lbl_precioTotal->Text = L"" + SumaGlobal;

		//activamos confirmar
		this->btn_confirmar_compra->Enabled = true;

		//limpiamos
		this->cbox_selec_categoria->SelectedIndex = -1;
		this->cbox_selec_producto->SelectedIndex = -1;
		this->cbox_selec_producto->Items->Clear(); 
		this->txt_cant_prod->Clear();
		this->lbl_precio_producto->Text = L"0";
		this->lbl_cantidad_actual->Text = L"0";
		this->cbox_marca_modelo->SelectedIndex = -1;
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->txt_precio_semitotal->Clear();
		this->txt_cant_prod->Clear();
		//Stock
		this->lbl_cantidad_actual->Text = L"0";
		this->lbl_unidad_base_stock_si->Text = L"- - -";
		this->lbl_precio_producto->Text = L"0";
		this->lbl_marca_modelo_stock_si->Text = L"- - -";
		this->panel_borrar_stock->Visible = true;
	}


	//BOTÓN CANCELAR - REGISTRO DE VENTAS
	private: System::Void btn_cancelar_compra_Click(System::Object^ sender, System::EventArgs^ e) {
		this->cbox_selec_categoria->SelectedIndex = -1;
		this->cbox_selec_producto->SelectedIndex = -1;
		this->cbox_tipo_pago->SelectedIndex = -1;
		this->txt_cant_prod->Clear();
		this->cbox_selec_producto->Items->Clear(); 
		this->lbl_precio_producto->Text = L"0"; 
		this->lbl_cantidad_actual->Text = L"0";
		this->lbl_precioTotal->Text = L"0";
		SumaGlobal = 0;
		dataGridView_ventas->Rows->Clear();
		this->btn_confirmar_compra->Enabled = false;

		this->lbl_titular_pago->Visible = false;
		this->txt_titular_pago->Visible = false;
		this->txt_titular_pago->Clear();

		this->cbox_marca_modelo->SelectedIndex = -1;
		this->cbox_unidadVenta->SelectedIndex = -1;
		this->txt_precio_semitotal->Clear();
		this->txt_cant_prod->Clear();
		//Stock
		this->lbl_cantidad_actual->Text = L"0";
		this->lbl_unidad_base_stock_si->Text = L"- - -";
		this->lbl_precio_producto->Text = L"0";
		this->lbl_marca_modelo_stock_si->Text = L"- - -";
		this->panel_borrar_stock->Visible = true;
		xyz = -1;

	}


	//BOTÓN CONFIRMAR - REGISTRO DE VENTAS
	private: System::Void btn_confirmar_compra_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cbox_tipo_pago->Text == "" ) { //Validar campo completado
			MessageBox::Show(L"Faltan completar el tipo de pago."); return;
		}
	
		int n_fila = dataGridView_ventas->RowCount, pos, numVentasTotalLista = 0,idProd;

		for (int i = 0; i < n_fila; i++) {
			//DESCONTAMOS CANTIDAD EN INVENTARIO DE PRODUCTOS VENDIDOS
			if ((fr = fopen("./registros/Inventario.txt", "r+t")) == NULL) {
				exit(1);
			}
			while (fread(&prod, lf, 1, fr)) {
				if (strcmp(prod.nombre, this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[1]->Value)).c_str())==0) { //Producto
					//MODIFICAR EN EL ARCHIVO
					prod.cantidad = prod.cantidad - atoi(this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[4]->Value)).c_str()); //Cantidad
					idProd = prod.id;
					pos = (prod.id - 1) * lf;
					fseek(fr, pos, 0);
					fwrite(&prod, lf, 1, fr);
					//MODIFICAR TABLA
					tabla_Inventario->Rows[prod.id - 1]->Cells[5]->Value = prod.cantidad;
					break;
				}
			}
			fclose(fr);
			limpiarStruct2();

			//GUARDAMOS EN ARCHIVO EL REGISTRO DE VENTAS
			int num = revisarUltimoId3();
			DateTime local = DateTime::Now; //Fecha actual
			if ((fv = fopen("./registros/Ventas.txt", "r+t")) == NULL) {
				exit(1);
			}
			num++;
			vent.num = num;
			strcpy(vent.fecha, this->toStandardString(System::Convert::ToString(local.ToString("d"))).c_str());
			vent.idProducto = idProd;
			vent.idEmpleado = IDusuarioActual;
			strcpy(vent.unidadVenta, this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[3]->Value)).c_str()); //Tipo pago
			vent.cantidad = atoi(this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[4]->Value)).c_str()); //Cantidad
			vent.dinero = atof(this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[5]->Value)).c_str()); //Dinero = cant x precio
			strcpy(vent.tipoPago, this->toStandardString(cbox_tipo_pago->Text).c_str()); //Tipo pago
			if (cbox_tipo_pago->SelectedIndex == 0) {
				strcpy(vent.titular, "NULL");
			}
			else {
				strcpy(vent.titular, this->toStandardString(txt_titular_pago->Text).c_str());
			}
			pos = (num - 1) * lv;
			fseek(fv, pos, 0);
			fwrite(&vent, lv, 1, fv);
			fclose(fv);
			limpiarStruct3();

			//Suma num ventas de la lista (cantidad)
			numVentasTotalLista = numVentasTotalLista + atoi(this->toStandardString(System::Convert::ToString(dataGridView_ventas->Rows[i]->Cells[2]->Value)).c_str()); //Cantidad
		}
		//fin bucle

		//AUMENTAMOS DINERO Y CANTIDAD DE VENTAS DEL EMPLEADO 
		if ((fd = fopen("./registros/Empleados.txt", "r+t")) == NULL) {
			exit(1);
		}
		while (fread(&var, lr, 1, fd)) {
			if (var.id == IDusuarioActual) {
				//MODIFICAR EN EL ARCHIVO
				var.numVentas = var.numVentas + numVentasTotalLista;
				var.dinero = var.dinero + SumaGlobal;
				pos = (var.id - 1) * lr;
				fseek(fd, pos, 0);
				fwrite(&var, lr, 1, fd);
				break;
			}
		}
		fclose(fd);
		limpiarStruct();

		//Confirmamos en mensaje
		MessageBox::Show(L"Venta registrada correctamente.");
		
		//LIMPIAMOS TODO
		this->cbox_selec_categoria->SelectedIndex = -1;
		this->cbox_selec_producto->SelectedIndex = -1;
		this->cbox_tipo_pago->SelectedIndex = -1;
		this->txt_cant_prod->Clear();
		this->cbox_selec_producto->Items->Clear();
		this->lbl_precio_producto->Text = L"0";
		this->lbl_cantidad_actual->Text = L"0";
		this->lbl_precioTotal->Text = L"0";
		SumaGlobal = 0;
		dataGridView_ventas->Rows->Clear();
		this->btn_confirmar_compra->Enabled = false;
		this->lbl_titular_pago->Visible = false;
		this->txt_titular_pago->Visible = false;
		this->txt_titular_pago->Clear();
		this->panel_borrar_stock->Visible = true;
		xyz = -1;

	}


	//LIMPIAR ESTRUCTURA VENTAS
	void limpiarStruct3() {
		strcpy(vent.fecha, "                              ");
		strcpy(vent.unidadVenta, "                        ");
		strcpy(vent.tipoPago, "                           ");
		strcpy(vent.titular, "                            ");
	}

	//Revisar ultimo ID en Ventas
	int revisarUltimoId3() {
		if ((fv = fopen("./registros/Ventas.txt", "rt")) == NULL) {
			exit(1);
		}
		int numero;
		while (fread(&vent, lv, 1, fv)) {
			numero = vent.num;
		}
		fclose(fv); //Cerrar archivo
		return numero;
	}

	//SI HAY CAMBIO EN TIPO DE PAGO - REGISTRO VENTAS
	private: System::Void cbox_tipo_pago_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbox_tipo_pago->SelectedIndex == 0 || cbox_tipo_pago->SelectedIndex == -1 ) {
			this->lbl_titular_pago->Visible = false;
			this->txt_titular_pago->Visible = false;
			this->txt_titular_pago->Clear();
		}
		if (cbox_tipo_pago->SelectedIndex == 1) {
			this->lbl_titular_pago->Visible = true;
			this->txt_titular_pago->Visible = true;
		}
	}

	//BOTON CARGAR STOCK DE PRODUCTO SELECCIONADO
	private: System::Void btn_ver_stock_Click(System::Object^ sender, System::EventArgs^ e) {
		//validamos
		if (cbox_selec_categoria->Text == "" || cbox_selec_producto->Text == "" ||
			cbox_marca_modelo->Text == "" ) {
			MessageBox::Show(L"Faltan completar campos."); return;
		}
		this->panel_borrar_stock->Visible = false; int i = 0;

		if ((fr = fopen("./registros/Inventario.txt", "rt")) == NULL) {
			exit(1);
		}
		
		while (fread(&prod, lf, 1, fr)) {
			if (strcmp(prod.nombre, this->toStandardString(this->cbox_selec_producto->Text).c_str()) == 0
				&& strcmp(prod.tipo, this->toStandardString(this->cbox_selec_categoria->Text).c_str()) == 0
				&& strcmp(prod.marca, this->toStandardString(this->cbox_marca_modelo->Text).c_str()) == 0) {

				for (i = 0; i <= xyz; i++) {
					if (prod.id == aux_idprod[i]) {
						prod.cantidad = prod.cantidad - aux_cant[i];
					}
				}
				this->lbl_cantidad_actual->Text = L""+ prod.cantidad;
				this->lbl_unidad_base_stock_si->Text = toSystemString(prod.unidadBase);
				this->lbl_precio_producto->Text = L"" + prod.precio;
				this->lbl_marca_modelo_stock_si->Text = toSystemString(prod.marca);
				break;
			}
		}
		fclose(fr); //Cerrar archivo
		limpiarStruct2();

	}





	//REPORTE POR EMPLEADO ==================================================================================
	//BOTON REPORTE POR EMPLEADO (LINK)
	private: System::Void bttn_reportes_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel_interfaces->Controls->RemoveAt(0);
		this->tittle_menu->Text = L"REPORTES";
		this->panel_interfaces->Controls->Add(this->panel_reporte_porEmpleado);

		dataGridView_reporte_porEmpleado->Rows->Clear();
		dataGridView_reporte_porEmpleado_ventas->Rows->Clear();
		this->cbox_sel_id_porEmpleado->SelectedIndex = -1;
		this->lbl_ventas_respectoMesAnterior_porEmpleado->Text = L"##";

		//LLENAMOS SELECCIONADOR DE ID
		this->cbox_sel_id_porEmpleado->Items->Clear();
		if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&var, lr, 1, fd)) { //leemos y agregamos id
			if (strcmp(var.tipo_usuario, "Administrador") == 0 || strcmp(var.tipo_usuario, "Vendedor") == 0) {
				cbox_sel_id_porEmpleado->Items->Add(var.id); //Agrega opción en id
			}
		}
		fclose(fd); //Cerrar archivo
		limpiarStruct();
		this->cbox_sel_id_porEmpleado->SelectedIndex = -1;
	}
	
	//SELECCIONADOR DE ID - REPORTE POR EMPLEADO
	private: System::Void cbox_sel_id_porEmpleado_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		dataGridView_reporte_porEmpleado->Rows->Clear();
		dataGridView_reporte_porEmpleado_ventas->Rows->Clear();

		//LLENAMOS TABLA DE DATOS DEL EMPLEADO CON CANTIDAD DE VENTAS Y DINERO
		DateTime local = DateTime::Now; //Fecha actual
		int ID_usuario_reporte;
		if ((fd = fopen("./registros/Empleados.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&var, lr, 1, fd)) { //leemos y agregamos id
			if (var.id == atoi(this->toStandardString(this->cbox_sel_id_porEmpleado->Text).c_str())) {
				//Creamos nueva fila
				int n_fila = dataGridView_reporte_porEmpleado->Rows->Add();
				//Agregamos la información
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[0]->Value = var.id;
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[1]->Value = System::Convert::ToString(local.ToString("d"));
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[2]->Value = toSystemString(var.nombres);
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[3]->Value = toSystemString(var.apellidoPaterno);
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[4]->Value = toSystemString(var.apellidoMaterno);
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[5]->Value = toSystemString(var.dni);
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[6]->Value = var.numVentas;
				dataGridView_reporte_porEmpleado->Rows[n_fila]->Cells[7]->Value = var.dinero;
				ID_usuario_reporte = var.id;
				break;
			}
		}
		fclose(fd); //Cerrar archivo
		limpiarStruct();
		
		
		float VENTATOTAL=0;
		//LLENAMOS TABLA CON TODAS LAS VENTAS QUE REALIZÓ EL EMPLEADO
		if ((fv = fopen("./registros/Ventas.txt", "rt")) == NULL) {
			exit(1);
		}
		while (fread(&vent, lv, 1, fv)) { //leemos y agregamos id
			VENTATOTAL = VENTATOTAL + vent.dinero;
			if (vent.idEmpleado == ID_usuario_reporte) {
				//Creamos nueva fila
				int nn_fila = dataGridView_reporte_porEmpleado_ventas->Rows->Add();
				//Agregamos la información
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[0]->Value = toSystemString(vent.fecha);
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[1]->Value = vent.idProducto;
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[2]->Value = toSystemString(vent.tipoPago);
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[3]->Value = toSystemString(vent.unidadVenta);
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[4]->Value = vent.cantidad;
				dataGridView_reporte_porEmpleado_ventas->Rows[nn_fila]->Cells[5]->Value = vent.dinero;
			}
		}
		fclose(fv); //Cerrar archivo
		limpiarStruct3();

		//MOSTRAMOS VENTAS TOTALES
		this->lbl_ventas_respectoMesAnterior_porEmpleado->Text = L""+VENTATOTAL;
	
	}


	

	



};	
}
