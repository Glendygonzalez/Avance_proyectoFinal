#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class compra {
protected: string orden_compra;
		 string id_proveedor;
		 string fecha_orden;
		 string fecha_ingreso;
		 string id_compra;
		 string idcompradetalle;
		 string idproducto;
		 string cantidad;
		 string costounitario;


public:
	compra() {
	}
	
	compra(string ic, string ord, string prov, string fo, string fi, string icd, string ip, string cant, string cu){
		id_compra = ic;
		orden_compra = ord;
		id_proveedor = prov;
		fecha_orden = fo;
		fecha_ingreso = fi;
		idcompradetalle = icd;
		idproducto = ip;
		cantidad = cant;
		costounitario = cu;
	}
	// METODOS
	void setid_compra(string com) { id_compra = com; }
	void setorden_compra(string ord) { orden_compra = ord; }
	void setid_proveedor(string prov) { id_proveedor = prov; }
	void setfecha_orden(string fo) { fecha_orden = fo; }
	void setfecha_ingreso(string fi) { fecha_ingreso = fi; }

	void setidcompradetalle(string icd) { idcompradetalle = icd; }
	void setidproducto(string ip) { idproducto = ip; }
	void setcantidad(string cant) { cantidad = cant; }
	void setcostounitario(string cu) { costounitario = cu; }

	string getid_compra() { return id_compra; }
	string getorden_compra() { return orden_compra; }
	string getid_proveedor() { return id_proveedor; }
	string getfecha_orden() { return fecha_orden; }
	string getfecha_ingreso() { return fecha_ingreso; }

	string getidcompradetalle() { return idcompradetalle; }
	string getidproducto() { return idproducto; }
	string getcantidad() { return cantidad; }
	string getcostounitario() { return costounitario; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insert = "INSERT INTO `db_supermercado`.`compras`(no_orden_compra, id_proveedor, fecha_orden, fechaingreso)VALUES('" + orden_compra + "','" + id_proveedor + "','" + fecha_orden + "','" + fecha_ingreso + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;			
		}
			string insert2 = "INSERT INTO `db_supermercado`.`compras_detalle`(idcompra, idproducto, cantidad, precio_costo_unitario)VALUES('" + idcompradetalle + "','" + idproducto + "','" + cantidad + "','" + costounitario + "'); ";
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
			string consulta = "select * from compras;";
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

			string consulta2 = "select * from compras_detalle;";
			const char* c2 = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), c2);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					cout << "------ Detalle de Compra ------" << endl;
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
			string update = "UPDATE `compras` SET `no_orden_compra` = '" + orden_compra + "', `id_proveedor` = '" + id_proveedor + "', `fecha_orden` = '" + fecha_orden + "', `fechaingreso` = '" + fecha_ingreso + "' WHERE(`idcompra` = '" + id_compra + "');";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;

			}
			else {
				cout << "xxxxError en la Actualizacion xxxx" << endl;
			}


			string update2 = "UPDATE `compras_detalle` SET `idcompra` = '" + id_compra + "' , `idproducto`= '" + idproducto + "', `cantidad` ='" + cantidad + "', `precio_costo_unitario` = '" + costounitario + "'WHERE (`idcompra` = '" + id_compra + "');";
			const char* j = update2.c_str();
			q_estado = mysql_query(cn.getConectar(), j);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;

			}
			else {
				cout << "xxxxError en la Actualizacion xxxx" << endl;
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
			string eliminar = "DELETE FROM compras WHERE (idcompra = '" + id_compra + "')";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminado Correctamente..." << endl;
			}
			else {
				cout << "" << endl;
			}

			string eliminar2 = "DELETE FROM compras_detalle WHERE (idCompra_detalle = '" + id_compra + "')";
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
