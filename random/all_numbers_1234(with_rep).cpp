#include<iostream>
using namespace std;

void all_numbers_1234()
{
	int num[4] = {1,1,1,1}, count = 1;
	//printf("%d%d%d%d\n",num[0],num[1],num[2],num[3]);
	do{
		printf("%d%d%d%d\n",num[0],num[1],num[2],num[3]);
		num[3] = num[3] + 1;
		if(num[3] == 5) {
			num[3] = 1;
			num[2] = num[2] + 1;
			if(num[2] == 5) {
				num[2] = 1;
				num[1] = num[1] + 1;
			}
			if(num[1] == 5) {
				num[1] = 1;
				num[0] = num[0] + 1;
			}
		}
		else if(num[2] == 5) {
			num[2] = 1;
			num[1] = num[1] + 1;
			if(num[1] == 4) {
				num[1] = 1;
				num[0] = num[0] + 1;
			}
		}
		else if(num[1] == 5) {
			num[1] = 1;
			num[0] = num[0] + 1;
		}
		//continue;
		//count++;
	}while(num[0] <= 4);
	//printf("%d",count);
}

main()
{
	all_numbers_1234();
}