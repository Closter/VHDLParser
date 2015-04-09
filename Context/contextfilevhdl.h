#ifndef CONTEXTFILEVHDL_H
#define CONTEXTFILEVHDL_H

#include "Context/abstractcontext.h"

/**
 * @brief The ContextFileVHDL class manage the context of a VHDL File
 */
class ContextFileVHDL : public AbstractContext
{
public:
  ContextFileVHDL(Word *startingWord, Word *endingWord, QObject *parent = 0);

  void analyze();
};

#endif // CONTEXTFILEVHDL_H
