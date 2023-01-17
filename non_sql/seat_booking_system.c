#include <stdio.h>

int seats[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 1 means the seat is available, 0 means it is booked

void bookTicket() {
    int seatNumber;
    printf("Enter seat number: ");
    scanf("%d", &seatNumber);
    if (seats[seatNumber - 1] == 1) {
        seats[seatNumber - 1] = 0;
        printf("Ticket booked successfully.\n");
    } else {
        printf("Sorry, seat is already booked.\n");
    }
}

void cancelTicket() {
    int seatNumber;
    printf("Enter seat number: ");
    scanf("%d", &seatNumber);
    if (seats[seatNumber - 1] == 0) {
        seats[seatNumber - 1] = 1;
        printf("Ticket canceled successfully.\n");
    } else {
        printf("Sorry, seat is not booked.\n");
    }
}

void displayAvailableSeats() {
    printf("Available seats: ");
    for (int i = 0; i < 10; i++) {
        if (seats[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Book a ticket\n");
        printf("2. Cancel a ticket\n");
        printf("3. Display available seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
                displayAvailableSeats();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
