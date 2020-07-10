//Mark McCarthy

/*This program evaluates a user given postfix 
expression by leveraging the LIFO property of the 
stack data structure using std::stack template*/

#include<iostream>
#include<stack>
#include<exception>
#include<vector>
#include<sstream>

using namespace std;

	//custom exception declaration and definitions//

//Invalid_Postfix_Ex is thrown when there is an 
//error in the input expression and can not be 
//evaluated correctly.2
struct Invalid_Postfix_Ex : public exception {
	const char* what() const override {
		return"ERROR: Invalid Postfix Expression.\n";
	}
};

//Zero_Division is thrown when the denominator
//of an operation from the stack is 0.
struct Zero_Division : public exception {
	const char* what() const override {
		return "ERROR: Division by Zero.\n";
	}
};

//function to determine if there are sufficient 
//elts in the stack to do an operation.
void can_operate(stack<int> stk);

int main() {

	//init stack
	stack<int> expression;

	//init all var
	char curr;
	string input;
	int temp, num_2, num_1, result,i = 0,flag = 1;

	//prompt user for the input string
	cout << "Enter a Postfix Expression to evaluate."
		<<"Press enter when done: ";
	cin >> input;

	/*while loop passes each elt(curr) of the input string through
	a set of conditions. Based the type of character curr is, curr
	will either be pushed to the stack, used as an operator, or 
	cause an exception to be thrown.*/
	while (i<input.length()) {
		
		curr = input[i];
		
		//if curr is a digit char, push it to the stack
		if (isdigit(curr)) {
			temp = curr-'0';
			expression.push(temp);
		}

		//if curr is an operator, perform the operation on the top 
		//two elts of the stack
		else if (curr == '+'||curr == '-'||curr == '*'||curr =='/') {
			
			//if there are not correct elts available to perform operation
			// throw Invalid Expression exception
			try {
				can_operate(expression);
			}
			catch (const Invalid_Postfix_Ex& err) {
				cerr << err.what() << endl;
				flag = -1;
				break;
			}
			
			//else perform the operation matching curr.
			//operations happen on the top two elts of
			//the stack. Then the result is pushed to 
			//the stack.
			switch (curr) {
			case'+':
				num_2 = expression.top();
				expression.pop();
				num_1 = expression.top();
				expression.pop();
				result = num_1 + num_2;
				expression.push(result);
				break;
			case'-':
				num_2 = expression.top();
				expression.pop();
				num_1 = expression.top();
				expression.pop();
				result = num_1 - num_2;
				expression.push(result);
				break;
			case'*':
				num_2 = expression.top();
				expression.pop();
				num_1 = expression.top();
				expression.pop();
				result = num_1 * num_2;
				expression.push(result); 
				break;
			case'/':
				num_2 = expression.top();
				expression.pop();
				num_1 = expression.top();
				expression.pop();

				//if there is an operation that would cause 
				//a division by zero, throw exception
				try {
					if (num_2 == 0) {
						Zero_Division zde;
						throw zde;
					}
				}
				catch(const Zero_Division& zde){
					std::cerr << zde.what() << endl;
					flag = -1;
					break;
				}
				//else continue
				result = num_1 / num_2;
				expression.push(result);
				break;
			}
		}

		//if curr is not a digit or an operation, it is 
		//an Invalid Expression. throw execption
		else {
			try {
				Invalid_Postfix_Ex err;
				throw err;
			}
			catch (const Invalid_Postfix_Ex& err) {
				cerr << err.what() <<"Bad character."<< endl;
				flag = -1;
			}
			break;
		}

		//increment i(move to next char in input string.
		i++;
	}

	//if the stack is empty after the calculation
	//something was incorrect in the expression or there was
	//none.
	if(expression.empty()) {
		try {
			Invalid_Postfix_Ex err;
			throw err;
		}
		catch (const Invalid_Postfix_Ex& err) {
			cerr << err.what() <<"stack empty"<< endl;
			flag = -1;
		}
	}

	//if there is more than one number left in the
	//stack after the calculation, the expression was
	//invalid.
	if (expression.size() > 1) {
		try {
			Invalid_Postfix_Ex err;
			throw err;
		}
		catch (const Invalid_Postfix_Ex& err) {
			cerr << err.what() <<"too many nums"<< endl;
			flag = -1;
		}
	}

	//if the expression was evaluated correctly output the result
	if (flag > 0) {
		cout << "The expression evaluates to: " << expression.top() << endl;
	}

	//else something went wrong so do not display incorrect evaluation.
	else {
		cout << "The expression could not be evaluated." << endl;
	}
}

//function determines if there are sufficient
//conditions to perform an operation on the stack elts
void can_operate(stack<int> stk) {

	//make a copy of the stack
	stack<int> temp = stk;

	//if there are not enough elts to perform
	//operation throw exception
	if (temp.size() < 2) {
		Invalid_Postfix_Ex err;
		throw err;
	}
}