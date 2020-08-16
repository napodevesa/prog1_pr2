#include <stdio.h>
#include <math.h>
#include <string.h>
#include <api.h>
#include <time.h>
#include "customer.h"
#include "hotel.h"
#include "movement.h"
#include "list.h"
#include "queue.h"

void appData_init(tAppData *object) {
	/* Set parent folder as the default path */
	strcpy(object->path, "../");
	
	/* Initialize the customer table */
	customerTable_init(&(object->customers));
	
	/* Initialize the hotels table */
	hotelTable_init(&(object->hotels));
    
	/* Initialize the movements table */
	movementTable_init(&(object->movements));
}

void appData_load(tAppData *object, tError *retVal) {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Load the table of hotels */
	sprintf(path,"%shotels.txt", object->path);
	hotelTable_load(&(object->hotels), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of hotels\n");
	}

	/* Load the table of customers */
	sprintf(path,"%scustomers.txt", object->path);
	customerTable_load(&(object->customers), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of customers\n");
	}
    
	/* Load the table of movements */
	sprintf(path,"%smovements.txt", object->path);
	movementTable_load(&(object->movements), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of movements\n");
	}
}

void appData_save(tAppData object, tError *retVal)  {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Save the table of hotels */
	sprintf(path,"%shotels.txt", object.path);
	hotelTable_save(object.hotels, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of hotels\n");
	}
	
	/* Save the table of customers */
	sprintf(path,"%scustomers.txt", object.path);
	customerTable_save(object.customers, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of customers\n");
	}
    
	/* Save the table of movements */
	sprintf(path,"%smovements.txt", object.path);
	movementTable_save(object.movements, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of movements\n");
	}
}

void appData_setPath(tAppData *object, const char *path)  {		
	strncpy(object->path, path, 255);	
}


/*********************** 
 *        API
 **********************/

void getHotels(tAppData object, tHotelTable *result) {
	*result = object.hotels;	
}

void getHotel(tAppData object, tHotelId hotelId, tHotel *hotel, tError *retVal) {
	
	int i;
	*retVal = OK;

	/* Check if there is a hotel with this id */
	i = hotelTable_find(object.hotels, hotelId);
	if (i!=NO_HOTEL) {
		hotel_cpy(hotel,object.hotels.table[i]);
	} else {
		*retVal = ERR_ENTRY_NOT_FOUND;
	}
}

void addHotel(tAppData *object, tHotel hotel, tError *retVal) 
{
	*retVal = OK;
	tHotel tmp;

	/* Check if there is another hotel with the same id */
	getHotel(*object, hotel.id, &tmp, retVal);
	if(*retVal==OK) {
		*retVal = ERR_DUPLICATED_ENTRY;
	} else {
		/* Add the new hotel using the hotel table method */
		hotelTable_add(&(object->hotels), hotel, retVal);
	}
}

void getCustomers(tAppData object, tCustomerTable *result) {
	*result = object.customers;	
}

void getCustomer(tAppData object, tCustomerId id, tCustomer *customer, tError *retVal) {
	
	int i;
	*retVal = OK;
	
	/* Check if there is a customer with this id */
	i = customerTable_find(object.customers, id);
	if (i!=NO_CUSTOMER) {
		customer_cpy(customer,object.customers.table[i]);
	} else {
		*retVal = ERR_ENTRY_NOT_FOUND;
	}
}

void addCustomer(tAppData *object, tCustomer customer, tError *retVal) {
	*retVal = OK;
	tCustomer tmpCustomer;
    
	/* Check if there is another customer with the same id */
	getCustomer(*object, customer.id, &tmpCustomer, retVal);
	if(*retVal==OK) {
		*retVal = ERR_DUPLICATED_ENTRY;
	} else {
		/* Add the new customer using the customer table method */
		customerTable_add(&(object->customers), customer, retVal);
	}
}

void removeCustomer(tAppData *object, tCustomer customer) 
{	
	/* Call the method from the customers table*/
	customerTable_del(&(object->customers), customer);
}

int findCustomerBooking( tBookingList bookings, tCustomerId customerId )
{
    int index= NO_BOOKING;
/******************* PR2 - EX1A *****************/
    int length;
    tBooking booking;
    boolean found;
    tError retVal= OK;
    
    index= 1;
    found= FALSE;
    length= bookingList_length(bookings);    
    while (index<=length && !found && retVal == OK)
    {
        retVal= bookingList_get(bookings,index,&booking);
        found= (booking.id == customerId);
        index++;
    }

    if (found)
        index= index-1;
    else
        index= NO_BOOKING;
/******************************************************/
    return index;
}

void freeRoomsOfBooking(tHotel *hotel, tBooking booking)
{
    int i, roomNumber, floor, room;
    
    for (i= 0; i<booking.nAssignedRooms; i++)
    {
        roomNumber= booking.assignedRooms[i];
        floor= (roomNumber / 100);
        room= (roomNumber % 100);
        hotel->layout[floor-1][room-1]= FALSE;
        hotel->occupiedRooms--;
    }

    hotel->percentOccupation= 100.0 * ((float)hotel->occupiedRooms / (float)hotel->numRooms);
}

int numberOfDays(tDate d1, tDate d2)
{
    double seconds;
    struct tm t1= { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    struct tm t2= { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    t1.tm_mday= d1.day;
    t1.tm_mon= d1.month-1;
    t1.tm_year= d1.year-1900;
    
    t2.tm_mday= d2.day;
    t2.tm_mon= d2.month-1;
    t2.tm_year= d2.year-1900; 
   
    seconds= fabs( difftime( mktime(&t1), mktime(&t2) ) );

    return (int)(seconds / 86400.0);
}

float calculatePrice(tHotel hotel, tBooking booking, tDate date)
{
    float price= 0.0; 
/******************* PR2 - EX2A *****************/
    float singleRoom, doubleRoom, tripleRoom, quadRoom;
    int i, floor, nDays;

    /* get the price per room */
    singleRoom= hotel.price * SINGLE_ROOM_PRICE_FACTOR;
    doubleRoom= hotel.price * DOUBLE_ROOM_PRICE_FACTOR;
    tripleRoom= hotel.price * TRIPLE_ROOM_PRICE_FACTOR;
    quadRoom =  hotel.price * QUAD_ROOM_PRICE_FACTOR;
    
    /* add room prices for this booking */
    price= 0;
    for (i= 0; i<booking.nAssignedRooms; i++)
    {
        floor= booking.assignedRooms[i] / 100;
        if (floor == 1)
            price += singleRoom;
        else if (floor == 2)
            price += doubleRoom;
        else if (floor == 3)
            price += tripleRoom;
        else
            price += quadRoom;
    }
    
    /* add price per person accoding to numer of guests and regime */
    if (booking.regime == ROOM_AND_BREAKFAST)
        price += (booking.nGuests * BREAKFAST_PRICE);
    else if (booking.regime == HALF_BOARD)
        price += (booking.nGuests * HALF_BOARD_PRICE);
    else if (booking.regime == FULL_BOARD)
        price += (booking.nGuests * FULL_BOARD_PRICE);

    /* product by number of days for this stay */
    nDays = numberOfDays(date,booking.checkInDate);
    price *= (float)(nDays);
    
    /* penalty for late checkout */
    if (date_cmp(date,booking.checkOutDate)>0)
        price *= LATE_CHECKOUT_PRICE_FACTOR;
/******************************************************/
    return price;
}

void processCheckouts( tHotel *hotel, tCustomerTable customers, tDate date, tCustomerQueue *queue, 
                       tBookingList *currentBookings, tBookingList *completedBookings )
{
/******************* PR2 - EX2B *****************/
   tCustomerId customerId;
   tBooking booking;
   float price;
   int index;
       
   while (!customerQueue_empty(*queue))
   {
       customerId= customerQueue_head(*queue);
       if (customerTable_find(customers, customerId) != NO_CUSTOMER)
       {
           index= findCustomerBooking(*currentBookings, customerId);
           if (index != NO_BOOKING)
           {
               bookingList_get(*currentBookings,index,&booking);
               if (date_cmp(booking.checkOutDate,date)==0)
               {
                   bookingList_delete(currentBookings,index);
                   price= calculatePrice(*hotel,booking,date);
                   freeRoomsOfBooking(hotel,booking);
                   booking.price= price;
                   bookingList_insert(completedBookings,booking,1);               
               }
           }
       }
       
       customerQueue_dequeue(queue);
   }
/******************************************************/
}

int availableRooms(tHotel hotel, int capacity)
{
    int i, available;

    available= 0;

    for (i= 0; i < MAX_ROOMS_PER_FLOOR; i++)
         if (hotel.layout[capacity-1][i] == FALSE)
             available++;
             
    return available;
}

void assignRoom(tHotel *hotel, int capacity, int amount, tBooking *booking)
{
    int i, roomNumber;
    
    for (i= 0; i < MAX_ROOMS_PER_FLOOR && amount > 0; i++)
         if (hotel->layout[capacity-1][i] == FALSE)
         {
             hotel->layout[capacity-1][i] = TRUE; 
             hotel->occupiedRooms++;
             roomNumber= (capacity*100 + i + 1);
             booking->assignedRooms[ booking->nAssignedRooms ]= roomNumber;
             booking->nAssignedRooms++;
             amount--;
         }
         
    hotel->percentOccupation= 100.0 * ((float)hotel->occupiedRooms / (float)hotel->numRooms);
}

void assignRoomsForBooking(tHotel *hotel, tBooking *booking)
{
    int singleRooms, doubleRooms, tripleRooms, quadRooms;
    
    singleRooms= availableRooms(*hotel,1);
    doubleRooms= availableRooms(*hotel,2);
    tripleRooms= availableRooms(*hotel,3);
    quadRooms =  availableRooms(*hotel,4);
    
    if (booking->nGuests == 1)
    {
        if (singleRooms >= 1)
            assignRoom(hotel,1,1,booking);
        else if (doubleRooms >= 1)
            assignRoom(hotel,1,1,booking);            
        else if (tripleRooms >= 1)
            assignRoom(hotel,1,1,booking);            
        else if (quadRooms >= 1)
            assignRoom(hotel,1,1,booking);            
    } else if (booking->nGuests == 2) {
        if (doubleRooms >= 1)
            assignRoom(hotel,2,1,booking);
        else if (singleRooms >= 2)
            assignRoom(hotel,1,2,booking);            
        else if (tripleRooms >= 1)
            assignRoom(hotel,3,1,booking);            
        else if (quadRooms >= 1)
            assignRoom(hotel,4,1,booking); 
    } else if (booking->nGuests == 3) {
        if (tripleRooms >= 1)
            assignRoom(hotel,3,1,booking);
        else if (doubleRooms >= 1 && singleRooms >= 1) {
            assignRoom(hotel,1,1,booking);            
            assignRoom(hotel,2,1,booking);              
        }
        else if (tripleRooms >= 3)
            assignRoom(hotel,3,3,booking);
        else if (doubleRooms >= 2)
            assignRoom(hotel,2,2,booking);         
        else if (quadRooms >= 4)
            assignRoom(hotel,4,1,booking);         
    } else {
        if (quadRooms >= 1)
            assignRoom(hotel,4,1,booking);
        else if (doubleRooms >= 2)
            assignRoom(hotel,2,1,booking);      
        else if (tripleRooms >= 3 && singleRooms >= 1) {
            assignRoom(hotel,3,1,booking);            
            assignRoom(hotel,1,1,booking);            
        }
        else if (singleRooms >= 4)
            assignRoom(hotel,1,4,booking);         
        else if (tripleRooms >= 1 && doubleRooms >= 1) {
            assignRoom(hotel,3,1,booking);            
            assignRoom(hotel,2,1,booking);            
        }
        else if (tripleRooms >= 2)
            assignRoom(hotel,3,2,booking);
    }
}

void processCheckins( tHotel *hotel, tCustomerTable customers, tDate date, tCustomerQueue *queue, 
                      tBookingList *pendingBookings, tBookingList *currentBookings )
{
/******************* PR2 - EX1B *****************/
   tCustomerId customerId;
   tBooking booking;
   int index;
       
   while (!customerQueue_empty(*queue))
   {
       customerId= customerQueue_head(*queue);
       
       if (customerTable_find(customers, customerId) != NO_CUSTOMER)
       {
           index= findCustomerBooking(*pendingBookings, customerId);
           if (index != NO_BOOKING)
           {
               bookingList_get(*pendingBookings,index,&booking);
               if (date_cmp(booking.checkInDate,date)==0)
               {
                   bookingList_delete(pendingBookings,index);
                   assignRoomsForBooking(hotel,&booking);
                   bookingList_insert(currentBookings,booking,1);               
               }
           }
       }
       
       customerQueue_dequeue(queue);
   }
/******************************************************/
}

void updateHotelOccupation( tHotel *hotel, tBookingList currentBookings )
{
    int length, index, i, j, floor, room, roomNumber;
    tBooking booking;
    
    /* initialize all rooms as non-occupied */
    hotel->occupiedRooms= 0;
    for (i = 0; i < MAX_FLOORS; i++)
        for (j= 0; j < MAX_ROOMS_PER_FLOOR; j++)
            hotel->layout[i][j]= FALSE;            
    
    index= 1;
    length= bookingList_length(currentBookings);    
    for (index=1; index<=length; index++)
    {
        bookingList_get(currentBookings,index,&booking);

        /* mark all rooms of a current booking as occupied */
        for (i = 0; i < booking.nAssignedRooms; i++) 
        {
            roomNumber= booking.assignedRooms[i];
            floor= roomNumber / 100;
            room = roomNumber % 100;
            hotel->layout[floor-1][room-1]= TRUE;
            hotel->occupiedRooms++;
        }
    }

    /* calculate total rooms amb percentage of occupation */
    hotel->numRooms= (MAX_FLOORS * MAX_ROOMS_PER_FLOOR);
    hotel->percentOccupation= 100.0 * ((float)hotel->occupiedRooms / (float)hotel->numRooms);
}

void processMovement( tMovement *movement, 
                      tCustomerTable *customers, tHotelTable *hotels, tError *retVal )
{
    int index;
    
    index= hotelTable_find(*hotels,movement->id);
    
    if (index == NO_HOTEL)
       *retVal = ERR_NO_HOTEL;
    else
    {
        /* update the occupation of the hotel according to ongoing bookings */
        updateHotelOccupation( &hotels->table[index], movement->currentBookings );
        
        /* process the checkouts */
        processCheckouts( &hotels->table[index], *customers, movement->date, 
                          &movement->checkoutQueue, 
                          &movement->currentBookings, &movement->completedBookings );

        /* process the checkins */
        processCheckins(  &hotels->table[index], *customers, movement->date, 
                          &movement->checkinQueue, 
                          &movement->pendingBookings, &movement->currentBookings );
                          
        *retVal = OK;
    }
}

void processAllMovements(tAppData *object, tError *retVal)
{    
    int i;
    
    for (i= 0; i < object->movements.nMovements; i++) 
    {
        /* process the movement */
        processMovement( &object->movements.table[i], &object->customers, &object->hotels, retVal );
    }
}
