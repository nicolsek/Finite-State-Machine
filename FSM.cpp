#include <iostream>
#include <vector>

//States for the state creation.
enum StateType {
	undefined, //If the state is undefined it will default to 0.

	state0,
	state1,
	state2,
	state3,

	final, //Final state to iterate through.
};

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
};

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
        switch (state.getType()) {
            case StateType::state0:
                std::cout << "Executing state0" << std::endl;
                break;
            case StateType::state1:
                std::cout << "Executing state1" << std::endl;
                break;
            case StateType::state2:
                std::cout << "Executing state2" << std::endl;
                break;
            case StateType::state3:
                std::cout << "Executing state3" << std::endl;
                break;
        }
    
        this->popState();
    }
}

/**
 * @desc The main function.
 */
int main() {
	Stack stack;

	for (int stateType = state0; stateType != StateType::final; ++stateType) { //Get the first state and increase every state until done.
		State state = State(StateType(stateType)); //Create the new state to add.
		stack.addState(state); //Add that state to the stack.
	}

	stack.printStack(); //Print the contents of the stack.

    stack.executeStack();

    stack.printStack(); //After executing the states check the stack to see if they've been completed.

	return 0;
}
