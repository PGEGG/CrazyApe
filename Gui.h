#ifndef Gui_h
#define Gui_h

class Gui
{
public:
    GUI();
    void setField(int *field[]);
    void info_button();
    void start_button();
    void stop_button();
    void reset_button();
    ~GUI();
};

#endif