/*
菜单驱动的学生成绩管理系统：
① 录入每个学生的学号、姓名和考试成绩。
② 计算课程的总分和平均分。
③ 按成绩由高到低排出名次表。
④ 按成绩由低到高排出名次表。
⑤ 按学号由小到大排出成绩表。
⑥ 按姓名的字典顺序排出成绩表。
⑦ 按学号查询学生排名及其考试成绩。
⑧ 按姓名查询学生排名及其考试成绩。
⑨ 按优秀（90-100分）、良好（80-89分）、中等（70 - 79分）：、及格（60—69分）、不及格
(0-59分)5个类别，统计每个类别的人数以及所占的百分比。
⑩ 输出每个学生的学号、姓名及考试成绩。
⑪ 退出程序。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30        /*最多30个学生*/
#define MNL 20      /*学生名字最大长度 maximal name length*/
int ReadScore(long num[],char name[][MNL],int score[]);
void TotalAndAverage(int score[],int n);
void ScoreSort(long num[],char name[][MNL],int score[],int n,int (*compare)(int a,int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void Swap(long *x,long*y);
void SwapStr(char a[],char b[]);
void PrintDescendingRank(long num[],char name[][MNL],int score[],int n);
void PrintAscendingRank(long num[],char name[][MNL],int score[],int n);
void NumberSort(long num[],char name[][MNL],int score[],int n);
void NameSort(long num[],char name[][MNL],int score[],int n);
void PrintNameScore(char name[][MNL],int score[],int n);
void IDSearch(long num[],char name[][MNL],int score[],int n);
void NameSearch(long num[],char name[][MNL],int score[],int n);
void StatisticsAnalysis(int score[],int n);
void PrintScore(long num[],char name[][MNL],int score[],int n);

int main(void)
{
    printf("Number:200810417\nName:杨洲\nSubject No.6-program No.1\n\n");
    int n;
    int score[N];
    long num[N];
    char name[N][MNL];
    int choice;

    do
    {
        printf("1. Input record\n"
               "2. Calculate total and average score of course\n"
               "3. Sort in descending order by score\n"
               "4. Sort in ascending order by score\n"
               "5. Sort in ascending order by student's ID\n"
               "6. Sort in dictionary order by name\n"
               "7. Search by student's ID\n"
               "8. Search by name\n"
               "9. Statistic analysis\n"
               "10.List record\n"
               "11.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            n = ReadScore(num,name,score);
            break;
        case 2:
            TotalAndAverage(score,n);
            break;
        case 3:
            ScoreSort(num,name,score,n,Descending);
            PrintDescendingRank(num,name,score,n);
            break;
        case 4:
            ScoreSort(num,name,score,n,Ascending);
            PrintAscendingRank(num,name,score,n);
            break;
        case 5:
            NumberSort(num,name,score,n);
            PrintScore(num,name,score,n);
            break;
        case 6:
            NameSort(num,name,score,n);
            PrintNameScore(name,score,n);
            break;
        case 7:
            IDSearch(num,name,score,n);
            break;
        case 8:
            NameSearch(num,name,score,n);
            break;
        case 9:
            StatisticsAnalysis(score,n);
            break;
        case 10:
            PrintScore(num,name,score,n);\
            break;
        case 11:
            exit(0);
            break;
        }
        printf("\n\n----------------------------------------------------\n");
    }
    while(1);

    return 0;
}

/*录入每个学生的学号、姓名和考试成绩。
返回学生数n。*/
int ReadScore(long num[],char name[][MNL],int score[])
{
    int n,i=0;
    printf("How many students?\n");
    scanf("%d",&n);

    printf("Please input student's ID,name and score,format as: (20201111 King 89)\n");
    for(i = 0; i<n; i++)
    {
        scanf("%ld %s %d",&num[i],&name[i],&score[i]);

    }

    printf("Have stored the data successfully,thanks!");

    return n;
}

/*计算和打印课程的总分和平均分。*/
void TotalAndAverage(int score[],int n)
{
    int total = 0,i = 0;
    float average;

    for(; i < n; i++)
    {
        total += score[i];
    }

    average = ((float)total)/n;

    printf("Total score: %d\nAverage score: %.2f\n",total,average);
}

/*按成绩由高（低）到低（高）排序*/
void ScoreSort(long num[],char name[][MNL],int score[],int n,int (*compare)(int a,int b))
{
    int i,j,k;
    for(i =0; i<n-1; i++)
    {
        k = i;
        for(j = i+1; j < n; j++)
        {
            if((*compare)(score[j],score[k]))
            {
                k = j;
            }
        }

        if(k != i)
        {
            Swap(&score[k],&score[i]);
            Swap(&num[k],&num[i]);
            SwapStr(name[k],name[i]);
        }
    }
}

/*使数据按升序排序*/
int Ascending(int a,int b)
{
    return a < b;
}

/*使数据按降序排序*/
int Descending(int a,int b)
{
    return a > b;
}

/*两个整数值互换*/
void Swap(long *x,long*y)
{
    long temp;
    temp =*x;
    *x=*y;
    *y=temp;
}

/*交换两个字符串*/
void SwapStr(char a[],char b[])
{
    char temp[1][MNL];

    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

/*顺序打印数组中数据，按数据在数组位置顺序打印排名，如第n个数据排名是第n名*/
void PrintDescendingRank(long num[],char name[][MNL],int score[],int n)
{
    int i;
    printf("Rank\tNumber\tScore\tName\n");

    for(i=0; i<n; i++)
    {
        printf("%d\t%ld\t\t%d\t%s\n",i+1,num[i],score[i],name[i]);
    }
}

/*顺序打印数组中数据，按数据在数组位置逆序打印排名，如第n个数据排名是倒数第n名*/
void PrintAscendingRank(long num[],char name[][MNL],int score[],int n)
{
    int i;
    int m=n;        /*存放n以便在后面循环中使用*/
    printf("Rank\tNumber\t\tScore\tName\n");

    for(i=0; i<n; i++)
    {
        printf("%d\t%ld\t\t%d\t%s\n",m--,num[i],score[i],name[i]);
    }
}

/*按学号由小到大排序*/
void NumberSort(long num[],char name[][MNL],int score[],int n)
{
    int i,j,k;
    for(i =0; i<n-1; i++)
    {
        k = i;
        for(j = i+1; j < n; j++)
        {
            if(num[k] > num[j] )
            {
                k = j;
            }
        }

        if(k != i)
        {
            Swap(&score[k],&score[i]);
            Swap(&num[k],&num[i]);
            SwapStr(name[k],name[j]);
        }
    }
}

/*按姓名的字典顺序排序*/
void NameSort(long num[],char name[][MNL],int score[],int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
        {
            if(strcmp(name[j],name[k])>0)
            {
                k=j;
            }
        }
    }
    if(k!=i)
    {
        Swap(&num[i],&num[k]);
        Swap(&score[i],&score[k]);
        SwapStr(name[i],name[k]);
    }
}

/*打印名字和分数*/
void PrintNameScore(char name[][MNL],int score[],int n)
{
    int i;
    printf("Name\t\tScore\n");
    printf("------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t\t%d\n",name[i],score[i]);
    }
}

/*按学号查询学生排名及其考试成绩。*/
void IDSearch(long num[],char name[][MNL],int score[],int n)
{
    long number;
    int find = 0;

    ScoreSort(num,name,score,n,Descending);
    printf("Enter student's number:");
    scanf("%ld",number);

    for(; n > 0; n--)
    {
        if(num[n-1] == number)
        {
            printf("Rank: %d\n",n);
            printf("Score: %d\n",score[n-1]);
            find = 1;
        }
    }

    if(!find)
    {
        printf("Not found!");
    }
}

/*按姓名查询学生排名及其考试成绩。*/
void NameSearch(long num[],char name[][MNL],int score[],int n)
{
    int find = 0;
    char search[1][MNL];

    ScoreSort(num,name,score,n,Descending);
    printf("Enter student's name:");
    scanf("%s",search);
    for(; n > 0; n--)
    {
        if(strcmp(name[n-1],search)==0)
        {
            printf("Rank: %d\n",n);
            printf("Score: %d\n",score[n-1]);
            find = 1;
        }
    }

    if(!find)
    {
        printf("Not found!");
    }
}

/*按优秀（90-100分）、良好（80-89分）、中等（70 - 79分）：、及格（60—69分）、不及格
(0-59分)5个类别，打印每个类别的人数以及所占的百分比。*/
void StatisticsAnalysis(int score[],int n)
{
    int i = 0;
    int level[5]= {0,0,0,0,0};      /*5个类别的人数*/
    for(; i < n; i++)
    {
        if(score[i]>= 90 && score[i]<=100)
            level[0]++;
        else if(score[i]>=80 && score[i]<=89)
            level[1]++;
        else if(score[i]>=70 && score[i]<=79)
            level[2]++;
        else if(score[i]>=60 && score[i]<=69)
            level[3]++;
        else if(score[i]>=0 && score[i]<=59)
            level[4]++;
    }
    printf("          \tExcellent\tGood\tAverage\tPassed\tFailed\n");
    printf("Number    \t%d       \t%d  \t%d     \t%d    \t%d\n",level[0],level[1],level[2],level[3],level[4]);
    printf("Percentage\t%.2f%%\t\t%.2f%%\t%.2f%%\t%.2f%%\t%.2f%%\n",100*((float)level[0])/n,100*((float)level[1])/n,100*((float)level[2])/n,100*((float)level[3])/n,100*((float)level[4])/n);
}

/*输出每个学生的学号、姓名及考试成绩。*/
void PrintScore(long num[],char name[][MNL],int score[],int n)
{
    int i;
    printf("Number\tScore\t\tName\n");

    for(i = 0; i<n; i++)
    {
        printf("%ld\t%d\t%s\n",num[i],score[i],name[i]);
    }
}
