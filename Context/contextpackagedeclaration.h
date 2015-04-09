#ifndef CONTEXTPACKAGEDECLARATION_H
#define CONTEXTPACKAGEDECLARATION_H

#include "Context/abstractcontext.h"

class ContextPackageDeclaration : public AbstractContext
{
public:
  ContextPackageDeclaration(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);

};

#endif // CONTEXTPACKAGEDECLARATION_H
