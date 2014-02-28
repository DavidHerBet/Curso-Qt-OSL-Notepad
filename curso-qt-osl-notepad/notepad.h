#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QPlainTextEdit>

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = 0);
    ~Notepad();

private:
    // Editor de texto
    QPlainTextEdit *txtEditor_;
};

#endif // NOTEPAD_H
