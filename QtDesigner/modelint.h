#ifndef MODELINT_H
#define MODELINT_H

#include <QObject>

class ModelInt : public QObject
{
    Q_OBJECT
public:
    explicit ModelInt(QObject *parent = nullptr);

    void setValue(int val);
    int value() const;

signals:
    void valueChanged(int val);

private:
    int m_value;
};

#endif // MODELINT_H
