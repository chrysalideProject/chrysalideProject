#ifndef AUTREPERSONNELMODEL_H
#define AUTREPERSONNELMODEL_H
#include "personnemodel.h"

class autrePersonnelModel : public personneModel
{
    public:
        autrePersonnelModel(int);
        static QMap<int, autrePersonnelModel*> recupererAutrePersonnels();
        bool travaille(QDate when,QString soirMidi);
        void prendreRepas(int noRepas);
};

#endif // AUTREPERSONNELMODEL_H
