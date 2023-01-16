#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//INITIALIZING THE DATABASE-------------------------------------------------------------------------
char movies[][50] = {"Avatar 2: The Way Of Waters", "Robot 2                      ", "Mr. Robot                  ", "Wanna_Hack_Society       "};
char customer_name[][100] = {""};
int booked_tickets[100][50];
int cancelled_tickets[100][50];
int available_tickets[50] = {96, 69, 59, 70};
int booking_count;
//---------------------------------------------------------------------------------------------------

void show_menu();
void list_movies();
void book_show();
void cancel_show();
void generate_receipt();
void dump_data();
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int main(){
    int q = 0;
    int choice, id;
    system("clear");
    while(q == 0){
        show_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            list_movies();
            break;

        case 2:
            book_show();
            break;

        case 3:
            cancel_show();
            break;

        case 4:
            printf("\nPlease enter the Customer ID: ");
            scanf("%d", &id);
            generate_receipt(id);
            break;

        case 5:
            dump_data();
            break;

        case 6:
            printf("\n\n Thankyou, team MelloB's Cineplex\n\n");
            q = 1;
            break;
        case 7:
            printf("%s", movies[2]);
        
        default:
            printf("Wrong Option!");
            break;
        }
    }
    
}

void show_menu(){
    //system("clear");
    printf("\n\n\t\t\t\tWelcome to MelloB's Cineplex!\n\n\n\n");
    printf("Choose what you want to do :-)\n\n");
    printf("1.) List the number of movies available\n");
    printf("2.) Book a ticket\n");
    printf("3.) Cancel a ticket\n");
    printf("4.) Generate Receipt\n");
    printf("5.) Dump Database Data\n");
    printf("6.) Exit\n");
    printf("7.) Debug\n");
    printf("\nYour choice here:-> ");
}

void list_movies(){
    int i = 0;
    system("clear");
    printf("\t\t\t\tWelcome to MelloB's Cineplex!\n\n\n\n");
    printf("Movie ID\t \tMovie Name\t \t \tAvailable Tickets\n\n");
    while(i<=3){
        printf("%d\t \t \t%s\t \t%d\n", i, movies[i], available_tickets[i]);
        delay(1);
        i = i+1;
    }
    system("exit");
}

void book_show(){
    char cus_name[50];
    int movie_id, user_id, tickets, confirm = 0;
    user_id = booking_count;
    printf("\n--------------------------------BOOKING PORTAL-------------------------------");
    printf("\nPlease enter Movie ID: ");
    scanf("%d", &movie_id);
    printf("\nPlease enter the number of tickets and customer name(MAX_LIMIT=50): ");
    scanf("%d\n", &tickets);
    //printf("\n\nPlease enter customer name(MAX_LIMIT=50):- ");
    fgets(cus_name, 50, stdin);
    
    while(confirm == 0){
        printf("\n\nPlease enter 1 to confirm booking: ");
        scanf("%d", &confirm);
    }
    
    strcpy(customer_name[booking_count], cus_name);
    booked_tickets[user_id][movie_id] = tickets;
    available_tickets[movie_id] = available_tickets[movie_id] - tickets;
    booking_count = booking_count + 1;
    printf("\n------------------------------BOOKING COMPLETE--------------------------------");
}

void cancel_show(){
    char cus_name[50];
    int movie_id, user_id, tickets, confirm = 0;
    user_id = booking_count;
    printf("\n--------------------------------CANCELING PORTAL-------------------------------");
    printf("\nPlease enter Movie ID: ");
    scanf("%d", &movie_id);
    printf("\nPlease enter the number of tickets: ");
    scanf("%d", &tickets);
    printf("\n\nPlease enter Customer ID:- ");
    scanf("%d", &user_id);
    
    while(confirm == 0){
        printf("\n\nPlease enter 1 to confirm cancellation: ");
        scanf("%d", &confirm);
    }
    
    cancelled_tickets[user_id][movie_id] = tickets;
    available_tickets[movie_id] = available_tickets[movie_id] + tickets;
    printf("\n------------------------------CANCELING COMPLETE--------------------------------");
}

void generate_receipt(int user_id){
    int i = 0;
    printf("\n\n\n\n==============================================================MELLOB's CINEPLEX======================================================================");
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\tCustomer ID:\t\t\t\t%d\n", user_id);
    printf("\n\t\tCustomer Name:\t\t\t\t%s", customer_name[user_id]);
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\t\tMovie ID\t\t\tBooked Tickets\t\t\tCancelled Tickets\t\t\tNet Tickets\n\n");
    while(i<=3){
        if(booked_tickets[user_id][i] != 0 || cancelled_tickets[user_id][i] != 0)
            printf("\n\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d", i, booked_tickets[user_id][i], cancelled_tickets[user_id][i], booked_tickets[user_id][i]-cancelled_tickets[user_id][i]);
        i = i+1;
    }
    printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------");
}

void dump_data(){
    int i = 0;
    printf("\n\n\n\nDUMPING DATABASE DATA----------------------------------------------------");
    printf("Number of tickets booked: %d", booking_count);
    list_movies();
    printf("\n\n");
    while (i<=booking_count)
    {
        generate_receipt(i);
        i = i+1;
    }
    printf("\n\n\n\nDUMP COMPLETE-------------------------------------------------------------");
}