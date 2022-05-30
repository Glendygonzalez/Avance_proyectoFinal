#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h" 
using namespace std;
class Producto {
protected: string producto, descripcion, imagen, fecha_ingreso;
		 int idProducto = 0, idMarca =0, precio_costo=0, precio_venta=0, existencia =0;  //Variables para POO//

public:
	Producto() {
	}
	Producto(int idPro, string pro, int idMar, string descrip, string img, int preC, int preV, int exis, string fn) {
		idProducto = idPro;
		producto = pro;
		idMarca = idMar;
		descripcion = descrip;
		imagen = img;
		precio_costo = preC;
		precio_venta = preV;
		existencia = exis;
		fecha_ingreso = fn;
	}
	// METODOS
	//set (modificar)
	void setIdProducto(int idPro) { idProducto = idPro; }
	void setproducto(string pro) { producto = pro; }
	void setIdMarca(int idMar) { idMarca = idMar; }
	void setDescripcion(string descrip) { descripcion = descrip; }
	void setImagen(string img) { imagen = img; }
	void setPrecio_costo(int preC) { precio_costo = preC; }
	void setPrecio_venta(int preV) { precio_venta = preV; }
	void setExistencia(int exis) { existencia = exis; }
	void setFecha_ingreso(string fn){ fecha_ingreso = fn; }
	//get (mostrar)
	int getIdProducto() { return idProducto; }
	string getProducto() { return producto; }
	int getIdMarca() { return idMarca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	int getPrecio_costo() { return precio_costo; }
	int getPrecio_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }


	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		string Im = to_string(idMarca);
		string Pc = to_string(precio_costo);
		string Pv = to_string(precio_venta);
		string Exi = to_string(existencia);

		if (cn.getConectar()) {
			string  insertar = "INSERT INTO productos(producto,idMarca,Descripcion,Imagen,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + producto + "'," + Im + ",'" + descripcion + "','" + imagen + "'," + Pc + ", " + Pv +", " + Exi +",'" + fecha_ingreso +"'); ";
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

			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "IDproducto: " << fila[0] << " Producto: " << fila[1] << " IDmarca:" << fila[2] << " Descripcion: " << fila[3] << " Imagen: " << fila[4] << " Precio Costo: " << fila[5] << " Precio Venta: " << fila[6] << " Existencia: " << fila[7]<< "Fecha de ingreso:" << fila[8] << endl;
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
		string Ip = to_string(idProducto);
		string Im = to_string(idMarca);
		string Pc = to_string(precio_costo);
		string Pv = to_string(precio_venta);
		string Exi = to_string(existencia);
		if (cn.getConectar()) {
			string update = "UPDATE productos SET Producto = '" +producto+ "',idMarca = " +Im+ ",Descripcion = '"+descripcion+"',Imagen = '"+imagen+"',Precio_costo = "+Pc+",Precio_venta = "+Pv+",Existencia = "+Exi+",Fecha_ingreso = '"+fecha_ingreso+"' where  idProducto = " + Ip + ";";
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
		string Ip = to_string(idProducto);
		if (cn.getConectar()) {
			string borrar = "DELETE from productos where  idProducto = " + Ip + ";";
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
	void buscar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select producto, idMarca, precio_costo from productos where (idProducto = '"+producto+"'); ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado))
				{
					/*cout << "|                          PRODUCTO                                 |" << endl;*/
					cout << "\n___________________________________________________________________" << endl;

					cout << fila[1] << "       " << fila[0] << "          " << fila[2]; cout << imagen;
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


