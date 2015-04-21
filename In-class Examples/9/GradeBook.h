
#include <string>
using namespace std;

class GradeBook
{
public:
   GradeBook(string name); // constructor initialize courseName
   void setCourseName(string name); // sets the course name
   string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message
private:
   string courseName; // course name for this GradeBook
};