#include <stdio.h>
#include <string.h>
#include <ctype.h>
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


//  swap function to swap positions while performing insertion

 void swapVariables(struct person *add1, struct person *add2){
    struct person temp = *add1;
    *add1= *add2;
    *add2= temp;
}

//  insertion sort function to sort employees by ID
void SortDBByEmployeeIDs(struct person DB[], int n){

for(int i=0; i<n; i++){
 
    for(int j=i-1; j<n; j--){
 
        if(DB[j+1].id<DB[j].id){
            swapVariables(&DB[j], &DB[j+1]);
 
        }else{
            break;
        }
 
    }

    }
}


//  Print DB function 
void PrintDB (struct person DB[], int DBSize)
{

    printf("Name\t\t\t\tSALARY\t   ID\n");
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

//  Function to remove employee from DB
void RemoveEmployee(struct person DB[], int n)
{

    printf("\nName\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    printf("%s\t%s\t%d\t%d\n", DB[n].firstName, DB[n].lastName, DB[n].salary, DB[n].id);
    printf("----------------------------------------------\n");
    printf("Are you sure you want to to delete this employee? Press 1 to delete Yes, Press 0 to abort.\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice); 
    if (choice == 1)
    {
            for (int i = n; i < employeeCount; i++){
                DB[i] = DB[i+1];
            }
            employeeCount--;

            printf("Employee deleted\n");
    }
    else if (choice == 0)
    {
        printf("Operation Aborted.\n");
    }
    else
    {
        printf("Invalid entry Please try again!\n");
    }
}

int UpdateEmployee(struct person DB[], int x)
{
    int option;
    char firstName[MAXNAME], lastName[MAXNAME];
    int newSalary, newID;
    printf("\nName\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    printf("%-15s\t%-15s\t%d\t%d\n", DB[x].firstName, DB[x].lastName, DB[x].salary, DB[x].id);
    printf("----------------------------------------------\n");
    printf("Would you like to edit the information of this employee?Press 1 to edit. Press 0 to cancel.\n");
    printf("Enter your choice: ");
    scanf("%d", &option); 

    if (option == 0)
    {
        printf("Cancelled!\n");
        return 0;
    }
    if (option == 1)
    {
        printf("What do you want to change?\n");
        printf("\t(Press 1) First Name\n");
        printf("\t(Press 2) Last Name\n");
        printf("\t(Press 3) Salary\n");
        printf("\t(Press 4) Employee ID\n");
        printf("\t(Press 5) All the details of the employee\n");
        printf("Enter your choice: ");
        scanf("%d", &option); 

        switch (option) {
            case 1:  
                printf("\n Please enter the updated first name: "); 
                scanf("%s", firstName);      

                printf("\nName\t\t\t\tSALARY\t   ID\n");
                printf("----------------------------------------------\n");
                printf("%-15s\t%-15s\t%d\t%d\n", firstName, DB[x].lastName, DB[x].salary, DB[x].id);
                printf("----------------------------------------------\n");
                printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                printf("Enter your choice: ");
                scanf("%d", &option); 

                if (option == 1)
                {
                    printf("Updated!\n");
                    strcpy(DB[x].firstName, firstName);
                }
                else if (option == 0)
                {
                    printf("Cancelled.\n");
                }
                else
                {
                    printf("\nInvalid entry!\n");
                }
                break;
            case 2:
                printf("\n Please enter the updated last name: "); 
                scanf("%s", lastName);      

                printf("\nName\t\t\t\tSALARY\t   ID\n");
                printf("----------------------------------------------\n");
                printf("%-15s\t%-15s\t%d\t%d\n", DB[x].firstName, lastName, DB[x].salary, DB[x].id);
                printf("----------------------------------------------\n");
                printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                printf("Enter your choice: ");
                scanf("%d", &option); 

                if (option == 1)
                {
                    printf("\nUpdated.\n");
                    strcpy(DB[x].lastName, lastName);
                }
                else if (option == 0)
                {
                    printf("\nCancelled.\n");
                }
                else
                {
                    printf("\nInvalid entry!\n");
                }
                break;
            case 3:                 
                printf("\n Please enter the updated salary: "); 
                scanf("%d", &newSalary);      

                printf("\nName\t\t\t\tSALARY\t   ID\n");
                printf("----------------------------------------------\n");
                printf("%-15s\t%-15s\t%d\t%d\n", DB[x].firstName, DB[x].lastName, newSalary, DB[x].id);
                printf("----------------------------------------------\n");
                printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                printf("Enter your choice: ");
                scanf("%d", &option); 

                if (option == 1)
                {
                    printf("\nUpdate Complete.\n");
                    DB[x].salary = newSalary;
                }
                else if (option == 0)
                {
                    printf("\nUpdate Cancelled.\n");
                }
                else
                {
                    printf("\nInvalid entry. Cancelling action\n");
                }
                break;
            case 4:
                printf("\n Please enter the updated employee ID: "); 
                scanf("%d", &newID);      

                printf("\nName\t\t\t\tSALARY\t   ID\n");
                printf("----------------------------------------------\n");
                printf("%-15s\t%-15s\t%d\t%d\n", DB[x].firstName, DB[x].lastName, DB[x].salary, newID);
                printf("----------------------------------------------\n");
                printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                printf("Enter your choice: ");
                scanf("%d", &option); 

                if (option == 1)
                {
                    printf("\nUpdate Complete.\n");
                    DB[x].id = newID;
                }
                else if (option == 0)
                {
                    printf("\nUpdate Cancelled.\n");
                }
                else
                {
                    printf("\nInvalid entry. Cancelling action\n");
                }             
                SortDBByEmployeeIDs(DB, employeeCount);
                break;
            case 5:
                printf("\n Please enter the updated first name: "); 
                scanf("%s", firstName);      
                printf("\n Please enter the updated last name: "); 
                scanf("%s", lastName);
                printf("\n Please enter the updated salary: "); 
                scanf("%d", &newSalary);
                printf("\n Please enter the updated employee ID: "); 
                scanf("%d", &newID); 

                printf("\nName\t\t\t\tSALARY\t   ID\n");
                printf("----------------------------------------------\n");
                printf("%-15s\t%-15s\t%d\t%d\n", firstName, lastName, newSalary, newID);
                printf("----------------------------------------------\n");
                printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                printf("Enter your choice: ");
                scanf("%d", &option); 

                if (option == 1)
                {
                    printf("\nUpdate Complete.\n");
                    strcpy(DB[x].firstName, firstName);
                    strcpy(DB[x].lastName, lastName);
                    DB[x].salary = newSalary;
                    DB[x].id = newID;
                }
                else if (option == 0)
                {
                    printf("\nUpdate Cancelled.\n");
                }
                else
                {
                    printf("\nInvalid entry. Cancelling action\n");
                }   
                SortDBByEmployeeIDs(DB, employeeCount);   
                break;
        }
    }
    else
    {
        printf("\nInvalid entry. Cancelling action\n");
        return 0;
    }

}

//  Insertion sort to sort employee salaries to show the highest salaries
void SortEmployeeBySalary(struct person DB[], int n){
   for(int i=0; i<n; i++){
 
    for(int j=i-1; j<n; j--){
 
        if(DB[j+1].salary<DB[j].salary){
            swapVariables(&DB[j+1], &DB[j]);
 
        }else{
            break;
        }
 
    }

    } 

}

//  Function to lookup the employees with their last names
int LastNameLookup(struct person DB[], int n, char *name){
    
    int j;
    int check = -1;
    char enteredName[MAXNAME], DBlastName[MAXNAME];

    j = strlen(name);
    for (int i = 0; i < j; i++)
    {
        enteredName[i] = tolower(name[i]);
    }

    printf("\nName\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        j = strlen(DB[i].lastName);
        for (int k = 0; k < j; k++)
        {
            DBlastName[k] = tolower(DB[i].lastName[k]);
        }
        if (strcmp(enteredName, DBlastName) == 0)
        {
            printf("%-15s\t%-15s\t%d\t%d\n", db[i].firstName,db[i].lastName,db[i].salary, db[i].id);
            check = 0;
        }
        memset(&DBlastName[0], 0, sizeof(DBlastName)); 
    }
    printf("----------------------------------------------\n");

    if (check == 0)
    {
        return check;
    }
    return check;


}
//  Function to print highSalaries of the employees
void PrintSalaries(struct person highSalariesDB[], int n){
    printf("Name\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    for (int i = n-1; i >=0; i--)
    {
        printf("%-15s\t%-15s\t%d\t%d\n", highSalariesDB[i].firstName,highSalariesDB[i].lastName,highSalariesDB[i].salary, highSalariesDB[i].id);
    }
    printf("----------------------------------------------\n");
    printf(" Number of Employees (%d)\n", n);
}

//  Function to chose employees highest salaries

int PrintHighestSalary(struct person DB[], int n){
    struct person highSalariesDB[n];
    int choice;
    for (int i = 0; i < n; i++)
    {
        highSalariesDB[i] = DB[i];
    }

    printf("\nPlease enter how many employees you want to view with the highest salaries\n");
    printf("Enter your choice: ");

    scanf("%d", &choice); //Read user choice for DB menu
    // if(!isdigit(choice)) return 0;
    if(choice <0 ) return -1;
    if (choice > n) choice = n;
    
    SortEmployeeBySalary(highSalariesDB, n);
    PrintSalaries(highSalariesDB, choice);
    
}


int main(int argc, char *argv[]){
    
        CreateDB(argv[1]);
        SortDBByEmployeeIDs(db, employeeCount);        
        int choice; 
        int index = 0; 
        while (1) {
            printf("\nEmployee DB Menu:\n");
            printf("----------------------------------\n");
            printf("\t(1) Print the Database\n");
            printf("\t(2) Lookup by ID\n");
            printf("\t(3) Lookup by Last Name\n");
            printf("\t(4) Add an Employee\n");
            printf("\t(5) Remove an Employee\n");
            printf("\t(6) Update Employee Record\n");
            printf("\t(7) Print Employee(s) with Highest Salary\n");
            printf("\t(8) Find all Employees with Entered Last Name\n");
            printf("\t(9) Quit\n");
            printf("----------------------------------\n");
            printf("Enter your choice: ");

//Read user choice for DB menu
            scanf("%d", &choice); 
               int target_ID;
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
                 
                    printf("\nPlease enter an employee ID: ");
                    scanf("%d", &target_ID);          
                    index = LookupID(db, employeeCount, target_ID);
                    if (index == -1){
                        printf("%d not found in employee database\n", target_ID);
                    }
                    else{
                        RemoveEmployee(db, index);
                    }                   
                    break;
                 case 6:
                 
                    printf("\nPlease enter an employee ID: ");
                    scanf("%d", &target_ID);          
                    index = LookupID(db,employeeCount, target_ID);
                    if (index == -1)
                    {
                         printf("%d not found in employee database\n", target_ID);
                    }
                    else
                    {
                        UpdateEmployee(db, index); 
                    }       
                    break;
                case 7:
                    index = PrintHighestSalary(db, employeeCount);
                    if(index==-1) printf("Entered choice cannot be less than 0");
                    if(index == 0) printf("Entered choice must be a number");
                    break;
                case 8:
                    printf("Enter employee's last name: ");
                    scanf("%s", target_name);
                    index = LastNameLookup(db, employeeCount, target_name);
                    if(index == -1){
                        printf("%s not found in employee database", target_name);
                    }
                    break;
                case 9:
                    printf("\ngoodbye!\n");      
                    return 0;
                    break;
                
                default:            
                    printf( "\nInvalid input. Please try again.\n" );
                    break;
            }
        }
    }



   