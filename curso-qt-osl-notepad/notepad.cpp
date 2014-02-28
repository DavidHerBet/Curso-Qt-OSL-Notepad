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

    // Inicializamos las acciones de los elementos del menú
    // Agregamos los shortcuts a las acciones correspondientes
    // Añadimos la acción al menu correspondiente

    // ARCHIVO
    actArchivoAbrir_ = new QAction(tr("Abrir..."), this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);

    actArchivoGuardar_ = new QAction(tr("Guardar"), this);
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    mnuArchivo_->addAction(actArchivoGuardar_);

    // Añadir separador para agrupar
    mnuArchivo_->addSeparator();

    actArchivoSalir_ = new QAction(tr("Salir"), this);
    actArchivoSalir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    mnuArchivo_->addAction(actArchivoSalir_);

    // EDITAR
    actEditarDeshacer_ = new QAction(tr("Deshacer"), this);
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
    mnuEditar_->addAction(actEditarDeshacer_);

    actEditarRehacer_ = new QAction(tr("Rehacer"), this);
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Z));
    mnuEditar_->addAction(actEditarRehacer_);

    // Añadir separador para agrupar
    mnuEditar_->addSeparator();

    actEditarCortar_ = new QAction(tr("Cortar"), this);
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    mnuEditar_->addAction(actEditarCortar_);

    actEditarCopiar_ = new QAction(tr("Copiar"), this);
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);

    actEditarPegar_ = new QAction(tr("Pegar"), this);
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);

    // Añadir separador para agrupar
    mnuEditar_->addSeparator();

    actEditarSeleccionarTodo_ = new QAction(tr("Seleccionar todo"), this);
    actEditarSeleccionarTodo_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    mnuEditar_->addAction(actEditarSeleccionarTodo_);

    // FORMATO
    actFormatoFuente_ = new QAction(tr("Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    // AYUDA
    actAyudaAcercaDe_ = new QAction(tr("Acerca de"), this);
    mnuAyuda_->addAction(actAyudaAcercaDe_);

    // Conectar las acciones a los slots
    connect(actArchivoAbrir_, SIGNAL(triggered()), this, SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL(triggered()), this, SLOT(alGuardar()));
    connect(actArchivoSalir_, SIGNAL(triggered()), this, SLOT(alSalir()));
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_, SLOT(undo()));
    connect(actEditarRehacer_, SIGNAL(triggered()), txtEditor_, SLOT(redo()));
    connect(actEditarCortar_, SIGNAL(triggered()), txtEditor_, SLOT(cut()));
    connect(actEditarCopiar_, SIGNAL(triggered()), txtEditor_, SLOT(copy()));
    connect(actEditarSeleccionarTodo_, SIGNAL(triggered()), txtEditor_, SLOT(selectAll()));
    connect(actFormatoFuente_, SIGNAL(triggered()), this, SLOT(alFuente()));
    connect(actAyudaAcercaDe_, SIGNAL(triggered()), this, SLOT(alAcercaDe()));
}

Notepad::~Notepad()
{

}

void Notepad::alAbrir()
{
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this, tr("Abrir archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::ReadOnly)) {
            txtEditor_->setPlainText(archivo.readAll());
            archivo.close();
        }
    }
}

void Notepad::alGuardar()
{
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this, tr("Guardar como"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        QFile archivo;

        // Asignamos la expresión regular para archivos de texto
        QRegExp regexp("*.txt");

        // Imitamos el matching de regexp de la shell
        regexp.setPatternSyntax(QRegExp::Wildcard);

        // Si el nombre elegido no termina en .txt se lo añadimos
        if (!regexp.exactMatch(nombreArchivo))
            archivo.setFileName(nombreArchivo + ".txt");
        else
            archivo.setFileName(nombreArchivo);

        // Guardamos el archivo
        if (archivo.open(QFile::WriteOnly)) {
            archivo.write(txtEditor_->toPlainText().toUtf8());
            archivo.close();
        }
    }
}

void Notepad::alSalir()
{
    exit(0);
}

void Notepad::alFuente()
{

}

void Notepad::alAcercaDe()
{

}
