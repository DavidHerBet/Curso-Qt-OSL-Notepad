#include "notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
{
    // Establecemos el título de la ventana
    setWindowTitle("Bloc de notas - Curso Qt OSL "
                   "- David Hernández Bethencourt");

    // Establecemos el tamaño inicial de la ventana
    setGeometry(30,30,750,550);

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

    // Inicializamos el toolbar
    mainToolbar_ = new QToolBar(this);

    // Mantenemos el toolbar fijo arriba
    mainToolbar_->setAllowedAreas(Qt::TopToolBarArea);
    mainToolbar_->setMovable(false);

    // Definimos que el texto se muestre a la derecha del icono
    mainToolbar_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    // Definimos iconos para las acciones del toolbar
    actArchivoAbrir_->setIcon(QIcon(":/iconos/resources/Abrir.png"));
    actArchivoGuardar_->setIcon(QIcon(":/iconos/resources/Guardar.png"));
    actEditarDeshacer_->setIcon(QIcon(":/iconos/resources/Deshacer.png"));
    actEditarRehacer_->setIcon(QIcon(":/iconos/resources/Rehacer.png"));
    actEditarCortar_->setIcon(QIcon(":/iconos/resources/Cortar.png"));
    actEditarCopiar_->setIcon(QIcon(":/iconos/resources/Copiar.png"));
    actEditarPegar_->setIcon(QIcon(":/iconos/resources/Pegar.png"));
    actFormatoFuente_->setIcon(QIcon(":/iconos/resources/Fuente.png"));

    // Hacemos que los iconos no sean visibles desde el menú
    actArchivoAbrir_->setIconVisibleInMenu(false);
    actArchivoGuardar_->setIconVisibleInMenu(false);
    actEditarDeshacer_->setIconVisibleInMenu(false);
    actEditarRehacer_->setIconVisibleInMenu(false);
    actEditarCortar_->setIconVisibleInMenu(false);
    actEditarCopiar_->setIconVisibleInMenu(false);
    actEditarPegar_->setIconVisibleInMenu(false);
    actFormatoFuente_->setIconVisibleInMenu(false);

    // Añadimos las acciones al toolbar
    mainToolbar_->addAction(actArchivoAbrir_);
    mainToolbar_->addAction(actArchivoGuardar_);
    mainToolbar_->addAction(actEditarDeshacer_);
    mainToolbar_->addAction(actEditarRehacer_);
    mainToolbar_->addAction(actEditarCortar_);
    mainToolbar_->addAction(actEditarCopiar_);
    mainToolbar_->addAction(actEditarPegar_);
    mainToolbar_->addAction(actFormatoFuente_);

    // Agregamos el toolbar a la ventana
    addToolBar(mainToolbar_);

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
    nombreArchivo = QFileDialog::getSaveFileName(this, tr("Guardar"),
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
    bool accept;
    QFont font = QFontDialog::getFont(&accept, txtEditor_->font(), this);

    // Si el usuario acepta, se establece la fuente elegida
    if (accept)
        txtEditor_->setFont(font);
}

void Notepad::alAcercaDe()
{
    QMessageBox acercaDe;
    acercaDe.setWindowTitle(tr("Acerca de"));
    acercaDe.setText(tr("Bloc de notas creado por David "
                        "Hernández Bethencourt en el curso "
                        "de Qt de la Oficina del Software Libre "
                        "(OSL) de la Universidad de La Laguna"));
    acercaDe.addButton(tr("Cerrar"), QMessageBox::RejectRole);
    acercaDe.exec();
}
