#include <iostream>
#include <list>

/*------------------------------------------------------------------------
    This example shows the difference between using a switch statement 
    to handle different behavior across different objects versus using
    polymorphism to simplify this problem.

    Polymorphism also offers the benefit of the function not needing 
    to "know" what the object is in order for it to be added to this
    family of objects.
------------------------------------------------------------------------*/

enum Type{e_Circle, e_Square, e_Rectangle};

struct Shape
{
    Shape(){};
    Shape(Type type){m_type = type;};
    Type m_type;
    ~Shape(){};
};

struct PolyShape
{
    virtual void Draw() = 0; // pure virtual function
    virtual ~PolyShape(){};      // ensure derivec dtors are virtual
};

class Polymorphism
{
    public:
        Polymorphism();
        ~Polymorphism();
        void drawShapesWithoutPolymorphism(std::list<Shape *>& shape);
        void drawPolyShapes(std::list<PolyShape *>& polyShape);
        void runPolymorphismExample();
    
};

struct Circle :  public PolyShape
{
    virtual void Draw()
    {
        std::cout << "\t\tdrawing a Circle from a virtual function - Polymorphism is COOL!\n";
    }
};

struct Square :  public PolyShape
{
    virtual void Draw()
    {
        std::cout << "\t\tdrawing a Square from a virtual function - Polymorphism is COOL!\n";
    }
};

struct Rectangle :  public PolyShape
{
    virtual void Draw()
    {
        std::cout << "\t\tdrawing a Rectangle from a virtual function - Polymorphism is COOL!\n";
    }
};