#include <iostream>
//rewriting(refactor) to use bool, function based design
int main(){

    double sales;
    double state_tax = 0.04;
    double county_tax = 0.02;
    
    int choice = 1;
    //ask user for sales total and then find taxed amount continuously using while loop
    while (choice) {
        std:: cout << "Enter your total sales amount: ";
        std:: cin >> sales;


        
        double sales_after_stax = sales * state_tax;
        double sales_after_ctax = sales * county_tax;
        double total = sales - sales_after_stax - sales_after_ctax;

        

        std::cout << "Sales: $" << sales << "\n";
        std::cout << "state tax: $" << sales_after_stax << "\n";
        std::cout << "county tax: $" << sales_after_ctax << "\n";
        std::cout << "Total earned: $" << total << "\n";
        std::cout << "Taxed amount: $" << sales_after_stax + sales_after_ctax << "\n";
        std::cout << "Continue? Y = 1 N = 0 \n";
        std:: cin >> choice;
               
    }
     std::cout << "Program exited. Goodbye!\n";
    return 0;
}