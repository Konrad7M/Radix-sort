#include <iostream>
#include <math.h>

using namespace std;


struct cell		//DEKLARACJA STRUKTURY KOMORKI
{
	
	int numer;
	
	char val;
	
	int srt_n;
	
	int x_val;
	
	int y_val;
	
	cell * north;
	
	cell * west;
	
	cell * east;
	
	cell * south;
	
	cell() :east(NULL),west(NULL),north(NULL),south(NULL),val('0'),x_val(0),y_val(0),numer(0),srt_n(0){	};
};



class Board			//KLASA SZACHOWNICY
{
	
	
	friend  class Tracker;
	
	public:
cell *zero_cell;	// NW cell

cell *north_east;

cell* south_west;

cell* south_east;

int MAX_X;	

int MAX_Y;	

int notfirst;
	
cell * ptr;	

cell * ptr_temp;
	
public:
	
Board(int MAX_X,int MAX_Y)	:MAX_X(0),MAX_Y(0)			//KONSTRUKTOR
{
zero_cell=new cell;

ptr=zero_cell;

notfirst=0;
int i;

for(i=1;i<MAX_X;i++)
	add_kolumn();
	
	for(i=1;i<MAX_Y;i++)
	add_row();




}


~Board()												//Destruktor
{
	int i,x;
x=MAX_Y;	
	
	for(i=0;i<=x;i++)
		{
			
			delete_row();
				
			
		}	
			
				
			
			delete zero_cell;	
				
			if(zero_cell==NULL)
			cout<<"sukces";	
				
			zero_cell=NULL;
				
			
	
	
}

void print_chessboard()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;
	
	wsk_5=wsk_4=zero_cell;

while(wsk_5)
{

while(wsk_4)	
	{
	cout<< "["<<wsk_4->x_val<<" "<<wsk_4->y_val<<"] ";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}

void print()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;
	
	wsk_5=wsk_4=zero_cell;

while(wsk_5)
{

while(wsk_4)	
	{
	cout<< "["<<wsk_4->srt_n<<"] ";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}

void clear()			//wyzeruj
{
	cell *wsk_4;
	cell *wsk_5;
	
	wsk_5=wsk_4=zero_cell;

while(wsk_5->south)
{

while(wsk_4)	
	{
	wsk_4->srt_n=wsk_4->numer=0;
	wsk_4->val='0';
	
	wsk_4=wsk_4->east;
	}

	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}
	

void add_kolumn()	//DODAWANIE KOLUMN
{
	



	cell * wsk_4;
	cell *wsk_5;	

wsk_4=wsk_5=zero_cell;

while(wsk_4->east)
{
wsk_4=wsk_4->east;
}



north_east=wsk_4->east=new cell;
	
wsk_5=wsk_4;

wsk_4=wsk_4->east;

wsk_4->west=wsk_5;

wsk_4->x_val=wsk_4->west->x_val+1;
wsk_4->y_val=0;
	
wsk_5=wsk_5->south;

	if(notfirst==1)
	while(wsk_5)

		{
			ptr_temp=wsk_4;
			wsk_4->south=new cell;
		
			wsk_4=wsk_4->south;
		
		
			wsk_4->west=wsk_5;
			wsk_4->north=ptr_temp;
			wsk_5->east=wsk_4;
	
			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;
			
			wsk_5=wsk_5->south;
			south_east=wsk_4;
		}
		else
		south_east=north_east;

	
	if(notfirst==0){notfirst=1;	}
	
	

MAX_X++;

}



void add_row()		//DODAWANIE SZEREGOW
{
	
		


	cell * wsk_4;

	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;	


while(wsk_4->south)
{
wsk_4=wsk_4->south;
}

wsk_4->south=new cell;
	
wsk_5=wsk_4;

south_west=wsk_4=wsk_4->south;

wsk_4->north=wsk_5;

wsk_4->y_val=wsk_4->north->y_val+1;
wsk_4->x_val=0;
	
wsk_5=wsk_5->east;

	if(notfirst==1)
	while(wsk_5)
	
		{
			ptr_temp=wsk_4;
			wsk_4->east=new cell;
		
			wsk_4=wsk_4->east;
		
		
			wsk_4->north=wsk_5;
			wsk_4->west=ptr_temp;
			wsk_5->south=wsk_4;
	
			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;
			
			south_east=wsk_4;
			
			wsk_5=wsk_5->east;
		
		}

	
if(notfirst==0){notfirst=1;south_east=south_west;	}
	

MAX_Y++;

	
}



void delete_row()					//USUWANIE SZEREGOW
{
	
cell *wsk_4;	
	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;		
		
	while(wsk_4->south)
	{	
		wsk_4=wsk_4->south;
	}
	
	wsk_5=wsk_4;
	
	south_west=wsk_4->north;
	
	

	while(wsk_4)
	{
		
	if(wsk_4->north!=NULL)
		wsk_4->north->south=NULL;
		
if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}
		
		south_east=wsk_5;
		wsk_5=wsk_4->east;
		
		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
		
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;	
	}


MAX_Y--;

}

	

void delete_kolumn()						//USUWANIE KOLUMN
{
	cell *wsk_4;	
	cell *wsk_5;
	
	wsk_4=wsk_5=zero_cell;	
		
	while(wsk_4->east)
{
wsk_4=wsk_4->east;
}

north_east=wsk_4;
	
	wsk_5=wsk_4;
	

	while(wsk_4)
	{
	if(wsk_4->west!=NULL)
		wsk_4->west->east=NULL;
		
		if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}
		
		south_east=wsk_5->west;
		
		wsk_5=wsk_4->south;
		
		
		
		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;	
	}

if(zero_cell==wsk_4)
	{
		notfirst=0;
	
		zero_cell=new cell;
	
		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;
	
		zero_cell->x_val=0;
	
		zero_cell->y_val=0;
	}

	
	MAX_X--;
	
}


		
	
	
};



class Tracker		//KLASA GLOWIC
{



	
int current_x_coordinate;
int current_y_coordinate;
int next_x_coordinate;	
int next_y_coordinate;	


cell * zero_cell;
	
	public:
	
	cell * ptr;
int x_max;
int y_max;	


//Konstrukctor

	Tracker(Board *b)
	{
	ptr=zero_cell=b->zero_cell;
	x_max=b->MAX_X;
	y_max=b->MAX_Y;
	current_x_coordinate=0;//zero->x_val;
	current_y_coordinate=0;//zero->y_val;
		
	}

	~Tracker()
	{
	}
	
//metody

	cell *kom(int next_x_coordinate,int next_y_coordinate)	
	{
	int k,n,i;
	
	if((0>next_x_coordinate)||(next_x_coordinate>x_max)||(next_y_coordinate>y_max)||(0>next_y_coordinate))
	{
		cout<<"Blad nieprawidlowe wspolrzedne tracker nie poruzy sie \n";
		return ptr;
	}
	else
{	

		
		
		k=next_x_coordinate-current_x_coordinate;
		n=next_y_coordinate-current_y_coordinate;
		
		if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
			}
		}
		
		
	}

	
	current_x_coordinate=next_x_coordinate;
	current_y_coordinate=next_y_coordinate;
	
	if(ptr==NULL)
	{
	cout<<"WARNING - out of bounds - ERROR \n";
	}
	
	return ptr;

}

	
	cell* free_track_go(int k,int n)
	{
		
		int i;
		
		
		
		
	if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0;reload_tr(); return ptr;}
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			
			if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}	
		
		current_x_coordinate=ptr->x_val;
		current_y_coordinate=ptr->y_val;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
		
		
			return ptr;
	}
	
	change_tr(cell *input_cel)
	{		
		ptr=zero_cell=input_cel;
		current_x_coordinate=0;//zero->x_val;
		current_y_coordinate=0;//zero->y_val;
	}
	
	reload_tr()
	{
		ptr=zero_cell;
		current_x_coordinate=0;//zero->x_val;
		current_y_coordinate=0;//zero->y_val;
	}
	
	
};

#define nullptr 0

//-------------------------------------------------------------DEKLAROWANIE ZMIENNYCH GLOBALNYCH--------------------------------------------------------





int i,j,x,y,input_variable,menu,board_x_size,board_y_size;



//-----------------------------------------------------------DEKLARACJE FUNKCJI-------------------------------------------------------



void radix(Board &B)			//sortowanie radix
{
	
	//declare column tracker
	
	Tracker column(&B);
	Tracker row(&B);
	Tracker sort(&B);
	
	
	//declare row tracker
	
	
	int j,i,reps,k,dec,d;
	
	dec=10;
	
	reps=1+log10 (abs(sort.kom(0,10)->srt_n));
	
	
	for(j=0;j<reps;j++)
	{
		
		for(i=1;i<=x;i++)
		{
			
			k=(sort.kom(i,10)->srt_n % dec)/(dec/10);
			
			column.kom(0,k)->srt_n++;
			
			row.kom(column.kom(0,k)->srt_n,k)->srt_n=sort.kom(i,10)->srt_n;




		}
		//wrzucamy zaw wszystkich szeregow do ostatniego szeregu
		
		B.print();
		
		cout<<"\n\n";
		
		k=1;
		
		for(i=0;i<=9;i++)
		{
			for(d=1;d<=column.kom(0,i)->srt_n;d++)
			{
				
				
				sort.kom(k++,10)->srt_n=row.kom(d,i)->srt_n;
				
			}
			
		}
		
		for(i=0;i<=9;i++)
			column.kom(0,i)->srt_n=0;
		
		dec=dec*10;
		
		
			B.print();
		
		cout<<"\n\n";
	}

}


	
	//-------------------------------------------------------------MAIN-------------------------------------------------------
	

int main()

{
	
//-------------------------------------------------------------deklaracja pierszej komorki--------------------------------------------------------
	
	
	
	
	
	
	
	
//-------------------------------------------------------------wczytanie parametrow--------------------------------------------------------	
	
	
	
	cout<<" podaj ilosc liczb do sort \n";
	
	cin>>x;
	
	
	int prev;
	
	prev=0;
	
	Board b_1(x+2,11);
	
	
	
	Tracker t_1(&b_1);
	
	t_1.kom(0,10)->srt_n=x;
	
	for(i=1;i<=x;i++)
	{
		
		cout<<"podaj liczbe\n";
		
		cin>>y;
		
		t_1.kom(i,10)->srt_n=y;
		
		if(abs(y)>abs(prev))
		{
			t_1.kom(0,10)->srt_n=prev=abs(y);
		}
		
		
	}
	
	

//---------------------------------TUTAJ JEST MENU-------------------------------------------------------------

int holder;

holder=1;
while(holder==1)
{
cout<<" Menu : \n";
cout<<" 1.wyswietl \n";
cout<<" 2.wyswietl \n";
cout<<" 3.sortuj \n";
cout<<" 4.dodaj liczbe \n";
cout<<" 20.exit \n";

cin>>menu;

switch(menu)
{
	
		case 1:			//WYSWIETL
		{		
			
			b_1.print_chessboard();
			break;
		}
	
	
		case 2 :		//WYSWIETL
		{	
			
			
		b_1.print();
			
			break;
			
		}
		
		case 3:			//sortoj
		{		
			
		
			radix(b_1);
			
			b_1.clear();
			
			break;
		}
		
		
		case 4:
		{
			
		
			
			break;
		}
		
			case 5:
		{
			
			b_1.clear();
			
			break;
		}
		
		
		
		
		
		
		
		
	case 20:			//WYJSCIE
		{
			
		
			
		holder=0;
		break;
		}
	
	
	
	
	
	
}//koniec swticha
}









	system("PAUSE");
	
	return 0;
}

