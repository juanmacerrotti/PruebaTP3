#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char auxiliarId [4096];
	char auxiliarNombre [4096];
	char auxiliarHorasTrabajadas [4096];
	char auxiliarSueldo [4096];

	Employee* pAuxiliarEmpleado;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fopen("data.csv","r");
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas,auxiliarSueldo) == 4)
			{
				pAuxiliarEmpleado = employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHorasTrabajadas, auxiliarSueldo);
				if(pAuxiliarEmpleado != NULL)
				{
					ll_add(pArrayListEmployee,pAuxiliarEmpleado);
				}
			}
		}while (feof(pFile) == 0);
		retorno=0;
		fclose(pFile);
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
