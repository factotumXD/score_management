/*学生成绩管理系统V1.0*/
#include <stdio.h>
#include <stdlib.h>
#define N 30
int ReadScore(long num[],int score[]);
void TotalAndAverage(int score[],int n);
void SelectionSort(long num[],int score[],int n);
void Swap(long *x,long *y);
void NumberSort(long num[],int score[],int n);
void Search(long num[],int score[],int n);
void StatisticsAnalysis(int score[],int n);
void PrintScore(long num[],int score[],int n);
void PrintAscendingRank(long num[],int score[],int n);
void PrintDescendingRank(long num[],int score[],int n);


int main(void)
{
    printf("Number:200810417\nName:杨洲\nSubject No.5-program No.1\n\n");
    int score[N];
    int choice;
    long num[N];
    int n;
    do
    {
        printf("1．Input record\n2. Calculate total and average score of course\n3. Sort in descending order by score\n4. Sort in ascending order by score\n5. Sort in ascending order by student's ID\n6．Search by student's ID\n7．Statistic analysis\n8．List record\n9．Exit\nPlease enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            n = ReadScore(num,score);
            break;
        case 2:
            TotalAndAverage(score,n);
            break;
        case 3:
            PrintDescendingRank(num,score,n);
            break;
        case 4:
            PrintAscendingRank(num,score,n);
            break;
        case 5:
            NumberSort(num,score,n);
            PrintScore(num,score,n);
            break;
        case 6:
            Search(num,score,n);
            break;
        case 7:
            StatisticsAnalysis(score,n);
            break;
        case 8:
            PrintScore(num,score,n);
            break;
        case 9:
            exit(0);
        }
        printf("\n\n----------------------------------------------------\n");
    }while(1);

    return 0;
}

/*录入每个学生的学号和考试成绩。*/
int ReadScore(long num[],int score[])
{
    int n,i=0;
    printf("How many students?\n");
    scanf("%d",&n);

    printf("Please input student's ID and score,format as: (20201111 89)\n");
    for(i = 0; i<n; i++)
    {
        scanf("%ld %d",&num[i],&score[i]);
    }
    printf("Have stored the data successfully,thanks!");

    return n;
}
/*计算课程的总分和平均分。*/
void TotalAndAverage(int score[],int n)
{
    int total = 0,i = 0;
    float average;

    for(;i < n;i++)
    {
        total += score[i];
    }

    average = ((float)total)/n;

    printf("Total score: %d\nAverage score: %.2f\n",total,average);
}

/*用选择排序法将学号和分数按分数降序排序*/
void SelectionSort(long num[],int score[],int n)
{
    int i,j,k;
    for(i =0;i<n-1;i++)
    {
        k = i;
        for(j = i+1;j < n;j++)
        {
            if(score[k]<score[j])
            {
                k = j;
            }
        }
        if(k != i)
        {
            Swap(&score[k],&score[i]);
            Swap(&num[k],&num[i]);
        }
    }
}

/*交换两个long数据*/
void Swap(long *x,long *y)
{
    long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*按学号由小到大排序*/
void NumberSort(long num[],int score[],int n)
{
    int i,j,k;
    for(i =0;i<n-1;i++)
    {
        k = i;
        for(j = i+1;j < n;j++)
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
        }
    }
}

/*按学号查询学生排名及其考试成绩。*/
void Search(long num[],int score[],int n)
{
    SelectionSort(num,score,n);

    long number;
    int find = 0;

    printf("Input student's number: ");
    scanf("%ld",&number);

    for(; n > 0; n--)
    {
        if(num[n-1] == number)
        {
            printf("Score: %d\n",score[n-1]);
            printf("Rank: %d\n",n);
            find = 1;
        }
    }

    if(!find)
    {
        printf("Not found!");
    }
}

/*按优秀（90—100分）、良好（80—89分）、中等（70—79分）、及格（60一69分）、不及格
(0—59分)5个类别，统计每个类别的人数以及所占的百分比。*/
void StatisticsAnalysis(int score[],int n)
{
    int i = 0;
    int level[5]={0,0,0,0,0};       /*5个类别的人数*/
    for(;i < n;i++)
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

/*输出每个学生的学号、考试成绩。*/
void PrintScore(long num[],int score[],int n)
{
    int i;
    printf("Number\tScore\n");

    for(i = 0;i<n;i++)
    {
        printf("%ld\t%d\n",num[i],score[i]);
    }
}

/*按成绩由高到低排出名次表。*/
void PrintDescendingRank(long num[],int score[],int n)
{
    SelectionSort(num,score,n);
    int i;
    printf("Rank\tNumber\tScore\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%ld\t%d\n",i+1,num[i],score[i]);
    }
}

/*按成绩由低到高排出名次表。*/
void PrintAscendingRank(long num[],int score[],int n)
{
    SelectionSort(num,score,n);
    printf("Rank\tNumber\tScore\n");

    for(;n>0;n--)
    {
        printf("%d\t%ld\t%d\n",n,num[n-1],score[n-1]);
    }
}







