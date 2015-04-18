#ifndef VP_LIBRARY_H
#define VP_LIBRARY_H

#include "vp_abstractdeclaration.h"

#define VP_LIBRARY_LIB_KEYWORD  "library"
#define VP_LIBRARY_USE_KEYWORD  "use"

#define VP_LIBRARY_USE_LIB_WORD_IX  1
#define VP_LIBRARY_USE_DOT1_IX      2
#define VP_LIBRARY_USE_PKG_WORD_IX  3
#define VP_LIBRARY_USE_DOT2_IX      4
#define VP_LIBRARY_USE_PKG_USE_IX   5
#define VP_LIBRARY_USE_ENDLINE_IX   6


/**
 * @brief The VP_Library class decribe a library declaration in VHDL
 */
class VP_Library : public VP_AbstractDeclaration
{
public:
  explicit VP_Library(QPoint posLibrary, QPoint posPackage, QString libraryName, QString packageName, QString partName);


  // Accessors
  //----------
  QPoint getPosPackage()
  {
    return m_posPackage;
  }

  QString getPacakgeName()
  {
    return m_package;
  }

  QString getPartName()
  {
    return m_part;
  }

  bool isAllPackageUsed()
  {
    return m_allPackages;
  }

  //----------


private:

  QPoint m_posLibrary; ///< library declaration position into the analyze text (x for line number and y for col number)
  QPoint m_posPackage; ///< package declaration position into the analyze text (x for line number and y for col number)

  QString m_library;      ///< library name
  QString m_package;      ///< package name
  QString m_part;         ///< part used name (may be "ALL", meaning all the package)

  bool m_allPackages;     ///< Flag indicating that all paackage's part are used

};

#endif // VP_LIBRARY_H
