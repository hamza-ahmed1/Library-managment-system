#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include"mainfunctions.h"


struct login{
	
	char rollno[10];
	char username[10];
	char password[10];
	
};


int main(){
	
	char name[20];
	char rollno[20];
    char bname[20];
	struct login id;
	FILE *fptr, *fptr1;
	
	printf("                          ------------------------------------------------\n");
	printf("                          |             WELCOME TO LIBRARY                |\n");
	printf("                          ------------------------------------------------\n");
int cat;
do{
       cat=category();
     
    switch(cat){
			case 1:
			  
				puts("-:Admin Verification:-\n");
				
				printf("Enter Username.\n");
				fflush(stdin);
				scanf("%s", &id.username);
				
				
				printf("Enter Password.\n");
				fflush(stdin);
				
				scanf("%s",&id.password);
				 int login=verification(id.username,id.password);
				 
				
				if(login==1){
                             
                             admin();
                             break;
                             }
                                            
                                            
                             
                else{
                     printf("Unable to enter administrator ID or Password\n"); 
					break;
                }
    
			case 2:
		
			
				puts("Select method!\n1)Login\n2)Signup");
					int status;
					fflush(stdin);
					scanf("%d",&status);
					
				puts("-:Give your login info:-\n");
				printf("Enter your Student ID.\n");
				scanf("%s", &id.rollno);
				printf("Enter Password.\n");
				scanf("%s", &id.password);
				if(status==1){
				int stdop=studentlogin(id.rollno,id.password);
				
				switch(stdop){
				
				case 1:
			           
					fptr = fopen("book.txt","r");
	                char content[1000];
	
	                printf("The Books Avaliable is library are following.\n");
	
	                if(fptr != NULL){
		                while(fgets(content, 1000, fptr)){
		                printf("%s", content);	
		                }	
	                }
					
					 
                    fclose(fptr);
                    puts("");
						
				
                    break;
                    
                case 2:
                	fptr = fopen("bookissue.txt","r");
	                char temp_content[1000];
	
	                printf("The Books Avaliable is library are following.\n");
	
	                if(fptr != NULL){
		                while(fgets(temp_content, 1000, fptr)){
		                printf("%s", temp_content);	
		                }	
		                
	                }
	                break;
					
                
                case 3:
                	
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
                    puts("Enter book index no");
                    int bookindex;
                    scanf("%d",&bookindex);
                    
                    bookissue(bookindex);
                	break;
                    
                case 4:
	                	
	                printf("Ending the program.\n");
	            	exit(0);       
			    	break;
	                    	
			}
						
				}
else if(status==2){

studentsignup(id.rollno,id.password);}
				else{puts("Invalid input!!!");}
			
			
				
		case 3:
		
		
			printf("Ending the program.\n");
			exit(0);
			break;
			
      }

    }while(cat <4);

	 	
	
		
}




		





