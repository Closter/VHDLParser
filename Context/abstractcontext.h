#ifndef ABSTRACTCONTEXT_H
#define ABSTRACTCONTEXT_H

#include <QObject>

#include "Elements/vp_word.h"

/**
 * @brief The AbstractContext class decribe a context of a VHDL structure :
 * - an entity port declaration
 * - an architecure declaration
 * - a process
 * - a condition
 * -...
 * A context is hierarchical and can contains one or more context.
 */
class AbstractContext : public QObject
{
  Q_OBJECT
public:
  explicit AbstractContext(VP_Word *startingWord, VP_Word *endingWord, QObject *parent = 0);

  virtual void analyze(VP_Word *firstWord) = 0; ///< Extract all sub context from this context


  // Accessors
  //----------
  VP_Word *getWordList()
  {
    return m_wordList;
  }


  //----------

protected:

  QList<VP_Word*> m_wordList;  ///< Context's word list

  QList<AbstractContext*> m_subContextList; ///< The list of sub-context of this context

};

#endif // ABSTRACTCONTEXT_H
