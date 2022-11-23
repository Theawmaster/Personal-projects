#NTU Hotel Room Reservation Program
![Hotel_booking_clipart](https://media.istockphoto.com/id/1194954335/vector/hotel-booking-word-concepts-banner.jpg?s=612x612&w=0&k=20&c=VTthlUdS7FFhgAkdxZNS73k9UNVe-hZ2acutoGng38s=)

##Description:
This is a program to allow users to book NTU hotel. It has a max booking capacity of 5 rooms. 

##Assignment requirements:
The program uses an array of MAX structures for hotel
rooms.

###Language
1. C (Using NTU Automated Processing Assessment System)

###Structure
1. roomID – It stores the room identification number
2. status – It stores a marker that indicates whether the room is assigned or not (i.e.,EMPTY or TAKEN)
3. customerName – It stores the name of the customer who occupies the room

###Functions
1. listOccupiedRooms() - – The function prints the list of room assignments in hotel
- The function prints the following message when it is executed: "listOccupiedRooms():"
- If the hotel is empty, i.e., no room is occupied, the function should display the message:"The hotel is empty"

2. assignRoom() – The function assigns a customer to a room. It reads in the selected room number (roomID) and customer name from user, and then assigns the room accordingly
- The function prints the following message when it is executed: "assignRoom():" 
- After assigning a room suceessfully, the function should display the message: "The room has been assigned successfully "
- If the hotel is full (i.e. MAX) during room assignment, the function should display the message: "The hotel is full"
- If the selected room has been assigned to another customer already, the function should display the message: "Occupied! Enter another roomID"
- If the selected room number is not between 1 and MAX (i.e., 5), the function should display the  message: "Enter a roomID between 1 and 5".  The function should continue to read a room number from the user

3. removeRoom() – The function removes a room assignment. It reads in the selected room number (i.e. roomID) from user and then remove the assigned room accordingly
- The function prints the following message when it is executed: "removeRoom():"
- After room removal, the function should display the message: "Removal is successful"
- After room removal, the function should display the message: "Removal is successful"
- If the selected room is empty, the function should display the message: "Empty! Enter another roomID for removal"
- If the selected room number is not between 1 and 5 (i.e., MAX), the function should display the message: "Enter a roomID between 1 and 5"

4. findCustomer() – The function finds the target customer name from the Room records stored in hotel, and prints the target room information to the screen
- The function prints the following message when it is executed: "findCustomer():"
- The function finds the first appearance of the target customer name in the array structure (i.e. according to roomID), and prints the corresponding target customer information to the screen
- The target string matching should be done irregardless of the letter cases (upper case letter and lower case letter will be treated to be the same)
- If target customer name is found in hotel, the function should display the message: "The target customer name is found" and display the room information of the corresponding customer
- If target customer name does not exist in hotel, the function should display the message: "The target customer name is not found"

##Guide
1. Upon execution of the program, menu interface displayed.
2. Type 1 to display the available room to book. If empty, message of "The hotel is empty" will be displayed. Else if the hotel is full, message of "The hotel is full" will be displayed. Else, the booking details of will be displayed.
3. Type 2 to book a hotel room. User to input a integer between 1 and 5 for room ID. This is followed by inputing customer name. Upon successful registration, message of "The room has been assigned successfully" will be displayed.
4. Type 3 to remove a booking. User to input a room ID they wish to remove. If there are empty rooms, a message of "All the rooms are empty". Else if the room ID inserted is empty, a message of "Empty! Enter another roomID for removal" will be displayed. Else, upon sucessful room removal, a message of "Removal is successful" will be displayed.
5. Type 4 to search for a customer name. User to key in the target name. If successful, a message of "The target customer name is found" will be displayed, else a message of "The target customer name is not found" will be displayed.
6. Type 5 to terminate the program. 