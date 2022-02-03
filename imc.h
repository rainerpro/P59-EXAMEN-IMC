#ifndef IMC_H
#define IMC_H
#include"principal.h"

#include <QMainWindow>
#include <qmath.h>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDialog>
#include <QTextStream>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class imc; }
QT_END_NAMESPACE

class imc : public QMainWindow
{
    Q_OBJECT

public:
    imc(QWidget *parent = nullptr);
    ~imc();


private slots:
    void on_btCalcular_released();
private:
    Ui::imc *ui;
    QList<principal*> m_lista;
    QString curfile;

    void savefile();

    void calcular();
    bool obtenerDatos();
    void ordenar();
    void moverLinea(float imc);

    QString m_datos;
    QString m_fecha;
    QString dias;

    float m_estatura;
    float m_peso;
    float m_imc;
};
#endif // IMC_H
