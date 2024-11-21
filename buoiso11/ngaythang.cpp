#include <stdio.h>
#include <stdbool.h>
struct ngaythang{
	int ngay;
	int thang;
	int nam;	
};
void nhap(ngaythang *nt){
	printf ("nhap ngay: ");
	scanf ("%d", nt->ngay);
	printf ("nhap thang: ");
	scanf ("%d", nt->thang);
	printf ("nhap nam: ");
	scanf ("%d", nt->nam);
}
void xuat(ngaythang nt){
	printf ("%02d/%02d/%02d", nt.ngay,nt.thang,nt.nam);
}
int ngay(ngaythang *nt){
	switch (nt->thang){
		case 1:case 3: case 5: case 7: case 8: case 10: case 12:{
			return 31;
			break;
		}
		case 2:{
			if (nt->nam%4==0){
				return 29;
				break;
			}
			else{
				return 28;
				break;
			}
		}
		case 4: case 6: case 9:  case 11:{
			return 30;
			break;
		}
	}
}
int valid(ngaythang *nt){
	if (nt->ngay>ngay(nt)){
		return 0;
	}
	else return 1;
}
void update(ngaythang *nt, ngaythang *add){
	nt->ngay+=nt->ngay;
	if(nt->ngay>ngay(nt)){
		nt->ngay/=ngay(nt);
	}
}
main(){
	ngaythang nt;
	nhap(&nt);
	xuat(nt);
//	if (valid(nt)==1){
//		
//	}
	ngaythang add;
	nhap(&add);
}
