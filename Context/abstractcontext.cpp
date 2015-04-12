#include "abstractcontext.h"

AbstractContext::AbstractContext(QObject *parent) :
  QObject(parent)
{

}



/**
 * @brief AbstractContext::creatSubContext Add this new subcontext to the list and start the analyze
 * @param context The new sub context
 * @param firstWord The first word of the new context to analyze
 * @return The word next to the end of this context
 */
VP_Word* AbstractContext::newSubContext(AbstractContext *context, VP_Word *firstWord)
{
  if(firstWord == NULL)
    return NULL;

  m_subContextList << context;  // Add this subcontext to the list

  VP_Word *w = context->analyze(firstWord);  // Start analyze this subcontext

  return w;
}


/**
 * @brief AbstractContext::lookForWords Search for a word in this context.
 * The search stop at the first keyword don't know in this context.
 * @param firstWord The first word to start the search
 * @param wordText The text of the word to find
 * @return A list of correspondig word
 */
QList<VP_Word*> AbstractContext::lookForWords(VP_Word *firstWord, QString wordText)
{
  QList<VP_Word*> wordList;
  VP_Word         *currentWord = firstWord;

  do
  {
    if(currentWord->isKeyword())
    {
      if(isKeywordFromThisContext(currentWord))
      {
        if(currentWord->getText().compare(wordText, Qt::CaseInsensitive) == 0)  // Is the word to look for
          wordList << currentWord;  // Yes
      }
      else  // Not a keyword from this context
        break;  // End of look
    }

    currentWord = currentWord->nextWord();

  }while(currentWord != NULL);

  return wordList;
}



/**
 * @brief AbstractContext::isKeywordFromThisContext Check if this word is a keyword manage by this context
 * @param word Word to check
 * @return True if this word have to be manage by this context, otherwise False
 */
bool AbstractContext::isKeywordFromThisContext(VP_Word *word)
{
  bool keywordFromContext = false;

  foreach(QString str, m_contextKeywordList)  // Search in all the list of keyword list
  {
    if(word->getText().compare(str, Qt::CaseInsensitive) == 0)  // Case insensitive compare
    {
      keywordFromContext = true;  // Founded
      break;  // Don't need to look after
    }
  }

  return keywordFromContext;
}


/**
 * @brief AbstractContext::lastWordOfThisContext Search and return the last word of this context :
 * the next word is the first word of the next context (always a keyword).
 * @param firstWord The first word to start the search.
 * @return The last word of this context.
 */
VP_Word* AbstractContext::lastWordOfThisContext(VP_Word *firstWord)
{
  VP_Word *currentWord = firstWord;

  while(currentWord->nextWord() != NULL)
  {
    if(currentWord->nextWord()->isKeyword())
    {
      if(!isKeywordFromThisContext(currentWord->nextWord()))  // This keyword is not from this context
      {
        break;
      }
    }

    currentWord = currentWord->nextWord();
  }

  return currentWord;
}
