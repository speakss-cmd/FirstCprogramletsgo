#include <iostream>
//rewriting(refactor) to use bool, function based design

//first we separate logic from user interaction

void calcAndprint(double sales) { 
    //void functions print results instead of returning them

    const double state_tax = 0.04; //use const for static values
    const double county_tax = 0.02;
        
    double sales_after_stax = sales * state_tax;
    double sales_after_ctax = sales * county_tax;
    double total = sales - sales_after_stax - sales_after_ctax;

    //this is better design using void calcAndprint bc
    // it separates logic from user interaction
    // cleaner to read and clear naming
    // variables are scoped tightly
    std::cout << "Sales: $" << sales << "\n";
    std::cout << "state tax: $" << sales_after_stax << "\n";
    std::cout << "county tax: $" << sales_after_ctax << "\n";
    std::cout << "Total earned: $" << total << "\n";
    std::cout << "Taxed amount: $" << sales_after_stax + sales_after_ctax << "\n";
}
int main(){

    double sales = 0.0;
    bool choice = true; // we use bool not INT.

    //ask user for sales total and then find taxed amount continuously using while loop
    while (choice) {
        std:: cout << "Enter your total sales amount: ";
        std:: cin >> sales;


        calcAndprint(sales); //here we call the function
        

        std::cout << "Continue? Y = 1 N = 0 \n";
        std:: cin >> choice; //will auto cancel loop if 0
               
    }
     std::cout << "Program exited. Goodbye!\n";
    return 0;
}
