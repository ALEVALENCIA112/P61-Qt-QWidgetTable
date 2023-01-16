#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();

    QString apellido = ui->inApellido->text();

    QString telefono = ui->inTelefono->text();

    QString email = ui->inEmail->text();

    if (nombre.isEmpty()|| apellido.isEmpty() || telefono.isEmpty() || email.isEmpty()){
        QMessageBox::warning(this, "Adventencia", "Se debe completar todos los campos antes de continuar");
        return;
    }

    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}


void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}

