#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
main()
{
	int num,ci=0, len=0;
	float shu;
	char name[20],kon;
	srand(time(NULL));
	num=rand()%10;
	FILE *Name;
    Name=fopen("C:\\Users\\���Ŀ�\\Desktop\\Name.txt","a+");
    kon=fgetc(Name);
   if(kon==EOF)
   {
   	printf("%s",name);
   }
	printf("��������:\n");
	while(1)
	{
		while(1)
		{
			len = scanf("%f",&shu);
            if(len!=0)
			{
            	break;
            }
            printf("�ܲ��������㣿\n") ;
            getchar();
		}
	
	if(shu>num)
      {
	    printf("���ˣ�\n");
	    ci++;
	
      }
      else if(shu<num)
      {
      	printf("С�ˣ�\n");
      	ci++;
     
      }
      else if(shu==num)
      {
      	ci++;
    	printf("��ϲ�㣬�¶��ˣ�\n");
    	printf("�㹲����%d��\n",ci);
    	if(kon!=EOF)
        {
   	     printf("�����������Ϸ����:\n");
   	     scanf("%s",&name);
   	    fprintf(Name,"%s",name);
   	    fclose(Name);
        }
    	break;
      } 
      else
      {
      	printf("�ܲ��������㣿\n");
      	ci++;
      }
   }
    
   return 0;
}
