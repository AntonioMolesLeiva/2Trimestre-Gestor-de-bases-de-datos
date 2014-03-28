#include<iostream>
#include<cstring>
#include<cstdlib> //para el system("clear") atof
#include<ctype.h> //para el toascii

using namespace std;

struct Alumno{
	string cod_alumno;
	string DNI;
	string Nombre;
	string Apellido1;
	string Apellido2;
	string Telefono;
	double NotaMedia;
};

struct TablaAlumnos{
	Alumno** punteroapuntero;
	int totalTuplas;
};
/*
* @brief Imprime el menu con las opciones
*/
void imprimeMenu() {

cout<<"Pulse la tecla que desee para realizar una de las siguientes acciones: "<<endl;
cout <<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
cout<<"\t1)Crear tabla Alumnos con N tuplas"<<endl;
cout<<"\t2)Vaciar tabla Alumnos"<<endl;
cout<<"\t3)Imprimir tabla Alumnos"<<endl;
cout<<"\t4)Insertar 1 Alumno en tabla Alumnos"<<endl;
cout<<"\t5)Eliminar 1 Alumno en tabla Alumnos"<<endl;
cout<<"\t6)Buscar Alumno por Atributo Nombre en tabla Alumnos (utilizar la búsqueda secuencial)"<<endl;
cout<<"\t7)Buscar Alumno por Atributo Nota Media en tabla Alumnos (utilizar la búsqueda binaria)"<<endl;
cout<<"\t8)Ordenar tabla Alumnos por Atributo Nota Media"<<endl;
cout<<"\t9)Ordenar tabla Alumnos por Código del Alumno"<<endl;
cout<<"\t10)Proyectar la tabla Alumnos por los Atributos Nombre y Nota Media."<<endl;
cout<<"\t11)alumnos que tienen una nota media mayor de 6.5"<<endl;
cout<<"\t0)SALIR"<<endl;
cout <<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;


}
/*
* @brief crea una tabla con dim alumnos comprobando dim y actualizando tabla
* @param TablaAlumnos &tabla por referncia para actualizar los datos
* @param Alumno **v para crear el vector
* @param int dim como total tuplas a insertar
*/
void crearTabla (TablaAlumnos &tabla,Alumno **&v,int dim) {

	while (dim<=0) {
							cout<<"Dimensión de tabla no válido, por favor, introduzca una válida: ";
							cin>>dim;
						}
	//creo vector
	v=new Alumno* [dim];
	
	//si no hay memoria suficiente en el sistema para reservar
	if(v==0) {
		cout<<"El sistema no está disponible para crear la tabla alumnos en éste momento"<<endl;
		}
	else {
		//asigno el puntero						
		tabla.punteroapuntero=v;
		tabla.totalTuplas=dim;
						
		system("clear");
		cout<<endl<<"Tabla alumnos creada con "<<tabla.totalTuplas<<" alumno/s."<<endl<<endl;
		}
}
/*
* @brief borra todas las tuplas e inicializa la tabla a 0
* @param TablaAlumnos &tabla(E-S) como tabla de alumnos a la que aplicaremos la función
* @param int &util (E-S) como las útiles del vector
*/
void EliminarTabla(TablaAlumnos &tabla,int &util) {
	
	//si no hay tuplas
	if (tabla.totalTuplas==0) {
	
		cout<<"No se puede borrar una tabla que no se ha creado."<<endl<<endl;
	}
	
	else {
		//borro las celdas
		delete [] tabla.punteroapuntero;
	
		//despunto puntero
		tabla.punteroapuntero=0;
	
		//inicializo tuplas
		tabla.totalTuplas=0;
	
		//inicializo las útiles
		util=0;
		
		cout<<"Tabla alumnos eliminada totalmente"<<endl<<endl;
	}

}
/*
* @brief imprime la tabla pero solo muestra nombre y nota media de los alumnos con nota media >6.5
* @pre estar ordenada la tabla por nota media 
* @param const TablaAlumnos &tabla como tabla a imprimir
* @param int util como las utiles del vector
*/
void imprimirMas65(const TablaAlumnos &tabla,int util) {
	
	int cont=0;
	
	//compruebo si hay alumnos con nota>6.5
	for(int i=0;i<util&&cont==0;i++){
	
		if(tabla.punteroapuntero[i]->NotaMedia>6.5) cont++;
		}
	
	//si hay al menos 1 alumno con notamedia>6.5	
	if (cont>0) {
		for(int i=0;i<util;i++){
		
			if(tabla.punteroapuntero[i]->NotaMedia>6.5) {
				cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
				cout<<"\t    Nombre: "<<tabla.punteroapuntero[i]->Nombre<<"    Nota media: "<<tabla.punteroapuntero[i]->NotaMedia<<endl;
			}
		}
		

		cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
		
		cout<<"usado "<<util<<" de "<<tabla.totalTuplas<<" tuplas."<<endl;
	}
	else {
		//si no hay tuplas
		if (util==0) cout<<"No existen tuplas para mostrar"<<endl<<endl;
		else cout<<"No existen alumnos con media mayor a 6.5"<<endl<<endl; 
	}
	
}
/*
* @brief imprime la tabla entera pero solo muestra nombre y nota media
* @param const TablaAlumnos &tabla como tabla a imprimir
* @param int util como las utiles del vector
*/
void imprimirNombreNotaMedia(const TablaAlumnos &tabla,int util) {
	for(int i=0;i<util;i++){
	
		cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
		cout<<"\t    Nombre: "<<tabla.punteroapuntero[i]->Nombre<<"    Nota media: "<<tabla.punteroapuntero[i]->NotaMedia<<endl;
		}
		
		if (util==0) cout<<"No existen tuplas para mostrar ("<<util<<" usado de "<<tabla.totalTuplas<<" tuplas)."<<endl<<endl; 
		else {
		cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
		
		cout<<"usado "<<util<<" de "<<tabla.totalTuplas<<" tuplas."<<endl;
		}
}
/*
* @brief imprime las ocurrencias encontradas de nombre
* @param const TablaAlumnos &tabla como tabla a imprimir
* @param int util como las utiles del vector
*/
void BusqAlumnxNombre(const TablaAlumnos &tabla,int util) {
	
	//declaraciones
	int cont=0;
	string nombre;
	
	
		//si no hay tuplas
	if (tabla.totalTuplas==0) {
		system("clear");
		cout<<"no existen tuplas para mostrar."<<endl;
	}
	else {
	cout<<endl<<"Introduce nombre de alumno para mostrar."<<endl<<endl;
	cin>>nombre;
	
		//busco si hay al menos un alumno con ése nombre
	for(int i=0;i<util&&cont==0;i++){
	
		if(tabla.punteroapuntero[i]->Nombre==nombre) cont++;
		}
		//si hay al menos uno imprimo	
	if (cont>0) {
	
	for(int i=0;i<util;i++){
		
		if (tabla.punteroapuntero[i]->Nombre==nombre) {
		cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
		cout<<"\t    Código del Alumno: "<<tabla.punteroapuntero[i]->cod_alumno<<"    DNI: "<<tabla.punteroapuntero[i]->DNI<<endl;
		cout<<"\t    Nombre: "<<tabla.punteroapuntero[i]->Nombre<<endl;
		cout<<"\t    Apellido1: "<<tabla.punteroapuntero[i]->Apellido1<<"     Apellido2: "<<tabla.punteroapuntero[i]->Apellido2<<endl;
		cout<<"\t    Teléfono: "<<tabla.punteroapuntero[i]->Telefono<<"    Nota media: "<<tabla.punteroapuntero[i]->NotaMedia<<endl;
		cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
		}
		
		}
		
	}
	
	if (util==0) cout<<"No existen tuplas para mostrar ("<<util<<" usado de "<<tabla.totalTuplas<<" tuplas)."<<endl<<endl; 
	else if (cont==0) cout<<"No existe ése alumno para mostrar"<<endl<<endl; 
	else cout<<"usado "<<util<<" de "<<tabla.totalTuplas<<" tuplas."<<endl;
	}
}
/*
* @brief imprime la tabla entera
* @param TablaAlumnos &tabla como tabla a imprimir
* @param int util como las utiles del vector
*/
void imprimirTabla(const TablaAlumnos &tabla,int util) {

	for(int i=0;i<util;i++){
	
	cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
	cout<<"\t    Código del Alumno: "<<tabla.punteroapuntero[i]->cod_alumno<<"    DNI: "<<tabla.punteroapuntero[i]->DNI<<endl;
	cout<<"\t    Nombre: "<<tabla.punteroapuntero[i]->Nombre<<endl;
	cout<<"\t    Apellido1: "<<tabla.punteroapuntero[i]->Apellido1<<"     Apellido2: "<<tabla.punteroapuntero[i]->Apellido2<<endl;
	cout<<"\t    Teléfono: "<<tabla.punteroapuntero[i]->Telefono<<"    Nota media: "<<tabla.punteroapuntero[i]->NotaMedia<<endl;
	cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
	}
	
	if (util==0) cout<<"No existen tuplas para mostrar ("<<util<<" usado de "<<tabla.totalTuplas<<" tuplas)."<<endl<<endl; 
}
/*
* @brief comprueba si hay espacio, si no hay, se crea el doble de espacio
* @param TablaAlumnos &tabla (E-S) tabla en la que se va a actualizar el espacio
* @param int util como las útiles del vector
*/
void compruebaHueco(TablaAlumnos &tabla,int util) {
		
		if(util==tabla.totalTuplas) {
	
			Alumno **v;
	
			v=new Alumno* [tabla.totalTuplas*=2];
			
			//copio el vector antiguo en el de mas capacidad creado
			for(int i=0;i<util;i++) v[i]=tabla.punteroapuntero[i];
		
		//elimino tuplas del vector anterior
		delete [] tabla.punteroapuntero;
		
		//reasigno puntero
		tabla.punteroapuntero=v;
	
		}
}

/*
* @brief función que ordena por el método burbuja una tabla por DNI
* @param TablaAlumnos &tabla como vector desordenado a ordenar
* @param int util como número de las casillas útiles del vector (no su dimensión)
*/
void OrdBurbujaxDNI (TablaAlumnos &tabla,int util) {

	//declaraciones
	bool cambio=true;
	Alumno *aux;
	aux=new Alumno;
	
	//operaciones	
	if(aux==0) cout<<"No hay suficiente memoria para ordenar, se abortará el ordenado"<<endl;
	else {
	for (int izqda=0;izqda<util&&cambio;izqda++) {
		
		cambio=false;
		for (int i=util-1;i>izqda;i--) {
			
			if(tabla.punteroapuntero[i]->DNI<tabla.punteroapuntero[i-1]->DNI) {
			
			cambio=true;
	
			//swap de números		
			aux=tabla.punteroapuntero[i];
			tabla.punteroapuntero[i]=tabla.punteroapuntero[i-1];
			tabla.punteroapuntero[i-1]=aux;
			}
		}
	}
	//despunto puntero
	aux=0;
	}
}
/*
* @brief función que devuelve true si está el DNI y false si no está
* @param const TablaAlumnos &tabla como vector desordenado a ordenar
* @param int util como número de las casillas útiles del vector (no su dimensión)
*/
bool BusqBinariaxDNI (const TablaAlumnos &tabla,int util, string buscar) {
	
	//declaraciones
	int izqda=0,derecha=util-1,centro=(izqda+derecha)/2,aux=0;
	bool encontrado=false;
	
	//si no hay registros
	if(tabla.totalTuplas==0) 	cout<<"No hay nada que comparar"<<endl;
	
	else {
	
		while ((derecha-izqda>1) && !encontrado ) {
		
			if (buscar>=tabla.punteroapuntero[centro]->DNI) {
						izqda=centro;
						centro=(izqda+derecha)/2;
			
						if (tabla.punteroapuntero[centro]->DNI==buscar) encontrado=true;
			
					}
		
				else {
					derecha=centro;
					centro=(izqda+derecha)/2;
		
					if (tabla.punteroapuntero[centro]->DNI==buscar) encontrado=true;
		
				}
		}
		
		//cuando el rango es muy pequeño miro ambos lados
		if (tabla.punteroapuntero[centro]->DNI==buscar) {encontrado=true;}
		else if (tabla.punteroapuntero[derecha]->DNI==buscar) {encontrado=true;}
		
		else {encontrado=false;}
		
		return (encontrado);
	
	}
}
/*
* @brief función comprueba si el string introducido hasta que sea correcto (con recursividad)
* @param string &a (E-S) como cadena a comprobar
*/
void compruebaNombre(string &a) {

	//declaracion
	bool c=true;
	
	//operaciones
		//mientras que la cadena sea mayor de 2 caracteres
	if (a.size()>=2) { 
			for (int i=0;i<a.size()&c;i++){
					//para sólo admitir a-z o A-Z
					if((toascii(a[i])<65||(toascii(a[i])>90)&&(toascii(a[i])<97)||toascii(a[i])>122))	{

						c=false;
				
					}
				}
			if(!c) {
				cout<<"cadena de texto incorrecta.\n Introdúzcala de nuevo: ";
				cin>>a;
				compruebaNombre(a);
			}
				
			
			}
	else {
		cout<<"La cadena de texto debe tener al menos 2 caracteres.\n Introdúzcalo de nuevo: ";
		cin>>a;
		compruebaNombre(a);
	}
			
}
/*
* @brief función comprueba si el string introducido hasta que sea correcto y no haya sido introducido en la tabla previamente (con recursividad) NO COMPRUEBA LA LETRA NI PERMITE DNI EXTRANJEROS
* @param  TablaAlumnos &tabla (E-S)como tabla donde están las tuplas
* @param int util como las filas útiles de la tabla
* @param string &dni como el dni a comprobar e introducir
*/
void compruebaDNI( TablaAlumnos &tabla,int util,string &dni) {
	
	//declaracion
	int cont=0;
	
	//operaciones
		//mientras es distinto de 9 caracrteres
	while(dni.size()!=9) {             	
	
	cout<<"DNI erróneo.\n Introdúzcalo de nuevo: ";
	cin>>dni;
	
		}
		
		for (int i=0;i<8;i++){
			if((toascii(dni[i])>=48&&toascii(dni[i])<=57)&&(toascii(dni[8])>=65 && toascii(dni[8])<=90))	{
			cont++;

			}
		
			else {
				cout<<"DNI dni erróneo (la letra en mayúsculas).\n Introdúzcalo de nuevo: ";
				cin>>dni;
				compruebaDNI(tabla,util,dni);
			}
	
		}
	
	//2da parte
		//si hay mas de 1 tupla comprobar
	if (tabla.totalTuplas>0) {
		
		//ordeno por DNI
		OrdBurbujaxDNI (tabla,util);
		
		//mientras que exista el DNI vuelve a introducirlo
		while(BusqBinariaxDNI (tabla,util,dni)) {
	 	
	 		cout<<endl<<"Ya existe éste DNI.\n\nPor favor introduce otro DNI: ";
	 		cin>>dni;
	 		compruebaDNI(tabla,util,dni);
	 	}
	 	
	 	
	 	cout<<"El DNI válido vale: "<<dni<<endl<<endl;	
	}
	
	
	}
/*
* @brief Busca un código de alumno en la tabla por el método de búsqueda binario true si lo encuentra falso si no está
* @param const TablaAlumnos &tabla como vector a buscar
* @param int util como número de las casillas útiles del vector (no su dimensión)
* @param string buscar como el código de alumno a buscar
*/
bool BusqBinariaxCodigo_Alumno (const TablaAlumnos &tabla,int util, string buscar) {
	
	//declaraciones
	int izqda=0,derecha=util-1,centro=(izqda+derecha)/2,aux=0;
	bool encontrado=false;
	
	
	//operaciones
	if(tabla.totalTuplas==0) {
	cout<<"No hay nada que comparar"<<endl;
	}
	else {
	
		while ((derecha-izqda>1) && !encontrado ) {
		
			if (buscar>=tabla.punteroapuntero[centro]->cod_alumno) {
						izqda=centro;
						centro=(izqda+derecha)/2;
			
						if (tabla.punteroapuntero[centro]->cod_alumno==buscar) encontrado=true;
			
					}
		
				else {
					derecha=centro;
					centro=(izqda+derecha)/2;
		
					if (tabla.punteroapuntero[centro]->cod_alumno==buscar) encontrado=true;
		
				}
		}
		//cuando el rango es muy pequeño
		if (tabla.punteroapuntero[centro]->cod_alumno==buscar) {encontrado=true;}
		
		else {encontrado=false;}
		
		return (encontrado);
	
	}
}

/*
* @brief función que ordena una tabla por código alumno
* @param int TablaAlumnos &tabla como vector desordenado a ordenar
* @param int util como número de las casillas útiles del vector (no su dimensión)
*/
void OrdBurbujaxCodigo_Alumno (TablaAlumnos &tabla,int util) {

//declaraciones
	bool cambio=true;
	Alumno *aux;
	aux=new Alumno;
	
	//operaciones
	for (int izqda=0;izqda<util&&cambio;izqda++) {
		
		cambio=false;
		for (int i=util-1;i>izqda;i--) {
			
			if(tabla.punteroapuntero[i]->cod_alumno<tabla.punteroapuntero[i-1]->cod_alumno) {
			
			cambio=true;
	
			//swap de números		
			aux=tabla.punteroapuntero[i];
			tabla.punteroapuntero[i]=tabla.punteroapuntero[i-1];
			tabla.punteroapuntero[i-1]=aux;
			}
		}
	}
	//despunto puntero
	aux=0;
}
/*
* @brief función comprueba si el string introducido hasta que sea correcto y no haya sido introducido en la tabla previamente (con recursividad)
* @param  TablaAlumnos &tabla (E-S)como tabla donde están las tuplas
* @param int util como las filas útiles de la tabla
* @param string &a como la cadena a comprobar e introducir
* @pos devuelve la tabla ordenada por código de alumno
*/
void compruebaCodigo( TablaAlumnos &tabla,int util,string &a) {
 	
	//si hay mas tuplas comprobar
 	if(tabla.totalTuplas!=0) {
 	
 	//ordeno por codigo del alumno
 	OrdBurbujaxCodigo_Alumno (tabla,util);
 	
 	//mientras que exista, introdúcelo de nuevo
 	while(BusqBinariaxCodigo_Alumno (tabla,util,a)) {
 	
 		cout<<endl<<"Ya existe un codigo previo.\n\nPor favor introduce otro código: ";
 		cin>>a;
 	}
 	
 	
 	cout<<"El codigo a inroducir válido vale: "<<a<<endl<<endl;	
 }
}
/*
* @brief función comprueba si el string introducido es un teléfono formato 123456789 o +00123456789 o +000123456789 (con recursividad)
* @param  TablaAlumnos &tabla (E-S)como tabla donde están las tuplas
* @param int util como las filas útiles de la tabla
* @param string &a como la cadena a comprobar e introducir
*/
void compruebaTlf(string a) {
	
	//declaraciones
	bool c=true;
	
	//operaciones
		//formato 111222333
		if (a.size()==9) { 
				for (int i=0;i<a.size()&&c;i++){
						if((toascii(a[i])<48||toascii(a[i])>57))	{
						c=false;
						}
					}
				if(!c){ 
					cout<<"Teléfono incorrecto.\n Introdúzcalo de nuevo: ";
					cin>>a;
					compruebaTlf(a);
				}
				else {
					cout<<"numero correcto "<<a<<endl;
				}
				
			
				}
		// formato +00111222333 o +000111222333
		else if (a.size()==12||a.size()==13) {
			//si tiene el símbolo +
			if (toascii(a[0])==43) {
				for (int i=1;i<a.size()&&c;i++){
						if((toascii(a[i])<48||toascii(a[i])>57))	{
						c=false;
						}
					}
				if(!c){ 
					cout<<"Teléfono incorrecto.\n Introdúzcalo de nuevo: ";
					cin>>a;
					compruebaTlf(a);
				}
				else {
					cout<<"numero correcto "<<a<<endl;
				}
				
			}
			else {
				cout<<"Teléfono incorrecto.\n Introdúzcalo de nuevo: ";
				cin>>a;
				compruebaTlf(a);
			}
		}
		else {
			cout<<"Teléfono erróneo.\n Introdúzcalo de nuevo: ";
			cin>>a;
			compruebaTlf(a);
		}
}
/*
* @brief  función que comprueba si la cadena introducida es una nota media válida (con recursividad)
* @param  string &a (E-S) como cadena a comprobar
*/
double compruebaNotaMEdia(string &a) {
	//declaraciones
	bool c=true;
	int npuntos=0;
	
	//operaciones
		for (int i=0;i<a.size()&&c;i++){
					
						if((toascii(a[i])<=48||toascii(a[i])>=57))	{
						
							//cuenta los puntos en la cadena
							if(toascii(a[i])==46) {
								npuntos++;
								}
							else {
							c=false;
							}
						}
						
					}
				if(!c||npuntos>1){ 
					cout<<"Nota media incorrecta(usar . cómo decimal).\n Introdúzcala de nuevo: ";
					cin>>a;
					compruebaNotaMEdia(a);
				}
				else {
					cout<<"Nota Media correcta. "<<a<<endl;
				}
			
		//2da parte
		
		//declaraciones
		int longstring=a.size();
		char aux[longstring];
		
		//operaciones
			//copio un string en un string de char
		for(int h=0;h<=longstring;h++) {
		 aux[h]=a[h];
		}
	//salida	
		//convierto string en double
	return(atof(aux));
}
/*
* @brief inserta un alumno en el vector y lo agranda si fuera necesario
* @param TablaAlumnos tabla como tabla a insertar un alumno
* @param int util como las utiles del vector
*/
void insertarAlumno(TablaAlumnos &tabla,int &util) {
	
	Alumno *a;
	a=new Alumno;
	string notaMedia;
	if(a==0) cout<<"El sistema no dispone de memoria para la operación. Vuelva a intentarlo mas tarde"<<endl;
	
	else {
		compruebaHueco(tabla,util);
				
		cout<<"Codigo Alumno: ";
		cin>>a->cod_alumno;
		compruebaCodigo(tabla,util,a->cod_alumno);
		cout<<"DNI: ";
		cin>>a->DNI;
		compruebaDNI(tabla,util,a->DNI);
		cout<<"Nombre:";
		cin>>a->Nombre;
		compruebaNombre(a->Nombre);
		cout<<"Apellido1:";
		cin>>a->Apellido1;
		compruebaNombre(a->Apellido1);
		cout<<"Apellido2:";
		cin>>a->Apellido2;
		compruebaNombre(a->Apellido2);
		cout<<"Teléfono:";
		cin>>a->Telefono;
		compruebaTlf(a->Telefono);
		cout<<"NotaMedia:";
		cin>>notaMedia;
		
		/*compruebaCodigo(tabla,util,a->cod_alumno);
		compruebaDNI(tabla,util,a->DNI);
		compruebaNombre(a->Nombre);
		compruebaNombre(a->Apellido1);
		compruebaNombre(a->Apellido2);
		compruebaTlf(a->Telefono);*/
	
		
		a->NotaMedia=compruebaNotaMEdia(notaMedia);
		tabla.totalTuplas=1;
		tabla.punteroapuntero[util]=a;
		a=0;
		util++;
		
		system("clear");
		
		cout<<"Alumno insertado correctamente"<<endl<<endl;

	}
}
/*
* @brief elimina un alumno (por el código del alumno) de la tabla
* @param TablaAlumnos &tabla (E-S) como tabla dónde se va a eliminar el alumno
* @param int &util (E-S) como tuplas útiles de la tabla (no su dimensión)
*/
void EliminarAlumno(TablaAlumnos &tabla,int &util) {
	
	//declaraciones
	string codAlu;
	
	//operaciones
	if (tabla.totalTuplas==0) {
	system("clear");
		
		cout<<endl<<"No existen alumnos para eliminar"<<endl<<endl;
	}
	else {
		cout<<"inserta un Código de Alumno Válido: ";
		cin>>codAlu;
		
		//si existe el código del alumno
		if(BusqBinariaxCodigo_Alumno (tabla,util,codAlu)) {
		
		//declaraciones-operaciones
		Alumno **v;
		tabla.totalTuplas--;
		v=new Alumno* [tabla.totalTuplas];
		util--;		
		
		for(int i=0,j=0;i<tabla.totalTuplas+1;i++) {
			
			//mientras que sea distinto el codigo del alumno con lo que estoy buscando
			if(tabla.punteroapuntero[i]->cod_alumno!=codAlu) {
				
				//copio el vector de punteros en uno auxiliar
				v[j]=tabla.punteroapuntero[i];
				j++;
			}
			
		}
		
		//borro el vector de punteros antiguo
		delete [] tabla.punteroapuntero;
		
		//vacío dirección de memoria
		tabla.punteroapuntero=0;
		
		//reasigno al vector nuevo
		tabla.punteroapuntero=v;
		
		//vacío dirección del puntero auxilar
		v=0;
		
		cout<<endl<<"Alumno borrado exitosamente"<<endl<<endl;
		}
		
		else {
			cout<<"No existen alumnos con codigo \" "<<codAlu<<" \""<<endl;
			EliminarAlumno(tabla,util);
		}
	}
}

/*
* @brief imprime la tabla desde la primera nota media buscada
* @param const TablaAlumnos &tabla como tabla a imprimir
* @param int util como las utiles del vector (no su dimensión)
* @param int j como posición inicial desde la cual imprimir
*/
void imprimirTablaBusqBinaria(const TablaAlumnos &tabla,int util,int j) {
	//declaracion
	double aux;
	
	//operaciones
	aux=tabla.punteroapuntero[j]->NotaMedia;
	
	for(j;j<util&&tabla.punteroapuntero[j]->NotaMedia==aux;j++){
	
	cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
	cout<<"\t    Código del Alumno: "<<tabla.punteroapuntero[j]->cod_alumno<<"    DNI: "<<tabla.punteroapuntero[j]->DNI<<endl;
	cout<<"\t    Nombre: "<<tabla.punteroapuntero[j]->Nombre<<endl;
	cout<<"\t    Apellido1: "<<tabla.punteroapuntero[j]->Apellido1<<"     Apellido2: "<<tabla.punteroapuntero[j]->Apellido2<<endl;
	cout<<"\t    Teléfono: "<<tabla.punteroapuntero[j]->Telefono<<"    Nota media: "<<tabla.punteroapuntero[j]->NotaMedia<<endl;
	cout<<endl<<"\t* * * * * * * * * * * * * * * * * * * "<<endl<<endl;
	}
	
	if (util==0) cout<<"No existen tuplas para mostrar ("<<util<<" usado de "<<tabla.totalTuplas<<" tuplas)."<<endl<<endl; 
}
/*
* @brief Busca por nota media en la tabla y coge la primera posicion en el vector
* @param TablaAlumnos &tabla (E-S) como vector a buscar
* @param int util como número de las casillas útiles del vector (no su dimensión)
*/
void BusqBinariaxNotaMedia (TablaAlumnos &tabla,int util) {

	//declaraciones
	int izqda=0,derecha=util-1,centro=(izqda+derecha)/2,aux=0;
	bool encontrado=false;
	double buscar=0;
	
	//operaciones
	if(tabla.totalTuplas==0) {
	system("clear");
	cout<<"No existen tuplas para mostrar ("<<util<<" usado de "<<tabla.totalTuplas<<" tuplas)."<<endl<<endl; 
	}
	else {
	cout<<"¿Qué nota media quieres buscar?: ";
	cin>>buscar;
	
	while (izqda<derecha && !encontrado ) {
		
		if (derecha-izqda==1) {
		if(buscar==tabla.punteroapuntero[centro]->NotaMedia) centro=centro;
		if(buscar==tabla.punteroapuntero[derecha]->NotaMedia) centro=derecha;
		if(buscar==tabla.punteroapuntero[izqda]->NotaMedia) centro=izqda;
		encontrado=true;
		}
		
		else if (buscar>=tabla.punteroapuntero[centro]->NotaMedia) {
			izqda=centro;
			centro=(izqda+derecha)/2;
			
			if (tabla.punteroapuntero[centro]->NotaMedia==buscar) {
			
				encontrado=true;
				aux=centro;

				if ((aux-1>=0)) {
					while(tabla.punteroapuntero[aux]->NotaMedia==tabla.punteroapuntero[centro]->NotaMedia&&(aux-1>=0))
					{

						aux--;
					}
					centro=aux;
					centro++;
				}
			}
			}
			
			
		else {
		derecha=centro;
		centro=(izqda+derecha)/2;
		
		if (tabla.punteroapuntero[centro]->NotaMedia==buscar) {
			
				encontrado=true;
				aux=centro;

				if ((aux-1>=0)) {
					
					while(tabla.punteroapuntero[aux]->NotaMedia==tabla.punteroapuntero[centro]->NotaMedia&&(aux-1>=0))
					{

						aux--;
					}
					centro=aux;
					centro++;
				}
			}
		
		}
		
	
	
		//2da parte
		if (encontrado==true) {
	
			if (tabla.punteroapuntero[centro]->NotaMedia==buscar) {imprimirTablaBusqBinaria(tabla,util,centro);}
			else {
				system("clear");
				cout<<endl<<"No existe ésta nota"<<endl<<endl;
				}
	
	
		}
	
		else {
		cout<<"No existen alumnos con nota media igual a "<<buscar<<endl<<endl;
		}

	}
	}
}
/*
* @brief función que ordena una tabla por el método de la burbuja
* @param int TablaAlumnos &tabla (E-S) como vector desordenado a ordenar
* @param int util como número de las casillas útiles del vector (no su dimensión)
*/
void OrdBurbujaxNotaMedia (TablaAlumnos &tabla,int util) {
	
	//declaraciones
	bool cambio=true;
	Alumno *aux;
	aux=new Alumno;
	
	//operaciones
	for (int izqda=0;izqda<util&&cambio;izqda++) {
		
		cambio=false;
		for (int i=util-1;i>izqda;i--) {
			
			if(tabla.punteroapuntero[i]->NotaMedia<tabla.punteroapuntero[i-1]->NotaMedia) {
			
			cambio=true;
	
			//swap de números		
			aux=tabla.punteroapuntero[i];
			tabla.punteroapuntero[i]=tabla.punteroapuntero[i-1];
			tabla.punteroapuntero[i-1]=aux;
			}
			
		}
	}
	aux=0;
}
int main (){

	system("clear");
	
	//declaraciones
	int opcion=1,dim=0,util=0;
	TablaAlumnos tabla;
	tabla.totalTuplas=0;
	tabla.punteroapuntero=0;
	Alumno *alu=0;
	Alumno **v=0;
	
	
	/*
	PRUEBAS
	*/
	/*Alumno *a;
	a=new Alumno;
	crearTabla(tabla,v,8);
	a->cod_alumno="5";
	a->DNI="75486070R";
	a->Nombre="Antonio";
	a->Apellido1="Moles";
	a->Apellido2="Leiva";
	a->Telefono="677781271";
	a->NotaMedia=6.6;
	tabla.punteroapuntero[0]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="4";
	a->DNI="12345678T";
	a->Nombre="Juanito";
	a->Apellido1="Valderrama";
	a->Apellido2="Valderrama";
	a->Telefono="678987456";
	a->NotaMedia=7;
	tabla.punteroapuntero[1]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="6";
	a->DNI="11111111S";
	a->Nombre="Jose";
	a->Apellido1="Diaz";
	a->Apellido2="Molina";
	a->Telefono="22222222U";
	a->NotaMedia=3;
	tabla.punteroapuntero[2]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="2";
	a->DNI="33333333R";
	a->Nombre="Antonio";
	a->Apellido1="asdf";
	a->Apellido2="asdf";
	a->Telefono="666666666";
	a->NotaMedia=1;
	tabla.punteroapuntero[3]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="1";
	a->DNI="55555555W";
	a->Nombre="JAvier";
	a->Apellido1="Diaz";
	a->Apellido2="Daroca";
	a->Telefono="777777777";
	a->NotaMedia=4;
	tabla.punteroapuntero[4]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="3";
	a->DNI="00000000W";
	a->Nombre="A";
	a->Apellido1="A";
	a->Apellido2="A";
	a->Telefono="000000000";
	a->NotaMedia=4;
	tabla.punteroapuntero[5]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="7";
	a->DNI="10000000E";
	a->Nombre="B";
	a->Apellido1="B";
	a->Apellido2="B";
	a->Telefono="000000000";
	a->NotaMedia=4;
	tabla.punteroapuntero[6]=a;
	a=0;
	a=new Alumno;
	a->cod_alumno="8";
	a->DNI="10000000Z";
	a->Nombre="B";
	a->Apellido1="B";
	a->Apellido2="B";
	a->Telefono="000000000";
	a->NotaMedia=4;
	tabla.punteroapuntero[7]=a;
	a=0;
	util=8;*/
	//PRUEBAS
	
	cout<<"BIENVENIDO AL SIMULADOR DE FUNCIONAMIENTO DE UN SGBD RELACIONAL"<<endl;
	
	//operaciones	
	while(opcion>=1&&opcion<=11) {
		imprimeMenu();
		cout<<"Elige una opción: ";
		cin>>opcion;
	
		while (opcion<0||opcion>11) {
		cout<<"Opción errónea\n Introduce opcón válida(0-11): ";
		cin>>opcion;
		}
	
	
			switch(opcion) {
				case 1: //crear tabla alumnos
			
					system("clear");
					if ((tabla.totalTuplas==0&&tabla.punteroapuntero==0)) {
					
						cout<<"¿Cuantos alumnos desea crear en la tabla?: ";
						cin>>dim;
					
						crearTabla(tabla,v,dim);
					}
					else {
						cout<<"Ya existe una tabla y no se pueden crear mas tablas."<<endl<<endl;
					}
				
					break;
				case 2: //eliminar tabla alumnos
					system("clear");
				
					EliminarTabla(tabla,util);
					
					break;
				case 3: //imprimir tabla alumnos
					system("clear");
				
					imprimirTabla(tabla,util);
					break;
				case 4: //insertar alumno en la tabla
					system("clear");
				
					insertarAlumno(tabla,util);
					break;
				case 5: //eliminar alumno en la tabla
					system("clear");
					
					OrdBurbujaxCodigo_Alumno (tabla,util);
					EliminarAlumno(tabla,util);
					
					break;
				case 6: //buscar alumno por nombre busq secuencial
					system("clear");
				
					BusqAlumnxNombre(tabla,util);
					break;
				case 7: //buscar alumno por nota media busq binaria
					system("clear");
				
					OrdBurbujaxNotaMedia (tabla,util);
					BusqBinariaxNotaMedia (tabla,util);
					
					break;
				case 8: //ordenar por nota media
					system("clear");
				
					OrdBurbujaxNotaMedia (tabla,util);
					imprimirTabla(tabla,util);
					break;
				case 9: //ordenar por codigo de alumno
					system("clear");
					
					OrdBurbujaxCodigo_Alumno (tabla,util);
					imprimirTabla(tabla,util);
					break;
				case 10: //visualizar tabla solo con nombre y nota media
					system("clear");
					
					imprimirNombreNotaMedia(tabla,util);
					break;
				case 11: //EXTRA alumnos que tienen una nota media mayor de 6.5
					system("clear");
				
					imprimirMas65(tabla,util);
					break;
	
			}
		
		
	}
	
	cout<<"Ha salido del sistema."<<endl;
	EliminarTabla(tabla,util);
	
}
