#pragma once
class Budget {
private:
	int budid  = 0;
	double value = 0;
public:
	
	void setBud(double value);
	void setBudId(int bbb);
	int getBudId() const ;
	void increaseBud(double incr);
	double getBud() const;
	void readBud();
	void printBud() const;
};