#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "string.h"


void countc(char *file)    //ͳ���ַ���
{    
     int num=0; 
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("���ļ�ʧ��\n"); 
        exit(0);
    }
     ch = fgetc(f);
     while(ch!=EOF)
     {
            if(ch>='!'&&ch<='~')   //asc2����'!'�ŵ�'~'Ϊ��ȥ�ո�����Ĵ�ӡ�ַ� 
              {
			   num++;
              } 
		     ch=fgetc(f);      
     }
     fclose(f); 
     printf("�ַ���Ϊ: %d\n", num);
}

void countw(char *file)  //ͳ�Ƶ�����
{
     int flag=0,count=0;
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("���ļ�ʧ��\n"); 
        exit(0);
    }
     ch = fgetc(f);
     while(ch!=EOF)
     {
         ch=fgetc(f);
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            flag = 0;
        else if(flag==0 && (ch != '-' && ch != '_')) //��Щ�����ﺬ��_��- 
        {
            flag = 1;
            count++;
        }
    }
     fclose(f);
     printf("�ʵ���ĿΪ: %d\n", count); 
}

void countl(char *file)  //ͳ������
{
     int l=1;
     char ch;
     FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("���ļ�ʧ��\n"); 
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
     printf("����Ϊ: %d\n",l); 
}

void counta(char *file)  //�ۺ�ͳ�ƺ��������������У����У�ע����
{    
    int e=0,n=0,c=0;
    char ch;
    FILE *f;
     if((f=fopen(file,"r"))==NULL)
    {
        printf("���ļ�ʧ��\n"); 
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
            while (ch!='{'&&ch!='}'&&ch!='\n'&&ch != '/'&&ch!=EOF)  //��ע������û�п��е�����£�����ע���кͿ��о��Ǵ����� 
            {
                ch = fgetc(f);
            }
        }

    }
    printf("������Ϊ:%d.\n",c);
    printf("����Ϊ:%d.\n",e);
    printf("ע����Ϊ:%d.\n",n);
    fclose(f);
}



int main (int argc, char *argv[])   //������
{  

 switch(*argv[1])
    {
       case 'c':countc(argv[2]);break;
       case 'w':countw(argv[2]); break;
       case 'l':countl(argv[2]); break;
       case 'a':counta(argv[2]); break;
       default:printf("\t����\n");break;
    }

    return 0;
}

