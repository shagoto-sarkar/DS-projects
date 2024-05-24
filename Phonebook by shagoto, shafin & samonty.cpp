#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//defining a structure of a contact
struct node
{
    char firstname[20];
    char lastname[20];
    char number[15];
    struct node *next;
};
struct node *start=NULL;

/*this dynamically allocates memory for the Node */
struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
}

/*This display function traverse through the linked list
    And prints all the elements.*/
void display(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("\n%s\n",temp->firstname);
        printf("%s\n",temp->lastname);
        printf("%s\n\n",temp->number);
        temp=temp->next;
    }
}

/*This function Inserts a new node that holds the contact information at the
end of the Linked list And displays the whole list using the display fuction*/
void insert()
{
    struct node *temp,*nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    printf("\nEnter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%s",&nn->number);
    temp->next=nn;
    nn->next=NULL;
    display(start);
}

/*This function checks if previously any node is present if yes then
it just inserts another node at the end using insert function
But if there is no node present then it creates the first node and displays it. */
struct node *create()
{
    struct node *temp,*nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;
    printf("\nEnter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%s",&nn->number);
    nn->next=NULL;
    display(start);
    }
}
/*This function takes input the first name and the last name to be searched
then traverse through the list and compares it to all the nodes/contacts
and when matched it displays that node*/
void search() {
    struct node *temp;
    char f[20], l[20];
    int found = 0;
    temp = start;
    printf("\nEnter name to be searched:\n");
    scanf("%s %s", f, l);
    while (temp != NULL) {
        if (strcmp(temp->firstname, f) == 0 && strcmp(temp->lastname, l) == 0) {
            printf("\nName: %s %s\n", temp->firstname, temp->lastname);
            printf("Number: %s\n\n", temp->number);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Name not found in the phonebook.\n\n");
    }
}

void del() {
    struct node *temp, *prev;
    char f[20], l[20];
    int found = 0;
    temp = start;
    prev = NULL;

    printf("Enter name to be deleted:\n");
    scanf("%s %s", f, l);

    // Check if the first node needs to be deleted
    if (strcmp(start->firstname, f) == 0 && strcmp(start->lastname, l) == 0) {
        temp = start;
        start = start->next;
        free(temp);
        printf("\nName deleted from the phonebook.\n\n");
        return;
    }

    while (temp != NULL) {
        if (strcmp(temp->firstname, f) == 0 && strcmp(temp->lastname, l) == 0) {
            found = 1;
            prev->next = temp->next;
            free(temp);
            printf("Name deleted from the phonebook.\n\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Name not found in the phonebook.\n\n");
    }
}


int main()
{
    //system("color 57");//this to make console color pink.
    printf("\x1b[32m"); //this is for changing the font color to green.
    printf("*********************************\n");
    printf("*  -------                      * \n");
    printf("*     |                         *  By,\n");
    printf("*     |                         *  Shagoto(295)\n");
    printf("*     |");
    printf("he minimalist Phonebook  *  Samonty(405)\n");
    printf("*                               *  shafin(184)\n");
    printf("*********************************\n");
   // printf("A project by shafin(184), \n  Shagoto(295) & Samonty(405)\n");
    int op,ch;
    do{
        printf("\n--------------Welcome---------------\n");
        printf("1.Create     2.Insert     3.Display\n");
        printf("4.Delete     5.Search     6.Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
            case 6: return 0;

        }
        //printf("\nDo you want to quit ? 1 for no / 0 for yes:");
        //scanf("%d",&op);
        op=1;
    }while(op!=0);
return 0;
}

