#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>


// todo ***************************ESTRUCTURAS******************************************
typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    char idioma[10];
    int stock;
} estructura_teclado;
estructura_teclado teclado[20]; //  DEFINIMOS TECLADOS 

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int stock;
} estructura_mouse;
estructura_mouse mouse[20]; // DEFINIMOS MOUSE

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    float pulgadas; //! PULGADAS > 7
    int stock;
} estructura_monitor;
estructura_monitor monitor[20]; // DEFINIMOS MONITOR

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int ram; //! RAM SIEMPRE POTENCIA DE 2
    char procesador;
    float pulgadas; //! PULGADAS > 11
    int stock;
} estructura_notebook;
estructura_notebook note[20]; // DEFINIMOS NOTEBOOK

typedef struct
{
    int id;
    char marca[15];
    char modelo[10];
    int ram; //! RAM SIEMPRE POTENCIA DE 2
    char procesador;
    
    estructura_teclado pc_teclado;
    estructura_mouse pc_mouse;
    estructura_monitor pc_monitor;
    int stock;
} estructura_pc;
estructura_pc pc[20]; // DEFINIMOS TORRE/PC


typedef struct
{
    int id;
    char nombreuser[11];
    char nombres[25];
    char apellidom[10];
    char apellidop[10];
    char contrasena[5];
} usuario;
usuario user;

// todo ********************************************************************************

void llenar_user();
void llenar_datos_struct();
void mostrar_user();
int login();

void opciones(); //* MENU AGREGAR PROD 
int sub_op(); //* SUB MENU TIPO PROD Y SEGUN TIPO DE PROD, SE PIDEN DATOS ESPECIFICOS

//todo ************************************ MAIN ****************************************
int main(int argc, char const *argv[])
{
    int bandera = 1, i;
    system("title login inventario");
    llenar_user();
    llenar_datos_struct();
    do
    {
        bandera = login();
    }while(bandera == 1);

    system("cls");
    printf("Cargando...\n");
    for (i = 0; i <= 100; i++)
    {
        printf("\r%d%%", i);
        usleep(100000); //! manda warning pero solo en visual estudio en devc del profe todo oki
    }
    system("title vegeta 777");
    system("cls");
    printf("se a entrada a la matrix\n");
    printf(" .----------------.  .----------------.  .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. |\n");
    printf("| |  ________    | || |    ___       | || | ____    ____ | |\n");
    printf("| | |_   ___ `.  | || |  .' _ '.     | || ||_   \\  /   _|| |\n");
    printf("| |   | |   `. \\ | || |  | (_) '___  | || |  |   \\/   |  | |\n");
    printf("| |   | |    | | | || |  .`___'/ _/  | || |  | |\\  /| |  | |\n");
    printf("| |  _| |___.' / | || | | (___)  \\_  | || | _| |_\\/_| |_ | |\n");
    printf("| | |________.'  | || | `._____.\\__| | || ||_____||_____|| |\n");
    printf("| |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'\n");
    printf("D&M productions presentan:\n");
    printf("  _                      _             _       \n");
    printf(" (_)                    | |           (_)      \n");
    printf("  _ _ ____   _____ _ __ | |_ __ _ _ __ _  ___  \n");
    printf(" | | '_ \\ \\ / / _ \\ '_ \\| __/ _` | '__| |/ _ \\ \n");
    printf(" | | | | \\ V /  __/ | | | || (_| | |  | | (_) |\n");
    printf(" |_|_| |_|\\_/ \\___|_| |_|\\__\\__,_|_|  |_|\\___/ \n");
    system("pause");
    system("cls");

    opciones();
    system("pause");
    return 0;
}
// todo ********************************************************************************

int login() // NUEVO LOGIN MODIFICADO
{

    char contra[5];
    char usuario[6];
    int bandera = 1, i = -1, cont = 0, banderauser=1; // todo bandera vale menos 1 porque es un do while que suma 1 al i al inicio y para que i valga 0 al
    // todo empezar
    char bande; // todo bandera de character que sirve para que meta el enter

    system("cls");
    printf("Ingrese su nombre de usuario\n");
    scanf("%s",usuario);
    fflush(stdin);

    // todo aqui ahora es un do while que lee hasta 5 characteres o termina si uno es enter
    printf("Ingrese su contrasena\n");
    do
    {
        i = i + 1;
        contra[i] = _getch();
        printf("*");

    } while (i <= 3 && contra[i] != 13);
	
	// todo aqui si ingreso 5 characteres debe ingresar un enter para mandarlos , si ingreso 3 seria que ya metio un enter,
	// todo y no se mete aqui
	
    if (contra[i]!= 13)
    {
        do
        {
            bande = _getch();
        } while (bande != 13 );
    }
    
    // ! verificacion del usuario
    // todo aqui leeo el usuario con gets, pregunto si es igual al de la base de dato"""
    // todo si es igual pasa a la contrasena sino returna 1 y printea que reingrese los datos
    banderauser = strncmp(usuario,user.nombreuser,6);
    if (banderauser != 0)
    {
        system("cls");
        printf("datos incorrectos, reingrese los datos nuevamente\n");
        system("pause");
        return 1;
    }

    for (i = 0; contra[i] != '\0'; i++)
    {
        if (contra[i] == user.contrasena[i])
        {
            cont = cont + 1;
            if (cont == 5)
            {
                return 0;
            }
        }
        else
        {
            system("cls");
            printf("datos incorrectos, reingrese los datos nuevamente\n");
            system("pause");
            return 1;
        }
    }
}


void opciones(){

    // ! dime si las opciones estan bien 
    //Debe poder agregar un producto, actualizar un producto, listar los productos y eliminar un
//producto (CRUD).
//• Debe poder realizar una búsqueda por la marca del producto.
//• Debe contar con un menú para poder realizar las operaciones mencionadas.
//• Debe indicar la cantidad de existencias de cada producto.
    int opcion;
    do{
        printf("Ingrese su opcion\n");
        printf("1 agregar un producto\n");
        printf("2 actualizar un producto\n");
        printf("3 listar un tipo de productos\n");
        printf("4 eliminar un producto\n");
        printf("5 buscar un producto por su marca\n");// de forma recursiva
        printf("6 cerrar progama\n");
        opcion = _getch(); //! ME DETECTA EL 1 COMO 49 Y [DEMAS NUMEROS COMO N + 48] NOSE PORQUE

        
        // ! al entrar en el case llamamos una funcion 
        // ! sabemos siempre habra 3 minimo comentame cual es tu idea para  para saber en que posisicion vamos del
        // ! ejemplo teclado[i].marca como sabemos el i si esque elimino alguno o nose comentame tu idea
        
        switch(opcion){

            case 1:
                do
                {
                    opcion = sub_op();
                    if(opcion > 5 || opcion < 1)system("cls");
                }while(opcion > 5 || opcion < 1);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            default:
                printf("ERROR OPCION INVALIDA, REINGRESE DATO\n");
                break;

        }

    }while(opcion !=6);

}


int sub_op()//!FUNCION INCOMPLETA DE AGREGAR PRODUCTO
{
    int i, bandera = 0, op;

    system("cls");
    printf("Ingrese tipo de producto a agregar:\n");
    printf("1 Teclado\n");
    printf("2 Mouse\n");
    printf("3 Monitor\n");
    printf("4 Notebook\n");
    printf("5 PC de escritorio\n");
    op = _getch();
    fflush(stdin);

    for(i = 0; i < 20; i++)
    {
        switch(op)
        {
            case 1: //*TECLADO
                if(teclado[i].stock == 0)
                {
                    teclado[i].stock = 1;
                    printf("Ingrese la marca\n ");
                    gets(teclado[i].marca);
                    fflush(stdin);

                    printf("Ingrese el modelo\n");
                    gets(teclado[i].modelo);
                    fflush(stdin);

                    bandera = 1;
                }
                
                break;
            case 2: //*MOUSE
                if(mouse[i].stock == 0)
                {
                    printf("Ingrese la marca\n ");
                    gets(mouse[i].marca);
                    fflush(stdin);

                    printf("Ingrese el modelo\n");
                    gets(mouse[i].modelo);
                    fflush(stdin);

                    mouse[i].stock = 1;
                    bandera = 1;
                }
                
                break;
            case 3: //*MONITOR
                if(monitor[i].stock == 0)
                {
                    printf("Ingrese la marca\n ");
                    gets(monitor[i].marca);
                    fflush(stdin);

                    printf("Ingrese el modelo\n");
                    gets(monitor[i].modelo);
                    fflush(stdin);

                    monitor[i].stock = 1;
                    bandera = 1;
                }
                
                break;
            case 4: //*NOTEBOOK
                if(note[i].stock == 0)
                {
                    printf("Ingrese la marca\n ");
                    gets(note[i].marca);
                    fflush(stdin);

                    printf("Ingrese el modelo\n");
                    gets(note[i].modelo);
                    fflush(stdin);

                    note[i].stock = 1;
                    bandera = 1;
                }
                
                break;
            case 5: //*PC ESCRITORIO
                if(pc[i].stock == 0)
                {
                    printf("Ingrese la marca\n ");
                    gets(pc[i].marca);
                    fflush(stdin);
                    printf("Ingrese el modelo\n");
                    gets(pc[i].modelo);
                    fflush(stdin);
                    pc[i].stock = 1;
                    bandera = 1;
                }
                
                break;
            default:
                printf("ERROR OPCION INVALIDA, REINGRESE DATO\n");
                system("pause");
                bandera = 1;
                break;
        }

        if( bandera == 1)break;//*BREAK PARA SALIR DEL FOR UNA VEZ HECHO EL LLENADO
    }
    return op;//*DEVUELVO LA OPCION ESCOGIDA PARA REPETIR PROCESO O NO
}

void lista_produc();//! DE QUE FORMA MOSTRAMOS LA LISTA DE PRODUCTOS?

void llenar_datos_struct(){
    int i;
    for(i=0; i<20; i++){

        if(i==0 || i== 1 || i==2 ){ // * CONDICION PARA LLENAR STOCK SOLO LOS 3 PRIMEROS PRODUCTOS

            teclado[i].stock=1;
            mouse[i].stock=1;
            monitor[i].stock=1;
            note[i].stock=1;
            pc[i].stock=1;
        }else{ // * LLENA LOS OTROS STOCK COMO 0
            teclado[i].stock=0;
            mouse[i].stock=0;
            monitor[i].stock=0;
            note[i].stock=0;
            pc[i].stock=0;
        }
    }

// * en esta misma funcion llenar los 3 primeros datos tambiens agregar despues
// ? ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
}
void llenar_user()
{
    user.id = 777;
    strcpy(user.nombres, "juanito alcachofa");
    strcpy(user.apellidom, "aguilera");
    strcpy(user.apellidop, "arenas");
    strcpy(user.nombreuser, "vegeta");
    strcpy(user.contrasena, "12345");
}
void mostrar_user()
{
    printf("El nombre de usuario es %s\ny su contrasena es: %s\n", user.nombreuser, user.contrasena);
    printf("sus nombres son %s \n", user.nombres);
    printf("sus apellidos son %s %s\n", user.apellidop, user.apellidom);
    printf("y su id es %d\n", user.id);
}

