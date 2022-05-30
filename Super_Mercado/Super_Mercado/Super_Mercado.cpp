// Super_Mercado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Producto.h"
#include "Marca.h"
#include "Compra.h"
#include "Proveedor.h"
#include "Puesto.h"
#include "Empleado.h"
#include "Cliente.h"
#include "Venta.h"
#include <iostream>
using namespace  std;

int main()
{

	string producto, descripcion, imagen, fecha_ingreso, marca, orden_compra, id_proveedor, fecha_orden, id_compra, idmarca;
	string proveedor, nit, direccion, telefono;
	string puesto, idpuesto;
	string idempleado, nombres, apellidos, DPI, genero, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
	string idcliente, correo_electronico;
	string idventa, no_factura, serie, fecha_factura, idventa_detalle, idproducto, cantidad, precio_unitario;
	string idcompradetalle, costounitario;
	int idProducto = 0, idMarca = 0, precio_costo = 0, precio_venta = 0, existencia = 0, menu = 0, smenu = 0, fprincipal =0;
	Producto p = Producto();
	Marcas m = Marcas();
	compra c = compra();
	Proveedor pr = Proveedor();
	Puestos ps = Puestos();
	Empleado e = Empleado();
	Cliente cl = Cliente();
	Venta v = Venta();
	 
	do {
		cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
		cout << "\n1 - Ingresar a la Seccion de Producto" << endl;
		cout << "2 - Ingresar a la Seccion de Marcas" << endl;
		cout << "3 - Ingresar a la Seccion de Compras" << endl;
		cout << "4 - Ingresar a la Seccion de Proveedores" << endl;
		cout << "5 - Ingresar a la Seccion de Puestos" << endl;
		cout << "6 - Ingresar a la Seccion de Empleados" << endl;
		cout << "7 - Ingresar a la Seccion de Clientes" << endl;
		cout << "8 - Ingresar a la Seccion de Ventas" << endl;
		cout << "\nIngrese opcion: ";
		cin >> fprincipal;
		system("cls");
		switch (fprincipal) {
		case 1:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Producto \n2 - Lista de los Productos \n3 - Actualizar Datos \n4 - Eliminar Producto " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR PRODUCTO -----------" << endl;
				cout << "Ingrese ID de la Marca: ";
				cin >> idMarca;
				cin.ignore();
				cout << "Ingrese nombre del Producto:";
				getline(cin, producto);
				cout << "Ingrese Descripcion:";
				getline(cin, descripcion);
				cout << "Ingrese Imagen:";
				getline(cin, imagen);
				cout << "Ingrese Precio Costo:";
				cin >> precio_costo;
				cin.ignore();
				cout << "Ingrese Precio Venta:";
				cin >> precio_venta;
				cin.ignore();
				cout << "Ingrese Numero de Existencia:";
				cin >> existencia;
				cin.ignore();
				cout << "Ingrese Fecha de Ingreso:";
				getline(cin, fecha_ingreso);
	
				p.setproducto(producto);
				p.setIdMarca(idMarca);
				p.setDescripcion(descripcion);
				p.setImagen(imagen);
				p.setPrecio_costo(precio_costo);
				p.setPrecio_venta(precio_venta);
				p.setExistencia(existencia);
				p.setFecha_ingreso(fecha_ingreso);
				p.crear();
				break;
			case 2:
				cout << "-------- LISTA DE LOS PRODUCTOS --------" << endl;
				p.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR PRODUCTOS --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID del Producto:";
				cin >> idProducto;
				cin.ignore();
				cout << "Ingrese nombre del Producto:";
				getline(cin, producto);
				cout << "Ingrese ID de la Marca:";
				cin >> idMarca;
				cin.ignore();
				cout << "Ingrese Descripcion:";
				getline(cin, descripcion);
				cout << "Ingrese Imagen:";
				getline(cin, imagen);
				cout << "Ingrese Precio Costo:";
				cin >> precio_costo;
				cin.ignore();
				cout << "Ingrese Precio Venta:";
				cin >> precio_venta;
				cin.ignore();
				cout << "Ingrese Numero de Existencia:";
				cin >> existencia;
				cin.ignore();
				cout << "Ingrese Fecha de Ingreso:";
				getline(cin, fecha_ingreso);
				p.setIdProducto(idProducto);
				p.setproducto(producto);
				p.setIdMarca(idMarca);
				p.setDescripcion(descripcion);
				p.setImagen(imagen);
				p.setPrecio_costo(precio_costo);
				p.setPrecio_venta(precio_venta);
				p.setExistencia(existencia);
				p.setFecha_ingreso(fecha_ingreso);
				p.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR PRODUCTO --------" << endl;
				cout << "Ingrese ID del Producto:";
				cin >> idProducto;
				cin.ignore();
				p.setIdProducto(idProducto);
				p.eliminar();
				default:
				cout << "Opcion no encontrada" << endl;
				break;
			}
			break;
		case 2:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Marca \n2 - Lista de las Marcas \n3 - Actualizar Datos \n4 - Eliminar Marca " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
			cout << "-------- CREAR MARCA -----------" << endl;	
			cin.ignore();
			cout << "Ingrese Marca: ";
			getline(cin, marca);
			m.setMarca(marca);
			m.crear();
			break;
			case 2:
			cout << "-------- LISTA DE LAS MARCAS --------" << endl;
			m.leer();
			break;
			case 3:
			cout << "------- ACTUALIZAR MARCAS --------" << endl;
			cout << "-----------------------------------------------------" << endl;

			cout << "Ingrese ID de la Marca:";
			cin >> idmarca;
			cin.ignore();
			cout << "Ingrese Marca:";
			getline(cin, marca);
			m.setidMarca(idmarca);
			m.setMarca(marca);
			m.Actualizar();
			break;
			case 4:
			cout << "-------ELIMINAR MARCA --------" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "Ingrese ID de la Marca:";
			cin >> idmarca;
			cin.ignore();
			m.setidMarca(idmarca);
			m.eliminar();
			break;
			default:
			cout << "Opcion no encontrada" << endl;
			}
			break;
		case 3:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Compra \n2 - Lista de Compras \n3 - Actualizar Datos \n4 - Eliminar Compra " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR COMPRA -----------" << endl;
				cin.ignore();
				cout << "ingrese No. Orden de Compra: ";
				getline(cin, orden_compra);
				cout << "ingrese Id Proveedor: ";
				getline(cin, id_proveedor);
				cout << "ingrese Fecha de Orden: ";
				getline(cin, fecha_orden);
				cout << "ingrese Fecha de Ingreso: ";
				getline(cin, fecha_ingreso);
				cout << "ingrese ID Compra: ";
				getline(cin, idcompradetalle);
				cout << "ingrese ID Producto: ";
				getline(cin, idproducto);
				cout << "ingrese cantidad: ";
				getline(cin, cantidad);
				cout << "ingrese costo unitario: ";
				getline(cin, costounitario);

				c.setorden_compra(orden_compra);
				c.setid_proveedor(id_proveedor);
				c.setfecha_orden(fecha_orden);
				c.setfecha_ingreso(fecha_ingreso);
				c.setidcompradetalle(idcompradetalle);
				c.setidproducto(idproducto);
				c.setcantidad(cantidad);
				c.setcostounitario(costounitario);
				c.crear();
				break;
			case 2:
				cout << "-------- LISTA DE COMPRAS --------" << endl;
				c.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR COMPRAS --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID de Compra:";
				cin >> id_compra;
				cin.ignore();
				cout << "ingrese No. Orden de Compra: ";
				getline(cin, orden_compra);
				cout << "ingrese Id Proveedor: ";
				getline(cin, id_proveedor);
				cout << "ingrese Fecha de Orden: ";
				getline(cin, fecha_orden);
				cout << "ingrese Fecha de Ingreso: ";
				getline(cin, fecha_ingreso);
				cout << "ingrese ID Producto: ";
				getline(cin, idproducto);
				cout << "ingrese cantidad: ";
				getline(cin, cantidad);
				cout << "ingrese costo unitario: ";
				getline(cin, costounitario);
				c.setid_compra(id_compra);
				c.setorden_compra(orden_compra);
				c.setid_proveedor(id_proveedor);
				c.setfecha_orden(fecha_orden);
				c.setfecha_ingreso(fecha_ingreso);
				c.setidproducto(idproducto);
				c.setcantidad(cantidad);
				c.setcostounitario(costounitario);
				c.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR COMPRA --------" << endl;
				cout << "Ingrese ID de Compra:";
				cin >> id_compra;
				cin.ignore();				
				c.setid_compra(id_compra);
				c.eliminar();

				c.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
			break;
		case 4:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Proveedor \n2 - Lista de Proveedores \n3 - Actualizar Datos \n4 - Eliminar Proveedor " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR PROVEEDOR -----------" << endl;
				cin.ignore();
				cout << "ingrese Nombre Proveedor: ";
				getline(cin, proveedor);
				cout << "ingrese Nit: ";
				getline(cin, nit);
				cout << "ingrese Direccion: ";
				getline(cin, direccion);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);
				pr.setproveedor(proveedor);
				pr.setnit(nit);
				pr.setdireccion(direccion);
				pr.settelefono(telefono);

				pr.crear();
				break;
			case 2:
				cout << "-------- LISTA DE PROVEEDORES --------" << endl;
				pr.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR PROVEEDORES --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID de Proveedor:";
				cin >> id_proveedor;
				cin.ignore();
				cout << "ingrese Nombre Proveedor: ";
				getline(cin, proveedor);
				cout << "ingrese Nit: ";
				getline(cin, nit);
				cout << "ingrese Direccion: ";
				getline(cin, direccion);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);

				pr.setid_proveedores(id_proveedor);
				pr.setproveedor(proveedor);
				pr.setnit(nit);
				pr.setdireccion(direccion);
				pr.settelefono(telefono);
				pr.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR PROVEEDOR --------" << endl;
				cout << "Ingrese ID de Proveedor:";
				cin >> id_proveedor;
				cin.ignore();
				pr.setid_proveedores(id_proveedor);
				pr.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
			break;
		case 5:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Puesto \n2 - Lista de puestos \n3 - Actualizar Datos \n4 - Eliminar Puesto " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR PUESTO -----------" << endl;
				cin.ignore();
				cout << "Ingrese Puesto: ";
				getline(cin, puesto);
				ps.setidpuesto(idpuesto);
				ps.setpuesto(puesto);
				ps.crear();
				break;
			case 2:
				cout << "-------- LISTA DE PUESTOS --------" << endl;
				ps.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR PUESTOS --------" << endl;
				cout << "-----------------------------------------------------" << endl;

				cout << "Ingrese ID del puesto:";
				cin >> idpuesto;
				cin.ignore();
				cout << "Ingrese Puesto:";
				getline(cin, puesto);
				ps.setidpuesto(idpuesto);
				ps.setpuesto(puesto);
				ps.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR PUESTO --------" << endl;
				cout << "--------------------------------------------------" << endl;
				cout << "Ingrese ID del Puesto:";
				cin >> idpuesto;
				cin.ignore();
				ps.setidpuesto(idpuesto);
				ps.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
			break;
		case 6:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Empleado \n2 - Lista de Empleados \n3 - Actualizar Datos \n4 - Eliminar Empleado " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR EMPLEADO -----------" << endl;
				cin.ignore();
				cout << "ingrese Nombres de Empleado: ";
				getline(cin, nombres);
				cout << "ingrese Apellidos de Empleado: ";
				getline(cin, apellidos);
				cout << "ingrese Direccion: ";
				getline(cin, direccion);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);
				cout << "ingrese DPI de Empleado: ";
				getline(cin, DPI);
				cout << "ingrese genero de Empleado: ";
				getline(cin, genero);
				cout << "ingrese fecha de nacimiento de Empleado: ";
				getline(cin, fecha_nacimiento);
				cout << "ingrese id puesto de Empleado: ";
				getline(cin, idpuesto);
				cout << "ingrese fecha de inicio de labores de Empleado: ";
				getline(cin, fecha_inicio_labores);
				cout << "ingrese fecha de ingreso de Empleado: ";
				getline(cin, fechaingreso);
				e.setnombres(nombres);
				e.setapellidos(apellidos);
				e.setDPI(DPI);
				e.setgenero(genero);
				e.setfecha_nacimiento(fecha_nacimiento);
				e.setidpuesto(idpuesto);
				e.setfecha_inicio_labores(fecha_inicio_labores);
				e.setfechaingreso(fechaingreso);
				e.crear();
				break;
			case 2:
				cout << "-------- LISTA DE EMPLEADOS --------" << endl;
				e.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR EMPLEADOS --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID de Empleado:";
				cin >> idempleado;
				cin.ignore();
				cout << "ingrese Nombres de Empleado: ";
				getline(cin, nombres);
				cout << "ingrese Apellidos de Empleado: ";
				getline(cin, apellidos);
				cout << "ingrese Direccion: ";
				getline(cin, direccion);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);
				cout << "ingrese DPI de Empleado: ";
				getline(cin, DPI);
				cout << "ingrese genero de Empleado: ";
				getline(cin, genero);
				cout << "ingrese fecha de nacimiento de Empleado: ";
				getline(cin, fecha_nacimiento);
				cout << "ingrese id puesto de Empleado: ";
				getline(cin, idpuesto);
				cout << "ingrese fecha de inicio de labores de Empleado: ";
				getline(cin, fecha_inicio_labores);
				cout << "ingrese fecha de ingreso de Empleado: ";
				getline(cin, fechaingreso);

				e.setidempleado(idempleado);
				e.setnombres(nombres);
				e.setapellidos(apellidos);
				e.setDPI(DPI);
				e.setgenero(genero);
				e.setfecha_nacimiento(fecha_nacimiento);
				e.setidpuesto(idpuesto);
				e.setfecha_inicio_labores(fecha_inicio_labores);
				e.setfechaingreso(fechaingreso);
				e.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR EMPLEADO --------" << endl;
				cout << "Ingrese ID de Empleado:";
				cin >> idempleado;
				cin.ignore();
				e.setidempleado(idempleado);
				e.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
			break;
		case 7:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Cliente\n2 - Lista de Clientes \n3 - Actualizar Datos \n4 - Eliminar Cliente " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR CLIENTE -----------" << endl;
				cin.ignore();
				cout << "ingrese Nombres de Cliente: ";
				getline(cin, nombres);
				cout << "ingrese Apellidos de Cliente: ";
				getline(cin, apellidos);
				cout << "ingrese NIT: ";
				getline(cin, nit);
				cout << "ingrese genero de Cliente: ";
				getline(cin, genero);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);
				cout << "ingrese Correo Electronico de Cliente: ";
				getline(cin, correo_electronico);
				cout << "ingrese fecha de ingreso de Cliente: ";
				getline(cin, fechaingreso);
				cl.setnombres(nombres);
				cl.setapellidos(apellidos);
				cl.setnit(nit);
				cl.setgenero(genero);
				cl.settelefono(telefono);
				cl.setcorreo_electronico(correo_electronico);
				cl.setfechaingreso(fechaingreso);

				cl.crear();
				break;
			case 2:
				cout << "-------- LISTA DE CLIENTES --------" << endl;
				cl.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR CLIENTES --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID de Cliente:";
				cin >> idcliente;
				cin.ignore();
				cout << "ingrese Nombres de Cliente: ";
				getline(cin, nombres);
				cout << "ingrese Apellidos de Cliente: ";
				getline(cin, apellidos);
				cout << "ingrese NIT: ";
				getline(cin, nit);
				cout << "ingrese genero de Cliente: ";
				getline(cin, genero);
				cout << "ingrese Telefono: ";
				getline(cin, telefono);
				cout << "ingrese Correo Electronico de Cliente: ";
				getline(cin, correo_electronico);
				cout << "ingrese fecha de ingreso de Cliente: ";
				getline(cin, fechaingreso);

				cl.setnombres(nombres);
				cl.setapellidos(apellidos);
				cl.setnit(nit);
				cl.setgenero(genero);
				cl.settelefono(telefono);
				cl.setcorreo_electronico(correo_electronico);
				cl.setfechaingreso(fechaingreso);
				cl.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR CLIENTE --------" << endl;
				cout << "Ingrese ID de Cliente:";
				cin >> idcliente;
				cin.ignore();
				cl.setidcliente(idcliente);
				cl.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
			break;
		case 8:
			cout << "Ingrese la opcion que desea realizar presionando el numero" << endl;
			cout << "1 - Crear Venta \n2 - Lista de Ventas \n3 - Actualizar Datos \n4 - Eliminar Venta " << endl;
			cin >> smenu;
			switch (smenu) {
			case 1:
				cout << "-------- CREAR VENTA -----------" << endl;
				cin.ignore();
				cout << "ingrese No. de factura: ";
				getline(cin, no_factura);
				cout << "ingrese Serie: ";
				getline(cin, serie);
				cout << "ingrese Fecha de Factura: ";
				getline(cin, fecha_factura);
				cout << "ingrese NIT de Cliente: ";
				getline(cin, nit);
				system("cls");
				cl.setnit(nit);
				cl.buscar();

				/*cout << "ingrese id de Empleado: ";
				getline(cin, idempleado);
				cout << "ingrese fecha de ingreso de Venta: ";
				getline(cin, fechaingreso);
				cout << "ingrese ID Venta: ";
				getline(cin, idventa_detalle);*/
				cout << "ID Producto: ";
				getline(cin, producto);
				
				p.setproducto(producto);
				p.buscar();
				cout << "   Cantidad: ";
				getline(cin, imagen);
				
				/*cout << "ingrese precio unitario: ";
				getline(cin, precio_unitario);*/

				p.setImagen(imagen);
				v.setno_factura(no_factura);
				v.setserie(serie);
				v.setfecha_factura(fecha_factura);
				v.setidcliente(idcliente);
				v.setidempleado(idempleado);
				v.setfechaingreso(fechaingreso);
				v.setidventa_detalle(idventa_detalle);
				v.setidproducto(idproducto);
				v.setcantidad(cantidad);
				v.setprecio_unitario(precio_unitario);
				v.crear();
				break;
			case 2:
				cout << "-------- LISTA DE VENTAS --------" << endl;
				v.leer();
				break;
			case 3:
				cout << "------- ACTUALIZAR VENTAS --------" << endl;
				cout << "-----------------------------------------------------" << endl;
				cout << "Ingrese ID de Venta:";
				cin >> idventa;
				cin.ignore();
				cout << "ingrese No. de factura: ";
				getline(cin, no_factura);
				cout << "ingrese Serie: ";
				getline(cin, serie);
				cout << "ingrese Fecha de Factura: ";
				getline(cin, fecha_factura);
				cout << "ingrese Id de Cliente: ";
				getline(cin, idcliente);
				cout << "ingrese id de Empleado: ";
				getline(cin, idempleado);
				cout << "ingrese fecha de ingreso de Venta: ";
				getline(cin, fechaingreso);
				cout << "ingrese ID Venta: ";
				getline(cin, idventa_detalle);
				cout << "ingrese ID Producto: ";
				getline(cin, idproducto);
				cout << "ingrese Cantidad de producto: ";
				getline(cin, cantidad);
				cout << "ingrese precio unitario: ";
				getline(cin, precio_unitario);
				v.setidventa(idventa);
				v.setno_factura(no_factura);
				v.setserie(serie);
				v.setfecha_factura(fecha_factura);
				v.setidcliente(idcliente);
				v.setidempleado(idempleado);
				v.setfechaingreso(fechaingreso);
				v.setidventa_detalle(idventa_detalle);
				v.setidproducto(idproducto);
				v.setcantidad(cantidad);
				v.setprecio_unitario(precio_unitario);
				v.Actualizar();
				break;
			case 4:
				cout << "-------ELIMINAR VENTA --------" << endl;
				cout << "Ingrese ID de Venta:";
				cin >> idventa;
				cin.ignore();
				v.setidventa(idventa);
				v.eliminar();

				v.eliminar();
				break;
			default:
				cout << "Opcion no encontrada" << endl;
			}
		}
		cout << "\nDesea regresar al menu principal: 1 - SI | 2- NO" << endl;
		cin >> menu;
		system("cls");
	} while (menu == 1);
	system("pause");
	return 0;
}