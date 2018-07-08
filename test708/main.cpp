#include <cstdlib>
#include<stdio.h>

struct student
{
    
    int numbers;
    char name[10];
    char sex[10];
    int dateofbirt;
    char class1[15];
    char phoneNo[15];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("/Users/S20171105141/Desktop/student1.csv","r");
    if(fp1==NULL)
    {
        printf("error\n");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,
                   &s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;
    
    fp2=fopen("/Users/S20171105141/Desktop/student2.csv","w");
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,score\n");
    
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",
                s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,
                s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
        i++;
    }
    fclose(fp2);
    
    return 0;
}
