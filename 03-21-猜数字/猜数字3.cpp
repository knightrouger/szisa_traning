#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
float shu;
char name[20],kon,kon2,item2;
int num,ci=0,len=0,cost,choice,item[20],i;
int year,month,day,hour,fen,miao;
time_t start,end;
FILE *shuju;          //�����ļ�����ָ��// 
FILE *gamename;
void gamenamecz();
void game();
void shujucz();
int main()
{
	srand(time(NULL));
	num=rand()%10;        //*��������ã�0~1000*// 
    shuju=fopen("shuju.txt","r");  //ת��ָ��,����ֻ���ļ�// 
    kon2=fgetc(shuju);
    gamename=fopen("gamename.txt","r");
    kon=fgetc(gamename);     //��ȡ�ļ������Ƿ�Ϊ�գ����ƶ�ָ��// 
	gamenamecz();               //���ú���//
	fclose(gamename);
	fclose(shuju); 
	return 0;
}
void gamenamecz()
   {
      if(kon!=EOF)                       //���gamename�ļ���Ϊ��// 
           {
           	fseek(gamename, SEEK_SET, 0); 
           	fread(name,20,1,gamename);      //��ȡ�ļ���name����������// 
           	printf("���!%s\n",name);
           	printf("1.���������Ϸ��2.�鿴��ʷ�ɼ���3.���������ǳ�\n");
	        scanf("%d",&choice);
	        switch(choice)
	        {
	         case 1:
	         game();
	         break;
	         case 2:
	         shujucz();
	          break;	
	          case 3:
	          gamename=fopen("gamename.txt","w");
	          printf("���������ǳ�:\n");
	          scanf("%s",&name);
	          fwrite(&name,1,strlen(name),gamename);
	          fclose(gamename);
	          break;
	          default:
	          printf("������������ѡ��\n");
	          break;
   	       }
   	      }
   	       else
   	       {
   	       	  printf("�������");
   	       }
   }
   void timeget();
   void game()
{
	time(&start);   //��ʼ��ʱ// 
    printf("��һ��������:\n");
	while(1)
	{
		while(1)
		{
			len = scanf("%f",&shu);    //��ջ��棬��ֹ������������Ķ������ܷ�// 
            if(len!=0)
			{
            	break;
            }
            printf("�ܲ��������㣿ֻ��������,��β��㡣\n") ;
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
        time(&end);
        cost=difftime(end,start);
        printf("����%d��\n",cost);
        timeget();
		item[0]=year;
		item[1]=month;
	    item[2]=day;
		item[3]=hour;
		item[4]=fen;
		item[5]=miao;
		item[6]=cost;
		item[7]=num;
		item[8]=ci;
		shuju=fopen("shuju.txt","w+"); //����Ϸ���ݴ����ĵ�// 
	    fprintf(shuju,"%1d,%1d,%1d,%1d,%1d,%1d,%1d,%1d,%1d",year,month,day,hour,fen,miao,cost,num,ci);
   	    fwrite(&name,1,strlen(name) + 1,shuju);
		fclose(shuju);
		 printf("\n");
	          printf("����         ��ʼʱ��         ��ʱ �������� �²����\n");
			  gamename=fopen("gamename.txt","r"); 
              fread(&name,20,1,gamename); 
	          printf("%s",name);
	          fclose(gamename);

	          printf("  ");
	          printf("%d��%d��%d��",year,month,day);
              printf("%d:%d:%d",hour,fen,miao);
              printf("%6d�� %4d %9d",cost,num,ci);
              printf("\n");
    	if(kon==EOF) 
		 {   
   	         printf("�����������Ϸ����:\n");
   	         scanf("%s",&name);
   	         gamename=fopen("gamename.txt","w");
   	         fwrite(&name,1,strlen(name) + 1,gamename);
   	         fclose(gamename);
         }
         else if((kon==EOF)&&(kon2!=EOF))
         {
         	printf("���ֲ���Ϊ�ջ�ո�\n");
         }
         printf("��Ϸ������\n");
         break;
      } 
      else
      {
      	printf("�ܲ��������㣿\n");
      	ci++;
      }	
   }
}
void shujucz()
{
	if(kon2==EOF)
   	       {
   	       	  printf("ϵͳδ��⵽������ݣ����Ͽ�ʼ��Ϸ��~ \n");
   	       	  printf("Y/N  \n");
   	       	  scanf("%s",&choice);
   	       	  switch(choice)
   	       	  {
   	       	  case 'Y':
   	       	  	game();
   	       	  	break;
   	       	  case 'N':
   	       	  	break;
   	       	  }
   	       }
   	else if(kon2!=EOF)
   	       {
   	       	  printf("\n");
	          printf("����         ��ʼʱ��         ��ʱ �������� �²����\n");
			  gamename=fopen("gamename.txt","r"); 
              fread(&name,20,1,gamename); 
	          printf("%s",name);
	          fclose(gamename);

	          printf("  ");
	          printf("%d��%d��%d��",year,month,day);
              printf("%d:%d:%d",hour,fen,miao);
              printf("%6d�� %4d %9d",cost,num,ci);
              printf("\n");
   	       }
   	else
	{
	  printf("���ݴ���"); 	
   	}
}
void timeget()
{
	    time_t t;
        struct tm*lt;
        time (&t);
        lt =localtime(&t);
        year=lt->tm_year+1900;
        month=lt->tm_mon+1;
        day=lt->tm_mday;
        hour=lt->tm_hour;
        fen=lt->tm_min;
        miao=lt->tm_sec;
		printf("%d��%d��%d�� %d:%d:%d\n",year,month,day,hour,fen,miao);
}
