#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Venta {
protected: string idventa;
		 string no_factura;
		 string serie;
		 string fecha_factura;
		 string idcliente;
		 string idempleado;
		 string fechaingreso;
		 string idventa_detalle;
		 string idproducto;
		 string cantidad;
		 string precio_unitario;

public:
	Venta() {
	}

	Venta(string id_ven, string no_fac, string ser, string fech_fac, string id_cli, string id_emp, string fech_ing, string idv_d, string idprod, string cant, string pre_unit) {
		idventa = id_ven;
		no_factura = no_fac;
		serie = ser;
		fecha_factura = fech_fac;
		idcliente = id_cli;
		idempleado = id_emp;
		fechaingreso = fech_ing;
		idventa_detalle = idv_d;
		idproducto = idprod;
		cantidad = cant;
		precio_unitario = pre_unit;

	}
	// METODOS
	void setidventa(string id_ven) { idventa = id_ven; }
	void setno_factura(string no_fac) { no_factura = no_fac; }
	void setserie(string ser) { serie = ser; }
	void setfecha_factura(string fech_fac) { fecha_factura = fech_fac; }
	void setidcliente(string id_cli) { idcliente = id_cli; }
	void setidempleado(string id_emp) { idempleado = id_emp; }
	void setfechaingreso(string fech_ing) { fechaingreso = fech_ing; }

	void setidventa_detalle(string idv_d) { idventa_detalle = idv_d; }
	void setidproducto(string idprod) { idproducto = idprod; }
	void setcantidad(string cant) { cantidad = cant; }
	void setprecio_unitario(string pre_unit) { precio_unitario = pre_unit; }

	string getidventa() { return idventa; }
	string getno_factura() { return no_factura; }
	string getserie() { return serie; }
	string getfecha_factura() { return fecha_factura; }
	string getidcliente() { return idcliente; }
	string getidempleado() { return idempleado; }
	string getfechaingreso() { return fechaingreso; }

	string getidventa_detalle() { return idventa_detalle; }
	string getidproducto() { return idproducto; }
	string setcantidad() { return cantidad; }
	string getprecio_unitario() { return precio_unitario; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()){
		string insert = "INSERT INTO `db_supermercado`.`ventas`(no_factura, serie, fecha_factura, idClientes, idEmpleado, fecha_ingreso)VALUES('" + no_factura + "','" + serie + "','" + fecha_factura + "','" + idcliente + "','" + idempleado + "','" + fechaingreso + "'); ";
		const char* i = insert.c_str();
		q_estado = mysql_query(cn.getConectar(), i);
		if (!q_estado) {
			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar  xxx" << endl;
		}

		string insert2 = "INSERT INTO `db_supermercado`.`ventas_detalle`(idVenta, idProducto, cantidad, precio_unitario)VALUES('" + idventa_detalle + "','" + idproducto + "','" + cantidad + "','" + precio_unitario + "'); ";
		const char* j = insert2.c_str();
		q_estado = mysql_query(cn.getConectar(), j);
		if (!q_estado) {
			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar  xxx" << endl;
		}
		}
		else {
		cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from ventas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

			string consulta2 = "select * from ventas_detalle;";
			const char* c2 = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c2);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << "------ Detalle de venta ------" << endl;
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string update = "UPDATE `ventas` SET `no_factura` = '" + no_factura + "', `serie` = '" + serie + "', `fecha_factura` = '" + fecha_factura + "', `idClientes` = '" + idcliente + "',  `idEmpleado` = '" + idempleado + "', `fecha_ingreso` = '" + fechaingreso + "' WHERE(`idVenta` = '" + idventa + "');";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;

			}
			else {
				cout << "xxxxError en la Actualización xxxx" << endl;
			}
			string update2 = "UPDATE `ventas_detalle` SET`idVenta` = '" + idventa + "' ,`idProducto` = '" + idproducto + "',`cantidad` ='" + cantidad + "',`precio_unitario` = '" + precio_unitario + "' WHERE (`idventa_detalle` = '" + idventa_detalle + "');";
			const char* j = update2.c_str();
			q_estado = mysql_query(cn.getConectar(), j);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;

			}
			else {
				cout << "xxxxError en la Actualización xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string eliminar = "DELETE FROM ventas WHERE (idVenta = '" + idventa + "')";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminado Correctamente..." << endl;

			}
			else {
				cout << "" << endl;
			}
			string eliminar2 = "DELETE FROM ventas_detalle WHERE (idventa_detalle = '" + idventa + "')";
			const char* j = eliminar2.c_str();
			q_estado = mysql_query(cn.getConectar(), j);
			if (!q_estado) {
				cout << "" << endl;
			}
			else {
				cout << "xxxxError al Eliminar xxxx" << endl;
			}
		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};