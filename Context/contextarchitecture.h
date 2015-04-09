#ifndef CONTEXTARCHITECTURE_H
#define CONTEXTARCHITECTURE_H

#include "Context/abstractcontext.h"

class ContextArchitEcture : public AbstractContext
{
public:
  ContextArchitEcture(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);

};

#endif // CONTEXTARCHITECTURE_H
