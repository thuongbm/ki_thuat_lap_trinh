#include <stdio.h>
#include <float.h>
main(){
	float a[10];
	for (int i=0;i<4;i++){
		scanf ("%f", &a[i]);
	}
	float max=-1e9;
	for (int i=0;i<4;i++){
		if (max<a[i]) max=a[i];
	}
	printf ("%.2f", max);
}
