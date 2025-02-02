#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ncurses.h>

using namespace std ;

int numm(int a)
{
    int m = 0 ;
    for (int i = 0; a > 0 ; i++)
    {
        m++ ;
        a = a / 10 ;
    }

    return m ;
    
}



struct stu
{
    string name ;
    string family ;
    string Field ;
    int num_st ;
    float GPA ;
    
    
    
    
};


bool chek(int a , stu s[] , int ns , int i)
{
    bool t = false;
    for (int j = 0 ; j < ns ; j++)
    {
        if ( (a == s[j].num_st ) && ( j != i ) )
        {
            t = true ;
        }
        
    }

    return t ;
    
}




using namespace std ;

int main()
{

    int ns , nc ;

    cout << " Please enter the Number of Students :     " << "\n" ;
    //get right information;
    while (!(cin >> ns ))
    {
        cout <<"Please enter a "<<"\033[1mNumber\033[0m\n" <<"\n" ;
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
    }
    
    //
    stu rp[ns] ;

    

    
    cout << " Please enter the Number of Courses :     " << "\n" ;
    //get right information;
    while (!(cin >> nc ))
    {
        cout <<"Please enter a "<<"\033[1mNumber\033[0m\n" <<"\n" ;
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
    }
    

    // ( 2 * nc ) about corse ant unit about this corse
    float score[ns][2*nc] ;


    // about style of report card
    string sco[2*nc] ;


    // ger information about all of the corse
    // made table
    int nm = 1 ;
    for (int i = 0 ; i < ( 2 * nc ) ; i=i+2)
    {

        cout << "Please enter name of Course"<< nm  <<" :" << "\n" ;
        cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
        getline(cin , sco[i]) ;

        if ( (i+1) <= ( 2*nc) )
        {
            cout << "Please enter the number of Unit about this corse : " << "\n" ;
            //cin >> score[0][i+1] ;
            while (  ( !(cin >> score[0][i+1] ) )  ||  (  score[0][i] >= 10 )  ||  ( score[0][i] <= 0 )  )
            {
                cout <<"Please enter a "<<"\033[1mNumber Or Number between 0 up to 10 \033[0m\n" <<"\n" ; 
                cin.clear() ;
                cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
            }
        }
        
        nm++;
    }

    for (int i = 1 ; i < ( 2 * nc ) ; i = i+2)
    {
        for (int j = 1 ; j < ns ; j++)
        {
            score[j][i] = score[0][i] ;
        }
        
    }
    



    // get information about student 
    cout << "\n" << "(If the student does not have the course, please enter" << " '-1' ) "<< "\n" ;
    for (int i = 0 ; i < ns ; i++)
    {
        
        // clean buffer
        cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
        cout << "Please enter the First name of Students :     " ;
        getline(cin , rp[i].name ) ;


        //cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
        cout << "Please enter the Last name of Students :      " ;
        getline(cin , rp[i].family ) ;


        //cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
        cout << "Please enter the Field of Students :          " ;
        getline(cin , rp[i].Field ) ;

        
        cout << "Please enter the Student Number :             "  ;
        //cin >> rp[i].num_st ;
        while ( (!(cin >> rp[i].num_st ) ) || ( numm(rp[i].num_st) != 9)  ||  ( chek(rp[i].num_st , rp , ns , i )))
        {
            cout <<"Please enter  "<<"\033[1m 9 Number OR Right Non-repeating Number\033[0m\n" <<"\n" ;
            cin.clear() ;
            cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
        }
        nm = 0 ;
        double g = 0 ;
        for (int j = 0 ; j < ( 2 * nc ) ; j=j+2)
        {
            cout <<"please enter " << rp[i].name << " " << rp[i].family << "'s " << sco[j] << " grade :" <<"\n" ;
            //cin >> score[i][j] ;
            while (  ( (!(cin >> score[i][j] ) ) || ( score[i][j] > 20 ) || (score[i][j] < 0) ) && (score[i][j] != -1) )
            {
                // print bold text
                cout <<"Please enter  "<<"\033[1m Right Number\033[0m\n" <<"\n" ;
                cin.clear() ;
                cin.ignore(numeric_limits<streamsize>::max() , '\n') ;
            }

            if (score[i][j] == -1)
            {
                continue;
            }

            else
            {
                g = g + score[i][j] * score[i][j+1] ;
                nm = nm + score[i][j+1];

            }
            


            
    
            //g = g + score[i][j] * score[i][j+1] ;
            //nm = nm + score[i][j+1];
        }

        g = g / nm ;
        rp[i].GPA = g ;


    }


    for (int i = 0 ; i < ns ; i++)
    {
        for (int j = i+1  ; j < ns ; j++)
        {
            if ( rp[i].GPA < rp[j].GPA)
            {
                stu rp1 ;
                rp1 = rp[i];
                rp[i] = rp[j] ;
                rp[j] = rp1 ;

                for (int t = 0 ; t < ( 2 * nc ) ; t++)
                {
                    float score1 ;
                    score1 = score[i][t] ;
                    score[i][t] = score[j][t] ;
                    score[j][t] = score1 ;
                }
                

            }
            
        }
        
    }
    





    //show table 
    cout << "          " << "Name" << "         " << "|" ;
    cout << "        " << "Last Name" << "         " << "|" ;
    cout << "  " << "Student's Number" << "  " <<"|" ;
    cout << "             " << "Field" << "              " <<"|";
    cout << "   " << "GPA" << "   " <<"|" ;
    for (int i = 0 ; i < ( 2*nc ); i++)
    {
        if ( (i%2) == 0 )
        {
            cout <<"  " ;
            cout <<sco[i] ;
            for (int p = 0 ; p < (21 - sco[i].length() ) ; p++)
            {
                cout <<" " ;
            }
            
            cout << "  ";
            cout <<"|";
        }

        else
        {
            cout <<"  ";
            cout <<"Unit" ;
            cout <<"  ";
            cout <<"|" ;
        }
        
    }
    

    







    

    cout <<"\n" << "\n" ;
    // show for people
    for (int i = 0 ; i < ns ; i++)
    {
        //name
        cout << " * "<<rp[i].name ;
        for (int t = 0 ; t < (20 - rp[i].name.length() ); t++)
        {
            cout << " " ;
        }
        cout << "|" ;

        //family
        cout <<" " ;
        cout <<rp[i].family ;
        for (int t = 0 ; t < (24 - rp[i].family.length() ); t++)
        {
            cout << " " ;
        }
        cout <<" |" ;
        
        //student's Number
        cout <<"     " ;
        cout << rp[i].num_st ;
        cout <<"      |";

        // Field
        cout << " "<< rp[i].Field ;
        for (int t = 0; t < (30 - rp[i].Field.length() ); t++)
        {
            cout <<" " ;
        }
        cout << " |"  ;


        cout <<"  " ;
        cout << fixed << setprecision(2) ;
        cout << rp[i].GPA << "  " ;
        if ( rp[i].GPA < 10)
        {
            cout <<" " ;
        }
        cout << "|" ;
        

        


        for (int j = 0 ; j < (2*nc) ; j++)
        {
            if ( ( j % 2 ) == 1 )
            {
                cout <<"   " ;
                cout << fixed << setprecision(0) ;
                cout << score[i][j] ;
                cout << "    |" ;

            }

            else
            {

                cout <<"  " ;
                if (score[i][j] != -1)
                {
                    cout << fixed << setprecision(2) ;
                    cout <<score[i][j] ;
                    if (score[i][j] < 10)
                    {
                        cout <<" " ;
                    }
                    

                    
                }
                else
                {
                    cout << "     " ;
                }
                

                for (int p = 0 ; p < 16 ; p++)
                {
                    cout << " ";
                }
                
                cout << "  |" ;
            }
            

        }
        cout <<"\n" << "\n" ;
        
    }


    
    



    
    
        
    
    
    
}
