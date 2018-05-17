#ifndef ABMCLIENTE_H_INCLUDED
#define ABMCLIENTE_H_INCLUDED

typedef struct{

int idCliente;
char nombre[50];
char apellido[50];
char cuil[11];
int isEmpty;


}Cliente;

/** \brief Inicializa todos los arrays de Cliente, poniendo el valor de isEmpty en 1
 *
 * \param array Cliente*
 * \param size int
 * \return (0) si el tamaño del array es mayor a 0 o el array no apunta  a NULL (1)si el tamaño del array es igual o menor a 0 o el array apunta a NULL
 *
 */
int abmCliente_init(Cliente *array, int size);

/** \brief Da de alta un cliente, pidiendo los datos de nombre apellido y Cuil, genera ademas un idCliente automatico y pasa el estado de IsEmpty en 0
 *
 * \param array Cliente*
 * \param size int
 * \return (0) Si todos los datos son validados y correctamente cargados (-1)Si no hay espacio y (-2) Si hubo un error de carga o validacion
 *
 */
int abmCliente_alta(Cliente *array,int size);

/** \brief Busca el indice del Cliente que coincida con el Id ingresado
 *
 * \param array Cliente*
 * \param size int
 * \param id int
 * \return (i) si todo esta bien, devuelve el indice que coincida con el id (-1) si el tamaño del array es 0 o es NULL (-2)Si no coincide el id con ningun indice
 *
 */
int abmCliente_buscarPorId(Cliente *array,int size, int id);

/** \brief Pone en estado de Verdadero (1) el IsEmpty del Cliente que coincida con el ID ingresado
 *
 * \param array Cliente*
 * \param size int
 * \param id int
 * \return (0) Si esta todo bien, (-1)Si el indice a eliminar es menor a 0
 *
 */
int abmCliente_baja(Cliente *array,int size, int id);

/** \brief Pide un id y modifica los campos de Nombre apellido y Cuil del Cliente cuyo indice coincida con el del id ingresado
 *
 * \param array Cliente*
 * \param size int
 * \param id int
 * \return (0) Si todos los datos son validados y correctamente cargados (-1)Si no hay espacio y (-2) Si hubo un error de carga o validacion
 *
 */
int abmCliente_modificacion(Cliente* array, int size, int id);

/** \brief Muestra los campos de Nombre apellido cuil Isempty del Cliente cuyo indice coincida con el del id ingresado
 *
 * \param array Cliente*
 * \param id int
 * \return (0) Si todo esta bien (-1) Si el array apunta a Null
 *
 */
int abmCliente_mostrar(Cliente *array, int id);

#endif // ABMCLIENTE_H_INCLUDED
