/****************************************************/
/* Augusto Ribas                                    */
/* Trabalho 1 Introdução a Bioinformatica           */
/* Professor(a): Said                               */
/****************************************************/

#ifndef Classes_h
#define Classes_h

class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area() {return width*height;}
};



#endif
