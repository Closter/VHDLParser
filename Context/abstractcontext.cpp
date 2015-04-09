#include "abstractcontext.h"

AbstractContext::AbstractContext(Word *startingWord, Word *endingWord, QObject *parent) :
  QObject(parent)
{

  m_startOfContext = startingWord;
  m_endOfContext = endingWord;

}



/**
 * @brief AbstractContext::getWordList
 * @return A list of Word of this context
 */
QList<Word*> AbstractContext::getWordList()
{
  QList<Word*> wordList;

  wordList << m_startOfContext; // The first word is part of the list

  while(wordList.last()->nextWord() != m_endOfContext)  // Proceed to the end of context word
    wordList << wordList.last()->nextWord();

  wordList << m_endOfContext; // The last word is part of the list

  return wordList;
}


