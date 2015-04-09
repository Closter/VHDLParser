#ifndef CONTEXTFILEVHDL_H
#define CONTEXTFILEVHDL_H

#include "Context/abstractcontext.h"

#include "Elements/vp_word.h"

/**
 * @brief The ContextFileVHDL class manage the context of a VHDL File
 */
class ContextFileVHDL : public AbstractContext
{
public:
  ContextFileVHDL(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  void analyze(VP_Word *firstWord);


private:

  static QList<QString> m_keywordList;

};

#endif // CONTEXTFILEVHDL_H
