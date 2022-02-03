#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QObject>


class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);
    principal(float imc, float peso, const QString &fecha, float estatura);

    const QString &fecha() const;
    float estatura() const;
    float imc() const;
    float peso() const;
    void setImc(float newImc);
    void setPeso(float newPeso);
    void setFecha(const QString &newFecha);
    void setEstatura(float newEstatura);

signals:
private:
    float m_imc;
    float m_peso;
    QString m_fecha;
    float m_estatura;

};
#endif // PRINCIPAL_H
