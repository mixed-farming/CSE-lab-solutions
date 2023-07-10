#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passenger 
{
    char name[50];
    char mobile_number[15];
    char food_option;
} Passenger;

typedef struct Coach 
{
    char coach_type[3];
    char coach_number[4];
    Passenger passengers[10];
    struct Coach* next;
} Coach;

typedef struct Train 
{
    Coach* header;
    int cc_coaches;
    int ec_coaches;
    Coach* tail_cc;
    Coach* tail_ec;
} Train;

Passenger create_passenger(char name[], char mobile_number[], char food_option) 
{
    Passenger passenger;
    strcpy(passenger.name, name);
    strcpy(passenger.mobile_number, mobile_number);
    passenger.food_option = food_option;
    return passenger;
}

Coach* create_coach(char coach_type[], char coach_number[]) 
{
    Coach* coach = (Coach*)malloc(sizeof(Coach));
    strcpy(coach->coach_type, coach_type);
    strcpy(coach->coach_number, coach_number);
    coach->next = NULL;
    return coach;
}

void display_chart(Train* train) 
{
    Coach* current = train->header->next;
    printf("=== Chart ===\n");
    while (current != NULL) 
    {
        
        if (strcmp(current->coach_type, "CC") == 0) 
        {
            for (int i = 0; i < 10; i++) 
            {
                if (strlen(current->passengers[i].name) > 0) 
                {
                    printf("Coach: %s, Type: %s, Name: %s, Mobile: %s\n",
                           current->coach_number, current->coach_type,
                           current->passengers[i].name, current->passengers[i].mobile_number);
                }
            }
        }
            
        else if (strcmp(current->coach_type, "EC") == 0) 
        {
            for (int i = 0; i < 5; i++) 
            {
                if (strlen(current->passengers[i].name) > 0)
                {
                    printf("Coach: %s, Type: %s, Name: %s, Mobile: %s, Food: %c\n",
                           current->coach_number, current->coach_type,
                           current->passengers[i].name, current->passengers[i].mobile_number,
                           current->passengers[i].food_option);
                }
            }
        }
        current = current->next;
    }
}

void book_seat(Train* train) 
{
    char coach_type[3];
    printf("Enter coach type (CC/EC): ");
    scanf("%s", coach_type);
    
    if (strcmp(coach_type, "CC") != 0 && strcmp(coach_type, "EC") != 0) 
    {
        printf("Invalid coach type.\n");
        return;
    }

    if (strcmp(coach_type, "CC") == 0) 
    {
        if (train->cc_coaches == 0) 
        {
            printf("No more CC coaches available.\n");
            return;
        }
        Coach* coach = create_coach("CC", "CC");
        sprintf(coach->coach_number, "CC%d", train->cc_coaches);
        train->cc_coaches--;
        train->tail_cc->next = coach;
        train->tail_cc = coach;
    }
        
    else 
    {
        if (train->ec_coaches == 0) 
        {
            printf("No more EC coaches available.\n");
            return;
        }
        
        Coach* coach = create_coach("EC", "EC");
        sprintf(coach->coach_number, "EC%d", train->ec_coaches);
        train->ec_coaches--;
        train->tail_ec->next = coach;
        train->tail_ec = coach;
    }

    Coach* coach = (strcmp(coach_type, "CC") == 0) ? train->tail_cc : train->tail_ec;
    int capacity = (strcmp(coach->coach_type, "CC") == 0) ? 10 : 5;
    for (int i = 0; i < capacity; i++) 
    {
        if (strlen(coach->passengers[i].name) == 0) 
        {
            char name[50];
            char mobile_number[15];
            printf("Enter passenger name: ");
            scanf("%s", name);
            printf("Enter passenger mobile number: ");
            scanf("%s", mobile_number);

            if (strcmp(coach_type, "CC") == 0) 
            {
                coach->passengers[i] = create_passenger(name, mobile_number, ' ');
            }
                
            else 
            {
                char food_option;
                printf("Enter food option [V/N]: ");
                scanf(" %c", &food_option);
                coach->passengers[i] = create_passenger(name, mobile_number, food_option);
            }
            printf("Seat booked successfully.\n");
            return;
        }
    }

    printf("No more seats available in this coach.\n");
}

void departure(Train* train) {
    if (train->header->next == NULL) 
    {
        printf("No coaches to detach.\n");
        return;
    }

    Coach* detached_coach = train->header->next;
    train->header->next = detached_coach->next;

    if (strcmp(detached_coach->coach_type, "CC") == 0) 
    {
        train->cc_coaches++;
    }
    else 
    {
        train->ec_coaches++;
    }

    printf("Coach %s detached from the train.\n", detached_coach->coach_number);
    
    free(detached_coach);
}

int main() {
    Train goa_express;
    goa_express.header = create_coach("Engine", "H");
    goa_express.cc_coaches = 3;
    goa_express.ec_coaches = 2;
    goa_express.tail_cc = goa_express.header;
    goa_express.tail_ec = goa_express.header;

    int choice;
    
    do 
    {
        printf("\n=== Goa Express Menu ===\n");
        printf("1. Display Chart\n");
        printf("2. Book Seat\n");
        printf("3. Departure\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                display_chart(&goa_express);
                break;
            case 2:
                book_seat(&goa_express);
                break;
            case 3:
                departure(&goa_express);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (goa_express.cc_coaches == 0 && goa_express.ec_coaches == 0) 
        {
            printf("No coaches to detach.\n");
            choice = 4; // Exit the loop
        }
        
    } while (choice != 4);

    return 0;
}
