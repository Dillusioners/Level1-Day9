# include <iostream>
# include <vector>
# include <string>

/*
	Author: LeeTuah
	Program: Quiz Application
	For: SuperB league event
*/

// struct for storing question and answer in one place
struct question{
	std::string question;
	char answer;
	std::vector<std::string> options;
};

// initializes the questions struct
struct question Question(std::string question, char answer, std::vector<std::string> list){
	struct question q1;
	
	q1.question = question;
	for(int i = 0; i < 4; i++){
		q1.options.push_back(list[i]);	
	}
	q1.answer = answer;
	
	return q1;	
}

// declaring all of the questions inside a vector
std::vector<struct question> declare(){
	std::vector<struct question> q_list;
	
	q_list.push_back(Question(
	"Who is the final boss of Ohio?",
	'C',
	{"Cameraman", "Milkman", "Gigachad", "You"}
	));
	
	q_list.push_back(Question(
	"What is the fastest language in existence?",
	'B',
	{"C++", "Assembly", "Python", "Japanese"}
	));
	
	q_list.push_back(Question(
	"Jensen Huang is the owner of",
	'D',
	{"Windows Kernal", "Discord", "A.M.D.", "Nvidia"}
	));
	
	q_list.push_back(Question(
	"Why do we use Dark Mode in IDEs?",
	'D',
	{"Doesnot Hurt the eyes", "Who asked?", "Light mode is cringe", "IDK"}
	));
	
	return q_list;	
}

// method for printing a question inside the main code
void printQuestion(struct question q){
	std::cout << q.question << std::endl;
	char x = 65;
	for(int i = 0; i !=4; i++, x++){
		std::cout << x << ". " << q.options[i] << std::endl;
	}
	std::cout << ">> ";
}

int main(int argc, char const* argv[]){
	// printing the welcome message
	std::cout << "#######################\n";
	std::cout << "  WELCOME TO THE QUIZ  ";
	std::cout << "\n#######################\n\n";
	std::cout << "You will be asked four questions.\nChoose the correct answer to get a point.\nNo negative markings are alloted.\n\n";
	
	// initialising all the necessary variables
	int points = 0;
	std::string choice;
	char ch;
	std::vector<struct question> questions = declare();
	
	// iterating through the questions and accepting the answers for them from user
	for(auto i = questions.begin(); i != questions.end(); i++){
		printQuestion(*i);
		std::cin >> choice;
		ch = choice[0];
		
		// checking if answer is in small letter
		if(ch > 90) ch -= 32;
		
		// checking if answer is correct
		if(ch == i->answer){
			points++;
			std::cout << "You gave correct answer and gained a point!\nYour total points is " << points << ". Next Question:\n\n";
		}
		else{
			std::cout << "You gave wrong answer!\nYour total points is " << points << ". The correct answer was option " << i->answer << ". Next Question:\n\n";
		}
	}
	
	std::cout << "There is no next question as you have made it to the end of the quiz!\nCongrats on your score.\n";	
	
	return 0;
}
