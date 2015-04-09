#ifndef VP_WORD_H
#define VP_WORD_H

#include "Parser/word.h"

/**
 * @brief The VP_Word class manage an word element. This is the base
 * of all the code analysis.
 */
class VP_Word : public Word
{
  Q_OBJECT
public:
  explicit VP_Word(QString word, int lineNumber = 0, int colNumber = 0, bool isKeyword = false, bool isComment = false, VP_Word *previous = NULL, VP_Word *next = NULL, QObject *parent = 0);
  explicit VP_Word(Word *word, bool isKeyword = false, QObject *parent = 0);




private:

  bool m_isKeyword; ///< Indicate that this word is a VHDL keyword

};

#endif // VP_WORD_H
