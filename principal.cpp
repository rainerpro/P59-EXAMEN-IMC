#include "principal.h"

principal::principal(QObject *parent) : QObject(parent)
{

}

const QString &principal::fecha() const
{
    return m_fecha;
}

float principal::estatura() const
{
    return m_estatura;
}

float principal::imc() const
{
    return m_imc;
}

float principal::peso() const
{
    return m_peso;
}

principal::principal(float imc, float peso, const QString &fecha, float estatura) : m_imc(imc),
    m_peso(peso),
    m_fecha(fecha),
    m_estatura(estatura)
{}
