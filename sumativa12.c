#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct contacto {
   char nombre[25];
   char numero[25];
   char correo[50];
} contacto;
 
 //Inicia main 
int main(){

         printf("\n\t\t   Evaluacion  Sumativa #12 (Gestor de Contactos)\n");

        contacto * persona, *buscar;
        persona = (contacto*) malloc(10 * sizeof(contacto));
        buscar = (contacto*) malloc(10 * sizeof(contacto));

         int opcion = 0, num=1, elim;
         int posicion, x, pos, i;
         char palabra[18];
        

//inicio del menu. 
while (opcion != 6) {
    printf("\n   \t               -------MENU-------");
    printf("\n   \t  1. Añadir un nuevo Contacto");
    printf("\n   \t  2. Lista de Contactos");
    printf("\n   \t  3. Modificar Contacto");
    printf("\n   \t  4. Eliminar Contacto");
    printf("\n   \t  5. Buscar Contacto ");
    printf("\n   \t  6. Salir");
    printf("\n   \t --> Eliga una Opcion : ");
    scanf("%d", &opcion);
     


    switch(opcion)
    {
        case 1: 
            for (x = num-1; x < num; x++) { /* num vale 1 y x vale 0, x es menor que num asique se le suma 1 a x 
                                            y x vale ahora 1, ahora x vale lo mismo que num por lo que se cancela el ciclo */
                printf("\n         Introduzca la informacion del contacto %d \n",num);
                printf("\n       Nombre: ");
                scanf("%s", persona[x].nombre);
                strcpy(buscar[x].nombre, persona[x].nombre);

                printf("       Numero: ");
                scanf("%s", persona[x].numero);
                strcpy(buscar[x].numero, persona[x].numero);

                printf("       Correo: ");
                scanf("%s", persona[x].correo);
                strcpy(buscar[x].numero, persona[x].correo);


            }
                num=num+1; /*como el ciclo ya se cerro, se le incrementa el valor a num ahora num vale 2 y x vale 1 
                            al entrar nuevamente al ciclo se repetira el mismo paso anterior. */
        
        printf("\n         Su Contacto ha sido guardado con exito \n");

         break; 

        case 2: 
            printf("\n\n                                  Lista de Contactos ");
            printf("\n\n\t\t     Nombre\t\tTelefono\t\tCorreo ");
            pos=1;
            for (x = 0; x < num-1; x++){ //bucle para recorrer la lista
                printf("\n\t Contacto %i: %s\t\t%s\t\t%s", pos, persona[x].nombre, persona[x].numero, persona[x].correo); //imprime lista de nombres
                pos++;
            }
            printf("\n");

        break;

        case 3:
            printf("\n\n         Lista de Contactos \n"); 
            pos=1; //se inicia en 1 para que no contenga los valores de bucles anteriores.
                for (x = 0; x < num-1; x++) {  //bucle 
                printf("         Contacto %i: %s \n", pos, persona[x].nombre); //imprime la lista de contacto 
                pos++;
            }
            printf("\n         Seleccione el contacto a editar: ");
            scanf("%d", &posicion);
            posicion=posicion-1; //esto es para cuando presione al contacto 1 le indique al contacto 0 y asi se vea estetico.
            printf("\n         Nombre: "); 
                scanf("%s", persona[posicion].nombre);
                strcpy(buscar[posicion].nombre, persona[posicion].nombre);

                printf("        Numero: "); 
                scanf("%s", persona[posicion].numero);
                strcpy(buscar[posicion].numero, persona[posicion].numero);

                printf("        Correo: ");
                scanf("%s", persona[posicion].correo);
                strcpy(buscar[posicion].correo, persona[posicion].correo);
        break;

        case 4:
        printf("\n\n            Lista de contactos \n"); 
            pos=1; 
                for (x = 0; x < num-1; x++) {  //bucle para recorrer la lista
                printf("\n         Contacto %i: %s ", pos, persona[x].nombre); //imprime la lista
                pos++; 
            }
            printf("\n\n         Eliminar contacto: ");
            scanf("%d", &posicion);
            posicion=posicion-1; //le eliminamos 1 para que le indique al contacto 0 presionar el 1.
            elim=num;   //elim adquiere el valor de num para no dañar el ciclo y para que num mantenga su valor orginal. 
            elim++; //elim se incrementa para que obtenga un espacio vacio o que no exista.
            persona[posicion]=persona[elim]; 
            buscar[posicion]=persona[elim];
        break;

        case 5:
            pos=1;
            printf("    Introduzca el nombre para buscar: \n");
            printf("    Nombre: ");
            scanf("%s",palabra);
            printf("  Contactos Similares\n");
            printf("\n\n\t\t     Nombre\t\t   Telefono\t\t   Correo ");
            for (x = 0; x < num-1; x++){    
                for ( i = 0;  i < strlen(buscar[x].nombre) ; i++) { //bucle para recorrer la lista e igualar todos los nombres.
                    buscar[x].nombre[i] = toupper(buscar[x].nombre[i]); //toupper pondra en mayuscula todos los nombres para igualarlos
                }
                for ( i = 0;  i < strlen(palabra) ; i++) { //bucle para recorrer la lista de contactos.
                    palabra[i] = toupper(palabra[i]);   //toupper pondra en mayuscula todos los nombres para igualarlos.
                }
            }
            
    }

} // termina menu
    free(persona);
    free(buscar);

    return 0;
}