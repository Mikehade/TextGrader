#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int letter(int n, char arrl[]); //calling of letter function
float  word(int n, char arrw[]);  //calling of word function
float  sen(int m, char arrs[]);   //calling of sentence function

int main()
{
    string s = get_string("Text: ");    //get sentence input
    int n = strlen(s);      //declare variable to assing string length
    int a = letter(n, s);       //declare variable a and get return value from letter function
    float b = word(n, s) + 1;     //declare variable b and get return value from word function
    float c = sen(n, s);      //declare variable c and get return value from sentence function
    float g, h;
    g = (a * 100) / b; //get average value of letter per 100 words
    h = (c * 100) / b;      //gets value of sentence per 100 words
    int x = round((g * 0.0588) - (h * 0.296) - 15.8);   //use index formula to solve for grade
    if (x < 1)
    {
        printf("Before Grade 1\n"); //if grade is less than 1 output before grade 1
    }
    else if (x > 16)
    {
        printf("Grade 16+\n");  //if grade is greater than 16, output grade 16+
    }
    else
    {
        printf("Grade %i\n", x);    //if grade falls within range then output value of x
    }
}
float sen(int m, char arrs[]) //letter function
{
    int sums = 0;
    for (int l = 0; l < m; l++)     //for loop for taking chars in array and checking each for points to get sentences
    {
        if (arrs[l] == 46  || arrs[l] == 33)        //using ascii table to know if a char is point or exclamation
        {
            sums = sums + 1;    //then add 1
        }
        if (arrs[l] == 63)      //using ascii table to know if a char is question mark
        {
            sums = sums + 1;    //also add 1
        }
        else 
        {
            sums = sums + 0;    //else sum s is 0
        }
    }
    return sums;    //output value of sums
}


float  word(int n, char arrw[])   //word function
{
    int sumw = 0;
    for (int k = 0; k < n; k++)     //for loop to check chars in array one after the other
    {
        if (arrw[k] == 32  && arrw[k + 1] != 32)    //if char is space and next char is not espace
        {
            sumw = sumw + 1;        //add 1
        }
        else 
        {
            sumw = sumw + 0;        //else add 0
        }  
    }
    return sumw;
}


int letter(int n, char arrl[])  //letter function
{
    int sum = 0;
    for (int k = 0; k < n; k++)     //for loop to check chars in array one after the other
    {
        if (arrl[k] >= 65 && arrl[k] <= 122)    //if char falls within alphabet range
        {
            sum = sum + 1;      //add 1
        }
        else 
        {
            sum = sum + 0;  //else add zero
        }
    
    }
    return sum;
}








/*
int letter(int n, char arrl[])
{
    int sum = 0;
    for(int k = 0; k < n; k++)
    {
        //char t = toupper (arrl[k]);
        if(toupper (arrl[k]) >= 'A' && toupper (arrl[k]) <= 'Z')
        {
            sum = sum + 1;
        }
        else 
        {
            sum = sum + 0;
        }
    
    }
    return sum;
    
} */
