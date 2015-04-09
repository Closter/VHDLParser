#ifndef CONTEXTLIBUSE_H
#define CONTEXTLIBUSE_H

#include "Context/abstractcontext.h"

class ContextLibUse : public AbstractContext
{
public:
  ContextLibUse(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);

};

#endif // CONTEXTLIBUSE_H
