#ifndef IMC_H
#define IMC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class imc; }
QT_END_NAMESPACE

class imc : public QMainWindow
{
    Q_OBJECT

public:
    imc(QWidget *parent = nullptr);
    ~imc();

private:
    Ui::imc *ui;
};
#endif // IMC_H
