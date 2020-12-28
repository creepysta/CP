#include<iostream>
#include<string.h>
using namespace std;

main()
{
	int i = 0, j, k, cnt = 0, count;
	//cout<<"Enter the number of characters in your sentence: ";
	//scanf("%d",&count);
	//char *c = (char *)malloc(sizeof(char)*count);
	char c[100];
	cout<<"Enter the sentence:\n";
	cin.get(c,100);
	for(i=0;i<strlen(c);i++) {
		if(c[i]>=65 && c[i]<=91) {
			c[i] += 32;
		}
	}
	i=0;
	while(c[i]!='\0') {
		if(c[i]==' ') {
			k=i+1;
			while(k<strlen(c)) {
				c[k-1] = c[k];
				k++;
			}
			cnt++;
		}
		i++;
	}
	i=0;
	j=strlen(c)-cnt-1;
	while(c[i]!='\0') {
		if(c[i++]!=c[j--]) {
			cout<<"Not Palindrome\n";
			break;
		}
		if(j==0) {
			cout<<"Palindrome\n";
			break;
		}
	}
}