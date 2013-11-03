#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

static struct book
{
       char name[40];
       char auther[40];
       char id[6];
       int roll_no;
       int day;
       int month;
       int year;
}e;

int day1,month1,year1;
main()
{      printf(".................................WELCOME...................................\n");
       getch();
        system("cls");  
       printf("enter todays date in dd/mm/yyyy format\n");
      scanf("%d%d%d",&day1,&month1,&year1);
      
      
      
start: 
{      system("cls");  
                                          
      FILE*fp,*ft;
      int a;
      char another='y';
      fp=fopen("library.txt","r+");
     
      
      
      printf("\n");                                     
      printf("1-to enter new book to library\n2-to display info of books in library\n3-to issue book\n4-to return book\n");
      scanf("%d",&a);
       system("cls");
      switch(a)
      {
               case 1:
                    {     
                           fseek(fp,0,SEEK_END);
                           char name1[40];
                           
                           
                                              
                           printf("enter name of book\n");
                           
                           gets(e.name);
                           gets(e.name);
                           system("cls");
                           printf("enter name of auther of book\n");
                            
                           gets(e.auther);
                           
                           system("cls");
                           printf("enter id of book\n");
                           scanf("%s",e.id);
                            system("cls");
                           printf("set issue date as 00-00-0000 by default\n");
                           scanf("%d%d%d",&e.day,&e.month,&e.year);
                            system("cls");
                           printf("set library card no of book issued student as 0 by default\n ");
                           scanf("%d",&e.roll_no);
                           system("cls");
                           
                           
                           
                           
                           
                           fwrite(&e,sizeof(e),1,fp);
     
                            
                           
                           break;
                    }  
               case 2:
                    {     system("cls");
                          rewind(fp); 
                          fp=fopen("library.txt","r");
                           
                                 while(fread(&e,sizeof(e),1,fp)==1)
                                 {
                                 printf("NAME OF THE BOOK  :%s\nAUTHER            :%s\nID CODE           :%s\nISSUED TO         :%d\nISSUED ON         :%d-%d-%d \n",e.name,e.auther,e.id,e.roll_no,e.day,e.month,e.year);
                                 printf("\n\n"); 
                            
                                 }                           
                             
                           fclose(fp); 
                    
                            break;
                            
                                
                                 
                    }
               case 3:
                    {     system("cls");
                           char s[40];
                                 
                                 printf("enter id code of book u want to issue\n");
                                 scanf("%s",s);
                                 system("cls");
                                 rewind(fp);
                                 while(fread(&e,sizeof(e),1,fp)==1)
                                 {
                                                                   if(strcmp(e.id,s)==0)
                                                                   {
                                                                                       
                                                                                       if(e.day==0)
                                                                                       {           printf("enter library card no of student\n");
                                                                                                      scanf("%d",&e.roll_no);                                                                                      
                                                                                                    e.day=day1;
                                                                                                    e.month=month1;
                                                                                                    e.year=year1;
                                                                                                      system("cls");
                                                                                                    
                                                                                                    fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                    fwrite(&e,sizeof(e),1,fp);
                                                                                                    printf("info stored successfully\n");
                                                                                                    break;     
                                                                                                    
                                                                                       }
                                                                                       else
                                                                                       {
                                                                                        
                                                                                        printf("this book is already issued\n");
                                                                                        break;
                                                                                        
                                                                                       }
                                                                   }
                                 } 
                    
                            
                            
                            
                            
                            break;
                                 
                    }
               case 4:
                    {
                                                                   char s[40];
                                                                   printf("enter id code of book u want to return\n");
                                                                   scanf("%s",s);
                                                                    system("cls");
                                                                   rewind(fp);
                                                                    while(fread(&e,sizeof(e),1,fp)==1)
                                                                    {
                                                                     if(strcmp(e.id,s)==0)
                                                                     {
                                                                                            int p;
                                                                                            
                                                                                            if(e.month==month1)
                                                                                            {
                                                                                                  if((day1-e.day)<15)
                                                                                                  {
                                                                                                  printf("student has returned book on time\n");
                                                                                                  printf("set date of issue as 00-00-0000\n");
                                                                                                  scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                   system("cls");
                                                                                                  printf("enter library card no of student as 0\n");
                                                                                                  
                                                                                                 
                                                                                                  scanf("%d",&e.roll_no);
                                                                                                   system("cls");
                                                                                                  fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                  fwrite(&e,sizeof(e),1,fp); 
                                                                                                  break;
                                                                                                  }
                                                                                                  else
                                                                                                  {             
                                                                                                  printf("student should pay fine of Rs %d",2*(day1-e.day));
                                                                                                  printf("set date of issue as 00-00-0000\n");
                                                                                                  scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                  system("cls");
                                                                                                   printf("enter library card no of student as 0\n");
                                                                                                         
                                                                                                         scanf("%d",&e.roll_no);
                                                                                                         system("cls");
                                                                                                  fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                   fwrite(&e,sizeof(e),1,fp); 
                                                                                                   break;
                                                                                                  }  
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if(e.day>day1)
                                                                                                {
                                                                                                       p=month1-e.month;
                                                                                                       if((30-(e.day-day1))<15)
                                                                                                       {
                                                                                                         printf("u have returned book on time\n");
                                                                                                         printf("set date of book as 00-00-0000\n");
                                                                                                         scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                           system("cls");
                                                                                                           printf("enter library card no of student as 0\n");
                                                                                                         
                                                                                                         scanf("%d",&e.roll_no);
                                                                                                         system("cls");
                                                                                                         fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                         fwrite(&e,sizeof(e),1,fp); 
                                                                                                         break;
                                                                                                       }
                                                                                                       else
                                                                                                       {   if((30+day1-e.day)<15)
                                                                                                           {
                                                                                                                   printf("u have returned book on time\n");
                                                                                                                   printf("set date of book as 00-00-0000\n");
                                                                                                                   scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                                    fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                                     printf("enter library card no of student as 0\n");
                                                                                                                   
                                                                                                                   scanf("%d",&e.roll_no);
                                                                                                                   system("cls");
                                                                                                                   fwrite(&e,sizeof(e),1,fp); 
                                                                                                                   break;
                                                                                                           }
                                                                                                           else
                                                                                                           {                                                                             
                                                                                                           printf("student should pay fine of Rs %d",2*(30+(day1-e.day)-15));
                                                                                                           printf("set date of issue as 00-00-0000\n");
                                                                                                           scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                            system("cls");
                                                                                                            printf("enter library card no of student as 0\n");
                                                                                                                   
                                                                                                                   scanf("%d",&e.roll_no);
                                                                                                                   system("cls");
                                                                                                            fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                             fwrite(&e,sizeof(e),1,fp);
                                                                                                             break;
                                                                                                           } 
                                                                                                       }
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                           printf("student should pay fine of Rs %d",2*(30+(day1-e.day)-15));
                                                                                                           printf("set date of issue as 00-00-0000\n");
                                                                                                           scanf("%d%d%d",&e.day,&e.month,&e.year);
                                                                                                            system("cls");
                                                                                                             printf("enter library card no of student as 0\n");
                                                                                                                   
                                                                                                                   scanf("%d",&e.roll_no);
                                                                                                                   system("cls");
                                                                                                           fseek(fp,-sizeof(e),SEEK_CUR);
                                                                                                           fwrite(&e,sizeof(e),1,fp); 
                                                                                                           break;

                                                                                                }
                                                                                            }
                                                                     } 
                                 
                                                                    }

                             
                            
                            
                            break;
                    }
                    
                                                                    
                                                                                                           
                                                                                                                        
                                                                                                                             
                                                                                
                                                              
      
    }
       fclose(fp);
      getch();
}     int y;
      printf("if u want to continue press 5\n");
      scanf("%d",&y);
       system("cls");
      if(y==5)
      goto start;
      
      return 0;
}


      
