// This file was generated by qlalr - DO NOT EDIT!
#ifndef JSONPARSER_CPP
#define JSONPARSER_CPP

class JsonGrammar
{
public:
  enum VariousConstants {
    EOF_SYMBOL = 0,
    ERROR = 12,
    T_COLON = 7,
    T_COMMA = 8,
    T_FALSE = 9,
    T_LCURLYBRACKET = 3,
    T_LSQUAREBRACKET = 5,
    T_NULL = 11,
    T_NUMBER = 2,
    T_RCURLYBRACKET = 4,
    T_RSQUAREBRACKET = 6,
    T_STRING = 1,
    T_TRUE = 10,

    ACCEPT_STATE = 12,
    RULE_COUNT = 18,
    STATE_COUNT = 26,
    TERMINAL_COUNT = 13,
    NON_TERMINAL_COUNT = 8,

    GOTO_INDEX_OFFSET = 26,
    GOTO_INFO_OFFSET = 37,
    GOTO_CHECK_OFFSET = 37
  };

  static const char  *const    spell [];
  static const short             lhs [];
  static const short             rhs [];

#ifndef QLALR_NO_JSONGRAMMAR_DEBUG_INFO
  static const int     rule_index [];
  static const int      rule_info [];
#endif // QLALR_NO_JSONGRAMMAR_DEBUG_INFO

  static const short    goto_default [];
  static const short  action_default [];
  static const short    action_index [];
  static const short     action_info [];
  static const short    action_check [];

  static inline int nt_action (int state, int nt)
  {
    const int yyn = action_index [GOTO_INDEX_OFFSET + state] + nt;
    if (yyn < 0 || action_check [GOTO_CHECK_OFFSET + yyn] != nt)
      return goto_default [nt];

    return action_info [GOTO_INFO_OFFSET + yyn];
  }

  static inline int t_action (int state, int token)
  {
    const int yyn = action_index [state] + token;

    if (yyn < 0 || action_check [yyn] != token)
      return - action_default [state];

    return action_info [yyn];
  }
};


const char *const JsonGrammar::spell [] = {
  "end of file", "string", "number", "{", "}", "[", "]", ":", ",", "false", 
  "true", "null", "error", 
#ifndef QLALR_NO_JSONGRAMMAR_DEBUG_INFO
"Root", "Value", "Object", "Members", "Member", "Array", "Values", 
  "$accept"
#endif // QLALR_NO_JSONGRAMMAR_DEBUG_INFO
};

const short JsonGrammar::lhs [] = {
  13, 15, 16, 16, 16, 17, 14, 14, 14, 14, 
  14, 14, 14, 18, 19, 19, 19, 20};

const short JsonGrammar::rhs [] = {
  1, 3, 1, 3, 0, 3, 1, 1, 1, 1, 
  1, 1, 1, 3, 1, 3, 0, 2};


#ifndef QLALR_NO_JSONGRAMMAR_DEBUG_INFO
const int JsonGrammar::rule_info [] = {
    13, 14
  , 15, 3, 16, 4
  , 16, 17
  , 16, 16, 8, 17
  , 16
  , 17, 1, 7, 14
  , 14, 9
  , 14, 10
  , 14, 11
  , 14, 15
  , 14, 18
  , 14, 2
  , 14, 1
  , 18, 5, 19, 6
  , 19, 14
  , 19, 19, 8, 14
  , 19
  , 20, 13, 0};

const int JsonGrammar::rule_index [] = {
  0, 2, 6, 8, 12, 13, 17, 19, 21, 23, 
  25, 27, 29, 31, 35, 37, 41, 42};
#endif // QLALR_NO_JSONGRAMMAR_DEBUG_INFO

const short JsonGrammar::action_default [] = {
  0, 11, 10, 0, 7, 5, 17, 9, 12, 13, 
  8, 1, 18, 3, 0, 0, 0, 2, 4, 0, 
  6, 15, 0, 0, 14, 16};

const short JsonGrammar::goto_default [] = {
  3, 11, 2, 14, 13, 1, 22, 0};

const short JsonGrammar::action_index [] = {
  24, -13, -13, 0, -13, 12, 24, -13, -13, -13, 
  -13, -13, -13, -13, -1, -6, 12, -13, -13, 7, 
  -13, -13, -4, 24, -13, -13, 

  -8, -8, -8, -8, -8, -8, -1, -8, -8, -8, 
  -8, -8, -8, -8, -8, -8, -2, -8, -8, 0, 
  -8, -8, -8, 6, -8, -8};

const short JsonGrammar::action_info [] = {
  12, 19, 24, 17, 23, 0, 0, 16, 9, 8, 
  5, 0, 6, 15, 0, 0, 4, 10, 7, 0, 
  0, 0, 0, 0, 0, 9, 8, 5, 0, 6, 
  0, 0, 0, 4, 10, 7, 0, 

  21, 20, 18, 0, 0, 0, 0, 25, 0, 0, 
  0, 0, 0, 0};

const short JsonGrammar::action_check [] = {
  0, 7, 6, 4, 8, -1, -1, 8, 1, 2, 
  3, -1, 5, 1, -1, -1, 9, 10, 11, -1, 
  -1, -1, -1, -1, -1, 1, 2, 3, -1, 5, 
  -1, -1, -1, 9, 10, 11, -1, 

  1, 1, 4, -1, -1, -1, -1, 1, -1, -1, 
  -1, -1, -1, -1};


#line 28 "json.g"

/****************************************************************************
**
** Copyright (c) 2010 Girish Ramakrishnan <girish@forwardbias.in>
**
** Use, modification and distribution is allowed without limitation,
** warranty, liability or support of any kind.
**
****************************************************************************/

#ifndef JSONPARSER_P_H
#define JSONPARSER_P_H

#include <QString>
#include <QVariant>
#include <QVector>

class JsonLexer
{
public:
    JsonLexer(const QByteArray &data);
    ~JsonLexer();

    int lex();
    QVariant symbol() const { return m_symbol; }
    int lineNumber() const { return m_lineNumber; }
    int pos() const { return m_pos; }

private:
    int parseNumber();
    int parseString();
    int parseKeyword();

    QByteArray m_data;
    int m_lineNumber;
    int m_pos;
    QVariant m_symbol;
    QHash<QByteArray, int> m_keywords;
};

class JsonParser : protected JsonGrammar
{
public:
    JsonParser();
    ~JsonParser();

    bool parse(JsonLexer *lex);
    QVariant result() const { return m_result; }
    QString errorMessage() const { return QString("%1 at line %2 pos %3").arg(m_errorMessage).arg(m_errorLineNumber).arg(m_errorPos); }

private:
    void reallocateStack();

    inline QVariant &sym(int index)
    { return m_symStack[m_tos + index - 1]; }

    int m_tos;
    QVector<int> m_stateStack;
    QVector<QVariant> m_symStack;
    QString m_errorMessage;
    int m_errorLineNumber;
    int m_errorPos;
    QVariant m_result;
};

#endif // JSONPARSER_P_H

#line 96 "json.g"

/****************************************************************************
**
** Copyright (c) 2010 Girish Ramakrishnan <girish@forwardbias.in>
**
** Use, modification and distribution is allowed without limitation,
** warranty, liability or support of any kind.
**
****************************************************************************/

#include <QtDebug>

JsonLexer::JsonLexer(const QByteArray &ba)
    : m_data(ba), m_lineNumber(1), m_pos(0)
{
    m_keywords.insert("true", JsonGrammar::T_TRUE);
    m_keywords.insert("false", JsonGrammar::T_FALSE);
    m_keywords.insert("null", JsonGrammar::T_NULL);
}

JsonLexer::~JsonLexer()
{
}

int JsonLexer::parseString()
{
    QString str;
    bool esc = false;
    ++m_pos; // skip initial "
    for (; m_pos < m_data.length(); ++m_pos) {
        const char c = m_data[m_pos];
        if (esc) {
            if (c == 'b') str += '\b';
            else if (c == 'f') str += '\f';
            else if (c == 'n') str += '\n';
            else if (c == 'r') str += '\r';
            else if (c == 't') str += '\t';
            else if (c == '\\') str += '\\';
            else if (c == '\"') str += '\"';
            else if (c == 'u' && m_pos+4<m_data.length()-1) {
                QByteArray u1 = m_data.mid(m_pos+1, 2);
                QByteArray u2 = m_data.mid(m_pos+3, 2);
                bool ok;
                str += QChar(u2.toInt(&ok, 16), u1.toInt(&ok, 16));
                m_pos += 4;
            } else {
                str += c;
            }
            esc = false;
        } else if (c == '\\') {
            esc = true;
        } else if (c == '\"') {
            m_symbol = str;
            ++m_pos;
            return JsonGrammar::T_STRING;
        } else {
            str += c;
        }
    }
    return JsonGrammar::ERROR;
}

int JsonLexer::parseNumber()
{
    int start = m_pos;
    bool isDouble = false;
    for (; m_pos < m_data.length(); ++m_pos) {
        const char c = m_data[m_pos];
        if (c == '+' || c == '-' || (c >= '0' && c <= '9'))
            continue;
        if (c == '.' || c == 'e' || c == 'E') {
            isDouble = true;
            continue;
        }
        break;
    }
    QByteArray number = QByteArray::fromRawData(m_data.constData()+start, m_pos-start);
    bool ok;
    if (!isDouble) {
        m_symbol = number.toInt(&ok);
        if (!ok)
            m_symbol = number.toLongLong(&ok);
    }
    if (isDouble || !ok)
        m_symbol = number.toDouble();
    return JsonGrammar::T_NUMBER;
}

int JsonLexer::parseKeyword()
{
    int start = m_pos;
    for (; m_pos < m_data.length(); ++m_pos) {
        const char c = m_data[m_pos];
        if (c >= 'a' && c <= 'z')
            continue;
        break;
    }
    QByteArray keyword = QByteArray::fromRawData(m_data.constData()+start, m_pos-start);
    if (m_keywords.contains(keyword))
        return m_keywords.value(keyword);
    return JsonGrammar::ERROR;
}

int JsonLexer::lex()
{
    m_symbol.clear();
    while (m_pos < m_data.length()) {
        const char c = m_data[m_pos];
        switch (c) {
        case '[': ++m_pos; return JsonGrammar::T_LSQUAREBRACKET;
        case ']': ++m_pos; return JsonGrammar::T_RSQUAREBRACKET;
        case '{': ++m_pos; return JsonGrammar::T_LCURLYBRACKET;
        case '}': ++m_pos; return JsonGrammar::T_RCURLYBRACKET;
        case ':': ++m_pos; return JsonGrammar::T_COLON;
        case ',': ++m_pos; return JsonGrammar::T_COMMA;
        case ' ': case '\r': case '\t': case 'b': ++m_pos; break;
        case '\n': ++m_pos; ++m_lineNumber; break;
        case '"': return parseString();
        default: 
            if (c == '+' || c == '-' || (c >= '0' && c <= '9')) {
                return parseNumber(); 
            }
            if (c >= 'a' && c <= 'z') {
                return parseKeyword();
            }
            return JsonGrammar::ERROR;
        }
    }
    return JsonGrammar::EOF_SYMBOL;
}

JsonParser::JsonParser()
{
}

JsonParser::~JsonParser()
{
}

void JsonParser::reallocateStack()
{
    int size = m_stateStack.size();
    if (size == 0)
        size = 128;
    else
        size <<= 1;
    m_symStack.resize(size);
    m_stateStack.resize(size);
}

bool JsonParser::parse(JsonLexer *lexer)
{
    const int INITIAL_STATE = 0;
    int yytoken = -1;
    reallocateStack();
    m_tos = 0;
    m_stateStack[++m_tos] = INITIAL_STATE;

    while (true) {
        const int state = m_stateStack[m_tos];
        if (yytoken == -1 && -TERMINAL_COUNT != action_index[state]) {
            yytoken = lexer->lex();
        }
        int act = t_action(state, yytoken);
        if (act == ACCEPT_STATE)
            return true;
        else if (act > 0) {
            if (++m_tos == m_stateStack.size())
                reallocateStack();
            m_stateStack[m_tos] = act;
            m_symStack[m_tos] = lexer->symbol();
            yytoken = -1;
        } else if (act < 0) {
            int r = -act-1;
            m_tos -= rhs[r];
            act = m_stateStack.at(m_tos++);
            switch (r) {

#line 276 "json.g"
          case 0: { m_result = sym(1); break; } 
#line 279 "json.g"
          case 1: { sym(1) = sym(2); break; } 
#line 284 "json.g"
          case 3: { sym(1) = sym(1).toMap().unite(sym(3).toMap()); break; } 
#line 287 "json.g"
          case 4: { sym(1) = QVariantMap(); break; } 
#line 290 "json.g"
          case 5: { QVariantMap map; map.insert(sym(1).toString(), sym(3)); sym(1) = map; break; } 
#line 293 "json.g"
          case 6: { sym(1) = QVariant(false); break; } 
#line 296 "json.g"
          case 7: { sym(1) = QVariant(true); break; } 
#line 305 "json.g"
          case 13: { sym(1) = sym(2); break; } 
#line 308 "json.g"
          case 14: { QVariantList list; list.append(sym(1)); sym(1) = list; break; } 
#line 311 "json.g"
          case 15: { QVariantList list = sym(1).toList(); list.append(sym(3)); sym(1) = list; break; } 
#line 314 "json.g"
          case 16: { sym(1) = QVariantList(); break; } 
#line 316 "json.g"

            } // switch
            m_stateStack[m_tos] = nt_action(act, lhs[r] - TERMINAL_COUNT);
        } else {
            int ers = state;
            int shifts = 0;
            int reduces = 0;
            int expected_tokens[3];
            for (int tk = 0; tk < TERMINAL_COUNT; ++tk) {
                int k = t_action(ers, tk);

                if (! k)
                  continue;
                else if (k < 0)
                  ++reduces;
                else if (spell[tk]) {
                    if (shifts < 3)
                      expected_tokens[shifts] = tk;
                    ++shifts;
                }
            }

            m_errorLineNumber = lexer->lineNumber();
            m_errorPos = lexer->pos();
            m_errorMessage.clear();
            if (shifts && shifts < 3) {
                bool first = true;

                for (int s = 0; s < shifts; ++s) {
                    if (first)
                      m_errorMessage += QLatin1String("Expected ");
                    else
                      m_errorMessage += QLatin1String(", ");

                    first = false;
                    m_errorMessage += QLatin1String("'");
                    m_errorMessage += QLatin1String(spell[expected_tokens[s]]);
                    m_errorMessage += QLatin1String("'");
                }
            }
            return false;
        }
    }

    return false;
}


#endif // JSONPARSER_CPP

