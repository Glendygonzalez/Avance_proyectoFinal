#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Marcas {
protected: string marca;
		 string  idMarca;

public:
	Marcas() {
	}
	Marcas(string Im, string mar) {
		idMarca = Im;
		marca = mar;
	}
	// METODOS
	//set (modificar)
	void setidMarca(string Im) { idMarca = Im; }
	void setMarca(string mar) { marca = mar; }
	
	//get (mostrar)
	string getIdMarca() { return idMarca; }
	string getMarca() { return marca; }
	

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO marcas(marca)VALUES('"+marca+"'); ";
			const char* i = insertar.c_str();
			// executar el query
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

			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << " IDmarca: " << fila[0] << " Marca: " << fila[1] <<  endl;
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
			string update = "UPDATE marcas SET marca = '" + marca + "' where  (idMarca = '" + idMarca + "')";
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
			string borrar = "DELETE FROM marcas WHERE  (idMarca = '" + idMarca + "')";
			const char* i = borrar.c_str();
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

