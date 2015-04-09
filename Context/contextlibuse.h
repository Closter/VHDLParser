#ifndef CONTEXTLIBUSE_H
#define CONTEXTLIBUSE_H

#include "Context/abstractcontext.h"

class ContextLibUse : public AbstractContext
{
public:
  ContextLibUse(QObject *parent = 0);

  VP_Word* analyze(VP_Word *firstWord);

};

#endif // CONTEXTLIBUSE_H
