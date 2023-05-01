# include <iostream>
# include <limits>
# include <vector>

/*
	Author: LeeTuah
	Program: Flight Ticket Counter Program
	For SuperB league event
*/

// fixes std::cin if bad input is provided
void fix_cin(){
	if(std::cin.fail()){
		// clears std::cin and removes all the bad input from it
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}
}	

// prints the main menu in the program
void printMenu(){
	std::cout << "1. View Flights"<< std::endl;
	std::cout << "2. Book a Flight"<< std::endl;
	std::cout << "3. See all booked flights" << std::endl;
	std::cout << "4. Cancel the flight"<< std::endl;
	std::cout << "5. Exit the menu"<< std::endl;
	std::cout << ">> ";
}

// prints the avaliable flights for the airline
void printFlights(std::vector<std::string> flights){
	std::cout << "\n\n";
	std::cout << "These are the following flights we support:\n";
	for(int i = 0; i < (int)(flights.size()); i++){
		std::cout << i + 1 << ". " << flights[i] << ".\n";
	}
	std::cout << "\n\n";
}

// prints all the booked flights given by the user
void getBookedFlights(std::vector<int> booked, std::vector<std::string> flights){
	std::cout << "\n\n";
	std::cout << "These are the following flights you booked:\n";
	int cnt = 1;
	for(auto i = booked.begin(); i != booked.end(); i++, cnt++){
		std::cout << cnt << ". " << flights[*i - 1] << std::endl;
	}
	std::cout << "\n\n";
}

// books a flight as per the user
int bookFlight(std::vector<int> prices){
	int input;
	std::string choice;
	char ch;
		
	std::cout << "\n\nEnter the flight number (view the flight list of you donot know): ";
	std::cin >> input;
	fix_cin();
	
	// checking if input is valid
	if(input < 1 || input > 4){
		std::cout << "Invalid flight number provided!\n";
		return 0;	
	}
	
	std::cout << "The price for that flight is $" << prices[input - 1] << std::endl;
	std::cout << "Enter \'Y\' if you are satisfied with the billing amount: ";
	std::cin >> choice;
	ch = choice[0];
	
	// capitalizing the character		
	if(ch > 90) ch -= 32;
	
	if(ch != 'Y'){
		std::cout << "Aborting the booking process...\n";
		return 0;	
	}
	
	std::cout << "Alright, your flight has been booked. Enjoy your ride!\n\n";
	return input;
}

// returns a boolean value for if a flight number 
// matches with the booked flights of the user
bool validFlight(int f, std::vector<int> booked){
	return (f > 0 && f <= (int)(booked.size()));
}

int main(int argc, char *argv[]){
	// printing the intro scene
	std::cout << "#########################################\n";
	std::cout << "  WELCOME TO DILLUSIONERS FLIGHT AGENCY";	
	std::cout << "\n#########################################\n\n\n";

	// declaration of all the required variables	
	bool running = true;
	int choice = 0;
	std::vector<int> booked_flights, prices;
	std::vector<std::string> flights; 	
	prices = {231, 95, 287, 460};
	flights = {"Ohio", "California", "Florida", "Miami"};
	
	while(running){
		printMenu();
		std::cin >> choice;
		fix_cin();
		
		switch(choice){
			// exit
			case 5: {
				std::cout << "\nThanks for checking out our flight services!";
				running = false;
				break;
			}
			
			// view flights
			case 1: {
				printFlights(flights);
				break;
			}
				
			// book a flight
			case 2: {
				int flight = bookFlight(prices);
				if(flight == 0) break;
				booked_flights.push_back(flight);
				break;
			}
			
			// check all booked flights	
			case 3: {
				getBookedFlights(booked_flights, flights);
				break;
			}
			 // cancel a flight
			case 4: {
				std::cout << "Enter the flight number you want to cancel: ";
				int f;
				std::cin >> f;
				fix_cin();
				if(!validFlight(f, booked_flights)){
					std::cout << "Invalid flight provided!\n";
					break;			
				}
				booked_flights.erase(booked_flights.begin() + (f - 1));
				std::cout << "Successfully cancelled the file...";
				break;
			}
			
			// if the choice is not in menu		
			default: {
				std::cout << "Invalid choice!\n";				
			}
		}	
	}
	
	return 0;
}
