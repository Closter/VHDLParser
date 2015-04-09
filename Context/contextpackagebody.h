#ifndef CONTEXTPACKAGEBODY_H
#define CONTEXTPACKAGEBODY_H

#include "Context/abstractcontext.h"

class ContextPacKagEbody : public AbstractContext
{
public:
  ContextPacKagEbody(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTPACKAGEBODY_H
