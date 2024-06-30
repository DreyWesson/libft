#include "./inc/Form.hpp"
#include "./inc/Bureaucrat.hpp"

void testBureaucratConstructor() {
    try {
        Bureaucrat validBureaucrat("John", 50);
        std::cout << validBureaucrat << std::endl;

        // Bureaucrat invalidHighGrade("InvalidHigh", 0);

    //     Bureaucrat invalidLowGrade("InvalidLow", 160);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testBureaucratIncrementDecrement() {
    try {
        Bureaucrat validBureaucrat("John", 50);
        std::cout << validBureaucrat << std::endl;

        validBureaucrat.increment();
        std::cout << validBureaucrat << std::endl;

        validBureaucrat.decrement();
        std::cout << validBureaucrat << std::endl;

        // validBureaucrat.increment();

        // validBureaucrat.decrement();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testFormConstructor() {
    try {
        Form validForm("Application Form", 75, 50);
        std::cout << validForm << std::endl;

        // Form invalidSignGrade("InvalidSignGrade", 160, 50);

        // Form invalidSignGrade("InvalidSignGrade", 75, 0);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testFormSigning() {
    try {
        // Test signing and printing Form status
        Bureaucrat validBureaucrat("John", 50);
        Form validForm("Application Form", 75, 50);
        std::cout << validForm << std::endl;

        validForm.beSigned(validBureaucrat);
        std::cout << validForm << std::endl;

        // Uncomment the line below to test GradeTooLowException for signing
        // validForm.beSigned(validBureaucrat);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testBureaucratSignForm() {
    try {
        // Test Bureaucrat signForm function
        Bureaucrat bureaucratToSign("Signer", 80);
        Form validForm("Application Form", 75, 50);
        std::cout << validForm << std::endl;

        bureaucratToSign.signForm(validForm);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testBureaucratConstructor();
    testBureaucratIncrementDecrement();
    testFormConstructor();
    testFormSigning();
    testBureaucratSignForm();

    return 0;
}
