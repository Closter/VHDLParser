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
