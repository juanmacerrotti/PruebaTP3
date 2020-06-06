#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

static int idMaximo(LinkedList* pArrayListEmployee, int* idMaximo);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

	pArchivo = fopen(path,"r");

	if(pArchivo!=NULL)
	{
		parser_EmployeeFromText(pArchivo,pArrayListEmployee);
		retorno=0;
	}

	fclose(pArchivo);

   return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;

	pArchivo = fopen(path,"rb");

		if(pArchivo!=NULL)
		{
			parser_EmployeeFromText(pArchivo,pArrayListEmployee);
			retorno=0;
		}

	fclose(pArchivo);

	   return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char bufferNombre[128];
	int bufferSueldo;
	int bufferHorasTrabajadas;
	int id;
	Employee* empleado;

	if(pArrayListEmployee != NULL)
	{
		if(	utn_getNombre(bufferNombre,128,"ingrese nombre: \n", "nombre incorrecto \n", 2) == 0 &&
				utn_getNumero(&bufferSueldo,"ingrese sueldo: \n", "sueldo incorrecto \n",1,100000,2) ==0 &&
				utn_getNumero(&bufferHorasTrabajadas, "ingrese horas trabajadas:","formato horas incorrecto",1,24,2) == 0 &&
				idMaximo(pArrayListEmployee,&id) ==0)
			{
				id=id+1;
				empleado=employee_newParametros(id,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
				ll_add(pArrayListEmployee, empleado);
				printf("alta OK \n");
				retorno=0;
			}
	}
	else
	{
		printf("Error.");
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int i;
	Employee* empleado;
	char bufferNombre[128];
	int bufferSueldo;
	int bufferHorasTrabajadas;

if(pArrayListEmployee != NULL)
{
	if(utn_getNumero(&id,"ingrese ID del empleado a modificar:", "error", 0,ll_len(pArrayListEmployee),2) == 0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			empleado= ll_get(pArrayListEmployee,i);

			if(empleado->id == id)
			{
				if(	utn_getNombre(bufferNombre,128,"ingrese nombre: \n", "nombre incorrecto \n", 2) == 0 &&
					utn_getNumero(&bufferSueldo,"ingrese sueldo: \n", "sueldo incorrecto \n",1,100000,2) ==0 &&
					utn_getNumero(&bufferHorasTrabajadas, "ingrese horas trabajadas:","formato horas incorrecto",1,24,2) == 0)
					{
							employee_setNombre(empleado,bufferNombre);
							employee_setSueldo(empleado,bufferSueldo);
							employee_setHorasTrabajadas(empleado,bufferHorasTrabajadas);
					    	printf("modificacion OK \n");
					    	retorno=0;
					}
			}
		}
	}
}
    return retorno;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int i;
	Employee* empleado;

	if(pArrayListEmployee != NULL)
	{
		if(utn_getNumero(&id, "ingrese ID que quiere borrar:", "Formato ID incorrecto", 0,ll_len(pArrayListEmployee),2) ==0)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				empleado= ll_get(pArrayListEmployee,i);
				if(empleado->id == id)
				{
					employee_delete(empleado);
					ll_remove(pArrayListEmployee,i);
					retorno=0;
				}
				else
				{
					printf("No se encontre ID\n");
				}
			}
		}
	}

return retorno;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* empleado;

	if(pArrayListEmployee != NULL) //valida que la lista tenga algo
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++) // recorre lista
		{
		empleado = ll_get(pArrayListEmployee,i); //lee un empleado en una posicion de la lista.
		printf("NOMBRE: %s - SUELDO: %d - HORAS TRABAJADAS: %d - ID: %d", empleado->nombre,empleado->sueldo,empleado->horasTrabajadas,empleado->id); //imprime los campos de esa posicion.
		}
	}

return retorno;
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	ll_sort(pArrayListEmployee,Employee_funcionCriterio,1); //llama a la funcion de ordenamiento de la linkedlist
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) //guardar los datos de los empleados
{
	int retorno=-1;
	FILE* pArchivo;

	if((pArchivo = fopen(path,"w"))==NULL)
	{
		printf("El archivo no se puede abrir.\n");
	}



		fclose(pArchivo);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

static int idMaximo(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno=-1;
	Employee* auxEmpleado;
	int auxId=-1;
	int i;

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0; i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=ll_get(pArrayListEmployee,i);
			if(auxEmpleado->id>auxId)
			{
				*idMaximo=auxId;
			}
		}
	}

	return retorno;
}
