#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
//Control para que solo puedan añadirse hasta 10 clientes y almacenamos hasta 10 operaciones
#define MAX_CLIENTES 10
#define MAX_OPERACIONES 10

//Control de máximo de caracteres en campo char
#define MAX_NOMBRE 50
#define MAX_DIRECCION 255
#define MAX_CAMPOS

using namespace std;

// Cliente Typedef
typedef struct{
    int idcliente;
    int edad;
    int numcuenta;
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
}cliente;

/*
 * @brief Estructura para formato fecha
 */
typedef struct{
  size_t dia;
  size_t mes;
  int anio;
}fecha;

/*
 * @brief Estructura de datos para operaciones de cliente
 */
typedef struct{
    int idoperacion;
    char tipo;
    fecha fechaoperacion;
}operacion;


/*
 *  @brief Prototipamos el array de clientes
 *  @param arrayCliente Array de clientes
 */
void initCartera(cliente carteraClientes[]);

/*
 * @brief Prototipado de la función de adicion de cliente
 * @param ArrayCliente Array de clientes
 * @param numeroClientes número de clientes almacenados en el array
 * @return true si se crea correctamente
 */
bool createCartera(cliente carteraClientes[],int numeroClientes);


/*
 *  @brief Prototipamos el array de Operaciones
 *  @paramc operacionesCliente Array de operaciones
 */
void initOperaciones(operacion operacionesCliente[]);

/*
 * @brief Prototipado de la función de adicion de operación
 * @param ArrayCliente Array de Operaciones por cliente
 * @param
 * @return true si se crea correctamente
 */
bool createOperaciones(operacion operacionesCliente[],int numeroClientes);


// Inicializamos el disponible a 100 para hacer pruebas.
int disponible = 100;

//inicializamos el número de clientes en 0
size_t numeroClientes=0;

/*OTRA FORMA DE CONTAR EL NUMERO DE CLIENTES DEL ARRAY
*Devuelve el número de elementos del Array Clientes
int getLength(cliente array[]);*/

//Prototipamos la función de imprimir el menú de preselección
size_t imprimirPreseleccion();

//Prototipamos la función de imprimir menú de las Cuentas
size_t imprimirMenuCuentas();










int main() {
    //Variable que recogerá el input del usuario para el Menú de Preselección
    size_t sel;

    //Variable que recogerá el input del usuario
    size_t opt;

    //Variables donde almacenamos los datos del cliente actual
    size_t optDato;
    size_t idCliente;
    size_t numeroCuenta;

    /*
     * @brief Inicializamos la cartera de clientes
     */
    cliente carteraClientes[MAX_CLIENTES];
    initCartera(carteraClientes);

    /* PENDIENTE FINALIZAR
     * @brief Inicializamos la cartera de clientes
     */
    //operacion carteraClientes[MAX_OPERACIONES];
    //initCartera(operacionesCliente);


    // Bucle de preselección de usuario
    do {
        sel = imprimirPreseleccion();

        //Lanzamos las acciones por casos
        switch (sel) {

            //Si el usuario escoge la opción 1: Gestionar Clientes se le permite crear cliente si no hay más de 10
            case 1: {
                if (createCartera(carteraClientes,numeroClientes)){
                    cout<<"Cliente creado correctamente"<<endl;
                    numeroClientes++;
                    sel=0;

                } else {
                    cout << "No se pudo crear el cliente." << endl;
                }
            }
            break;

            case 2: {


                do {
                    opt = imprimirMenuCuentas();

                    //Estructura de control para lanzar la opción elegida por el usuario
                    switch (opt) {
                        case 1: {
                            // Declaramos variable importeIngreso Debe ser un número entero (no se aceptan ingresos decimales)
                            int importeIngreso;

                            //Solicitamos importe a ingresar por el cliente
                            cout << "Introduzca el importe a ingresar:" << endl;
                            cin >> importeIngreso;

                            if (importeIngreso > 0) {
                                //Efectuamos el ingreso y actualizamos el disponible
                                disponible = disponible + importeIngreso;

                                //Imprimimos Resultado de la operación
                                cout << "Se han ingresado en su cuenta:";
                                cout << importeIngreso;
                                cout << " EUR" << endl;
                                cout << "Su saldo disponible es de:";
                                cout << disponible;
                                cout << " EUR" << endl;

                            } else {
                                cout << "No puede ingresar un importe negativo. Operación cancelada." << endl;
                                cout<<"Volviendo al menu principal"<<endl<<endl;
                            }

                        }
                            break;

                        case 2: {
                            //Declaramos variable importeRetirada. Debe ser un número entero (no se aceptan ingresos decimales)
                            int importeRetirada;

                            //Solicitamos importe a ingresar por el cliente
                            cout << "Introduzca el importe a retirar:" << endl;
                            cin >> importeRetirada;

                            if (importeRetirada>0){
                                if (importeRetirada <= disponible) {
                                    //Efectuamos el ingreso y actualizamos el disponible
                                    disponible = disponible - importeRetirada;

                                    //Imprimimos Resultado de la operación
                                    cout << "Se han retirado de su cuenta:";
                                    cout << importeRetirada;
                                    cout << " EUR" << endl;
                                    cout << "Su saldo disponible es de:";
                                    cout << disponible;
                                    cout << " EUR" << endl;
                                    //Imprimimos resultado de operación
                                } else {
                                    cout << "Su saldo es de:" << disponible << " EUR" << endl;
                                    cout << "No puede retirar el importe solicitado."<<endl<<"Intente de nuevo.";
                                    cout<<"Volviendo al menu principal"<<endl<<endl;

                                }
                            } else {
                                cout<<"Debe introducir un importe positivo."<<endl;
                                cout<<"Volviendo al menu principal"<<endl<<endl;
                            }

                        }
                            break;

                        default: {
                            cout << "Saliendo" << endl;
                        }
                    }
                }while(opt==1||opt==2);

            }
            break;

            default: {
                cout << "Saliendo" << endl;
            }
        }

    }
    while(sel==1||sel==2||sel==0);

    return 0;
}


/*
*  IMPLEMENTACIÓN DE FUNCIONES ADICIONALES *
*/

size_t identificadorCliente(int optDato){

    do {
        optDato = imprimirMenuCuentas();

        switch (optDato) {
            case 1: {

            }
                break;

            case 2: {

            }
                break;

            default: {
                cout << "Saliendo" << endl;
            }
        }
    }while(optDato==1||optDato==2);
}

size_t tipoDatoCliente(){
    size_t tipodato;
    cout << "Confirme qué dato desea introducir:" << endl;
    cout << "1 para introducir el identificador de cliente" << endl;
    cout << "2 Para introducir el número de cuenta." << endl;
    cin>> tipodato;
    return tipodato;
}

size_t seleccionarCuenta(){
    size_t cuenta;
    cout << "Introduzca el número de cuenta:" << endl;
    cin>> cuenta;
    return cuenta;
}

size_t seleccionarCliente(){
    size_t cliente;
    cout << "Introduzca el número de cliente:" << endl;
    cin>> cliente;
    return cliente;
}



//función modularizada de impresión del menú de Gestión de Cuentas
size_t imprimirMenuCuentas (){

    //Declaramos la variable input para captar el input del usuario
    size_t input;

    //Imprimimos el menú al usuario
    cout << "ESCOJA LA OPERACION QUE DESEA REALIZAR:" << endl;
    cout << "1. Ingreso de efectivo" << endl;
    cout << "2. Retirada de efectivo" << endl;
    cout << "0. Volver al menú inicial"<<endl;
    cin >> input;

    //devolvemos un valor size_t para ser usado en main
    return input;
}

//función modularizada de impresión del menú de Preselección
size_t imprimirPreseleccion (){

    //Declaramos la variable input para captar el input del usuario
    size_t input;

    //Imprimimos el menú al usuario
    cout << "ESCOJA EL TIPO DE OPERACION:" << endl;
    cout << "1. Gestionar Clientes" << endl;
    cout << "2. Gestionar Cuentas" << endl;
    cout << "0. Salir"<<endl;
    cin >> input;

    //devolvemos un valor size_t para ser usado en main
    return input;
}

/*
 * @brief El cliente debe contener nombre, dirección, número de cuenta, edad e id de cliente
 * @return Array de 10 clientes
 */

void initCartera(cliente carteraClientes[]){
    for (size_t i=0;i<MAX_CLIENTES;i++){
        strcpy(carteraClientes[i].nombre,"");
        carteraClientes[i].idcliente=0;
        strcpy(carteraClientes[i].direccion,"");
        carteraClientes[i].edad=0;
        carteraClientes[i].numcuenta=0;
    }
}


/*
 * @brief inicializa un array de 10 operaciones para cada cliente
 * @return array de 10 operaciones
 */

void initOperaciones(operacion operacionesCliente[]){
    for (size_t i=0;i<MAX_CLIENTES;i++){
        for (size_t n=0;n<MAX_OPERACIONES;n++){
            operacionesCliente[i].idoperacion=0;
            strcpy(operacionesCliente[i].tipo,"");
            operacionesCliente[i].fecha.dia=00;
            operacionesCliente[i].fecha.mes=00;
            operacionesCliente[i].fecha.anio=0000;
        }
    }
}


/*
 * @brief
 * @params
 * @return array de clientes
 */
bool createCartera(cliente carteraClientes[],int numeroClientes){
    if(numeroClientes>MAX_CLIENTES-1){
        return false;
    } else {
        //Solicita nombre e idCliente, edad, direccion y númeroCuenta
        do{
            cout<<"Introduzca el nombre del cliente sin espacios:"<<endl;
            cin.getline(carteraClientes[numeroClientes].nombre,MAX_NOMBRE);
        }while(!strcmp(carteraClientes[numeroClientes].nombre,""));

        cout<<"Introduzca el número de cliente"<<endl;
        cin>>carteraClientes[numeroClientes].idcliente;

        /*do{
            cout<<"Introduzca el número de cliente"<<endl;
            cin>>carteraClientes[numeroClientes].idcliente;
        }while(carteraClientes[numeroClientes].idcliente);*/

        //Campos opcionales
        cout<<"Introduzca la edad del cliente:"<<endl;
        cin>>carteraClientes[numeroClientes].edad;

        cout<<"Introduzca la direccion:"<<endl;
        cin.getline(carteraClientes[numeroClientes].direccion,MAX_DIRECCION);

        cout<<"Introduzca el número de cuenta:"<<endl;
        cin>>carteraClientes[numeroClientes].numcuenta;

        return true;
    }
}
