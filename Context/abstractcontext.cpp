#include "abstractcontext.h"

AbstractContext::AbstractContext(VP_Word *startingWord, VP_Word *endingWord, QObject *parent) :
  QObject(parent)
{

  m_wordList << startingWord; // The first word is part of the list

  while(m_wordList.last()->nextWord() != endingWord)  // Proceed to the end of context word
    m_wordList << m_wordList.last()->nextWord();

  m_wordList << endingWord; // The last word is part of the list

}



