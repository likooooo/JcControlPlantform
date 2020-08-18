#include "Lib/PlantformIO/ProjController.h"

#ifndef INTERFACESLNCONTROLLER_H
#define INTERFACESLNCONTROLLER_H


class ISlnController
{
public:
    virtual void AddProj(Project proj);
    virtual void UnLoadProj(int index);
    virtual void LoadProj(int index);
    virtual void DeleteProj(int index);
};



#endif // INTERFACESLNCONTROLLER_H
