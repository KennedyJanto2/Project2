/* 
CS2600 Project2: Travel Expenses
Liangjie Shen
2/7/2022
*/

#include <stdio.h> // input/output library
#include <string.h> // string library including strlen()
#include <ctype.h> // isdigit()
#include <stdbool.h> // boolean function

// function declaration
bool timeFormat(char[]);

int main()
{
    int day = 0;
    char departTime[8];
    char arrivalTime[8];

    printf("Welcome to Travel Expense Calculator!\n");
    printf("Please enter the following information for the trip:!\n\n");

    while(day < 1){
        printf("The total number of days spent on the trip[1 or more]: ");
        scanf("%d", &day);
        if(day < 1)
            printf("Number of days cannot be less than 1! Try again!\n");
    }

    while(!timeFormat(departTime)){
        printf("The time of departure on the first day of the trip:[##:## AM/PM] ");
        scanf("%s",departTime);

        if(!timeFormat(departTime))
            printf("Wrong depart time format!\n");
        
    }

    while(!timeFormat(arrivalTime)){
        printf("The time of arrival back home on the last day of the trip:[##:## AM/PM] ");
        scanf("%s",arrivalTime);
        if(!timeFormat(arrivalTime))
            printf("Wrong arrive time format!\n");
    }
}

bool timeFormat(char validTime[]){
    int counter = 0;
    if(isdigit(validTime[counter])){ 

        if(validTime[counter] == '1' && isdigit(validTime[counter+1])){
            counter++;
            if(validTime[counter] >= '0' && validTime[counter] <='9'){
                counter++;
            }
        }

        else if(validTime[counter] >= '0' && validTime[counter] <='9')
            counter++;

        else    
            return false;

        if(validTime[counter] == ':'){
            counter++;
            if(isdigit(validTime[counter])&& isdigit(validTime[counter+1])){
                if(validTime[counter] >= '0' && validTime[counter] <='9' && validTime[counter+1] >= '0' && validTime[counter+1] <='9'){
                    counter+=2;
                    if(validTime[counter] == ' '){
                        counter++;
                        if((validTime[counter] == 'A' || validTime[counter] == 'P') && validTime[counter+1] == 'M')
                            return true;

                    }
                }
            }

        }

    }

    return false;


}