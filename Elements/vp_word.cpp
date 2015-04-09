#include "vp_word.h"


VP_Word::VP_Word(QString word, int lineNumber, int colNumber, bool isKeyword, bool isComment, VP_Word *previous, VP_Word *next, QObject *parent) :
  Word(word, lineNumber, colNumber, isComment, previous, next, parent)
{
  m_isKeyword = isKeyword;
}


VP_Word::VP_Word(Word *word, bool isKeyword, QObject *parent) :
  Word(word->getText(), word->getLine(), word->getColumn(), word->isComment(), word->previousWord(), word->nextWord(), parent)
{
  m_isKeyword = isKeyword;
}


