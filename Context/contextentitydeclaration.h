#ifndef CONTEXTENTITYDECLARATION_H
#define CONTEXTENTITYDECLARATION_H

#include "Context/abstractcontext.h"

class ContextEntItyDeclaration : public AbstractContext
{
public:
  ContextEntItyDeclaration(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTENTITYDECLARATION_H
