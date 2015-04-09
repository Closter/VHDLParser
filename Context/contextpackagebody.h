#ifndef CONTEXTPACKAGEBODY_H
#define CONTEXTPACKAGEBODY_H

#include "Context/abstractcontext.h"

class ContextPackageBody : public AbstractContext
{
public:
  ContextPackageBody(QObject *parent = 0);

  VP_Word *analyze(VP_Word *firstWord);

};

#endif // CONTEXTPACKAGEBODY_H
