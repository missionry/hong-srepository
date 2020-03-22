#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "string.h"


void countc(char *file)    //统计字符数
{    
     int num=0; 
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("打开文件失败\n"); 
        exit(0);
    }
     ch = fgetc(f);
     while(ch!=EOF)
     {
            if(ch>='!'&&ch<='~')   //asc2码里'!'号到'~'为除去空格以外的打印字符 
              {
			   num++;
              } 
		     ch=fgetc(f);      
     }
     fclose(f); 
     printf("字符数为: %d\n", num);
}

void countw(char *file)  //统计单词数
{
     int flag=0,count=0;
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("打开文件失败\n"); 
        exit(0);
    }
     ch = fgetc(f);
     while(ch!=EOF)
     {
         ch=fgetc(f);
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            flag = 0;
        else if(flag==0 && (ch != '-' && ch != '_')) //有些单词里含有_和- 
        {
            flag = 1;
            count++;
        }
    }
     fclose(f);
     printf("词的数目为: %d\n", count); 
}

void countl(char *file)  //统计行数
{
     int l=1;
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("打开文件失败\n"); 
        exit(0);
        l=0;
    }
     ch = fgetc(f);
     while(ch!=EOF)
     {
         ch=fgetc(f);
            if(ch=='\n')
               l++;
     }
     printf("行数为: %d\n",l); 
}

void counta(char *file)  //综合统计函数，包括代码行，空行，注释行
{    
    int e=0,n=0,c=0;
    char ch;
    FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("打开文件失败\n"); 
        exit(0);
    }
    ch = fgetc(f);
    while(ch!=EOF)
    {
    	if (ch==' ')
		{
		    ch=fgetc(f);
    	}
        else if (ch=='{'||ch=='}')
        {   
		    if ((ch = fgetc(f))!='/') 
            e++;
        }
        else if (ch=='\n')
        {
            ch = fgetc(f);
            while(ch =='\n')
            {
                e++;
                ch=fgetc(f);
            }
        }
        else if (ch=='/'&&(ch=fgetc(f))=='/')
        {
              while(ch!='\n')
              {
                ch=fgetc(f);
              }
                n++;
                ch=fgetc(f);
        }
        else
        {
            c++;
            while (ch!='{'&&ch!='}'&&ch!='\n'&&ch != '/'&&ch!=EOF)  //在注释行里没有空行的情况下，除了注释行和空行就是代码行 
            {
                ch = fgetc(f);
            }
        }

    }
    printf("代码行为:%d.\n",c);
    printf("空行为:%d.\n",e);
    printf("注释行为:%d.\n",n);
    fclose(f);
}



int main (int argc, char *argv[])   //主函数
{  

 switch(*argv[1])
    {
       case 'c':countc(argv[2]);break;
       case 'w':countw(argv[2]); break;
       case 'l':countl(argv[2]); break;
       case 'a':counta(argv[2]); break;
       default:printf("\t错误\n");break;
    }

    return 0;
}

