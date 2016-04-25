#ifndef TARGET_H
#define TARGET_H
#include <iostream>
#include <string>

class Target {
private:
	char* tTime; 
	int height;
    int width;
	std::string sector;
	bool tFound;

public:
	//constructor
	Target();


	//getters
	char * getTime() const{return tTime;}
	int getHeight()const{return height;}
    int getWidth()const{return width;}
    //std::string getPlanePos()const {return sector;}
	bool getFound()const{return tFound;}

	//setters
    //void setPlanePos(std::string sector);
	void setTime(char * n){tTime = n;}
	void setHeight(int n){height = n;}
    void setWidth(int n){width = n;}
	void setFound(bool a){tFound = a;}
	std::string str() const;
};
#endif