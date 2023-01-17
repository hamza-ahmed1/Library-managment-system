#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define maxline 100
#define maxlen 50
	char name[20];
	char rollno[20];
    char bname[20];

	FILE *fptr, *fptr1,*fptr2;
	

 


extern int category(){

	int cat;
	puts("Enter your category.");
	printf("1) Admin\n");
	printf("2) Student\n");
	printf("3)Exit \n");
	scanf("%d", &cat);
	return cat;
}
 void books(){
		FILE *fptr = fopen("book.txt","r");
	                    char content[1000];
	
	                    printf("The Books Avaliable is library are following.\n");
	
	                    if(fptr != NULL){
		                    while(fgets(content, 1000, fptr)){
		                    printf("%s", content);	
		                    }	
	                    }
	                    fclose(fptr);
						
	                    puts("");
}

extern void bookissue(int index){
	index+=3;
	fptr=fopen("book.txt","r");
	fptr1=fopen("bookissue.txt","w");
	  fptr2 = fopen("isssuestudent.txt","a");
	char buffer[maxline];
	
	if(fptr==NULL){
		puts("error occurs while loading file...");
	
	}
	bool keep_reading=true;
	int current_line=1;
	do{
	fgets(buffer,maxline,fptr);
	if(feof(fptr)) keep_reading=false;
	else if(current_line!=index)
	fputs(buffer,fptr1);
		 current_line++;	
	}while(keep_reading);
		puts("Enter name");
	char name[10];
	scanf("%s",name);


	FILE *fptr3=fopen("isssuestudent.txt","a");
	fprintf(fptr3,"%s",rollno);
}

extern void admin(){
	
	puts("Enter the number for the operation you want to perrform.\n");
	
	printf("1) List of all books.\n");
	printf("2) List of books avaliable in library.\n");
	printf("3) Add more books.\n");
	printf("4) Check the list of students who issued the books.\n");
	printf("5) End.\n"); 
	int adop;
	fflush(stdin);
	scanf("%d", &adop);
										 		
	switch(adop){
					
					case 1:
							books();
							admin();
							
						
	                    break;
	                    
	                case 2:
			
								fptr = fopen("bookissue.txt","r");
	                char available_content[1000];
	
	                printf("The Books Avaliable is library are following.\n");
	
	                if(fptr != NULL){
		                while(fgets(available_content, 1000, fptr)){
		                printf("%s", available_content);	
		                }	
	                }
					
					 
                    fclose(fptr);
                    puts("");
					admin();
				
	                	break;
	                	
	                case 3:
	                fptr1 = fopen("bookissue.txt","a");
	                char add_books[maxline];
	                puts("Enter book name");
	                scanf("%s",add_books);
	                      char author[maxline];
	                      fflush(stdin);
	                puts("Enter author name");
	                scanf("%s",author);
	                strcat(add_books,"       ");
	                strcat(add_books,author);
	                puts("No of pages");
	                char pages[maxline];
	                scanf("%s",pages);
	                 strcat(add_books,"       ");
	                    strcat(add_books,pages);
	                    fprintf(fptr1,"  %s",add_books);
	
	                admin();
	                	break;
	                	
	                case 4:
	                	fptr1= fopen("bookIssue.txt","r");
	                    char issue[1000];
	
	                    printf("Student who issued the books are following.\n");
	
	                    if(fptr1 != NULL){
		                    while(fgets(issue, 1000, fptr1)){
		                        printf("%s", issue);	
		                    }	
	                    }
	                    fclose(fptr1);
	                    puts("");
	                       admin();
	                	break;
	                    
	                case 5:
	                	
	                	printf("Ending the program.\n");
	                	exit(0);
	                	
	                	break;
	                    
				
							
						
						
				}
			
			
				
	
}

 extern int student(){
	
	puts("Enter the number for the operation you want to perform.\n");
	
	printf("1) List of the books.\n");
	printf("2) List of the books avaliable in library.\n");
	printf("3) Issue a book.\n");
	printf("4) End.\n");
	int cat;
	scanf("%d", &cat);
	return cat;
} 

extern int verification(char user[],char p[]){

	static int login=0;
	
strcat(user,"  ");
strcat(user,p);

int size=strlen(user);


	char data_of_file[maxline][maxlen];
	FILE *adminptr=fopen("adminsinfo.txt","r");
	int line=0;
	
	while (!feof(adminptr) &&!ferror(adminptr)){
		if(fgets( data_of_file[line],maxlen,adminptr)!=NULL){
			line++;
		}
	}
	int i;
	


for(i=1; i<maxline; i++ ){
	if(strncmp(user,data_of_file[i],size)==0){
		printf("Login Successfully!\n");
		login=1;
		break;
	}

}	
	return login;		
}

extern int std_status(){
	
				puts("Select method!\n1)Login\n2)Signup");
					int status;
					fflush(stdin);
					scanf("%d",&status);
					return status;
}
 int studentlogin(char name[],char password[]){
static int login=0;
	
strcat(name,"  ");
strcat(name,password);

int size=strlen(name);


	char data_of_file[maxline][maxlen];
	FILE *stdfptr=fopen("studentdata.txt","r");
	int line=0;
	int cat;
	
	while (!feof(stdfptr) &&!ferror(stdfptr)){
		if(fgets( data_of_file[line],maxlen,stdfptr)!=NULL){
			line++;
		}
	}
	int i;
for(i=1; i<maxline; i++ ){
	if(strncmp(name,data_of_file[i],size)==0){
		printf("Login Successfully!\n");
		login=1;
		break;
	}

}	
	if(login==1){
		 cat=student();
	}else{puts("Incorrect Password or User name");}	
	return cat;
	fclose(stdfptr);	
}
		
extern void studentsignup(char name[],char password[]){
	FILE *stdfptr=fopen("studentdata.txt","a");
	fprintf(stdfptr,"\n%s",name);
	fprintf(stdfptr,"  %s",password);
	studentlogin(name,password);
	fclose(stdfptr);
}



 