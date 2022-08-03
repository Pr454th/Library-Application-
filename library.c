#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#define max_size 200
#define descp_size 500
struct library
{
    int book_id;
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
    int dd,mm,yyyy;
    struct student *next;
};

struct student *shead=NULL;

void add()
{
    FILE *books;
    books=fopen("books.txt","a");
    struct library *new=(struct library*)malloc(sizeof(struct library));
    int bk_id;
    char bk_name[max_size],ak_name[max_size],desp[descp_size];
    new->next=NULL;
    printf("\t\t\t\t\t\t\tNew Book\n");
    printf("\t\t\t\t\tBook ID\t\t:");
    scanf("%d",&bk_id);
    printf("\t\t\t\t\tBook Name\t:");
    fflush(stdin);
    fgets(bk_name,max_size,stdin);
    printf("\t\t\t\t\tAuthor Name\t:");
    fflush(stdin);
    fgets(ak_name,max_size,stdin);
    printf("\t\t\t\t\tDescription\t:");
    fflush(stdin);
    fgets(desp,descp_size,stdin);
    new->book_id=bk_id;
    strcpy(new->book_name,bk_name);
    strcpy(new->description,desp);
    strcpy(new->author_name,ak_name);
    fprintf(books,"%d\n",bk_id);
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

// void display()//displaying book records
// {
//     FILE *records;
//     char c;
//     int count=0;
//     records=fopen("books.txt","r");
//     char line1[max_size],line2[max_size],line3[max_size],line4[max_size];
//     for (c = getc(records); c != EOF; c = getc(records))
//         if (c == '\n') // Increment count if this character is newline
//             count = count + 1;
//     count=count/4;
//     rewind(records);
//     while(count>0){
//             fgets(line1,sizeof(line1),records);
//             fgets(line2,sizeof(line2),records);
//             fgets(line3,sizeof(line3),records);
//             fgets(line4,sizeof(line4),records);
//             printf("%s\n",line1);
//             printf("%s\n",line2);
//             printf("%s\n",line3);
//             printf("%s\n",line4);
//             count--;
//     }
//     fclose(records);
// }

void search_book()
{
    struct library *t=head;
    int bk_id,flag=0;
    printf("\n\t\t\t\t\tBook ID\t\t:");
    scanf("%d",&bk_id);
    while(t!=NULL){
        if(t->book_id==bk_id){
            printf("\n\t\t\t\t\tBook is found\n\n");
            printf("\t\t\t\t\tBook Name\t:%s\n",t->book_name);
            printf("\t\t\t\t\tAuthor Name\t:%s\n",t->author_name);
            printf("\t\t\t\t\tDescription\t:%s\n",t->description);
            flag=1;
        }
        t=t->next;
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\tBook not found\n\n");
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
    printf("\n\t\t\t\t\tBooks Count : %d\n",count);
    while(temp!=NULL){
        printf("\n\t\t\t\t\tBook ID\t\t:%d\n",temp->book_id);
        printf("\t\t\t\t\tBook Name\t:%s",temp->book_name);
        printf("\t\t\t\t\tAuthor Name\t:%s",temp->author_name);
        printf("\t\t\t\t\tDescription\t:%s\n\n",temp->description);
        temp=temp->next;
    }
}

void delete_from_structure()
{
    int bk_id;
    printf("\n\t\t\t\t\tEnter book ID\t\t:");
    scanf("%d",&bk_id);
    struct library *temp=head;
    struct library *temp2=head;
    if(temp->next==NULL){
        head=NULL;
    }
    else if(temp->book_id==bk_id){
        head=temp->next;
    }
    while ((temp -> next != NULL) && (temp -> book_id!=bk_id)){
        temp2 = temp;
        temp = temp -> next;
    }
    if (temp->book_id==bk_id) {
        printf("\n\t\t\t\t\t\tSuccessful...\n");
        temp2 -> next = temp -> next;
        free(temp);
    }
    else{
        printf("\n\t\t\t\t\t\tId not found\n");
    }
}


 void sortList() {  
        //Node current will point to head  
        struct library *current = head, *index = NULL;
        int t1;  
        char t2[max_size],t3[max_size],t4[max_size];
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
                            t1=current->book_id;
                            strcpy(t2,current->book_name);
                            strcpy(t3,current->author_name);
                            strcpy(t4,current->description);
                            current->book_id=index->book_id;
                            strcpy(current->book_name,index->book_name);
                            strcpy(current->author_name,index->author_name);
                            strcpy(current->description,index->description);
                            index->book_id=t1;
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
}

void file_to_structure()
{
    FILE *fp;
    int count=0;
    char c;
    fp=fopen("books.txt","r");
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
            int x=atoi(line1);
            fgets(line2,sizeof(line2),fp);
            fgets(line3,sizeof(line3),fp);
            fgets(line4,sizeof(line4),fp);
            int len = strlen(line1);
            if( line1[len-1] == '\n' )
                line1[len-1] = 0;
            renew->book_id=x;
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

void file_to_issue_records()
{
    FILE *fp;
    int s_id,b_id,dd,mm,yyyy;
    fp=fopen("issuerecords.txt","r");
    while(!feof(fp)){
        struct student *renew=(struct student*)malloc(sizeof(struct student));
        fscanf(fp,"%d %d %d %d %d\n",&s_id,&b_id,&dd,&mm,&yyyy);
        renew->student_id=s_id;
        renew->issued_book_id=b_id;
        renew->dd=dd;
        renew->mm=mm;
        renew->yyyy=yyyy;
        renew->next=NULL;
        if(shead==NULL){
            shead=renew;
        }
        else{
            renew->next=shead;
            shead=renew;
        }
    }
}

int  IsLeapYear(int year)
{
    return (((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0));
}

int isValidDate(int dd,int mm,int yyyy)
{
    //check range of year,month and day
    if (yyyy > 2024 ||yyyy < 1999)
        return 0;
    if (mm < 1 || mm > 12)
        return 0;
    if (dd < 1 || dd > 31)
        return 0;
    //Handle feb days in leap year
    if (mm == 2)
    {
        if (IsLeapYear(yyyy))
            return (dd <= 29);
        else
            return (dd <= 28);
    }
    //handle months which has only 30 days
    if (mm == 4 || mm == 6 ||
            mm == 9 || mm == 11)
        return (dd <= 30);
    return 1;
}

void issue_book()
{
    struct student *new=(struct student*)malloc(sizeof(struct student));
    new->next=NULL;
    int status=0,flag=1;
    printf("\n\n\t\t\t\t\tStudent ID\t\t:");
    scanf("%d",&new->student_id);
    do{
        printf("\t\t\t\t\tBook ID\t\t:");
        scanf("%d",&new->issued_book_id);
        struct library *t=head;
        while(t!=NULL){
            if(t->book_id==new->issued_book_id)
                flag=0;
            t=t->next;
        }
        if(flag==1){
            printf("\n\t\t\t\t\t\tInvalid book ID\n");
        }
    }while(flag);
    do{

        printf("\t\t\t\t\tDate of Issue :");
        scanf("%d/%d/%d",&new->dd,&new->mm,&new->yyyy);
        status=isValidDate(new->dd,new->mm,new->yyyy);
        if(!status){
            printf("\n\t\t\t\t\t\tInvalid date\n");
        }
    }while(!status);
    if(shead==NULL){
        shead=new;
    }
    else{
        new->next=shead;
        shead=new;
    }
    FILE *fp2;
    fp2=fopen("issuerecords.txt","a");
    fprintf(fp2,"%d %d %d %d %d\n",new->student_id,new->issued_book_id,new->dd,new->mm,new->yyyy);
    fclose(fp2);
}

void issue_details()
{
    struct student *temp=shead;
    while(temp!=NULL){
        printf("\n\t\t\t\t\tStudent ID\t:%d\n\t\t\t\t\tBook ID\t\t:%d\n\t\t\t\t\tIssued date\t:%d/%d/%d\n\n",temp->student_id,temp->issued_book_id,temp->dd,temp->mm,temp->yyyy);
        temp=temp->next;
    }
}

void issue_records_to_file()
{
    FILE *fp;
    fp=fopen("issuerecords.txt","w");
    struct student *t=shead;
    while(t!=NULL){
        fprintf(fp,"%d %d %d %d %d\n",t->student_id,t->issued_book_id,t->dd,t->mm,t->yyyy);
        t=t->next;
    }
    fclose(fp);
}

void returned(int id)
{
    struct student *temp=shead;
    struct student *temp2=shead;
    if(temp->next==NULL){
        shead=NULL;
    }
    else if(temp->student_id==id){
        shead=temp->next;
    }
    while ((temp -> next != NULL) && (temp -> student_id!=id)){
        temp2 = temp;
        temp = temp -> next;
    }
    if (temp->student_id==id) {
        printf("\n\t\t\t\t\t\tSuccessful...\n");
        temp2 -> next = temp -> next;
        free(temp);
    }
    else{
        printf("\n\t\t\t\t\t\tId not found\n");
    }
}
void return_book()
{
    struct student *temp=shead;
    int s_id,bk_id,flag=0;
    printf("\t\t\t\t\tReturning book info...\n");
    printf("\t\t\t\t\tStudent ID:");
    scanf("%d",&s_id);
    printf("\t\t\t\t\tBook ID:");
    scanf("%d",&bk_id);
    while(temp!=NULL){
        if((temp->student_id==s_id)&&(temp->issued_book_id==bk_id)){
            returned(temp->student_id);
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("\n\t\t\t\t\t\tNo issueing record is found...\n");
    }
}

void structure_to_file()
{
    FILE *fp;
    fp=fopen("books.txt","w");
    struct library *t=head;
    while(t!=NULL){
        fprintf(fp,"%d\n",t->book_id);
    //fputs(bk_id,books);
        fputs(t->book_name,fp);
        fputs(t->author_name,fp);
        fputs(t->description,fp);
        t=t->next;
    }
    fclose(fp);
}

void update_book()
{
    delete_from_structure();
    add();
    structure_to_file();
}

int library(char user[])
{
    file_to_structure();
    file_to_issue_records();
    int choice;
    while(1){
        printf("\t\t\t\t---------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tMAIN MENU\n");
        printf("\t\t\t\t---------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\tWelcome\t:%s\n",user);
        printf("\t\t\t\t1.Add\n\t\t\t\t2.Display All\n\t\t\t\t3.Delete\n\t\t\t\t4.Search\n\t\t\t\t5.Update\n\t\t\t\t6.Issue Book\n\t\t\t\t7.Issue details\n\t\t\t\t8.Return Book\n\t\t\t\t9.Exit\n");
        printf("\n\n\t\t\t\tEnter Choice=>");
        scanf("%d",&choice);
        if(choice==1){
            add();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==2){
            sortList();
            records_in_structure();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==3){
            delete_from_structure();
            structure_to_file();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==4){
            search_book();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==5){
            update_book();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==6){
            issue_book();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==7){
            issue_details();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else if(choice==8){
            return_book();
            issue_records_to_file();
            printf("\t\t\t\tEnter any key to continue.....");
            getch();
            system("cls");
        }
        else{
            printf("\n\t\t\t\t\t\t\t\tThank you\n");
            return -1;
        }}
}

void login(int n){
    FILE *users;
    printf("\n\t\t\t\t###########################################################################");
    printf("\n\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t############              Library management System            ############");
    printf("\n\t\t\t\t############                                                   ############");
    printf("\n\t\t\t\t###########################################################################");
    users=fopen("users.txt","r");
    if(n>3){
        printf("\n\t\t\t\ttry later...\n");
        exit(0);//exiting after 4 tries
    }
    if(users){
        //printf("exists");
        char user_id[max_size];
        char password[max_size];
        printf("\n\n\t\t\t\t\tUsername\t:");
        fflush(stdin);
        fgets(user_id,max_size,stdin);
        printf("\n\t\t\t\t\tPassword\t:");
        fflush(stdin);
        fgets(password,max_size,stdin);
        char line1[max_size],line2[max_size],user[max_size];
        int fail;
	    while(!feof(users)){
            fgets(line1,sizeof(line1),users);
            fgets(line2,sizeof(line2),users);
             if((strcmp(line1,user_id)==0)&&(strcmp(line2,password)==0)){
                 strcpy(user,line1);
                 printf("\n\t\t\t\t\t\t\tSuccessful...\n\n");
                 printf("\t\t\t\t\tEnter any key to continue...");
                 getch();
                 system("cls");
                 fail=0;
                 break;
             }
            }
            if(fail!=0){
                 printf("\n\t\t\t\t\t\t\tInvalid username or password...\n");
                 system("cls");
                 login(++n);
             }
             else{
                 library(user);
             }

        }
    else{
        users=fopen("users.txt","w");//creating a new user login file
        printf("No user details is found\n");
        printf("Creating a user...");
        char user_id[max_size];
        char password[max_size];
        printf("\n\t\t\t\t\tUsername\t:");
        fflush(stdin);
        fgets(user_id,max_size,stdin);
        printf("\n\t\t\t\t\tPassword\t:");
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