#pragma once


class Pipe{

private:

    int m_x_position, m_y_position, m_width, m_height, m_colour;
    const int CONSSPEED = 1; // the speed of which pipes move toward the left 
    
public:

    Pipe(){

        m_x_position = 100;
        m_y_position = 100;
        m_width = 100;
        m_height = 100;
        m_colour = 0xAA00FF;

    }

    Pipe(int x, int y){

        m_x_position = x;
        m_y_position = y;
        m_width = 100;
        m_height = 100;
        m_colour = 0xAA00FF;

    }

    Pipe(int x, int y, int w, int h){

        m_x_position = x;
        m_y_position = y;
        m_width = w;
        m_height = h;
        m_colour = 0xAA00FF;

    }
    
    Pipe(int x, int y, int w, int h,int col){

        m_x_position = x;
        m_y_position = y;
        m_width = w;
        m_height = h;
        m_colour = col;
    }


    int getSpeed(){return CONSSPEED;}

    int getX(){return m_x_position;}

    int getY(){return m_y_position;}

    int get_Width(){return m_width;}

    int get_Height(){return m_height;}

    int get_Colour(){return m_colour;}

    void setX(int x){m_x_position += x;}
    
    void setY(int y){m_y_position = y;}

    void setH(int h){m_height = h;}


};



