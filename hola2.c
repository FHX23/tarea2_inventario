#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

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

void llenar_user();
void mostrar_user();
int login();

int main(int argc, char const *argv[])
{
    int bandera = 1, i; // MODIFICADO EL BANDERA = 1
    system("title login inventario");
    llenar_user();
    // mostrar_user();
    // system("pause");
    do
    {
        // ! quite los printf de aqui y los meti adentro de la funcion aunque son como mas generales yaque si falla contra o user 
       // if (bandera == 1)
        //    printf("Ingrese Contrasena del usuario\n"); // MODIFICADO //! creo aqui esta demas el if si es un do while,creoo
        bandera = login();
        //system("cls");

        //if (bandera == 1)
           // printf("Contrasena incorrecta reingrese:\n"); // MODIFICADO

    } while (bandera == 1);

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

    system("pause");
    return 0;
}

int login() // NUEVO LOGIN MODIFICADO
{

    char contra[5];
    char usuario[6];
    int bandera = 1, i = -1, cont = 0, banderauser=1; // todo bandera vale menos 1 porque es un do while que suma 1 al i al inicio y para que i valga 0 al
    // todo empezar
    char bande; // todo bandera de character que sirve para que meta el enter
    /*for (i = 0; i < 5; i++)
    {
        contra[i] = _getch();
        if( contra[i] == 13)break;
        printf("*");
    }
    */
    system("cls");
    printf("Ingrese su nombre de usuario\n");
    gets(usuario);
    fflush(stdin);
    
    //? leemos el usuario noma y luego la contra  y luego verificamos si una de las 2 fallo
    /*banderauser=strncmp(usuario,user.nombreuser,6);
        if (banderauser!=0)
        {
            system("cls");
            printf("usuario incorrecto reingrese los datos nuevamente\n");
            return 1;
        }
    */
    

    // todo aqui ahora es un do while que lee hasta 5 characteres o termina si uno es enter
    printf("Ingrese su contrasena\n");
    do
    {
        i = i + 1;
        contra[i] = _getch();
        printf("*");
        	//printf("valor de i %d\n",i);
    } while (contra[i] != 13);//condicion de i<=3 no es necesario o si?
	//printf("salio del bucle\n");
	// todo aqui si ingreso 5 characteres debe ingresar un enter para mandarlos , si ingreso 3 seria que ya metio un enter,
	// todo y no se mete aqui
	
	/*
    if (contra[i]!= 13)
    {
        do
        {
            bande = _getch();
        } while (bande != 13 );
    }
    */
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

    // todo aqui sigue igual
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

/*int login()
{

    char contra, retry;
    int i, j, bandera;
    bandera = 1;
    for (i = 0; i < 5; i++)
    {
        contra = _getch();
        if (contra == user.contrasena[i])
        {
            bandera = 0;
            system("cls");
            for (j = 0; j < i + 1; j++)
            {
                printf("*");
            }
        }
        else
        {
            system("cls");
            bandera = 1;
            printf("Error contrasena incorrecta\n");
            printf("Ingrese tecla para reintentar\n");
            retry = _getch();
            system("cls");
            break;
        }
    }
    return bandera;
}
*/

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