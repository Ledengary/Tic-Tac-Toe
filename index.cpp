#include <iostream>
#include <stdlib.h> // RAND & RAND
#include <time.h> // RAND
#include <stdio.h> // isdigit
//#include <windows.h> //BEEP
#include <string> // sstream
#include <sstream> // sstream
#include <fstream> // winners list
#include <ctype.h> // isalpha
using namespace std;
void what_now();
bool free_or_not();
void reset_matris();
string check_movarab();
string check_amud();
string check_ofogh();
string check_win();
bool check_fill();
int j_fill();
void show_matris();
void single_player();
void multi_player();
void start_game();
void winners_list();
void kill();
void main_main();
void nobat_ai();
int ai_fills();
bool check_isalpha();
void insert_winner();
int main(){
	system( "color 8F" );
//  	Beep(523,500);
	main_main();
	return 0;
}
void what_now(){
	cout<<"1 - Menu"<<endl;
	cout<<"0 - Exit"<<endl;
	int last_order;
	cout<<"Please insert the order : ";	cin>>last_order;
	switch( last_order ){
		case 1:
//			Beep(523,500);
			main_main();
			break;
		case 0:
//			Beep(784,500);
			kill();
			break;
		default:
			what_now();
	}
}
bool free_or_not( string ** matris ){
	bool available_or_not = false;
	for( int i = 0 ; i < 3 && !available_or_not ; i++ ){
		for( int j = 0 ; j < 3 ; j++ ){
			if( matris[i][j] != "X" && matris[i][j] != "O" ){
				available_or_not = true;
				break;		
			}
		}
	}
	return available_or_not;
}
void reset_matris( string ** matris ){
	int star_int;
	string star_str;
	stringstream ss1;
	for( int i = 0 ; i < 3 ; i++ ){
		for( int j = 0 ; j < 3 ; j++ ){
			star_int = ( ( 2 * i ) + j ) + ( i + 1 );
			star_str.clear();
			ss1.clear();
			ss1 << star_int;
			ss1 >> star_str;
			matris[i][j] = star_str;
		}
	}
}
string check_movarab( string ** matris , int last_i , int last_j ){
	string movarab = "NA";
	string check_it;
	check_it = matris[0][0];
	if( matris[1][1] == check_it && matris[2][2] == check_it ){
		movarab = matris[0][0];
		return movarab;
	}
	check_it = matris[0][2];
	if( matris[1][1] == check_it && matris[2][0] == check_it ){
		movarab = matris[0][2];
		return movarab;
	}
	return movarab;
}
string check_amud( string ** matris , int last_i , int last_j ){
	string amud = "NA";
	string check_it;
	check_it = matris[0][0];
	if( matris[1][0] == check_it && matris[2][0] == check_it ){
		amud = matris[0][0];
		return amud;
	}
	check_it = matris[0][1];
	if( matris[1][1] == check_it && matris[2][1] == check_it ){
		amud = matris[0][1];
		return amud;
	}
	check_it = matris[0][2];
	if( matris[1][2] == check_it && matris[2][2] == check_it ){
		amud = matris[0][2];
		return amud;
	}
	return amud;
}
string check_ofogh( string ** matris , int last_i , int last_j ){
	string ofogh = "NA";
	string check_it;
	check_it = matris[0][0];
	if( matris[0][1] == check_it && matris[0][2] == check_it ){
		ofogh = matris[0][0];
		return ofogh;
	}
	check_it = matris[1][0];
	if( matris[1][1] == check_it && matris[1][2] == check_it ){
		ofogh = matris[1][0];
		return ofogh;
	}
	check_it = matris[2][0];
	if( matris[2][1] == check_it && matris[2][2] == check_it ){
		ofogh = matris[2][0];
		return ofogh;
	}
	return ofogh;
}
string check_win( string ** matris , int last_i , int last_j ){
	string movarab = check_movarab(matris,last_i,last_j);
	string amud = check_amud(matris,last_i,last_j);
	string ofogh = check_ofogh(matris,last_i,last_j);
	if( movarab == "NA" &&  amud == "NA" && ofogh == "NA" ){
		return "NA";
	}
	else{
		if( movarab != "NA" ){
			return movarab;
		}
		if( amud != "NA" ){
			return amud;
		}
		if( ofogh != "NA" ){
			return ofogh;
		}
	}
}
bool check_fill( int  i_m , int j_m , string ** matris ){
	bool dm = (matris[i_m][j_m] == "X" || matris[i_m][j_m] == "O") ? true : false ;
	return dm;
}
int i_fill( int fill ){
	int i_m;
	if( fill == 1 || fill == 2 || fill == 3 ){
		i_m = 0;
	}
	if( fill == 4 || fill == 5 || fill == 6 ){
		i_m = 1;
	}
	if( fill == 7 || fill == 8 || fill == 9 ){
		i_m = 2;
	}
	return i_m;
}
int j_fill( int fill ){
	int j_m;
	if( fill == 1 || fill == 4 || fill == 7 ){
		j_m = 0;
	}
	if( fill == 2 || fill == 5 || fill == 8 ){
		j_m = 1;
	}
	if( fill == 3 || fill == 6 || fill == 9 ){
		j_m = 2;
	}
	return j_m;
}
void show_matris( string ** matris ){
	int star;
	int i , j;
	// Matris START ------------------------------------------------------------------------------
	cout<<" __________ ___________ ___________"<<endl<<endl;
	for( i = 0 ; i < 3 ; i++ ){
		for( j = 0 ; j < 3 ; j++ ){
			if( j == 0 ){
				cout<<"|          |           |           |"<<endl<<"|";
			}
			cout<<"    "<<matris[i][j]<<"     | ";
			if( j == 2 ){
				cout<<endl<<"|          |           |           |";
			}
		}
		cout<<endl<<" __________ ___________ ___________"<<endl<<endl;
	}
	// Matris END ------------------------------------------------------------------------------	
}
int ai_fills( string ** matris , int first_second ){
	int fill;
	srand(time(0));
	int rand_fill_first;
	if( first_second == 1 ){
		srand(time(0));
		rand_fill_first = 1 + rand() % 4;
		switch( rand_fill_first ){
			case 1:
				fill = 1;
				break;
			case 2:
				fill = 3;
				break;
			case 3:
				fill = 7;
				break;
			case 4:
				fill = 9;
				break;
			default:
				ai_fills( matris , first_second );
		}
	}
	if( first_second == 2 ){
		if( matris[1][1] != "X" ){
			fill = 5;
		}
		else{
			rand_fill_first = 1 + rand() % 8;	
			switch( rand_fill_first ){
				case 1:
					fill = 1;
					break;
				case 2:
					fill = 2;
					break;
				case 3:
					fill = 3;
					break;
				case 4:
					fill = 6;
					break;
				case 5:
					fill = 9;
					break;
				case 6:
					fill = 8;
					break;
				case 7:
					fill = 7;
					break;
				case 8:
					fill = 4;
					break;
				default:
					ai_fills( matris , first_second );
			}		
		}
	}
	else if( first_second == 3 ){
		if( matris[1][1] == "X" ){
			if( matris[0][0] == "O" ){
				fill = 9;
			}
			if( matris[0][2] == "O" ){
				fill = 7;
			}
			if( matris[2][0] == "O" ){
				fill = 3;
			}
			if( matris[2][2] == "O" ){
				fill = 1;
			}
		}
		else{
			if( matris[0][0] == "O" ){
				if( matris[0][2] != "X" && matris[0][1] != "X" ){
					fill = 3;
				}
				else{
					fill = 7;
				}
			}
			if( matris[0][2] == "O" ){
				if( matris[0][0] != "X" && matris[0][1] != "X" ){
					fill = 1;
				}
				else{
					fill = 9;
				}
			}
			if( matris[2][0] == "O"){
				if( matris[2][2] != "X" && matris[2][1] != "X" ){
					fill = 9;
				}
				else{
					fill = 1;
				}
			}
			if( matris[2][2] == "O" ){
				if( matris[2][0] != "X" && matris[2][1] != "X" ){
					fill = 7;
				}
				else{
					fill = 3;
				}
			}
		}
	}
	else if( first_second == 4 ){
		if( matris[1][1] == "X" ){
			bool mistook = false;
			if( matris[0][0] == "X" && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( matris[0][1] == "X" && matris[2][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( matris[0][2] == "X" && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( matris[1][0] == "X" && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( matris[1][2] == "X" && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( matris[2][0] == "X" && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( matris[2][1] == "X" && matris[0][1] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( matris[2][2] == "X" && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( !mistook ){
				if( matris[0][0] == "O"){
					if( matris[0][1] != "X" ){
						fill = 2;
					}
					if( matris[1][0] != "X" ){
						fill = 4;
					}
				}
				if( matris[0][1] == "O"){
					if( matris[0][0] != "X" ){
						fill = 1;
					}
					if( matris[0][2] != "X" ){
						fill = 3;
					}
				}
				if( matris[0][2] == "O"){
					if( matris[0][1] != "X" ){
						fill = 2;
					}
					if( matris[1][2] != "X" ){
						fill = 6;
					}
				}
				if( matris[1][2] == "O"){
					if( matris[0][2] != "X" ){
						fill = 3;
					}
					if( matris[2][2] != "X" ){
						fill = 9;
					}
				}
				if( matris[2][2] == "O"){
					if( matris[1][2] != "X" ){
						fill = 6;
					}
					if( matris[2][1] != "X" ){
						fill = 7;
					}
				}
				if( matris[2][1] == "O"){
					if( matris[2][0] != "X" ){
						fill = 7;
					}
					if( matris[2][2] != "X" ){
						fill = 9;
					}
				}
				if( matris[2][0] == "O"){
					if( matris[1][0] != "X" ){
						fill = 4;
					}
					if( matris[2][1] != "X" ){
						fill = 8;
					}
				}
				if( matris[1][0] == "O"){
					if( matris[0][0] != "X" ){
						fill = 1;
					}
					if( matris[2][0] != "X" ){
						fill = 7;
					}
				}
			}
		}
		else{
			bool mistook = false;
			if( ( matris[0][0] == "X" && matris[2][0] == "X" ) && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][2] == "X" ) && matris[0][1] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[2][2] == "X" ) && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][2] == "X" ) && matris[1][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][1] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[0][1] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[1][0] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[1][0] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][1] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[2][1] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[1][2] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[1][2] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( !mistook ){
				srand(time(0));
				rand_fill_first = 1 + rand() % 4;	
				switch( rand_fill_first ){
					case 1:
						( matris[0][1] != "O" && matris[0][1] != "X" ) ? fill = 2 : ai_fills( matris , first_second );
						break;
					case 2:
						( matris[1][2] != "O" && matris[1][2] != "X" ) ? fill = 6 : ai_fills( matris , first_second );
						break;
					case 3:
						( matris[2][1] != "O" && matris[2][1] != "X" ) ? fill = 8 : ai_fills( matris , first_second );
						break;
					case 4:
						( matris[1][0] != "O" && matris[1][0] != "X" ) ? fill = 4 : ai_fills( matris , first_second );
						break;
					default:
						ai_fills( matris , first_second );
				}
			}
		}
	}
	else if( first_second == 5 ){
		if( matris[1][1] == "X" ){
			if( matris[0][0] == "X" || matris[0][2] == "X" || matris[2][0] == "X" || matris[2][2] == "X" ){
				if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
					return 4;
				}
				if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
					return 2;
				}
				if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
					return 6;
				}
				if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[2][1] != "X" ){
					return 8;
				}
				if( ( matris[0][0] == "O" && matris[0][1] == "O" ) && matris[0][2] != "X" ){
					return 3;
				}
				if( ( matris[0][2] == "O" && matris[0][1] == "O" ) && matris[0][0] != "X" ){
					return 1;
				}
				if( ( matris[0][0] == "O" && matris[1][0] == "O" ) && matris[2][0] != "X" ){
					return 7;
				}
				if( ( matris[2][0] == "O" && matris[1][0] == "O" ) && matris[0][0] != "X" ){
					return 1;
				}
				if( ( matris[2][0] == "O" && matris[2][1] == "O" ) && matris[2][2] != "X" ){
					return 9;
				}
				if( ( matris[2][2] == "O" && matris[2][1] == "O" ) && matris[2][0] != "X" ){
					return 7;
				}
				if( ( matris[0][2] == "O" && matris[1][2] == "O" ) && matris[2][2] != "X" ){
					return 9;
				}
				if( ( matris[2][2] == "O" && matris[1][2] == "O" ) && matris[0][2] != "X" ){
					return 3;
				}
				if( ( matris[1][2] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
					return 4;
				}
				if( ( matris[1][0] == "O" && matris[1][1] == "O" ) && matris[1][2] != "X" ){
					return 6;
				}
				if( ( matris[0][1] == "O" && matris[1][1] == "O" ) && matris[2][1] != "X" ){
					return 8;
				}
				if( ( matris[2][1] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
					return 2;
				}
				if( ( matris[0][0] == "O" && matris[1][1] == "O" ) && matris[2][2] != "X" ){
					return 9;
				}
				if( ( matris[2][2] == "O" && matris[1][1] == "O" ) && matris[0][0] != "X" ){
					return 1;
				}
				if( ( matris[0][2] == "O" && matris[1][1] == "O" ) && matris[2][0] != "X" ){
					return 7;
				}
				if( ( matris[2][0] == "O" && matris[1][1] == "O" ) && matris[0][2] != "X" ){
					return 3;
				}
				if( matris[0][0] == "X" ){
					fill = 9;
				}
				if( matris[0][2] == "X" ){
					fill = 7;
				}
				if( matris[2][0] == "X" ){
					fill = 3;
				}
				if( matris[2][2] == "X" ){
					fill = 1;
				}
			}
			else{
				if( matris[0][1] == "X" ){
					fill = 8;
				}
				if( matris[1][0] == "X" ){
					fill = 6;
				}
				if( matris[1][2] == "X" ){
					fill = 4;
				}
				if( matris[2][1] == "X" ){
					fill = 2;
				}
			}
		}
		else{
			bool mistook = false;
			if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
				return 4;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
				return 2;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
				return 6;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[2][1] != "X" ){
				return 8;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[2][2] == "O" ) && matris[1][1] != "X" ){
				return 5;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[0][2] == "O" ) && matris[1][1] != "X" ){
				return 5;
				mistook = true;
			}
			
			bool mistook2 = false;
			if( ( matris[0][0] == "O" && matris[0][2] == "O"  && matris[0][1] == "X" ) && matris[2][1] == "X" ){
				return 5;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[2][0] == "O" && matris[1][0] == "X" ) && matris[1][2] == "X" ){
				return 5;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" && matris[2][1] == "X" ) && matris[0][1] == "X" ){
				return 5;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" && matris[1][2] == "X" ) && matris[1][0] == "X" ){
				return 5;
				mistook = true;
			}
			
			if( !mistook && !mistook2 ){
				if( matris[2][0] == "O" ){
					if( ( matris[2][1] != "X" && matris[2][1] != "O" ) && ( matris[2][2] != "X" && matris[2][2] != "O" ) ){
						fill = 9;
					}
					if( ( matris[0][0] != "X" && matris[0][0] != "O" ) && ( matris[1][0] != "X" && matris[1][0] != "O" ) ){
						fill = 1;
					}
				}
				if( matris[2][2] == "O" ){
					if( ( matris[0][2] != "X" && matris[0][2] != "O" ) && ( matris[1][2] != "X" && matris[1][2] != "O" ) ){
						fill = 3;
					}
					if( ( matris[2][0] != "X" && matris[2][0] != "O" ) && ( matris[2][1] != "X" && matris[2][1] != "O" ) ){
						fill = 7;
					}
				}
				if( matris[0][0] == "O" ){
					if( ( matris[0][2] != "X" && matris[0][2] != "O" ) && ( matris[0][1] != "X" && matris[0][1] != "O" ) ){
						fill = 3;
					}
					if( ( matris[1][0] != "X" && matris[1][0] != "O" ) && ( matris[2][0] != "X" && matris[2][0] != "O" ) ){
						fill = 7;
					}
				}
				if( matris[0][2] == "O" ){
					if( ( matris[0][0] != "X" && matris[0][0] != "O" ) && ( matris[0][1] != "X" && matris[0][1] != "O" ) ){
						fill = 1;
					}
					if( ( matris[1][2] != "X" && matris[1][2] != "O" ) && ( matris[2][2] != "X" && matris[2][2] != "O" ) ){
						fill = 9;
					}
				}
			}
		}
	}
	else if( first_second == 6 ){
		if( matris[1][1] == "X" ){
			bool mistook = false;
			if( ( matris[0][0] == "X" && matris[2][0] == "X" ) && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][2] == "X" ) && matris[0][1] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[2][2] == "X" ) && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][2] == "X" ) && matris[1][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][1] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[0][1] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[1][0] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[1][0] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][1] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[2][1] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[1][2] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[1][2] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[1][2] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[1][0] == "X" && matris[1][1] == "X" ) && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[0][1] == "X" && matris[1][1] == "X" ) && matris[2][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[2][1] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[1][1] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[1][1] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[1][1] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[1][1] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( !mistook ){
				srand(time(0));
				rand_fill_first = 1 + rand() % 8;	
				switch( rand_fill_first ){
					case 1:
						( matris[0][0] != "O" && matris[0][0] != "X" ) ? fill = 1 : ai_fills( matris , first_second );
						break;
					case 2:
						( matris[0][1] != "O" && matris[0][1] != "X" ) ? fill = 2 : ai_fills( matris , first_second );
						break;
					case 3:
						( matris[0][2] != "O" && matris[0][2] != "X" ) ? fill = 3 : ai_fills( matris , first_second );
						break;
					case 4:
						( matris[1][2] != "O" && matris[1][2] != "X" ) ? fill = 6 : ai_fills( matris , first_second );
						break;
					case 5:
						( matris[2][2] != "O" && matris[2][2] != "X" ) ? fill = 9 : ai_fills( matris , first_second );
						break;
					case 6:
						( matris[2][1] != "O" && matris[2][1] != "X" ) ? fill = 8 : ai_fills( matris , first_second );
						break;
					case 7:
						( matris[2][0] != "O" && matris[2][0] != "X" ) ? fill = 7 : ai_fills( matris , first_second );
						break;
					case 8:
						( matris[1][0] != "O" && matris[1][0] != "X" ) ? fill = 4 : ai_fills( matris , first_second );
						break;
					default:
						ai_fills( matris , first_second );
				}
			}
		}
		else{
			bool mistook = false;
			bool mistook2 = false;
			if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[2][1] != "X" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[0][1] == "O" ) && matris[0][2] != "X" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[0][1] == "O" ) && matris[0][0] != "X" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[1][0] == "O" ) && matris[2][0] != "X" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[1][0] == "O" ) && matris[0][0] != "X" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[2][1] == "O" ) && matris[2][2] != "X" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "O" && matris[2][1] == "O" ) && matris[2][0] != "X" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[1][2] == "O" ) && matris[2][2] != "X" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "O" && matris[1][2] == "O" ) && matris[0][2] != "X" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[1][2] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[1][0] == "O" && matris[1][1] == "O" ) && matris[1][2] != "X" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[0][1] == "O" && matris[1][1] == "O" ) && matris[2][1] != "X" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[2][1] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[1][1] == "O" ) && matris[2][2] != "X" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "O" && matris[1][1] == "O" ) && matris[0][0] != "X" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[1][1] == "O" ) && matris[2][0] != "X" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[1][1] == "O" ) && matris[0][2] != "X" ){
				fill = 3;
				mistook = true;
			}
			if( !mistook ){
				if( ( matris[0][0] == "X" && matris[2][0] == "X" ) && matris[1][0] != "O" ){
					fill = 4;
					mistook2 = true;
				}
				if( ( matris[0][0] == "X" && matris[0][2] == "X" ) && matris[0][1] != "O" ){
					fill = 2;
					mistook2 = true;
				}
				if( ( matris[0][2] == "X" && matris[2][2] == "X" ) && matris[1][2] != "O" ){
					fill = 6;
					mistook2 = true;
				}
				if( ( matris[2][0] == "X" && matris[2][2] == "X" ) && matris[1][1] != "O" ){
					fill = 8;
					mistook2 = true;
				}
				if( ( matris[0][0] == "X" && matris[0][1] == "X" ) && matris[0][2] != "O" ){
					fill = 3;
					mistook2 = true;
				}
				if( ( matris[0][2] == "X" && matris[0][1] == "X" ) && matris[0][0] != "O" ){
					fill = 1;
					mistook2 = true;
				}
				if( ( matris[0][0] == "X" && matris[1][0] == "X" ) && matris[2][0] != "O" ){
					fill = 7;
					mistook2 = true;
				}
				if( ( matris[2][0] == "X" && matris[1][0] == "X" ) && matris[0][0] != "O" ){
					fill = 1;
					mistook2 = true;
				}
				if( ( matris[2][0] == "X" && matris[2][1] == "X" ) && matris[2][2] != "O" ){
					fill = 9;
					mistook2 = true;
				}
				if( ( matris[2][2] == "X" && matris[2][1] == "X" ) && matris[2][0] != "O" ){
					fill = 7;
					mistook2 = true;
				}
				if( ( matris[0][2] == "X" && matris[1][2] == "X" ) && matris[2][2] != "O" ){
					fill = 9;
					mistook2 = true;
				}
				if( ( matris[2][2] == "X" && matris[1][2] == "X" ) && matris[0][2] != "O" ){
					fill = 3;
					mistook2 = true;
				}
				if( ( matris[1][2] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
					fill = 4;
					mistook2 = true;
				}
				if( ( matris[1][0] == "X" && matris[1][1] == "X" ) && matris[1][2] != "O" ){
					fill = 6;
					mistook2 = true;
				}
				if( ( matris[0][1] == "X" && matris[1][1] == "X" ) && matris[2][1] != "O" ){
					fill = 8;
					mistook2 = true;
				}
				if( ( matris[2][1] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
					fill = 2;
					mistook2 = true;
				}
				if( ( matris[0][0] == "X" && matris[1][1] == "X" ) && matris[2][2] != "O" ){
					fill = 9;
					mistook2 = true;
				}
				if( ( matris[2][2] == "X" && matris[1][1] == "X" ) && matris[0][0] != "O" ){
					fill = 1;
					mistook2 = true;
				}
				if( ( matris[0][2] == "X" && matris[1][1] == "X" ) && matris[2][0] != "O" ){
					fill = 7;
					mistook2 = true;
				}
				if( ( matris[2][0] == "X" && matris[1][1] == "X" ) && matris[0][2] != "O" ){
					fill = 3;
					mistook2 = true;
				}
				if( !mistook2 ){
					
				}
			}
		}
	}
	else if( first_second == 7 ){
		if( matris[1][1] == "X" ){
			bool mistook = false;
			if( ( matris[0][0] == "O" && matris[0][1] == "O") && matris[0][2] != "X" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[0][0] == "O" && matris[1][0] == "O") && matris[2][0] != "X" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[0][2] == "O" && matris[1][2] == "O") && matris[2][2] != "X" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][0] == "O" && matris[2][1] == "O") && matris[2][2] != "X" ){
				fill = 9;
				mistook = true;
			}
			
			if( matris[0][0] != "X" && ( matris[0][1] == "O" && matris[0][2] == "O" ) ){
				fill = 1;
				mistook = true;
			}
			if( matris[0][0] != "X" && ( matris[1][0] == "O" && matris[2][0] == "O" ) ){
				fill = 1;
				mistook = true;
			}
			if( matris[0][2] != "X" && ( matris[1][2] == "O" && matris[2][2] == "X" ) ){
				fill = 3;
				mistook = true;
			}
			if( matris[2][0] != "X" && ( matris[2][1] == "O" && matris[2][2] == "O" ) ){
				fill = 7;
				mistook = true;
			}
			
			bool mistook2 = false;
			if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
				fill = 4;
				mistook2 = true;
			}
			if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
				fill = 2;
				mistook2 = true;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
				fill = 6;
				mistook2 = true;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[1][1] != "X" ){
				fill = 8;
				mistook2 = true;
			}
			
			if( !mistook && !mistook2 ){
				
				if( matris[0][0] == "X" || matris[0][2] == "X" || matris[2][0] == "X" || matris[2][2] == "X" ){
					if( matris[0][0] == "X" ){
						fill = 9;
					}
					if( matris[0][2] == "X" ){
						fill = 7;
					}
					if( matris[2][0] == "X" ){
						fill = 3;
					}
					if( matris[2][2] == "X" ){
						fill = 1;
					}
				}
			}
		}
		else{
			bool mistook2 = false;
			if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
				fill = 4;
				mistook2 = true;
			}
			if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
				fill = 2;
				mistook2 = true;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
				fill = 6;
				mistook2 = true;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[1][1] != "X" ){
				fill = 8;
				mistook2 = true;
			}
			if( ( matris[0][0] == "O" && matris[2][2] == "O" ) && matris[1][1] != "X" ){
				fill = 5;
				mistook2 = true;
			}
			if( ( matris[0][2] == "O" && matris[2][0] == "O" ) && matris[1][1] != "X" ){
				fill = 5;
				mistook2 = true;
			}
			
			bool mistook3 = false;
			if( ( matris[0][0] == "O" && matris[1][1] == "O" ) && matris[2][2] != "X" ){
				fill = 9;
				mistook3 = true;
			}
			if( ( matris[0][2] == "O" && matris[1][1] == "O" ) && matris[2][0] != "X" ){
				fill = 7;
				mistook3 = true;
			}
			if( ( matris[2][0] == "O" && matris[1][1] == "O" ) && matris[0][2] != "X" ){
				fill = 3;
				mistook3 = true;
			}
			if( ( matris[2][2] == "O" && matris[1][1] == "O" ) && matris[0][0] != "X" ){
				fill = 1;
				mistook3 = true;
			}
		}
	}
	else if( first_second == 8 ){
		if( matris[1][1] == "X" ){
			bool mistook = false;
			if( ( matris[0][0] == "X" && matris[2][0] == "X" ) && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][2] == "X" ) && matris[0][1] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[2][2] == "X" ) && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][2] == "X" ) && matris[2][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[0][1] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[0][1] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[1][0] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[1][0] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[2][1] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[2][1] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[1][2] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[1][2] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( ( matris[1][2] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				fill = 4;
				mistook = true;
			}
			if( ( matris[1][0] == "X" && matris[1][1] == "X" ) && matris[1][2] != "O" ){
				fill = 6;
				mistook = true;
			}
			if( ( matris[0][1] == "X" && matris[1][1] == "X" ) && matris[2][1] != "O" ){
				fill = 8;
				mistook = true;
			}
			if( ( matris[2][1] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				fill = 2;
				mistook = true;
			}
			if( ( matris[0][0] == "X" && matris[1][1] == "X" ) && matris[2][2] != "O" ){
				fill = 9;
				mistook = true;
			}
			if( ( matris[2][2] == "X" && matris[1][1] == "X" ) && matris[0][0] != "O" ){
				fill = 1;
				mistook = true;
			}
			if( ( matris[0][2] == "X" && matris[1][1] == "X" ) && matris[2][0] != "O" ){
				fill = 7;
				mistook = true;
			}
			if( ( matris[2][0] == "X" && matris[1][1] == "X" ) && matris[0][2] != "O" ){
				fill = 3;
				mistook = true;
			}
			if( !mistook ){
				srand(time(0));
				rand_fill_first = 1 + rand() % 8;	
				switch( rand_fill_first ){
					case 1:
						( matris[0][0] != "O" && matris[0][0] != "X" ) ? fill = 1 : ai_fills( matris , first_second );
						break;
					case 2:
						( matris[0][1] != "O" && matris[0][1] != "X" ) ? fill = 2 : ai_fills( matris , first_second );
						break;
					case 3:
						( matris[0][2] != "O" && matris[0][2] != "X" ) ? fill = 3 : ai_fills( matris , first_second );
						break;
					case 4:
						( matris[1][2] != "O" && matris[1][2] != "X" ) ? fill = 6 : ai_fills( matris , first_second );
						break;
					case 5:
						( matris[2][2] != "O" && matris[2][2] != "X" ) ? fill = 9 : ai_fills( matris , first_second );
						break;
					case 6:
						( matris[2][1] != "O" && matris[2][1] != "X" ) ? fill = 8 : ai_fills( matris , first_second );
						break;
					case 7:
						( matris[2][0] != "O" && matris[2][0] != "X" ) ? fill = 7 : ai_fills( matris , first_second );
						break;
					case 8:
						( matris[1][0] != "O" && matris[1][0] != "X" ) ? fill = 4 : ai_fills( matris , first_second );
						break;
					default:
						ai_fills( matris , first_second );
				}
			}
		}
		else{
			bool mistook = false;
			bool mistook2 = false;
			if( ( matris[0][0] == "O" && matris[2][0] == "O" ) && matris[1][0] != "X" ){
				return 4;
			}
			if( ( matris[0][0] == "O" && matris[0][2] == "O" ) && matris[0][1] != "X" ){
				return 2;
			}
			if( ( matris[0][2] == "O" && matris[2][2] == "O" ) && matris[1][2] != "X" ){
				return 6;
			}
			if( ( matris[2][0] == "O" && matris[2][2] == "O" ) && matris[1][1] != "X" ){
				return 8;
			}
			if( ( matris[0][0] == "O" && matris[0][1] == "O" ) && matris[0][2] != "X" ){
				return 3;
			}
			if( ( matris[0][2] == "O" && matris[0][1] == "O" ) && matris[0][0] != "X" ){
				return 1;
			}
			if( ( matris[0][0] == "O" && matris[1][0] == "O" ) && matris[2][0] != "X" ){
				return 7;
			}
			if( ( matris[2][0] == "O" && matris[1][0] == "O" ) && matris[0][0] != "X" ){
				return 1;
			}
			if( ( matris[2][0] == "O" && matris[2][1] == "O" ) && matris[2][2] != "X" ){
				return 9;
			}
			if( ( matris[2][2] == "O" && matris[2][1] == "O" ) && matris[2][0] != "X" ){
				return 7;
			}
			if( ( matris[0][2] == "O" && matris[1][2] == "O" ) && matris[2][2] != "X" ){
				return 9;
			}
			if( ( matris[2][2] == "O" && matris[1][2] == "O" ) && matris[0][2] != "X" ){
				return 3;
			}
			if( ( matris[1][2] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
				return 4;
			}
			if( ( matris[1][0] == "O" && matris[1][1] == "O" ) && matris[1][2] != "X" ){
				return 6;
			}
			if( ( matris[0][1] == "O" && matris[1][1] == "O" ) && matris[2][1] != "X" ){
				return 8;
			}
			if( ( matris[2][1] == "O" && matris[1][1] == "O" ) && matris[1][0] != "X" ){
				return 2;
			}
			if( ( matris[0][0] == "O" && matris[1][1] == "O" ) && matris[2][2] != "X" ){
				return 9;
			}
			if( ( matris[2][2] == "O" && matris[1][1] == "O" ) && matris[0][0] != "X" ){
				return 1;
			}
			if( ( matris[0][2] == "O" && matris[1][1] == "O" ) && matris[2][0] != "X" ){
				return 7;
			}
			if( ( matris[2][0] == "O" && matris[1][1] == "O" ) && matris[0][2] != "X" ){
				return 3;
			}
			if( ( matris[0][0] == "X" && matris[2][0] == "X" ) && matris[1][0] != "O" ){
				return 4;
			}
			if( ( matris[0][0] == "X" && matris[0][2] == "X" ) && matris[0][1] != "O" ){
				return 2;
			}
			if( ( matris[0][2] == "X" && matris[2][2] == "X" ) && matris[1][2] != "O" ){
				return 6;
			}
			if( ( matris[2][0] == "X" && matris[2][2] == "X" ) && matris[2][1] != "O" ){
				return 8;
			}
			if( ( matris[0][0] == "X" && matris[0][1] == "X" ) && matris[0][2] != "O" ){
				return 3;
			}
			if( ( matris[0][2] == "X" && matris[0][1] == "X" ) && matris[0][0] != "O" ){
				return 1;
			}
			if( ( matris[0][0] == "X" && matris[1][0] == "X" ) && matris[2][0] != "O" ){
				return 7;
			}
			if( ( matris[2][0] == "X" && matris[1][0] == "X" ) && matris[0][0] != "O" ){
				return 1;
			}
			if( ( matris[2][0] == "X" && matris[2][1] == "X" ) && matris[2][2] != "O" ){
				return 9;
			}
			if( ( matris[2][2] == "X" && matris[2][1] == "X" ) && matris[2][0] != "O" ){
				return 7;
			}
			if( ( matris[0][2] == "X" && matris[1][2] == "X" ) && matris[2][2] != "O" ){
				return 9;
			}
			if( ( matris[2][2] == "X" && matris[1][2] == "X" ) && matris[0][2] != "O" ){
				return 3;
			}
			if( ( matris[1][2] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				return 4;
			}
			if( ( matris[1][0] == "X" && matris[1][1] == "X" ) && matris[1][2] != "O" ){
				return 6;
			}
			if( ( matris[0][1] == "X" && matris[1][1] == "X" ) && matris[2][1] != "O" ){
				return 8;
			}
			if( ( matris[2][1] == "X" && matris[1][1] == "X" ) && matris[1][0] != "O" ){
				return 2;
			}
			if( ( matris[0][0] == "X" && matris[1][1] == "X" ) && matris[2][2] != "O" ){
				return 9;
			}
			if( ( matris[2][2] == "X" && matris[1][1] == "X" ) && matris[0][0] != "O" ){
				return 1;
			}
			if( ( matris[0][2] == "X" && matris[1][1] == "X" ) && matris[2][0] != "O" ){
				return 7;
			}
			if( ( matris[2][0] == "X" && matris[1][1] == "X" ) && matris[0][2] != "O" ){
				return 3;
			}
		}
	}
	else if( first_second == 9 ){
		if( matris[1][1] == "X" ){
			if( matris[0][1] == "X" && matris[2][1] != "O" ){
				fill = 8;
			}
			if( matris[1][0] == "X" && matris[1][2] != "O" ){
				fill = 6;
			}
			if( matris[2][1] == "X" && matris[0][1] != "O" ){
				fill = 2;
			}
			if( matris[1][2] == "X" && matris[1][0] != "O" ){
				fill = 4;
			}
		}
	}
	if( fill == 1 || fill == 2 || fill == 3 || fill == 4 || fill == 5 || fill == 6 || fill == 7 || fill == 8 || fill == 9 ){
		return fill;
	}
	else{
		rand_fill_first = 1 + rand() % 8;	
		switch( rand_fill_first ){
			case 1:
				( matris[0][0] != "X" && matris[0][0] != "Y" ) ? fill = 1 : ai_fills( matris , first_second ) ;
				break;
			case 2:
				( matris[0][1] != "X" && matris[0][1] != "Y" ) ? fill = 2 : ai_fills( matris , first_second ) ;
				break;
			case 3:
				( matris[0][2] != "X" && matris[0][2] != "Y" ) ? fill = 3 : ai_fills( matris , first_second ) ;
				break;
			case 4:
				( matris[1][2] != "X" && matris[1][2] != "Y" ) ? fill = 6 : ai_fills( matris , first_second ) ;
				break;
			case 5:
				( matris[2][2] != "X" && matris[2][2] != "Y" ) ? fill = 9 : ai_fills( matris , first_second ) ;
				break;
			case 6:
				( matris[2][1] != "X" && matris[2][1] != "Y" ) ? fill = 8 : ai_fills( matris , first_second ) ;
				break;
			case 7:
				( matris[2][0] != "X" && matris[2][0] != "Y" ) ? fill = 7 : ai_fills( matris , first_second ) ;
				break;
			case 8:
				( matris[1][0] != "X" && matris[1][0] != "Y" ) ? fill = 4 : ai_fills( matris , first_second ) ;
				break;
			default:
				ai_fills( matris , first_second );
		}
		return fill;	
	}
}
//bool check_isalpha( int fill ){
//	bool is = false;
//	if( isalpha( fill ) ){
//		is = true;
//	}
//	return is;
//}
void insert_winner( string name ){
	std::ofstream ofs;
	ofs.open ("winners_list_rkh.txt", std::ofstream::out | std::ofstream::app);
	string insert = name + "&";
	ofs << insert;
	ofs.close();
}
void single_player( string name_a , string name_b , int round , int a_wins , int b_wins , int nobat , string ** matris , string note , int starter , int fs , bool first ){
	if( first == true ){
		fs = 1;
		first = false;
	}
	else{
		fs++;
	}
	
	if( round == 6 ){	
// 	 Beep(784,500);
		if( a_wins > b_wins ){
			system("CLS");
			cout<<endl;
			cout<<"   _______________________"<<endl;
			cout<<"  < "<<name_a<<" WON THE SERIES !!!"<<">"<<endl;
			cout<<"   -----------------------"<<endl;
			cout<<"          \   ^__^"<<endl;
			cout<<"           \  (oo)\_______"<<endl;
			cout<<"             (__)\       )\/\ "<<endl;
			cout<<"                ||----w |"<<endl;
			cout<<"                ||     ||"<<endl;
			cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
			insert_winner( name_a );
			what_now();
		}
		else{
			system("CLS");
			cout<<endl;
			cout<<"   _______________________"<<endl;
			cout<<"  < "<<name_b<<" WON THE SERIES !!!"<<">"<<endl;
			cout<<"   -----------------------"<<endl;
			cout<<"          \   ^__^"<<endl;
			cout<<"           \  (oo)\_______"<<endl;
			cout<<"             (__)\       )\/\ "<<endl;
			cout<<"                ||----w |"<<endl;
			cout<<"                ||     ||"<<endl;
			cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
			what_now();
		}
	}
	int fill;
//	stringstream ss4;
//	ss4.clear();
//	string fill_str_check;
//	fill_str_check.clear();
//	ss4 << fill;
//	ss4 >> fill_str_check;
//	if( ( "a" <= fill_str_check && fill_str_check <= "z" ) || ( "A" <= fill_str_check && fill_str_check <= "Z" ) ){
//		note = "Please Enter a number from 1 to 9 !"; cout<<"BITCH"; exit(0);
//		single_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter , fs , first );
//	}
	string fill_str;
	stringstream ss3;
	starter = nobat;
	system("CLS");
	cout<<"Round "<<round<<endl<<endl;
	cout<<name_a<<" -- "<<a_wins<<"\t\t"<<name_b<<" -- "<<b_wins<<endl;
	
	show_matris( matris );
	
	if( nobat == 1 ){
		if( note != "" ){
			cout<<note<<endl;
			note = "";
		}
		cout<<name_a<<"'s Turn :";	cin>>fill;
		if( fill > 9 ){
			note = "Enter a umber between 1 - 9 !";
			single_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter , fs , first );
		}
		int i_m = i_fill(fill);
		int j_m = j_fill(fill);
		bool won_or_not = false;
		if( check_fill(i_m , j_m , matris) == false ){
			matris[i_m][j_m] = "X";
//			Beep(587,500);
			if( check_win( matris , i_m , j_m ) != "NA" ){
				a_wins++;
				note = name_a + " Won !";
//				Beep(698,500);
				round++;
				first = true;
				won_or_not = true;
				reset_matris( matris );
			}
			nobat = 2;
		}
		else{
			note = "It's Taken !";
		}
		if( !won_or_not && free_or_not( matris ) == false ){
			if( starter == 1 ){
				note = name_b + " Won ! (filled space)";
				reset_matris( matris );	
//				Beep(698,500);
				round++;
				b_wins++;
				first = true;
				nobat = 2;
			}
			else if( starter == 2 ){
				note = name_a + " Won ! (filled space)";
				reset_matris( matris );
//				Beep(698,500);
				round++;
				a_wins++;
				first = true;
				nobat = 1;
			}
		}
		single_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter , fs , first );				
	}
	else if( nobat == 2 ){
		if( note != "" ){
			cout<<note<<endl;
			note = "";
		}
		if( free_or_not( matris ) == false ){
			
		}
		else{
			
		}
		fill = ai_fills( matris , fs );
		cout<<"Filling "<<fill<<"...";
		int i_m = i_fill(fill);
		int j_m = j_fill(fill);
		bool won_or_not = false;
		if( check_fill(i_m , j_m , matris) == false ){
			matris[i_m][j_m] = "O";
			ss3.clear();	fill_str.clear();
			ss3 << fill;
			ss3 >> fill_str;
			note = "AI filled " + fill_str;
//			Beep(659,500);
			if( check_win( matris , i_m , j_m ) != "NA" ){
				b_wins++;
				note = name_b + " Won !";
//				Beep(698,500);
				won_or_not = true;
				first = true;
				round++;
				reset_matris( matris );
			}
			nobat = 1;
		}
		if( !won_or_not && free_or_not( matris ) == false ){
			if( starter == 1 ){
				note = name_b + " Won ! (filled space)";
//				Beep(698,500);
				reset_matris( matris );	
				b_wins++;
				first = true;
				nobat = 2;
			}
			else if( starter == 2 ){
				note = name_a + " Won ! (filled space)";
//				Beep(698,500);
				reset_matris( matris );
				a_wins++;
				first = true;
				nobat = 1;
			}
		}
		single_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter , fs , first );
	}
}
void multi_player( string name_a , string name_b , int round , int a_wins , int b_wins , int nobat , string ** matris , string note , int starter ){
	if( round == 6 ){
// 	 Beep(784,500);
		if( a_wins > b_wins ){
			system("CLS");
			cout<<endl;
			cout<<"   _______________________"<<endl;
			cout<<"  < "<<name_a<<" WON THE SERIES !!!"<<">"<<endl;
			cout<<"   -----------------------"<<endl;
			cout<<"          \   ^__^"<<endl;
			cout<<"           \  (oo)\_______"<<endl;
			cout<<"             (__)\       )\/\ "<<endl;
			cout<<"                ||----w |"<<endl;
			cout<<"                ||     ||"<<endl;
			cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
			insert_winner( name_a );
			what_now();
		}
		else{
			system("CLS");
			cout<<endl;
			cout<<"   _______________________"<<endl;
			cout<<"  < "<<name_b<<" WON THE SERIES !!!"<<">"<<endl;
			cout<<"   -----------------------"<<endl;
			cout<<"          \   ^__^"<<endl;
			cout<<"           \  (oo)\_______"<<endl;
			cout<<"             (__)\       )\/\ "<<endl;
			cout<<"                ||----w |"<<endl;
			cout<<"                ||     ||"<<endl;
			cout<<endl<<endl<<"----------------------------------------------------------------------------"<<endl;
			insert_winner( name_b );
			what_now();
		}
	}
	int fill;
	starter = nobat;
	system("CLS");
	cout<<"Round "<<round<<endl<<endl;
	cout<<name_a<<" -- "<<a_wins<<"\t\t"<<name_b<<" -- "<<b_wins<<endl;
	
	show_matris( matris );
	
	if( nobat == 1 ){
		if( note != "" ){
			cout<<note<<endl;
			note = "";
		}
		cout<<name_a<<"'s Turn :";	cin>>fill;
		if( fill > 9 ){
			note = "Enter a umber between 1 - 9 !";
			multi_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter );
		}
		int i_m = i_fill(fill);
		int j_m = j_fill(fill);
		bool won_or_not = false;
		if( check_fill(i_m , j_m , matris) == false ){
			matris[i_m][j_m] = "X";
//  			Beep(587,500);
			if( check_win( matris , i_m , j_m ) != "NA" ){
				a_wins++;
				note = name_a + " Won !";
//				Beep(698,500);
				round++;
				won_or_not = true;
				reset_matris( matris );
			}
			nobat = 2;
		}
		else{
			note = "It's Taken !";
		}
		if( !won_or_not && free_or_not( matris ) == false ){
			if( starter == 1 ){
				note = name_b + " Won ! (filled space)";
				reset_matris( matris );	
//				Beep(698,500);
				round++;
				b_wins++;
				nobat = 2;
			}
			else if( starter == 2 ){
				note = name_a + " Won ! (filled space)";
				reset_matris( matris );
//				Beep(698,500);
				round++;
				a_wins++;
				nobat = 1;
			}
		}
		multi_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter );				
	}
	else if( nobat == 2 ){
		if( note != "" ){
			cout<<note<<endl;
			note = "";
		}
		cout<<name_b<<"'s Turn :";	cin>>fill;
		if( fill > 9 ){
			note = "Enter a umber between 1 - 9 !";
			multi_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter );
		}
		if( free_or_not( matris ) == false ){
			
		}
		else{
			
		}
		int i_m = i_fill(fill);
		int j_m = j_fill(fill);
		bool won_or_not = false;
		if( check_fill(i_m , j_m , matris) == false ){
			matris[i_m][j_m] = "O";
//			Beep(659,500);
			if( check_win( matris , i_m , j_m ) != "NA" ){
				b_wins++;
				note = name_b + " Won !";
//				Beep(698,500);
				won_or_not = true;
				round++;
				reset_matris( matris );
			}
			nobat = 1;
		}
		else{
			note = "It's Taken !";
		}
		if( !won_or_not && free_or_not( matris ) == false ){
			if( starter == 1 ){
				note = name_b + " Won ! (filled space)";
//				Beep(698,500);
				reset_matris( matris );	
				b_wins++;
				nobat = 2;
			}
			else if( starter == 2 ){
				note = name_a + " Won ! (filled space)";
//				Beep(698,500);
				reset_matris( matris );
				a_wins++;
				nobat = 1;
			}
		}
		multi_player( name_a , name_b ,  round , a_wins , b_wins , nobat , matris , note , starter );
	}
}
void start_game(){
	system("CLS");
	int single_or_multi;
	cout<<endl;
	cout<<"1 - Single Player"<<endl;
	cout<<"2 - multi Player"<<endl;
	cout<<endl;
	cout<<"Please insert the order : ";	cin>>single_or_multi;
	string name_a , name_b;
	int starter;
	int star_int;
	string note = "";
	stringstream ss1;
	string star_str;
	string ** matris;
	matris = new string *[3];
	for(int i = 0; i < 3; i++){
	    matris[i] = new string[3];
	}
	for( int i = 0 ; i < 3 ; i++ ){
		for( int j = 0 ; j < 3 ; j++ ){
			star_int = ( ( 2 * i ) + j ) + ( i + 1 );
			star_str.clear();
			ss1.clear();
			ss1 << star_int;
			ss1 >> star_str;
			matris[i][j] = star_str;
		}
	}
	switch ( single_or_multi ){
		case 1:
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"Player's Name : ";	cin>>name_a;
			name_b = "AI";
			srand(time(0));
			starter = 1 + rand() % 2;
			single_player( name_a , name_b , 1 , 0 , 0 , starter , matris , note , starter , 0 , true );
			break;
		case 2:
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"First Player's Name : ";	cin>>name_a;	
			cout<<"Second Player's Name : ";	cin>>name_b;
			if( name_a == name_b ){
				name_a += "_1";
				name_b += "_2";
			}
			srand(time(0));
			starter = 1 + rand() % 2;
			multi_player( name_a , name_b , 1 , 0 , 0 , starter , matris , note , starter );
			break;
		default :
			start_game();
	}
}
void winners_list(){
	system("CLS");
	ifstream myfile("winners_list_rkh.txt");
    string data;
    getline (myfile, data);
    if( data != "" ){
		string ch;
	    string ch2;
	    int td_words = 0;
	    for( int i = 0 ; i < data.size() ; i++ ){
	    	ch = data.at(i);
	    	if( ch == "&" ){
	    		td_words++;
			}
		}
		string word[td_words];
		int counter_word = 0;
	    for( int i = 0 ; i < data.size() ; i++ ){
	    	ch = data.at(i);
	    	if( ch != "&" ){
	    		word[counter_word] += data[i];
			}
			else{
	//			td_each_word[word[counter_word]]++;
				counter_word++;
			}
		}
		bool swapped = true;
		int cc = 0;
		string temp;
		while( swapped ){
			swapped = false;
			cc++;
			for( int i = 0 ; i < td_words - cc ; i++ ){
				ch = word[i].at(0);
				ch2 = word[i+1].at(0);
				if( ch > ch2 ){
					temp = word[i];
					word[i] = word[i+1];
					word[i+1] = temp;
					swapped = true;
				}
			}
		}
		int td_each_word[td_words];
		for( int i = 0 ; i < td_words ; i++ ){
			td_each_word[i] = 1;
		}
		for( int i = 0 ; i < td_words - 1 ; i++ ){
			temp = word[i];
			for( int j = i + 1 ; j < td_words ; j++ ){
				if( word[j] == temp ){
					td_each_word[i]++;
				}
				else{
					break;
				}
			}
		}
		string word_2[td_words];
		int	td_each_word_2[td_words];
		int difference = 0;
		int counter_2 = 0;
		for( int i = 0 ; i < td_words ;  ){
			if( td_each_word[i] != 1 ){
				word_2[counter_2] = word[i];
				td_each_word_2[counter_2] = td_each_word[i];
				difference += td_each_word[i] - 1;
				i += td_each_word[i];
				counter_2++;
			}
			else{
				word_2[counter_2] = word[i];
				td_each_word_2[counter_2] = td_each_word[i];
				
				i++;
				counter_2++;
			}
		}
		swapped = true;
		cc = 0;
		int temp_int = 0;
		while( swapped ){
			swapped = false;
			cc++;
			for( int i = 0 ; i < (td_words - difference) - cc ; i++ ){
				if( td_each_word_2[i] < td_each_word_2[i+1] ){
					temp = word[i];
					word[i] = word[i+1];
					word[i+1] = temp;
					temp_int = td_each_word_2[i];
					td_each_word_2[i] = td_each_word_2[i+1];
					td_each_word_2[i+1] = temp_int;
					swapped = true;
				}
			}
		}
		int max_td = 0;
		for( int i = 0 ; i < (td_words - difference) ; i++ ){
			if( td_each_word_2[i] > max_td ){
				max_td = td_each_word_2[i];
			}
		}
		int rows = 0;
		for( int i = 0 ; i < td_words - difference ; i++ ){
			int radif = rows + 1;
			cout<<radif<<" - "<<word_2[i]<<"  -->  "<<td_each_word_2[i];
			( td_each_word_2[i] > 1 ) ? cout<<" times winner " : cout<<" time winner ";
			(radif == 1 ) ? cout<<" ( CHAMPION )" : cout<<"";
			cout<<endl;
			if( td_each_word_2[i+1] < td_each_word_2[i] ){
				rows++;
			}
		}
	}
	else{
		cout<<"No Winners found !";
	}
	cout<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"NOTE : Board is sorted by players both Wins and Names."<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<endl;
    what_now();
}
void kill(){
	system("CLS");
	cout<<"Good Bye :(";
	exit (0);
}
void main_main(){
	system("CLS");
	int order_main_main;
	cout<<" _______________________________"<<endl;
	cout<<"|                               |"<<endl;
	cout<<"| Welcome to TIC TOC TOE game ! |"<<endl;
	cout<<"|                               |"<<endl;
	cout<<" -------------------------------"<<endl<<endl;
	cout<<"1 - Start Game"<<endl;
	cout<<"2 - Winners List"<<endl;
	cout<<"3 - Exit"<<endl;
	cout<<endl;
	cout<<"Please insert the order : ";	cin>>order_main_main;
	switch ( order_main_main ){
		case 1:
			start_game();
			break;
		case 2:		
//			Beep(587,500);
			winners_list();
			break;
		case 3:
//  			Beep(784,500);
			kill();
			break;
		default:
			main_main();
	}
}
