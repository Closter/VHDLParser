#ifndef CONTEXTPACKAGEDECLARATION_H
#define CONTEXTPACKAGEDECLARATION_H

#include "Context/abstractcontext.h"

class ContextPacKagEdeclaration : public AbstractContext
{
public:
  ContextPacKagEdeclaration(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTPACKAGEDECLARATION_H
