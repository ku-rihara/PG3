#include <stdio.h>
#include<memory>
/// class 
#include"Number.h"

int main() {
    std::unique_ptr<Number<int, int>> numI = std::make_unique<Number<int, int>>();
    std::unique_ptr<Number<float, float>> numF = std::make_unique<Number<float, float>>();
    std::unique_ptr<Number<double, double>> numD = std::make_unique<Number<double, double>>();
    std::unique_ptr<Number<int, float>> numIF = std::make_unique<Number<int, float>>();
    std::unique_ptr<Number<int, double>> numID = std::make_unique<Number<int, double>>();
    std::unique_ptr<Number<float, double>> numFD = std::make_unique<Number<float, double>>();


    printf("int同士:%d\n", numI->Min(5,3));
    printf("float同士:%2.1f\n", numF->Min(5.5f, 3.5f));
    printf("double同士:%2.1lf\n", numD->Min(5.6, 3.9));
    printf("intとfloat:%d\n", numIF->Min(5, 3.8f));
    printf("intとdouble:%d\n", numID->Min(5, 4.0));
    printf("floatとdouble:%2.1f\n", numFD->Min(5.5f, 3.5));

    return 0;
}
