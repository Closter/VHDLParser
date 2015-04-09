#ifndef CONTEXTLIBDECLARATION_H
#define CONTEXTLIBDECLARATION_H

#include "Context/abstractcontext.h"

class ContextLibDeclaration : public AbstractContext
{
public:
  ContextLibDeclaration(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTLIBDECLARATION_H
