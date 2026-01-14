/* WARNING if type checker is not performed, translation could contain errors ! */

#include "Verification.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

#define Verification__maxMeals 3
#define Verification__maxStudents 100
/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static bool Verification__student_registered[101];
static bool Verification__is_present[101];
static int32_t Verification__meals_taken[101];
static int32_t Verification__num_students;
static bool Verification__mess_status;
static bool Verification__error_flag;
/* Clause INITIALISATION */
void Verification__INITIALISATION(void)
{
    
    unsigned int i = 0;
    for(i = 0; i <= 100;i++)
    {
        Verification__student_registered[i] = false;
    }
    for(i = 0; i <= 100;i++)
    {
        Verification__is_present[i] = false;
    }
    for(i = 0; i <= 100;i++)
    {
        Verification__meals_taken[i] = 0;
    }
    Verification__num_students = 0;
    Verification__mess_status = true;
    Verification__error_flag = false;
}

/* Clause OPERATIONS */

void Verification__AddStudent(Verification__STUDENT ss)
{
    Verification__student_registered[ss] = true;
    Verification__meals_taken[ss] = 0;
    {
        int32_t count;
        
        count = Verification__num_students+1;
        if((count) <= (Verification__maxStudents))
        {
            Verification__num_students = count;
        }
    }
}

void Verification__RemoveStudent(Verification__STUDENT ss)
{
    Verification__student_registered[ss] = false;
    Verification__is_present[ss] = false;
    {
        int32_t count;
        
        count = Verification__num_students-1;
        if((count) >= (0))
        {
            Verification__num_students = count;
        }
    }
}

void Verification__MarkEntry(Verification__STUDENT ss)
{
    Verification__is_present[ss] = true;
}

void Verification__TakeMeal(Verification__STUDENT ss)
{
    {
        int32_t m_count;
        
        m_count = Verification__meals_taken[ss];
        if((m_count) < (3))
        {
            Verification__meals_taken[ss] = m_count+1;
        }
    }
}

void Verification__ResetDay(void)
{
    unsigned int i = 0;
    {
        for(i = 0; i <= 100;i++)
        {
            Verification__is_present[i] = false;
        }
        for(i = 0; i <= 100;i++)
        {
            Verification__meals_taken[i] = 0;
        }
    }
}

void Verification__OpenMess(void)
{
    Verification__mess_status = true;
}

void Verification__CloseMess(void)
{
    Verification__mess_status = false;
}

void Verification__HandleError(void)
{
    Verification__error_flag = false;
}

