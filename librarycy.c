#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define max_size 200
#define descp_size 500
struct library
{
    char book_id[max_size];
    char book_name[max_size];
    char author_name[max_size];
    char description[descp_size];
    struct library *next;
};

struct library *head=NULL;

struct student
{
    int student_id;
    int issued_book_id;
};

void add()
{
    FILE *books;
    books=fopen("books.bin","a");
    struct library *new=malloc(sizeof(struct library*));
    char bk_id[max_size];
    char bk_name[max_size],ak_name[max_size],desp[descp_size];
    new->next=NULL;
    printf("Book ID:");
    scanf("%s",bk_id);
    printf("Book Name:");
    fflush(stdin);
    fgets(bk_name,max_size,stdin);
    printf("Author Name:");
    fflush(stdin);
    fgets(ak_name,max_size,stdin);
    printf("Description:");
    fflush(stdin);
    fgets(desp,descp_size,stdin);
    strcpy(new->book_id,bk_id);
    strcpy(new->book_name,bk_name);
    strcpy(new->description,desp);
    strcpy(new->author_name,ak_name);
    fprintf(books,"%s\n",bk_id);
    //fputs(bk_id,books);
    fputs(bk_name,books);
    fputs(ak_name,books);
    fputs(desp,books);
    fclose(books);
    if(head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }
}

void display()//displaying book records
{
    FILE *records;
    char c;
    int count=0;
    records=fopen("books.bin","r");
    char line1[max_size],line2[max_size],line3[max_size],line4[max_size];
    for (c = getc(records); c != EOF; c = getc(records))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    count=count/4;
    rewind(records);
    while(count>0){
            fgets(line1,sizeof(line1),records);
            fgets(line2,sizeof(line2),records);
            fgets(line3,sizeof(line3),records);
            fgets(line4,sizeof(line4),records);
            printf("%s\n",line1);
            printf("%s\n",line2);
            printf("%s\n",line3);
            printf("%s\n",line4);
            count--;
    }
    fclose(records);
}

void search_book()
{
    struct library *t=head;
    char bk_id[max_size];
    printf("\nBook ID :");
    scanf("%s",bk_id);
    while(t!=NULL){
        if(strcmp(t->book_id,bk_id)==0){
            printf("\nBook is found\n\n");
            printf("Book Name\t:%s\n",t->book_name);
            printf("Author Name\t:%s\n",t->author_name);
            printf("Description\t:%s\n",t->description);
        }
        t=t->next;
    }
}

void records_in_structure()
{
    struct library *temp=head;
    struct library *temp2=head;
    int count=0;
    while(temp2!=NULL){
        count++;
        temp2=temp2->next;
    }
    printf("\nBooks Count : %d\n",count);
    while(temp!=NULL){
        printf("\nBook ID :%s\n",temp->book_id);
        printf("Book Name :%s",temp->book_name);
        printf("Author Name:%s",temp->author_name);
        printf("Description :%s\n\n",temp->description);
        temp=temp->next;
    }
}

void delete_from_structure()
{
    char bk_id[max_size];
    printf("\nEnter book ID to be deleted : ");
    scanf("%s",bk_id);
    struct library *temp=head;
    struct library *temp2=head;
    if(temp->next==NULL){
        head=NULL;
    }
    else if(strcmp(temp->book_id,bk_id)==0){
        head=temp->next;
    }
    while ((temp -> next != NULL) && (strcmp(temp -> book_id,bk_id)!=0)){
        temp2 = temp;
        temp = temp -> next;
    }
    if (strcmp(temp->book_id,bk_id)==0) {
        printf("\nElement found\n");
        temp2 -> next = temp -> next;
        free(temp);
    }
    else{
        printf("\nId not found\n");
    }
}

// void swap(struct library *a, struct library *b)
// {
//     strcpy(t1,a->book_id);
//     strcpy(t2,a->book_name);
//     strcpy(t3,a->author_name);
//     strcpy(t4,a->description);
//     strcpy(a->book_id,b->book_id);
//     strcpy(a->book_name,b->book_name);
//     strcpy(a->author_name,b->author_name);
//     strcpy(a->description,b->description);
//     strcpy(b->book_id,t1);
//     strcpy(b->book_name,t2);
//     strcpy(b->author_name,t3);
//     strcpy(b->description,t4);
// }

 void sortList() {  
        //Node current will point to head  
        struct library *current = head, *index = NULL;  
        char t1[max_size],t2[max_size],t3[max_size],t4[max_size];
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->book_id > index->book_id) {
                            strcpy(t1,current->book_id);
                            strcpy(t2,current->book_name);
                            strcpy(t3,current->author_name);
                            strcpy(t4,current->description);
                            strcpy(current->book_id,index->book_id);
                            strcpy(current->book_name,index->book_name);
                            strcpy(current->author_name,index->author_name);
                            strcpy(current->description,index->description);
                            strcpy(index->book_id,t1);
                            strcpy(index->book_name,t2);
                            strcpy(index->author_name,t3);
                            strcpy(index->description,t4);
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  

void welcomeMessage()
{
    system("cls");
    printf("\t\t\t\tEnter any key to continue.....");
    getch();
}

void file_to_structure()
{
    FILE *fp;
    int count=0;
    char c;
    fp=fopen("books.bin","r");
    if(fp){
        char line1[max_size],line2[max_size],line3[max_size],line4[max_size];
        for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
        count=count/4;
        rewind(fp);
        while(count>0){
            struct library *renew=malloc(sizeof(struct library*));
            fgets(line1,sizeof(line1),fp);
            fgets(line2,sizeof(line2),fp);
            fgets(line3,sizeof(line3),fp);
            fgets(line4,sizeof(line4),fp);
            int len = strlen(line1);
            if( line1[len-1] == '\n' )
                line1[len-1] = 0;
            strcpy(renew->book_id,line1);
            strcpy(renew->book_name,line2);
            strcpy(renew->description,line3);
            strcpy(renew->author_name,line4);
            renew->next=NULL;
            if(head==NULL){
                head=renew;
            }
            else{
                renew->next=head;
                head=renew;
            }
            count--;
    }
    }
    fclose(fp);
}

void structure_to_file()
{
    FILE *fp;
    fp=fopen("books.bin","w");
    struct library *t=head;
    printf("hello");
    while(t!=NULL){
        printf("hello2");
        fprintf(fp,"%s\n",t->book_id);
    //fputs(bk_id,books);
        fputs(t->book_name,fp);
        fputs(t->author_name,fp);
        fputs(t->description,fp);
        t=t->next;
    }
    fclose(fp);
}

int library(char user[])
{
    file_to_structure();
    int choice;
    while(1){
        printf("\t\t\t\t---------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tMAIN MENU\n");
        printf("\t\t\t\t---------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tWelcome\t:%s\n",user);
        printf("\nChoice:");
        scanf("%d",&choice);
        if(choice==1){
            add();
        }
        else if(choice==2){
            display();
        }
        else if(choice==3){
            sortList();
            records_in_structure();
        }
        else if(choice==4){
            delete_from_structure();
            structure_to_file();
        }
        else if(choice==5){
            search_book();
        }
        else if(choice==6){}
        else{
            return -1;
        }}
}

void login(int n){
    FILE *users;
    users=fopen("users.bin","r");
    if(n>3){
        printf("\n\t\t\t\ttry later...\n");
        exit(0);//exiting after 4 tries
    }
    if(users){
        //printf("exists");
        char user_id[max_size];
        char password[max_size];
        printf("\n\t\t\t\tUsername\t:");
        fflush(stdin);
        fgets(user_id,max_size,stdin);
        printf("\n\t\t\t\tPassword\t:");
        fflush(stdin);
        fgets(password,max_size,stdin);
        char line1[max_size],line2[max_size],user[max_size];
        int fail;
	    while(!feof(users)){
            fgets(line1,sizeof(line1),users);
            fgets(line2,sizeof(line2),users);
             if((strcmp(line1,user_id)==0)&&(strcmp(line2,password)==0)){
                 strcpy(user,line1);
                 printf("\n\t\t\t\t\t\t\tSuccessful...\n");
                 fail=0;
                 break;
             }
            }
            if(fail!=0){
                 printf("\n\t\t\t\t\t\t\tInvalid username or password...\n");
                 login(++n);
             }
             else{
                 library(user);
             }

        }
    else{
        users=fopen("users.bin","w");//creating a new user login file
        printf("No user details is found\n");
        printf("Creating a user...");
        char user_id[max_size];
        char password[max_size];
        printf("\n\t\t\t\tUsername\t:");
        fflush(stdin);
        fgets(user_id,max_size,stdin);
        printf("\n\t\t\t\tPassword\t:");
        fflush(stdin);
        fgets(password,max_size,stdin);
        fputs(user_id,users);//creating a default user
        fputs(password,users);
        fclose(users);
        login(0);
    }
}

int main()
{
    int choice;
    welcomeMessage();
    login(0);
    return 0;
}