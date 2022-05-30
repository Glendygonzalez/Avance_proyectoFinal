#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Proveedor {
protected: string proveedor;
		 string id_proveedores;
		 string nit;
		 string direccion;
		 string telefono;	

public:
	Proveedor() {
	}

	Proveedor(string ipro, string pro, string n, string dir, string tel) {
		id_proveedores = ipro;
		proveedor = pro;
		nit = n;
		direccion = dir;
		telefono = tel;
	}
	// METODOS
	void setid_proveedores(string ipro) { id_proveedores = ipro; }
	void setproveedor(string pro) { proveedor = pro; }
	void setnit(string n) { nit = n; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(string tel) { telefono = tel; }

	string getid_proveedores() { return id_proveedores; }
	string getproveedor() { return proveedor; }
	string getnit() { return nit; }
	string getdireccion() { return direccion; }
	string gettelefono() { return telefono; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "INSERT INTO `db_supermercado`.`proveedores`(proveedor, nit, direccion, telefono)VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
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
			string consulta = "select * from proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
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
			string update = "UPDATE `proveedores` SET `proveedor` = '" + proveedor + "', `nit` = '" + nit + "', `direccion` = '" + direccion + "', `telefono` = '" + telefono + "' WHERE(`id_proveedores` = '" + id_proveedores + "');";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
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
			string eliminar = "DELETE FROM proveedores WHERE (id_proveedores = '" + id_proveedores + "')";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminado Correctamente..." << endl;

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
