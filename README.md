# La Bodega de Don Wlan

<p align="center">
  <img src="img/logo.png" alt="Logo La Bodega de Don Wlan" width="280">
</p>

**Sistema de gestión de bodega y punto de venta (POS)** desarrollado en **C++/CLI con Windows Forms** para Windows.

Proyecto académico del curso *Organización de Archivos* — Universidad Nacional de Trujillo (UNT), Ciclo IV, 2022.

---

## Descripción

Aplicación de escritorio para administrar una bodega (abarrotes): control de empleados, inventario de productos, registro de ventas y reportes, todo almacenado en **archivos binarios de registros de longitud fija** (lectura/escritura directa con `fread` / `fwrite`), que es justamente el tema central del curso.

## Módulos

| Módulo | Descripción |
|--------|-------------|
| **Inicio de sesión** | Valida usuario y contraseña contra el archivo de empleados; oculta opciones según el rol. |
| **Roles de usuario** | `Administrador` (acceso total), `Vendedor` (registrar ventas y ver su reporte), `Encargado de Inventario` (solo inventario). También se pueden registrar empleados de Limpieza y Seguridad. |
| **Registro de empleados** | Alta de empleados: nombres, apellidos, DNI, fecha de nacimiento, domicilio, teléfono, usuario, contraseña y tipo de usuario. |
| **Ver empleados** | Listado de todos los empleados registrados. |
| **Inventario** | Agregar o modificar productos por categoría (Abarrotes, Lácteos, Bebidas, Limpieza, etc.) con precio, cantidad y unidad base. |
| **Registro de ventas** | Carrito de compra con selección de categoría → producto → marca/modelo, cálculo de precio total, tipo de pago, control de stock y actualización de ventas del empleado. |
| **Reportes** | Reporte por empleado: datos del empleado, productos vendidos y ventas totales de la empresa (en S/.). |

## Tecnologías

- **C++/CLI** (`/clr`) con **Windows Forms**
- **.NET Framework 4.7.2**
- **Visual Studio 2022** (Platform Toolset `v143`, x64)
- Archivos binarios como base de datos (`fread`/`fwrite`)

## Estructura del proyecto

```
trabajo/
├── trabajo.sln              # Solución de Visual Studio
├── Form1.h                  # Toda la interfaz y la lógica de la aplicación (~3.800 líneas)
├── Form1.cpp                # Punto de entrada del formulario
├── CppCLR_WinFormsProject.cpp
├── AssemblyInfo.cpp         # Información del ensamblado
├── pch.h / pch.cpp          # Precompiled headers
├── app.rc / app.ico         # Recurso e ícono de la aplicación
├── img/                     # Imágenes de la interfaz (logo, fondo, íconos)
├── notas/                   # Notas y snippets de referencia
└── registros/               # Archivos binarios de datos + utilidades
    ├── Empleados.txt        # Registros binarios de empleados
    ├── Inventario.txt       # Registros binarios de productos
    ├── Ventas.txt           # Registros binarios de ventas
    ├── crearArchivos.cpp    # Genera datos de ejemplo de empleados
    ├── crearInventario.cpp  # Genera datos de ejemplo de inventario
    └── crearVentas.cpp      # Genera datos de ejemplo de ventas
```

## Requisitos

- Windows 10/11
- Visual Studio 2022 con el workload **"Desarrollo de escritorio en C++"** y **.NET Framework 4.7.2**

## Cómo compilar y ejecutar

1. Clonar el repositorio:
   ```bash
   git clone https://github.com/<tu-usuario>/<nombre-del-repo>.git
   ```
2. Abrir `trabajo.sln` con Visual Studio 2022.
3. Seleccionar configuración **Debug | x64**.
4. Presionar **F5** (o *Compilar → Compilar solución*).

> **Nota:** La app carga los archivos desde `./registros/` y las imágenes desde `./img/` con rutas relativas, así que se debe ejecutar desde la carpeta de salida del proyecto (comportamiento por defecto al pulsar F5 en Visual Studio).

## Usuario de prueba

La base de datos de ejemplo incluye un administrador:

| Campo | Valor |
|-------|-------|
| Usuario | `FrancoJord` |
| Contraseña | `1234567890` |

Si necesitas regenerar los archivos de datos de ejemplo, compila y ejecuta los programas en `registros/` (`crearArchivos.cpp`, `crearInventario.cpp`, `crearVentas.cpp`) desde la misma carpeta `registros/`.

## Estructura de los registros

Los tres archivos binarios almacenan structs de longitud fija, por ejemplo:

```cpp
struct Empleado {
    int  id;
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
    int  numVentas;
    float dinero;
    char estado[2];
};
```

Esto permite acceso directo a los registros por tamaño de struct (`fread(&var, sizeof(var), 1, fd)`), técnica central de la organización de archivos secuencial e indexado.

---

*Proyecto con fines académicos.*
