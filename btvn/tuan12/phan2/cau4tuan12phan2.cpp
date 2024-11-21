#include <stdio.h>
#include <stdlib.h>
struct thoigian{
	int gio;
	int phut;
	int giay;
};
void nhap(thoigian *tg){
	printf("Nhap gio: ");
    scanf("%d", &tg->gio);
    printf("Nhap phut: ");
    scanf("%d", &tg->phut);
    printf("Nhap giay: ");
    scanf("%d", &tg->giay);
}
void xuat(thoigian tg){
	printf ("%02d:%02d:%02d", tg.gio,tg.phut,tg.giay);
}
thoigian *capnhat(thoigian *tg, thoigian *ct){
    thoigian *sum = (thoigian*) malloc (1*sizeof(thoigian));
    sum->gio=tg->gio+ct->gio;
    sum->phut=tg->phut+ct->phut;
    sum->giay=tg->giay+ct->giay;
    if (sum->phut >= 60) {
        sum->gio += sum->phut / 60;
        sum->phut %= 60;
    }
    if (sum->gio >= 24) {
        sum->gio %= 24;
    }
    if (sum->giay >= 60) {
        sum->phut += sum->giay / 60;
        sum->giay %= 60;
    }
    return sum;
}
main(){
	thoigian tg;
	do{
		nhap(&tg);
	} 
	while(tg.giay>24||tg.phut>60||tg.giay>60);
	printf ("thoi gian sau khi nhap la: ");
	xuat(tg);
	thoigian ct;
	printf ("\nnhap thoi gian duoc cong them: \n");
	nhap(&ct);
	thoigian *kq = capnhat(&tg, &ct);
    printf("\nThoi gian sau khi cong them:");
    xuat(*kq);
}
//struct ngaythang{
//	int ngay;
//	int thang;
//	int nam;
//};
//void nhap(ngaythang *nt){
//	printf("Nhap ngay: ");
//    scanf("%d", &nt->ngay);
//    printf("Nhap thang: ");
//    scanf("%d", &nt->thang);
//    printf("Nhap nam: ");
//    scanf("%d", &nt->nam);
//}
//void xuat(ngaythang nt){
//	printf ("%02d/%02d/%02d", nt.ngay,nt.thang,nt.nam);
//}
//int kt(ngaythang *nt){
//	
//}
//main(){
//	ngaythang nt;
//	nhap(&nt);
//	printf ("ngay thang sau khi nhap la: ");
//	xuat(nt);
//}
