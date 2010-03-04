#ifndef REPASMODEL_H
#define REPASMODEL_H
#include <QDate>

class repasModel
{
    private:
    int numero;
public:
    repasModel(QDate,QString);
    int getNumero(){return numero;};
};

#endif // REPASMODEL_H
