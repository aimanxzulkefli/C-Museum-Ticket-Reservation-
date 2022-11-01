#include <iostream>

int pick;
int idBuyer;
int ticketBuyer;
int ageBuyer[100];
double total[100];
double sum;
int temp;

void overviewMuseum();
void ticketPromotion();
void displayTicket();
void printTicket();
void buyTicket();
void deleteTicket();

int main(){

    do{
        std::cout<<"\n************************************\n";
		std::cout<<"****** STATE MUSEUM OF MELAKA ******\n";
		std::cout<<"************************************\n";
	
		std::cout<<"Pick a number to continue\n";
		std::cout<<"1.	Overview\n";
		std::cout<<"2.	Ticket Promotion\n";
		std::cout<<"3.	Buy Ticket\n";
		std::cout<<"4.	Delete Ticket\n";
		std::cout<<"5.	Print\n";
		std::cout<<"9.	Exit\n";
	
		std::cout<<"Your pick: ";
		std::cin>>pick;
		
		std::cout<<"************************************\n\n";

        if(!(pick)){
            std::cin.clear();
            std::cin.ignore(100,'\n');
        } 

        switch(pick){
            case 1:
				overviewMuseum();
				break;
			case 2:
				ticketPromotion();
				break;
			case 3:
				buyTicket();
				break;
			case 4:
				deleteTicket();
				break;
			case 5:
				printTicket();
				break;
			case 9:
				std::cout<<"Goodbye:)";
				return 0;
			default:
			std::cout<<"Not valid selection\n";
        }
    }while(pick != 9);
}

void overviewMuseum(){
	std::cout<<"OVERVIEW OF MUSEUM MELAKA\n\n";
	std::cout<<"The museum portrays the lifestyle of the different communities and sub-communities\n";
	std::cout<<"that make up the population of Melaka. Among the exhibits on display are items used\n";
	std::cout<<"in traditional wedding ceremonies, kitchen utensils, musical instruments and collections\n";
	std::cout<<"of ancient porcelain ware. There are also collections of ancient weapons, stamps and\n";
	std::cout<<"various currencies\n";
}

void ticketPromotion(){
	std::cout<<"PROMOTION OF THE DAY\n\n";
	std::cout<<"Category				Code\n";
	std::cout<<"Children (age below 12)		:50%	C50\n";
	std::cout<<"Adult (age 12 and above)	:30%	A30\n";
	std::cout<<"Senior (age above 60)		:80%	S80\n";
}

void buyTicket(){
    std::cout<<"CATEGORY AND PRICE\n\n";
	std::cout<<"Category			Normal Price	Discount Price\n";
	std::cout<<"Children (age below 12)		15		7.5\n";
	std::cout<<"Adult (age 12 and above)	20		14\n";
	std::cout<<"Senior (age above 60)		10		2\n\n";

    std::cout<<"\n*Only store 1 ID at a time\n\n";
	std::cout<<"Please enter your ID : ";

            while(!(std::cin>>idBuyer)){
		        std::cout<<"ID take a number only: ";
		        std::cin.clear();
		        std::cin.ignore(100,'\n');
	        }

    temp = idBuyer;

    std::cout<<"How many ticket you like to buy : ";
					
			while(!(std::cin>>ticketBuyer)){
				std::cout<<"Please enter a number: ";
				std::cin.clear();
				std::cin.ignore(100,'\n');
			}
    
    std::cout<<"Please enter age of the ticket owner : \n";
		
		    for(int i=0; i<ticketBuyer; i++){

			    std::cout<<"Person "<<i+1<<" = ";

			        while(!(std::cin>>ageBuyer[i])){
				        std::cout<<"Please enter a number: ";
				        std::cin.clear();
				        std::cin.ignore(100,'\n');
			        }
		    }
            displayTicket();
}

void displayTicket(){
    std::cout<<"\n************************************\n";

    for(int i = 0; i <ticketBuyer; i++){
        if(ageBuyer[i]<12){
            std::cout<<"("<<i+1<<")";
            std::cout<<"\nChildren (age below 12) (C50)\n";
            total[i] = 7.5;
            std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
        }

        if(ageBuyer[i]>=12&&ageBuyer[i]<60){
				std::cout<<"("<<i+1<<")";
				std::cout<<"\nAdult (age 12 and above) (A30)\n";
				total[i] = 14; 
				std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
		}
		if(ageBuyer[i]>=60){
				std::cout<<"("<<i+1<<")";
				std::cout<<"\nSenior (age above 60) (S80)\n";
				total[i] = 2; 
				std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
		}
    }
    std::cout<<"\n************************************\n";
}

void deleteTicket(){
    std::cout<<"DELETE TICKET\n\n";
	std::cout<<"Enter your ID : ";

    while(!(std::cin>>idBuyer)){
		std::cout<<"Please enter a number: ";
		std::cin.clear();
		std::cin.ignore(100,'\n');
	}

    if(idBuyer == temp){
        displayTicket();

        std::cout<<"Pick a number in () to delete\n";
		std::cout<<"Your pick: ";
	
		while(!(std::cin>>pick)){
			std::cout<<"Please enter a number in (): ";
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}

        for(int i=pick; i<=ticketBuyer; i++){
            ageBuyer[i-1]=ageBuyer[i];
        }

        ticketBuyer = ticketBuyer - 1;

        std::cout<<"Ticket updated\n";
    }else{
        std::cout<<"ID is not valid or deleted\n";
		std::cout<<"************************************\n";
    }
}

void printTicket(){
    std::cout<<"************************************\n";
	std::cout<<"******* TICKET MUSEUM MELAKA *******";
	std::cout<<"\n************************************\n";
		
		for(int i=0; i<ticketBuyer; i++){
			if(ageBuyer[i]<12){
				std::cout<<"("<<i+1<<")";
				std::cout<<"\nChildren (age below 12) (C50)\n";
				total[i] = 7.5; 
				std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
			}
			if(ageBuyer[i]>=12&&ageBuyer[i]<60){
				std::cout<<"("<<i+1<<")";
				std::cout<<"\nAdult (age 12 and above) (A30)\n";
				total[i] = 14; 
				std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
			}
			if(ageBuyer[i]>=60){
				std::cout<<"("<<i+1<<")";
				std::cout<<"\nSenior (age above 60) (S80)\n";
				total[i] = 2; 
				std::cout<<"Ticket for "<<ageBuyer[i]<<" years member is : RM "<<total[i]<<"\n";
			}
            sum+=total[i];
        }
		std::cout<<"\n************************************\n";
		std::cout<<"     TOTAL PRICE IS : RM"<<sum<<"     \n";
		std::cout<<"************************************\n";
}