#include <stdio.h>
#include <stdlib.h>
#include "abmCliente.h"
#include "abmPublicaciones.h"
#include "informes.h"
#include "getsValids.h"
#define CANTIDADCLIENTES 100
#define CANTIDADAVISOS 1000

int main()
{
    int menu,idCliente, idPublicacion;
    Cliente clientes[CANTIDADCLIENTES];
    Publicacion publicaciones[CANTIDADAVISOS];
    abmCliente_init(clientes, CANTIDADCLIENTES);
    abmPublicacion_init(publicaciones, CANTIDADAVISOS);

   do
    {
       get_validInt("\nMENU\n\n1:Alta Cliente\n2:Modificar Cliente\n3:Baja cliente\n4:Publicar aviso\n5:Pausear Aviso\n6:Reanudar aviso\n7:Imprimir Clientes\n8:Imprimir publicaciones\n9:Informe Clientes\n10:Informe Publicaciones\n\n0:Salir\n","Ingrese una opcion correcta",&menu,0,10,2);
       fflush(stdin);

        switch(menu)
        {

        case 1:
            abmCliente_alta(clientes, CANTIDADCLIENTES);
            break;
        case 2:
            get_validInt("Ingrese el ID del cliente: ","Solo numeros", &idCliente, 0, CANTIDADCLIENTES, 3);
            fflush(stdin);
            abmCliente_mostrar(clientes, idCliente);
            abmCliente_modificacion(clientes, CANTIDADCLIENTES, idCliente);
            abmCliente_mostrar(clientes, idCliente);
            break;
        case 3:
            get_validInt("Ingrese un ID: ","Solo numeros", &idCliente, 0, CANTIDADCLIENTES, 3);
            fflush(stdin);
            abmCliente_baja(clientes, CANTIDADCLIENTES, idCliente);
            abmPublicacion_baja(publicaciones, CANTIDADAVISOS, idCliente);

            break;
        case 4:
            abmPublicacion_alta(publicaciones,CANTIDADAVISOS);
            break;
        case 5:
            get_validInt("Ingrese el ID de la publicacion: ","Solo numeros", &idPublicacion, 0, CANTIDADAVISOS, 3);
            fflush(stdin);
            abmPublicacion_Pausar(publicaciones, CANTIDADAVISOS, idPublicacion);

            break;
        case 6:
            get_validInt("Ingrese el ID de la publicacion: ","Solo numeros", &idPublicacion, 0, CANTIDADAVISOS, 3);
            fflush(stdin);
            abmPublicacion_Reanudar(publicaciones, CANTIDADAVISOS,idPublicacion);
            break;
        case 7:
            informes_mostrarClientes(clientes,publicaciones,CANTIDADCLIENTES,CANTIDADAVISOS);
            break;
        case 8:
            informes_mostrarPublicacion(clientes, publicaciones, CANTIDADAVISOS,CANTIDADCLIENTES);
            break;
        case 9:
            informes_ClienteMaxPub(publicaciones, clientes,CANTIDADAVISOS, CANTIDADCLIENTES);
            break;
        case 10:
            informes_publicacionesPorRubro(publicaciones,CANTIDADAVISOS);
            break;
            }



    }while(menu !=0);

        return 0;
    }
