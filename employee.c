// Employee Payroll System using C language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//structure to store employee details
struct employee
 {
    char name[500]; // Employee name
    int id; // Employee ID
    char dept[20]; // Employee department
    float salary; // Employee gross salary
};
//array declared using structure employee
struct employee emp[100];

// store the number of employees
int n = 0;

//function to welcome the user
void welcome();

//function to say bye to user
void bye();

//function to add a new employee
void add_employee();

//function to modify an existing employee
void modify_employee();

//function to delete an existing employee
void delete_employee();

//function to display all the employees
void display_employees();

// function to calculate the net salary of an employee
float net_salary(float salary);

//function to claculate net salary after cutting the taxes
float tax(float salary);

//function to generate the payroll report of an employee
void payroll_report(struct employee e);

// Function to generate a payroll slip and save it to a file
void generate_payroll_slip(struct employee e);

//Declare a function to save the employee data to a file
void save_data();

//function to load the employee data from a file
void load_data();

//Declare a function to display the main menu
void main_menu();

//main function
int main() 
{
    //Welcoming the user
    welcome();
    // Load the employee data from the file
    load_data();
    // Display the main menu
    main_menu();
    //Saying good bye to user
    bye();
    // Return 0 to indicate normal termination
    return 0;
}

//function to welcome the user
void welcome() 
{
    printf("Welcome to the Employee Payroll System!\n");
    printf("Developed by:\n");
    printf("-> Rohan Batra                                   23104056\n");
    printf("-> Shubham Rawat                                 231040xx\n");
    printf("\nPurpose of the App:\n");
    printf("This application allows you to manage employee payroll information.\n");
    printf("You can add, modify, delete employees, generate payroll reports, and more.\n\n");
}

//function to say bye to user
void bye()
{
    printf("\nBYE");
    printf("\nThankyou for using the application");
    printf("\nFind the project at github:https://github.com/MrRohanBatra/Employee-Payroll-System");
}

//function to add a new employee
void add_employee() 
{
    char ch;
    char first[50],last[50],name[100];
    do 
    {
        n++;

        //enter the employee details
        printf("\nEnter the details of employee %d:\n", n);

        // Read the employee name
        printf("Name: ");
        scanf("%s %s",first,last);
        strcat(first," ");
        strcat(first,last);
        strcpy(emp[n-1].name, first);
        // Read the employee ID
        printf("ID: ");
        scanf("%d", &emp[n-1].id);

        // Read the employee department
        printf("Department: ");
        scanf("%s", emp[n-1].dept);

        // Read the employee gross salary
        printf("Gross Salary: ");
        scanf("%f", &emp[n-1].salary);

        // Ask the user if they want to add another employee
        printf("\nDo you want to add another employee? (Y/N): ");
        scanf(" %c", &ch);
    } 
    while (ch == 'Y' || ch == 'y');

    // Save the employee data to the file
    save_data();

    // Display the main menu
    main_menu();
}

//function to modify an existing employee
void modify_employee() 
{
    int id;

    int index = -1;

    
    char ch;

    // Prompt the user to enter the employee ID
    printf("\nEnter the ID of the employee to be modified: ");
    scanf("%d", &id);

    // Search for the employee with the given ID
    for (int i = 0; i < n; i++) 
    {
        if (emp[i].id == id) 
        {
            // Store the index of the employee
            index = i;
            break;
        }
    }

    // Check if the employee is found
    if (index == -1) 
    {
        // Display an error message
        printf("\nEmployee not found!\n");
    } 
    else 
    {
        // Display the employee details
        printf("\nEmployee details:\n");
        printf("Name: %s\n", emp[index].name);
        printf("ID: %d\n", emp[index].id);
        printf("Department: %s\n", emp[index].dept);
        printf("Gross Salary: %.2f\n", emp[index].salary);

        // Ask the user if they want to modify the employee
        printf("\nDo you want to modify this employee? (Y/N): ");
        scanf(" %c", &ch);

        // Check if the user chooses to modify the employee
        if (ch == 'Y' || ch == 'y') 
        {
            // Prompt the user to enter the new employee details
            printf("\nEnter the new details of employee %d:\n", index + 1);

            // Read the new employee name
            printf("Name: ");
            char first[50],last[50];
            scanf("%s %s",first,last);
            strcat(first," ");
            strcat(first,last);
            strcpy(emp[index].name, first);
            //scanf("%s", emp[index].name);

            // Read the new employee ID
            printf("ID: ");
            scanf("%d", &emp[index].id);

            // Read the new employee department
            printf("Department: ");
            scanf("%s", emp[index].dept);

            // Read the new employee gross salary
            printf("Gross Salary: ");
            scanf("%f", &emp[index].salary);

            // Display a success message
            printf("\nEmployee modified successfully!\n");

            // Save the employee data to the file
            save_data();
        }
    }

    // Display the main menu
    main_menu();
}

//function to delete an existing employee
void delete_employee() 
{
    // Declare a local variable to store the employee ID
    int id;

    // Declare a local variable to store the index
    int index = -1;

    // Declare a local variable to store the choice
    char ch;

    // Prompt the user to enter the employee ID
    printf("\nEnter the ID of the employee to be deleted: ");
    scanf("%d", &id);

    // Search for the employee with the given ID
    for (int i = 0; i < n; i++) 
    {
        if (emp[i].id == id) 
        {
            // Store the index of the employee
            index = i;
            break;
        }
    }

    // Check if the employee is found
    if (index == -1) 
    {
        // Display an error message
        printf("\nEmployee not found!\n");
    } 
    else 
    {
        // Display the employee details
        printf("\nEmployee details:\n");
        printf("Name: %s\n", emp[index].name);
        printf("ID: %d\n", emp[index].id);
        printf("Department: %s\n", emp[index].dept);
        printf("Gross Salary: %.2f\n", emp[index].salary);

        // Ask the user if they want to delete the employee
        printf("\nDo you want to delete this employee? (Y/N): ");
        scanf(" %c", &ch);

        // Check if the user chooses to delete the employee
        if (ch == 'Y' || ch == 'y') 
        {
            // Delete the employee by shifting the array elements
            for (int i = index; i < n - 1; i++) 
            {
                emp[i] = emp[i + 1];
            }

            // Decrement the number of employees
            n--;

            // Display a success message
            printf("\nEmployee deleted successfully!\n");

            // Save the employee data to the file
            save_data();
        }
    }

    // Display the main menu
    main_menu();
}

//function to display all the employees
void display_employees() 
{
    //if there are any employees
    if (n == 0) 
    {
        // Display an error message
        printf("\nNo employees to display!\n");
    } 
    else 
    {
        // Display the employee details
        printf("\nEmployee details:\n");
        for (int i = 0; i < n; i++) 
        {
            printf("\nEmployee %d:\n", i + 1);
            printf("Name: %s\n", emp[i].name);
            printf("ID:%d\n", emp[i].id);
            printf("Department: %s\n", emp[i].dept);
            printf("Gross Salary: %.2f\n", emp[i].salary);
        }
    }

    // Display the main menu
    main_menu();
}

//function to calculate the net salary of an employee

float net_salary(float salary) {
    //variable to store the net salary
    float net;

    //variable to store the deductions
    float deductions;

    // Declare a local variable to store the allowances
    float allowances;

    //deductions as 10% of the gross salary
    deductions = salary * 0.1;

    //allowances as 5% of the gross salary
    allowances = salary * 0.05;
    
    //net salary as gross salary minus deductions plus allowances
    net = salary - deductions + allowances;

    // Return the net salary
    return net;
}

//function to calculate tax
float tax(float salary)
{
    float tax;
    //variable to stoe tax
    if(salary<=500000) 
    //if salary <50000
    {
        tax=0.1*salary; 
        //tax=10% 
    }
    else if(salary>500000 && salary<=1000000) 
    //salary>500000 && salary<=1000000 
    {
        tax=50000+(salary-500000)*0.2; 
        //tax=50000 +20% of(salary-500000)
    }
    else if(salary>100000) 
    //salary > 1000000
    {
        tax=150000+(salary-1000000)*0.3; 
        //tax=150000 +30% of (salary-1000000)
    }
    return tax;
}

//function to generate the payroll report of an employee
void payroll_report(struct employee e) 
{
    //variable to store the net salary
    float net;

    //variable to store the pay date
    char date[20];

    // Declare a local variable to store the current time
    time_t t;

    // Get the current time
    t = time(NULL);

    //Format the current time as a date string
    strftime(date, 20, "%d-%m-%Y", localtime(&t));

    // Calculate the net salary of the employee
    net = net_salary(e.salary);

    // Display the payroll report of the employee
    printf("\nPayroll Report of Employee %d:\n", e.id);
    printf("Name: %s\n", e.name);
    printf("ID: %d\n", e.id);
    printf("Department: %s\n", e.dept);
    printf("Gross Salary: %.2f\n", e.salary);
    printf("Net Salary: %.2f\n", net);
    printf("Tax Payable: %.2f\n",tax(net));
    printf("Pay Date: %s\n", date);
}

// Function to generate a payroll slip and save it to a file
void generate_payroll_slip(struct employee e) 
{
    //variable to store the net salary
    float net;

    //variable to store the pay date
    char date[20];

    //variable to store the current time
    time_t t;

    //Get the current time
    t = time(NULL);

    //Format the current time as a date string
    strftime(date, 20, "%d-%m-%Y", localtime(&t));

    //Calculate the net salary of the employee
    net = net_salary(e.salary);

    //Create a file pointer
    FILE *fp;

    //Open the file in write mode
    fp = fopen("payroll_slip.txt","w");

    //Check if the file is opened successfully
    if (fp == NULL) 
    {
        // Display an error message
        printf("\nError in opening the file!\n");
    } 
    else 
    {
        // Write the payroll slip details to the file
        fprintf(fp, "Payroll Slip\n");
        fprintf(fp, "-------------------------\n");
        fprintf(fp, "Employee Name: %s\n", e.name);
        fprintf(fp, "Employee ID: %d\n", e.id);
        fprintf(fp, "Department: %s\n", e.dept);
        fprintf(fp, "Gross Salary: %.2f\n", e.salary);
        fprintf(fp, "-------------------------\n");
        fprintf(fp, "Net Salary: %.2f\n", net_salary(e.salary));
        fprintf(fp, "Tax Payable: %.2f\n",tax(net));
        fprintf(fp, "-------------------------\n");


        // Close the file
        fclose(fp);

        // Display a success message
        printf("\nPayroll Slip generated and saved to 'payroll_slip.txt'!\n");
    }
}

//function to save the employee data to a file
void save_data() 
{
    //variable to store the file pointer
    FILE *fp;

    //Open the file in write mode
    fp = fopen("employee.dat", "w");

    //Check if the file is opened successfully
    if (fp == NULL) 
    {
        // Display an error message
        printf("\nError in opening the file!\n");
    }
    else 
    {
        // Write the number of employees to the file
        fprintf(fp, "%d\n", n);

        // Write the employee details to the file
        for (int i = 0; i < n; i++) 
        {
            fprintf(fp, "%s %d %s %.2f\n", emp[i].name, emp[i].id, emp[i].dept, emp[i].salary);
        }

        // Close the file
        fclose(fp);

        // Display a success message
        printf("\nData saved to the file!\n");
    }
}

//function to load the employee data from a file
void load_data() 
{
    //variable to store the file pointer
    FILE *fp;

    // Open the file in read mode
    fp = fopen("employee.dat", "r");

    // Check if the file is opened successfully
    if (fp == NULL) 
    {
        // Display an error message
        printf("\nError in opening the file!\n");
    } 
    else 
    {
        // Read the number of employees from the file
        fscanf(fp, "%d", &n);

        // Read the employee details from the file
        for (int i = 0; i < n; i++) 
        {
            fscanf(fp, "%s %d %s %f", emp[i].name, &emp[i].id, emp[i].dept, &emp[i].salary);
        }

        // Close the file
        fclose(fp);

        // Display a success message
        printf("\nSystem Check successfull!\nStarting........\n");
    }
}

//function to display the main menu
void main_menu() 
{
    //variable to store the choice
    int choice;

    // Display the main menu
    printf("\nEmployee Payroll System\n");
    printf("1. Add Employee\n");
    printf("2. Modify Employee\n");
    printf("3. Delete Employee\n");
    printf("4. Display Employees\n");
    printf("5. Tax Payable\n");
    printf("6. Generate Payroll Report\n");
    printf("7. Generate Payroll Slip\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int id,index;

    // Switch on the choice
    switch (choice) 
    {
        case 1:
        {
            // Call the function to add a new employee
            add_employee();
            break;
        }
        case 2:
        {
            // Call the function to modify an existing employee
            modify_employee();
            break;
        }
        case 3:
        {
            // Call the function to delete an existing employee
            delete_employee();
            break;
        }
        case 4:
        {
            // Call the function to display all the employees
            display_employees();
            break;
        }
        case 5:
        {
          index = -1;
            // Prompt the user to enter the employee ID
            printf("\nEnter the ID of the employee for tax report: ");
            scanf("%d", &id);

            // Search for the employee with the given ID
            for (int i = 0; i < n; i++) 
            {
                if (emp[i].id == id) 
                {
                    // Store the index of the employee
                    index = i;
                    break;
                }
            }

            // Check if the employee is found
            if (index == -1) 
            {
                // Display an error message
                printf("\nEmployee not found!\n");
            } 
            else 
            {
                //calculate the tax
                float tax1=tax(net_salary(emp[index].salary));
                // Call the function to generate the payroll report of the employee
                printf("Tax Payable:%.2f",tax1);
            }

            // Display the main menu
            main_menu();
            break;
        }
        case 6:
        {
              index = -1;
            // Prompt the user to enter the employee ID
            printf("\nEnter the ID of the employee for payroll report: ");
            scanf("%d", &id);

            // Search for the employee with the given ID
            for (int i = 0; i < n; i++) 
            {
                if (emp[i].id == id) 
                {
                    // Store the index of the employee
                    index = i;
                    break;
                }
            }

            // Check if the employee is found
            if (index == -1) 
            {
                // Display an error message
                printf("\nEmployee not found!\n");
            } 
            else 
            {
                // Call the function to generate the payroll report of the employee
                payroll_report(emp[index]);
            }

            // Display the main menu
            main_menu();
            break;
        }
        case 7:
        {
             index = -1;
            // Prompt the user to enter the employee ID
            printf("\nEnter the ID of the employee for payroll slip generation: ");
            scanf("%d", &id);

            // Search for the employee with the given ID
            for (int i = 0; i < n; i++) 
            {
                if (emp[i].id == id) 
                {
                    // Store the index of the employee
                    index = i;
                    break;
                }
            }

            // Check if the employee is found
            if (index == -1) 
            {
                // Display an error message
                printf("\nEmployee not found!\n");
            } 
            else 
            {
                // Call the function to generate the payroll report of the employee
                generate_payroll_slip(emp[index]);
            }

            // Display the main menu
            main_menu();
            break;
        }
        case 8:
        {
            //bye function
            bye();
            // Exit the program
            exit(0);
            break;
        }
        default:
        {
            // Display an error message
            printf("\nInvalid choice!\n");

            // Display the main menu
            main_menu();
            break;
        }
    }
}
