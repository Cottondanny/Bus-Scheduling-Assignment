#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//email validation
bool validate_email(const char* email) //boolean datatype to check true or false 
{
    int length=strlen(email); //declaring length here just to check email length
    bool has_at = false; //declares false at first because we haven't found the at yet
    bool has_dot_after_at = false; //same as before
    int at_position = -1; //this can be int at_position; but put -1 for good practice;

    if (length < 5) //setting minimum length for email
    {
        return false; //email cannot be less than 5 characters
    }
    for (int i = 0; i<length; i++) //we will find the @ now
    {
        if (email[i]=='@') //if we have found the @ in the email
        {
            if(has_at) //but the email already has an @ it'll return false
            {
                return false;
            }
            has_at = true; //if not, then it will return true
            at_position = i; //and set the position of the @ to at_position variable

            if (i==0) //if the @ position is at the front it'll return false
            {
                return false;
            }
        }else if (email[i]=='.' && has_at) //if we have found the at, and there's a dot
        {
            has_dot_after_at = true; //this will be true 
        }
    }
    if (!has_at || !has_dot_after_at)
    {
        return false;
    }
    return true;
}



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

    bool valid;
    do {
        printf("Enter email address: ");
        scanf("%s", &email); 
    
        valid = validate_email(email); // Store result in a variable
        if (!valid) {
            printf("Invalid email format. Please enter a valid email address.\n");
        }
    } while (!valid); // Use stored result in the loop condition
    
    
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
