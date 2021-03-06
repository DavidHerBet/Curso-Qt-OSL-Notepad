#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QToolBar>

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void alAbrir();
    void alGuardar();
    void alSalir();
    void alFuente();
    void alAcercaDe();
    void alNegrita();
    void alCursiva();
    void alSubrayado();

private:
    // Editor de texto
    QTextEdit *txtEditor_;

    // Barra de menú
    QMenuBar *mainMenu_;

    // Elementos del menú
    QMenu *mnuArchivo_;
    QMenu *mnuEditar_;
    QMenu *mnuFormato_;
    QMenu *mnuAyuda_;

    // Acciones de Archivo
    QAction *actArchivoAbrir_;
    QAction *actArchivoGuardar_;
    QAction *actArchivoSalir_;

    // Acciones de Editar
    QAction *actEditarDeshacer_;
    QAction *actEditarRehacer_;
    QAction *actEditarCortar_;
    QAction *actEditarCopiar_;
    QAction *actEditarPegar_;
    QAction *actEditarSeleccionarTodo_;

    // Acciones de Formato
    QAction *actFormatoFuente_;

    // Acciones de Ayuda
    QAction *actAyudaAcercaDe_;

    // Menú de herramientas
    QToolBar *mainToolbar_;

    // EXTRAS
    QToolBar *extraToolbar_;
    QAction *actEditarNegrita_;
    QAction *actEditarCursiva_;
    QAction *actEditarSubrayado_;
};

#endif // NOTEPAD_H
