#ifndef PERSONNEMODEL_H
#define PERSONNEMODEL_H

#include <QObject>
#include <QSqlQuery>
#include <QVariant>

class personneModel : public QObject
{
    Q_OBJECT

protected:
    long id;
    QString nom;
    QString prenom;

    public:
        personneModel(long, QString, QString);

};

#endif // PERSONNEMODEL_H