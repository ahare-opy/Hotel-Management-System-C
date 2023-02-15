#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct res{
    int code,price;
    char name[250],BDT[5];
};

struct Res{
    int room,code,quantity,price;
};

typedef struct ro{
    int room;
    char Name[20];
    int PNumber;
    int period;
    char city[20];
    char nationality[20];
    int member;
    char date[15];
    float expense;
}Room;

typedef struct tra{
  int room;
  char Name[100];
  char TType[100];
  char Pickup[100];
  char Destination[100];
  char time[20];
  float distance;
  float fare;
}Transpor;

Transpor C[100];

Room A[50];

struct Res R[40];
struct res TB[40],TL[40],TD[40],Tb[40];

FILE *w,*a,*r;

void Load()
{
    r=fopen("Hotel Log.txt","r");

    int i;

    for(i=0;i<50;i++)
    {
        fscanf(r,"%d %s %d %d %s %s %d %s %f",&A[i].room,A[i].Name,&A[i].PNumber,&A[i].period,A[i].city,A[i].nationality,&A[i].member,A[i].date,&A[i].expense);
    }
    fclose(r);
}

void Update()
{
    w=fopen("Hotel Log.txt","w");
    int i;

    for(i=0;i<50;i++)
    {
        fprintf(w,"%d\t%s\t\t%d\t\t%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%.2f\n",i+1,A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].date,A[i].expense);
    }
    fclose(w);
}

void Reset()
{
    int i;
    w=fopen("Hotel Log.txt","w");
    r=fopen("Hotel Log.txt","r");

    for(i=0;i<50;i++)
    {
        fprintf(w,"%d\tN/A\t\t0\t\t0\t\tN/A\t\tN/A\t\t0\t\t00/00/0000\t0.00\n",i+1);
    }
    fclose(w);

    for(i=0;i<50;i++)
    {
        fscanf(r,"%d %s %d %d %s %s %d %s %f",&A[i].room,A[i].Name,&A[i].PNumber,&A[i].period,A[i].city,A[i].nationality,&A[i].member,A[i].date,&A[i].expense);
    }
    fclose(r);
}

void showcus()
{
    int i;
    Load();

    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("Room\tCustomer\tPhone\t\tStay\t\tCity\t\tNatio\t\tMember\t\tArrival\t\t\tTotal\n");
    printf("NO.\tName\t\tNumber\t\tPeriod\t\tName\t\tality\t\tStaying\t\tDate\t\t\tExpense\n\n\n\n");
    for(i=0;i<50;i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%s\t\t%s\t\t%d\t\t%s\t\t%.2f\n",A[i].room,A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].date,A[i].expense);
    }

    printf("\n\n\n\n\n");
    system("Pause");
    system("CLS");
}

int countTransport()
{
    int lines=0;
    char ch;
    r=fopen("Transport.txt","r");

    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            ++lines;
        }
    }
    fclose(r);
    return lines;
}

void TransportLoad()
{
    int i,lines;
    lines = countTransport();

    r=fopen("Transport.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %s %s %s %f %f %[^\n]",&C[i].room,C[i].Name,C[i].Pickup,C[i].Destination,C[i].time,&C[i].distance,&C[i].fare,C[i].TType);
    }
    fclose(r);

}

void Check_In()
{
    while(1)
    {
        system("color FC");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t\t\t>>>Check In Menu<<<\n\n\n\n");
        printf("\t\t\t>>>Room Types<<<\n\n\n\n\n");
        printf("1. Super Deluxe\n2. Couple Deluxe\n3. Deluxe\n4. Couple\n5. Single\n\n6. Exit\n\n\nYour Choice....   ");

        int choice;

        scanf("%d",&choice);

        system("CLS");
        switch(choice)
        {
        case 1:
            Super_Deluxe();
            break;
        case 2:
            Couple_Deluxe();
            break;
        case 3:
            Deluxe();
            break;
        case 4:
            Couple();
            break;
        case 5:
            Single();
            break;
        case 6:
            printf("\n\tYou are returning to main menu\n\n\n");
            system("Pause");
            system("CLS");
            return 0;

        }
    }
}

void Super_Deluxe()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Room Features<<<\n\n\n\n");
    printf("Room Type\t: Super Deluxe\nPrice per day\t: BDT 10000\nBed Number\t: 4\nCapacity\t: 6 People\n\n\n\nPress 1\t: Continue\n\nPress 0\t: Return\n\n\n\nYour Choice.... ");
    int p;
    scanf("%d",&p);
    if(p==0) return 0;
    system("CLS");
    Load();
    int i,j,a=0;
    char b[5]="N/A";

    for(j=0;j<10;j++)
    {
        if(strcmp(A[j].Name,"N/A")==0)
        {
            printf("Free Room No. -\t%d\n",A[j].room);
            a++;
        }
    }
    if(a==0) printf("\n\n\tNo vacant room\n\n\n\n");
    else
    {
        printf("\n\n\n\t\t\t\t\t>>>Check In Process<<<\n\n\n");
        printf("Enter the room No.\t\t: ");
        scanf("%d ",&j);
        i=j-1;
        printf("Enter your first name\t\t: ");
        scanf("\n");
        scanf("%s",A[i].Name);
        printf("Enter Phone Number\t\t: ");
        scanf("%d",&A[i].PNumber);
        printf("Enter period of your stay\t:");
        scanf("%d",&A[i].period);
        printf("Enter your City name\t\t: ");
        scanf("%s",A[i].city);
        printf("Enter your Nationality\t\t: ");
        scanf("%s",&A[i].nationality);
        printf("Enter No. of total people\t: ");
        scanf("%d",&A[i].member);
        printf("Enter arrival date\t\t: ");
        scanf("%s",&A[i].date);
        A[i].expense=10000*A[i].period;

        printf("\n\n\n\nCheck In successful\n\n\n");
        system("Pause");
        system("CLS");
        Update();
    }
}

void Couple_Deluxe()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Room Features<<<\n\n\n\n");
    printf("Room Type\t: Couple Deluxe\nPrice per day\t: BDT 8000\nBed Number\t: 3\nCapacity\t: 4 People\n\n\n\nPress 1\t: Continue\n\nPress 0\t: Return\n\n\n\nYour Choice.... ");
    int p;
    scanf("%d",&p);
    if(p==0) return 0;
    system("CLS");
    Load();
    int i,j,a=0;
    char b[5]="N/A";

    for(j=10;j<20;j++)
    {
        if(strcmp(A[j].Name,"N/A")==0)
        {
            printf("Free Room No. -\t%d\n",A[j].room);
            a++;
        }
    }
    if(a==0) printf("\n\n\tNo vacant room\n\n\n\n");
    else
    {
        printf("\n\n\n\t\t\t\t\t>>>Check In Process<<<\n\n\n");
        printf("Enter the room No.\t\t: ");
        scanf("%d ",&j);
        i=j-1;
        printf("Enter your first name\t\t: ");
        scanf("\n");
        scanf("%s",A[i].Name);
        printf("Enter Phone Number\t\t: ");
        scanf("%d",&A[i].PNumber);
        printf("Enter period of your stay\t:");
        scanf("%d",&A[i].period);
        printf("Enter your City name\t\t: ");
        scanf("%s",A[i].city);
        printf("Enter your Nationality\t\t: ");
        scanf("%s",&A[i].nationality);
        printf("Enter No. of total people\t: ");
        scanf("%d",&A[i].member);
        printf("Enter arrival date\t\t: ");
        scanf("%s",&A[i].date);
        A[i].expense=8000*A[i].period;

        printf("\n\n\n\nCheck In successful\n\n\n");
        system("Pause");
        system("CLS");
        Update();
    }
}

void Deluxe()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Room Features<<<\n\n\n\n");
    printf("Room Type\t: Deluxe\nPrice per day\t: BDT 6000\nBed Number\t: 2\nCapacity\t: 6 People\n\n\n\nPress 1\t: Continue\n\nPress 0\t: Return\n\n\n\nYour Choice.... ");
    int p;
    scanf("%d",&p);
    if(p==0) return 0;
    system("CLS");
    Load();
    int i,j,a=0;
    char b[5]="N/A";

    for(j=20;j<30;j++)
    {
        if(strcmp(A[j].Name,"N/A")==0)
        {
            printf("Free Room No. -\t%d\n",A[j].room);
            a++;
        }
    }
    if(a==0) printf("\n\n\tNo vacant room\n\n\n\n");
    else
    {
        printf("\n\n\n\t\t\t\t\t>>>Check In Process<<<\n\n\n");
        printf("Enter the room No.\t\t: ");
        scanf("%d ",&j);
        i=j-1;
        printf("Enter your first name\t\t: ");
        scanf("\n");
        scanf("%s",A[i].Name);
        printf("Enter Phone Number\t\t: ");
        scanf("%d",&A[i].PNumber);
        printf("Enter period of your stay\t:");
        scanf("%d",&A[i].period);
        printf("Enter your City name\t\t: ");
        scanf("%s",A[i].city);
        printf("Enter your Nationality\t\t: ");
        scanf("%s",&A[i].nationality);
        printf("Enter No. of total people\t: ");
        scanf("%d",&A[i].member);
        printf("Enter arrival date\t\t: ");
        scanf("%s",&A[i].date);
        A[i].expense=6000*A[i].period;

        printf("\n\n\n\nCheck In successful\n\n\n");
        system("Pause");
        system("CLS");
        Update();
    }
}

void Couple()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Room Features<<<\n\n\n\n");
    printf("Room Type\t: Couple\nPrice per day\t: BDT 4000\nBed Number\t: 2\nCapacity\t: 3 People\n\n\n\nPress 1\t: Continue\n\nPress 0\t: Return\n\n\n\nYour Choice.... ");
    int p;
    scanf("%d",&p);
    if(p==0) return 0;
    system("CLS");
    Load();
    int i,j,a=0;
    char b[5]="N/A";

    for(j=30;j<40;j++)
    {
        if(strcmp(A[j].Name,"N/A")==0)
        {
            printf("Free Room No. -\t%d\n",A[j].room);
            a++;
        }
    }
    if(a==0) printf("\n\n\tNo vacant room\n\n\n\n");
    else
    {
        printf("\n\n\n\t\t\t\t\t>>>Check In Process<<<\n\n\n");
        printf("Enter the room No.\t\t: ");
        scanf("%d ",&j);
        i=j-1;
        printf("Enter your first name\t\t: ");
        scanf("\n");
        scanf("%s",A[i].Name);
        printf("Enter Phone Number\t\t: ");
        scanf("%d",&A[i].PNumber);
        printf("Enter period of your stay\t:");
        scanf("%d",&A[i].period);
        printf("Enter your City name\t\t: ");
        scanf("%s",A[i].city);
        printf("Enter your Nationality\t\t: ");
        scanf("%s",&A[i].nationality);
        printf("Enter No. of total people\t: ");
        scanf("%d",&A[i].member);
        printf("Enter arrival date\t\t: ");
        scanf("%s",&A[i].date);
        A[i].expense=4000*A[i].period;

        printf("\n\n\n\nCheck In successful\n\n\n");
        system("Pause");
        system("CLS");
        Update();
    }
}

void Single()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Room Features<<<\n\n\n\n");
    printf("Room Type\t: Single\nPrice per day\t: BDT 2000\nBed Number\t: 1\nCapacity\t: 2 People\n\n\n\nPress 1\t: Continue\n\nPress 0\t: Return\n\n\n\nYour Choice.... ");
    int p;
    scanf("%d",&p);
    if(p==0) return 0;
    system("CLS");
    Load();
    int i,j,a=0;
    char b[5]="N/A";

    for(j=40;j<50;j++)
    {
        if(strcmp(A[j].Name,"N/A")==0)
        {
            printf("Free Room No. -\t%d\n",A[j].room);
            a++;
        }
    }
    if(a==0) printf("\n\n\tNo vacant room\n\n\n\n");
    else
    {
        printf("\n\n\n\t\t\t\t\t>>>Check In Process<<<\n\n\n");
        printf("Enter the room No.\t\t: ");
        scanf("%d",&j);
        i=j-1;
        printf("Enter your first name\t\t: ");
        scanf("\n");
        scanf("%s",A[i].Name);
        printf("Enter Phone Number\t\t: ");
        scanf("%d",&A[i].PNumber);
        printf("Enter period of your stay\t: ");
        scanf("%d",&A[i].period);
        printf("Enter your City name\t\t: ");
        scanf("%s",A[i].city);
        printf("Enter your Nationality\t\t: ");
        scanf("%s",&A[i].nationality);
        printf("Enter No. of total people\t: ");
        scanf("%d",&A[i].member);
        printf("Enter arrival date\t\t: ");
        scanf("%s",&A[i].date);
        A[i].expense=2000*A[i].period;

        printf("\n\n\n\nCheck In successful\n\n\n");
        system("Pause");
        system("CLS");
        Update();
    }
}

void Check_Out() //main+sub
{
    system("color E0");
    TransportLoad();
    Load();
    load_res();
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Check Out Menu<<<\n\n\n\n");
    int p,i,j;
    int lines = countTransport();
    int c= count_res();
    printf("Enter Room Number\t: ");
    scanf("%d",&p);

    i=p-1;
    if(strcmp(A[i].Name,"N/A")!=0){ printf("\n\n\nCustomer Name\t\t: %s\nPhone Number\t\t: %d\nPeriod of stay\t\t: %d\nCity name\t\t: %s\nNationality\t\t: %s\nNo. of total people\t: %d\n\n\nTotal Bill\t\t: %.2f\n\n\n\n",A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].expense);

    strcpy(A[i].Name,"N/A");
    strcpy(A[i].city,"N/A");
    strcpy(A[i].nationality,"N/A");
    strcpy(A[i].date,"00/00/0000");
    A[i].period=0,A[i].PNumber=0,A[i].expense=0.00,A[i].member=0;

    w=fopen("Transport.txt","w");
    for(i=0;i<lines;i++)
    {
        if(C[i].room != p)
        {
            fprintf(w,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%s\n",C[i].room,C[i].Name,C[i].Pickup,C[i].Destination,C[i].time,C[i].distance,C[i].fare,C[i].TType);
        }
    }
    fclose(w);


    a=fopen("Restaurent Log.txt","w");
    for(j=0;j<c;j++)
    {
        if(R[j].room!=p && R[j].room!=0)
        {
            fprintf(a,"%d %d %d %d\n",R[j].room,R[j].code,R[j].quantity,R[j].price);
        }
    }
    fclose(a);
    Update();
    }

    else printf("\n\n\n\n\t\tNo customer available\n\n\n");

    system("Pause");
    system("CLS");
}

void Hotel_Service() //main+sub
{
    while(1)
    {
        system("color A0");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");

        printf("Press 1\t: Restaurent\nPress 2\t: Laundry\nPress 3\t: Transport\nPress 4\t: Massage\nPress 5\t: Exit\n\n\n\nYour choice... ");
        int c;
        scanf("%d",&c);
        system("CLS");

        switch(c)
        {
            case 1:
                Restaurent();
                break;
            case 2:
                Laundry();
                break;
            case 3:
                Transport();
                break;
            case 4:
                Massage();
                break;
            case 5:
                printf("\n\tYou are returning to main menu\n\n\n");
                system("Pause");
                system("CLS");
                return 0;
        }
    }
}

void Laundry()
{
    Load();
    system("color F4");
    int i,j,d,m;
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Laundry Service<<<\n\n\n\n\n");
    printf("Per piece cloth charge ***BDT 200***\n\n\n\n***You can't cancel order\n\n\nPress 1\t: Continue\nPress 0\t: Exit\n\n\nYour Choice... ");
    scanf("%d",&m);

    if(m==0) return 0;
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Laundry Service<<<\n\n\n\n\n");
    printf("\n\n\n\n\nEnter Room Number\t: ");
    scanf("%d",&d);

    i=d-1;

    if(strcmp(A[i].Name,"N/A")!=0){ printf("\n\n\nCustomer Name\t\t: %s\nPhone Number\t\t: %d\nPeriod of stay\t\t: %d\nCity name\t\t: %s\nNationality\t\t: %s\nNo. of total people\t: %d\n\n\nTotal Bill\t\t: %.2f\n\n\n\n",A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].expense);

    printf("Enter the number of cloths you want to laundry\t: ");
    scanf("%d",&j);
    j*=200;

    A[i].expense+=j;
    printf("\n\n\nYour Total Bill\t: %.2f\n\n\n",A[i].expense);
    }

    else printf("\n\n\n\n\t\tNo customer available\n\n\n");

    system("Pause");
    system("CLS");

    Update();
}

void Transport()
{
    system("color E0");
    Load();

    int i,d,k;
    float j,m;
    char s1[100],s2[100],s3[100],s4[100];
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Transport Service<<<\n\n\n\n\n");
    printf("Mini Bus per KM charges ***BDT 150***\n");
    printf("Private Car per KM charges ***BDT 60***\n");
    printf("Limousine per KM charges ***BDT 100***\n\n\n\n\n");
    printf("Press 1 : Scedule Ride\nPress 2 : Transport History\nPress 0 : Cancel Ride\n\n\nYour Choice... ");
    scanf("%d",&k);

    if(k==0)
        {
            Cancel_Ride();
            return 0;
        }
    else if(k==2)
    {
        TransLog();
        return 0;
    }
    system("ClS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Transport Service<<<\n\n\n\n\n");

    printf("\n\n\n\n\nEnter Room Number\t: ");
    scanf("%d",&d);

    i=d-1;

    if(strcmp(A[i].Name,"N/A")!=0){ printf("\n\n\nCustomer Name\t\t: %s\nPhone Number\t\t: %d\nPeriod of stay\t\t: %d\nCity name\t\t: %s\nNationality\t\t: %s\nNo. of total people\t: %d\n\n\nTotal Bill\t\t: %.2f\n\n\n\n",A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].expense);

    printf("Enter Transport type\t: ");
    scanf("\n");
    scanf("%[^\n]",s3);
    printf("\nEnter Pick Up Location\t: ");
    scanf("\n");
    scanf("%[^\n]",s1);
    printf("\nEnter Drop up Location\t: ");
    scanf("\n");
    scanf("%[^\n]",s2);
    printf("\nEnter Pick Up Time\t: ");
    scanf("\n");
    scanf("%[^\n]",s4);
    printf("\nEnter the distance in KM\t: ");
    scanf("%f",&j);
    if(s3[0]=='M') m=j*150;
    else if(s3[0]=='P') m=j*60;
    else if(s3[0]=='L') m=j*100;

    A[i].expense+=m;
    printf("\n\n\nYour Total Bill\t: %.2f\n\n\n",A[i].expense);
    a=fopen("Transport.txt","a");
    fprintf(a,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%s\n",d,A[i].Name,s1,s2,s4,j,m,s3);
    fclose(a);
    Update();
    }

    else printf("\n\n\n\n\t\tNo customer available\n\n\n");


    system("Pause");
    system("CLS");

}

void TransLog()
{
    TransportLoad();
    Load();

    int lines=countTransport();

    int i,j,k,z=0;
    system("ClS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Transport Service<<<\n\n\n\n\n");
    printf("Enter Room Number\t: ");
    scanf("%d",&k);
    j=k-1;
    if(strcmp(A[j].Name,"N/A")!=0){
    for(i=0;i<lines;i++)
    {
      if(C[i].room==k)
        {
            z++;
            printf("\n\nCustomer Name\t: %s\nTransport Type\t: %s\nPick Up Location\t: %s\nDrop up Location\t: %s\nPick Up Time\t: %s\nDistance in KM\t: %.2f\nTransport Fair\t: %.2f\n\n",C[i].Name,C[i].TType,C[i].Pickup,C[i].Destination,C[i].time,C[i].distance,C[i].fare);
        }
    }
    if(z==0)
    {
        printf("\n\nNo Travel history\n\n");
    }
    }
    else printf("\n\n\n\n\t\tNo customer available\n\n\n");

    system("Pause");
    system("CLS");
}

void Cancel_Ride()
{
    TransportLoad();
    Load();

    int lines=countTransport();

    int i,j,k,z=0,m;
    system("ClS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Transport Service<<<\n\n\n\n\n");
    printf("Enter Room Number\t: ");
    scanf("%d",&k);

    m=k-1;
    if(strcmp(A[m].Name,"N/A")!=0){
    for(i=0;i<lines;i++)
    {
        if(C[i].room==k)
        {
            j=i;
            z++;
        }
    }
    if(z>0){
    for(i=0;i<lines;i++)
    {
      if(i==j)
        {
            printf("\n\nCustomer Name\t: %s\nTransport Type\t: %s\nPick Up Location\t: %s\nDrop up Location\t: %s\nPick Up Time\t: %s\nDistance in KM\t: %.2f\nTransport Fair\t: %.2f\n\n",C[i].Name,C[i].TType,C[i].Pickup,C[i].Destination,C[i].time,C[i].distance,C[i].fare);
            break;
        }
    }
    w=fopen("Transport.txt","w");
    for(i=0;i<lines;i++)
    {
        if(i!=j)
        {
            fprintf(w,"%d\t%s\t%s\t%s\t%s\t%f\t%f\t%s\n",C[i].room,C[i].Name,C[i].Pickup,C[i].Destination,C[i].time,C[i].distance,C[i].fare,C[i].TType);
        }
    }
    fclose(w);

    printf("\n\nRide got cancelled");

    printf("\n\nPrevious Bill\t: %.2f\n\n",A[k-1].expense);

    A[k-1].expense-=C[j].fare;

    printf("Present bill\t: %.2f\n\n\n",A[k-1].expense);

    Update();
    }

    else
    {
        printf("\n\n\nNo Ride Of this room\n\n\n\n");
    }
    }

    else printf("\n\n\n\n\t\tNo customer available\n\n\n");

    system("Pause");
    system("CLS");
}

void Massage()
{
    Load();
    system("color 90");
    int i,j,k;
    char L[15];
    system("ClS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Massage Service<<<\n\n\n\n\n");
    printf("Enter Room Number\t: ");
    scanf("%d",&k);

    i=k-1;

    if(strcmp(A[i].Name,"N/A")!=0){ printf("\n\n\nCustomer Name\t\t: %s\nPhone Number\t\t: %d\nPeriod of stay\t\t: %d\nCity name\t\t: %s\nNationality\t\t: %s\nNo. of total people\t: %d\n\n\nTotal Bill\t\t: %.2f\n\n\n\n",A[i].Name,A[i].PNumber,A[i].period,A[i].city,A[i].nationality,A[i].member,A[i].expense);

    system("pause");
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Massage Service<<<\n\n\n\n\n");
    printf("***Can't Cancel Order\n\n\nPress 1\t: *VIP MASSAGE*\t\t\t\tBDT 6000\n\nPress 2\t: OIL MASSAGE\t\t\t\tBDT 3000\n\nPress 3\t: DRY MASSAGE\t\t\t\tBDT 1000\n\nPress 0\t: EXIT\n\n\n\nYour Choice..... ");
    scanf("%d",&k);
    if(k==0){ system("CLS");
     return 0;}
    system("CLS");
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Massage Service<<<\n\n\n\n\n");
    printf("Enter time\t: ");
    scanf("\n");
    scanf("%s",L);
    if(k==1) A[i].expense+=6000;
    else if(k==2) A[i].expense+=3000;
    else if(k==3) A[i].expense+=1000;

    printf("\n\n\nMasseuse Will be there :v\n\n\n");

    printf("\n\n\n\nUpdated Bill\t- %.2f\n\n\n",A[i].expense);
    Update();}

    else { system("CLS");
            printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t\t>>>Hotel Services<<<\n\n\n\n\n");
    printf("\t\t\t>>>Massage Service<<<\n\n\n\n\n");
            printf("\n\n\n\n\t\tNo customer available\n\n\n");}

    system("Pause");
    system("CLS");
}

void Hotel_Log()
{
    while(1)
    {
        system("color 80");
        int choice;
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t>>> Options <<<");
        printf("\n\n\n\n\t\tPress 0: Check In\n\n\t\tPress 1: Check Out\n\n\t\tPress 2: Hotel Service\n\n\t\tPress 3: Convention Center Booking\n\n\t\tPress 4: Exit\n\n\n\n\n\t\tYour Choice....  ");

        scanf("%d",&choice);

        system("CLS");
        switch(choice)
        {
            case 0:
                Check_In();
                break;
            case 1:
                Check_Out();
                break;
            case 2:
                Hotel_Service();
                break;

            case 3:
                convention_center();
                break;
            case 4:
                //printf("\n\n\n\n\t\tThank you for using this management system....<3\n\n\n\n");
                system("CLS");
                return 0;
            case 5:
                Reset();
                break;
        }
    }
}
struct user{
    int id;
    char name[20];
    char password[20];
};
struct adminuser{
    int id;
    char name[20];
    char password[20];
};

struct adminuser M[10];
struct user L[10];

int user;
int current_id;

FILE *r,*w,*a;

char name[20],pass[20];

int countAdmin()
{
    int lines=0;
    char ch;
    r=fopen("AdminLogin.txt","r");

    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);

    return lines;
}

int countuser()
{
    int lines=0;
    char ch;
    r=fopen("UserLogin.txt","r");

    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}

void AdminLoad()
{
    int i,lines;
    lines = countAdmin();
    r=fopen("AdminLogin.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %s",&M[i].id,M[i].name,M[i].password);
    }
    fclose(r);
}

void LoadUs()
{
    int i,lines;
    lines = countuser();
    r=fopen("UserLogin.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %s",&L[i].id,L[i].name,L[i].password);
    }
    fclose(r);

}

void AdminReload()
{
    int i,total=countAdmin();
    w=fopen("AdminLogin.txt","w");

    for(i=0;i<total;i++)
    {
        fprintf(w,"%d\t%s\t%s\n",M[i].id,M[i].name,M[i].password);
    }
    fclose(w);

}

void Reload()
{
    int i,total=countuser();
    w=fopen("Temp.txt","w");

    for(i=0;i<total;i++)
    {
        fprintf(w,"%d\t%s\t%s\n",L[i].id,L[i].name,L[i].password);
    }
    fclose(w);

    remove("UserLogin.txt");
    rename("Temp.txt","UserLogin.txt");
}

void Admin_Login()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\n\n\t\t>>>Admin Panel<<<\n\n\n\n");
    AdminLoad();

    int i,t,p=0,lines=countAdmin();
    char j[20],k[20];

    printf("Enter Name\t: ");
    scanf("\n");
    scanf("%s",j);
    printf("Enter Pass\t: ");
    scanf("\n");
    scanf("%s",k);

    for(i=0;i<lines;i++)
    {
        if(strcmp(M[i].name,j)==0)
        {
            if(strcmp(M[i].password,k)==0)
            {
                system("CLS");
                Admin_Panel();
                system("CLS");
                return 0;
            }
            else
            {
                printf("\n\nWrong Password...\n\nPress 1\t: Try Again !\nPress 2\t: Exit\n\n\nYour Choice... ");
                scanf("%d",&t);

                if(t==1)
                {
                    system("CLS");
                    Admin_Login();
                    system("CLS");
                    return 0;
                }
            }
            p++;
        }

    }
    if(p==0)
        {
            printf("\n\nNo Such Admin...\n\nPress 1\t: Try Again !\nPress 2\t: Exit\n\n\nYour Choice... ");
            scanf("%d",&t);

            if(t==1)
            {
                system("CLS");
                Admin_Login();
                system("CLS");
                return 0;
            }
        }
   system("CLS");
}
void Admin_Panel()
{
    while(1)
    {
        system("color A0");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\n\n\t\t>>>Admin Panel<<<\n\n\n\n");

        int a;

        printf("Press 0\t: Admin Registration\n\nPress 1\t: Remove Admin\n\nPress 2\t: User Registration\n\nPress 3\t: Remove User\n\nPress 4\t: Show All User\n\nPress 5\t: Hotel Log\n\nPress 6\t: Show All Customer\n\nPress 7\t: Update Admin Password\n\nPress 8\t: Update User Password\n\nPress 9\t: Show All Admin\n\nPress 10: Edit Restaurent Food\n\nPress 11: Exit\n\n\nYour Choice... ");
        scanf("%d",&a);
        system("CLS");
        switch(a)
        {
        case 0:
            AdReg();
            break;
        case 1:
            ReReg();
            break;
        case 2:
            Registration();
            break;
        case 3:
            ReUser();
            break;
        case 4:
            showUs();
            break;
        case 5:
            Hotel_Log();
            break;
        case 6:
            showcus();
            break;
        case 7:
            UpdateAd();
            break;
        case 8:
            UpdateUs();
            break;
        case 9:
            showAd();
            break;
        case 10:
            Editfood();
            break;
        case 11:
            return 0;
        }
    }
    system("CLS");
}

void AdReg()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    AdminLoad();
    printf("\t>>>Registration portal<<<\n\n");
    a=fopen("AdminLogin.txt","a");

    user=countAdmin();

    printf("Enter Username\t: ");
    scanf("%s",M[user].name);
    printf("\nEnter Password\t: ");
    scanf("%s",M[user].password);

    M[user].id=user+1;

    fprintf(a,"%d %s %s\n",M[user].id,M[user].name,M[user].password);
    fclose(a);

    system("CLS");
    printf("\tRegistration Successfull !!!\n\n\n");
    system("Pause");
    system("CLS");
}

void Registration()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t>>>Registration portal<<<\n\n");
    a=fopen("UserLogin.txt","a");

    user=countuser();

    printf("Enter Username\t: ");
    scanf("%s",L[user].name);
    printf("\nEnter Password\t: ");
    scanf("%s",L[user].password);

    L[user].id=user+1;

    fprintf(a,"%d\t%s\t%s\n",L[user].id,L[user].name,L[user].password);
    fclose(a);

    system("CLS");
    printf("\tRegistration Successfull !!!\n\n\n");
    system("Pause");
    system("CLS");
}

void ReReg()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\n\n\t\t>>>Admin Panel<<<\n\n\n\n***Remove Admin\n\n\n");
    AdminLoad();

    int i,t,p,lines=countAdmin();
    char j[20],k[20];

    printf("Enter Name\t: ");
    scanf("\n");
    scanf("%s",j);

    w=fopen("AdminLogin.txt","w");

    for(i=0;i<lines;i++)
    {
        if(strcmp(M[i].name,j)!=0)
        {
            fprintf(w,"%d %s %s\n",M[i].id,M[i].name,M[i].password);
        }
    }
    fclose(w);

    printf("\n\n\nRemoval Successful\n\n");
    system("pause");
    system("CLS");
}

void ReUser()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\n\n\t\t>>>Admin Panel<<<\n\n\n\n***Remove User\n\n\n");
    LoadUs();

    int i,t,p,lines=countuser();
    char j[20],k[20];

    printf("Enter Name\t: ");
    scanf("\n");
    scanf("%s",j);

    w=fopen("UserLogin.txt","w");

    for(i=0;i<lines;i++)
    {
        if(strcmp(L[i].name,j)!=0)
        {
            fprintf(w,"%d %s %s\n",L[i].id,L[i].name,L[i].password);
        }
    }
    fclose(w);
    printf("\n\n\nRemoval Successful\n\n");
    system("pause");
    system("CLS");
}

void Login()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t>>>Login Portal<<<\n\n");
    int i,t,q=0,total=countuser();

    printf("Enter Username\t: ");
    scanf("%s",name);
    printf("\n\nEnter Password\t: ");
    scanf("%s",pass);

    LoadUs();

    for(i=0;i<total;i++)
    {
    if(strcmp(L[i].name,name)==0)
    {
        if(strcmp(L[i].password,pass)==0)
        {
            system("CLS");
            Hotel_Log();
            system("CLS");
            return 0;
        }
        else
        {
            printf("\n\nWrong Password !\n\nPress 1\t: Try Again !\nPress 2\t: Exit\n\n\nYour Choice... ");
            scanf("%d",&t);

            if(t==1)
            {
                system("CLS");
                Admin_Login();
                system("CLS");
                return 0;
            }
        }
        q++;
    }
    }
    if(q==0)
    {
        printf("\n\nNo Such User...\n\nPress 1\t: Try Again !\nPress 2\t: Exit\n\n\nYour Choice... ");
            scanf("%d",&t);

            if(t==1)
            {
                system("CLS");
                Login();
                system("CLS");
                return 0;
            }
    }
    system("CLS");
}

void showAd()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    int i,lines=countAdmin();
    r=fopen("AdminLogin.txt","r");

    printf("ID\tName\tPassword\n");
    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %s",&M[i].id,M[i].name,M[i].password);
        printf("%d\t%s\t%s\n",M[i].id,M[i].name,M[i].password);
    }
    fclose(r);
    printf("\n\n\n");
    system("Pause");
    system("CLS");
}

void showUs()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    int i,lines=countuser();
    r=fopen("UserLogin.txt","r");

    printf("ID\tName\tPassword\n");
    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %s",&L[i].id,L[i].name,L[i].password);
        printf("%d\t%s\t%s\n",L[i].id,L[i].name,L[i].password);
    }
    fclose(r);
    printf("\n\n\n");
    system("Pause");
    system("CLS");
}

void UpdateAd()
{
    AdminLoad();
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    int i,total=countAdmin();

    printf("Enter Username\t: ");
    scanf("%s",&name);

    for(i=0;i<total;i++)
    {
        if(strcmp(M[i].name,name)==0) break;
    }

    printf("Enter New PassWord\t: ");
    scanf("%s",pass);

    strcpy(M[i].password,pass);

    AdminReload();

    system("CLS");
    printf("\n\n\nPassword Updated....\n\n\n");
    system("Pause");
    system("CLS");
}

void UpdateUs()
{
    LoadUs();
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    int i,total=countuser();

    printf("Enter Username\t: ");
    scanf("%s",&name);

    for(i=0;i<total;i++)
    {
        if(strcmp(L[i].name,name)==0) break;
    }

    printf("Enter New PassWord\t: ");
    scanf("%s",pass);

    strcpy(L[i].password,pass);

    Reload();

    system("CLS");
    printf("\n\n\nPassword Updated....\n\n\n");
    system("Pause");
    system("CLS");
}

int count_res()
{
    int a,lines;
    char ch;

    r=fopen("Restaurent Log.txt","r");
    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}

int count_bre()
{
    int a,lines=0;
    char ch;

    r=fopen("Breakfast.txt","r");
    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}


int count_lun()
{
    int a,lines=0;
    char ch;

    r=fopen("Lunch.txt","r");
    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}


int count_din()
{
    int a,lines=0;
    char ch;

    r=fopen("Dinner.txt","r");
    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}

int count_brev()
{
    int a,lines=0;
    char ch;

    r=fopen("Beverages.txt","r");
    while(!feof(r))
    {
        ch=fgetc(r);
        if(ch=='\n')
        {
            lines++;
        }
    }
    fclose(r);
    return lines;
}

void load_res()
{
    int i,lines=count_res();

    r=fopen("Restaurent Log.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %d %d %d",&R[i].room,&R[i].code,&R[i].quantity,&R[i].price);
    }
    fclose(r);
}

void load_bre()
{
    int i,lines;
    lines=count_bre();

    r=fopen("Breakfast.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %d %[^\n]",&TB[i].code,TB[i].BDT,&TB[i].price,TB[i].name);
        printf("%d\t%s\t\t\t%s %d\n",TB[i].code,TB[i].name,TB[i].BDT,TB[i].price);
    }
    fclose(r);
}

void load_lun()
{
    int i,lines=count_lun();

    r=fopen("Lunch.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %d %[^\n]",&TL[i].code,TL[i].BDT,&TL[i].price,TL[i].name);
        printf("%d\t%s\t\t\t%s %d\n",TL[i].code,TL[i].name,TL[i].BDT,TL[i].price);
    }
    fclose(r);
}

void load_din()
{
    int i,lines=count_din();

    r=fopen("Dinner.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %d %[^\n]",&TD[i].code,TD[i].BDT,&TD[i].price,TD[i].name);
        printf("%d\t%s\t\t\t%s %d\n",TD[i].code,TD[i].name,TD[i].BDT,TD[i].price);
    }
    fclose(r);
}

void load_brev()
{
    int i,lines=count_brev();

    r=fopen("Beverages.txt","r");

    for(i=0;i<lines;i++)
    {
        fscanf(r,"%d %s %d %[^\n]",&Tb[i].code,Tb[i].BDT,&Tb[i].price,Tb[i].name);
        printf("%d\t%s\t\t\t%s %d\n",Tb[i].code,Tb[i].name,Tb[i].BDT,Tb[i].price);
    }
    fclose(r);
}

void Editfood()
{
    while(1)
    {
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t\t***Restaurent***\n\n\n");
        int a,i,j;

        printf("Press 1\t: Add Food \n\nPress 2\t: Remove Food\n\nPress 0\t: Exit\n\n\nYour Choice... ");
        scanf("%d",&a);
        system("CLS");
        switch(a)
        {
        case 1:
            Addfood();
            break;
        case 2:
            Removefood();
            break;
        case 0:
            return 0;
        }
    }
}

void Addfood()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t***Restaurent***\n\n\n");

    int i,n,a,b;
    char g[200];
    printf("Press 1\t: Add Breakfast Menu\nPress 2\t: Add Lunch Menu\nPress 3\t: Add Dinner Menu\nPress 4\t: Add Breverage Menu\n\n\nYour Choice....");
    scanf("%d",&n);

    if(n==1)
    {
        printf("\t\t\tBreakfast\n\n\n");
        load_bre();
        a=count_bre();

        printf("\n\nEnter name of the dish\t: ");
        scanf("\n");
        scanf("%[^\n]",g);
        printf("Enter the price of food\t: ");
        scanf("%d",&b);
        w=fopen("Breakfast.txt","a");
        fprintf(w,"%d\tBDT %d\t%s\n",TB[a-1].code+1,b,g);
        fclose(w);
    }
    else if(n==2)
    {
        printf("\t\t\t  Lunch\n\n\n");
        load_lun();
        a=count_lun();
        printf("Enter name of the dish\t: ");
        scanf("\n");
        scanf("%[^\n]",g);
        printf("Enter the price of food\t: ");
        scanf("%d",&b);
        w=fopen("Lunch.txt","a");
        fprintf(w,"%d\tBDT %d\t%s\n",TL[a-1].code+1,b,g);
        fclose(w);
    }
    else if(n==3)
    {
        printf("\t\t\t Dinner\n\n\n");
        load_din();
        a=count_din();
        printf("Enter name of the dish\t: ");
        scanf("\n");
        scanf("%[^\n]",g);
        printf("Enter the price of food\t: ");
        scanf("%d",&b);
        w=fopen("Dinner.txt","a");
        fprintf(w,"%d\tBDT %d\t%s\n",TD[a-1].code+1,b,g);
        fclose(w);
    }
    else if(n==4)
    {
        printf("\t\t\tBeverages\n\n\n");
        load_brev();
        a=count_brev();
        printf("Enter name of the dish\t: ");
        scanf("\n");
        scanf("%[^\n]",g);
        printf("Enter the price of food\t: ");
        scanf("%d",&b);
        w=fopen("Beverages.txt","a");
        fprintf(w,"%d\tBDT %d\t%s\n",Tb[a-1].code+1,b,g);
        fclose(w);
    }
    printf("\n\n\nFood Added...\n\n\n");
    system("pause");
}

void Removefood()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t***Restaurent***\n\n\n");

    int i,n,a,b;

    printf("Press 1\t: Remove Breakfast Menu\nPress 2\t: Remove Lunch Menu\nPress 3\t: Remove Dinner Menu\nPress 4\t: Remove Breverage Menu\n\n\nYour Choice....");
    scanf("%d",&n);

    if(n==1)
    {
        printf("\t\t\tBreakfast\n\n\n");
        load_bre();
        a=count_bre();

        printf("\n\n\nEnter the code to be removed\t: ");
        scanf("%d",&b);
        w=fopen("Breakfast.txt","w");
        for(i=0;i<a;i++)
        {
            if(TB[i].code!=b)
            {
                fprintf(w,"%d\t%s %d\t%s\n",TB[i].code,TB[i].BDT,TB[i].price,TB[i].name);
            }
        }
        fclose(w);
    }
    else if(n==2)
    {
        printf("\t\t\t  lunch\n\n\n");
        load_lun();
        a=count_lun();

        printf("\n\n\nEnter the code to be removed\t: ");
        scanf("%d",&b);
        w=fopen("Lunch.txt","w");
        for(i=0;i<a;i++)
        {
            if(TL[i].code!=b)
            {
                fprintf(w,"%d\t%s %d\t%s\n",TL[i].code,TL[i].BDT,TL[i].price,TL[i].name);
            }
        }
        fclose(w);
    }
    else if(n==3)
    {
        printf("\t\t\tDinner\n\n\n");
        load_din();
        a=count_din();

        printf("\n\n\nEnter the code to be removed\t: ");
        scanf("%d",&b);
        w=fopen("Dinner.txt","w");
        for(i=0;i<a;i++)
        {
            if(TD[i].code!=b)
            {
                fprintf(w,"%d\t%s %d\t%s\n",TD[i].code,TD[i].BDT,TD[i].price,TD[i].name);
            }
        }
        fclose(w);
    }
    else if(n==4)
    {
        printf("\t\t\tBreverage\n\n\n");
        load_brev();
        a=count_brev();

        printf("\n\n\nEnter the code to be removed\t: ");
        scanf("%d",&b);
        w=fopen("Beverages.txt","w");
        for(i=0;i<a;i++)
        {
            if(Tb[i].code!=b)
            {
                fprintf(w,"%d\t%s %d\t%s\n",Tb[i].code,Tb[i].BDT,Tb[i].price,Tb[i].name);
            }
        }
        fclose(w);
    }
    printf("\n\n\nFood Removed...\n\n\n");
    system("pause");
}

void Order_food()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t***Restaurent***\n\n\n");
    Load();
    load_res();
    int a,i,j=0,k,m=0,S[15],Z[15],t,c,Y[15],st;
    c=count_res();
    float l;
    printf("Enter Room Number\t: ");
    scanf("%d",&a);
    a=a-1;
    w=fopen("Restaurent Log.txt","w");
    for(j=0;j<c;j++)
    {
        if(R[j].room!=a+1 && R[j].room!=0)
        {
            fprintf(w,"%d %d %d %d\n",R[j].room,R[j].code,R[j].quantity,R[j].price);
        }
    }
    fclose(w);
    l=A[a].expense;
    if(strcmp(A[a].Name,"N/A")!=0)
    {
       do
       {
           system("CLS");
           printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
           printf("\t\t***Restaurent***\n\n\n");
           printf("\t\t\tBreakfast\n\n\n");
           load_bre();
           printf("\n\n\n\t\t\t Lunch\n\n\n");
           load_lun();
           printf("\n\n\n\t\t\tDinner\n\n\n");
           load_din();
           printf("\n\n\n\t\t\tBreverages\n\n\n");
           load_brev();
           printf("\n\n\n\nEnter Code\t: ");
           scanf("%d",&S[m]);
           printf("Enter quantity\t: ");
           scanf("%d",&Z[m]);
           m++;
           printf("\n\n\nPress 0\t: Continue Order\nPress 1\t: Confirm Order\n\nYour Choice.... ");
           scanf("%d",&st);
       }while(st!=1);
       system("CLS");
       printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
       printf("\t\t***Restaurent***\n\n\n");
       for(i=0;i<m;i++)
       {
           if(S[i]>100 && S[i]<200)
           {
               t=count_bre();
               {
                   for(j=0;j<t;j++)
                   {
                       if(S[i]==TB[j].code)
                       {
                           Y[i]=(TB[j].price*Z[i]);
                           A[a].expense+=Y[i];
                       }
                   }
               }
           }
           else if(S[i]>200 && S[i]<300)
           {
              t=count_lun();
               {
                   for(j=0;j<t;j++)
                   {
                       if(S[i]==TL[j].code)
                       {
                           Y[i]=(TL[j].price*Z[i]);
                           A[a].expense+=Y[i];
                       }
                   }
               }
           }
           else if(S[i]>300 && S[i]<400)
           {
               t=count_din();
               {
                   for(j=0;j<t;j++)
                   {
                       if(S[i]==TD[j].code)
                       {
                           Y[i]=(TD[j].price*Z[i]);
                           A[a].expense+=Y[i];
                       }
                   }
               }
           }
           else if(S[i]>400)
           {
               t=count_brev();
               {
                   for(j=0;j<t;j++)
                   {
                       if(S[i]==Tb[j].code)
                       {
                           Y[i]=(Tb[j].price*Z[i]);
                           A[a].expense+=Y[i];
                       }
                   }
               }
           }
       }
       load_res();
       w=fopen("Restaurent Log.txt","a");
       for(i=0;i<m;i++)
       {
           fprintf(w,"%d %d %d %d\n",a+1,S[i],Z[i],Y[i]);
       }
       fclose(w);
       printf("\nRestaurent Bill\t: %.2f",A[a].expense-l);
       printf("\n\nYour Total Bill\t: %.2f\n\n",A[a].expense);
       Update();
    }
    else
    {
        printf("\nNo Customer\n");
    }

    system("pause");
    system("CLS");
}

void Cancel_order()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
    printf("\t\t***Restaurent***\n\n\n");
    load_res();
    Load();
    int i,j,k,m=count_res(),a,b=0,p;
    printf("Enter room number\t: ");
    scanf("%d",&i);
    i=i-1;

    if(strcmp(A[i].Name,"N/A")!=0)
    {
        printf("Room\tCode\tQuantity\tPrice\n\n");
        for(j=0;j<m;j++)
        {
            if(R[j].room==i+1)
            {
                printf("%d\t%d\t%d\t%d\n",R[j].room,R[j].code,R[j].quantity,R[j].price);
                b++;
            }
        }
        if(b==0)
        {
            printf("No Food Order\n\n\n");
            system("pause");
            system("CLS");
            return 0;
        }
        printf("\n\n\nEnter The food code to cancel\t: ");
        scanf("%d",&a);
        for(j=0;j<m;j++)
        {
            if(R[j].room==i+1 && R[j].code==a)
            {
                p=j;
                break;
            }
        }
        A[i].expense-=R[p].price;
        w=fopen("Restaurent Log.txt","w");
        for(j=0;j<m;j++)
        {
            if(R[j].code!=a)
            {
                fprintf(w,"%d\t%d\t%d\t%d\n",R[j].room,R[j].code,R[j].quantity,R[j].price);
            }
        }
        fclose(w);
        printf("\n\nUpdated Total Expense\t: %.2f\n\n\n\n",A[i].expense);
        Update();
    }
    else
    {
        printf("\nNo Customer\n\n\n");
    }

    system("pause");
    system("CLS");
}

int Restaurent()
{
    while(1)
    {
        system("color F9");
        system("CLS");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t\t***Restaurent***\n\n\n");
        printf("Press 1\t: Order Food\n\nPress 2\t: Cancel Order\n\nPress 0\t: Exit\n\n\n\nYour Choice... ");
        int a;
        scanf("%d",&a);
        system("CLS");
        switch(a)
        {
        case 1:
            Order_food();
            break;
        case 2:
            Cancel_order();
            break;
        case 0:
            return 0;
        }
    }
}

struct CustomerDetails
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Choose a time between 10am to 5pm  :\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name                            :");
		scanf("%s",s.name);
		printf("Enter Address                         :");
		scanf("%s",s.address);
		printf("Enter Phone Number                    :");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality                     :");
		scanf("%s",s.nationality);
		printf("Enter Email                           :");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days)               :");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy)      :");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Center is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

void list()
{
    printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("Center    ");
	printf("NAME\t ");
	printf("\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{

		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
	printf("Enter the choose time  of the Center to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Choose time is not found!!");

		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
	printf("Enter (choose  the time  customer to search its details): \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nChoose time:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
	printf("Enter( Choose time of the customer to edit):\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\n Choose time     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%f",&s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}

void convention_center(){
	int i=0;
	char customername;
	char choice;

	while (1)
	{

        system("CLS");
        system("color C0");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
		printf("\n");
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf("\n\t,--------------------------------------,");
		printf(" \n\t|Enter 1 -> Booking a convention center|");
		printf("\n\t|--------------------------------------|");
		printf(" \n\t|Enter 2 -> View booking  Record       |");
		printf("\n\t|--------------------------------------|");
		printf(" \n\t|Enter 3 -> Delete booking Record      |");
		printf("\n\t|--------------------------------------|");
		printf(" \n\t|Enter 4 -> Search booking  Record     |");
		printf("\n\t|--------------------------------------|");
		printf(" \n\t|Enter 5 -> Edit booking  Record       |");
		printf("\n\t|--------------------------------------|");
		printf(" \n\t|Enter 6 -> Exit                       |");
		printf("\n\t'--------------------------------------'");
		printf("\n");


		choice=getche();
		choice=toupper(choice);
		system("CLS");
		switch(choice)
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t ****THANK YOU****");
				printf("\n\t FOR TRUSTING OUR SERVICE");

				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}


int main()
{

    int choice;

    while(1)
    {
        system("color B0");
        printf("\n\n\n\t\t\t\t\t\t   >>> Hotel de Moessure <<<\n\n\n\n\n\n\n\n");
        printf("\t>>>Operations<<<\n\n\nPress 0: Admin Panel\nPress 1: Login\nPress 2: Exit\n\nYour Choice: ");

        scanf("%d",&choice);

        switch(choice)
        {
        case 0:
            system("CLS");
            Admin_Login();
            break;
        case 1:
            system("CLS");
            Login();
            break;
        case 2:
            return 0;
        }
    }

    return 0;
}

