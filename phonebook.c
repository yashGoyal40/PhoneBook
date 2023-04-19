#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_contacts 100

void add_a_contact();
void view_all_contact();
void edit_a_contact();
void search_contact();
void delete_contact();
FILE *fp;
struct contact{
    char name[45];
    char address[100];
    char phone[20];
    char email[50];
};

struct contact contacts[max_contacts];
int num_contacts = 0;

void print_statement(){
    printf("\n\n/././././././././././././././././././\n");
    printf("/.  Phonebook Management System    ./\n");
    printf("/.  1. Add a contact               ./\n");
    printf("/.  2. View all contacts           ./\n");
    printf("/.  3. Edit a contact              ./\n");
    printf("/.  4. Search for a contact        ./\n");
    printf("/.  5. Delete a contact            ./\n");
    printf("/.  6. Exit                        ./\n");
    printf("/././././././././././././././././././\n\n");

}


int main(){
    int a;
    do{
    print_statement();
    printf("enter your choice: ");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        add_a_contact();
        break;
    case 2:
        view_all_contact();
        break;
    case 3:
        edit_a_contact();
        break;
    case 4:
        search_contact();
        break;
    case 5:
        delete_contact();
        break;
    case 6:
        printf("exiting the program........");
        break;
    default:
        printf("invalid choice");
        break;
    }
    }while(a!=6);
}


void add_a_contact(){
    fp = fopen("contacts.txt","a");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return;
    }
    printf("Enter Name[UNIQUE]: ");
    scanf("%s",contacts[num_contacts].name);

    printf("Enter Address: ");
    scanf("%s",contacts[num_contacts].address);

    printf("Enter Phone: ");
    scanf("%s",contacts[num_contacts].phone);

    printf("Enter Email: ");
    scanf("%s",contacts[num_contacts].email);
   
    fprintf(fp, "%s %s %s %s\n", contacts[num_contacts].name, contacts[num_contacts].address, contacts[num_contacts].phone, contacts[num_contacts].email);
    num_contacts++;
    fclose(fp);
    return;
}


void view_all_contact(){
    fp=fopen("contacts.txt","r");
    if(fp==NULL){
        printf("No saved contacts found.\n");
        return;
    }
    printf("Name\t\tAddress\t\tPhone\t\tEmail\n");
    printf("---------------------------------------------------------------\n");
    char c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        if(c==' '){
            printf("\t\t");
        }
        c = fgetc(fp);
    }
    fclose(fp);
    return;
}


void edit_a_contact(){
    char name[45];
    printf("Enter name of the contact to edit: ");
    scanf("%s", name);
    
    fp = fopen("contacts.txt","r");
    if(fp==NULL){
        printf("No saved contacts found.\n");
        return;
    }

    num_contacts = 0;
    char file_name[45], file_address[100], file_phone[15], file_email[45];
    while(fscanf(fp, "%s %s %s %s", file_name, file_address, file_phone, file_email) != EOF){
        strcpy(contacts[num_contacts].name, file_name);
        strcpy(contacts[num_contacts].address, file_address);
        strcpy(contacts[num_contacts].phone, file_phone);
        strcpy(contacts[num_contacts].email, file_email);
        num_contacts++;
    }

    fclose(fp);

    int contact_index = -1;
    for(int i=0;i<num_contacts;i++){
        if(strcmp(name,contacts[i].name)==0){
            contact_index=i;
            break;
        }
    }

    if(contact_index == -1){
        printf("Contact not found.\n");
        return;
    }
    
    printf("Contact found. Enter new information:\n");
    printf("Enter Name[UNIQUE]: ");
    scanf("%s", contacts[contact_index].name);

    printf("Enter Address: ");
    scanf("%s", contacts[contact_index].address);

    printf("Enter Phone: ");
    scanf("%s", contacts[contact_index].phone);

    printf("Enter Email: ");
    scanf("%s", contacts[contact_index].email);
    

    fp = fopen("contacts.txt","w");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < num_contacts; i++){
        fprintf(fp, "%s %s %s %s\n", contacts[i].name, contacts[i].address, contacts[i].phone, contacts[i].email);
    }
    fclose(fp);

}
   

void search_contact(){
    char name[45];
    printf("Enter name of the contact to search: ");
    scanf("%s", name);
    
    fp = fopen("contacts.txt","r");
    if(fp==NULL){
        printf("No saved contact found.\n");
        return;
    }

    num_contacts = 0;
    char file_name[45], file_address[100], file_phone[15], file_email[45];
    while(fscanf(fp, "%s %s %s %s", file_name, file_address, file_phone, file_email) != EOF){
        strcpy(contacts[num_contacts].name, file_name);
        strcpy(contacts[num_contacts].address, file_address);
        strcpy(contacts[num_contacts].phone, file_phone);
        strcpy(contacts[num_contacts].email, file_email);
        num_contacts++;
    }
     fclose(fp);

    int contact_index = -1;
    for(int i=0;i<num_contacts;i++){
        if(strcmp(name,contacts[i].name)==0){
            contact_index=i;
            break;
        }
    }

    if(contact_index == -1){
        printf("Contact not found.\n");
        return;
    }
    printf("Name\t\tAddress\t\tPhone\t\tEmail\n");
    printf("---------------------------------------------------------------\n");
    printf("%s\t\t%s\t\t%s\t\t%s\n", contacts[contact_index].name, contacts[contact_index].address, contacts[contact_index].phone, contacts[contact_index].email);
    return;
}


void delete_contact(){
    char name[50];
    printf("Enter name of contact to delete: ");
    scanf("%s", name);

    fp = fopen("contacts.txt","r");
    if(fp==NULL){
        printf("No saved contact found.\n");
        return;
    }

    num_contacts = 0;
    char file_name[45], file_address[100], file_phone[15], file_email[45];
    while(fscanf(fp, "%s %s %s %s", file_name, file_address, file_phone, file_email) != EOF){
        strcpy(contacts[num_contacts].name, file_name);
        strcpy(contacts[num_contacts].address, file_address);
        strcpy(contacts[num_contacts].phone, file_phone);
        strcpy(contacts[num_contacts].email, file_email);
        num_contacts++;
    }
    fclose(fp);

    int contact_index = -1;
    for(int i=0;i<num_contacts;i++){
        if(strcmp(name,contacts[i].name)==0){
            contact_index=i;
            break;
        }
    }

    if(contact_index == -1){
        printf("Contact not found.\n");
        return;
    }

    fp = fopen("contacts.txt","w");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return;
    }

    for(int i = 0; i < num_contacts; i++){
        if(contacts[i].phone == contacts[contact_index].phone){
            continue;
        }
        else{
            fprintf(fp, "%s %s %s %s\n", contacts[i].name, contacts[i].address, contacts[i].phone, contacts[i].email);
        }
    }
    fclose(fp);
    return;
}
