#pragma once
class Backpack
{
private:
	//[0] = riflesman
	//[1] = machinegunner
	//[2] = grenadier
	//[3] = motars
	//[4] = artillery
	//[5] = tank
	//[6] = IFV
	int Troops[7];

public:
	Backpack();

	//riflesman
	void riflemansetter(int a);
	int riflemangetter();

	//machinegunners
	void machinegunnersetter(int a);
	int machinegunnergetter();

	//grenadiers
	void grenadiersetter(int a);
	int grenadiergetter();

	//Motars
	void motarsetter(int a);
	int motargetter();

	//artillery
	void artillerysetter(int a);
	int artillerygetter();

	//tank
	void tanksetter(int a);
	int tankgetter();

	//IFV
	void IFVsetter(int a);
	int IFVgetter();
};

