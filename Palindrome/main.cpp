#include "for_main.h"

int main(int argc, char const *argv[]) {
    Pallindrome *pal_arr=new Pallindrome[3];
    INIT_PALLINDROM_ARRAY;
    int selection, p_index = -1, l_index = -1, r_index = -1;
    char c, t;
    while (1) {
        SHOW_MENU;
        if (!(cin >> selection)) {CLR_CIN_AND_ERR;continue;} // get a number & make sure it's valid
        c = getchar();
        switch (selection) {
            case 1:
                Create(p_index, pal_arr);
                break;
            case 2:
                Update(p_index, pal_arr);
                break;
            case 3:
                Threading(l_index, r_index, p_index, pal_arr);
                break;
            case 4:
                Subtraction(l_index,r_index,pal_arr);
                break;
            case 5:
                Add_Char(p_index,pal_arr);
                break;
            case 6:
                Comparison(l_index,r_index,pal_arr);
                break;
            case 7:
                Increment(p_index,pal_arr);
                break;
            case 8:
                Print_Spcific_Letter(p_index,r_index,pal_arr);
                break;
            case 9:
                Print(p_index,pal_arr);
                break;
            case 10:
                delete []pal_arr;
                return 0;
        }
    }
    return 0;
}
