#include <iostream>
#include <vector>


// ---- single responsibility principle (SRP)
class Book{}; // this class is responsible for storing information about a book
class Magazine{}; // this class is responsible for storing information about a magazine
class Printer{
    void print(const Book &b){};
    void print(const Magazine &m){};
}; // this class is responsible for printing
// every class should have only one responsibility
// ------------------------------------------- //

// ---- open-closed principle (OCP)
enum class Size{ SMALL, MEDIUM, LARGE };
enum class Color{ RED, GREEN, BLUE };
class Product{
public:
    Size size;
    Color color;
};

template <typename T> class AndSpecification;
template <typename T> class Specification{
public:   
    virtual bool is_satisfied(const T &item) const = 0;

    AndSpecification<T> operator&&(Specification<T> &&right)
    {
        return AndSpecification<T>(*this, right);
    }
};
template <typename T> class Filter{
public:
    virtual std::vector<T*> filter(std::vector<T*> items, const Specification<T> &spec) = 0;
};

class BetterFilter : public Filter<Product>{
public:
    std::vector<Product*> filter(std::vector<Product*> items, const Specification<Product> &spec) override
    {
        std::vector<Product*> result;
        for(const auto &item : items){
            if(spec.is_satisfied(*item)){
                result.push_back(item);
            }
        }
        return result;
    }
};


class ColorSpecification : public Specification<Product>{
public:
    Color mColor;

    explicit ColorSpecification(const Color &color) : mColor{color}{}

    virtual bool is_satisfied(const Product &item) const override{
        return item.color == mColor;
    }
};

class SizeSpecification : public Specification<Product>{
public:
    Size mSize;

    explicit SizeSpecification(const Size &size) : mSize{size}{}

    virtual bool is_satisfied(const Product &item) const override{
        return item.size == mSize;
    }
};

template <typename T> class AndSpecification : public Specification<T>{
public: 
    explicit AndSpecification( Specification<T> &left, Specification<T> &right) : mLeft{left}, mRight{right}{}
    virtual bool is_satisfied(const T &item) const override{
        return mLeft.is_satisfied(item) && mRight.is_satisfied(item);
    }
private:
    Specification<T>& mLeft;
    Specification<T>& mRight;
};

//usage
ColorSpecification red(Color::RED);
SizeSpecification large(Size::LARGE);

auto comboSpecs = ColorSpecification(Color::RED) && SizeSpecification(Size::LARGE);

std::vector<Product*> products;
BetterFilter bf;
std::vector<Product*> red_products = bf.filter(products, red);
std::vector<Product*> large_products = bf.filter(products, large);
std::vector<Product*> red_large_products = bf.filter(products, AndSpecification<Product>(red, large));
std::vector<Product*> red_k = bf.filter(products, comboSpecs);
// ------------------------------------------- //

// ---- Liskov substitution principle (LSP)
// Base class: Shape
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class: Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

// Function that uses the base class
void drawShape(Shape& shape) {
    shape.draw();
}

int main() {
    Circle circle;
    Rectangle rectangle;

    // LSP in action: We can pass derived class objects to a function that expects the base class
    drawShape(circle); // Output: Drawing a circle.
    drawShape(rectangle); // Output: Drawing a rectangle.

    return 0;
}
// ------------------------------------------- //

// ---- interface segregation principle (ISP)
// ---- dependency inversion principle (DIP)