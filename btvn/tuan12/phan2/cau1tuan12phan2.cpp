#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void tachchuoi(char *a, char **w, int *k){
	int c=strlen(a);
	*k=0;
	char *token=strtok(a, " ");
	while (token != NULL){
		w[*k] = (char*)malloc((strlen(token) + 1) * sizeof(char));
        strcpy(w[*k], token);
        (*k)++;
        token = strtok(NULL, " ");
    }
}
/*char *dainhat(char *a){
	char *d = (char*)malloc(100 * sizeof(char));
    strcpy(d, "");
	char *token=strtok(a, " ");
	while (token!=NULL){
		if (strlen(token)>strlen(d)){
			strcpy(d,token);
		}
		token = strtok(NULL, " ");
	}
	return d;
}*/
char *dainhat(char **w, int k){
	char *d = (char*)malloc(100 * sizeof(char));
    strcpy(d, "");
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
void thaythe(char **w, int k, char x){
	for (int i=0;i<k;i++){
		if (strchr(w[i],x)!=NULL){
			strcpy(w[i],"new world");
		}
	}
}
void timvademkt(char *s1){
	int cnt[256]={0};
	int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        cnt[s1[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (cnt[i] > 0) {
            printf("\n%c: %d ", i, cnt[i]);
        }
    }
}
int cmp(const void*a, const void*b){
	char *x=(char*)a;
	char *y=(char*)b;
	if (strcmp(x,y)<0) return -1;
	else return 1;
}
main(){
	char *a;
	a=(char*) malloc(100*sizeof(char));
	printf ("nhap chuoi: ");
	gets (a);
	char **w;
	w=(char**) malloc(100*sizeof(char*));
	for (int i = 0; i < 100; i++) {
        w[i] = (char*)malloc(100 * sizeof(char));
    }
    int k;
    tachchuoi(a, w, &k);
    printf("Cac tu trong chuoi:\n");
    for (int i = 0; i < k; i++) {
        printf("%s\n", w[i]);
	}
	char *lonnhat = dainhat(w,k);
	char *s1=noiduoi(w,k);
    printf("Tu dai nhat: %s\n", lonnhat);
    printf ("\nchuoi sau khi dao nguoc la: %s", strrev(s1));
    s1=noiduoi(w,k);
    printf ("\nnhap ky tu can thay the: ");
    char x;
    scanf ("%c", &x);
    thaythe(w,k,x);
    printf ("ky tu va so lan xuat hien cua no la: ");
    timvademkt(s1);
    char **q;
	q=(char**) malloc(100*sizeof(char*));
	tachchuoi(s1,w,&k);
	qsort(w,k,sizeof(w[0]),cmp);
	printf ("\nchuoi sau khi duoc sap xep theo tu dien la: \n");
	for (int i=0;i<k;i++){
		printf ("%s ", w[i]);
	}
}
