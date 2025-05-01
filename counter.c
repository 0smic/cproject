#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 12

typedef struct day{
    int count;
    int date;
} day_t;

typedef struct month {
    int count;
    struct day *days;
} months_t;

void insert_month(int date, months_t *months);
void insert_days_details(months_t *months, int index);
void read_counter(months_t *months,int date);

void main(){
    int date;
    months_t* months = malloc(sizeof(months_t) * TABLE_SIZE);
    printf("Enter the date (ddmmyy): ");
    scanf("%d",&date);
    insert_month(date,months);    
}

void insert_month(int date,months_t *months){
    int index = hash(date);
    index = hash(date);
    months[index].count = 0;
    printf("%d", months[index].count);
    insert_days_details(months,index);
    read_counter(months,date);
}

void insert_days_details(months_t *months, int index){
    int count;
    day_t *tmp_days = malloc(sizeof(day_t)*30);
    for (int i=0;i<30;i++){
        printf("Enter the count of [%d]: ",i);
        scanf("%d",&tmp_days[i].count);
        printf("\ncount : %d\n",tmp_days[i].count);
    }
    while(1){
        if (months[index].days == NULL){
            months[index].days = tmp_days;   
            return;
        }
        index++;
    }
}

void read_counter(months_t *months,int date){
    int index = hash(date);
    months_t month = months[index];
    day_t *tmp_days = months[index].days;
    for (int i=0;i<30;i++){
        printf("\nDay[%d]: %d",i,tmp_days[i].count);
    }
}

int hash(int date){
    return ((date*295) /2) % TABLE_SIZE;
}
