#include "gameui.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <thread>
#include <chrono>

int mapxpos[312] =
{
	23,24,32,33,34,35,
	19,20,21,22,23,24,25,26,27,28,30,31,32,33,34,35,36,38,39,40,43,
	23,24,25,26,27,30,31,32,33,34,35,36,37,38,39,40,41,42,43,
	20,21,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
	23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
	23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
	26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
	24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
	26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
	28, 29, 30, 31, 32, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
	29, 30, 31, 32, 34, 35, 40, 41, 42, 43, 44, 45, 46, 47, 48,
	34, 35, 36, 37, 45, 46, 47, 48,
	31, 32, 33, 34, 35, 36, 37, 38, 39,
	30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	29, 30, 31, 32, 33, 34, 35, 38,
	31, 32, 33
};
int mapypos[312] =
{
	1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
	12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
	14, 14, 14, 14, 14, 14, 14, 14,
	15, 15, 15, 15, 15, 15, 15, 15, 15,
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
	17, 17, 17, 17, 17, 17, 17, 17,
	18, 18, 18
};

int houseroofxpos[331] =
{

	//house 1
	14,15,16,
	11,12,13,14,15,16,17,18,19,
	8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
	5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,
	4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
	3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
	2,3,5,6,7,10,11,14,17,18,20,22,23,25,26,28,

	//house 2
	41,42,
	37,38,39,40,41,42,43,44,45,
	36,37,38,39,40,41,42,43,44,45,46,47,48,
	33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
	32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,
	31,33,34,36,37,39,42,43,45,46,48,52,
	43,

	//house 3
	63,64,65,
	60,61,62,63,64,65,66,67,68,69,
	58,59,60,61,62,63,64,65,66,67,68,69,70,71,
	56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
	53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,
	52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,
	51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,
	51,53,56,57,60,63,65,66,69,71,73,74,78,
	60
};

int houseroofypos[331] =
{
	//house 1
	4,4,4,
	5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,

	//house 2
	4,4,
	5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,
	10,

	//house 3
	6,6,6,
	7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	13,13,13,13,13,13,13,13,13,13,13,13,13,
	14
};

int housexpos[156] =
{
	//house 1
	8,9,12,13,15,16,19,21,24,
	6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,   19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,   19,20,21,22,23,24,25,

	//house 2
	35,38,40,41,44,47,49,50,
	34,35,36,37,38,39,    44,45,46,47,48,49,50,
	34,35,36,37,38,39,    44,45,46,47,48,49,50,

	//house 3
	54,55,58,59,61,62,64,67,68,70,72,75,
	54,55,56,57,58,59,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,
	54,55,56,57,58,59,60,61,     68,69,70,71,72,73,74,75,
	54,55,56,57,58,59,60,61,     68,69,70,71,72,73,74,75
};

int houseypos[156] =
{
	//house 1
	10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	13,13,13,13,13,13,13,13,13,13,13,13,13,13,

	//house 2
	9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,

	//house 3
	13,13,13,13,13,13,13,13,13,13,13,13,
	14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16
};

int firexpos1[102]
{
	//house 1
	10,11,
	10,11,12,13,
	11,12,13,14,15,
	8,9,10,11,12,13,14,15,
	12,13,14,

	22,
	20,21,22,  25,26,
	20,21,22,23,24,25,
	20,21,22,23,24,25,
	23,24,
	24,

	//house 2
	39,
	40,41,
	37,38,39,40,41,
	38,42,43,44,45,46,

	//house 3
	67,
	66,67,
	63,64,65,66,
	62,63,64,65,66,67,68,  72,73,
	61,62,63,64,65,66,   71,72,
	64,65,66,69,70,71,72,3,74,75,76,
	64,65,66,67,68,69,
	65,66,67,    72


};
int fireypos1[102]
{
	//house 1
	3,3,
	4,4,4,4,
	5,5,5,5,5,
	6,6,6,6,6,6,6,6,
	7,7,7,

	3,
	4,4,4,4,4,
	5,5,5,5,5,5,
	6,6,6,6,6,6,
	7,7,
	9,

	//house 2
	3,
	4,4,
	5,5,5,5,5,
	6,6,6,6,6,6,

	//house 3
	4,
	5,5,
	6,6,6,6,
	7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,
	11,11,11,11
};

int firexpos2[309]
{
	//house 1
	16,
	15,16,
	12,13,14,15,
	6,  10,11,12,13,14,15,16,   22,
	6,7, 10,11,12,13,14,15,16,17,18,  20,21,22,  25,26,
	7,8,   11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,
	5,6,7,8,9,10,11,14,15,16,17,18,19,20,21,23,24,25,26,
	6,7,8,   17,18,19,   24,25,26,27,
	6,7,   15,

	//house 2
	44,
	42,43,44,
	39,40,41,42,43,44,
	37,38,39,40,41,42,43,44,45,  50,
	37,38,39,40,41,42,43,44,45,46,48,49,50,
	36,37,38,39,40,41,42,43,44,45,46,48,49,
	35,36,  40,  43,44,45,46,47,48,49,
	33,34,  37,38,39,40,  44,45,46,47,48,49,
	45,46,

	//house 3
	63,
	62,63,
	62,63,  67,  74,
	60,61,62,63,  66,67,  73,
	57,58,59,60,61,62,63,64,65,66,  73,74,
	56,57,58,59,60,61,62,63,64,65,66,67,68,  72,73,74,75,
	56,57,58,59,60,61,62,63,64,65,66,    71,72,73,74,75,
	57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
	58,59,60,61,62,63,64,65,66,67,68,69,71,72,73,74,75,76,
	58,59,60,61,62,63,64,65,66,67,68,  71,72,73,75,
	58,59,60,61,62,  72,73
};

int fireypos2[309]
{
	//house 1
	0,
	1,1,
	2,2,2,2,
	3,3,3,3,3,3,3,3,3,
	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,
	10,10,10,

	//house 2
	1,
	2,2,2,
	3,3,3,3,3,3,
	4,4,4,4,4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,

	//house 3
	2,
	3,3,
	4,4,4,4,
	5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12
};
int citybuildingxpos[481]
{
	58,59,60,
	58,59,60,
	8,7,9,10,29,30,31,32,33,58,59,60,
	8,7,9,10,11,12,27,29,28,30,31,32,33,58,59,60,
	8,7,9,10,11,12,27,29,28,30,31,32,33,35,34,36,37,55,56,57,58,59,60,
	8,7,9,10,11,12,13,25,26,27,29,28,30,31,32,33,35,34,36,38,46,47,48,55,56,57,58,59,60,61,62,
	3,4,8,7,9,10,11,12,13,25,26,27,29,28,30,31,32,33,35,34,36,39,46,47,48,55,56,57,58,59,60,61,62,
	2,3,4,5,6,8,7,9,10,11,12,13,14,24,25,26,27,29,28,30,31,32,35,34,36,37,38,40,39,45,46,47,48,55,56,57,58,59,60,61,62,63,64,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,24,25,23,26,27,29,28,30,31,32,35,34,36,40,46,47,48,55,56,57,58,59,60,61,62,63,64,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,19,21,20,22,24,25,23,26,27,29,28,35,34,36,40,46,47,48,55,56,57,58,59,60,61,62,63,64,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,19,21,20,22,24,25,23,26,27,29,28,31,32,33,35,34,36,37,38,40,39,42,43,44,45,46,47,48,55,56,57,58,59,60,61,62,63,64,70,71,72,73,74,76,75,77,78,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,19,21,20,22,24,25,23,26,27,29,28,31,32,33,35,34,36,40,42,43,44,46,47,48,55,56,57,58,59,60,61,62,63,64,73,74,76,75,77,78,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,19,21,20,22,24,25,23,26,27,29,28,31,32,33,35,34,36,40,41,42,46,47,48,55,56,57,58,59,60,61,62,63,64,67,73,74,76,75,77,78,
	1,2,3,4,5,6,8,7,9,10,11,12,13,14,19,21,20,22,24,25,23,26,27,29,28,31,32,33,35,34,36,37,38,40,39,41,42,43,44,45,46,47,48,55,56,57,58,59,60,61,62,63,64,67,68,69,70,71,72,73,74,76,75,77,78

};

int citybuildingypos[481]
{
	2, 2, 2,
	3, 3, 3,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
	12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
	13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
	14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
	15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15

};

int scene4firexpos[230] =
{
	6,62,
	5,6,59,60,61,62,
	3,4,5,6,7,57,58,59,60,61,
	3,4,5,6,8,7,30,57,58,59,60,
	3,4,5,6,8,7,9,30,31,32,57,58,59,60,
	3,4,5,6,8,7,9,10,31,32,51,57,58,59,60,
	3,4,5,6,8,7,9,10,29,28,30,31,32,50,51,
	4,5,6,7,29,28,30,31,32,33,34,50,51,53,52,
	21,20,22,26,27,29,28,30,31,32,33,35,34,36,43,44,45,46,47,48,49,50,51,53,52,77,
	18,17,19,21,20,22,24,23,26,27,29,28,30,31,32,33,35,34,36,43,44,45,46,47,48,49,50,51,52,77,78,
	18,17,19,21,20,22,24,25,23,26,27,29,28,30,31,32,33,34,46,47,48,49,50,51,52,71,76,77,78,
	18,17,19,21,20,22,24,25,23,26,45,46,47,48,49,50,51,52,72,76,75,77,78,
	21,20,22,24,25,23,26,27,45,46,47,76,75,77,78,
	18,19,21,20,22,24,25,23,26,41,42,
	3,18,19,20,34,72,
	61
};

int scene4fireypos[230] =
{
	3,3,
	4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
	14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
	16,16,16,16,16,16,16,16,16,16,16,
	17,17,17,17,17,17,
	18
};

gameui::gameui()
{
}
void gameui::gotoxy(int x, int y) {
	COORD srcn;
	HANDLE userhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	srcn.X = x; srcn.Y = y;
	SetConsoleCursorPosition(userhandle, srcn);
}
void gameui::color(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

void gameui::cutscene1()
{

	////////////////map 1////////////////////
	color(0x08);
	for (int i = 0; i < 26; i++)
	{
		if (i != 23 && (i < 12 || i > 16))
		{
			gotoxy(i + 16 + 20, 1);
			std::cout << char(219);
		}
	}
	for (int i = 0; i < 28; i++)
	{
		gotoxy(i + 15 + 20, 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 30; i++)
	{
		gotoxy(i + 14 + 20, 3);
		std::cout << char(219);
	}
	for (int i = 0; i < 32; i++)
	{
		gotoxy(i + 13 + 20, 4);
		std::cout << char(219);
	}
	for (int i = 0; i < 34; i++)
	{
		gotoxy(i + 12 + 20, 5);
		std::cout << char(219);
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(i + 51 + 20, 5);
		std::cout << char(219);
	}
	for (int i = 0; i < 42; i++)
	{
		gotoxy(i + 12 + 20, 6);
		std::cout << char(219);
	}
	for (int i = 0; i < 40; i++)
	{
		gotoxy(i + 13 + 20, 7);
		std::cout << char(219);
	}
	for (int i = 0; i < 38; i++)
	{
		if (i != 10 && i != 11)
		{
			gotoxy(i + 14 + 20, 8);
			std::cout << char(219);
		}
	}
	for (int i = 0; i < 22; i++)
	{
		gotoxy(i + 27 + 20, 9);
		std::cout << char(219);

		gotoxy(i + 26 + 20, 10);
		std::cout << char(219);
	}
	for (int i = 0; i < 21; i++)
	{
		gotoxy(i + 26 + 20, 11);
		std::cout << char(219);
		gotoxy(i + 27 + 20, 14);
		std::cout << char(219);
		gotoxy(i + 27 + 20, 15);
		std::cout << char(219);
	}
	for (int i = 0; i < 20; i++)
	{
		gotoxy(i + 27 + 20, 12);
		std::cout << char(219);
	}
	for (int i = 0; i < 19; i++)
	{
		gotoxy(i + 28 + 20, 13);
		std::cout << char(219);
		gotoxy(i + 28 + 20, 16);
		std::cout << char(219);
	}
	for (int i = 0; i < 17; i++)
	{
		gotoxy(i + 29 + 20, 17);
		std::cout << char(219);
	}
	for (int i = 0; i < 15; i++)
	{
		gotoxy(i + 30 + 20, 18);
		std::cout << char(219);
	}
	for (int i = 0; i < 13; i++)
	{
		gotoxy(i + 31 + 20, 19);
		std::cout << char(219);
	}
	for (int i = 0; i < 10; i++)
	{
		gotoxy(i + 33 + 20, 20);
		std::cout << char(219);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(i + 21 + 20, 16);
		std::cout << char(219);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(i + 21 + 20, 15);
		std::cout << char(219);
		gotoxy(i + 49 + 20, 18);
		std::cout << char(219);
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(i + 52 + 20, 15);
		std::cout << char(219);
		gotoxy(i + 51 + 20, 16);
		std::cout << char(219);
		gotoxy(i + 50 + 20, 17);
		std::cout << char(219);
	}
	gotoxy(55 + 20, 14);
	std::cout << char(219);

	////////////////map 2////////////////////
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("CLS");
	color(0x08);
	for (int i = 0; i < 16; i++)
	{
		gotoxy(43 + 20, i + 2);
		std::cout << char(219);
		gotoxy(44 + 20, i + 2);
		std::cout << char(219);
		gotoxy(45 + 20, i + 2);
		std::cout << char(219);
		gotoxy(46 + 20, i + 2);
		std::cout << char(219);
		gotoxy(47 + 20, i + 2);
		std::cout << char(219);
		gotoxy(48 + 20, i + 2);
		std::cout << char(219);
		gotoxy(49 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 14; i++)
	{
		gotoxy(42 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 13; i++)
	{
		gotoxy(41 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 12; i++)
	{
		if (i != 10)
		{
			gotoxy(40 + 20, i + 2);
			std::cout << char(219);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		gotoxy(39 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 8; i++)
	{
		if (i != 6 && i != 7)
		{
			gotoxy(38 + 20, i + 2);
			std::cout << char(219);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(37 + 20, i + 2);
		std::cout << char(219);
		gotoxy(36 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(35 + 20, i + 2);
		std::cout << char(219);
		gotoxy(31 + 20, i + 2);
		std::cout << char(219);
		gotoxy(30 + 20, i + 2);
		std::cout << char(219);
	}
	for (int i = 0; i < 2; i++)
	{
		gotoxy(34 + 20, i + 2);
		std::cout << char(219);
		gotoxy(33 + 20, i + 2);
		std::cout << char(219);
		gotoxy(29 + 20, i + 2);
		std::cout << char(219);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gotoxy(32 + 20 - j, i + 2);
			std::cout << char(219);
		}
	}
	gotoxy(28 + 20, 2);
	std::cout << char(219);
	for (int i = 0; i < 5; i++)
	{
		if (i != 1)
		{
			gotoxy(i + 30 + 20, 14);
			std::cout << char(219);
			gotoxy(i + 32 + 20, 16);
			std::cout << char(219);
		}
		gotoxy(i + 31 + 20, 15);
		std::cout << char(219);
	}
	gotoxy(33 + 20, 17);
	std::cout << char(219);

	////////////////map 3////////////////////
	std::this_thread::sleep_for(std::chrono::seconds(3));
	system("CLS");
	color(0x08);

	for (int i = 0; i < 312; i++)
	{
		gotoxy(mapxpos[i] + 20, mapypos[i]);
		std::cout << char(219);
	}
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::string lines[] = {
	 "It is 2001, the military of the Republic Of Altis has siezed power after a coup on the democratic government of the island nation",

	 "Led by Rikyar(Leader) Adriaan Helt, the new government has begin suppressing internal dissent and opposition through force",

	 "Their suppression of opposition has led to formation of rebel forces, leading to a protracted insurgency that has killed many ",

	 "One day, a suppression mission by government forces leads to a village in the island's interior being destroyed",

	 "Only one person survived, he was Johan Heisenburg. Angered, he has vowed to punish the government and intends to do so by fighting with a militia....."


	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	// Cutscene ends
	gotoxy(x, y);
	std::cout << "Press any key to start the game." << std::endl;
	_getch();

	// Game starts here
	std::cout << "Game is starting..." << std::endl;

}

void gameui::cutscene2()
{
	std::string lines2[] = {
		"Musiala: Good job commander! Your forces have routed government units from the area, allowing us to breathe freely after months of heavy fighting.",
		"However, there is another pressing issue we must tackle. One of our most important suppliers, Virgil 'the shopkeeper' van dijk, has been captured and imprisoned.",
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines2) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));

	//prison middle
	for (int i = 0; i < 14; i++)
	{
		for (int j = 18; j < 61; j++)
		{
			//check color for grey lines
			if (j == 24 || j == 30 || j == 36 || j == 42 || j == 48 || j == 54)
			{
				color(0x08);
			}
			else
			{
				color(0x04);
			}
			gotoxy(j + 20, 3 + i);
			std::cout << char(219);
		}
	}
	//prison sides
	for (int i = 0; i < 12; i++)
	{
		//left side
		for (int j = 5; j < 18; j++)
		{
			//check color for grey lines
			if (i == 0 || j == 17)
			{
				color(0x08);
			}
			else
			{
				color(0x04);
			}
			gotoxy(j + 20, 5 + i);
			std::cout << char(219);
		}
		//right side
		for (int j = 61; j < 74; j++)
		{
			//check color for grey lines
			if (i == 0 || j == 61)
			{
				color(0x08);
			}
			else
			{
				color(0x04);
			}
			gotoxy(j + 20, 5 + i);
			std::cout << char(219);
		}
	}
	for (int i = 0; i < 11; i++)
	{
		color(0x08);
		gotoxy(4 + 20, 6 + i);
		std::cout << char(219);
		gotoxy(74 + 20, 6 + i);
		std::cout << char(219);
	}

	//roof
	for (int i = 0; i < 41; i++)
	{
		gotoxy(i + 19 + 20, 2);
		color(0x08);
		std::cout << char(219);
	}
	for (int i = 0; i < 39; i++)
	{
		gotoxy(i + 20 + 20, 1);
		color(0x08);
		std::cout << char(219);
	}

	//connecter
	color(0x08);
	gotoxy(18 + 20, 3);
	std::cout << char(219);
	gotoxy(60 + 20, 3);
	std::cout << char(219);

	gotoxy(17 + 20, 4);
	std::cout << char(219);
	gotoxy(61 + 20, 4);
	std::cout << char(219);

	//door
	for (int i = 0; i < 13; i++)
	{
		for (int j = 13; j < 17; j++)
		{
			color(0x06);
			gotoxy(i + 33 + 20, j);
			std::cout << char(178);
		}
	}

	//windows
	//middle
	for (int i = 20; i < 58; i = i + 6)
	{
		for (int j = 4; j < 11; j = j + 3)
		{
			color(0x08);
			gotoxy(i + 20, j);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j);
			std::cout << char(176);
			gotoxy(i + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j + 1);
			std::cout << char(176);
		}
	}
	//sides
	for (int i = 7; i < 14; i = i + 6)
	{
		for (int j = 7; j < 14; j = j + 3)
		{
			color(0x08);
			gotoxy(i + 20, j);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j);
			std::cout << char(176);
			gotoxy(i + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j + 1);
			std::cout << char(176);
		}
	}
	for (int i = 63; i < 70; i = i + 6)
	{
		for (int j = 7; j < 14; j = j + 3)
		{
			color(0x08);
			gotoxy(i + 20, j);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j);
			std::cout << char(176);
			gotoxy(i + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 1 + 20, j + 1);
			std::cout << char(176);
			gotoxy(i + 2 + 20, j + 1);
			std::cout << char(176);
		}
	}
	//bottom left
	for (int i = 20; i < 27; i = i + 6)
	{
		color(0x08);
		gotoxy(i + 20, 13);
		std::cout << char(176);
		gotoxy(i + 1 + 20, 13);
		std::cout << char(176);
		gotoxy(i + 2 + 20, 13);
		std::cout << char(176);
		gotoxy(i + 20, 13 + 1);
		std::cout << char(176);
		gotoxy(i + 1 + 20, 13 + 1);
		std::cout << char(176);
		gotoxy(i + 2 + 20, 13 + 1);
		std::cout << char(176);
	}
	//bottom right
	for (int i = 50; i < 57; i = i + 6)
	{
		color(0x08);
		gotoxy(i + 20, 13);
		std::cout << char(176);
		gotoxy(i + 1 + 20, 13);
		std::cout << char(176);
		gotoxy(i + 2 + 20, 13);
		std::cout << char(176);
		gotoxy(i + 20, 13 + 1);
		std::cout << char(176);
		gotoxy(i + 1 + 20, 13 + 1);
		std::cout << char(176);
		gotoxy(i + 2 + 20, 13 + 1);
		std::cout << char(176);
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::string cutscene2line2[] = {
		"The Prison of Altis, one of the most fortified prisons in the world.",
		"Standing 180 feet tall, consisting of 1000 cell blocks, heavily guarded 24/7 with the best forces the Altis military has to offer.",
		"Infiltrating this prison won't be an easy task....",
		"Without Virgil, our forces will be unable to carry out attacks as per normal, thus you are tasked to lead a armed unit to destroy the prision and bring Virgil to us",
		"Good luck Johan, this mission is crucial to our cause!, without Virgil we will be unable to purchase and replinish our forces."
	};
	for (const auto& text : cutscene2line2) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

}

void gameui::cutscene3()
{


	std::string lines3[] = {
		"Musiala: Good Job commander! with Virgil free, we can continue to recieve shipments from our external supporters",
		"We have amassed enough forces to launch our own offensive, an attack on the city of Basre.",
		"I will our spymaster, Komani Lungu, brief you on the attack",
		"Komani: Wait....Johan?! Its you, i haven't seen you in so long!",
		"Johan: What?! Komani I didn't know you were part of this militia",
		"Komani: Well...i was gulity of doing nothing and supporting the government, so i decided to switch sides and help the militia",
		"Johan: its good that we friends have reunited to fight againist the government that wants us dead",
		"Komani: yes!,now back to my briefing. We have gathered enough armor units to support this offensive, use it well and don't waste them."
        "The shop is unlocked now!, after every mission you may proceed to it to replinish your armed unit."
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines3) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscene4() {

	for (int i = 0; i < 331; i++)
	{
		gotoxy(houseroofxpos[i] + 20, houseroofypos[i]);
		color(0x08);
		std::cout << char(178);
	}

	for (int i = 0; i < 156; i++)
	{
		gotoxy(housexpos[i] + 20, houseypos[i]);
		color(0x0E);
		std::cout << char(178);
	}

	std::string cutscene4line1[] = {
		"Enemies are still hiding in the villages!",
		"They think a fake village as a hideout would work.",
		"BURN THEM ALL!!!!!!"
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : cutscene4line1) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

	for (int i = 0; i < 102; i++)
	{
		gotoxy(firexpos1[i] + 20, fireypos1[i]);
		color(0x0C);
		std::cout << char(177);
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));

	for (int i = 0; i < 309; i++)
	{
		gotoxy(firexpos2[i] + 20, fireypos2[i]);
		color(0x0C);
		std::cout << char(177);
	}

	std::string line4[] = {
		".................",
		"i......what have we done?",
		"this battle, it was a nightmare......",
		"aren't we a liberating force? aiming to overthrow the oppresive state? We are the voice of the people, but are we the voice if we hurt them?",
		"heh.....maybe we have been too careless, firing our rounds and driving our tanks everywhere.",
		"But...the amount of citizens we injuned and killed accidentally is horrible",
		"Did I do the right thing?......to join this militia?",
		"................",
		"Musiala: Good afternoon Johan, our offensive onto Basre was successful, however at the cost of many innocent lives.",
		"But we cannot harp on this misfortunte, with the government driven from the area, our Militia can finally advance onto the Capital",
		"You will be tasked with entering and subduing all enemy forces outside the parliment buliding and ensuring that government forces will not push us back again",
		"good luck"

	};
	for (const auto& text : line4) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscene5() {

	//buildings
	for (int i = 0; i < 481; i++)
	{
		color(0x08);
		gotoxy(citybuildingxpos[i] + 20, citybuildingypos[i]);
		std::cout << char(219);
	}

	for (int i = 0; i < 79; i++)
	{
		if (i < 53 || i > 56)
		{
			color(0x07);
			gotoxy(i + 20, 16);
			std::cout << char(219);
		}
		if (i < 50 || i > 54)
		{
			color(0x0F);
			gotoxy(i + 20, 17);
			std::cout << char(219);
		}
		if (i < 47 || i > 50)
		{
			color(0x07);
			gotoxy(i + 20, 18);
			std::cout << char(219);
		}
	}
	//fire
	for (int i = 0; i < 230; i++)
	{
		color(0x0C);
		gotoxy(scene4firexpos[i] + 20, scene4fireypos[i]);
		std::cout << char(177);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::string line5[] = {
		"Gunfire is heard all over the wartorn city, with many bulidings damaged and destroyed.....",
		"With enemy forces routed and either destroyed or retreating back to the last government stronghold, the government parliment, the city is now liberates....",
		"Johan and his officers walk through the ruined city, looking upon the destruction caused",
		"As Johan walks, a medic runs to him...",
		"Sir! we have bad news, we have found the body of Komani Lungu, it looks to be that he was killed by government forces, most likely cause he was found out",
		"Johan: what?.....that can't be",
		"thats impossible.....no...no!"
		"It seems that in war, no one is immune from the scythe of death....."
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : line5) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));

	system("CLS");

	//main
	for (int i = 0; i < 74; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			color(0x0C);
			if (i == 0 || i == 73)
			{
				color(0x04);
			}
			gotoxy(i + 3 + 20, j + 6);
			std::cout << char(219);
		}
	}
	//dark roof line
	for (int i = 0; i < 72; i++)
	{
		color(0x06);
		gotoxy(i + 4 + 20, 5);
		std::cout << char(219);
	}
	for (int i = 0; i < 35; i++)
	{
		color(0x06);
		gotoxy(i + 22 + 20, 2);
		std::cout << char(219);
	}
	//light roof line
	for (int i = 0; i < 17; i++)
	{
		color(0x0E);
		gotoxy(i + 3 + 20, 6);
		std::cout << char(219);

		gotoxy(i + 60 + 20, 6);
		std::cout << char(219);
	}
	gotoxy(19 + 20, 5);
	std::cout << char(219);
	gotoxy(19 + 20, 4);
	std::cout << char(219);

	gotoxy(59 + 20, 6);
	std::cout << char(219);
	gotoxy(59 + 20, 5);
	std::cout << char(219);
	gotoxy(59 + 20, 4);
	std::cout << char(219);
	for (int i = 0; i < 39; i++)
	{
		gotoxy(i + 20 + 20, 3);
		std::cout << char(219);

		gotoxy(i + 20 + 20, 4);
		std::cout << char(219);
	}

	//emblem
	for (int i = 0; i < 6; i++)
	{
		color(0x08);
		gotoxy(i + 37 + 20, 3);
		std::cout << char(219);

		gotoxy(i + 37 + 20, 4);
		std::cout << char(219);

		gotoxy(i + 37 + 20, 5);
		std::cout << char(219);
	}
	for (int i = 0; i < 4; i++)
	{
		gotoxy(i + 38 + 20, 6);
		std::cout << char(219);
	}

	for (int i = 0; i < 2; i++)
	{
		color(0x06);
		gotoxy(i + 39 + 20, 4);
		std::cout << char(219);
		gotoxy(i + 39 + 20, 5);
		std::cout << char(219);
	}

	//pillars
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			color(0x04);
			gotoxy(i + 5 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 13 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 21 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 29 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 37 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 45 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 53 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 61 + 20, 8);
			std::cout << char(219);

			gotoxy(i + 69 + 20, 8);
			std::cout << char(219);

			if (i != 2 && i != 3)
			{
				gotoxy(i + 5 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 13 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 21 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 29 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 37 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 45 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 53 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 61 + 20, j + 8);
				std::cout << char(219);

				gotoxy(i + 69 + 20, j + 8);
				std::cout << char(219);
			}
		}
	}

	//flagpole
	for (int i = 0; i < 11; i++)
	{
		color(0x08);

		gotoxy(35 + 20, 8 + i);
		std::cout << char(219);

		gotoxy(43 + 20, 8 + i);
		std::cout << char(219);
	}

	//flag one
	for (int i = 0; i < 2; i++)
	{
		color(0x0D);
		gotoxy(32 + 20 + i, 8);
		std::cout << char(219);

		gotoxy(33 + 20 + i, 8);
		std::cout << char(219);

		gotoxy(31 + 20 + i, 9);
		std::cout << char(219);

		gotoxy(33 + 20 + i, 9);
		std::cout << char(219);

		gotoxy(31 + 20 + i, 10);
		std::cout << char(219);

	}

	//flag two
	for (int i = 0; i < 2; i++)
	{
		color(0x06);
		gotoxy(44 + 20 + i, 8);
		std::cout << char(219);

		gotoxy(45 + 20 + i, 8);
		std::cout << char(219);

		gotoxy(46 + 20 + i, 9);
		std::cout << char(219);

		color(0x09);
		gotoxy(44 + 20 + i, 9);
		std::cout << char(219);

		gotoxy(46 + 20 + i, 10);
		std::cout << char(219);

	}
	color(0x07);
	gotoxy(32 + 20, 9);
	std::cout << char(219);

	gotoxy(46 + 20, 9);
	std::cout << char(219);

	//foundation
	for (int i = 0; i < 76; i++)
	{
		color(0x08);
		gotoxy(i + 2 + 20, 19);
		std::cout << char(219);
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::string cutscene5line2[] = {
		"!?!?!?!?!!??",
		"Somehow in the middle of the a full blown war, not a single part of the parliment is damaged....",
		"Musiala: Commander! Our forces have routed the enemy, and their remaining forces are entrenched at the parliment buliding",
		"We have intel that Adriaan Helt remains there commanding",
	};

	for (const auto& text : cutscene5line2) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("CLS");

	std::string cutscene5line3[] = 
	{
	"Johan went into the parliment clearing all the military officials one by one... until one remains...."
	};

	for (const auto& text : cutscene5line3) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscence6()
{
	std::string line6[] = {
		"your forces stormed the parliment, successfully defeating the remmmants of the goverment forces",
		"The Rikyar, the main cause of this war, has been captured. He stares at your with a angered look, but stays silent",
		"With the parliment captured, you have forced the Rikyar to surrender his forces",
		"Rikyar: Urgh....fine",
		"The war had ended, while some forces may still resist, the period of oppression has ended...",
		"it seems, that liberty have finally come to Altis...."
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : line6) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}



void gameui::stats()
{
	std::cout << "Below are the stats of the units\n";
	std::cout << "from left to right, unit name, HP, attack, range, size, cost\n";

	getstats("Rifleman", 10, 5, 3, 1, 5);

	getstats("Machine Gunner", 10, 15, 3, 1, 7);

	getstats("Grenadier", 10, 20, 4, 1, 6);

	getstats("Mortar", 20, 20, 7, 1, 8);

	getstats("Artillery", 30, 40, 10, 4, 15);

	getstats("IFV", 60, 10, 5, 4, 10);

	getstats("Tank", 80, 30, 8, 9, 15);
}

void gameui::win()
{
	std::string liness1[] = {
		"You have defeated the enemy",
		"good job!"
	};



	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness1) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::loss()
{
	std::string liness2[] = {
		"The enemy has routed our forces",
		"terrible loss for us, we must regroup and strike back!",
		"try again......."
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness2) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

}

void gameui::gamestart(gameui& player)
{
	

}

void gameui::getstats(std::string nameset, int H, int a, int r, int s, int c)
{
	if (unitcount < 7) {
		unitname[unitcount] = nameset;
		HP[unitcount] = H;
		attack[unitcount] = a;
		range[unitcount] = r;
		size[unitcount] = s;
		cost[unitcount] = c;
		std::cout
			<< unitname[unitcount] << ": "
			<< HP[unitcount] << ", "
			<< attack[unitcount] << ", "
			<< range[unitcount] << ", "
			<< size[unitcount] << ", "
			<< cost[unitcount] << "\n";
	}

	unitcount++;
}

void gameui::turtorial() {
	std::string liness[] = {
	 "You are Johan Heisenburg, your villiage was destroyed by government forces a few weeks ago, you have joined the New Boers, a militia fighting the government",
	 "you are in the jungle headquarters of the rebels, you are meeting your newly assigned commander, Major Jamal Musiala, to begin your training: ",
	 "Musiala: Welcome Johan, I am your commander and will be overseeing your training.",
	 "I heard you are a hunter, and that your father was a commander in the Altian Military, thus you will become a captain in our militia",
	 "To command your troops, use the WASD keys to move up, left, down, right.",
	 "To attack enemies, command your troops by pressing the J button to attack",
	 "That is all, good luck commander!"
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	
}

void gameui::printdelay(const std::string& text, int delay)
{
	for (char e :text) {
		if (_kbhit()) {
			_getch();
			break;
		}
		std::cout << e;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	std::cout << std::endl;
 
}
