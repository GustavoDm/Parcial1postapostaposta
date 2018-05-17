#ifndef ABMPUBLICACIONES_H_INCLUDED
#define ABMPUBLICACIONES_H_INCLUDED
#include "abmCliente.h"
typedef struct{

int idCliente;
int rubro;
char texto[64];
int idAviso;
int estado;
int isEmpty;

}Publicacion;

/** \brief Inicializa el array indicando que estan vacios poniendo el campo isEmpty en 1
 *
 * \param array Publicacion*
 * \param size int
 * \return (0)si esta todo bien, (-1)Si el tamaño que le pasan al array es 0 o menor o si es NULL
 *
 */
int abmPublicacion_init(Publicacion *array, int size);

/** \brief Da de alta una Publicacion, pidiendo Id del cliente, numero de rubro y contenido del aviso, genera ademas un idAviso automatico y pone el isEmpty en 0
 *
 * \param array Publicacion*
 * \param size int
 * \return int (0) Si todos los datos son validados y correctamente cargados (-1)Si no hay espacio y (-2) Si hubo un error de carga o validacion
 *
 */
int abmPublicacion_alta(Publicacion *array, int size);

/** \brief Cambia el campo estado de una publicacion de (1)Activo a (0)Pausado
 *
 * \param array Publicacion*
 * \param size int
 * \param id int
 * \return (0)Si esta todo bien (-1)Si el tamaño que le pasan al array es 0 o menor o si es NULL
 *
 */
int abmPublicacion_Pausar(Publicacion *array, int size, int id);

/** \brief Cambia el campo estado de una publicacion de (0)Pausado a (1)Activo
 *
 * \param array Publicacion*
 * \param size int
 * \param id int
 * \return (0)Si esta todo bien (-1)Si el tamaño que le pasan al array es 0 o menor o si es NULL
 *
 */
int abmPublicacion_Reanudar(Publicacion *array, int size, int id);


/** \brief
 *
 * \param array Publicacion*
 * \param size int
 * \param id int
 * \return int
 *
 */
int abmPublicacion_baja(Publicacion *array, int size, int id);

#endif // ABMPUBLICACIONES_H_INCLUDED
