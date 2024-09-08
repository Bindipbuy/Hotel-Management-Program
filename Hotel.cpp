#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <limits>

#ifdef _WIN32
	#define clearscreen system("cls")
#else
	#define clearscreen system("clear")
#endif

typedef std::vector <std::tuple <std::string, std::string, float> > Foodtype;

class Customer{
	protected:
		std::string Name, Contact, DOB;
		char Gender;
		int Age;
	public:
		std::string getName(){
			return Name;
		}
		std::tuple <std::string, char, int, std::string, std::string> getInfo(){
			return {Name, Gender, Age, DOB, Contact};
		}
		void setInfo(std::string Name, char Gender, int Age, std::string DOB, std::string Contact){
			this -> Name = Name;
			this -> Gender = Gender;
			this -> Age = Age;
			this -> DOB = DOB;
			this -> Contact = Contact;
		}
		void DisplayInfo(){
			std::cout << "Customer Name : " << Name << std::endl;
			std::cout << "Gender : " << Gender << std::endl;
			std::cout << "Age : " << Age << std::endl;
			std::cout << "Date of Birth : " << DOB << std::endl;
			std::cout << "Contact : " << Contact << std::endl;
		}
		void EnterInfo(){
			std::cout << "Enter Name : ";
			getline(std::cin >> std::ws, Name);
			do {
				std::cout << "Enter Gender : ";
				std::cin >> Gender;
				Gender = toupper(Gender);
				while (getchar() != '\n');
			} while (Gender != 'F' && Gender != 'M');
			while (true){
				std::cout << "Enter Age : ";
				std::cin >> Age;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;

			}
			std::cout << "Enter Date of Birth : ";
			getline(std::cin >> std::ws, DOB);
			std::cout << "Enter Contact : ";
			getline(std::cin >> std::ws, Contact);
		}
		void Reset(){
			Name = "";
			Gender = '\0';
			Age = 0;
			DOB = "";
			Contact = "";
		}
};

class Staff : public Customer{
	protected:
		std::string ID, Address, Position, Password, StartTime;
		float Salary;
	public:
		std::string getID(){
			return ID;
		}
		std::tuple <std::string, std::string, char, int, std::string, std::string, std::string, std::string, std::string> getInfo(){
			return {ID, Name, Gender, Age, DOB, Position, StartTime, Address, Contact};
		}
		void setInfo(std::string ID, std::string Name, char Gender, int Age, std::string DOB, std::string Position, std::string StartTime, std::string Address, std::string Contact){
			this -> ID = ID;
			this -> Name = Name;
			this -> Gender = Gender;
			this -> Age = Age;
			this -> DOB = DOB;
			this -> Position = Position;
			this -> StartTime = StartTime;
			this -> Address = Address;
			this -> Contact = Contact;
		}
		void setPosition(std::string Position){
			this -> Position = Position;
		}
		void setSalary(float Salary){
			this -> Salary = Salary;
		}
		void DisplayInfo(){
			std::cout << "ID : " << ID << std::endl;
			std::cout << "Name : " << Name << std::endl;
			std::cout << "Gender : " << Gender << std::endl;
			std::cout << "Age : " << Age << std::endl;
			std::cout << "Date of Birth : " << DOB << std::endl;
			std::cout << "Position : " << Position << std::endl;
			std::cout << "Salary : " << Salary << '$' << std::endl;
			std::cout << "Start to work : " << StartTime << std::endl;
			std::cout << "Contact : " << Contact << std::endl;
			std::cout << "Address : " << Address << std::endl;
		}
		void EnterInfo(){
			std::cout << "Enter ID : ";
			std::cin >> ID;
			std::cout << "Enter Name : ";
			while (getchar() != '\n');
			getline(std::cin >> std::ws, Name);
			do {
				std::cout << "Gender : ";
				std::cin >> Gender;
				Gender = toupper(Gender);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} while (Gender != 'F' && Gender != 'M');
			do {
				std::cout << "Enter Age : ";
				std::cin >> Age;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} while (Age < 18);
			std::cout << "Enter Date of Birth : ";
			getline(std::cin >> std::ws, DOB);
			std::cout << "Enter Time to Work : ";
			getline(std::cin >> std::ws, StartTime);
			std::cout << "Enter Contact : ";
			getline(std::cin >> std::ws, Contact);
			std::cout << "Enter Address : ";
			getline(std::cin >> std::ws, Address);
		}
};

class User : public Staff{
	private:
		std::string Password;
	public:
		std::string getPosition(){
			return Position;
		}
		bool verifyPassword(std::string Password){
			if (this -> Password == Password){
				return true;
			}
			return false;
		}
		std::tuple <std::string, std::string, char, int, std::string, std::string, std::string, std::string, std::string, std::string> getInfo(){
			return {ID, Name, Gender, Age, DOB, Position, StartTime, Address, Contact, Password};
		}
		void setInfo(std::string ID, std::string Name, char Gender, int Age, std::string DOB, std::string Position, std::string StartTime, std::string Address, std::string Contact, std::string Password){
			Staff::setInfo(ID, Name, Gender, Age, DOB, Position, StartTime, Address, Contact);
			this -> Password = Password;
		}
		void EnterInfo(){
			Staff::EnterInfo();
			std::cout << "Enter Password : ";
			getline(std::cin >> std::ws, Password);
		}
};

class Room{
	private:
		std::string room, VIP;
		float pricePerDay;
		double cost;
		int floor, bed, DaytoStay;
		bool available, foodservice;
		Customer customer;
	public:
		Room(std::string room, std::string VIP, int bed, int floor, float price) : room(room), VIP(VIP), bed(bed), floor(floor), pricePerDay(price){
			available = true;
		}
		std::string getRoomNumber(){
			return room;
		}
		Customer getCustomer(){
			return customer;
		}
		float getPrice(){
			return pricePerDay;
		}
		void setCustomer(Customer customer){
			available = false;
			this -> customer = customer;
		}
		bool getAvailable(){
			return available;
		}
		void setAvailable(bool available){
			this -> available = available;
		}
		void CheckOutCustomer(){
			customer.Reset();
			DaytoStay = 0;
			foodservice = false;
		}
		void ChangeCustomer(){
			available = false;
			customer.EnterInfo();
			do {
				std::cout << "Day to Stay : ";
				std::cin >> DaytoStay;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} while (DaytoStay < 1);
		}
		int getDST(){
			return DaytoStay;
		}
		void setDST(int Day){
			this -> DaytoStay = Day;
		}
		bool getFoodService(){
			return foodservice;
		}
		void setFoodService(bool foodservice){
			this -> foodservice = foodservice;
		}
		void CalculateCost(){
			if (foodservice){
				cost = double((pricePerDay + 30) * DaytoStay);
			}
			else {
				cost = double(pricePerDay * DaytoStay);
			}
			if (DaytoStay == 0){
				if (foodservice){
					cost = 15;
				}
				else {
					cost = 5;
				}
			}
		}
		void DisplayRoom(bool withCustomer){
			CalculateCost();
			std::string foodService = (foodservice) ? "True (30$)" : "False (0$)";
			std::cout << "Room : " << room << std::endl;
			std::cout << "Room Status : " << VIP << std::endl;
			std::cout << "Number of Bed : " << bed << std::endl;
			std::cout << "Floor : " << floor << std::endl;
			std::cout << "Price Per Day : " << pricePerDay << '$' << std::endl;
			if (withCustomer) {
				std::cout << "Food Service : " << foodService << std::endl;
				std::cout << "Day to Stay : " << DaytoStay << std::endl;
				customer.DisplayInfo();
				std::cout << "Cost : " << cost << '$' << std::endl;
			}
		}
};

void CreateStaff(std::vector<Staff>& Staffs, std::vector<User>& Users, const std::map<std::string, float>& Jobs, bool& admin){
	std::map<std::string, float> StaffJobs;
	int JobsType, UserType, StaffType, Index = 1, Amount;
	User employee;
	int Position = 0;

	for (const auto& job : Jobs){
		if (job.first != "Manager" && job.first != "Receptionist"){
			StaffJobs[job.first] = job.second;
		}
	}
	if (admin){
		do {
			clearscreen;
			type:
			std::cout << "===========>> Staff Type <<=========\n"
					  << "1.User\n"
					  << "2.Staff\n"
					  << "--> ";
			std::cin >> JobsType;
			if (std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		} while (JobsType < 1 || JobsType > 2);
	} else {
		JobsType = 2;
	}

	switch (JobsType){
		case 1:
				clearscreen;
				std::cout << "===============>> User Type <<==============\n"
						  << "1.Manager\n"
						  << "2.Receptionist\n";
				do {
					std::cout << "--> ";
					std::cin >> UserType;
					if (std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				} while (UserType < 1 || UserType > 2);

				while (true){
					std::cout << "How Many Staff? : ";
					std::cin >> Amount;
					if (std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;

				}

				switch (UserType){
					case 1:
						for (int i = 0; i < Amount; i++){
							employee.EnterInfo();
							employee.setPosition("Manager");
							employee.setSalary(Jobs.at("Manager"));
							Users.push_back(employee);
							std::cout << std::endl;
						}
						Users.shrink_to_fit();
						break;
					case 2:
						for (int i = 0; i < Amount; i++){
							employee.EnterInfo();
							employee.setPosition("Receptionist");
							employee.setSalary(Jobs.at("Receptionist"));
							Users.push_back(employee);
							std::cout << std::endl;
						}
						Users.shrink_to_fit();
						break;
				}
				break;
		case 2:
				clearscreen;
				std::cout << "====================>> Staff Position <<====================\n";
				for (const auto& job : StaffJobs){
					std::cout << Index++ << '.' << job.first << std::endl;
				}

				std::cout << "Tip: Please Enter Number!!!" << std::endl;
				do {
					std::cout << "Enter Position : ";
					std::cin >> Position;
					if (std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				} while (Position < 1 || Position > StaffJobs.size());

				while (true){
					std::cout << "How many Staff? : ";
					std::cin >> Amount;
					if (std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				auto selectedIndex = StaffJobs.begin();
				std::advance(selectedIndex, Position - 1);

				Staff staff;
				for (int i = 0; i < Amount; i++){
					staff.EnterInfo();
					staff.setPosition(selectedIndex -> first);
					staff.setSalary(selectedIndex -> second);
					std::cout << std::endl;
					Staffs.push_back(staff);
				}
				Staffs.shrink_to_fit();
				break;
		}
}

void DeleteAccount(std::vector<Staff>& Staffs, std::vector<User>& Users){
	int type, Amount, Index = 1, Position;
	std::string Username, Password, ID;
	bool found = false;
	std::cout << "===============>> Staff Position <<===============\n"
			  << "1.User\n"
			  << "2.Staff" << std::endl;;
	do {
		std::cout << "--> ";
		std::cin >> type;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (type < 1 || type > 2);

	switch (type){
		case 1:
			clearscreen;
			std::cout << "==================>> User Position <<==================\n"
					  << "1.Manager\n"
					  << "2.Receptionist" << std::endl;
			do {
				std::cout << "---> ";
				std::cin >> Position;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			} while (Position < 1 || Position > 2);
			do {
				std::cout << "How many User? ";
				std::cin >> Amount;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			} while (Amount < 1);

			switch (Position){
				case 1:
					for (int i = 0; i < Amount; i++){
						std::cout << "Enter Username : ";
						getline(std::cin >> std::ws, Username);
						for (auto& user: Users){
							if (user.getName() == Username && user.getPosition() == "Manager"){
								if (!found){
									std::cout << "\033[32mFound\033[0m" << std::endl;
									found = true;
								}
								user.DisplayInfo();
							}
						}
						if (found){
							std::cout << "\nEnter the ID to Delete : ";
							std::cin >> ID;
							while (getchar() != '\n');
							for (int j = 0; j < Users.size(); j++){
								if (Username == Users[0].getName() && ID == Users[0].getID()){
									std::cout << "Can't Delete Default Username!!!" << std::endl;
									break;
								}
								else if (Username == Users[j].getName() && ID == Users[j].getID()){
									Users.erase(Users.begin() + j);
									Users.shrink_to_fit();
									break;
								}
							}
						} else std::cout << "\nNot found" << std::endl;
					}
					break;
				case 2:
					for (int i = 0; i < Amount; i++){
						std::cout << "Enter Username : ";
						getline(std::cin >> std::ws, Username);
						for (auto& user : Users){
							if (user.getName() == Username && user.getPosition() == "Receptionist"){
								if (!found){
									std::cout << "\033[32mFound\033[0m" << std::endl;
									found = true;
								}
								user.DisplayInfo();
							}
						}
						if (found){
							std::cout << "\nEnter the ID to Delete : ";
							getline(std::cin >> std::ws, ID);
							while (getchar() != '\n');
							for (int j = 0; j < Users.size(); j++){
								if (Username == Users[j].getName() && ID == Users[j].getID()){
									Users.erase(Users.begin() + j);
									Users.shrink_to_fit();
									break;
								}
							}
						} else std::cout << "Not found" << std::endl;
					}
					break;
			}
			break;
		case 2:
			do {
				std::cout << "How many User? ";
				std::cin >> Amount;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			} while (Amount < 1);

			for (int i = 0; i < Amount; i++){
				std::cout << "Enter Username : ";
				getline(std::cin >> std::ws, Username);
				for (auto& staff : Staffs){
					if (Username == staff.getName()){
						if (!found){
							std::cout << "\033[32mFound\033[0m" << std::endl;
							found = true;
						}
						staff.DisplayInfo();
					}
					if (found){
						std::cout << "\nEnter ID to Delete : ";
						std::cin >> ID;
						while (getchar() != '\n');
						for (int j = 0; j < Staffs.size(); j++){
							if (Username == Staffs[j].getName() && ID == Staffs[j].getID()){
								Staffs.erase(Staffs.begin() + j);
								Staffs.shrink_to_fit();
								break;
							}
						}
					} else std::cout << "Not found" << std::endl;
				}
			}
		break;
	}
}

void DisplayInfo(std::vector<Staff>& Staffs, std::vector<User>& Users, bool isAdmin){
	bool hasManager = false, hasReceptionist = false;
	bool hasStaff = !Staffs.empty();

	for (auto& user : Users){
		if (user.getPosition() == "Manager")
			hasManager = true;
		else if (user.getPosition() == "Receptionist")
			hasReceptionist = true;
	}

	if (hasManager && isAdmin){
		std::cout << "======================>> Manager <<=====================\n";
		for (int i = 0; i < Users.size(); i++){
			if (Users[i].getPosition() == "Manager"){
				Users[i].DisplayInfo();
				std::cout << std::endl;
			}
		}
	}
	if (hasReceptionist && isAdmin){
		std::cout << "===================>> Receptionist <<===================\n";
		for (int i = 0; i < Users.size(); i++){
			if (Users[i].getPosition() == "Receptionist"){
				Users[i].DisplayInfo();
				std::cout << std::endl;
			}
		}
	}
	if (hasStaff){
		std::cout << "=======================>> Staff <<======================\n";
		for (int i = 0; i < Staffs.size(); i++){
			Staffs[i].DisplayInfo();
			std::cout << std::endl;
		}
	}

	if (!hasManager && !hasReceptionist && !hasStaff && isAdmin){
		std::cout << "No Employee!!!" << std::endl;
	}
	if (!hasStaff && !isAdmin){
		std::cout << "No Employee!!!" << std::endl;
	}
}

void SearchInfo(std::vector<Staff> Staffs, std::vector<User>& Users, bool isAdmin){
	std::string username, id;
	bool isfound = false;
	int searchtype;
	char usertypes = (isAdmin) ? '1' : '2';

	do {
		clearscreen;
		std::cout << "======================>> Search Staffs <<=====================\n"
				<< "1. Name Search\n"
				<< "2. ID Search\n"
				<< "Choose : ";
		std::cin >> searchtype;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (searchtype < 1 || searchtype > 2);

	switch (searchtype) {
		case 1:
			std::cout << "Enter Staff Name : ";
			getline(std::cin >> std::ws, username);
			std::cout << std::endl;
			switch (usertypes){
				case '1':
					for (auto& user : Users){
						if (username == user.getName()){
							user.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					for (auto& staffs : Staffs){
						if (username == staffs.getName()){
							staffs.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					break;
				case '2':
					for (auto& staffs : Staffs){
						if (username == staffs.getName()){
							staffs.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					break;
			}
			if (!isfound){
				std::cout << "Not found!!!" << std::endl;
			}
			break;
		case 2:
			std::cout << "Enter Staff ID : ";
			getline(std::cin >> std::ws, id);
			std::cout << std::endl;
			switch (usertypes){
				case '1':
					for (auto& user : Users){
						if (id == user.getID()){
							user.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					for (auto& staffs : Staffs){
						if (id == staffs.getID()){
							staffs.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					break;
				case '2':
					for (auto& staffs : Staffs){
						if (id == staffs.getID()){
							staffs.DisplayInfo();
							std::cout << std::endl;
							isfound = true;
						}
					}
					break;
			}
			if (!isfound){
				std::cout << "Not found!!!" << std::endl;
			}
			break;
	}
	
}

void OrderRoom(std::vector<Room>& Rooms){
	bool Ordered = false, isAvailable = false, isFull = true;
	char Foodservice;
	std::string whatroom;
	int Number;
	while (!Ordered){
		std::cout << "=================>> Room Order <<=================" << std::endl;
		std::cout << "Display Available room" << std::endl;
		for (int i = 0; i < Rooms.size(); i++){
			if (Rooms[i].getAvailable()){
				std::cout << "\033[32m----> Room\033[0m" << std::endl;
				Rooms[i].DisplayRoom(0);
				isFull = false;
			}
		}
		if (!isFull){
			while (true){
				std::cout << "\nHow many Room?\n"
						  << "---> ";
				std::cin >> Number;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;

			}
			for (int i = 0; i < Number; i++){
				std::cout << "Enter Room : ";
				getline(std::cin >> std::ws, whatroom);

				for (int i = 0; i < Rooms.size(); i++){
					if (whatroom == Rooms[i].getRoomNumber() && Rooms[i].getAvailable()){
						Ordered = true;
						isAvailable = true;
						std::cout << "\033[34mCustomer Info\033[0m" << std::endl;
						Rooms[i].ChangeCustomer();
						do {
							std::cout << "Food Service 30$ (y/n): ";
							std::cin >> Foodservice;
							while (getchar() != '\n');
							Foodservice = tolower(Foodservice);
						} while (Foodservice != 'y' && Foodservice != 'n');
						(Foodservice == 'y') ? Rooms[i].setFoodService(true) : Rooms[i].setFoodService(false);
						std::cout << std::endl;
					}
				}
				if (isAvailable == false){
					i--;
					std::cout << "Room not Available!!!" << std::endl;
				}
			}
		} else {
			std::cout << "\n\033[32mRoom is Full!!!\033[0m" << std::endl;
			Ordered = true;
		}
	}
}

void CheckOutRoom(std::vector <Room>& Rooms){
	std::string RoomNumber;
	int choose, Days;

	bool isAvailable = true, isExist = false, found = false;
	for (auto& bookedRoom : Rooms){
		if (bookedRoom.getAvailable() == false){
			if (!found){
				std::cout << "============>> Checkout Room <<============\n"
						  << "1.Early Checkout\n"
						  << "2.Checkout On Date" << std::endl;
				do {
					std::cout << "Choose : ";
					std::cin >> choose;
					if (std::cin.fail()){
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						continue;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				} while (choose < 1 || choose > 2);
				std::cout << "\033[31m---> \033[0m" << "What room do you want to checkout? : " << std::endl;
			}
			bookedRoom.DisplayRoom(1);
			found = true;
			std::cout << std::endl;
		}
	}
	if (found){
		while (true){
			std::cout << "Tip : Enter Room Number!!!" << std::endl;
			std::cout << "\033[32m--->\033[0m ";
			std::cin >> RoomNumber;
			if (std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;

		}
	}
	for (auto& room : Rooms){
		if (RoomNumber == room.getRoomNumber()){
			isExist = true;
			if (room.getAvailable() == false){
				if (choose == 1){
					do {
						std::cout << "Enter the Stayed Day : ";
						std::cin >> Days;
						if (std::cin.fail()){
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							Days = -1;
							continue;
						}
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					} while (Days < 0 || Days > room.getDST());

					room.setDST(Days);
				}
				isAvailable = true;
				std::cout << "\n\033[32mChecked Out Room\033[0m" << std::endl;
				room.DisplayRoom(1);

				room.CheckOutCustomer();
				room.setAvailable(true);
				std::cout << std::endl;
			} else {
				std::cout << "Room is Already Available" << std::endl;
			}
		}
	}
	if (!found){
		std::cout << "Room is All Available" << std::endl;
		isExist = true;
	}
	if (!isExist){
		std::cout << "Room didn't Exist" << std::endl;
	}
}

bool Login(std::vector <User> Users){
	bool Verified = false;
	bool isAdmin = false;
	std::string Username, Password;
	int Choose;
	while (!Verified){
		clearscreen;
		std::cout << "---> Login As\n"
				  << "1.Manager\n"
				  << "2.Receptionist\n"
				  << "Choose : ";
		std::cin >> Choose;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (Choose < 1 || Choose > 2){
			continue;
		}
		std::cout << "Enter Username : ";
		getline(std::cin >> std::ws, Username);
		std::cout << "Enter Password : ";
		getline(std::cin, Password);

		std::string Position = (Choose == 1) ? "Manager" : "Receptionist";
		for (int i = 0; i < Users.size(); i++){
			if (Username == Users[i].getName() && Users[i].verifyPassword(Password) && Position == Users[i].getPosition()){
				Verified = true;
				if (Position == "Manager"){
					isAdmin = true;
				}
			}
		}
	}
	return isAdmin;
}

void readinfo(std::vector <Room>& Rooms, std::vector <Staff>& Staffs, std::vector <User>& Users, const std::map<std::string, float>& Jobs){
	std::ifstream Customers;
	Customers.open("Customers.txt");
	if (Customers.is_open()){
		std::string line;
		int Foundline = 0;
		while (getline(Customers, line) && !line.empty()){
			std::string room, FoodService, Name, DOB, Contact;
			char Gender;
			int Age, Day;

			size_t find_room = line.find("Room : ");
			size_t find_DST = line.find("DST : ");
			size_t find_foodservice = line.find("Food Service : ");
			size_t find_name = line.find("Name : ");
			size_t find_gender = line.find("Gender : ");
			size_t find_age = line.find("Age : ");
			size_t find_dob = line.find("DOB : ");
			size_t find_contact = line.find("Contact : ");

			if (find_room != std::string::npos){
				find_room += 7;
				room = line.substr(find_room, find_DST - find_room - 3);
				Foundline += 1;
			}

			if (find_DST != std::string::npos){
				find_DST += 6;
				Day = std::stoi(line.substr(find_DST, find_foodservice - find_DST - 3));
				Foundline += 1;
			}

			if (find_foodservice != std::string::npos){
				find_foodservice += 15;
				FoodService = line.substr(find_foodservice, find_name - find_foodservice - 3);
				Foundline += 1;
			}

			if (find_name != std::string::npos){
				find_name += 7;
				Name = line.substr(find_name, find_gender - find_name - 3);
				Foundline += 1;
			}

			if (find_gender != std::string::npos){
				find_gender += 9;
				Gender = line.at(find_gender);
				Foundline += 1;
			}

			if (find_age != std::string::npos){
				find_age += 6;
				Age = std::stoi(line.substr(find_age, find_dob - find_age - 3));
				Foundline += 1;
			}

			if (find_dob != std::string::npos){
				find_dob += 6;
				DOB = line.substr(find_dob, find_contact - find_dob - 3);
				Foundline += 1;
			}

			if (find_contact != std::string::npos){
				find_contact += 10;
				Contact = line.substr(find_contact);
				Foundline += 1;
			}

			if (Foundline == 8){
				Customer customer;
				customer.setInfo(Name, Gender, Age, DOB, Contact);
				for (auto& currentRoom : Rooms){
					bool Foodservice = (FoodService == "True") ? true : false; 
					if (room == currentRoom.getRoomNumber()){
						currentRoom.setAvailable(0);
						currentRoom.setCustomer(customer);
						currentRoom.setDST(Day);
						currentRoom.setFoodService(Foodservice);
						break;
					}
				}
				Foundline = 0;
			}

		}
		Customers.close();
	}

	std::ifstream staffs;
	staffs.open("Staffs.txt");
	if (staffs.is_open()){
		std::string line;
		int Foundline = 0;
		while (getline(staffs, line) && !line.empty()){
			std::string ID, Name, DOB, Position, StartTime, Address, Contact;
			char Gender;
			int Age;

			size_t find_id = line.find("ID : ");
			size_t find_name = line.find("Name : ");
			size_t find_gender = line.find("Gender : ");
			size_t find_age = line.find("Age : ");
			size_t find_dob = line.find("DOB : ");
			size_t find_position = line.find("Position : ");
			size_t find_st = line.find("ST : ");
			size_t find_address = line.find("Address : ");
			size_t find_contact = line.find("Contact : ");

			if (find_id != std::string::npos){
				find_id += 5;
				ID = line.substr(find_id, find_name - find_id - 3);
				Foundline += 1;
			}

			if (find_name != std::string::npos){
				find_name += 7;
				Name = line.substr(find_name, find_gender - find_name - 3);
				Foundline += 1;
			}

			if (find_gender != std::string::npos){
				find_gender += 9;
				Gender = line.at(find_gender);
				Foundline += 1;
			}

			if (find_age != std::string::npos){
				find_age += 6;
				Age = std::stoi(line.substr(find_age, find_dob - find_age - 3));
				Foundline += 1;
			}

			if (find_dob != std::string::npos){
				find_dob += 6;
				DOB = line.substr(find_dob, find_position - find_dob - 3);
				Foundline += 1;
			}

			if (find_position != std::string::npos){
				find_position += 11;
				Position = line.substr(find_position, find_st - find_position - 3);
				Foundline += 1;
			}

			if (find_st != std::string::npos){
				find_st += 5;
				StartTime = line.substr(find_st, find_address - find_st - 3);
				Foundline += 1;
			}

			if (find_address != std::string::npos){
				find_address += 10;
				Address = line.substr(find_address, find_contact - find_address - 3);
				Foundline += 1;
			}

			if (find_contact != std::string::npos){
				find_contact += 10;
				Contact = line.substr(find_contact);
				Foundline += 1;
			}
			
			if (Foundline == 9){
				Staff staff;
				staff.setInfo(ID, Name, Gender, Age, DOB, Position, StartTime, Address, Contact);
				staff.setSalary(Jobs.at(Position));

				Staffs.push_back(staff);
				Foundline = 0;
			}
		}
		Staffs.shrink_to_fit();
		staffs.close();
	}

	std::ifstream users;
	users.open("Users.txt");
	if (users.is_open()){
		std::string line;
		int Foundline = 0;
		while (getline(users, line) && !line.empty()){
			std::string ID, Name, DOB, Position, StartTime, Address, Contact, Password;
			char Gender;
			int Age;

			size_t find_id = line.find("ID : ");
			size_t find_name = line.find("Name : ");
			size_t find_gender = line.find("Gender : ");
			size_t find_age = line.find("Age : ");
			size_t find_dob = line.find("DOB : ");
			size_t find_position = line.find("Position : ");
			size_t find_st = line.find("ST : ");
			size_t find_address = line.find("Address : ");
			size_t find_contact = line.find("Contact : ");
			size_t find_password = line.find("Password : ");

			if (find_id != std::string::npos){
				find_id += 5;
				ID = line.substr(find_id, find_name - find_id - 3);
				Foundline += 1;
			}

			if (find_name != std::string::npos){
				find_name += 7;
				Name = line.substr(find_name, find_gender - find_name - 3);
				Foundline += 1;
			}

			if (find_gender != std::string::npos){
				find_gender += 9;
				Gender = line.at(find_gender);
				Foundline += 1;
			}

			if (find_age != std::string::npos){
				find_age += 6;
				Age = std::stoi(line.substr(find_age, find_dob - find_age - 3));
				Foundline += 1;
			}

			if (find_dob != std::string::npos){
				find_dob += 6;
				DOB = line.substr(find_dob, find_position - find_dob - 3);
				Foundline += 1;
			}

			if (find_position != std::string::npos){
				find_position += 11;
				Position = line.substr(find_position, find_st - find_position - 3);
				Foundline += 1;
			}

			if (find_st != std::string::npos){
				find_st += 5;
				StartTime = line.substr(find_st, find_address - find_st - 3);
				Foundline += 1;
			}

			if (find_address != std::string::npos){
				find_address += 10;
				Address = line.substr(find_address, find_contact - find_address - 3);
				Foundline += 1;
			}

			if (find_contact != std::string::npos){
				find_contact += 10;
				Contact = line.substr(find_contact, find_password - find_contact - 3);
				Foundline += 1;
			}

			if (find_password != std::string::npos){
				find_password += 11;
				Password = line.substr(find_password);
				Foundline += 1;
			}

			User user;
			user.setInfo(ID, Name, Gender, Age, DOB, Position, StartTime, Address, Contact, Password);
			user.setSalary(Jobs.at(Position));

			Users.push_back(user);
		}
		Users.shrink_to_fit();
		users.close();
	}
}

void writeinfo(std::vector<Room> Rooms, std::vector<Staff> Staffs, std::vector<User> Users){
	std::ofstream Customers;
	Customers.open("Customers.txt");

	for (int i = 0; i < Rooms.size(); i++){
		if (!Rooms[i].getAvailable()){
			std::string room = Rooms[i].getRoomNumber();
			int DST = Rooms[i].getDST();
			std::string foodservice = (Rooms[i].getFoodService()) ? "True" : "False";

			std::tuple<std::string, char, int, std::string, std::string> information = Rooms[i].getCustomer().getInfo();
			std::string Name = std::get<0> (information);
			char Gender = std::get<1> (information);
			int Age = std::get<2> (information);
			std::string DOB = std::get<3> (information);
			std::string Contact = std::get<4> (information);

			Customers << "Room : " << room << " , DST : " << DST << " , Food Service : " << foodservice << " , Name : " << Name << " , Gender : " << Gender << " , Age : " << Age << " , DOB : " << DOB << " , Contact : " << Contact << std::endl;
		}
	}
	Customers.close();

	std::ofstream staffs;
	staffs.open("Staffs.txt");
	for (auto& staff : Staffs){
		std::tuple<std::string, std::string, char, int, std::string, std::string, std::string, std::string, std::string> information = staff.getInfo(); 
		std::string ID = std::get<0> (information);
		std::string Name = std::get<1> (information);
		char Gender = std::get<2> (information);
		int Age = std::get<3> (information);
		std::string DOB = std::get<4> (information);
		std::string Position = std::get<5> (information);
		std::string StartTime = std::get<6> (information);
		std::string Address = std::get<7> (information);
		std::string Contact = std::get<8> (information);
		staffs << "ID : " << ID << " , Name : " << Name << " , Gender : " << Gender << " , Age : " << Age << " , DOB : " << DOB << " , Position : " << Position << " , ST : " << StartTime << " , Address : " << Address << " , Contact : " << Contact << std::endl;
	}
	staffs.close();

	std::ofstream users;
	users.open("Users.txt");
	for (int i = 1; i < Users.size(); i++){
		std::tuple<std::string, std::string, char, int, std::string, std::string, std::string, std::string, std::string, std::string> information = Users[i].getInfo(); 
		std::string ID = std::get<0> (information);
		std::string Name = std::get<1> (information);
		char Gender = std::get<2> (information);
		int Age = std::get<3> (information);
		std::string DOB = std::get<4> (information);
		std::string Position = std::get<5> (information);
		std::string StartTime = std::get<6> (information);
		std::string Address = std::get<7> (information);
		std::string Contact = std::get<8> (information);
		std::string Password = std::get<9> (information);
		users << "ID : " << ID << " , Name : " << Name << " , Gender : " << Gender << " , Age : " << Age << " , DOB : " << DOB << " , Position : " << Position << " , ST : " << StartTime << " , Address : " << Address << " , Contact : " << Contact << " , Password : " << Password << std::endl;
	}
	users.close();
}

class Table{
	private:
		int number;
		std::vector <std::string> orderedfoods;
		double payment = 0;
	public:
		Table(int number):number(number){}
		int getNumber(){
			return number;
		}
		std::vector <std::string> getOrderedfoods(){
			return orderedfoods;
		}
		void setOrderedfoods(std::string food){
			orderedfoods.push_back(food);
		}
		void setPayment(float price){
			payment += price;
		}
		double getPayment(){
			return payment;
		}
};

void ManyOrder(std::vector<Table>& Tables, std::vector <std::tuple<std::string, std::string, float>>& Menus, std::string Menu, std::string Type){
	int numberoforder, Order, Table, index = 1;
	std::vector <std::string> Ordered;
	std::map <std::string, float> OptimizedMenus;

	for (auto& menu : Menus){
		if (std::get<1> (menu) == Type){
			OptimizedMenus[std::get<0> (menu)] = std::get<2> (menu);
		}
	}

	std::cout << Menu << " Menu" << std::endl;
	for (auto& menu : OptimizedMenus){
		std::cout << index++ << '.' << std::get<0> (menu) << " (" << std::get<1> (menu) << '$' << ')' << std::endl;
	}

	while (true){
		std::cout << "How many " << Menu << "?\n"
				  << "--> ";
		std::cin >> numberoforder;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;

	}
	for (int i = 0; i < numberoforder; i++){
		do {
			std::cout << "\nOrder Number " << i + 1 << std::endl;
			std::cout << "--> ";
			std::cin >> Order;
			if (std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		} while (Order < 1 || Order > index - 1);
		
		auto it = OptimizedMenus.begin();
		std::advance(it, Order - 1);
		Ordered.push_back(it -> first);
		Ordered.shrink_to_fit();
	}
	do {
		std::cout << "Table : ";
		std::cin >> Table;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (Table < 1 || Table > Tables.size());

	for (auto& table : Tables){
		if (Table == table.getNumber()){
			for (const auto& food : Ordered){
				table.setOrderedfoods(food);
				table.setPayment(OptimizedMenus[food]);
			}
		}
	}
}

void OrderFood(std::vector <std::tuple<std::string, std::string, float >>& Foods, std::vector <std::tuple<std::string, std::string, float >>& Drinks, std::vector<Table>& Tables){
	int choose, alcohol;

	do {
		clearscreen;
		std::cout << "-----> Food Shift <-----\n"  
				  << "1.Breakfast\n"
				  << "2.Lunch\n"
				  << "3.Dinner\n"
				  << "\n-----> Drink Menu <-----\n"
				  << "4.Natural Drinks\n"
				  << "5.Soft Drinks\n"
				  << "6.Coffee\n"
				  << "7.Alcohol\n"
				  << "--> ";
		std::cin >> choose;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (choose < 1 || choose > 7);

	clearscreen;
	switch (choose){
		case 1:
			ManyOrder(Tables, Foods, "Food", "Breakfast");
			break;
		case 2:
			ManyOrder(Tables, Foods, "Food", "Lunch");
			break;
		case 3:
			ManyOrder(Tables, Foods, "Food", "Dinner");
			break;
		case 4:
			ManyOrder(Tables, Drinks, "Drinks", "Natural");
			break;
		case 5:
			ManyOrder(Tables, Drinks, "Soft Drink", "Soft Drink");
			break;
		case 6:
			ManyOrder(Tables, Drinks, "Coffee", "Coffee");
			break;
		case 7:
			do {
				std::cout << "--> Alcohol <--\n"
						  << "1.Beer\n"
						  << "2.Cocktail\n"
						  << "Choose : ";
				std::cin >> alcohol;
				if (std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			} while (alcohol < 1 || alcohol > 2);

			switch (alcohol){
				case 1:
					clearscreen;
					ManyOrder(Tables, Drinks, "Beer", "Beer");
					break;
				case 2:
					clearscreen;
					ManyOrder(Tables, Drinks, "Cocktails", "Cocktail");
					break;
			}
	}
}

void RestaurantMenu(std::vector <std::tuple <std::string, std::string, float> > Foods, std::vector <std::tuple <std::string, std::string, float> > Drinks, std::vector <Table> Tables){
	int Choose;

	do {
		clearscreen;
		std::cout << "========>> Main Menu <<========\n"
				  << "1.Go to Menu\n"
				  << "2.Table Reception\n"
				  << "3.Exit\n"
				  << "Choose : ";
		std::cin >> Choose;
		if (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (Choose){
			case 1:
				clearscreen;
				OrderFood(Foods, Drinks, Tables);
				break;
			case 2:
				clearscreen;
				for (int i = 0; i < Tables.size(); i++){
					if (!(Tables[i].getOrderedfoods().empty())){
						std::map <std::string, int> OrderedTimes;
						int index = 1;
						for (int j = 0; j < Tables[i].getOrderedfoods().size(); j++){
							OrderedTimes[Tables[i].getOrderedfoods().at(j)]++;
						}
						std::cout << "Table : " << Tables[i].getNumber() << '\n'
								  << "\033[32mOrder List\033[0m\n";
						for (auto it = OrderedTimes.begin(); it != OrderedTimes.end(); it++){
							if ((it -> second) == 1){
								std::cout << index++ << '.' << it -> first << std::endl;
							}
							else {
								std::cout << index++ << '.' << it -> first << " x" << it -> second << std::endl;
							}
						}
						std::cout << "\n* Cost in Dollars : " << Tables[i].getPayment() << '$' << std::endl;
						std::cout << "* Cost in Riel : " << size_t(Tables[i].getPayment() * 4150) << " Riel" << std::endl;
						std::cout << std::endl;
					}
				}
				std::cout << "Press Enter to Continue!!!";
				getchar();
				break;

		}
	} while (Choose != 3);
}

bool Menu(bool& shutdownSignal, bool& isAdmin, std::vector <Room>& Rooms, std::vector <User>& Users, std::vector <Staff>& Staffs, const std::map <std::string, float>& Jobs, const Foodtype& Foods, const Foodtype& Drinks, std::vector<Table>& Tables){
	int Choose;
	bool found = false;
	do {
		clearscreen;
		std::cout << "===================>> Menu <<==================\n"
				  << "1.Enter New Staff\n"
				  << "2.Display Available Room\n"
				  << "3.Checkin Room\n"
				  << "4.Checkout Room\n"
				  << "5.Logout\n"
				  << "6.Shutdown\n"
				  << "7.Restaurant\n"
				  << "8.Display Staffs\n"
				  << "9.Search Staff" << std::endl;
		if (isAdmin){
			std::cout << "10.Delete User\n"
					  << "---> ";
			std::cin >> Choose;
			while (getchar() != '\n');
			if (std::cin.fail()){
				std::cin.clear();
				continue;
			}
		} else {
			std::cout << "---> ";
			std::cin >> Choose;
			while (getchar() != '\n');
			if (std::cin.fail()){
				std::cin.clear();
				continue;
			}
		}
	} while (!(isAdmin) && Choose > 9);

	switch (Choose){
		case 1:
			clearscreen;
			CreateStaff(Staffs, Users, Jobs, isAdmin);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 2:
			clearscreen;
			for (auto& room : Rooms){
				if (room.getAvailable()){
					if (!found){ 
						std::cout << "============>> Available Room <<============" << std::endl;
						found = true;
					}
					room.DisplayRoom(0);
					std::cout << std::endl;
				}
			}
			if (!found){
				std::cout << "No Available room!!!" << std::endl;
			}
			found = false;
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 3:
			clearscreen;
			OrderRoom(Rooms);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 4:
			clearscreen;
			CheckOutRoom(Rooms);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 5:
			clearscreen;
			return true;
			break;
		case 6:
			clearscreen;
			shutdownSignal = true;
			return true;
			break;
		case 7:
			RestaurantMenu(Foods, Drinks, Tables);
			break;
		case 8:
			clearscreen;
			DisplayInfo(Staffs, Users, isAdmin);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 9:
			SearchInfo(Staffs, Users, isAdmin);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
		case 10:
			clearscreen;
			DeleteAccount(Staffs, Users);
			std::cout << "Press enter to continue!!!";
			getchar();
			break;
	}
	return false;
}

int main() {
	// this is main need room staff and user
	typedef std::vector<std::tuple <std::string, std::string, int, int, float>> RoomProperties;

	const std::map <std::string, float> Jobs = { {"Manager", 1500}, {"Receptionist", 1200}, {"Chief", 800},
												 {"Security", 500}, {"Cleaner", 500} };

	const RoomProperties rooms = { 
									{"001", "Standard", 1, 1, 20},
									{"002", "Standard", 1, 1, 20},
									{"003", "Standard", 2, 1, 30},
									{"004", "VIP", 1, 1, 40},
									{"005", "VIP", 2, 1, 50},
									{"006", "Standard", 1, 1, 20},
									{"007", "Standard", 1, 2, 20},
									{"008", "Standard", 2, 2, 30},
									{"009", "VIP", 1, 2, 40},
									{"010", "VIP", 2, 2, 50},
									{"011", "Standard", 1, 1, 20},
									{"012", "Standard", 1, 1, 20},
									{"013", "Standard", 2, 1, 40},
									{"014", "VIP", 2, 2, 40},
									{"015", "VIP", 2, 1, 50},
								 };

	const Foodtype Foods = {
		// Morning
		{"Hot Dog", "Breakfast", 3.5},
		{"Pancakes", "Breakfast", 7},
		{"Eggs with Toast", "Breakfast", 6.5},
		{"Sandwich", "Breakfast", 4},
		{"Cheese Warp", "Breakfast", 8},
		{"Omelet", "Breakfast", 5.5},
		{"Burrito", "Breakfast", 8.5},
		{"French toas", "Breakfast", 9},
		{"Scrambled eggs", "Breakfast", 10},
		{"Fruit Salad", "Breakfast", 13},

		// Afternoon
		{"Pizza", "Lunch", 4.5},
		{"Hamburger", "Lunch", 3.5},
		{"Sushi", "Lunch", 100},
		{"Bacon Cheese burger", "Lunch", 5},
		{"Stronganoff", "Lunch", 8},
		{"Vegetable chili", "Lunch", 8},
		{"Four Cheese", "Lunch", 9},
		{"Broccoli Cheddar Soup", "Lunch", 6},
		{"Mozzarella Sticks", "Lunch", 7},
		{"Hot Fudge Sundae", "Lunch", 5},
		{"Strawberry Sundae", "Lunch", 5},
		{"Vanilla Ice Cream", "Lunch", 4},
		{"Butterscotch Ice Cream", "Lunch", 6},

		// Evening
		{"Steak", "Dinner", 5},
		{"Sausage", "Dinner", 4.5},
		{"Fried fish", "Dinner", 6},
		{"Chicken soup with prunes", "Dinner", 5},
		{"Potato anchovy salad", "Dinner", 6},
		{"Roast beef", "Dinner", 11},
		{"Fuit Cake", "Dinner", 7},
		{"Scotch eggs", "Dinner", 4},
		{"Cod with mustard sauce", "Dinner", 8},
		{"Baked troutwrapped in bacon", "Dinner", 10},
	};

	const Foodtype Drinks = {
		{"Water", "Natural", 0.5},
		{"Cambodia Water", "Natural", 1},
		{"Vital", "Natural", 0.5},

		{"Cocacola", "Soft Drink", 1},
		{"Pepsi", "Soft Drink", 1},
		{"Sprite", "Soft Drink", 1},
		{"Mountain Dew", "Soft Drink", 1},
		{"Dr. Pepper", "Soft Drink", 1.10},
		{"7-UP", "Soft Drink", 1},
		{"Root Beer", "Soft Drink", 1.10},
		{"Sunkist", "Soft Drink", 1},
		{"Canada Dry Ginger Ale", "Soft Drink", 1},
		{"Barq's Root Beer", "Soft Drink", 1.25},

		{"Cappuccino", "Coffee", 1.25},
		{"Expresso", "Coffee", 2},
		{"Americano", "Coffee", 2.50},
		{"Latte", "Coffee", 2.50},
		{"Macchiato", "Coffee", 2.50},
		{"Mocha", "Coffee", 4},
		{"Flat White", "Coffee", 3.50},
		{"Cortado", "Coffee", 3.00},
		{"Cold Brew", "Coffee", 3.50},
		{"Affogato", "Coffee", 4.00},

		{"Gangzberg", "Beer", 0.80},
		{"Angkor", "Beer", 0.80},
		{"Tiger Beer", "Beer", 0.80},
		{"Black Cat Beer", "Beer", 1.00},
		{"ABC", "Beer", 1.25},
		{"Anchor", "Beer", 0.80},
		{"Krud", "Beer", 1.00},
		{"Hanuman", "Beer", 1.00},
		{"Cambodia", "Beer", 0.80},
		{"Vattanac Beer", "Beer", 1.00},

		{"Negroni", "Cocktail", 55},
		{"Margarita", "Cocktail", 8.00},
		{"Mojito", "Cocktail", 7.00},
		{"Old Fashioned", "Cocktail", 10},
		{"Cosmopolitan", "Cocktail", 9},
		{"Martini", "Cocktail", 10},
		{"Pina Colada", "Cocktail", 8},
		{"Negroni", "Cocktail", 9},
		{"Wisky Sour", "Cocktail", 8},
		{"Daiquiri", "Cocktail", 7.00},
		{"Manhattan", "Cocktail", 9},
	};

	std::vector <Table> Tables = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	std::vector<Room> Rooms;
	std::vector<Staff> Staffs;
	std::vector<User> Users;

	User Manager;
	Manager.setInfo("23", "Hello", 'F', 23, "01/01/2000", "Manager", "7AM", "Phnom Penh", "0123456789", "Hello123");
	Manager.setSalary(Jobs.at("Manager"));
	Users.push_back(Manager);

	for (auto& currentroom : rooms){
		std::string room = std::get<0> (currentroom);
		std::string VIP = std::get<1> (currentroom);
		int bed = std::get<2> (currentroom);
		int floor = std::get<3> (currentroom);
		float price = std::get<4> (currentroom);
		Room newroom(room, VIP, bed, floor, price);
		newroom.setAvailable(true);
		Rooms.push_back(newroom);
		Rooms.shrink_to_fit();
	}

	readinfo(Rooms, Staffs, Users, Jobs);

	bool shutdownSignal = false;
	while (!shutdownSignal){
		bool isAdmin = Login(Users);
		bool exit = false;
		while (!exit){
			exit = Menu(shutdownSignal, isAdmin, Rooms, Users, Staffs, Jobs, Foods, Drinks, Tables);
		}
	}

	writeinfo(Rooms, Staffs, Users);
	return 0;
}