#include<stdio.h>

//Calculating the percentage of passed students
void Calculate(int stdNum, int passNum)
{
    float passPerc;//Variable to store the %value

    if(stdNum < 0)//Student number cant be - ve
        printf("Student number can't be -ve\n");

    else if(passNum < 0)//Similarly pass number cant be -ve
        printf("Passing students cant be in -ve\n");

    else if(passNum > stdNum)//Also pass number cant be more than total students
        printf("Number of students passed cannot be more than total students !\n");
    else
        {
            //Printing the percentage
            passPerc = (float) passNum / stdNum * 100.0000;
            printf("%0.2f percentage of students have passed\n",passPerc);
        }
    
}
int main(int argc, char const *argv[])
{
    //Getting input
    int totalStudents, passedStudents;
    printf("How many students do you have ?: \n");
    scanf("%d",&totalStudents);//Total students

    printf("How many students have passed in total ?: ");
    scanf("%d",&passedStudents);//passed students

    //Invoking method
    Calculate(totalStudents, passedStudents);
    return 0;
}
