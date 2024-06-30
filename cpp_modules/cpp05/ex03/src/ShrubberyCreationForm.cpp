#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145, 137), _target( target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src)
        this->_target = src._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    try
    {
        checkPermission(executor);
        std::ofstream file((_target + "_shrubbery").c_str());
        if (!file.is_open())
            throw ShrubberyCreationForm::FileOpenException();
        file << "                         /000\\000\\\n";
        file << "                     /00000 o,o 00000\\\n";
        file << "                 /0000000000000000000000\\\n";
        file << "            /0000000000000000000-0000000000\\\n";
        file << "          /000000000000000000000000000000000000|\n";
        file << "           |00000000000000-0000000000000 o-o 0\\\n";
        file << "         /000000000000000000000000000000000000000\\\n";
        file << "        /00000\\00000000000000--00000\\/000000000000|\n";
        file << "      /00\\  /00\\000000000000 0,0 0000/000000000000|\n";
        file << "     \\00000|0000000               0000000000000000\\\n";
        file << "      |00\\000000000000 MERRY XMAS    000000000000000000|\n";
        file << "     /0000000 o-o 00            0000 -,- 00000000000000/\n";
        file << "    /0000000000000--0000000000000000000000000000000000000\\\n";
        file << "     |000000000000000000000000000--00000000000000000000000|\n";
        file << "   /000 0000000000000000000000000000000--00000000000 0,0 0|\n";
        file << "  |0000000000000 o,O 00000000000000000000000000000000000000\\\n";
        file << "   |0000//00000000000000000000000000000000/\\000000000000000/\n";
        file << "  /0000000000---000000000000000000000000000000000000000000/\n";
        file << " /000000000/\\00000000000000000000000000000000\\000000000|\n";
        file << "|0000000000|0000000000000000000000000--00000000\\000000000\\\n";
        file << "  \\0000000/   \\00/\\0000000||\\ \\000/ \\000/  \\00000000000/\n";
        file << "                         //|\\\n";
        file << "                         /||\\\n";
        file << "                  /0     /||\\  0       /0\\\n";
        file << "          \\/||\\|\\//\\||||/|||\\\\|\\\\|/||//||\\|\n";
        file << "                       -/-/|-\\\n";
        file << "                    '_--/ ||--\\_\n";
        file << "                   -__/  |-|  -\\--__-    X,X\n";
        file << "                 _'--_-/|'_-\\-\\_'\n";
        file << "         X,X    ____-__/__-\\|'----_____'         0,0\n";
        file << "                       /    | .     \\.\n";
        file << "                    '__     _ .     /\n";
        file << "                   -__/  |-|  -\\--__-\n";
        file << "                  -__-_-/ |__-_-__-\n";
        file << "                 -__-_-/ /  |__-_-__-\n";
        file << "                -__-_-/ /   |__-_-__-\n";
        file.close();
    } catch (const AForm::GradeTooLowException & e) {
        std::cerr << "GradeTooLowException: " << e.what();
        throw;
    } catch (const AForm::FormNotSignedException & e) {
        std::cerr << "FormNotSignedException: " << e.what();
        throw;
    } catch (const AForm::FileOpenException & e) {
        std::cerr << "FileOpenException: " << e.what();
        throw;
    } catch (const std::exception & e) {
        std::cerr << e.what();
        throw;
    }
}
