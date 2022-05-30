#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Empleado {
protected: string idempleado;
		 string nombres;
		 string apellidos;
		 string direccion;
		 string telefono;
		 string DPI;
		 string genero;
		 string fecha_nacimiento;
		 string idpuesto;
		 string fecha_inicio_labores;
		 string fechaingreso;

public:
	Empleado() {
	}

	Empleado(string emp, string nom, string ape, string dir, string tel, string d, string gen, string fn, string ip, string fil, string fi) {
		idempleado = emp;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		DPI = d;
		genero = gen;
		fecha_nacimiento = fn;
		idpuesto = ip;
		fecha_inicio_labores = fil;
		fechaingreso = fi;

	}
	// METODOS
	void setidempleado(string emp) { idempleado = emp; }
	void setnombres(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(string tel) { telefono = tel; }
	void setDPI(string d) { DPI = d; }
	void setgenero(string gen) { genero = gen; }
	void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	void setidpuesto(string ip) { idpuesto = ip; }
	void setfecha_inicio_labores(string fil) { fecha_inicio_labores = fil; }
	void setfechaingreso(string fi) { fechaingreso = fi; }

	string getidempleado() { return idempleado; }
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getdireccion() { return direccion; }
	string gettelefono() { return telefono; }
	string getDPI() { return DPI; }
	string getgenero() { return genero; }
	string getfecha_nacimiento() { return fecha_nacimiento; }
	string getidpuesto() { return idpuesto; }
	string getfecha_inicio_labores() { return fecha_inicio_labores; }
	string getfechaingreso() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "INSERT INTO `db_supermercado`.`empleados`(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso)VALUES('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + DPI + "','" + genero + "','" + DPI + "','" + fecha_nacimiento + "','" + idpuesto + "','" + fecha_inicio_labores + "','" + fechaingreso + "'); ";
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
			string consulta = "select * from empleados;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10]  << endl;
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
			string update = "UPDATE `empleados` SET `nombres` = '" + nombres + "', `apellidos` = '" + apellidos + "', `direccion` = '" + direccion + "', `telefono` = '" + telefono + "', `DPI` = '" + DPI + "', `genero` = '" + genero + "', `fecha_nacimiento` = '" + fecha_nacimiento + "', `idPuesto` = '" + idpuesto + "', `fecha_inicio_labores` = '" + fecha_inicio_labores + "', `fecha_ingreso` = '" + fechaingreso + "' WHERE(`idEmpleado` = '" + idempleado + "');";
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
			string eliminar = "DELETE FROM empleados WHERE (idEmpleado = '" + idempleado + "')";
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

