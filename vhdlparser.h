#ifndef VHDLPARSER_H
#define VHDLPARSER_H

#include <QObject>
#include <QFile>


//#define VP_VHDL_SX_SEP_CAR_COMMENTARY         "--"
//#define VP_VHDL_SX_SEP_CAR_DOT                "."
//#define VP_VHDL_SX_SEP_CAR_COLON              ":"
//#define VP_VHDL_SX_SEP_CAR_SEMICOLON          ";"
//#define VP_VHDL_SX_SEP_CAR_COMMA              ","
//#define VP_VHDL_SX_SEP_CAR_SIGNAL_ASSIGNEMENT "<="
//#define VP_VHDL_SX_SEP_CAR_VAR_ASSIGNEMENT    ":="
//#define VP_VHDL_SX_SEP_CAR_PORT_ASSIGNEMENT   "=>"
//#define VP_VHDL_SX_SEP_CAR_OPEN_BRACKET       "("
//#define VP_VHDL_SX_SEP_CAR_CLOSE_BRACKET      ")"
//#define VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL      "="
//#define VP_VHDL_SX_SEP_CAR_COMPARE_UNEQUAL    "/="
//#define VP_VHDL_SX_SEP_CAR_COMPARE_MORE       ">"
//#define VP_VHDL_SX_SEP_CAR_COMPARE_LESS       "<"
//#define VP_VHDL_SX_SEP_CAR_COMPARE_MORE_EQUAL ">="
//#define VP_VHDL_SX_SEP_CAR_COMPARE_EQUAL_LESS "=<"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_PLUS      "+"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_MINUS     "-"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_MULTIPLY  "*"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_DIVIDE    "/"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_EXPO      "**"
//#define VP_VHDL_SX_SEP_CAR_OPERATOR_CONCAT    "&"

#define VP_VHDL_SX_SEP_CAR_REGEXP       "(\\-\\-|\\.|:|;|,|<=|:=|=>|\\(|\\)|=|/=|>|<|>=|=<|\\+|\\-|\\*|/|\\*\\*|&)"
#define VP_VHDL_SX_SEP_CAR_1CAR_REGEXP  "(\\.|:|;|,|\\(|\\)|=|>|<|\\+|\\-|\\*|/|&)"
#define VP_VHDL_SX_SEP_CAR_2CAR_REGEXP  "(\\-\\-|<=|:=|=>|/=|>=|=<|\\*\\*)"




/**
 * @brief The VHDLParser class contains a VHDL module's structural representation.
 *
 */
class VHDLParser : public QObject
{
  Q_OBJECT
public:

  explicit VHDLParser(QObject *parent = 0);

  bool analyzeFile(QFile *file);

signals:

public slots:

};

#endif // VHDLPARSER_H
