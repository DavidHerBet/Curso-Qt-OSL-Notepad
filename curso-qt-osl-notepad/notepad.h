#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QMenu>

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = 0);
    ~Notepad();

private:
    // Editor de texto
    QPlainTextEdit *txtEditor_;

    // Barra de menú
    QMenuBar *mainMenu_;

    // Elementos del menú
    QMenu *mnuArchivo_;
    QMenu *mnuEditar_;
    QMenu *mnuFormato_;
    QMenu *mnuAyuda_;
};

#endif // NOTEPAD_H
