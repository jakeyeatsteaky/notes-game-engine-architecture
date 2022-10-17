#include "polymorphism.hpp"

Polymorphism::Polymorphism()
{
    std::cout << "Polymorphism Example:\n\n";
    runPolymorphismExample();
}

Polymorphism::~Polymorphism()
{

}

void Polymorphism::drawShapesWithoutPolymorphism(std::list<Shape *>& shapes)
{
    std::list<Shape*>::iterator pShapeBegin = shapes.begin();
    std::list<Shape*>::iterator pEnd = shapes.end();

    // The Switch case is a useful way for changing behavior based on the type created.  However, this requires the program to "know" of all the possible types.
    // The polymorphic example allows the programmer to easily create more types, with different behavior by using the virtual Draw function rather than making 
    // a new switch case.
    
    std::cout << "\tDrawing Shapes using switch case:\n";
    for( ; pShapeBegin != pEnd; pShapeBegin++)
    {
        switch((*pShapeBegin)->m_type)
        {
            case e_Circle:
                std::cout << "\t\tdrawing a Circle" << std::endl;
                break;
            
            case e_Square:
                std::cout << "\t\tdrawing a Square" << std::endl;
                break;
            
            case e_Rectangle:
                std::cout << "\t\tdrawing a Rectangle" << std::endl;
                break;

        }
    }
}

void Polymorphism::drawPolyShapes(std::list<PolyShape*>& polyShapes)
{
    std::cout << "\n\tDrawing shapes using polymorphism:\n";

    std::list<PolyShape*>::iterator pShapeBegin = polyShapes.begin();
    std::list<PolyShape*>::iterator pEnd = polyShapes.end();

    for( ; pShapeBegin != pEnd; pShapeBegin++)
    {
        (*pShapeBegin)->Draw();
    }
}

void Polymorphism::runPolymorphismExample()
{
    Shape* circle = new Shape(e_Circle);
    Shape* square = new Shape(e_Square);
    Shape* rectangle = new Shape(e_Rectangle);
    std::list<Shape *> shapeList = {circle, rectangle, square, square, rectangle};

    Circle* poly_circle = new Circle();
    Square* poly_square = new Square();
    Rectangle* poly_rectangle = new Rectangle();
    std::list<PolyShape *> polyShapeList = {poly_circle, poly_square, poly_circle, poly_rectangle};

    drawShapesWithoutPolymorphism(shapeList);
    drawPolyShapes(polyShapeList);

}
