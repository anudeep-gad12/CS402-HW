#include <stdio.h>
#include <string.h>
#include "IO.h"
#define MAXNAME 64

extern FILE *file;  // To read the input file
struct person  
{
    char firstName[MAXNAME];
    char lastName[MAXNAME];
    int id;
    int salary;
};
struct person db[1024]; // Array of persons struct 
int employeeCount = 0; // number of employees in the DB

//  Print DB function 
void PrintDB (struct person DB[], int DBSize)
{

    printf("Name\t\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < DBSize; i++)
    {
        printf("%-15s\t%-15s\t%d\t%d\n", DB[i].firstName,DB[i].lastName,DB[i].salary, DB[i].id);
    }
    printf("----------------------------------------------\n");
    printf(" Number of Employees (%d)\n", DBSize);
}

//  Lookup by ID in DB function
int LookupID(struct person DB[],int dbLength, int ID) 
{ 
       for (int i = 0; i < dbLength; i++){
      if(db[i].id ==ID) return i;

    }

    return -1;
} 

//  Lookup by LastName in DB function
int LookuplastName (struct person DB[], int dbLength, char* name)
{

    for (int i = 0; i < dbLength; i++)
    {
        if (strcmp(DB[i].lastName, name) == 0)
        {
            return i;
        }
    }
    return -1;
}


int AddEmployee(struct person arr[])
{
    char newfirstName[MAXNAME];
    char newlastName[MAXNAME];
    int newSalary;
    int YN;

    printf("\nEnter the first name of the employee: ");
    scanf("%s", newfirstName);
    while (strlen(newfirstName) > 64)
    {
        printf("Invalid entry. Please try again.\n");
    printf("\nEnter the first name of the employee: ");
    scanf("%s", newfirstName);
    
    }
    printf("Enter the last name of the employee: ");
    scanf("%s", newlastName);
    while (strlen(newfirstName) > 64)
    {
        printf("Invalid entry. Please try again.\n");
    printf("Enter the last name of the employee: ");
    scanf("%s", newlastName);
    
    }
    printf("Enter employee's salary (30000 to 150000): ");
    scanf("%d", &newSalary);
    while (newSalary < 30000 || newSalary > 150000)
    {
        printf("Hey, %d is not between 30000 and 150000, try again...\n",&newSalary);
    printf("Enter employee's salary (30000 to 150000): ");
    scanf("%d", &newSalary);
    
    }
    printf("\nDo you want to add the following employee to the DB?\n");
    printf("\t%s %s, \tSalary: %d\n", newfirstName, newlastName, newSalary);
    printf("\nEnter 1 for yes, 0 for no: ");
    scanf("%d", &YN);

//  add new employees to DB
    if (YN == 1)
    {
        strcpy(db[employeeCount].firstName, newfirstName);
        strcpy(db[employeeCount].lastName, newlastName);
        db[employeeCount].salary = newSalary;
        db[employeeCount].id = db[employeeCount-1].id +1;
        employeeCount++;    
        FILE *fpointer = fopen("input.txt", "a");
        fprintf(fpointer, "\n%d\t%s\t%s\t%d\n", db[employeeCount-1].id +1, newfirstName,newlastName,newSalary);
    }
    return 1;
}


void CreateDB(char* inputFile)
{
    if (open_file(inputFile) == 0)
    {
        char line[200];
        int ret;
        while (fgets(line, sizeof(line), file)) 
        {
            ret = read_int(line, 1, &db[employeeCount].id);
            ret = read_int(line, 2, &db[employeeCount].salary);
            ret = read_string(line, 1, &db[employeeCount].firstName);
            ret = read_string(line, 2, &db[employeeCount].lastName);
            employeeCount++; 
        }
        //  if reached end of the file close it 

        if (feof(file)) {
            close_file(file);
        } 
    }
}


int main(int argc, char *argv[]){
    
        CreateDB(argv[1]);        
        int choice; 
        int index = 0; 
        while (1) {
            printf("\nEmployee DB Menu:\n");
            printf("----------------------------------\n");
            printf("\t(1) Print the Database\n");
            printf("\t(2) Lookup by ID\n");
            printf("\t(3) Lookup by Last Name\n");
            printf("\t(4) Add an Employee\n");
            printf("\t(5) Quit\n");
            printf("----------------------------------\n");
            printf("Enter your choice: ");

//Read user choice for DB menu
            scanf("%d", &choice); 
//  User selection from the options
        switch (choice) {
                case 1:            
                    PrintDB(db, employeeCount);
                    break;
                case 2: ;
                    int target_ID; //target employee ID 
                    printf("\nEnter a 6 digit employee id: ");
                    scanf("%d", &target_ID);          
                    index = LookupID(db, employeeCount, target_ID);
                    if (index == -1)
                    {
                        printf("\nUser with employee ID '%d' not found\n", target_ID);
                    }
                    else
                    {
                        printf("\nName\t\t\t\tSALARY\t   ID\n");
                        printf("----------------------------------------------\n");
                        printf("%s\t%s\t%d\t%d\n", db[index].firstName,db[index].lastName,db[index].salary, db[index].id);
                        printf("----------------------------------------------\n");
                    }
                    
                    break;
                case 3: ;
                    char target_name[MAXNAME]; //target name to search                 
                    printf("\nPlease enter an employee's last name: ");
                    scanf("%s", target_name); 
                    index = LookuplastName(db, employeeCount, target_name);
                    if (index == -1)
                    {
                        printf("\nUser with last name '%s' not found\n", target_name);
                    }
                    else
                    {
                        printf("\nName\t\t\t\tSALARY\t   ID\n");
                        printf("----------------------------------------------\n");
                        printf("%s\t%s\t%d\t%d\n", db[index].firstName,db[index].lastName,db[index].salary, db[index].id);
                        printf("----------------------------------------------\n");
                    }                    
                    break;
                case 4:        
                    AddEmployee(db);
                    break;
                case 5:
                    printf("\ngoodbye!\n");      
                    return 0;
                    break;
                default:            
                    printf( "\nInvalid input. Please try again.\n" );
                    break;
            }
        }
    }