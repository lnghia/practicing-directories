#include <iostream>
#include <graphics.h>

using namespace std;

typedef class dagiac{
public:
	dagiac();
	~dagiac();
	double getx();
	void setx(double x);
	double gety();
	void sety(double y);
	void Nhap(dagiac a[], int i, int n);
	void Xuat(dagiac a[], int n);
	void tinhtien(dagiac a[], int n);
	void thuphong(dagiac a[], int n);
	void quay();
	void vetg(dagiac a[], int n);
private:
	double X;
	double Y;
	double x1;
	double y1;
}dg;

dg::dagiac(){
	X=0;
	Y=0;
}

dg::~dagiac(){}

double dg::getx(){
	return X;
}

void dg::setx(double x){
	X=x;
}

double dg::gety(){
	return Y;
}

void dg::sety(double y){
	Y=y;
}

void dg::Nhap(dg a[], int i, int n){
	cout << "Nhap lan luot x va y cua dinh thu " << i+1 << " cua da giac: " << endl;
	cin >> a[i].X >> a[i].Y;
}

void dg::Xuat(dg a[], int i){
	cout << "Toa do cac dinh cua da giac: " << endl;
    cout << "(" << a[i].X << "," << a[i].Y << ")" << endl;
}

void dg::thuphong(dg a[], int n){
    double xg=0;
    double yg=0;
    for (int i=0; i<n; ++i){
        xg+=a[i].X;
        yg+=a[i].Y;
    }
    xg/=n;
    yg/=n;
    double t;
    cout << "Nhap ti le thu (phong): "; cin >> t;
    if (t>1)
        for (double i=1; i<=t; i+=0.1){
            cleardevice();
            for (int j=0; j<n; ++j){
                a[j].x1=i*(a[j].X-xg)+xg;
                a[j].y1=i*(a[j].Y-yg)+yg;
            }
            for (int j=0; j<n-1; ++j)
                line(a[j].x1, a[j].y1, a[j+1].x1, a[j+1].y1);
            line(a[0].x1, a[0].y1, a[n-1].x1, a[n-1].y1);
            delay(50);
        }
    if(t<1){
        for (double i=1; i>=t; i-=0.1){
            cleardevice();
            for (int j=0; j<n; ++j){
                a[j].x1=i*(a[j].X-xg)+xg;
                a[j].y1=i*(a[j].Y-yg)+yg;
            }
            for (int j=0; j<n-1; ++j)
                line(a[j].x1, a[j].y1, a[j+1].x1, a[j+1].y1);
            line(a[0].x1, a[0].y1, a[n-1].x1, a[n-1].y1);
            delay(50);
        }
    }
}

void dg::tinhtien(dg a[], int n){
	int x, y;
	cout << "Nhap toa do vector tinh tien: " << endl;
	cin >> x >> y;
	int i=1, j=1;
	int x1, x2, x3;
	int y1, y2, y3;
	while (i<=x || j<=y){
        cleardevice();
        for (int k=0; k<n; ++k){
            a[k].x1=a[k].X+i;
            a[k].y1=a[k].Y+j;
        }
        for (int k=0; k<n-1; ++k){
            line(a[k].x1, a[k].y1, a[k+1].x1, a[k+1].y1);
        }
        line(a[0].x1, a[0].y1, a[n-1].x1, a[n-1].y1);
        if (x!=0) ++i;
        if (y!=0) ++j;
        delay(50);
    }
    getch();
}

void dg::vetg(dg a[], int n){
	int g=DETECT, gmode;
	initgraph(&g, &gmode, "C:/TC/BGI");
	for (int i=0; i<n-1; ++i)
        line(a[i].X, a[i].Y, a[i+1].X, a[i+1].Y);
	line(a[0].X, a[0].Y, a[n-1].X, a[n-1].Y);
	thuphong(a, n);
	tinhtien(a, n);
    getch();
}

int main(){
    int n; cout << "Nhap so dinh cua da giac: ";
    cin >> n;
	dg *b=new dg[n];
	dg a;
	for (int i=0; i<n; ++i)
        b[i].Nhap(b, i, n);
	for (int i=0; i<n; ++i)
        b[i].Xuat(b, i);
	a.vetg(b, n);
	return 0;
}

