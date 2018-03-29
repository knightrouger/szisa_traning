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
    Name=fopen("C:\\Users\\吴文康\\Desktop\\Name.txt","a+");
    kon=fgetc(Name);
   if(kon==EOF)
   {
   	printf("%s",name);
   }
	printf("猜数字是:\n");
	while(1)
	{
		while(1)
		{
			len = scanf("%f",&shu);
            if(len!=0)
			{
            	break;
            }
            printf("能不能正经点？\n") ;
            getchar();
		}
	
	if(shu>num)
      {
	    printf("大了！\n");
	    ci++;
	
      }
      else if(shu<num)
      {
      	printf("小了！\n");
      	ci++;
     
      }
      else if(shu==num)
      {
      	ci++;
    	printf("恭喜你，猜对了！\n");
    	printf("你共猜了%d次\n",ci);
    	if(kon!=EOF)
        {
   	     printf("请输入你的游戏名字:\n");
   	     scanf("%s",&name);
   	    fprintf(Name,"%s",name);
   	    fclose(Name);
        }
    	break;
      } 
      else
      {
      	printf("能不能正经点？\n");
      	ci++;
      }
   }
    
   return 0;
}
