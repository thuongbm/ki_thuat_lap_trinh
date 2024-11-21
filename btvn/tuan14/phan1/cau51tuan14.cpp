#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void detached(char *s, char **w, int *k){
	int c=strlen(s);
	*k=0;
	char *token=strtok(s, " ");
	while (token!=NULL){
		w[*k]=(char*) malloc ((strlen(token)*1)*sizeof(char));
		strcpy(w[*k], token);
		(*k)++;
		token=strtok(NULL, " ");
	}
}
char *longest(char **w, int k){
	char *d;
	d=(char*) malloc (100*sizeof(char));
	strcpy(d,"");
	for (int i=0;i<k;i++){
		if (strlen(w[i])>strlen(d)){
			strcpy(d,w[i]);
		}
	}
	return d;
}
char *noiduoi(char **w, int k) {
    int total_length = 0;
    for (int i = 0; i < k; i++) {
        total_length += strlen(w[i]);
    }

    char *result = (char*)malloc((total_length + k) * sizeof(char)); 
    result[0] = '\0'; 
    strcat(result, w[0]); 
    for (int i = 1; i < k; i++) {
        strcat(result, " "); 
        strcat(result, w[i]); 
    }
    return result;
}
void replace(char **w, int k, char x){
	for (int i=0;i<k;i++){
		if (strchr(w[i], x)!=NULL){
			strcpy(w[i], "hello world");
		}
	}
}
int *findandcount(char *s1){
	int *cnt;
	cnt=(int*) malloc(256*sizeof(int)); 
	int len=strlen(s1);
	for (int i=0;i<len;i++){
		cnt[s1[i]]++;
	}
	return cnt;
}
int cmp(const void*a, const void*b){
	char *x=(char*)a;
	char *y=(char*)b;
	if (strcmp(x,y)<0) return -1;
	else return 1;
}
main(){
	char *s;
	s=(char*) malloc(100*sizeof(char));
	gets(s);
	char **w;
	w=(char**) malloc(100*sizeof(char*));
	for (int i=0;i<100;i++){
		*w=(char*) malloc(100*sizeof(char));
	}
	int k;
	
	detached(s,w,&k);
	printf ("cac tu trong chuoi la: ");
	for (int i=0;i<k;i++){
		printf ("\n%s ", w[i]);
	}
	printf ("\n");
	char *lgs;
	lgs=longest(w,k);
	printf ("chuoi dai nhat la: %s", lgs);
	char *s1=noiduoi(w,k);
	printf ("\nchuoi sau khi dao nguoc la: %s", strrev(s1));
	printf ("\nnhap ky tu can so sanh: ");
	char x;
	scanf ("%c", &x);
	printf ("\ntan suat xuat hien cua cac ky thu la: ");
	int *cnt=findandcount(s1);
	for (int i=0;i<256;i++){
		if (cnt[i]>0){
			printf ("\n%c: %d", i, cnt[i]);
		}
	}
	char **q;
	q=(char**) malloc(100*sizeof(char*));
	detached(s1,w,&k);
	qsort(w,k,sizeof(w[0]),cmp);
	printf ("\nchuoi sau khi duoc sap xep theo tu dien la: \n");
	for (int i=0;i<k;i++){
		printf ("%s ", w[i]);
	}
	free(s);
	free(s1);
	free(w);
	free(q);
}
