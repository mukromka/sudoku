#include<string>
using namespace std;
class Board
{
private:
	string temp;
	string arena[9][9];
public:
	void drawArena();
	void importArena();
	void randomizeArena();
};
