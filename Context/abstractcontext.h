#ifndef ABSTRACTCONTEXT_H
#define ABSTRACTCONTEXT_H

#include <QObject>

#include "Parser/word.h"

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
  explicit AbstractContext(Word *startingWord, Word *endingWord, QObject *parent = 0);

  QList<Word*> getWordList();


  virtual void analyze() = 0; ///< Extract all sub context from this context


  // Accessors
  //----------
  Word *getStartingWord()
  {
    return m_startOfContext;
  }

  Word *getEndingWord()
  {
    return m_endOfContext;
  }


  //----------

private:

  Word *m_startOfContext; ///< The first word of this context
  Word *m_endOfContext;   ///< The last word of this context

  QList<AbstractContext*> m_subContextList; ///< The list of sub-context of this context

};

#endif // ABSTRACTCONTEXT_H
