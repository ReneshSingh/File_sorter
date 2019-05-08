# File sorter

## About the program
This program reads in a file and sorts it using the user’s choice of provided algorithms. Once the files have been sorted it is written to a file in the same location with the original file name appended with the date and time it was sorted. Further the new file name with the time in milliseconds it took to sort is presented on screen.

##Technical information

The program creates a new thread to perform the reading and sorting of the file chosen by the user, this thread is terminated once the new file has been output and the information concerning the file has been passed to the application. 

The program is limited to running three concurrent file sorting actions. This limitation is managed by the thread management function within the program. The appropriate error messages are displayed for closing the program or when limits are acceded. 

The program makes use of the following design patens:
*MVC (Model View Controller) 
*Reflection
*Singleton
*Serialization
*Inheritance
*polymorphism
*Memento
*Abstraction
*Multi-threading
