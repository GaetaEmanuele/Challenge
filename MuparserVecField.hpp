#include <muParser.h>
#include <string>
#include <vector>

class MuparserVecField
{
public:
    MuparserVecField(const MuparserVecField &m)
        : m_parser_x(m.m_parser_x), m_parser_y(m.m_parser_y)
    {
        m_parser_x.DefineVar("x", &m_var_x);
        m_parser_x.DefineVar("y", &m_var_y);
        m_parser_y.DefineVar("x", &m_var_x);
        m_parser_y.DefineVar("y", &m_var_y);
    };

    MuparserVecField(const std::string &expr_x, const std::string &expr_y)
    {
        try
        {
            m_parser_x.DefineVar("x", &m_var_x);
            m_parser_x.DefineVar("y", &m_var_y);
            m_parser_y.DefineVar("x", &m_var_x);
            m_parser_y.DefineVar("y", &m_var_y);
            m_parser_x.SetExpr(expr_x);
            m_parser_y.SetExpr(expr_y);
        }
        catch (mu::Parser::exception_type &e)
        {
            std::cerr << e.GetMsg() << std::endl;
        }
    };

    std::vector<double> operator()(const double &x, const double &y)
    {
        m_var_x = x;
        m_var_y = y;
        double result_x = m_parser_x.Eval();
        double result_y = m_parser_y.Eval();
        return {result_x, result_y};
    };

private:
    double m_var_x;
    double m_var_y;
    mu::Parser m_parser_x;
    mu::Parser m_parser_y;
};

