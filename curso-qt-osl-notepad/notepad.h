#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = 0);
    ~Notepad();
};

#endif // NOTEPAD_H
