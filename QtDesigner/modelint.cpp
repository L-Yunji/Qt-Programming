#include "modelint.h"

ModelInt::ModelInt(QObject *parent)
    : QObject{parent}
{}

void ModelInt::setValue(int val)
{
    if(m_value != val)
    {
        m_value = val;
        emit valueChanged(val);
    }
}

int ModelInt::value() const
{
    return m_value;
}
