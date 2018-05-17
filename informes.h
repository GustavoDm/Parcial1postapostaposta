#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "abmCliente.h"
#include "abmPublicaciones.h"



/** \brief Muestra un listado de todos los clientes Activos y sus respectivos campos
 *
 * \param arrayCliente Cliente*
 * \param arrayPublicacion Publicacion*
 * \param sizeCliente int
 * \param sizePublicacion int
 * \return (0) Si esta todo bien, (-1) si el tamaño del array es 0 o menor o es NULL
 *
 */
int informes_mostrarClientes(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizeCliente, int sizePublicacion);

/** \brief Muestra un listado de todas la publicaciones junto con sus respectivos campos y el Cuil del cliente
 *
 * \param arrayCliente Cliente*
 * \param arrayPublicacion Publicacion*
 * \param sizePublicacion int
 * \param sizeCliente int
 * \return (0) Si esta todo bien, (-1) si el tamaño del array es 0 o menor o es NULL
 *
 */
int informes_mostrarPublicacion(Cliente *arrayCliente, Publicacion *arrayPublicacion, int sizePublicacion, int sizeCliente);

/** \brief Cuenta las publicaciones totales del cliente cuyo id haya sido ingresado
 *
 * \param arrayPublicacion Publicacion*
 * \param sizePublicacion int
 * \param idCliente int
 * \return La cantidad de Publicaciones totales
 *
 */
int informes_PublicacionesTotales(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);

/** \brief Cuenta las publicaciones activas del cliente cuyo id haya sido ingresado
 *
 * \param arrayPublicacion Publicacion*
 * \param sizePublicacion int
 * \param idCliente int
 * \return La cantidad de Publicaciones activas
 *
 */
int informes_PublicacionesActivas(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);

/** \brief Cuenta las publicaciones pausadas del cliente cuyo id haya sido ingresado
 *
 * \param arrayPublicacion Publicacion*
 * \param sizePublicacion int
 * \param idCliente int
 * \return La cantidad de Publicaciones pausadas
 *
 */
int informes_PublicacionesPausadas(Publicacion* arrayPublicacion,int sizePublicacion,int idCliente);

/** \brief Informa el Cliente con mas publicaciones totales, el que tiene mas publicaciones activas y el que tiene mas publicaciones pausadas
 *
 * \param arrayPublicacion Publicacion*
 * \param arrayCliente Cliente*
 * \param sizePublicacion int
 * \param sizeCliente int
 * \return (0)Si esta todo bien, (-1)Si el tamaño del array es 0 o menor o es NULL, y (-2)Si no hay ningun cliente o publicacion cargados
 *
 */
int informes_ClienteMaxPub(Publicacion *arrayPublicacion, Cliente *arrayCliente, int sizePublicacion, int sizeCliente);

/** \brief Informa el rubro con mas publicaciones totales, el que tiene mas publicaciones activas y el que tiene mas publicaciones pausadas
 *
 * \param arrayPublicacion Publicacion*
 * \param arrayCliente Cliente*
 * \param sizePublicacion int
 * \param sizeCliente int
 * \return (0)Si esta todo bien, (-1)Si el tamaño del array es 0 o menor o es NULL, y (-2)Si no hay ninguna publicacion cargada
 *
 */
int informes_publicacionesPorRubro(Publicacion* arrayPublicacion,int sizePublicacion);
#endif // INFORMES_H_INCLUDED
