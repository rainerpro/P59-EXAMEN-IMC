#include "imc.h"
#include "ui_imc.h"

imc::imc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::imc)
{
    ui->setupUi(this);
}

imc::~imc()
{
    delete ui;
}

