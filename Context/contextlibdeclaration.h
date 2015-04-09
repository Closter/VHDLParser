#ifndef CONTEXTLIBDECLARATION_H
#define CONTEXTLIBDECLARATION_H

#include "Context/abstractcontext.h"

class ContextLibDeclaration : public AbstractContext
{
public:
  ContextLibDeclaration(QObject *parent = 0);

  VP_Word *analyze(VP_Word *firstWord);

};

#endif // CONTEXTLIBDECLARATION_H
