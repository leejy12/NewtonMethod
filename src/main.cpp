#include "Newton.h"
#include <sstream>
#include <string>

int main()
{
    std::string strCoefficients;
    std::vector<double> vCoeffecients;
    std::stringstream ss;

    std::cout << "Enter coefficients of the polynomial: ";
    std::getline(std::cin, strCoefficients);
    ss << strCoefficients;
    double coeff;
    while (ss >> coeff)
        vCoeffecients.push_back(coeff);

    if (!ss.eof())
    {
        std::cout << "Invalid input.\n";
        return 1;
    }

    double start;
    std::cout << "Enter starting value: ";
    std::cin >> start;

    std::cout << "Solving " << f << "=0 using Newton's Method starting at x0 = " << start << '\n';
    const NewtonMethodResult result = NewtonMethod(f, start);

    if (result.success)
    {
        std::cout << "x = " << result.value() << '\n';
    }
    else
    {
        std::cout << result.reason() << '\n';
    }

    return 0;
}
