#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(void);
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo);
void employee_delete(Employee* this);

/*****************************************************/

//set y get (formato texto)

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setIdTxt(Employee* this,char* id);
int employee_getIdTxt(Employee* this,char* id);

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);

int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_getSueldoTxt(Employee* this,char* sueldo);

//get y set (NATIVOS)

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/****************************************************/
int Employee_funcionCriterio (void* item1, void* item2);

#endif // employee_H_INCLUDED
