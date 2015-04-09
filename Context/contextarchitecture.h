#ifndef CONTEXTARCHITECTURE_H
#define CONTEXTARCHITECTURE_H

#include "Context/abstractcontext.h"

class ContextArchitEcture : public AbstractContext
{
public:
  ContextArchitEcture(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTARCHITECTURE_H
