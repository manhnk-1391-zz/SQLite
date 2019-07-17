#include<vector>

struct date
{
    int month;
    int year;
};

class Info
{
private:
    int ID;
    char* firstName;
    char* lastName;
    char* sex;
    int yearOfBirth;
    char* position;
    date dateJoin;

    bool conditionDate(int month, int year){
        if(month < 1 || month > 12) return false;
        if(year < 2010 || year > 2019) return false;
        return true;
    }

public:
    void setID(int id){ this->ID = id;}
    int getID(){return this->ID;}

    void setName(char* first, char* last){ this->firstName = first; this->lastName = last;}
    char* getFirstName(){ return this->firstName;}
    char* getLastName(){ return this->lastName;}

    void setSex(char* sex_){ this->sex = sex_;}
    char* getSex(){ return this->sex;}

    void setYearOfBirth(int year){ this->yearOfBirth = year;}
    int getYearOfBirth(){return this->yearOfBirth;}

    void setPosition(char* position_){ this->position = position_;}
    char* getPosition(){return this->position;}

    bool setDateJoin(int month, int year){ 
        if(!conditionDate(month, year))
            return false;
        this->dateJoin.month = month, this->dateJoin.year = year;
        return true;
    }
    date getDateJoin(){return this->dateJoin;}
};

class Salary{
private:
    int ID;
    char* firstName;
    char* lastName;
    char* level;
    float rank;
    int salary;
    int seniority;

public:
    void setID(int id){ this->ID = id;}
    int getID(){ return this->ID;}

    void setName(char* first, char* last){ this->firstName = first; this->lastName = last;}
    char* getFirstName(){ return this->firstName;}
    char* getLastName(){ return this->lastName;}

    void setLever(char* lever_){ this->level = lever_;}
    char* getLever(){ return this->level;}

    void setRank(float rank){this->rank = rank;}
    float getRank(){ return this->rank; }

    void setSalary(int salary_){this->salary = salary_;}
    int getSalary(){ return this->salary; }

    void setSeniorty(int seniorty_){this->seniority = seniorty_;}
    int getSeniorty(){return this->seniority;}
};

class Lead{
private:
    int ID;
    char* projectName;
    std::vector<char*> member;
    char* roomName;
    char* managerName;
    char* customer;

public:
    void setID(int id){ this->ID = id;}
    int getID(){return this->ID;}

    void setMember(std::vector<char*> member_){ this->member = member_;}
    std::vector<char*> getMember(){return this->member;}

    void setRoomName(char* roomName_ ){ this->roomName = roomName_;}
    char* getRoomName(){ return this->roomName;}

    void setCustomer(char* customer_){ this->customer = customer_;}
    char* getCustomer(){return this->customer;}

    void setManagerName(char* managerName_){ this->managerName = managerName_;}
    char* geManagerName(){return this->managerName;}
};

class Normal{
private:
    int ID;
    char* projectName;
    char* dev;
    char* roomName;
    char* managerName;

public:
    void setID(int id){ this->ID = id;}
    int getID(){return this->ID;}

    void setProjectName(char* projectName_){this->projectName = projectName_;}
    char* getProjectName(){return this->projectName;}

    void setDev( char* dev_){ this->dev = dev_;}
    char* getDev(){return this->dev;}

    void setRoomName(char* roomName_ ){ this->roomName = roomName_;}
    char* getRoomName(){ return this->roomName;}

    void setManagerName(char* managerName_){ this->managerName = managerName_;}
    char* geManagerName(){return this->managerName;}
};

class Manager{
private:
    int ID;
    int countEmployee;
    int countProject;
    char* nameRoom;
    
public:
    void setID(int id){ this->ID = id;}
    int getID(){return this->ID;}

    void setCountEmployee(int countEmployee_){this->countEmployee = countEmployee_;}
    int getCountEmployee(){return this->countEmployee;}

    void setCountProject(int countProject_){ this->countProject = countProject_;}
    int getCountProject(){return this->countProject;}

    void setRoomName(char* roomName_ ){ this->roomName = roomName_;}
    char* getRoomName(){ return this->roomName;}
};

class Employee{
    Info info;
    Salary Salary;
    enum position{
        normal = 0,
        lead,
        manager
    };
}