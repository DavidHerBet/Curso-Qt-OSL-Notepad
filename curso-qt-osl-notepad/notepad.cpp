#include "notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
{
    // Establecemos el título de la ventana
    setWindowTitle("Bloc de notas - Curso Qt OSL "
                   "- David Hernández Bethencourt");

    // Establecemos el tamaño inicial de la ventana
    setGeometry(30,30,600,500);

    // Inicializamos el editor de texto
    txtEditor_ = new QPlainTextEdit(this);

    // Agregamos nuestro editor de texto a la ventana
    setCentralWidget(txtEditor_);
}

Notepad::~Notepad()
{

}
