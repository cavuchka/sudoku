// Почти написал программу для генерирования судоку. Компилируется,
// работает, однако в 50% случаях генерирует только 3-8 строк и 
// зависает. В остальных случаях генерирует полность, но в 
// квадратах числа повторяются. Подскажите, где ошибка, а то я 100
// раз код просмотрел и не заметил.

#include <iostream>
#include <stdlib.h>
using namespace std;
 
int main()
{
    srand(time(0));
    const int size=9;
    int number;
    int sudoku[size][size];
    int i, j;
    int k, l;
    int chance;
    int i_from, j_from;
    
    bool repeated;
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            
            chance=rand()%4;
            if(chance==0)
            {
                cout << "#" << " ";
                sudoku[i][j]=0;
                continue;
            }
            
            if(i<3) i_from=0;
            else if(i<6) i_from=3;
            else i_from=6;
            
            if(j<3) j_from=0;
            else if(j<6) j_from=3;
            else j_from=6;
            
            for(;;)
            {
                repeated=false;
                number=rand()%9+1;
                
                for(l=i_from; l<i; l++)
                    for(k=j_from; k<j; k++)
                        if(sudoku[l][k]==number)
                        {
                            repeated=true;
                            break;
                        }
                
                for(l=0; l<i; l++)
                    if(sudoku[l][j]==number)
                    {
                        repeated=true;
                        break;
                    }
                for(k=0; k<j; k++)
                    if(sudoku[i][k]==number)
                    {
                        repeated=true;
                        break;
                    }
                
                if(repeated==true)
                    continue;
                    
                sudoku[i][j]=number;
                break;
            }
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
