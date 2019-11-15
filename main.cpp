
/// Буер Мур, белки

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define leng  500000
#define M 30

using namespace std;

/// Счётчик операций
int count =0;

int o = 0;

char SymbolOfX[M]; //Таблица символов искомой строки
int ValueShift[M]; //Смещение

string rnk;
string need;

template <class T >
T les (T x , T y )
{
    count ++;
    if ( x < y ) {return true;}
    else { return false; }
}

template <class T >
T more (T x , T y )
{
    count ++;
    if ( x > y ) {return true;}
    else { return false; }
}

template <class T >
T nonequal (T x , T y )
{
    count ++;
    if ( x != y ) {return true;}
    else { return false; }
}

template <class T >
T my_equal (T x , T y )
{
    count ++;
    if ( x == y ) {return true;}
    else { return false; }
}

char input (int r)
{
    switch (r)
    {
    case 0:
        return 'A';
        break;
    case 1:
        return 'B';
        break;
    case 2:
        return 'C';
        break;
    case 3:
        return 'D';
        break;
    }
}

int main()
{
    rnk.reserve(leng);
    srand(time(NULL));
    int i = 0;

    while (i < leng) {  rnk[i] = input( rand()%4); i++;  }
    /* cout << endl <<"Start string"<< endl; i = 0; while (i < leng) { cout << rnk[i]; i++; } cout << endl;*/
    need.reserve(M);
    i = 0;
    while (i < M) { need[i] = input(rand()%4); i++;}
    /*cout << endl <<"Need string"<< endl; i = 0; while (i < M) { cout << need[i]; i++; }*/
    int ress = M;
    int new_length = leng;

    for ( int e = 0; e < 10; e++)
    {

            //////////////////////// Формирование таблицы сдвигов \\\\\\\\\\\\\\\\\\\\\

            i =0;
            int k = 0;
            bool fl;

            for (i = ( ress - 1); i >= 0; i--)
            {
                fl = 0;
                int j = 0;
                while ( (j < k+1 ) && (fl == 0))
                {
                    if (SymbolOfX[j] == need[i]) { fl = 1;}
                    j++;
                }
                if (fl == 0)
                {
                    SymbolOfX[k] = need[i];
                    ValueShift[k] = ress - i - 1;

                    k++;
                }
            }


            ///сам поиск
            bool ff, match; int l; i =0;

            for (i = 0; i < (new_length - ress+1); i++)
            {
                int j = ress - 1;
                match = 1;

                while ((j >= 0)&&(match == 1))
                {
                    if (nonequal (rnk[i + j], need[j]))
                    {
                        match = 0;
                        //Если это последний символ
                        if (j == ress - 1)
                        {
                            l = 0;
                            ff = 0;

                            //Поиск символа в таблице смещений
                            while ((l < ress)&&(ff == 0))
                            {
                            //Если символ есть
                                if (my_equal (rnk[i + j], SymbolOfX[l]))
                                {
                                    ff = 1;
                                    i = i + ValueShift[l] - 1; //Сдвиг на величину
                                }
                                l++;
                            }

                        }
                    }

                    j--;
                }

                if (match == 1) o++;
            }
            new_length = new_length * 0.5;
            cout << "-------THE END------" << endl;
            cout << " Number of operation = " << count<< endl ;
            cout << " The length of basic string = " << new_length<< endl;
            cout << " The length of finding string = " << ress << endl;
            count =0;


    }

    return 0;
}
