#include <stdio.h>
#include <string.h>

//loginuser function
void loginuser()
{
    printf("Welcome to Danny Express login page!");

}
//register user function 
void registeruser()
{   
    //declaring the file location
    FILE *pFile; //FILE is a built in pre-defined structure in stdio. *pFile is a pointer to the file
    char fullname[100], email[100], username[50], password[50], confirmpassword[50]; //declaring the maximum lengths

    pFile=fopen("credentials.txt","a");
    if (pFile==NULL) //checking whether the file exists or not
    {
        printf("Error opening the file\n");
        return;
    }

    while (getchar() != '\n'); // Clears leftover newline from option 

    //getting user information
    printf("Enter your full name: ");
    fgets(fullname, sizeof(fullname), stdin); //this allows spaces in full name

    if (fullname[strlen(fullname) - 1] == '\n')  //to remove the newline character from full name
    {
        fullname[strlen(fullname) - 1] = '\0';
    }

    printf("Enter email address: ");
    scanf("%s", &email);

    printf("Enter username: ");
    scanf("%s", &username);

    do //it will keep asking to print password until they match
    {
        printf("Enter password: ");
        scanf("%s", &password);
    
        printf("Confirm Password: ");
        scanf("%s", &confirmpassword);
    
        if (strcmp(password,confirmpassword)!=0) //strcmp compares the two passwords. 
        {                                       //if they're the same they will output 0
            printf("Passwords do not match. Please try again.\n"); //if they're not the same(!=0),this will print
        }
    }while (strcmp(password,confirmpassword)!=0);

    //write user info into the credentials file
    fprintf(pFile, "%-20s | %-15s | %-25s | %-15s\n", fullname, username, email, password); //-20 and -15 is for alignment

    //close the file
    fclose(pFile);

    printf("User registered successfully!\nWelcome to Danny Express.\n");

}

//main menu function
void mainmenu()
{
    int option;
    printf("Welcome to Danny Express!\n1.Login User\n2.Register User\n3.Exit\nOption:");
    scanf("%d",&option);

    while (option!=1 && option!=2 && option!=3)
        {
            printf("Invalid option!\nEnter option: ");
            while (getchar() != '\n'); //this makes sure user input is the int datatype. it won't accept others
            scanf("%d",&option);
        }
    if (option==1)
    {
        loginuser();
    }
    else if (option==2)
    {
        registeruser();
    }
    else if (option==3)
    {
        printf("Exit");
    }
}

//main function 
int main(void)
{
    mainmenu();

    return 0;
}