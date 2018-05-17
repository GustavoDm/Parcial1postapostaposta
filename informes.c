#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abmPublicaciones.h"
#include "abmCliente.h"
#include "getsValids.h"

int informes_mostrarClientes(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizeCliente, int sizePublicacion)
{
    int retorno = -1;
    int i;
    if((sizeCliente> 0 && arrayCliente != NULL)&& (sizePublicacion> 0 && arrayPublicacion!=NULL))
    {
        retorno = 0;
        for(i=0;i<sizeCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %s\n",arrayCliente[i].idCliente, arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].cuil);

        }
    }
    return retorno;
}


int informes_mostrarPublicacion(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizePublicacion, int sizeCliente)
{
    int retorno = -1;
    int i;
    int indiceCliente;

    if(sizePublicacion > 0 && arrayPublicacion != NULL && arrayCliente != NULL && sizeCliente > 0)
    {
        retorno = 0;
        for(i=0;i<sizePublicacion;i++)
        {
            indiceCliente=abmCliente_buscarPorId(arrayCliente,sizeCliente,arrayPublicacion[i].idCliente);
            if(!arrayPublicacion[i].isEmpty && arrayPublicacion[i].estado)
            {
                printf("\nCUITCLIENTE: %s",arrayCliente[indiceCliente].cuil);
                printf("\nRUBRO: %d", arrayPublicacion[i].rubro);
                printf("\nAVISO: %s",arrayPublicacion[i].texto);
                printf("\nIDAVISO: %d",arrayPublicacion[i].idAviso);
                printf("\nESTADO: %d", arrayPublicacion[i].estado);
                printf("\n----------------------");
            }
        }
    }
    return retorno;
}

int informes_PublicacionesTotales(Publicacion *arrayPublicacion,int sizePublicacion,int idCliente)
{
    int i;
    int acumuladorPublicaciones=0;
    if(sizePublicacion > 0 && arrayPublicacion != NULL)
    {
        for(i=0;i<sizePublicacion;i++)
        {
            if(!arrayPublicacion[i].isEmpty)
            {
                if(arrayPublicacion[i].idCliente == idCliente)
                {
                       acumuladorPublicaciones++;
                }
            }

        }
    }
    return acumuladorPublicaciones;
}

int informes_PublicacionesActivas(Publicacion *arrayPublicacion,int sizePublicacion,int idCliente)
{
    int i;
    int acumuladorPublicaciones=0;
    if(sizePublicacion > 0 && arrayPublicacion != NULL)
    {
        for(i=0;i<sizePublicacion;i++)
        {
            if(!arrayPublicacion[i].isEmpty)
            {
                if(arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].estado)
                {
                       acumuladorPublicaciones++;
                }
            }

        }
    }
    return acumuladorPublicaciones;
}

int informes_PublicacionesPausadas(Publicacion *arrayPublicacion,int sizePublicacion,int idCliente)
{
    int i;
    int acumuladorPublicaciones=0;
    if(sizePublicacion > 0 && arrayPublicacion != NULL)
    {
        for(i=0;i<sizePublicacion;i++)
        {
            if(!arrayPublicacion[i].isEmpty)
            {
                if(arrayPublicacion[i].idCliente == idCliente && !arrayPublicacion[i].estado)
                {
                       acumuladorPublicaciones++;
                }
            }

        }
    }
    return acumuladorPublicaciones;
}

int informes_ClienteMaxPub(Publicacion *arrayPublicacion, Cliente *arrayCliente, int sizePublicacion, int sizeCliente)
{

    int retorno=-1;
    int i;
    int nohaydatos=1;
    int maxAvisosActivos;
    int maxAvisosPausados;
    int maxAvisosTotal;
    int idClienteMasActivos;
    int idClienteMasPausados;
    int idClienteMasAvisos;
    int flagMaxPausados=1;
    int flagMaxActivos=1;
    int flagMaxTotal=1;

    if((sizePublicacion > 0 && arrayPublicacion != NULL)&&(sizeCliente > 0 && arrayCliente != NULL))
    {
        for(i=0;i<sizePublicacion;i++)
        {

            if((!arrayPublicacion[i].isEmpty) && (!arrayCliente[i].isEmpty))
            {
                if(maxAvisosActivos<informes_PublicacionesActivas(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente) || flagMaxActivos)
                {
                    maxAvisosActivos = informes_PublicacionesActivas(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente);
                    idClienteMasActivos=abmCliente_buscarPorId(arrayCliente,sizeCliente,arrayPublicacion[i].idCliente);
                    flagMaxActivos=0;
                }

                if(maxAvisosPausados<informes_PublicacionesPausadas(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente)|| flagMaxPausados)
                {
                    maxAvisosPausados = informes_PublicacionesPausadas(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente);
                    idClienteMasPausados=abmCliente_buscarPorId(arrayCliente,sizeCliente,arrayPublicacion[i].idCliente);
                    flagMaxPausados=0;
                }

                if(maxAvisosTotal<informes_PublicacionesTotales(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente)|| flagMaxTotal)
                {
                    maxAvisosTotal = informes_PublicacionesTotales(arrayPublicacion, sizePublicacion, arrayPublicacion[i].idCliente);
                    idClienteMasAvisos=abmCliente_buscarPorId(arrayCliente,sizeCliente,arrayPublicacion[i].idCliente);
                    flagMaxTotal=0;
                }
                retorno=0;
                nohaydatos=0;

            }

        }
        if(!nohaydatos)
            {
            printf("\n(A)El cliente con mas avisos activos es:\nNombre: %s Apellido: %s, idCliente: %d, Cantidad Avisos activos: %d\n",
                    arrayCliente[idClienteMasActivos].nombre, arrayCliente[idClienteMasActivos].apellido,arrayCliente[idClienteMasActivos].idCliente,maxAvisosActivos);
            printf("\n(B)El cliente con mas avisos Pausados es:\nNombre: %s Apellido: %s, idCliente: %d, Cantidad Avisos pausados: %d\n",
                    arrayCliente[idClienteMasPausados].nombre, arrayCliente[idClienteMasPausados].apellido, arrayCliente[idClienteMasPausados].idCliente, maxAvisosPausados);
            printf("\n(C)El cliente con mas avisos es:\nNombre: %s Apellido: %s, idCliente: %d, Cantidad Avisos: %d\n",
                    arrayCliente[idClienteMasAvisos].nombre,arrayCliente[idClienteMasAvisos].apellido, arrayCliente[idClienteMasAvisos].idCliente, maxAvisosTotal);


           }
           else
           {
               printf("No hay datos cargados");
           }
    }
    return retorno;
}

int informes_cantidadPublicacionesRubro(Publicacion* arrayPublicacion,int sizePublicacion,int rubro)
{
    int i;
    int acumuladorPublicaciones=0;
    if(sizePublicacion > 0 && arrayPublicacion != NULL)
    {
        for(i=0;i<sizePublicacion;i++)
        {
            if(!arrayPublicacion[i].isEmpty)
            {
                if(arrayPublicacion[i].rubro == rubro && arrayPublicacion[i].estado)
                {
                       acumuladorPublicaciones++;
                }
            }
        }
    }
    return acumuladorPublicaciones;
}

int informes_publicacionesPorRubro(Publicacion* arrayPublicacion,int sizePublicacion)
{
    int retorno=-1;
    int i;
    int rubro;
    int nohaydatos=1;
    int maxPublicacionesActivas;
    int idPublicacionMinActivas;
    int minPublicacionesActivas;
    int idPublicacionMaxActivas;
    int flagMaxActivos=1;
    int flagMinActivos=1;

    if(sizePublicacion > 0 && arrayPublicacion != NULL)
    {
        for(i=0;i<sizePublicacion;i++)
        {
            if(!arrayPublicacion[i].isEmpty)
            {

                if(maxPublicacionesActivas<informes_cantidadPublicacionesRubro(arrayPublicacion,arrayPublicacion[i].rubro,sizePublicacion) || flagMaxActivos)
                {
                    maxPublicacionesActivas = informes_cantidadPublicacionesRubro(arrayPublicacion,arrayPublicacion[i].rubro,sizePublicacion);
                    idPublicacionMaxActivas = i;
                    flagMaxActivos=0;
                }

                if(minPublicacionesActivas>informes_cantidadPublicacionesRubro(arrayPublicacion,sizePublicacion, arrayPublicacion[i].rubro) || flagMinActivos)
                {
                    minPublicacionesActivas = informes_cantidadPublicacionesRubro(arrayPublicacion,sizePublicacion,arrayPublicacion[i].rubro);
                    idPublicacionMinActivas = i;
                    flagMinActivos=0;
                }
                nohaydatos=0;
                retorno=0;
            }
        }
    if(!nohaydatos)
    {
        get_validInt("Ingrese un rubro: ","Rubro Invalido",&rubro,1,3,3);
        printf("\n(A)El rubro tiene %d publicaciones activas\n",informes_cantidadPublicacionesRubro(arrayPublicacion,sizePublicacion, rubro));
        printf("\n(B)El rubro con mas cantidad de publicaciones activas es: %d\n", arrayPublicacion[idPublicacionMaxActivas].rubro);
        printf("\n(C)El rubro con menor cantidad de publicaciones activas es: %d", arrayPublicacion[idPublicacionMinActivas].rubro);
    }
    else
    {
        printf("No hay avisos ingresados en el sistema");
    }
    }
    return retorno;
}
