#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
main()
{
	int num,ci=0;
	float shu;
	srand(time(NULL));
	num=rand()%1000;
	printf("猜数字是\n");
	pan:scanf("%f",&shu);
	   if(shu>num)
      {
	    printf("大了！\n");
	    ci++;
	    goto pan;
      }
      else if(shu<num)
      {
      	printf("小了！\n");
      	ci++;
      	goto pan;
      }
      else if(shu==num)
     {
    	printf("恭喜你，猜对了！\n");
    	printf("你共猜了%d次",ci);
     } 
      else
      {
      	printf("能不能正经点？\n");
      	ci++;
      	goto pan;
      }
}
