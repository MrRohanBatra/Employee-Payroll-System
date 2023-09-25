// Employee Payroll System using C language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store employee details
struct employee {
    char name[50]; // Employee name
    int id; // Employee ID
    char dept[20]; // Employee department
    float salary; // Employee gross salary
};

// Declare a global array of employee structures
struct employee emp[100];

// Declare a global variable to store the number of employees
int n = 0;

// Declare a function to add a new employee
void add_employee();

// Declare a function to modify an existing employee
void modify_employee();

// Declare a function to delete an existing employee
void delete_employee();

// Declare a function to display all the employees
void display_employees();

// Declare a function to calculate the net salary of an employee
float net_salary(float salary);

// Declare a function to generate the payroll report of an employee
void payroll_report(struct employee e);

// Declare a function to save the employee data to a file
void save_data();

// Declare a function to load the employee data from a file
void load_data();

// Declare a function to display the main menu
void main_menu();

// Define the main function
int main() {
    // Load the employee data from the file
    load_data();

    // Display the main menu
    main_menu();

    // Return 0 to indicate normal termination
    return 0;
}

// Define the function to add a new employee
void add_employee() {
    // Declare a local variable to store the choice
    char ch;

    // Repeat until the user chooses to exit
    do {
        // Increment the number of employees
        n++;

        // Prompt the user to enter the employee details
        printf("\nEnter the details of employee %d:\n", n);

        // Read the employee name
        printf("Name: ");
        scanf("%s", emp[n-1].name);

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
    } while (ch == 'Y' || ch == 'y');

    // Save the employee data to the file
    save_data();

    // Display the main menu
    main_menu();
}

// Define the function to modify an existing employee
void modify_employee() {
    // Declare a local variable to store the employee ID
    int id;

    // Declare a local variable to store the index
    int index = -1;

    // Declare a local variable to store the choice
    char ch;

    // Prompt the user to enter the employee ID
    printf("\nEnter the ID of the employee to be modified: ");
    scanf("%d", &id);

    // Search for the employee with the given ID
    for (int i = 0; i < n; i++) {
        if (emp[i].id == id) {
            // Store the index of the employee
            index = i;
            break;
        }
    }

    // Check if the employee is found
    if (index == -1) {
        // Display an error message
        printf("\nEmployee not found!\n");
    } else {
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
        if (ch == 'Y' || ch == 'y') {
            // Prompt the user to enter the new employee details
            printf("\nEnter the new details of employee %d:\n", index + 1);

            // Read the new employee name
            printf("Name: ");
            scanf("%s", emp[index].name);

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

// Define the function to delete an existing employee
void delete_employee() {
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
    for (int i = 0; i < n; i++) {
        if (emp[i].id == id) {
            // Store the index of the employee
            index = i;
            break;
        }
    }

    // Check if the employee is found
    if (index == -1) {
        // Display an error message
        printf("\nEmployee not found!\n");
    } else {
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
        if (ch == 'Y' || ch == 'y') {
            // Delete the employee by shifting the array elements
            for (int i = index; i < n - 1; i++) {
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

// Define the function to display all the employees
void display_employees() {
    // Check if there are any employees
    if (n == 0) {
        // Display an error message
        printf("\nNo employees to display!\n");
    } else {
        // Display the employee details
        printf("\nEmployee details:\n");
        for (int i = 0; i < n; i++) {
            printf("\nEmployee %d:\n", i + 1);
            printf("Name: %s\n", emp[i].name);
            printf("ID: %d\n", emp[i].id);
            printf("Department: %s\n", emp[i].dept);
            printf("Gross Salary: %.2f\n", emp[i].salary);
        }
    }

    // Display the main menu
    main_menu();
}

// Define the function to calculate the net salary of an employee
float net_salary(float salary) {
    // Declare a local variable to store the net salary
    float net;

    // Declare a local variable to store the deductions
    float deductions;

    // Declare a local variable to store the allowances
    float allowances;

    // Calculate the deductions as 10% of the gross salary
    deductions = salary * 0.1;

    // Calculate the allowances as 5% of the gross salary
    allowances = salary * 0.05;
    
        // Calculate the net salary as gross salary minus deductions plus allowances
    net = salary - deductions + allowances;

    // Return the net salary
    return net;
}

// Define the function to generate the payroll report of an employee
void payroll_report(struct employee e) {
    // Declare a local variable to store the net salary
    float net;

    // Declare a local variable to store the pay date
    char date[20];

    // Declare a local variable to store the current time
    time_t t;

    // Get the current time
    t = time(NULL);

    // Format the current time as a date string
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
    printf("Pay Date: %s\n", date);
}

// Define the function to save the employee data to a file
void save_data() {
    // Declare a local variable to store the file pointer
    FILE *fp;

    // Open the file in write mode
    fp = fopen("employee.dat", "w");

    // Check if the file is opened successfully
    if (fp == NULL) {
        // Display an error message
        printf("\nError in opening the file!\n");
    } else {
        // Write the number of employees to the file
        fprintf(fp, "%d\n", n);

        // Write the employee details to the file
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%s %d %s %.2f\n", emp[i].name, emp[i].id, emp[i].dept, emp[i].salary);
        }

        // Close the file
        fclose(fp);

        // Display a success message
        printf("\nData saved to the file!\n");
    }
}

// Define the function to load the employee data from a file
void load_data() {
    // Declare a local variable to store the file pointer
    FILE *fp;

    // Open the file in read mode
    fp = fopen("employee.dat", "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        // Display an error message
        printf("\nError in opening the file!\n");
    } else {
        // Read the number of employees from the file
        fscanf(fp, "%d", &n);

        // Read the employee details from the file
        for (int i = 0; i < n; i++) {
            fscanf(fp, "%s %d %s %f", emp[i].name, &emp[i].id, emp[i].dept, &emp[i].salary);
        }

        // Close the file
        fclose(fp);

        // Display a success message
        printf("\nData loaded from the file!\n");
    }
}

// Define the function to display the main menu
void main_menu() {
    // Declare a local variable to store the choice
    int choice;

    // Display the main menu
    printf("\nEmployee Payroll System\n");
    printf("1. Add Employee\n");
    printf("2. Modify Employee\n");
    printf("3. Delete Employee\n");
    printf("4. Display Employees\n");
    printf("5. Generate Payroll Report\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int id,index;

    // Switch on the choice
    switch (choice) {
        case 1:
            // Call the function to add a new employee
            add_employee();
            break;
        case 2:
            // Call the function to modify an existing employee
            modify_employee();
            break;
        case 3:
            // Call the function to delete an existing employee
            delete_employee();
            break;
        case 4:
            // Call the function to display all the employees
            display_employees();
            break;
        case 5:
            index = -1;
            // Prompt the user to enter the employee ID
            printf("\nEnter the ID of the employee for payroll report: ");
            scanf("%d", &id);

            // Search for the employee with the given ID
            for (int i = 0; i < n; i++) {
                if (emp[i].id == id) {
                    // Store the index of the employee
                    index = i;
                    break;
                }
            }

            // Check if the employee is found
            if (index == -1) {
                // Display an error message
                printf("\nEmployee not found!\n");
            } else {
                // Call the function to generate the payroll report of the employee
                payroll_report(emp[index]);
            }

            // Display the main menu
            main_menu();
            break;
        case 6:
            // Exit the program
            exit(0);
            break;
        default:
            // Display an error message
            printf("\nInvalid choice!\n");

            // Display the main menu
            main_menu();
            break;
    }
}
