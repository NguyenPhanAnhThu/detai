#include<windows.h>
#include <string.h>
#include <queue>
#include<iomanip>
#include <cstring>
#include <iostream>
#include<fstream> 
#include "mylib.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib> 
#define key_enter 13
#define key_back 8
#define key_tab 9
using namespace std;
const int MAXMB =20;

struct HanhKhach{
	int CMND=0;
	char Ho[21]="";
	char Ten[21]="";
	char Phai[6]="";
};

struct NodeHanhKhach {
    HanhKhach HK;  
    NodeHanhKhach *Left, *Right;  
};
typedef NodeHanhKhach *Tree;   

struct ChuyenBay{
	Tree FirstTree=NULL;
	char MaChuyenBay[21]="";
	int Ngay;
	int Thang;
	int Nam;
	int Gio;
	int Phut;
	char SanBayDen[51]="";
	int TrangThai;
	char SoHieu[21]="";
};

struct NodeChuyenBay{
    ChuyenBay CB;
	struct NodeChuyenBay *next;
};
typedef NodeChuyenBay* PTRChuyenBay;

struct MayBay{
	char SoHieu[21]="";
	char Loai[21]="";
	int SoCho=0;
	PTRChuyenBay FirstMB=NULL;
};

 struct LISTMayBay {
	int n=0 ;
	MayBay nodes[MAXMB];
};

const int so_item = 22;
const int dong =5;
const int cot = 6 ;
const int Up = 72;
const int Down = 80;

char menu_MayBay [so_item][50] = {
                              " Them May Bay                    ",			                   
			                  " Them Chuyen Bay                 ",
			                  " Dat Ve                          ",
			                  "",
			                  "",
			                  "",
			                  " In Danh Sach Theo Ma Chuyen Bay  ",
			                  " Tim Ve Trong Theo Ngay & Dia Diem",
			                  " Tim Ve Trong Theo Ma Chuyen Bay  ",
			                  " Thong Ke So Lan Bay              ",
			                  "",
			                  "",			                 
			                  " Sua Thong Tin May Bay            ",
			                  " Hieu Chinh Thoi Gian Bay	        ",
			                  "",
			                  "",
							   "",			              			            
			                  " Xoa May Bay                      ",
			                  " Huy Chuyen Bay                   ",	
							   "",
			                  "",	  
							    " Dang Xuat                      ",	                		                 			                 
			                  };

void VeKhung()
{
	 
	gotoxy(4,3);
    cout <<"_______________________________________________________________________________________________________________________________";
    gotoxy(4,4);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,5);                     
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,6);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,7);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,8);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,10);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,9);
	cout <<"|____________________________________|                                                                                         |";
    gotoxy(4,11);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,12);   
    cout <<"|                                    |                                                                                         |";
    gotoxy(4,13);
	cout <<"|                                    |                                                                                         |";
	gotoxy(4,14);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,15);
	cout <<"|____________________________________|                                                                                         |";
    gotoxy(4,16);
	cout <<"|                                    |                                                                                         |";  
    gotoxy(4,17);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,18);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,19);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,20);
	cout <<"|____________________________________|                                                                                         |";
    gotoxy(4,21);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,22);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,23);
	cout <<"|                                    |                                                                                         |";
	gotoxy(4,24);
	cout <<"|                                    |                                                                                         |";	
    gotoxy(4,25);
	cout <<"|____________________________________|                                                                                         |";
    gotoxy(4,26);
	cout <<"|                                    |                                                                                         |";
    gotoxy(4,27);
	cout <<"|____________________________________|_________________________________________________________________________________________|";
}

void color_intro(){
	 SetColor(12);
}

 void backgroud () {
	 SetColor(2);
	SetBGColor(0);
}
void HighLight () {
	SetColor(10);
	SetBGColor(0);
}

void MenuGV_Color () {
	SetColor(1);
}

 
void showIntro(){
 
	gotoxy(40,2);
	color_intro();
	cout << ">>>>>>>>>>>>>>>>>>>> Quan Ly Ve May Bay <<<<<<<<<<<<<<<<<<<<";
}
void TestResize()
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX() ;
    font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(cons,0,font);
    font->dwFontSize.X = 18;
    font->dwFontSize.Y = 22;
    //font->FontWeight = 22;
    //font->FontFamily = FF_DECORATIVE;
    SetCurrentConsoleFontEx(cons,0,font);
 } 
int MenuDong_MayBay(char td [so_item][50],int dem_Item){
	
	showIntro();
   HighLight();
  //  system("cls"); 
  	VeKhung();
  
	    int chon =dem_Item;
  int i; 
  for ( i=0; i< so_item ; i++)
  {
  	 MenuGV_Color();  
     gotoxy(cot, dong +i);
     cout << td[i];
  }
   
  gotoxy(cot,dong+chon);
   HighLight();  
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        MenuGV_Color();   
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	if(chon == 21)
              	{
              		chon=19;
				}
				else if(chon == 17)
              	{
              		chon=14;
				}
				else if(chon == 12)
              	{
              		chon=10;
				}
				else if(chon == 6)
              	{
              		chon=3;
				}
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		         MenuGV_Color();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	if(chon == 2)
              	{
              		chon=5;
				}
				else if(chon == 9)
              	{
              		chon=11;
				}
				else if(chon == 13)
              	{
              		chon=16;
				}
				else if(chon == 18)
              	{
              		chon=20;
				}
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
     	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

void Baoloi (char* S ){
//	 MenuGV_Color(); 
	int x= wherex() ; int y = wherey();
	gotoxy(45,26);
	cout << S;
	Sleep(1300);
	gotoxy(45, 26); 
	cout << "                                                 ";
	gotoxy(x,y);
}

//// May Bay

int Search_MayBay(LISTMayBay &mb, char *sohieu)
{	for ( int i =0 ; i <mb.n ; i++)
  		if (stricmp(mb.nodes[i].SoHieu,sohieu) == 0) return i;
	 return -1;
}

void Nhap_MayBay(LISTMayBay &mb){
	MayBay l;
	 int line=0;
    int sllop,tong; 
    color_intro();
    	gotoxy(45,5);
    cout << "so luong May Bay muon Tao : ";
      int n,k=0;
   string text[1]={""};
     while((n = getch()) != 13 )
     {           
     	if(n>='0'&&n<='9')
       {
       	k=n;
       	k=k-48;
       	cout << k;
       	text[0]+=char(n); 		     
	   }   
	     if( n == key_back){	    
					if(text[0].length()>0){	
						text[0].erase(text[0].length()-1,1);
						cout<<"\b \b";
					}				 
				} 			   
	 } 
	 sllop= atoi(text[0].c_str()); 
    tong = mb.n + sllop;
	while (mb.n < tong) {
		line+=3;
	 
	   	do
	{	 
		gotoxy(45,4+line); 
		cout << "So Hieu MB :"; 
		fflush(stdin) ; gets(l.SoHieu);
	 if (stricmp(l.SoHieu,"")==0) 
		{
				gotoxy(45,26);
			cout << "Nhap Thong Tin Chua Day Du ";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                               ";
		}
	}
	while(stricmp(l.SoHieu,"")==0);
	  
	  if (stricmp(l.SoHieu,"")==0) break;
	   
	  if (Search_MayBay(mb,l.SoHieu) >=0)
	  {
	    gotoxy(45,26);
     Baoloi( "Ma lop ban nhap bi trung. Hay nhap lai.");
	    continue;
	  }  
	do
	{	 
		gotoxy(45,5+line);
		cout << "Loai May Bay :"; 
		fflush(stdin) ; gets(l.Loai);
	 if (stricmp(l.Loai,"")==0) 
		{
				gotoxy(45,26);
			cout << "Nhap Thong Tin Chua Day Du ";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                               ";
		}
	}
	while(stricmp(l.Loai,"")==0);
	
		do
	{	 
 gotoxy(45,6+line);
		cout << "So Cho :"; 
	cin >> l.SoCho;
	 if (l.SoCho<20) 
		{
				gotoxy(45,26);
			cout << "So Ghe Tren Chuyen Bay Phai Lon Hon 20";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                                             ";
		gotoxy(45,6+line);
		cout << "                               ";
		
		}
	}
	while(l.SoCho < 20);
	  
	  mb.nodes[mb.n++]=l;
	}
	if (mb.n==tong)
	{	  
		 gotoxy(45,26);
	cout << "DANH SACH LOP DA DAY.";   
	}
	
}


void xoa_MayBay(LISTMayBay &dsMB){
 
	 int i=0, found, dump[10],test=0;
	 char  MaLop[11];
       MayBay l;
       gotoxy(45,5);
	 cout << "Nhap Ma May Bay muon xoa : ";
	  fflush(stdin) ; gets(l.SoHieu);
      
      if (strlen(l.SoHieu) == 0)
        return ;
      else
      {	
      	i = found = 0;
        do {
           strcpy(MaLop,dsMB.nodes[i].SoHieu);
          if (strcmp(strupr(l.SoHieu), strupr(MaLop)) == 0)
          {
          	 dump[found++] = i;
		  }
            
          i++;
        } while (i<dsMB.n);        
        if (!found)
        {
        	gotoxy(45,26);
        	 cout << "Khong tim thay Ma Lop co ten " << l.SoHieu << "\n\n\n\n\n";
        	 system("pause");
		}
      else
        {
           --dsMB.n;
            for (test=dump[0]; test<dsMB.n; test++)
            {
            	     dsMB.nodes[test] =  dsMB.nodes[test+1];
			}
               	gotoxy(45,26);
              cout << "Xoa Lop Thanh Cong. \n\n\n";
              system("pause");
        }
     
      } 
}

void SuaTT_MayBay(LISTMayBay &dsMB){
	
	int i=0, found, dump[10],test=0;
	 char  SoHieu[11]="" , Loai[21]="",MaLop[21]="";
	 int SoCho=0;
       MayBay l;
       gotoxy(45,5);
	cout << "Nhap So Hieu May Bay Muon Sua : ";
	  fflush(stdin) ; gets(l.SoHieu);
      
      if (strlen(l.SoHieu) == 0)
        return ;
      else
      {	
      	i = found = 0;
        do {
           strcpy(MaLop,dsMB.nodes[i].SoHieu);
          if (strcmp(strupr(l.SoHieu), strupr(MaLop)) == 0)
          {
          	 dump[found++] = i;
          	 gotoxy(45,6);
          	 cout << "So Hieu May Bay : ";
          	 fflush(stdin) ; gets(SoHieu);
          	 strcpy(dsMB.nodes[i].SoHieu,SoHieu);
          	 gotoxy(45,7);
          	 cout << "Loai May Bay : ";
          	 fflush(stdin) ; gets(Loai);
          	 strcpy(dsMB.nodes[i].Loai,Loai);
          	 gotoxy(45,8);
          	 cout << "So Cho : ";
          	 cin >> SoCho;
          	dsMB.nodes[i].SoCho = SoCho;
          	 
		  }
            
          i++;
        } while (i<dsMB.n);        
        if (!found)
        {
        	gotoxy(45,26);
        	 cout << "Khong tim thay May Bay co So Hieu " << l.SoHieu << "\n\n\n\n\n";
        	 system("pause");
		}
      
     
      } 
	
}

void LietKe_DaSach_MayBay(LISTMayBay mb)
{
		for ( int i =0 ; i <mb.n ; i++)
  	    {
  	    	cout << "\nMay Bai Co So Hieu : " << mb.nodes[i].SoHieu;
  	    	cout << "\nMay Bai Loai       : " << mb.nodes[i].Loai;
  	    	cout << "\nMay Bai Co So Cho  : " << mb.nodes[i].SoCho << endl;
  	    	
		  }
}

 
//////////  Chuyen Bay
 

void Insert_Last_ChuyenBay(PTRChuyenBay &FirstCB, ChuyenBay cb){
	PTRChuyenBay p=new NodeChuyenBay;
	p->CB=cb; p->next=NULL;
	if (FirstCB ==NULL) FirstCB = p;
	else {
	 PTRChuyenBay Last ;
	 for (Last = FirstCB; Last->next!=NULL; Last=Last->next );
	 Last->next=p;
	}
}

NodeChuyenBay * KiemTraMaMBTrung(LISTMayBay &dsMB, char *macb) {
	PTRChuyenBay p;
	for ( int i =0 ; i <dsMB.n ; i++)
	  for (p = dsMB.nodes[i].FirstMB; p!=NULL; p=p->next)
	    if (stricmp(p->CB.MaChuyenBay,macb)==0) return p;
	return NULL;
}

void LietKe_DaSach_ChuyenBay(LISTMayBay mb)
{
	PTRChuyenBay p;
		for ( int i =0 ; i <mb.n ; i++)
  	    {
  	    	cout << "\nMay Bai Co So Hieu : " << mb.nodes[i].SoHieu;
  	    	cout << "\nMay Bai Loai       : " << mb.nodes[i].Loai;
  	    	cout << "\nMay Bai Co So Cho  : " << mb.nodes[i].SoCho << endl;
  	    for (p = mb.nodes[i].FirstMB; p!=NULL; p=p->next)
        { 
             cout << "So Hieu MB : " << p->CB.SoHieu;
             cout << "Ma Chuyen Bay : " << p->CB.MaChuyenBay;
             cout << "Ngay : " << p->CB.Ngay;
             cout << "Thang : " << p->CB.Thang;
             cout << "Nam : " << p->CB.Nam;
             cout << "Gio : " << p->CB.Gio;
             cout << "Phut : " << p->CB.Phut;
             cout << "Trang Thai : " << p->CB.TrangThai;     
        }  	    
		  }
}


 void Nhap_ChuyenBay (LISTMayBay &dsMB) {	
     
    ChuyenBay cb;
    int line=0; 
    char Sohieu[11];
    int soluong=0,dem=0;
      	gotoxy(45,5);
       cout << "So Hieu May Bay Muon Tao : "; 
	  fflush(stdin) ; gets(cb.SoHieu);
	  int vtMB = Search_MayBay(dsMB,cb.SoHieu);
    if   (vtMB ==-1)  
	{ 
	Baoloi("Ma Chuyen Bay khong co trong danh lop.");
	  return;
	} 
 	gotoxy(45,6);
	 cout << "Ban Muon Lap Bao Nhieu Chuyen Bay : ";
	  int n,k=0;
   string text[1]={""};
     while((n = getch()) != 13 )
     {           
     	if(n>='0'&&n<='9')
       {
       	k=n;
       	k=k-48;
       	cout << k;
       	text[0]+=char(n); 		     
	   }   
	     if(n==key_back){	    
					if(text[0].length()>0){	
						text[0].erase(text[0].length()-1,1);
						cout<<"\b \b";
					}				 
				} 			   
	 } 
	 soluong= atoi(text[0].c_str()); 
	while (dem!=soluong) {
		 
   
    	do
	{	 
	 	gotoxy(45,7+line);
		cout << "Ma Chuyen Bay :"; 
		fflush(stdin) ; gets(cb.MaChuyenBay);
	 
     if (stricmp(cb.MaChuyenBay,"")==0) 
		{				 
			gotoxy(45,26);
			cout << "Nhap Thong Tin Chua Day Du ";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                               ";
		}
	}
	while(  stricmp(cb.MaChuyenBay,"")==0  );
	
	  if (stricmp(cb.MaChuyenBay,"")==0) break;
	  if (KiemTraMaMBTrung(dsMB,cb.MaChuyenBay) !=NULL )
	  { 
	  
	  Baoloi("Ma May Bay ban nhap bi trung. Hay nhap lai.");
	    continue;
	  }  
	  gotoxy(45,8+line);
      cout << "Ngay : ";
      cin >> cb.Ngay;
      gotoxy(45,9+line);
      cout << "Thang : ";
      cin >> cb.Thang;
      gotoxy(45,10+line);
      cout << "Nam : ";
	  cin >> cb.Nam;
	  gotoxy(45,11+line);
	  cout << "Gio : ";
	  cin >> cb.Gio;
	  gotoxy(45,12+line);
	  cout << "Phut : ";
	  cin >> cb.Phut;
	  gotoxy(45,13+line);
	  cout << "San Bay Den : ";
	  fflush(stdin) ; gets(cb.SanBayDen);
	  gotoxy(45,14+line);
	  cout << "Trang Thai : ";
	  cin >> cb.TrangThai;
	 
  
	  Insert_Last_ChuyenBay(dsMB.nodes[vtMB].FirstMB, cb);
	  
	  dem++;
	  line+=8;
	}
}

void Level_STT(Tree Root )
{
 
        queue<Tree> q;
        Tree p;
        int dem=0;
        if (Root == NULL) return ;
        p = Root;
        q.push(p);
      
        while (!q.empty())
        {
                p = q.front();
                q.pop();         
        dem+=1;
        gotoxy(46,8+dem);
        cout << dem;
        gotoxy(55,8+dem);
        cout << dem;
        gotoxy(69,8+dem);
        cout << p->HK.CMND;
         gotoxy(85,8+dem);
        cout << p->HK.Ho << " " << p->HK.Ten;
        gotoxy(109,8+dem);
        cout << p->HK.Phai;
             
 
                if (p->Left) q.push(p->Left);
                if (p->Right) q.push(p->Right);
         
        }
}

void SuaTT_ChuyenBay(LISTMayBay &dsMB)
{
	int ngay=0 , thang =0, nam =0, gio =0 ,phut =0 ;
    char macb_edit[11];
            
    do
	{	 
	   gotoxy(45,5);		 
		cout << "Ma Chuyen Bay muon sua:";
		fflush(stdin) ; gets(macb_edit);
	 if (stricmp(macb_edit,"")==0) 
		{
			gotoxy(45,26);
			cout << "Nhap Thong Tin Chua Day Du ";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                               ";
		}
	}
	while(stricmp(macb_edit,"")==0);
                     
	       NodeChuyenBay* p=KiemTraMaMBTrung(dsMB, macb_edit);
	       if(p==NULL)
	       {
	       	Baoloi("Ma May Bay Khong Ton Tai.");
	       	return ;
		   }  
    	 
		 gotoxy(45,6);
		cout << "Thay Doi Thoi Gian Bay :";
		 gotoxy(45,7);
           cout << "Ngay :";
           cin >> ngay;	 
 
	p->CB.Ngay = ngay;
      
  gotoxy(45,8);
	        cout << "Thang  :"; 
	        cin >> thang;
	  p->CB.Thang = thang;
     gotoxy(45,9);
	         cout << "Nam  :";
	         cin >> nam;
	 
	  p->CB.Nam = nam;
    gotoxy(45,10);
	        cout << "Gio  :";  
	        cin >> gio;
	 p->CB.Gio = gio;
  gotoxy(45,11);
	        cout << "Phut  :"; 
	        cin >> phut;
	 p->CB.Phut = phut;
	        
	        gotoxy(45,26);
	  cout << "Thay Doi Thanh Cong\n\n";
	  system("pause");
             
}

 int Delete_info(PTRChuyenBay &FirstMB,char *macb)
{ PTRChuyenBay p=FirstMB; PTRChuyenBay q;
  if (FirstMB==NULL ) return 0;
  if (stricmp(FirstMB->CB.MaChuyenBay ,macb )==0) {
     p=FirstMB;
	 FirstMB = p->next ;
	 delete p ; return 1;
  }
  for ( p=FirstMB;p->next!=NULL && stricmp(p->next->CB.MaChuyenBay ,macb )!=0; p=p->next) ;
  if (p->next!= NULL ) {
		q=p->next; 
		p->next=q->next;
		delete q; return 1;
	}
  return 0;
}
int Xoa_MayBay(LISTMayBay &dsMB, char *macb) {

	for (int i=0 ; i< dsMB.n ; i++)
	  if ( Delete_info(dsMB.nodes[i].FirstMB,macb)==1)
	     return 1;
	return 0;     
}
void Xoa_MayBay_function(LISTMayBay &dsMB)
{
		char MaMB[11];
	int checkdelete=0;
	 
	gotoxy(45,5);
	cout << "Ma Chuyen Bay Muon Huy : ";
            fflush(stdin) ; gets(MaMB);
            checkdelete = Xoa_MayBay(dsMB,MaMB);
            if(checkdelete == 1)
          {
          	gotoxy(45,26);
  	           cout << "Xoa thanh cong.\n\n\n";
  	           system("pause");
          }
          else
          {
          	gotoxy(45,26);
          	cout << "Ma Chuyen Bay Khong Ton Tai. \n\n\n";
  	           system("pause");
		  }
}

//   Hanh Khach
 
 void outItem(HanhKhach x) {
      cout << "                      "  <<x.CMND << "                    " << x.Ho << " " <<  x.Ten << "              " << x.Phai << endl;
} 

void LNR(Tree T) {

    if (T != NULL) {
        LNR(T->Left);
        outItem(T->HK);
        LNR(T->Right);
    }
}
 
int Search_ViTri_ChuyenBay(LISTMayBay &dsMB, char *macb)
{
		PTRChuyenBay p;
		for ( int i =0 ; i <dsMB.n ; i++)
	  for (p = dsMB.nodes[i].FirstMB; p!=NULL; p=p->next)
	    if (stricmp(p->CB.MaChuyenBay,macb)==0) return i;
	return 100;
}
 
 // Cau C vd Cau^ D dùng chung cái show nay`
void LietKe_ChuenBay_HanhKhach(LISTMayBay &dsMB , char* maCB) {
	PTRChuyenBay p;  
	Tree pp;
 
	 int vtMB=Search_ViTri_ChuyenBay(dsMB,maCB);
     if(vtMB==100)
     {
     	Baoloi("Ma Chuyen Bay Khong Ton Tai \n\n\n\n\n\n\n\n\n\n\n");
     	return ;
	 }
           
 
	
 for (p = dsMB.nodes[vtMB].FirstMB; p!=NULL; p=p->next)
    {
    	gotoxy(60,6);
    	  cout << "Danh Sach Hanh Khach Thuoc Chuyen Bay " << p->CB.MaChuyenBay;
    	  gotoxy(60,7);
		  cout << "Ngay Gio Khoi Hanh : " << p->CB.Ngay <<"/"<< p->CB.Thang <<"/"<< p->CB.Nam << " Noi Den : "<<p->CB.SanBayDen;
         pp =p->CB.FirstTree;   
		  gotoxy(45,8);
		  cout << "STT     So Ve           So CMND             Ho Ten           Gioi Tinh ";	 
  	    Level_STT(pp);
   
 }
 
 cout << "\n\n\n";
} 
 
int insertNode(Tree &T, HanhKhach x) {
    if (T != NULL) {
        if (T->HK.CMND == x.CMND)
            return -1;   
        if (T->HK.CMND > x.CMND)
            return insertNode(T->Left, x);  
        else if (T->HK.CMND < x.CMND)
            return insertNode(T->Right, x);   
    }
    T = (NodeHanhKhach *) malloc(sizeof(NodeHanhKhach));
    if (T == NULL)
        return 0;    
    T->HK = x;
    T->Left = T->Right = NULL;
    return 1;    
}

Tree SearchCMND(Tree T, int hk)     
{
 
   Tree P;
   P = T;
   
   while (P != NULL && P->HK.CMND != hk) 
   	    if(hk < P->HK.CMND)
   	    P = P->Left;
   	    else
   	    P = P->Right;  	    
  return(P); 
}

int Level(Tree Root,int cmnd )
{
 
        queue<Tree> q;
        Tree p;
        if (Root == NULL) return 0;
        p = Root;
        q.push(p);
      
        while (!q.empty())
        {
                p = q.front();
                q.pop();         
        if(p->HK.CMND == cmnd )
        return 1;
        else
        return 0;
        
 
                if (p->Left) q.push(p->Left);
                if (p->Right) q.push(p->Right);
         
        }
}

 

void NhapTT_HanhKhach_DatVe(LISTMayBay &dsMB){
	ChuyenBay cb;
	HanhKhach hk;
//	LietKe_DaSach_ChuyenBay(dsMB);ss
//	
//	cout << "Hanh Khach Xem Thong Tin Chuyen Bay de Dat Ve : ";
	 	do
	{	 
		gotoxy(45,5);
		cout << "Ma Chuyen Bay :"; 
		fflush(stdin) ; gets(cb.MaChuyenBay);
	 
     if (stricmp(cb.MaChuyenBay,"")==0) 
		{		
		gotoxy(45,26);
			cout << "Nhap Thong Tin Chua Day Du ";
				Sleep(1000);
		gotoxy(45,26);
		cout << "                               ";	
		}
	}
	while(  stricmp(cb.MaChuyenBay,"")==0  );
	
	   
	  if (KiemTraMaMBTrung(dsMB,cb.MaChuyenBay) ==NULL )
	  {   
	  Baoloi("Ma May Bay Ban Nhap Khong Ton Tai.");
	  return;	     
	  }
	  
	  PTRChuyenBay ptr=KiemTraMaMBTrung(dsMB,cb.MaChuyenBay);
	  
	  gotoxy(45,6);
	  cout << "So CMND : ";   cin >> hk.CMND;
	  // Dang Bi loi 
      int a = Level(ptr->CB.FirstTree, hk.CMND);
	  if( a == 1)
	  {
 
	  	    Baoloi("Ban Da Dat Ve Tren Chuyen Nay.");
	  	    LietKe_ChuenBay_HanhKhach(dsMB , cb.MaChuyenBay);
	  	    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	  	    system("pause");
			 return ;	  	  	  	  
	  }
	  else 
	  {
	  	 gotoxy(45,7);
	  cout << "Ho : ";   fflush(stdin) ; gets(hk.Ho);
	  gotoxy(45,8);
	  cout << "Ten : ";   fflush(stdin) ; gets(hk.Ten);
	  gotoxy(45,9);
	  cout << "Phai : ";   fflush(stdin) ; gets(hk.Phai);
	  
	  insertNode(ptr->CB.FirstTree , hk);
	  }
	  
	   
}

 

int Search_SoLuong_HanhKhach(Tree Root){
	 queue<Tree> q;
        Tree p;
        int dem=0;
 
        if (Root == NULL) return 0;
 
        p = Root;
        q.push(p);
 
        while (!q.empty())
        {
                p = q.front();
                q.pop();   
				 
                	dem++;
 
                if (p->Left) q.push(p->Left);
                if (p->Right) q.push(p->Right);
         
        }
       
         return dem;
}

void Tim_ChuyenBay_ConTrong(LISTMayBay &dsMB) {
	PTRChuyenBay p;  
	Tree pp;
    char maCB[21]="";
     gotoxy(45,5);
    cout << "Nhap Ma Chuyen Bay Muon Tim Ghe Trong : ";
     fflush(stdin) ; gets(maCB);
	 int vtMB=Search_ViTri_ChuyenBay(dsMB,maCB);
	 if(vtMB==100)
     {
     	Baoloi("Ma Chuyen Bay Khong Ton Tai \n\n\n\n\n\n\n\n\n\n\n");
     	return ;
	 }
    gotoxy(45,6);
  	      cout << "May Bai Co So Hieu : " << dsMB.nodes[vtMB].SoHieu;
  	gotoxy(45,7);
			cout << "May Bai Loai       : " << dsMB.nodes[vtMB].Loai;
  	gotoxy(45,8);
			  cout << "May Bai Co So Cho  : " << dsMB.nodes[vtMB].SoCho << endl;
	
 for (p = dsMB.nodes[vtMB].FirstMB; p!=NULL; p=p->next)
    {
       int slhk = Search_SoLuong_HanhKhach(p->CB.FirstTree);
			  	    if( slhk >= dsMB.nodes[vtMB].SoCho){
			  	    	//het ve
					  }
					  else{
					  	  int TongVeTrong = dsMB.nodes[vtMB].SoCho - slhk;
					  	gotoxy(45,9);
					  	cout << "So Hieu MB    Ma CB        Thoi Gian       Noi Den     So Ve Trong     ";
	gotoxy(47,10);
	cout  << p->CB.SoHieu; 
	gotoxy(58,10);
	cout << p->CB.MaChuyenBay; 
	gotoxy(71,10);
	cout << p->CB.Ngay <<"/" << p->CB.Thang <<"/" << p->CB.Nam << " "<<p->CB.Gio<<":"<<p->CB.Phut;
	gotoxy(87,10);
	cout <<p->CB.SanBayDen;
	gotoxy(103,10);
	cout << TongVeTrong;
					  }
   
 }
 
 cout << "\n\n\n";
} 

//cau e 
void LietKe_VeTrong_TheoNgay(LISTMayBay &dsMB){
	ChuyenBay cb;
		int line=0;
	gotoxy(45,5);
	cout << "Nhap Thong Tin De Tim Ve Trong : "; 
	gotoxy(45,6);
	  cout << "Ngay : ";
      cin >> cb.Ngay;
      gotoxy(45,7);
      cout << "Thang : ";
      cin >> cb.Thang;
      gotoxy(45,8);
      cout << "Nam : ";
	  cin >> cb.Nam;
	  gotoxy(45,9); 
	  cout << "San Bay Den : ";
	  fflush(stdin) ; gets(cb.SanBayDen);
	  
	   
	  	
	  	PTRChuyenBay p;
		for ( int i =0 ; i <dsMB.n ; i++)
		{
		   for (p = dsMB.nodes[i].FirstMB; p!=NULL; p=p->next)
			{
			  	if( (p->CB.Ngay == cb.Ngay) && (p->CB.Thang == cb.Thang) && (p->CB.Nam == cb.Nam) && (strcmp(p->CB.SanBayDen,cb.SanBayDen)==0))			  	
			  	{
			  	    int slhk = Search_SoLuong_HanhKhach(p->CB.FirstTree);
			  	    if( slhk >= dsMB.nodes[i].SoCho){
			  	    	//het ve
					  }
					  else{
					   
					  	int TongVeTrong = dsMB.nodes[i].SoCho - slhk;
					  	gotoxy(45,10);
					  	cout << "So Hieu MB    Ma CB        Thoi Gian       Noi Den     So Ve Trong     ";
	gotoxy(47,11+line);
	cout  << p->CB.SoHieu; 
	gotoxy(58,11+line);
	cout << p->CB.MaChuyenBay; 
	gotoxy(71,11+line);
	cout << p->CB.Ngay <<"/" << p->CB.Thang <<"/" << p->CB.Nam << " "<<p->CB.Gio<<":"<<p->CB.Phut;
	gotoxy(87,11+line);
	cout <<p->CB.SanBayDen;
	gotoxy(103,11+line);
	cout << TongVeTrong;
					  	line+=1;
 
					  }
			  	   
			  	    
				}
				else {
					 
	           	Baoloi("Chuyen Bay Khong Ton Tai.");
	           	return ;
	                }
			}
		      
	   }
	                
	 
	  
}
int Dem_SoLuong_ChuyenBay(LISTMayBay dsMB){
  int mang[51]={0},i=0,j=0,max=0,t=0;
  int line=0,line1=0;
 string na[51];
	PTRChuyenBay p;
	int slb=0;
		for ( int i =0 ; i < dsMB.n ; i++)
  	    { 	   
		  slb=0;  
  	    for (p = dsMB.nodes[i].FirstMB; p!=NULL; p=p->next)
        { 
        slb++;
              mang[i] = slb;
              na[i]=dsMB.nodes[i].SoHieu;
        }  	    
		  }
		  
		  
// Sap Xep

    for(i=0 ; i <  dsMB.n - 1 ; i++){
		max = i;
		for(j=i+1 ; j <  dsMB.n  ; j++){
			if( mang[j] > mang[max])
			max = j;
		}
		if( max != i){
			t = mang[max];
			mang[max] = mang[i];
			mang[i] = t;
		}
	}		  
	// show ra cau g
	int dem=0;
	gotoxy(45,5);
	cout << "So Hieu May Bay";
	gotoxy(80,5);
	cout << "So Luot Thuc Hien Chuyen Bay";
		for ( int i =0 ; i < dsMB.n ; i++)
  	    {
  	    	for ( int j = 0 ; j < dsMB.n ; j++)
  	      {
  	      	dem=0;
  	      	for (p = dsMB.nodes[j].FirstMB; p!=NULL; p=p->next)
            { 
             dem++;
                
            } 
            if(dem == mang[i])
               {
            		gotoxy(50,6+line);
		         cout  << dsMB.nodes[j].SoHieu; 
		        
	              line+=1;	   
		     	}
  	      }
  	    	
		    
 
  	    }
		  	
		 for(i=0 ; i< dsMB.n;i++){
		 		gotoxy(90,6+line1);
	 	cout <<  mang[i] ;
	 	 line1+=1;	
	 }
 
}
int DemMB(PTRChuyenBay FirstCB){
	int dem=0;
	for (PTRChuyenBay p=FirstCB; p!=NULL; p=p->next)
	  dem++;
	return dem ; 
  	
}

 

void SaveFileMB (LISTMayBay &dsMb, char *tenfile){
  FILE *f;
  Tree Root;
  f= fopen(tenfile,"wb");
  if (f==NULL) {
    Baoloi( "Khong the mo file."); 
    return ;
  }
  int siso; PTRChuyenBay pp;
   int mh[21],dem=0,dem1;
  
  fwrite(&dsMb.n,sizeof(int),1,f);
  for (int i=0 ; i < dsMb.n; i++)
  {
  	fwrite(&dsMb.nodes[i],sizeof(MayBay),1,f);
  	siso=DemMB(dsMb.nodes[i].FirstMB);
  	fwrite(&siso,sizeof(int),1,f);
  	for (pp=dsMb.nodes[i].FirstMB; pp!=NULL; pp=pp->next)
  	   {
  	   	 dem1=0;
  	   	fwrite(&pp->CB,sizeof(ChuyenBay),1,f);
  	   	    Root = pp->CB.FirstTree;
  	   	   	queue<Tree> q;
        Tree p;
        if (Root == NULL) return;
        p = Root;
        q.push(p);
          
        while (!q.empty())
        {
                p = q.front();
                q.pop();
			  dem1++;
			  	 
                if (p->Left) q.push(p->Left);
                if (p->Right) q.push(p->Right);       
        }
         mh[dem]=dem1;
    
  		fwrite(&mh[dem],sizeof(int),1,f);
  		
  		 p = Root;
  		q.push(p);
          while (!q.empty())
        {
                p = q.front();
                q.pop();
				fwrite(&p->HK ,sizeof(HanhKhach),1,f);			 		
                if (p->Left) q.push(p->Left);
                if (p->Right) q.push(p->Right);       
        }
        dem++;
        
        
		 }
  }
  fclose(f);
}
void LoadFileMB (LISTMayBay &dsMb, char *tenfile){
  FILE *f;
  f= fopen(tenfile,"rb");
  if (f==NULL) {
    Baoloi( "Khong the mo file."); 
    return ;
  }
  int siso,i, j ,n,k; MayBay L; HanhKhach hk ;PTRChuyenBay pp ;
  ChuyenBay cb;
  	   int dem;
  int mh[21];
  fread(&dsMb.n,sizeof(int),1,f);
  for (i=0 ; i < dsMb.n ;i++) {
  	
    fread(&L,sizeof(MayBay),1,f);
    L.FirstMB=NULL;
    dsMb.nodes[i]=L; 
   	fread(&siso,sizeof(int),1,f);
  	for ( j=1; j <=siso; j++)
  	{ 
  	
	  dem=0; 
	  fread(&cb,sizeof(ChuyenBay),1,f);
  	  Insert_Last_ChuyenBay(dsMb.nodes[i].FirstMB, cb);	 
			 fread(&mh,sizeof(int),1,f);    
  	  	pp = KiemTraMaMBTrung(dsMb, cb.MaChuyenBay );
	   cb.FirstTree=NULL;
	   pp->CB=cb; 
  	for (k=0;k<mh[dem];k++)
  	{ 
  	 
	  fread(&hk,sizeof(HanhKhach),1,f);	  
			 insertNode(pp->CB.FirstTree, hk);
			  
  	}
  	dem++;
  	}
  	 
  }
  
  dsMb.n=i;
  fclose(f);
}

void Start(LISTMayBay &mb,char* link,int ch){
	int chon=0,slot=0;
	int tonghk=0;
	int check=0;
	while  (1) 
	{
		 chon = MenuDong_MayBay(menu_MayBay,slot);
		 
		if(chon==1)
		{
		  	 slot=chon-1;
		  	 Nhap_MayBay(mb);		  	 			   
		}
		if(chon==2)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	Nhap_ChuyenBay(mb);
			   
		}
		if(chon==3)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 NhapTT_HanhKhach_DatVe(mb);
			   tonghk+=1;
		}
			if(chon==7)
		{
		  	 slot=chon-1;
		  	 ChuyenBay cb;
		  	 color_intro();
		  	 gotoxy(45,5);
		  	 cout << "Nhap Ma Chuyen bay De Xem Thong Tin : ";
		  	   fflush(stdin) ; gets(cb.MaChuyenBay);
		   LietKe_ChuenBay_HanhKhach(mb , cb.MaChuyenBay);
		    cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		   system("pause");
			   
		}
			if(chon==8)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	LietKe_VeTrong_TheoNgay(mb);
		  	 cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
			   
		}
			if(chon==9)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 	Tim_ChuyenBay_ConTrong(mb);
		  	 	 cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		  	 	system("pause");
			   
		}
			if(chon==10)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 	Dem_SoLuong_ChuyenBay(mb);	
				   cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";	  	 
		  	 system("pause");
			   
		}
			if(chon==13)
		{
		  	 slot=chon-1;	
			   color_intro();	   
		  	  SuaTT_MayBay(mb);
			   
		}
			if(chon==14)
		{
		  	 slot=chon-1;
		  	 color_intro();
		   	 SuaTT_ChuyenBay(mb);
			   
		}
			if(chon==18)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 xoa_MayBay(mb);
			   
		}
			if(chon==19)
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 Xoa_MayBay_function(mb);
		}
			 
		if(chon == 20)	 
		{
		  	 slot=chon-1;
		  	 color_intro();
		  	 Xoa_MayBay_function(mb);
		}
		
		if(chon==22)
			   return ;
 
			SaveFileMB(mb,link);
	}
}
 
 

 
 
int main(){
	LISTMayBay mb;
	int ch=0;
  char* Link="C:\\Users\\DUC SKT\\Desktop\\bobo\\MayBay.txt";
  //   LoadFileMB(mb,Link);

    TestResize();
  	resizeConsole(1400,800);
      XoaManHinh();  
   Start(mb,Link,ch);
 
	return 0;
}


 
