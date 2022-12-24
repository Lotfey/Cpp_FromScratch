#include<iostream>
#include<string>

class shape
{
private:
	std::string shapeName = "shape";
public:
	shape() = delete;
	shape(std::string& name) :shapeName(name) {}


	
	// Since we know that every shape must in=mplement it own draw
	// method, the base class implement drawShape as pure virtual function
	virtual std::string const getClassName() = 0;
	virtual void drawShape() = 0;

	//~shape()=default;
};

class square : public shape
{
public:
	square()=delete;
	square(std::string name) :shape(name) {};

	// here implement the pure virtual fuction custumised for the square class
	std::string const getClassName()
	{
		return "Square";
	}

	void drawShape()
	{
		std::cout << "Draw " << getClassName() << std::endl;
	}

	~square() = default;
};

int main()
{

	square S1("NiceSquare");
	std::cout << "Class name: " << S1.getClassName() << std::endl;
	S1.drawShape();

	return 0;
}
