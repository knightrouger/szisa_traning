#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
main()
{
	int num,ci=0;
	float shu;
	srand(time(NULL));
	num=rand()%1000;
	printf("��������\n");
	pan:scanf("%f",&shu);
	   if(shu>num)
      {
	    printf("���ˣ�\n");
	    ci++;
	    goto pan;
      }
      else if(shu<num)
      {
      	printf("С�ˣ�\n");
      	ci++;
      	goto pan;
      }
      else if(shu==num)
     {
    	printf("��ϲ�㣬�¶��ˣ�\n");
    	printf("�㹲����%d��",ci);
     } 
      else
      {
      	printf("�ܲ��������㣿\n");
      	ci++;
      	goto pan;
      }
}
