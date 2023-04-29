#include<stdio.h>

typedef struct emp
{
    int id;
    char name[50],addr[50],desgn[50],dept[50],jdate[50];
    float salary;
}EMP;

//adding a record

void add_rec()
{
    FILE *fp;
    EMP e;

    fp = fopen("emp.txt", "ab");

    printf("Enter ID: ");
    scanf("%d",&e.id);
    printf("Enter Name: ");
    gets(e.name);
    gets(e.name);
    printf("Enter Address: ");
    gets(e.addr);
    printf("Enter Designation: ");
    gets(e.desgn);
    printf("Enter Department: ");
    gets(e.dept);
    printf("Enter Joining Date (dd-mm-yyyy): ");
    gets(e.jdate);
    printf("Enter Salary: ");
    scanf("%f",&e.salary);

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);   
}

//displaying a record

void display_rec()
{
    FILE *fp;
    EMP e;

    fp = fopen("emp.txt", "rb");

    if(fp==NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    printf("-------------------------------------------------------------------------------\n");
    printf("ID\tName\tAddress\tDesignation\tDepartment\tJoining Date\tSalary\n");
    printf("-------------------------------------------------------------------------------\n");

    while(fread(&e,sizeof(e),1,fp)>0)
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%0.2f\n",
            e.id,e.name,e.addr,e.desgn,e.dept,e.jdate,e.salary);
    }
    printf("-------------------------------------------------------------------------------\n");

    fclose(fp);
}

//searching for record

void search_rec()
{
    FILE *fp;
    EMP e;
    int tid;

    fp = fopen("emp.txt", "rb");

    if(fp==NULL)
    {
        printf("Failed to open the file.\n");
        return;
    }

    printf("Enter ID to be searched: ");
    scanf("%d",&tid);

    while(fread(&e, sizeof(e), 1, fp)>0)
    {
        if(e.id == tid)
        {
            printf("-------------------------------\n");
            printf("ID           :  %d\n",e.id);
            printf("Name         :  %s\n",e.name);
            printf("Address      :  %s\n",e.addr);
            printf("Designation  :  %s\n",e.desgn);
            printf("Department   :  %s\n",e.dept);
            printf("Joining DAte :  %s\n",e.jdate);
            printf("Salary       :  %f\n",e.salary);
            printf("-------------------------------\n");
            break;
        }
    }

    if(feof(fp))
    {
        printf("Employee ID %d not found.\n",tid);
    }

    fclose(fp);
}

//deleting a record

void delete_rec()
{
    FILE *fp1, *fp2;
    int tid, flag=0;
    EMP e;

    fp1 = fopen("emp.txt", "rb");

    if(fp1==NULL)
    {
        printf("Failed to open file. \n");
        return;
    }

    fp2 = fopen("temp.txt", "wb");

    printf("Enter ID to be deleted: ");
    scanf("%d", &tid);

    while(fread(&e, sizeof(e), 1, fp1)>0)
    {
        if(e.id == tid)
        {
            flag = 1;
        }
        else
        {
            fwrite(&e, sizeof(e), 1, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    remove("emp.txt");
    rename("temp.txt","emp.txt");

    if(flag == 1)
    {
        printf("Record deleted successfully\n");
    }
    else
    {
        printf("ID was not found\n");
    }
}

//modifying record

void modify_rec()
{
    FILE *fp1, *fp2;
    int tid, flag=0,mod;
    EMP e;

    fp1 = fopen("emp.txt", "rb");

    if(fp1==NULL)
    {
        printf("Failed to open file. \n");
        return;
    }

    fp2 = fopen("temp.txt", "wb");

    printf("Enter ID to be modified: ");
    scanf("%d", &tid);

    while(fread(&e, sizeof(e), 1, fp1)>0)
    {
        if(e.id == tid)
        {
            flag = 1;

            printf("-------------------------------\n");
            printf("\nCurrent values\n");
            printf("ID           :  %d\n",e.id);
            printf("Name         :  %s\n",e.name);
            printf("Address      :  %s\n",e.addr);
            printf("Designation  :  %s\n",e.desgn);
            printf("Department   :  %s\n",e.dept);
            printf("Joining Date :  %s\n",e.jdate);
            printf("Salary       :  %f\n",e.salary);
            printf("-------------------------------\n");

            printf("-------------------------------\n");
            printf("\n1. Name");
            printf("\n2. Address");
            printf("\n3. Designation");
            printf("\n4. Department");
            printf("\n5. Joining Date");
            printf("\n6. Salary");
            printf("-------------------------------\n");
            printf("\nWhat do you want to modify(1-6): ");
            scanf("%d",&mod);

            switch(mod) {
                case 1:
                    printf("Enter new Name: ");
                    gets(e.name);
                    gets(e.name);
                    break;
                case 2:
                    printf("Enter new Address: ");
                    gets(e.addr);
                    gets(e.addr);
                    break;
                case 3:
                    printf("Enter new Designation: ");
                    gets(e.desgn);
                    gets(e.desgn);
                    break;
                case 4:
                    printf("Enter new Department: ");
                    gets(e.dept);
                    gets(e.dept);
                    break;
                case 5:
                    printf("Enter new Joining Date (dd-mm-yyyy): ");
                    gets(e.jdate);
                    gets(e.jdate);
                    break;  
                case 6:
                    printf("Enter new Salary: ");
                    scanf("%f",&e.salary);
                    scanf("%f",&e.salary);
                    break;
            }


        }
        fwrite(&e,sizeof(e),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);

    remove("emp.txt");
    rename("temp.txt","emp.txt");

    if(flag == 1)
    {
        printf("Record modified successfully\n");
    }
    else
    {
        printf("ID was not found\n");
    }
}

//main function

int main()
{
    int ch;

    do
    {
        printf("\t\t-------------------------------\n");
        printf("\t\t1. Add record\n");
        printf("\t\t2. Search record\n");
        printf("\t\t3. Display all record\n");
        printf("\t\t4. Delete record\n");
        printf("\t\t5. Modify record\n");
        printf("\t\t-------------------------------\n");
        printf("Enter your choice(1-5): ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                add_rec();
                break;
            case 2:
                search_rec();
                break;
            case 3:
                display_rec();
                break;
            case 4:
                delete_rec();
                break;
            case 5:
                modify_rec();
                break;
            default:
                printf("Enter a valid choice (1-5)\n");
                break;
        }

    }while(ch>0);

    return 0;
}