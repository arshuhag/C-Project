#include<stdio.h>
#include<string.h>
#include<conio.h>
struct bus
{
 char passenger[50];
 char mobile[20];
 char bus_name[50];
 char bus_no[10];
 char seat_no[10];
 char dep_time[20];
 char dep_date[20];
 char destination[50];
};

 int main()
 {
     int option, i;
     printf("\t\t\t  BUS RESERVATION SYSTEM....\n");
     printf("\n1. Reserve Ticket.\n");
     printf("\n2. View Available Buses.\n");
     printf("\n3. View Reserved List.\n");
     printf("\n4. Exit.\n");
     printf("\nChose your option: ");
     scanf("%d", &option);

     if(option==1) {
        printf("\nReserve Ticket.\n");
        printf("\nHow many ticket do you went to reserve: ");
        int ticket;
        scanf("%d", &ticket);
        struct bus a[ticket];
        for(i=0;i<ticket;i++) {
            printf("\nPassenger's Name: ");
            scanf("%s", a[i].passenger);
            printf("Passenger's Mobile Number: ");
            scanf("%s", a[i].mobile);
            printf("Bus Name: ");
            scanf("%s", a[i].bus_name);
            printf("Bus no: ");
            scanf("%s", a[i].bus_no);
            printf("Seat no: ");
            scanf("%s", a[i].seat_no);
            printf("Departure Time: ");
            scanf("%s", a[i].dep_time);
            printf("Departure Date: ");
            scanf("%s", a[i].dep_date);
            printf("Destination: ");
            scanf("%s", a[i].destination);
        }
        printf("Ticket Reserved Successfully...\n");
        freopen("ticket-reserve.txt", "a+", stdout);
        for(i=0;i<ticket;i++) {
            printf("Passenger's Name: %s\n", a[i].passenger);
            printf("Passenger's Mobile Number: %s\n", a[i].mobile);
            printf("Bus Name: %s\n", a[i].bus_name);
            printf("Bus No: %s\n", a[i].bus_no);
            printf("Seat No: %s\n", a[i].seat_no);
            printf("Departure Time: %s\n", a[i].dep_time);
            printf("Departure Date: %s\n", a[i].dep_date);
            printf("Destination: %s\n", a[i].destination);
            }
     }
     else if(option==2) {
        FILE *availability;
        char r[10000];
        availability = fopen("availabe-buses.txt", "r");
        if(!availability) {
            return 1;
        }
        while(fgets(r, 10000, availability)!= NULL) {
            printf("%s", r);
        }
        fclose(availability);
     }
     else if(option==3) {
        printf("\nReserved List:\n\n");
        FILE *reserved_open;
        char r[1000];
        reserved_open = fopen("ticket-reserve.txt", "r");
        if(!reserved_open) {
            return 1;
        }
        while(fgets(r, 1000, reserved_open)!= NULL) {
            printf("%s", r);
        }
        fclose(reserved_open);
     }
 getch();
}
