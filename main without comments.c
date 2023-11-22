#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct employee {
    char name[500];
    int id;
    char dept[20];
    float salary;
};

struct employee emp[100];
int n = 0;

void welcome();
void bye();
void add_employee();
void modify_employee();
void delete_employee();
void display_employees();
float net_salary(float salary);
float tax(float salary);
void payroll_report(struct employee e);
void generate_payroll_slip(struct employee e);
void save_data();
void load_data();
void main_menu();

int main() {
    welcome();
    load_data();
    main_menu();
    bye();
    return 0;
}

void welcome() {
    printf("Welcome to the Employee Payroll System!\n");
    printf("Developed by:\n");
    printf("-> Rohan Batra\n");
    printf("-> Shubham Rawat\n");
    printf("\nPurpose of the App:\n");
    printf("This application allows you to manage employee payroll information.\n");
    printf("You can add, modify, delete employees, generate payroll reports, and more.\n\n");
}

void bye() {
    printf("\n\nBYE");
    printf("\nThank you for using the application");
    printf("\nFind the project at github:https://github.com/MrRohanBatra/Employee-Payroll-System\n");
}

void add_employee() {
    char ch;
    char first[50], last[50], name[100];
    do {
        n++;
        printf("\nEnter the details of employee %d:\n", n);
        printf("Name: ");
        scanf("%s %s", first, last);
        strcat(first, " ");
        strcat(first, last);
        strcpy(emp[n - 1].name, first);
        printf("ID: ");
        scanf("%d", &emp[n - 1].id);
        printf("Department: ");
        scanf("%s", emp[n - 1].dept);
        printf("Gross Salary: ");
        scanf("%f", &emp[n - 1].salary);
        printf("\nDo you want to add another employee? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    save_data();
    main_menu();
}

void modify_employee() {
    int id;
    int index = -1;
    char ch;
    printf("\nEnter the ID of the employee to be modified: ");
    scanf("%d", &id);
    int i;
    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nEmployee not found!\n");
    } else {
        printf("\nEmployee details:\n");
        printf("Name: %s\n", emp[index].name);
        printf("ID: %d\n", emp[index].id);
        printf("Department: %s\n", emp[index].dept);
        printf("Gross Salary: %.2f\n", emp[index].salary);
        printf("\nDo you want to modify this employee? (Y/N): ");
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y') {
            printf("\nEnter the new details of employee %d:\n", index + 1);
            printf("Name: ");
            char first[50], last[50];
            scanf("%s %s", first, last);
            strcat(first, " ");
            strcat(first, last);
            strcpy(emp[index].name, first);
            printf("ID: ");
            scanf("%d", &emp[index].id);
            printf("Department: ");
            scanf("%s", emp[index].dept);
            printf("Gross Salary: ");
            scanf("%f", &emp[index].salary);
            printf("\nEmployee modified successfully!\n");
            save_data();
        }
    }
    main_menu();
}

void delete_employee() {
    int id;
    int index = -1;
    char ch;
    printf("\nEnter the ID of the employee to be deleted: ");
    scanf("%d", &id);
    int i;
    for (i = 0; i < n; i++) {
        if (emp[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nEmployee not found!\n");
    } else {
        printf("\nEmployee details:\n");
        printf("Name: %s\n", emp[index].name);
        printf("ID: %d\n", emp[index].id);
        printf("Department: %s\n", emp[index].dept);
        printf("Gross Salary: %.2f\n", emp[index].salary);
        printf("\nDo you want to delete this employee? (Y/N): ");
        scanf(" %c", &ch);
        if (ch == 'Y' || ch == 'y') {
            int i;
            for (i = index; i < n - 1; i++) {
                emp[i] = emp[i + 1];
            }
            n--;
            printf("\nEmployee deleted successfully!\n");
            save_data();
        }
    }
    main_menu();
}

void display_employees() {
    if (n == 0) {
        printf("\nNo employees to display!\n");
    } else {
        printf("\nEmployee details:\n");
        int i;
        for (i = 0; i < n; i++) {
            printf("\nEmployee %d:\n", i + 1);
            printf("----------------------------------\n");
            printf("Name: %s\n", emp[i].name);
            printf("ID:%d\n", emp[i].id);
            printf("Department: %s\n", emp[i].dept);
            printf("Gross Salary: %.2f\n", emp[i].salary);
            printf("----------------------------------\n");
        }
    }
    main_menu();
}

float net_salary(float salary) {
    float net;
    float deductions;
    float allowances;
    deductions = salary * 0.1;
    allowances = salary * 0.05;
    net = salary - deductions + allowances;
    return net;
}

float tax(float salary) {
    float tax;
    if (salary <= 500000) {
        tax = 0.1 * salary;
    } else if (salary > 500000 && salary <= 1000000) {
        tax = 50000 + (salary - 500000) * 0.2;
    } else if (salary > 100000) {
        tax = 150000 + (salary - 1000000) * 0.3;
    }
    return tax;
}

void payroll_report(struct employee e) {
    float net;
    char date[20];
    time_t t;
    t = time(NULL);
    strftime(date, 20, "%d-%m-%Y", localtime(&t));
    net = net_salary(e.salary);
    printf("\nPayroll Report of Employee %d:\n", e.id);
    printf("----------------------------------\n");
    printf("Name: %s\n", e.name);
    printf("ID: %d\n", e.id);
    printf("Department: %s\n", e.dept);
    printf("----------------------------------\n");
    printf("Gross Salary: %.2f\n", e.salary);
    printf("Net Salary: %.2f\n", net);
    printf("Tax Payable: %.2f\n", tax(net));
    printf("----------------------------------\n");
    printf("Pay Date: %s\n", date);
    printf("----------------------------------\n");
}

void generate_payroll_slip(struct employee e) {
    float net;
    char date[20];
    time_t t;
    t = time(NULL);
    strftime(date, 20, "%d-%m-%Y", localtime(&t));
    net = net_salary(e.salary);
    FILE *fp;
    fp = fopen("payroll_slip.txt", "w");
    if (fp == NULL) {
        printf("\nError in opening the file!\n");
    } else {
        fprintf(fp, "Payroll Slip\n");
        fprintf(fp, "-------------------------\n");
        fprintf(fp, "Employee Name: %s\n", e.name);
        fprintf(fp, "Employee ID: %d\n", e.id);
        fprintf(fp, "Department: %s\n", e.dept);
        fprintf(fp, "Gross Salary: %.2f\n", e.salary);
        fprintf(fp, "-------------------------\n");
        fprintf(fp, "Net Salary: %.2f\n", net_salary(e.salary));
        fprintf(fp, "Tax Payable: %.2f\n", tax(net));
        fprintf(fp, "-------------------------\n");
        fclose(fp);
        printf("\nPayroll Slip generated and saved to 'payroll_slip.txt'!\n");
    }
}

void save_data() {
    FILE *fp;
    fp = fopen("employee.dat", "w");
    if (fp == NULL) {
        printf("\nError in opening the file!\n");
    } else {
        fprintf(fp, "%d\n", n);
        int i;
        for (i = 0; i < n; i++) {
            fprintf(fp, "%s %d %s %.2f\n", emp[i].name, emp[i].id, emp[i].dept, emp[i].salary);
        }
        fclose(fp);
        printf("\nData saved to the file!\n");
    }
}

void load_data() {
    FILE *fp;
    fp = fopen("employee.dat", "r");
    if (fp == NULL) {
        printf("\nError in opening the file!\n");
    } else {
        fscanf(fp, "%d", &n);
        int i;
        char first[50], last[50];
        for (i = 0; i < n; i++) {
            fscanf(fp, "%s %s %d %s %f", first, last, &emp[i].id, emp[i].dept, &emp[i].salary);
            strcat(first, " ");
            strcat(first, last);
            strcpy(emp[i].name, first);
        }
        fclose(fp);
        printf("\nSystem Check successful!\nStarting........\n");
    }
}

void main_menu() {
    int choice;
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
    int id, index;
    switch (choice) {
        case 1:
            add_employee();
            break;
        case 2:
            modify_employee();
            break;
        case 3:
            delete_employee();
            break;
        case 4:
            display_employees();
            break;
        case 5:
            index = -1;
            printf("\nEnter the ID of the employee for tax report: ");
            scanf("%d", &id);
            int i;
            for (i = 0; i < n; i++) {
                if (emp[i].id == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("\nEmployee not found!\n");
            } else {
                float tax1 = tax(net_salary(emp[index].salary));
                printf("\nTax Payable: %.2f\n", tax1);
            }
            main_menu();
            break;
        case 6:
            index = -1;
            printf("\nEnter the ID of the employee for payroll report: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++) {
                if (emp[i].id == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("\nEmployee not found!\n");
            } else {
                payroll_report(emp[index]);
            }
            main_menu();
            break;
        case 7:
            index = -1;
            printf("\nEnter the ID of the employee for payroll slip generation: ");
            scanf("%d", &id);
            for (i = 0; i < n; i++) {
                if (emp[i].id == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("\nEmployee not found!\n");
            } else {
                generate_payroll_slip(emp[index]);
            }
            main_menu();
            break;
        case 8:
            bye();
            exit(0);
            break;
        default:
            printf("\nInvalid choice!\n");
            main_menu();
            break;
    }
}

