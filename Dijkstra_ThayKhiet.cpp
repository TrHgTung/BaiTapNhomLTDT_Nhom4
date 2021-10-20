#include<bits/stdc++.h>  //LTDT_TH06
#include<Windows.h>
#include<ctime>
using namespace std;	//BoTest: test_DIJKSTRA_Khietln.txt

#define MAX 100
#define VoCuc -1
#define FileIn "test_DIJKSTRA_Khietln.txt"


struct GRAPH{
	int sodinh, a[MAX][MAX];
};

void readGRAPH(GRAPH &g){		//nhap du lieu theo kieu thong thuong
	cout << " ------------------------ MAN HINH NHAP LIEU (MA NHOM: I_NHOM_4) ---------------------------" << endl;	//thiet ke giao dien
 	for(int t=0; t<3; t++)	{ cout << endl;	}
 	cout << "Nhap so luong dinh: " ;
	cin >> g.sodinh;
	cout << endl;
	cout << "Moi nhap tat ca cac gia tri phan tu cua do thi:  " << endl;
	for(int i=0; i<g.sodinh; i++){
		for(int j=0; j <g.sodinh; j++){
			cin >> g.a[i][j];
		}
	}
}

/*void readGRAPH(GRAPH &g) {		//nhap du lieu co san tu file (ten file + duong dan o #define FileIN
	FILE *f = fopen(FileIn,"rb");
	//fscanf(f,"%d",&g.sodinh);
	cout << " ------------------------ MAN HINH NHAP LIEU (MA NHOM: I_NHOM_4) ---------------------------" << endl;
 	for(int t=0; t<3; t++)	{ cout << endl;	}	//thut xuong 3 dong so voi tieu de, trang tri cho giao dien
 		cout << "Du lieu duoc lay tu file: " << FileIn << endl;
 		//cout << "	 So dinh: 0"<< n << endl;
		//cout << endl;
 		//cout << "	 Hien thi ma tran trong so: " << endl << endl;
		cin >> g.sodinh;
		for(int i=0; i<g.sodinh; i++){
			for(int j=0; j <g.sodinh; j++){
				cin >> g.a[i][j];
			}
		}
		fclose(f);
	}
*/

void printGRAPH(GRAPH g){
	cout << " ------------------------ MAN HINH KET QUA (MA NHOM: I_NHOM_4) ---------------------------" << endl;	//thiet ke giao dien
 	for(int t=0; t<3; t++)	{ cout << endl;	}
	cout << "So dinh cua do thi la: " << g.sodinh << endl;
	for(int i=0; i < g.sodinh; i++){
		for(int j=0; j < g.sodinh; j++){
			cout << setw(4) << g.a[i][j] << "	";
		}
		cout<< endl;
	}
	//cout << endl;
}

// Properties -- Nhung thuoc tinh -- //
bool ThuocTinh[MAX];
int Length[MAX];
int LastV[MAX];
// -- //

void Dijkstra(GRAPH g, int x, int y){
	int i = 0, min = -1;
	for(i; i < g.sodinh; i++){
		ThuocTinh[i] = true;
		Length[i] = VoCuc;
		LastV[i] = -1;
	}
	Length[x] = 0;
	ThuocTinh[x] = false;
	LastV[x] = x;
	
	int v = x, t = x;
	while(ThuocTinh[y]){
		for(int k=0; k <g.sodinh; k++){
			if(g.a[v][k] != 0 && ThuocTinh[k] == true && (Length[k] == VoCuc || Length[k] > Length[v] + g.a[v][k])){
				Length[k] = Length[v] + g.a[v][k];
				LastV[k] = v;
			}
		}
		v = -1;
		for(i = 0; i < g.sodinh; i++)
		{
			if(ThuocTinh[i] == true && Length[i] != VoCuc)
				if(v == -1 || Length[v] > Length[i])
					v = i;
		}
		ThuocTinh[v] = false;
	}
}
void XuatDuongDi(int x, int y)
{
	int DuongDi[MAX];	//duong di duoc xuat nguoc
	int v = y, i;
	//Tìm duong di: truy xuat tu LastV
	int id = 0;
	while (v != x)
	{
		DuongDi[id] = v;
		v = LastV[v];
		id++;
	}
	DuongDi[id] = x;
	//Xuat nguoc di tìm duong di dinhDau -> dinhCuoi
	cout << "Duong di can tim la:  ";
	for(i = id; i > 0; i--)
		cout << DuongDi[i] << " -->";
	cout << DuongDi[i] << endl;
}

int main()
{
	GRAPH g;
	readGRAPH(g);
	printGRAPH(g);

	int x, y;
	//x = 0; y = 4;
    
	cout << "Nhap dinh dau (dinh xuat phat): "; cin >> x;	cout << endl;
	cout << "Nhap dinh cuoi (dich): "; cin >> y; cout << endl;
    //cin >> x >>y;
	//tìm duong di ngan nhat tu dinh_x den dinh y
	Dijkstra(g, x, y);
	//dung thuat toan dijsktra in duong di ngan nhat tu dinh x toi dinh y
	XuatDuongDi(x, y);
	Sleep(2500);
	
	system("cls");	//Windows  -- Neu Linux: System("Clear");
	cout << " ------------------------ MAN HINH GIOI THIEU (MA NHOM: I_NHOM_4) ---------------------------" << endl;	//thiet ke giao dien
 	for(int t=0; t<3; t++)	{ cout << endl;	}
 	time_t now = time(0);
 	char *dt = ctime(&now);
	cout << "Nhom : I_NHOM_4 -- Lop LTDT 2111COMP170102 -- HCMUE -- Date: " << dt << endl;
	cout << endl << endl;
	cout << "Trinh Hoang Tung -- 46.01.104.211" << endl;		//Nhap ten o day
	cout << "Nguyen Hoang Truc Van -- 46.01.104.216" << endl;
	cout << "Dang Huynh Minh Khanh -- 46.01.104.080" << endl;
	cout << "Nguyen Duc Nhat -- 46.01.104.127" << endl;
	
	return 0;
}
/*	--- TEST CASE --- 
	5
	0 2 0 3 0
	2 0 0 6 0
	0 0 0 2 5
	3 6 2 0 0
	0 0 5 0 0
	1 4
	
	 -- Chu thich testcase -- 
	dong 1 la so luong dinh (5)
	cac gia tri cua cac dong con lai tru 2 gia tri cua dong cuoi: la cac phan tu cua mang do thi (
																								0 2 0 3 0
																								2 0 0 6 0
																								0 0 0 2 5
																								3 6 2 0 0
																								0 0 5 0 0
																								1 4			)
	dong cuoi cung (gom 2 gia tri) : la diem dau va diem cuoi cua duong di muon xet duyet (1 4 || voi 1 la diem dau va 4 la diem dich)*/
