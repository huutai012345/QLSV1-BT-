#include<iostream>
#include <string>
#define MAX 100
using namespace std;

//CHUA TEST


//=================== DS mon hoc ==================
struct mon_hoc
{
	string ma_mh;
	string ten_mh;
	int tclt;
	int tlth;
};

struct ds_mon_hoc
{
	mon_hoc ds_mh[MAX];
	int sl_mh = 0;
};

//================== DS Diem ============== //ds liên kết => 1 diem = 1 node
struct diem_mon
{
	//data
	string ma_mh;
	int lan;
	float diem;
	//pointer
	diem_mon* pnext;
};

struct ds_diem
{
	diem_mon* phead = NULL;
	int so_diem_mon = 0;
};

//================= DS sinh vien ============ //ds liên kết => 1 sinh viên = 1 node
struct sinh_vien
{
	//data
	string ma_sv;
	string ho;
	string ten;
	string phai;
	string sdt;
	ds_diem ds_diem;
	//======== c2 - khó quản lý =================
	/*diem_mon *phead = NULL;
	int so_diem_mon = 0;*/

	//pointer
	sinh_vien* pnext;
};

struct ds_sinh_vien
{
	sinh_vien* phead = NULL;
	int so_sv = 0;
};

//================== DS LOP ===================
struct lop
{
	string ma_lop;
	string ten_lop;
	int nam_nhap_hoc;
	//
	ds_sinh_vien ds_sinh_vien;
};

struct ds_lop
{
	lop ds_lop[MAX];
	int sl_lop = 0;
};

//================== khu vuc khai bao nguyen mau ham ============
void menu(ds_lop& ds_lop, ds_mon_hoc& dsMH);
//================= nhap xuat lop ==========
void nhap_lop(ds_lop& dsLop);
void xuat_ds_lop(ds_lop dsLop);
void addListSV(ds_sinh_vien& dsSV);
void nhap_sinh_vien(ds_lop& dsLop);
void sortListByName(ds_sinh_vien& dsSV);
void printList(ds_sinh_vien dsSV);
void printListSVByYear(ds_lop dsLop);
void printListSVByName(ds_lop dsLop);
void inputMonHoc(ds_mon_hoc& dsMH);
void printMonHoc(ds_mon_hoc dsMH);
void addDiem(ds_diem& dsD);
void inputDiem(ds_lop& dsLop);
void printDSDiem(ds_lop dsLop);
void printPhieuDiem(ds_lop dsLop);

int main()
{
	ds_lop dsLop;
	ds_mon_hoc dsMH;
	menu(dsLop,dsMH);
	return 0;
}

void menu(ds_lop& dsLop,ds_mon_hoc& dsMH)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t MENU\n";
		cout << "1. Nhap Lop" << endl;
		cout << "2. Nhap Sinh Vien Lop" << endl;
		cout << "3. Xuat Danh Sach Sinh Vien Theo Nien Khoa" << endl;
		cout << "4. DSSV 1 Lop" << endl;
		cout << "5. Nhap Mon Hoc" << endl;
		cout << "6. In DS Mon Hoc" << endl;
		cout << "7. Nhap Diem" << endl;
		cout << "8. In Bang Diem Mon Hoc Cua 1 Lop" << endl;
		cout << "9. In Phieu Diem" << endl;
		cout << "0. Thoat." << endl;
		int luachon;
		cout << "Nhap lua chon: "; 
		cin >> luachon;

		system("cls");
		switch (luachon)
		{
		case 1:
		{
			cin.ignore();
			nhap_lop(dsLop);
			break;
		}
		case 2:
		{
			cin.ignore();
			nhap_sinh_vien(dsLop);
			break;
		}
		case 3:
		{
			cin.ignore();
			printListSVByYear(dsLop);
			system("pause");
			break;
		}
		case 4:
		{
			cin.ignore();
			printListSVByName(dsLop);
			break;
		}
		case 5:
		{
			cin.ignore();
			inputMonHoc(dsMH);
			break;
		}
		case 6:
		{
			printMonHoc(dsMH);
			system("pause");
			break;
		}
		case 7:
		{
			cin.ignore();
			inputDiem(dsLop);
			break;
		}
		case 8:
		{
			cin.ignore();
			printDSDiem(dsLop);
			system("pause");
			break;
		}
		case 9:
		{
			cin.ignore();
			printPhieuDiem(dsLop);
			system("pause");
			break;
		}
		case 0:
		{
			exit(0);
		}
		}
	}
}

void nhap_lop(ds_lop& dsLop)
{
	//======== nhap sl ==========
	int n;
	do
	{
		cout << "Nhap so luong lop can nhap: "; 
		cin >> n;
		if (n > MAX || n <= 0)
		{
			cout << "Moi nhap lai!" << endl;
		}
	} while (n > MAX || n <= 0);
	
	//======== xu ly nhap =======
	for (int i = 0; i < n; i++)
	{
		cout << "=========== Nhap lop thu " << i+1 << ": ============" << endl;
		cout << "Nhap ma lop: ";
		cin.ignore();
		getline(cin, dsLop.ds_lop[i].ma_lop);
		cout << "Nhap ten lop: ";
		getline(cin, dsLop.ds_lop[i].ten_lop);
		cout << "Nhap nam nhap hoc cua lop: "; 
		cin >> dsLop.ds_lop[i].nam_nhap_hoc;
		dsLop.sl_lop++;
	}
}
void xuat_ds_lop(ds_lop dsLop)
{
	int n = dsLop.sl_lop;
	for (int i = 0; i < n; i++)
	{
		cout << "=========== Lop thu " << i << " la: ============" << endl;
		cout << "Ma lop: " << dsLop.ds_lop[i].ma_lop << endl;
		cout << "Ten lop: " << dsLop.ds_lop[i].ten_lop << endl;
		cout << "Nam nhap hoc cua lop: " << dsLop.ds_lop[i].nam_nhap_hoc << endl;
	}
}

void addListSV(ds_sinh_vien& dsSV)
{
	sinh_vien* nodeSV = new sinh_vien();
	cout << "Nhap Ma Sinh Vien:" ;
	getline(cin, nodeSV->ma_sv);
	cout << "Nhap Ho:" ;
	getline(cin, nodeSV->ho);
	cout << "Nhap Ten:" ;
	getline(cin, nodeSV->ten);
	cout << "Nhap Phai:" ;
	getline(cin, nodeSV->phai);
	cout << "Nhap SDT:" ;
	getline(cin, nodeSV->sdt);
	nodeSV->pnext = NULL;
	dsSV.so_sv++;

	if (dsSV.phead == NULL)
	{
		dsSV.phead = nodeSV;
		return;
	}

	sinh_vien* nodeTemp = dsSV.phead;
	while (true)
	{
		if (nodeTemp->pnext == NULL)
		{
			nodeTemp->pnext = nodeSV;
			return;
		}
		nodeTemp = nodeTemp->pnext;
	}
}
void nhap_sinh_vien(ds_lop& dsLop)
{
	string maLop;
	cout << "Nhap Ma Lop:";
	getline(cin,maLop);

	int n;
	cout << "Nhap So Lg SV:";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		if (dsLop.ds_lop[i].ma_lop == maLop)
		{	
			for (int j = 0; j < n; j++)
			{
				cout << "=========== Nhap SV thu " << j + 1 << ": ============" << endl;
				addListSV(dsLop.ds_lop[i].ds_sinh_vien);
			}
			return;
		}
	}
}

void sortListByName(ds_sinh_vien& dsSV)
{
	for (sinh_vien* k = dsSV.phead; k != NULL; k = k->pnext)
	{
		for (sinh_vien* h = k->pnext; h != NULL; h = h->pnext)
		{
			if ((k->ten + k->ho) > (h->ten + h->ho))
			{
				sinh_vien temp;
				
				temp.ma_sv = h->ma_sv;
				temp.ho = h->ho;
				temp.ten = h->ten;
				temp.phai = h->phai;
				temp.sdt = h->sdt;

				h->ma_sv = k->ma_sv;
				h->ho = k->ho;
				h->ten = k->ten;
				h->phai = k->phai;
				h->sdt = k->sdt;

				k->ma_sv= temp.ma_sv;
				k->ho= temp.ho;
				k->ten= temp.ten;
				k->phai= temp.phai;
				k->sdt= temp.sdt;
			}
		}
	}
}
void printList(ds_sinh_vien dsSV)
{
	for (sinh_vien* k = dsSV.phead; k != NULL; k = k->pnext)
	{
		cout << k->ma_sv << "\t" << k->ho +" "+ k->ten <<"\t"<< k->phai << "\t" << k->sdt << endl;
	}
	cout << endl;
}
void printListSVByYear(ds_lop dsLop)
{
	int nienkhoa;
	cout << "Nhap vao nien khoa:";
	cin >> nienkhoa;

	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		if (dsLop.ds_lop[i].nam_nhap_hoc == nienkhoa)
		{
			cout << "\n\n\t\t DSSV Theo Nien Khoa\n\n" << endl;
			printList(dsLop.ds_lop[i].ds_sinh_vien);
		}
	}
}
void printListSVByName(ds_lop dsLop)
{
	string maLop;
	cout << "Nhap Ma Lop:";
	getline(cin, maLop);

	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		if (dsLop.ds_lop[i].ma_lop == maLop)
		{
			sortListByName(dsLop.ds_lop[i].ds_sinh_vien);
			cout << "\n\n\t\t DSSV Theo Ten\n\n" << endl;
			printList(dsLop.ds_lop[i].ds_sinh_vien);
			return;
		}
	}
}

void inputMonHoc(ds_mon_hoc &dsMH)
{
	int n;
	cout << "Nhap SL Mon Hoc:";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "=========== Nhap Mon Hoc thu " << i + 1 << ": ============" << endl;
		mon_hoc mh;
		cout << "Nhap Ma Mon:";
		getline(cin, mh.ma_mh);
		cout << "Nhap Ten Mon:";
		getline(cin, mh.ten_mh);
		cout << "Nhap STCLT";
		cin >> mh.tclt;
		cout << "Nhap STCTT";
		cin >> mh.tlth;

		dsMH.ds_mh[dsMH.sl_mh] = mh;
		dsMH.sl_mh++;
	}
	
}
void printMonHoc(ds_mon_hoc dsMH)
{
	cout << "\n\n\t\t DS Mon Hoc\n\n\n";
	for (int i = 0; i < dsMH.sl_mh; i++)
	{
		cout << dsMH.ds_mh[i].ma_mh << "\t" << dsMH.ds_mh[i].ten_mh << "\t" << dsMH.ds_mh[i].tclt << "\t" << dsMH.ds_mh[i].tlth << endl;
	}
	cout << endl;
}

void addDiem(ds_diem &dsD)
{
	int n;
	cout << "Nhap So Lg Mon :";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "=========== Nhap Diem Cua Mon thu " << i + 1 << ": ============" << endl;
		diem_mon* nodeD = new diem_mon();

		cout << "Nhap Ma Mon" << endl;
		getline(cin, nodeD->ma_mh);
		cout << "Nhap Diem:" << endl;
		cin >> nodeD->diem;
		cout << "Nhap Lan Thi:" << endl;
		cin >> nodeD->lan;
		nodeD->pnext = NULL;
		dsD.so_diem_mon++;

		if (dsD.phead == NULL)
		{
			dsD.phead = nodeD;
			return;
		}

		diem_mon* nodeTemp = dsD.phead;
		while (true)
		{
			if (nodeTemp->pnext == NULL)
			{
				nodeTemp->pnext = nodeD;
				return;
			}
			nodeTemp = nodeTemp->pnext;
		}
	}
	
}
void inputDiem(ds_lop& dsLop)
{
	string maSV;
	cout << "Nhap Ma SV:" ;
	getline(cin, maSV);

	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		for (sinh_vien *k = dsLop.ds_lop[i].ds_sinh_vien.phead; k != NULL; k = k->pnext)
		{
			if (k->ma_sv == maSV)
			{
				addDiem(k->ds_diem);
				return;
			}
		}
	}
}
void printDSDiem(ds_lop dsLop)
{
	string maLop;
	string maMon;
	int lanThi;
	cout << "Nhap Ma Lop:";
	getline(cin, maLop);
	cout << "Nhap Ma Mon Hoc:";
	getline(cin, maMon);
	cout << "Nhap Lan Thi:" ;
	cin >> lanThi;

	cout << "\n\n\t\t DS Diem Thi Mon " << maMon << " Lan "<<lanThi<<" Cua " << maLop << endl << endl << endl;
	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		if (dsLop.ds_lop[i].ma_lop == maLop)
		{
			for (sinh_vien* k = dsLop.ds_lop[i].ds_sinh_vien.phead; k != NULL; k = k->pnext)
			{
				for (diem_mon* h = k->ds_diem.phead; h != NULL; h = h->pnext)
				{
					if (h->ma_mh == maMon && h->lan==lanThi)
					{
						cout << k->ma_sv << "\t" << k->ho+" "+k->ten << "\t"<<h->diem << endl;
						break;
					}
				}
			}
			break;
		}
	}
}
void printPhieuDiem(ds_lop dsLop)
{
	string maSV;
	cout << "Nhap Ma SV:";
	getline(cin, maSV);

	cout << "\n\n\t\t Phieu Diem Cua Sinh Vien Co Ma "<<maSV << endl << endl << endl;
	for (int i = 0; i < dsLop.sl_lop; i++)
	{
		for (sinh_vien* k = dsLop.ds_lop[i].ds_sinh_vien.phead; k != NULL; k = k->pnext)
		{
			if (k->ma_sv == maSV)
			{
				for (diem_mon* h = k->ds_diem.phead; h != NULL; h = h->pnext)
				{
					cout << h->ma_mh <<"\t"<< h->diem << "\t"<<h->lan<<endl;
				}
				break;
			}
		}
	}
}
