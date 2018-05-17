#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abmPublicaciones.h"
#include "abmCliente.h"
#include "getsValids.h"


static int proximoId(void);
static int buscarLugarLibre(Publicacion* array,int size);
static int buscarPorIdAviso(Publicacion* array,int size, int id);

int abmPublicacion_init(Publicacion *array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int abmPublicacion_alta(Publicacion *array, int size)
{
    int retorno = -1;
    int i;
    int idCliente;
    int rubro;
    char texto[64];

    if(size > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,size);
        if(i >= 0)
        {
          if(!get_validInt("\nIngrese el ID del Cliente","\nID Invalido",&idCliente,0,100,3))
            {
                if(!get_validInt("\nIngrese el numero de rubro:\n(1)Clasificados\n(2)Inmuebles\n(3)Solos y solas","\nOpcion no valida",&rubro,1,3,3))
                {
                    if(!get_validAlfaNumerico("Ingrese su aviso: (maximo 64 caracteres)\n","Intente usar solo letras y numeros","Su aviso supera los 64 caracteres",texto,64,3 ))
                    {
                        retorno = 0;
                        array[i].idCliente = idCliente;
                        array[i].rubro = rubro;
                        strcpy(array[i].texto,texto);
                        array[i].idAviso = proximoId();
                        array[i].isEmpty = 0;
                        array[i].estado=1;
                        printf("El ID del aviso es: %d\n", array[i].idAviso);
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}



static int buscarPorIdAviso(Publicacion* array,int size, int id)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].idAviso==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}




int abmPublicacion_baja(Publicacion *array, int size, int id)
{
    int i;
    int retorno=-1;

    if(size > 0 && array != NULL)
    {
        for(i=0;i<size;i++)
        {
            if(id==array[i].idCliente && !array[i].isEmpty)
            {
                array[i].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

int abmPublicacion_Pausar(Publicacion *array, int size, int id){

int retorno =-1;
int indiceAPausear;
indiceAPausear=buscarPorIdAviso(array,size,id);

if(size > 0 && array != NULL)
    {
        if(indiceAPausear >= 0)
        {
            retorno=0;
            array[indiceAPausear].estado=0;
        }
    }
    return retorno;
}

int abmPublicacion_Reanudar(Publicacion *array, int size, int id){

int retorno =-1;
int indiceAReanudar;
indiceAReanudar=buscarPorIdAviso(array,size,id);

if(size > 0 && array != NULL)
    {
        if(indiceAReanudar >= 0)
        {
            retorno=0;
            array[indiceAReanudar].estado=1;
        }
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion *array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


