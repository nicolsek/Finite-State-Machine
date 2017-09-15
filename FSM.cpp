#include <iostream>
#include <string>
#include <vector>


/* Simulating A Vending Machine! */

/* Vending Machine States --
 * Ready
 * Depositing Food Item
 * Reading Currency
 * Defective Currency :(
 * Being Shaken
 */

//States for the state creation.
enum StateType {
    Ready,
    Deposit,
    Reading,
    Invalid,
    Shaken,

};

//Acceptable commands to give the communcations bus as keywords.
std::string InstKeywords [4] = {"Deposit", "Retrieve", "deposit", "retrieve"}; 


/**
 * @desc An implementation of a communication bus for a vending machine.
 */
class ComBus {
    public:
        /* Public Constructor */
        ComBus();

        /* Local Members */
        void sendInstruct(std::string); //Send an instruction to be parsed by the com bus which will then invoke states.
};

/**
 * @desc It parses an instruction sent and will invoke the functions needed.
 * @param {const*} inst the instruction to be parsed.
 */
void ComBus::sendInstruct(std::string inst) {
    /** Keywords to parse
     * Deposit [Amount of money in relation to 1 being a whole dollar and .1 being a dime]
     * Retrieve [Letter + Number]
     */

    std::string command;

    for (auto &keyword : InstKeywords) {
        std::string::size_type n = inst.find(keyword); //<--- Size of string if found

        if (n != std::string::npos) {
            std::cout << inst.substr(n, keyword.length()) << std::endl; 
        }
    }
}

ComBus::ComBus() {

}

/**
 * @desc A single state for the stack.
 */
class State {
	public:
		/* Public Constructor */
		State(StateType); //Public constructor.

		/* Local Members */
		StateType getType(); //Returns the state type of the state.

	private:
		StateType stateType; //The type of state this is.
};;

/**
 * @desc The public constructor for the state.
 * @param {StateType} type the type of state for the state.
 */
State::State(StateType type) {
	this->stateType = type; //Set this state type for the state.
}

/**
 * @desc Get the type of this state.
 * @return {StateType} the type of state.
 */
StateType State::getType() {
	return this->stateType;
}

/**
 * @desc The stack for the FSM.
 */
class Stack {
	public:
		/* Public Constructor */
		Stack();
		
		/* Local Members */
		void addState(State); //Add a state to the top of the stack.
		void popState(); //Pop the state at the top of the stack.
        void executeStack(); //Execute the current states of the stack.

		/* Debug Members */
		void printStack(); //Print the stack.

	private:
		std::vector<State> stack; //The stack.
};

/**
 * @desc Public constructor for the stack.
 */
Stack::Stack() {

}

/**
 * @desc Add a state to the top of the stack.
 * @param {State} state the state to be pushed back.
 */
void Stack::addState(State state) {
	this->stack.push_back(state);
}

/**
 * @desc Pop the state from the top of the stack.
 */
void Stack::popState() {
	this->stack.pop_back(); 
}

/**
 * @desc Print the contents of the stack.
 */
void Stack::printStack() {
	for (auto &state : this->stack) {
		std::cout << "State Type --> " << int(state.getType()) << std::endl; //Get the states type, cast it to an int, and print it. 
	}
}

/**
 * @desc Execute the current states on the stack and pop them as they're completed.
 */
void Stack::executeStack() {
    for (auto &state : this->stack) {
//        switch (state.getType()) {
//        
//        }
    
        this->popState();
    }
}

/**
 * @desc The main function.
 */
int main() {
	Stack stack; //<-- The stack being implemented.
    ComBus combus; //<-- The combus 


    for(;;) { //Main running loop.
        std::string instruction;

        std::cin >> instruction;
        combus.sendInstruct(instruction);
    }

	return 0;
}
