#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Cliente {
protected: string idcliente;
		 string nombres;
		 string apellidos;
		 string nit;
		 string telefono;
		 string genero;
		 string correo_electronico;
		 string fechaingreso;

public:
	Cliente() {
	}

	Cliente(string ic, string nom, string ape, string n, string tel, string gen, string ce, string fi) {
		idcliente = ic;
		nombres = nom;
		apellidos = ape;
		nit = n;
		genero = gen;
		telefono = tel;
		correo_electronico = ce;
		fechaingreso = fi;

	}
	// METODOS
	void setidcliente(string ic) { idcliente = ic; }
	void setnombres(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setnit(string n) { nit = n; }
	void setgenero(string gen) { genero = gen; }
	void settelefono(string tel) { telefono = tel; }
	void setcorreo_electronico(string ce) { correo_electronico = ce; }
	void setfechaingreso(string fi) { fechaingreso = fi; }

	string getidcliente() { return idcliente; }
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getnit() { return nit; }
	string getgenero() { return genero; }
	string gettelefono() { return telefono; }
	string getcorreo_electronico() { return correo_electronico; }
	string getfechaingreso() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "INSERT INTO `db_supermercado`.`clientes`(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso)VALUES('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + telefono + "','" + correo_electronico + "','" + fechaingreso + "'); ";
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
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
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
			string update = "UPDATE `clientes` SET `nombres` = '" + nombres + "', `apellidos` = '" + apellidos + "', `NIT` = '" + nit + "', `genero` = '" + genero + "',  `telefono` = '" + telefono + "', `correo_electronico` = '" + correo_electronico + "', `fecha_ingreso` = '" + fechaingreso + "' WHERE(`idCliente` = '" + idcliente + "');";
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
			string eliminar = "DELETE FROM clientes WHERE (idCliente = '" + idcliente + "')";
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
	void buscar() {
		int q_estado;
		int serie=1;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select nombres, apellidos, nit from clientes where (NIT = '" + nit + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << "\n___________________________________________________________________" << endl;
					cout << "|NO. FACTURA: ";   cout << "						 " << endl;
					cout << "|Serie:" <<serie++;   cout << "                                             " << endl;
					cout << "|Fecha:"; cout << "                                  " << endl;
					cout << "|Nit:" << fila[2]; cout << "                                               " << endl;
					cout << "|Cliente:" << fila[0] << " " << fila[1];      cout << "                                               " << endl;
					cout << "|Direccion: Ciudad" "                                          " << endl;
					cout << "|                          PRODUCTO                                 " << endl;




					/*cout << fila[0] << "," << fila[1] << "," << fila[2] << endl;*/
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
};