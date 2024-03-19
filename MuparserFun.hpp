#include <muParser.h>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

class MuparserFun {
public:
    MuparserFun(const MuparserFun &m):m_parser(m.m_parser){
        m_parser.DefineVar("x", &m_x);
        m_parser.DefineVar("y", &m_y);
    }

     MuparserFun(const std::string &s)
  {
    try
      {
        m_parser.DefineVar("x", &m_x);
        m_parser.DefineVar("y", &m_y);
        m_parser.SetExpr(s);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };
    double operator()(const double& x1, const double& x2) {
        m_x = x1;
        m_y = x2;
        try {
            return m_parser.Eval();
        } catch (mu::Parser::exception_type &e) {
            std::cerr << e.GetMsg() << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
    }

private:
    double m_x;
    double m_y;
    mu::Parser m_parser;
};
    
