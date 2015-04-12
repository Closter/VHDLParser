#ifndef CONTEXTLIBDECLARATION_H
#define CONTEXTLIBDECLARATION_H

#include "Context/abstractcontext.h"

#include "VHDL_Syntaxe.h"
#include "Elements/vp_library.h"

/**
 * @brief The ContextLibDeclaration class contains all the elements
 * of the library context : library declaration and library use
 */
class ContextLibrary : public AbstractContext
{
public:
  ContextLibrary(QObject *parent = 0);

  VP_Word *analyze(VP_Word *firstWord);

private:

  QList<VP_Library*>  m_library; // The library of this context
};

#endif // CONTEXTLIBDECLARATION_H
