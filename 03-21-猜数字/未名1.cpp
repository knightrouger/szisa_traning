#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
float shu;
char name[20],kon,kon2,item2;
int num,ci=0,len=0,cost,choice,item[20],i;
int year,month,day,hour,fen,miao;
time_t start,end;
FILE *shuju;          //设置文件变量指针// 
FILE *gamename;
void gamenamecz();
void game();
void shujucz();
int main()
{
	srand(time(NULL));
	num=rand()%10;        //*随机数设置，0~1000*// 
    shuju=fopen("shuju.txt","r");  //转移指针,创建只读文件// 
    kon2=fgetc(shuju);
    gamename=fopen("gamename.txt","r");
    kon=fgetc(gamename);     //读取文件内容是否为空，并移动指针// 
	gamenamecz();               //调用函数//
	fclose(gamename);
	fclose(shuju); 
	return 0;
}
void gamenamecz()
   {
      if(kon!=EOF)                       //如果gamename文件不为空// 
           {
           	fseek(gamename, SEEK_SET, 0); 
           	fread(name,20,1,gamename);      //读取文件中name变量的数据// 
           	printf("你好!%s\n",name);
           	printf("1.玩猜数字游戏；2.查看历史成绩；3.更改设置昵称\n");
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
	          printf("请输入新昵称:\n");
	          scanf("%s",&name);
	          fwrite(&name,1,strlen(name),gamename);
	          fclose(gamename);
	          break;
	          default:
	          printf("请输入数字来选择\n");
	          break;
   	       }
   	      }
   	       else
   	       {
   	       	  printf("程序错误");
   	       }
   }
   void timeget();
   void game()
{
	time(&start);   //开始计时// 
    printf("猜一猜数字是:\n");
	while(1)
	{
		while(1)
		{
			len = scanf("%f",&shu);    //清空缓存，防止输入数字以外的东西而跑飞// 
            if(len!=0)
			{
            	break;
            }
            printf("能不能正经点？只能是数字,这次不算。\n") ;
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
        time(&end);
        cost=difftime(end,start);
        printf("用了%d秒\n",cost);
        timeget();
		shuju=fopen("shuju.txt","wd"); //将游戏数据存入文档//
		fwrite(&year,1,sizeof(year),shuju);
		fwrite(&month,1,sizeof(month),shuju);
		fwrite(&day,1,sizeof(day),shuju);
		fwrite(&hour,1,sizeof(hour),shuju);
		fwrite(&fen,1,sizeof(fen),shuju);
		fwrite(&miao,1,sizeof(miao),shuju);
		fwrite(&cost,1,sizeof(cost),shuju);
		fwrite(&num,1,sizeof(num),shuju);
		fwrite(&ci,1,sizeof(ci),shuju); 
		fclose(shuju);
		 printf("\n");
	          printf("名字         开始时间         耗时 所猜数字 猜测次数\n");
			  gamename=fopen("gamename.txt","r"); 
              fread(&name,20,1,gamename); 
	          printf("%s",name);
	          fclose(gamename);
              shuju=fopen("shuju.txt","r");
              fread(&year,1,sizeof(year),shuju);
              fread(&month,1,sizeof(month),shuju);
              fread(&day,1,sizeof(day),shuju);
              fread(&hour,1,sizeof(hour),shuju);
              fread(&fen,1,sizeof(fen),shuju);
              fread(&miao,1,sizeof(miao),shuju);
              fread(&cost,1,sizeof(cost),shuju);
              fread(&num,1,sizeof(num),shuju);
              fread(&ci,1,sizeof(ci),shuju);
	          printf("  ");
	          printf("%d年%d月%d日",year,month,day);
              printf("%d:%d:%d",hour,fen,miao);
              printf("%6d秒 %4d %9d",cost,num,ci);
              printf("\n");
              fclose(shuju);
    	if(kon==EOF)
		 {   
   	         printf("请输入你的游戏名字:\n");
   	         scanf("%s",&name);
   	         gamename=fopen("gamename.txt","w");
   	         fwrite(&name,1,strlen(name) + 1,gamename);
   	         fclose(gamename);
         }
         else if((kon==EOF)&&(kon2!=EOF))
         {
         	printf("名字不能为空或空格\n");
         }
         printf("游戏结束！\n");
         break;
      } 
      else
      {
      	printf("能不能正经点？\n");
      	ci++;
      }	
   }
}
void shujucz()
{
	if(kon2==EOF)
   	       {
   	       	  printf("系统未检测到你的数据，马上开始游戏把~ \n");
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
	          printf("名字         开始时间         耗时 所猜数字 猜测次数\n");
			  gamename=fopen("gamename.txt","r"); 
              fread(&name,20,1,gamename); 
	          printf("%s",name);
	          fclose(gamename);
              shuju=fopen("shuju.txt","r");
              fread(&year,1,sizeof(year),shuju);
              fread(&month,1,sizeof(month),shuju);
              fread(&day,1,sizeof(day),shuju);
              fread(&hour,1,sizeof(hour),shuju);
              fread(&fen,1,sizeof(fen),shuju);
              fread(&miao,1,sizeof(miao),shuju);
              fread(&cost,1,sizeof(cost),shuju);
              fread(&num,1,sizeof(num),shuju);
              fread(&ci,1,sizeof(ci),shuju);
	          printf("  ");
	          printf("%d年%d月%d日",year,month,day);
              printf("%d:%d:%d",hour,fen,miao);
              printf("%6d秒 %4d %9d",cost,num,ci);
              printf("\n");
              fclose(shuju);
   	       }
   	else
	{
	  printf("数据错误！"); 	
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
		printf("%d年%d月%d日 %d:%d:%d\n",year,month,day,hour,fen,miao);
}
