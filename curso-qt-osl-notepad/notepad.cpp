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

    // Inicializamos los elementos del menú
    mainMenu_ = new QMenuBar(this);
    mnuArchivo_ = new QMenu(tr("&Archivo"), this);
    mnuEditar_ = new QMenu(tr("&Editar"), this);
    mnuFormato_ = new QMenu(tr("&Formato"), this);
    mnuAyuda_ = new QMenu(tr("&Ayuda"), this);

    // Agregamos los elementos al menú
    mainMenu_->addMenu(mnuArchivo_);
    mainMenu_->addMenu(mnuEditar_);
    mainMenu_->addMenu(mnuFormato_);
    mainMenu_->addMenu(mnuAyuda_);

    // Agregamos el menú a la ventana (QMainWindow)
    setMenuBar(mainMenu_);
}

Notepad::~Notepad()
{

}
