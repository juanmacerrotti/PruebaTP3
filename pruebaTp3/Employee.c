
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"
#include "parser.h"
#include "LinkedList.h"

#define NOMBRE_LEN 128

static int esNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

Employee* employee_new(void)
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}

Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int flagOk=0;
	Employee* punteroEmpleados = NULL;
	punteroEmpleados = employee_new();

	if(punteroEmpleados != NULL)
	{
		if(employee_setNombre(punteroEmpleados,nombreStr) == 0)
		{
			if(employee_setHorasTrabajadasTxt(punteroEmpleados, horasTrabajadasStr) == 0)
			{
				if(employee_setIdTxt(punteroEmpleados,idStr) == 0)
				{
					if(employee_setSueldoTxt (punteroEmpleados,sueldoStr) == 0)
					{
						flagOk=1;
					}
				}
			}
		}
		if(flagOk==0)
		{
			employee_delete (punteroEmpleados);
			punteroEmpleados=NULL;
		}
	}
	return punteroEmpleados;
}

Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
	int flagOk=0;
	Employee* punteroEmpleados = NULL;
	punteroEmpleados = employee_new();

	if(punteroEmpleados != NULL)
	{
		if(employee_setNombre(punteroEmpleados,nombreStr) == 0)
		{
			if(employee_setHorasTrabajadas(punteroEmpleados, horasTrabajadas) == 0)
			{
				if(employee_setId(punteroEmpleados,id) == 0)
				{
					if(employee_setSueldo(punteroEmpleados,sueldo) == 0)
					{
						flagOk=1;
					}
				}
			}
		}
		if(flagOk==0)
		{
			employee_delete (punteroEmpleados);
			punteroEmpleados=NULL;
		}
	}
	return punteroEmpleados;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**********************************************************************************************************************************************************************/

//get y set (formato texto)
int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(esNombre(nombre, 128) == 0)
		{
			strncpy(this->nombre,nombre,128);
			retorno=0;
		}
	}

	return retorno;
}

int employee_getNombre (Employee* this, char* nombre)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre,128);
		retorno=0;
	}
	return retorno;
}

int employee_setIdTxt (Employee* this, char* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,100))
		{
			this->id=atoi(id);
			retorno=0;
		}

	}
		return retorno;
}

int employee_getIdTxt (Employee* this, char* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
			sprintf(id,"%d",this->id);
			retorno=0;
	}
		return retorno;
}

int employee_setSueldoTxt (Employee* this, char* sueldo)
{
	int retorno=-1;
	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo,100000))
		{
			this->sueldo=atoi(sueldo);
			retorno=0;
		}

	}
		return retorno;
}

int employee_getSueldoTxt (Employee* this, char* sueldo)
{
	int retorno=-1;
	if(this != NULL && sueldo != NULL)
	{
			sprintf(sueldo,"%d",this->sueldo);
			retorno=0;
	}
		return retorno;
}

int employee_setHorasTrabajadasTxt (Employee* this, char* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,1000))
		{
			this->horasTrabajadas=atoi(horasTrabajadas);
			retorno=0;
		}

	}
		return retorno;
}

int employee_getHorasTrabajadasTxt (Employee* this, char* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas != NULL)
	{
			sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
			retorno=0;
	}
		return retorno;
}

/**************************/
//get y set (NATIVAS)

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_setId (Employee* this, int id)
{
	int retorno=-1;
	if(this != NULL && id >=0)
	{
		this->id=id;
		retorno=0;
	}
		return retorno;
}

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_getId (Employee* this, int* id)
{
	int retorno=-1;
	if(this != NULL && id >=0)
	{
		*id=this->id;
		retorno=0;
	}
		return retorno;
}

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_setSueldo (Employee* this, int sueldo)
{
	int retorno=-1;
	if(this != NULL && sueldo >=0)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
		return retorno;
}

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno=-1;
		if(this != NULL && sueldo >=0)
		{
			*sueldo=this->sueldo;
			retorno=0;
		}
			return retorno;
}

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas >=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
		return retorno;
}

/**
 * \brief
 * \param
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
int employee_getHorasTrabajadas (Employee* this, int* horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL && horasTrabajadas >=0)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
		return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief compara dos sueldo de empleados.
 * \param item1 puntero a void (direccion de memoria de un empleado)
 * \param item2 puntero a void (direccion de memoria de un empleado)
 * \return Retorna 1 (si suledo 1 es mayor o igual que el 2) retorno 0 (si sueldo dos es mas grande que sueldo 1) retorno -1 (error)
 */
int Employee_funcionCriterio (void* item1, void* item2)
{
	int retorno = -1;

	Employee* empleado1;
	Employee* empleado2;

	int sueldo1;
	int sueldo2;

	empleado1= (Employee*)item1;
	empleado2=(Employee*)item2;

	if(item1 != NULL && item2 != NULL)
	{
		if(employee_getSueldo(empleado1,&sueldo1)==0 &&
				employee_getSueldo(empleado2,&sueldo2) == 0)
			{
				if(sueldo1>=sueldo2)
				{
					retorno=1;
				}
				else
				{
					retorno=0;
				}
			}
	}

	return retorno;
}


