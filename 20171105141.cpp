#include <stdlib.h>//exit
#include<stdio.h>
#include<string.h>
struct student
{
	
	int numbers;
	char name[10];
	char sex[10];
	int dateofbirt;
	char class1[15];
	char phoneNo[12];
	char judge[100];
	int* nop = (int*)malloc(sizeof(int)*1);//��ί�����ĸ��� 
	int max;
	int min;
	int average;//ƽ���� 
	int score=0;//�ܷ� 
};
struct student s[100];

int main()
{
    
	FILE *fp1,*fp2;
	int i=0,j=0,a=0,b=0,d=0; //i,jΪѭ��������aΪ�������� ,dΪ��ί���� ,bΪ���������� 
	char header[100]; 
	
	fp1 =fopen("student1.csv","r");
    if(fp1==NULL)
	{
		printf("error");
		exit(-1);//0Ϊ�����˳�������Ϊ�쳣�˳� 
	}
	else
	{
        fscanf(fp1,"%s",header);
	    while(!feof(fp1))//���ļ�δ���귵��0��ѭ�����������귵��1.ѭ������ 
       {
	        fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%s",
	                    &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,&s[i].phoneNo,&s[i].judge);
            i++;
       }
    fclose(fp1);
    } 
    
	j=i;
	int max,min,fs;
	char delims[]=",";
	char *result=NULL;
    for(i=0;i<j;i++)
	   {
		    result=strtok(s[i].judge,delims);
	        while(result!=NULL)
	            {
	                fs=atoi(result);
 	                result = strtok( NULL, delims);
	   	            b++;
	   	            s[i].nop[a]=fs;
                    a++;
       	       }
  	        a=0;
       }
    d=b/i;//��ί���� 
    j=i;
    for(i=0;i<j;i++)
    {
    	
	    s[i].max=s[i].min=s[i].nop[0];
    }
    j=i;
    for(i=0;i<j;i++)
    {
	    for(a=0;a<d;a++)
		{
		    if(s[i].nop[a]>s[i].max)
	            s[i].max=s[i].nop[a];
	        if(s[i].nop[a]<s[i].min)
	            s[i].min=s[i].nop[a];
        }
    }
    i=j;
    for(i=0;i<j;i++)
        {
	        for(a=0;a<d;a++)
			    {
	                s[i].score=s[i].nop[a]+s[i].score;
                }
            s[i].average=(s[i].score-s[i].max-s[i].min)/(d-2);
        }
    j=i;
	i=0;
	fp2=fopen("student2.csv","w");
	if(fp2==NULL)
	{
	    printf("error");
	    exit(-1);
	}
	else
	{
        fprintf(fp2,"%s,aver\n",header);
        printf("%s,aver\n",header);
        while(i<j)
            {
	            fprintf(fp2,"%d,%s,%s,%d,%s,%s,",s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo);
	            printf("%d,%s,%s,%d,%s,%s,",s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo);
    	        for(a=0;a<d;a++)
		            {
			            fprintf(fp2,"%d,",s[i].nop[a]);
			            printf("%d,",s[i].nop[a]);
		            }
		        fprintf(fp2,"%d",s[i].average);
	        	printf("%d",s[i].average);
		        fprintf(fp2,"\n");
		        printf("\n");
                i++;
            }
    }
    fclose(fp2);
    return 0; 
}

