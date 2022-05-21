#include <stdio.h>
#include <string.h>
// deneme için 3 yazdık 100 yazarak değiştirebiliriz
#define SIZE 3

// software engineering bölümü
struct seng
{

    int ID;
    int password;
    int AKTS;
    char name[20];
    char surname[20];

    int yzm;
    int mat;
    int programming;
    int physics;

} Seng_student[SIZE];

// computer engineering bölümü
struct ceng
{

    int ID;
    int password;
    int AKTS;
    char name[20];
    char surname[20];

    int com101;
    int mat;
    int hardware;
    int programming;

} Ceng_student[SIZE];

// machine engieering bölümü
struct meng
{

    int ID;
    int password;
    int AKTS;
    char name[20];
    char surname[20];

    int machine;
    int mat;
    int physics;
    int mukavemet;

} Meng_student[SIZE];

struct associate
{

    char name[20];
    char surname[20];
    int id;
    int password;
    char lesson[20];

} Associate[4];

FILE *associateFile;
FILE *studentFile;
FILE *officerFile;
FILE *documentStudent;

int admin_function();
int officer_function();
int associate_function();
int student_function();
void menu();

int main()
{
    menu();
}

void menu()
{

    int menu_option = 0;
    printf("For the admin access ------> 1\nFor the officer access ------> 2\nFor the associate access ------>3\nFor the student access ------>4\n\n");
    scanf("%d", &menu_option);

    switch (menu_option)
    {
    case 1:
        admin_function();
        break;
    case 2:
        officer_function();
        break;
    case 3:
        associate_function();
        break;
    case 4:
        student_function();
        break;

    default:
        printf("Wrong entry");
    }
}

int admin_function()
{

    int adminPassword = 3264;
    int officerPassword = 0;
    int adminOption = 0;
    int officerId = 0;
    int assignOption = 0;

    printf("Welcome to the system admin!\n\nPlease enter your password\n\n");
    scanf("%d", &adminPassword);

    if (adminPassword == 3264)
    {

        printf("Login is succesful ! \n\n ");

        printf("If you want assign associate enter 1, If you want assign officer enter 2: ");
        scanf("%d", &assignOption);

        switch (assignOption)
        {
        case 1:
            for (int i = 0; i < 4; i++)
            {

                char file_name[20] = "associate";
                char converter[20];

                // associate1, associate2 diye giden dosyalar olusturmak icin boyle bir yontem kullaniyorum
                sprintf(converter, "%d%s", i + 1, ".txt");
                strcat(file_name, converter);

                associateFile = fopen(file_name, "a+");

                // hoca bilgilerinin girildigi yer
                printf("Associate %d's id: ", i + 1);
                scanf("%d", &Associate[i].id);
                printf("Associate %d's name: ", i + 1);
                scanf("%s", Associate[i].name);
                printf("Associate %d's surname: ", i + 1);
                scanf("%s", Associate[i].surname);
                printf("Associate %d's password: ", i + 1);
                scanf("%d", &Associate[i].password);
                // fprintf(associateFile, "%s\n\n", "Associate's ID -- Associate's Pass -- Associate's Name -- Associate's Surname");
                fprintf(associateFile, "\n%5d %20d %23s %25s\n", Associate[i].id, Associate[i].password, Associate[i].name, Associate[i].surname);

                fclose(associateFile);
            }

            printf("Associates assigns are succesful!\n\nPlease assign officer\n\n");
            break;

        case 2:

            officerFile = fopen("officer.txt", "a+");
            // memur bilgilerinin girildigi yer
            printf("Assign officer's id: ");
            scanf("%d", &officerId);
            printf("Assign officer's password: ");
            scanf("%d", &officerPassword);

            fprintf(officerFile, "%d %d", officerId, officerPassword);

            fclose(officerFile);

            break;
        }

        printf("That's it! If you wanna go back to main menu please enter 1: ");
        scanf("%d", &adminOption);

        if (adminOption == 1)
        {
            menu();
        }
    }
}

int officer_function()
{

    int officerOption = 0;
    char tempStudent[20];
    char copyName[20];
    int tempOfficerID = 0;
    int tempOfficerPassword = 0;
    int getOfficerID = 0;
    int getOfficerPassword = 0;
    int assignOption = 0;

    printf("Please enter your ID: \n");
    scanf("%d", &getOfficerID);
    printf("Please enter your password: ");
    scanf("%d", &getOfficerPassword);

    officerFile = fopen("officer.txt", "a+");

    while (!feof(officerFile))
    {
        // officer.txt icindeki verileri okutup karsilastirma yapilacak
        fscanf(officerFile, "%d%d", &tempOfficerID, &tempOfficerPassword);

        if (tempOfficerID == getOfficerID && tempOfficerPassword == getOfficerPassword)
        {

            printf("Login is succesfull Mr. Officer! \n\n");
            printf("If you want to assign Associate's lessons enter 1, if you want enroll a student enter 2: ");
            scanf("%d", &assignOption);

            switch (assignOption)
            {

            case 1:
                for (int i = 0; i < 4; i++)
                {
                    officerFile = fopen("officer.txt", "a+");

                    // ogretmenlere sirasi ile ders verme
                    printf("What is the %d. Associate's lessons ? (Choose two lessons): \n", i + 1);
                    printf("yzm, mat,com,programming, physics, hardware,  machine1,  mukavemet\n");
                    scanf("%s", Associate[i].lesson);

                    char file_name[20] = "associate";
                    char converter[20];

                    sprintf(converter, "%d%s", i + 1, ".txt");
                    strcat(file_name, converter);

                    associateFile = fopen(file_name, "a+");

                    fprintf(associateFile, "\n\n%s ", Associate[i].lesson);

                    scanf("%s", Associate[i].lesson);

                    fprintf(associateFile, " %s ", Associate[i].lesson);
                    fclose(associateFile);
                }
                break;

            case 2:
                // seng -> Software Engineering, ceng -> Computer Engineering, meng -> Mechanical Engineering
                printf("\nDepartments are seng, ceng and meng\n");

                for (int i = 0; i < SIZE; i++)
                {
                    char file_name2[20] = "student";
                    char converter[20];

                    printf("Please assign %d. student's department: ", i + 1);
                    scanf("%s", tempStudent);

                    if (strcmp(tempStudent, "seng") == 0)
                    {
                        // ogrenci kayit islemi
                        printf("Please assign %d. student's name: ", i + 1);
                        scanf("%s", Seng_student[i].name);
                        strcpy(copyName, Seng_student[i].name);
                        studentFile = fopen(strcat(copyName, ".txt"), "a+");

                        printf("Please assign %s's surname: ", Seng_student[i].name);
                        scanf("%s", Seng_student[i].surname);
                        printf("Please assing %s's id: ", Seng_student[i].name);
                        scanf("%d", &Seng_student[i].ID);
                        printf("Please assing %s's password: ", Seng_student[i].name);
                        scanf("%d", &Seng_student[i].password);
                        fprintf(studentFile, "seng \n%s%8s%11d%15d", Seng_student[i].name, Seng_student[i].surname, Seng_student[i].ID, Seng_student[i].password);
                        fclose(studentFile);
                    }

                    else if (strcmp(tempStudent, "ceng") == 0)
                    {
                        // computer engineeringe ogrenci kayidi
                        printf("Please assign %d. student's name: ", i + 1);
                        scanf("%s", Ceng_student[i].name);
                        strcpy(copyName, Ceng_student[i].name);

                        studentFile = fopen(strcat(copyName, ".txt"), "a+");

                        printf("Please assign %s's surname: ", Ceng_student[i].name);
                        scanf("%s", Ceng_student[i].surname);
                        printf("Please assing %s's id: ", Ceng_student[i].name);
                        scanf("%d", &Ceng_student[i].ID);
                        printf("Please assing %s's password: ", Ceng_student[i].name);
                        scanf("%d", &Ceng_student[i].password);
                        fprintf(studentFile, "ceng \n%s%8s%11d%15d", Ceng_student[i].name, Ceng_student[i].surname, Ceng_student[i].ID, Ceng_student[i].password);
                        fclose(studentFile);
                    }

                    else if (strcmp(tempStudent, "meng") == 0)
                    {
                        // mechanical engineeringe ogrenci kayiti
                        printf("Please assign %d. student's name: ", i + 1);
                        scanf("%s", Meng_student[i].name);
                        strcpy(copyName, Meng_student[i].name);

                        studentFile = fopen(strcat(copyName, ".txt"), "a+");

                        printf("Please assign %s's surname: ", Meng_student[i].name);
                        scanf("%s", Meng_student[i].surname);
                        printf("Please assing %s's id: ", Meng_student[i].name);
                        scanf("%d", &Meng_student[i].ID);
                        printf("Please assing %s's password: ", Meng_student[i].name);
                        scanf("%d", &Meng_student[i].password);
                        fprintf(studentFile, "meng \n%s%8s%11d%15d", Meng_student[i].name, Meng_student[i].surname, Meng_student[i].ID, Meng_student[i].password);
                        fclose(studentFile);
                    }

                    else
                    {
                        printf("Wrong entry");
                    }
                }
                break;
            }

            printf("\nIf you wanna go back to main menu please enter 1: ");
            scanf("%d", &officerOption);

            if (officerOption == 1)
            {
                menu();
            }

            else
            {

                break;
            }

            fclose(officerFile);
        }
    }
}

int associate_function()
{

    int getAssociateId = 0;
    int getAssociatePassword = 0;
    int tempAssociateId = 0;
    int midTerm = 0;
    int final = 0;
    char tempDepartment[20];
    int tempAssociatePassword = 0;
    char associateName[20];
    char associateSurname[20];
    char getStudentName[20];
    int hold = 0;

    printf("\nWelcome to the system associate! Please enter your ID: ");
    scanf("%d", &getAssociateId);

    printf("\nPlease enter your password: ");
    scanf("%d", &getAssociatePassword);

    for (int i = 0; i < 4; i++)
    {

        char file_name[20] = "associate";
        char converter[20];
        char copyName[20];
        char lesson1[20];
        char lesson2[20];

        sprintf(converter, "%d%s", i + 1, ".txt");
        strcat(file_name, converter);

        associateFile = fopen(file_name, "a+");

        while (!feof(associateFile))
        {

            fscanf(associateFile, "%d%d%s%s%s%s", &tempAssociateId, &tempAssociatePassword, associateName, associateSurname, lesson1, lesson2);
            if (tempAssociateId == getAssociateId && tempAssociatePassword == getAssociatePassword)
            {
                printf("\nWelcome to the system Mr. %s\n\n", associateName);

                printf("Please enter the name of student: ");
                scanf("%s", getStudentName);
                // ogrencinin adinda dosya acacagim icin copyasini aldim.
                strcpy(copyName, getStudentName);

                strcat(copyName, ".txt");

                studentFile = fopen(copyName, "a+");

                while (!feof(studentFile))
                {
                    fscanf(studentFile, "%s", tempDepartment);

                    if (strcmp(tempDepartment, "seng") == 0)
                    {

                        printf("Please enter %s's %s midterm grade: ", getStudentName, lesson1);
                        scanf("%d", &midTerm);
                        printf("Please enter %s's %s final grade: ", getStudentName, lesson1);
                        scanf("%d", &final);

                        int grade = (midTerm * 40 / 100) + (final * 60 / 100);

                        documentStudent = fopen(strcat(getStudentName, "Document"), "a+");

                        fprintf(documentStudent, "%s %d %d %d",lesson1, midTerm, final, grade);

                        fclose(documentStudent);
                        if (grade >= 60)
                        {
                            Seng_student[0].AKTS += 5;
                        }

                        menu();
                    }
                    else if (strcmp(tempDepartment, "meng") == 0)
                    {
                        printf("Please enter %s's %s midterm grade: ", getStudentName, lesson2);
                        scanf("%d", &midTerm);
                        printf("Please enter %s's %s final grade: ", getStudentName, lesson2);
                        scanf("%d", &final);

                        int grade = (midTerm * 40 / 100) + (final * 60 / 100);
                        documentStudent = fopen(strcat(getStudentName, "Document"), "a+");

                        fprintf(documentStudent, "%s,%d %d %d",lesson1, midTerm, final, grade);
                        fclose(documentStudent);

                        if (grade >= 60)
                        {
                            Meng_student[0].AKTS += 5;
                        }
                        menu();
                    }

                    else if (strcmp(tempDepartment, "ceng") == 0)
                    {
                        printf("Please enter %s's %s midterm grade: ", getStudentName, lesson1);
                        scanf("%d", &midTerm);
                        printf("Please enter %s's %s final grade: ", getStudentName, lesson1);
                        scanf("%d", &final);

                        int grade = (midTerm * 40 / 100) + (final * 60 / 100);
                        documentStudent = fopen(strcat(getStudentName, "Document"), "a+");

                        fprintf(documentStudent, "%s %d %d %d",lesson1, midTerm, final, grade);
                        fclose(documentStudent);

                        if (grade >= 60)
                        {
                            Ceng_student[0].AKTS += 5;
                        }
                        menu();
                    }
                }
                fclose(studentFile);
            }
        }
    }
}

int student_function()
{
    char studentName[20];
    char copyName[20];
    int password = 0;
    int tempPass = 0;
    int option = 0;
    char lesson[20];
    char midTerm[20];
    int grade, final, midterm = 0;
    char name[20];
    char department[20];
    char surname[20];
    int ID;

    printf("Welcome to the system student. Enter your name: ");
    scanf("%s", studentName);
    printf("\nPlease enter your password: ");
    scanf("%d", &password);

    strcpy(copyName, studentName);
    strcat(copyName, ".txt");

    studentFile = fopen(copyName, "a+");

    while (!feof(studentFile))
    {

        fscanf(studentFile, "%s%s%s%d%d", department, name, surname, &ID, &tempPass);

        if (tempPass == password)
        {

            printf("\nLogin is succesfull Mr. %s", studentName);
            printf("\nIf you wanna see your grades please enter 1, if you wanna see your document enter 2: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                strcat(studentName, "Document");

                documentStudent = fopen(studentName, "a+");

                printf("%s", studentName);
                while (!feof(documentStudent))
                {

                    fscanf(documentStudent, "%s%d%d%d",lesson, &midterm, &final, &grade);
                    printf("bu ne");
                }
                fclose(documentStudent);

                printf("\n\n%s's midterm: %d\n%s's final: %d\n%s grade: %d", lesson, midterm,lesson,final,lesson,grade);
                break;
            }
        }
    }
    fclose(studentFile);
}
