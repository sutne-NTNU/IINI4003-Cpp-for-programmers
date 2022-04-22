#include<iostream>

using namespace std;

template<class DataType>
class RGB {
private:
    /**
     * limit RGB value based on the datatype. max int=255, max double=1.0.
     */
    DataType limit(DataType value) {
        if (value < 0) return 0;
        if (is_same<DataType, int>()) {
            return min((int) value, 255);
        } else if (is_same<DataType, double>()) {
            return min((double) value, 1.0);
        }
    }

public:
    DataType red;
    DataType green;
    DataType blue;

    RGB(DataType red, DataType green, DataType blue) : red(limit(red)),
                                                       green(limit(green)),
                                                       blue(limit(blue)) {}

    explicit RGB(DataType value) : RGB(value, value, value) {}

    friend ostream &operator<<(ostream &ostream, const RGB<DataType> &rgb) {
        return ostream << "(" << rgb.red << ", " << rgb.green << ", " << rgb.blue << ")";
    }

    template<class DataType2>
    RGB<DataType> operator+(const RGB<DataType2> &other) {
        return RGB<DataType>(limit(red + other.red),
                             limit(green + other.green),
                             limit(blue + other.blue));
    }

    template<class DataType2>
    RGB<DataType> operator+(const DataType2 &value) {
        return RGB<DataType>(limit(red + value),
                             limit(green + value),
                             limit(blue + value));
    }
};


int main() {
    {
        RGB<double> rgb(0.5);
        std::cout << rgb << std::endl;
        std::cout << rgb + 0.3 << std::endl;
        std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
    }
    {
        RGB<int> rgb(130);
        std::cout << rgb << std::endl;
        std::cout << rgb + 60 << std::endl;
        std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
    }
};