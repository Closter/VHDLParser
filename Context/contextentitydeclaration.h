#ifndef CONTEXTENTITYDECLARATION_H
#define CONTEXTENTITYDECLARATION_H

#include "Context/abstractcontext.h"

class ContextEntityDeclaration : public AbstractContext
{
public:
  ContextEntityDeclaration(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);

};

#endif // CONTEXTENTITYDECLARATION_H
