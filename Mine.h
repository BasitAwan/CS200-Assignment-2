class Mine
{
private:
	bool **location;
	bool **maze;
	int size;

public:
	Mine();
	Mine(int x);
	Mine(bool **input , int x);
	void printmine();
	int can_solve(struct Miner &a,struct Miner b, struct mine_index &lo,struct mine_index start, struct mine_index y);

};


struct Miner
{
	bool up;
	bool down; 
	bool left;
	bool right;
};

struct mine_index
{
	int row,col;
};
