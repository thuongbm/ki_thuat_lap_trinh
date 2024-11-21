#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mathang{
	char mahang[100];
	int gia;
};
struct hoadon{
	char mahang[100];
	int soluong;
	char ngayban[100];
};
void nhapmathang(mathang *mh){
	printf ("nhap ma hang: ");
	fflush (stdin);
	gets (mh->mahang);
	printf ("nhap gia: ");
	scanf ("%d", &mh->gia);
}
void nhapmathang(mathang *mh, int m){
	for (int i=0;i<m;i++){
		nhapmathang(mh+i);
	}
}
void xuatmathang(mathang mh){
	printf ("\n%s %d", mh.mahang, mh.gia);
}
void xuatmathang(int m, mathang *mh){
	for (int i=0;i<m;i++){
		xuatmathang(*(mh+i));
	}
}
void xuathoadon(hoadon hd){
	printf ("\n%s %d %s", hd.mahang, hd.soluong, hd.ngayban);
}
void xuathoadon(int n, hoadon *hd){
	for (int i=0;i<n;i++){
		xuathoadon(*(hd+i));
	}
}
void nhaphoadon(hoadon *hd){
	printf ("nhap ma hang: ");
	fflush (stdin);
	gets (hd->mahang);
	printf ("nhap so luong: ");
	scanf ("%d", &hd->soluong);
	printf ("nhap ngay ban: ");
	fflush (stdin);
	gets (hd->ngayban);
}
void nhaphoadon(hoadon *hd, int n){
	for (int i=0;i<n;i++){
		nhaphoadon(hd+i);
	}
}
int dem(hoadon *hd, int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (hd[i].soluong>10){
			dem++;
		}
	}
	return dem;
}
int tien(mathang *mh, hoadon *hd, int m, int n, char x[]){
	int *tong;
	tong=(int*) calloc ((n+1),sizeof(int));
	for (int i=0;i<n;i++){
		if (strcmp(hd[i].ngayban,x)==0){
			for (int j=0;j<m;j++){
				if (hd[i].mahang==mh[j].mahang){
					tong[i]=hd[i].soluong*mh[j].gia;
				}
			}
		}
	}
//	for (int i=0;i<n;i++){
//		for (int j=0;j<m;j++){
//			if (strcmp(hd[i].ngayban,x)==0){
//				tong[i] += hd[i].soluong * mh[j].gia;
//			}
//		}
//	}
	int tien=0;
	for (int i=0;i<n;i++){
		tien+=tong[i];
	}
	return tien;
}
main(){
	int m,n;
	printf ("nhap so mat hang va hoa don: ");
	scanf ("%d%d", &m,&n);
	mathang *mh;
	mh = (mathang*) malloc ((m+1)*sizeof(mathang));
	hoadon *hd;
	hd = (hoadon*) malloc ((n+1)*sizeof(hoadon));
	nhapmathang(mh, m);
	nhaphoadon(hd, n);
	printf ("\nmat hang cua cua hang la: ");
	xuatmathang(m,mh);
	printf ("\nhoa don cua cua hang la: ");
	xuathoadon(n,hd);
	int b=dem(hd, n);
	if (b==0) printf ("\nkhong co hoa don co so luong lon hon 10");
	else printf ("\nso hoa don co so luong lon 10 la: %d", b);
	char x[100];
	printf ("\nnhap ngay:");
	fflush (stdin);
	gets (x);
	b=tien(mh, hd, m, n, x);
	if (b==0) printf ("\nkhong co ngay giao dich nthe");
	else printf ("\nso tien kiem duoc trong ngay chi dinh la: %d", b);
}
//#include <stdio.h>
//#include <string.h>
//
//
//struct MatHang {
//    char maHang[20]; 
//    int donGia;
//};
//
//
//struct HoaDon {
//    char maHang[20]; 
//    int soLuong; 
//    char ngayBan[20]; 
//};
//
//
//void nhapMatHang(struct MatHang *mh) {
//    printf("Nhap ma hang: ");
//    scanf("%s", mh->maHang);
//    printf("Nhap don gia: ");
//    scanf("%d", &mh->donGia);
//}
//
//
//void nhapHoaDon(struct HoaDon *hd) {
//    printf("Nhap ma hang: ");
//    scanf("%s", hd->maHang);
//    printf("Nhap so luong: ");
//    scanf("%d", &hd->soLuong);
//    printf("Nhap ngay ban: ");
//    scanf("%s", hd->ngayBan);
//}
//
//int main() {
//    int m, n;
//    printf("Nhap so luong mat hang: ");
//    scanf("%d", &m);
//    struct MatHang matHang[m];
//    for (int i = 0; i < m; i++) {
//        printf("Nhap thong tin mat hang thu %d:\n", i + 1);
//        nhapMatHang(&matHang[i]);
//    }
//
//    printf("Nhap so luong hoa don: ");
//    scanf("%d", &n);
//    struct HoaDon hoaDon[n];
//    for (int i = 0; i < n; i++) {
//        printf("Nhap thong tin hoa don thu %d:\n", i + 1);
//        nhapHoaDon(&hoaDon[i]);
//    }
//
//   
//    int count = 0;
//    for (int i = 0; i < n; i++) {
//        if (hoaDon[i].soLuong > 10) {
//            count++;
//        }
//    }
//    printf("So hoa don co so luong lon hon 10: %d\n", count);
//
//   
//    int tongTien = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (strcmp(hoaDon[i].maHang, matHang[j].maHang) == 0) {
//                tongTien += hoaDon[i].soLuong * matHang[j].donGia;
//                break;
//            }
//        }
//    }
//    printf("Tong tien ban duoc trong mot ngay: %d\n", tongTien);
//
//    return 0;
//}

