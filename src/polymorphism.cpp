#include "polymorphism.hpp"

Polymorphism::Polymorphism()
{
      runPolymorphismExample();
}

Polymorphism::~Polymorphism()
{

}

void Polymorphism::drawShapes(std::list<Shape *>& shapes)
{
    std::list<Shape*>::iterator pShapeBegin = shapes.begin();
    std::list<Shape*>::iterator pEnd = shapes.end();
    
    std::cout << "Drawing Shapes using switch case:\n";
    for( ; pShapeBegin != pEnd; pShapeBegin++)
    {
        switch((*pShapeBegin)->m_type)
        {
            case e_Circle:
                std::cout << "\tdrawing a Circle" << std::endl;
                break;
            
            case e_Square:
                std::cout << "\tdrawing a Square" << std::endl;
                break;
            
            case e_Rectangle:
                std::cout << "\tdrawing a Rectangle" << std::endl;
                break;

        }
    }
}

void Polymorphism::drawPolyShapes(std::list<PolyShape*>& polyShapes)
{
    std::cout << "\nDrawing shapes using polymorphism:\n";

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

    drawShapes(shapeList);
    drawPolyShapes(polyShapeList);

}
