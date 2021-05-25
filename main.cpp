#include <iostream>
#include <limits.h>
using namespace std;

    int const fila=4;
	int const col=5;
//fucniones y procesos en int main 
void llenaMatrizPrecio ( int precio [fila][col]);
void imprimirMatrizPrecio (int precio [fila][col]);
int calcularRecaudoPuerto (string puertoCarga[fila][col], string nombrePuerto, int precio[fila][col]);
void llenarVectorPuertos (int Npuertos, string vectorPuertos[]);
void mostrarDisponibles (bool disponibilidad [fila][col]);
//impresion matrices
void imprimirDisponibilidad (bool disponibilidad [fila][col]);
void imprimirMarca (string marca [fila][col]);
void imprimirTipoArticulo (string tipoArticulo [fila][col]);
void imprimirPeso (int peso[fila][col]);
void imprimirPuertoCarga (int puertoCarga[fila][col]);
//procedimiento
void conteoContenedores (bool disponibilidad [fila][col]);
void burbuja (string vectorPuertos [], int contenedorPuerto [], int Npuertos);
void marcaZonaEconomica (int precio [fila][col], string marca [fila][col]);
void marcaZonaPremium (int precio [fila][col], string marca [fila][col]);
void reporteEmpresa (int precio [fila][col], string marca [fila][col], string respuesta);
//funciones
float promedioPesoContenedores (int peso [fila][col]);
int filaMayorCarga (int peso [fila][col]);
int columnaMenorCarga (int peso [fila][col]);
int columnaMenorCarga (int peso [fila][col]);
int cantidadContenedoresClase (string tipoArticulo [fila][col]);
float promedioCargaPuerto (string puertoCarga [fila][col],int peso [fila][col]);
string nombreEmpresaMayorContenedor (string marca [fila][col], int peso [fila][col]);
int ContenedorLiviano (int peso [fila][col]);


//////////////////////////////////////////////////////////////////////////////////
int main (){
 //creacion de matrices   
	bool disponibilidad [fila][col];
	string marca [fila][col];
	string tipoArticulo [fila][col];
	int peso [fila][col];
	string puertoCarga [fila][col];
	int precio [fila][col];
	
//inicializacion y limpieza
	for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			disponibilidad [i][j]=1;
			peso [i][j]=0;
			tipoArticulo [i][j]="*";
			marca [i][j]="n";
			puertoCarga [i][j]="*";
			precio [i][j]=0;
		}
	}
	
    cout<<"###################### Informacion puertos ######################"<<endl;
//pregunta por numero de puertos
	int Npuertos=0;
	cout<<"Ingrese cantidad de puertos"<<endl;
	cin>>Npuertos;
	
//llenar vector puertos
    string vectorPuertos [Npuertos];
    llenarVectorPuertos (Npuertos,vectorPuertos);
//vectores
        int contenedorPuerto [Npuertos];

	
//llenar matriz precio 
    llenaMatrizPrecio (precio);
cout<<endl;
cout<<"El siguiente diagrama muestra de acuerdo a la coordenada el valor a pagar por su ocupacion"<<endl;
imprimirMatrizPrecio (precio);
cout<<endl;
//inicio preguntas de embarque
    float porcentajeOcupacionActual=0.0;
	float porcentajeOcupacionParcial=0.0;
    int contadorContenedorParcial=0;
cout<<"#####################################################################"<<endl;
for (int i=0; i<Npuertos;i++){	
    int totalPuerto=0;
    string nombrePuerto=vectorPuertos [i];
cout<<"####### Bienvenido al puerto "<<vectorPuertos [i]<<" ####### "<<endl;
//preguntar el numero de contenedores
    int Ncontenedor=0;
    cout<<"Ingrese cantidad de contenedores que quiere embarcar"<<endl;
	cin>>Ncontenedor;
	contenedorPuerto [i]=Ncontenedor;
     int contador=0;
//comienzo de llenado de matrices
    
        do{
        int coordenadaF=-1;
        int coordenadaC=-1;
//impresion coordenadas disponibles
        cout<<endl;
        cout<<"La coordenadas disponibles son:"<<endl;
        cout<<endl;
        mostrarDisponibles (disponibilidad);
        cout<<"Ingrese la coordenada de fila"<<endl;
		cin>>coordenadaF;
		cout<<"Ingrese la coordenada de columna"<<endl;
		cin>>coordenadaC;
		if (coordenadaF>=0 &&coordenadaF<fila && coordenadaC>=0 && coordenadaC<col && disponibilidad [coordenadaF][coordenadaC]==1){
			contador=contador+1;
			cout<<"Ingrese la marca del contenedor"<<endl;
			cin>> marca [coordenadaF][coordenadaC];
			cout<<"Ingrese el tipo de Articulo (A=alimentos, B=D.electronicas, C=Ropa y textiles"<<endl;
			cin>>tipoArticulo [coordenadaF][coordenadaC];
			cout<<"Ingrese el peso del contenedor"<<endl;
			cin>>peso [coordenadaF][coordenadaC];
			
			puertoCarga [coordenadaF][coordenadaC]=nombrePuerto;
			disponibilidad [coordenadaF][coordenadaC]= 0;
			cout<<"##################################################################"<<endl;
			cout<<"Contenedor ingresado correctamente"<<endl;
			cout<<"##################################################################"<<endl;
//funcion total por puerto
			totalPuerto=calcularRecaudoPuerto (puertoCarga,nombrePuerto,precio);
//proceso porcentaje ocupacion parcial
    contadorContenedorParcial=contadorContenedorParcial+1;
    porcentajeOcupacionParcial=(contadorContenedorParcial*100)/20;
    

		}else{
		    cout<<"##################################################################"<<endl;
		    cout<<"Coordenada no valida, ingrese una nueva coordenada"<<endl;
		    cout<<"##################################################################"<<endl;
        }
    }while(contador!=Ncontenedor);

//informacion para cada puerto
    porcentajeOcupacionActual=porcentajeOcupacionActual+porcentajeOcupacionParcial;
    cout<<"El porcentaje de ocupacion actual del buque es: "<<porcentajeOcupacionParcial<<"%"<<endl;
    cout<<endl;
    cout<<"El valor recaudado en el puerto "<<vectorPuertos [i]<<" es:$"<< totalPuerto<<endl;
    cout<<endl;
   }
   
   cout<<"###########################################################################"<<endl;
//impresion de matrices 
cout<<"Disponibilidad"<<endl;
imprimirDisponibilidad (disponibilidad);
cout<<endl; 
cout<<"Marca"<<endl;
imprimirMarca (marca);
cout<<endl;
cout<<"Tipo de articulo"<<endl;
imprimirTipoArticulo (tipoArticulo);
cout<<endl;
cout<<"Peso"<<endl;
imprimirPeso (peso);
cout<<endl;
cout<<"Puerto carga"<<endl;
 for (int i=0;i<fila;i++){
     for (int j=0;j<col;j++){
         cout<< puertoCarga [i][j]<<"\t";
     }
     cout<<endl;
 }
cout<<endl;

cout<<"############################ Recorrido finalizado ####################################"<<endl;
cout<<endl;
//procedimiento 1
conteoContenedores (disponibilidad);
cout<<endl;
//procedimiento 2 
burbuja (vectorPuertos,contenedorPuerto,Npuertos);
cout<<endl;
//procedimiento 3
marcaZonaEconomica (precio,marca);
cout<<endl;
//procedimiento 4
marcaZonaPremium (precio,marca);
cout<<endl;
//procedimiento 5
string respuesta="";
cout<<"Ingrese el nombre de la empresa, para generar el reporte"<<endl;
cin>>respuesta;
reporteEmpresa (precio,marca,respuesta);
cout<<endl;
//funcion 6
cout<<endl;
float pesoPromedioTotal=0;
pesoPromedioTotal=promedioPesoContenedores (peso);
cout<<"el promedio de peso de las contenedores embarcados es: "<<pesoPromedioTotal<<endl;
cout<<endl;
//funcion 7
cout<<endl;
int mayorCarga=0;
mayorCarga= filaMayorCarga (peso);
cout<<"La fila con mayor carga es la: "<<mayorCarga;
cout<<endl;
//funcion 8
cout<<endl;
int menorCarga=0;
menorCarga=columnaMenorCarga (peso);
cout<<"La columna con menor carga es la: "<<menorCarga;
cout<<endl;

//funcion 9
cout<<endl;
int contadorTipo=0;
contadorTipo=cantidadContenedoresClase (tipoArticulo);
cout<<"La cantidad de contenedores es:"<<contadorTipo<<endl;
cout<<endl;

//funcion 10 
cout<<endl;
float promedioPuerto=0;
promedioPuerto=promedioCargaPuerto (puertoCarga,peso);
cout<<"El promedio de peso embarcado en ese puerto es: "<<promedioPuerto<<endl;
cout<<endl;
//funcion 11
cout<<endl;
string empresa="";
empresa=nombreEmpresaMayorContenedor (marca, peso);
cout<<" La empresa "<<empresa<< " posee el contenedor con más peso"<<endl;
cout<<endl;
//funcion 12
cout<<endl;
int liviano=0;
liviano=ContenedorLiviano (peso);
cout<<"El peso del contenedor mas liviano es: "<<liviano<<endl;
cout<<endl;

   return 0;
  }



void llenaMatrizPrecio (int precio [fila][col]){
     for (int j=0;j<col;j++){
        for (int i=0;i<fila;i++){
             if (j==0 || j==4 || i==0 || i==3 ){
                 precio [i][j]=100;
             }else{
                 precio [i][j]=300;
             }
        }
    }
 }
 
void imprimirMatrizPrecio (int precio [fila][col]){
      for (int j=0;j<col;j++){
        for (int i=0;i<fila;i++){
             if (j==0 || j==4 || i==0 || i==3 ){
                 precio [i][j]=100;
             }else{
                 precio [i][j]=300;
             }
        }
    }
    	for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			cout<<precio[i][j]<<"\t";
		}
		cout<<endl;
	}
 }

void llenarVectorPuertos (int Npuertos, string vectorPuertos[]){
     for (int i=0;i<Npuertos;i++){
        cout<<"Ingrese el nombre del puerto "<<i+1<<endl;
        cin>>vectorPuertos[i];
    }
}

void mostrarDisponibles (bool disponibilidad [fila][col]){
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (disponibilidad [i][j]==1){
                cout<<i<<","<<j<<"\t";
            }
        }
        cout<<endl;
    }
    }
    
int calcularRecaudoPuerto (string puertoCarga[fila][col], string nombrePuerto, int precio[fila][col]){
    int total=0;
    for (int i=0; i<fila;i++){
        for(int j=0;j<col;j++){
            if (puertoCarga [i][j]==nombrePuerto){
                total=total+precio [i][j];
            }
        }
    }
    return total;
}

void imprimirDisponibilidad (bool disponibilidad [fila][col]){
    for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			cout<<disponibilidad [i][j]<<"\t";
		}
		cout<<endl;
	}
 }

void imprimirMarca (string marca [fila][col]){
    for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			cout<<marca[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void imprimirTipoArticulo (string tipoArticulo [fila][col]){
    for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			cout<<tipoArticulo[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void imprimirPeso (int peso[fila][col]){
	for (int i=0;i<fila;i++){
		for (int j=0;j<col;j++){
			cout<<peso[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void imprimirPuertoCarga (int puertoCarga[fila][col]){
	for (int k=0;k<fila;k++){
		for (int j=0;j<col;j++){
			cout<<puertoCarga[k][j]<<"\t";
		}
		cout<<endl;
	}
}

//procedimiento

//procedimiento 1  
void conteoContenedores (bool disponibilidad [fila][col]){
    int contador=0;
    for (int i=0;i<fila;i++){
        for (int j=0;j<col;j++){
            if (disponibilidad[i][j]==0){
                contador=contador+1;
            }
        }
    }
    cout<<"el numero de contenedores embarcados es:"<<contador<<endl;
}

// procedimiento 2
void burbuja (string vectorPuertos [], int contenedorPuerto [], int Npuertos){
    int auxC=0;
    for (int i=0; i<Npuertos;i++){
        for (int j=0;j<Npuertos;j++){
            if (contenedorPuerto [i]>contenedorPuerto [j]){
                auxC= contenedorPuerto[i];
                contenedorPuerto[i]=contenedorPuerto[j];
                contenedorPuerto[j]=auxC;
                string auxN=vectorPuertos[i];
                vectorPuertos[i]=vectorPuertos[j];
                vectorPuertos[j]=auxN;
            }
        }
    }
    cout<<"Reporte de puertos y el numero de contenedor ingresados"<<endl;
    for (int i=0;i<Npuertos;i++){
        cout<<"- "<<vectorPuertos[i]<<"--> "<<contenedorPuerto [i]<<endl;
    }
    }
    
// procedimiento 3
void marcaZonaEconomica (int precio [fila][col], string marca [fila][col]){
    cout<<"La marcas que tienen contenedores en la zona economica son:"<<endl;
    for (int i=0;i<fila;i++){
        for (int j=0;j<col;j++){
            if (precio [i][j]==100 && marca[i][j]!="n"){
                cout<<"- "<<marca [i][j]<<endl;
            }
        }
    }
}

//procedimiento 4
void marcaZonaPremium (int precio [fila][col], string marca [fila][col]){
    cout<<"Las marcas que tienen contenedores en la zona premium son: "<<endl;
      for (int i=0;i<fila;i++){
        for (int j=0;j<col;j++){
            if (precio [i][j]==300 && marca[i][j]!="n"){
                cout<<"- "<<marca [i][j]<<endl;
            }
        }
    }
}

//procedimiento 5 
void reporteEmpresa (int precio [fila][col], string marca [fila][col], string respuesta){

    int contadorPremium=0;
    int contadorEconomico=0;
    int totalPremium=0;
    int totalEconomico=0;
    int total=0;
    
     for (int i=0;i<fila;i++){
        for (int j=0;j<col;j++){
            if (marca [i][j]==respuesta && precio [i][j]==300){
                contadorPremium=contadorPremium+1;
                totalPremium=totalPremium+ precio [i][j];
            }
        }
    }
    
     for (int i=0;i<fila;i++){
        for (int j=0;j<col;j++){
            if (marca [i][j]==respuesta && precio [i][j]==100){
                contadorEconomico=contadorEconomico+1;
                totalEconomico=totalEconomico+precio [i][j];
            }
        }
    }
    total=totalEconomico+totalPremium;
    
    cout<<"Reporte"<<endl;
    cout<<"Contenedores en zona economica: "<<contadorEconomico<<endl;
    cout<<"Contenedores zona premium: "<<contadorPremium<<endl;
    cout<<"El valor a pagar: "<<total<<endl;
}

//funciones

//funcion 6 
float promedioPesoContenedores (int peso [fila][col]){
    float promedio=0;
    int contador=0;
    int acumulador=0;
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (peso [i][j]!=0){
                contador=contador+1;
                acumulador=acumulador+peso [i][j];
            }
        }
    }
    promedio=acumulador/contador;
    return promedio;
}

//funcion 7
int filaMayorCarga (int peso [fila][col]){
    int vectorCarga [fila];
    int acumulador=0;
    int mayor=INT_MIN;
    int filaMayor=-1;
for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
        acumulador=acumulador+ peso [i][j];
    }
    vectorCarga [i]=acumulador;
    acumulador=0;
}
    for (int i=0; i<fila;i++){
        if (vectorCarga [i]> mayor){
            mayor= vectorCarga[i];
            filaMayor=i;
        }
    }
    return filaMayor;
}

//funcion 8
int columnaMenorCarga (int peso [fila][col]){
    int menor= INT_MAX;
    int vector [col];
    int pesoCol=0;
    int columnaMenor=-1;
    for (int j=0; j<col;j++){
        for (int i=0;i<fila;i++){
            pesoCol= pesoCol+peso [i][j];
        }
        vector [j]=pesoCol;
        pesoCol=0;
    }
    for (int j=0; j<col;j++){
        if (vector [j]<menor){
            menor= vector [j];
            columnaMenor=j;
        }
    }
 return columnaMenor;
}

//funcion 9 
int cantidadContenedoresClase (string tipoArticulo [fila][col]){
    int contador=0;
    string respuesta="";
    cout<<"Ingrese el tipo de Articulo, del cual quiere saber la cantidad de contenedores"<<endl;
    cin>>respuesta;
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (tipoArticulo [i][j]==respuesta){
                contador=contador+1;
                
           }
        }
    }
 return contador;
}

//funcion 10
float promedioCargaPuerto (string puertoCarga [fila][col],int peso [fila][col]){
    int acumulador=0;
    int contador=0;
    string respuestaPuerto="";
    int promedio=0;
    cout<<"Ingrese el puerto, del cual quiere saber el promedio de carga embarcada"<<endl;
    cin>>respuestaPuerto;
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (respuestaPuerto==puertoCarga [i][j]){
            acumulador=acumulador+ peso [i][j];
            contador=contador+1;
        }
    }
    }
    promedio=acumulador/contador;
    return promedio;
}


//funcion 11
string nombreEmpresaMayorContenedor (string marca [fila][col], int peso [fila][col]){
    string Pesadoempresa="";
    int mayor=INT_MIN;
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (peso [i][j]>mayor){
                mayor= peso[i][j];
                Pesadoempresa= marca [i][j];
            }
        }
    }
    return Pesadoempresa;
}

//funcion 12
int ContenedorLiviano (int peso [fila][col]){
    int menorPeso=INT_MAX;
    string livianoEmpresa="";
    for (int i=0; i<fila;i++){
        for (int j=0; j<col;j++){
            if (peso [i][j]<menorPeso && peso [i][j]!=0){
                menorPeso=peso [i][j];
                
            }
        }
    }
    return menorPeso;
}




