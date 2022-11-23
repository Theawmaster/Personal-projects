// declaration

#define MAX 5 // maximum number of rooms

//function prototypes
void menu();
void set_memory();
void listOccupiedRooms();
void assignRoom();
void removeRoom();
void findCustomer();
void clrInpBuff();
void clrNewLn();
int strcompare();

//structure declaration
typedef struct
{
    int roomID;
    int status;
    char customerName[20];
} Room;

Room rooms[MAX];

//main function
int main()
{
    int choice;
    set_memory();
    menu();
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        clrInpBuff();
        switch (choice)
        {
            case 1:
                printf("listOccupiedRooms():\n");
                listOccupiedRooms(rooms, MAX);
                break;
            case 2:
                printf("assignRoom():\n");
                assignRoom(rooms, MAX);
                break;
            case 3:
                printf("removeRoom():\n");
                removeRoom(rooms, MAX);
                break;
            case 4:
                printf("findCustomer():\n");
                findCustomer(rooms, MAX);
                break;
            default:
                printf("Invalid! Please enter between (1 to 5).\n");
        }
    } while(choice!=5);
    return 0;
}

//printing menu interface
void menu()
{
    printf("NTU HOTEL ROOM RESERVATION PROGRAM:\n");
    printf("1: listOccupiedRooms()\n");
    printf("2: assignRoom()\n");
    printf("3: removeRoom()\n");
    printf("4: findCustomer()\n");
    printf("5: quit\n");
}

//set memory
void set_memory(){
    int i=0;
    for (i=0; i<MAX; i++)
    {
        rooms[i].roomID =i+1;
        rooms[i].status=0;
        memset(rooms[i].customerName, 0, 20);
    }
}

//displaying the occupied and available rooms
void listOccupiedRooms(Room *rooms, int size)
{
    int OccCnt=0 /*Occupy_count*/, i;

    for(i=0; i<size; i++)
    {
        if((rooms+i)->status==1)
        {
            ++OccCnt;
            printf("roomID: %d\n", (rooms+i)->roomID);
            printf("customer name: %s\n", (rooms+i)->customerName);
        }
    }

    if (OccCnt==0)
    {
        printf("The hotel is empty\n");
    }
}

//assigning room to users
void assignRoom(Room *rooms, int size)
{
    int roomID=0, rmIndexNum=0, rm_empty=0, j;
    char customerName[20];
    memset(customerName, 0, 20);

    for (j=0; j<size; j++)
    {
        if (rooms[j].status == 0)
            rm_empty++;
    }

    if (rm_empty==0)
    {
        printf("The hotel is full\n");
        return;
    }

    while (1)
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &roomID);
        clrInpBuff();

        if (roomID>size || roomID<1)
            continue;

        rmIndexNum=roomID-1;
        if ((rooms+rmIndexNum)->status==1)
        {
            printf("Occupied! Enter another roomID\n");
            continue;
        }

        break;
    }

    printf("Enter customer name:\n");
    fgets(customerName, 20, stdin);
    clrNewLn(customerName, 20);
    rooms[rmIndexNum].status = 1;
    strcpy(rooms[rmIndexNum].customerName, customerName);
    printf("The room has been assigned successfully\n");
}

//removing rooms
void removeRoom(Room *rooms, int size)
{

    int roomID=0, rmIndexNum=0, Emptyrm=0, j;

    for (j=0; j<size; j++)
    {
        if ((rooms+j)->status==0)
            Emptyrm++;
    }

    if (Emptyrm==size)
    {
        printf("All the rooms are empty\n");
        return;
    }

    while(1)
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &roomID);
        clrInpBuff();

        if (roomID>size || roomID<1)
            continue;

        rmIndexNum=roomID-1;
        if ((rooms+rmIndexNum)->status==0)
        {
            printf("Empty! Enter another roomID for removal\n");
            continue;
        }

        break;
    }

    (rooms+rmIndexNum)->status=0;
    memset((rooms+rmIndexNum)->customerName, 0, 20);
    printf("Removal is successful\n");
}

//search customer
void findCustomer(Room *rooms, int size)
{
    char customerName[20];
    int i=0;
    memset(customerName, 0, 20);

    printf("Enter customer name:\n");
    fgets(customerName, 20, stdin);
    clrNewLn(customerName, 20);

    for (i=0; i<size; i++)
    {
        if ((rooms+i)->status == 1 && strcompare((rooms+i)->customerName, customerName, 20) == 0)
        {
            printf("The target customer name is found\n");
            printf("roomID: %d\ncustomer name: %s\n", (rooms+i)->roomID, (rooms+i)->customerName);
            return;
        }
    }
    printf("The target customer name is not found\n");
}

//Clear Input Buffers
void clrInpBuff()
{
    char characters;
    while ((characters=getchar())!='\n' && characters!=EOF);
}

//clear following line
void clrNewLn(char *str, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        if (*(str+i)=='\r' || *(str+i)=='\n')
            *(str+i)='\0';
    }
}

//string compare
int strcompare(char *targetstr, char *sourcestr, int size)
{
    for (int h=0; h<size; h++)
    {
        if (*(targetstr+h)=='\0' && *(sourcestr+h)=='\0')
            return 0;
        else if (tolower(*(targetstr+h))!=tolower(*(sourcestr+h)))
            return 1;
    }
    return 0;
}