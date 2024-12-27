// ---- single responsibility principle (SRP)
class book{}; // this class is responsible for storing information about a book
class magazine{}; // this class is responsible for storing information about a magazine
class printer{
    void print(const book &b){};
    void print(const magazine &m){};
}; // this class is responsible for printing
// every class should have only one responsibility

// ---- open-closed principle (OCP)
// ---- Liskov substitution principle (LSP)
// ---- interface segregation principle (ISP)
// ---- dependency inversion principle (DIP)