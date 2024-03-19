double f (double x1,double x2){return (x1*x2 + 4*(x1*x1*x1*x1)+x2*x2+3*x1);};


double dfx1 (double x1,double x2){return (x2+16*x1*x1*x1+3);};
double dfx2 (double x1,double x2){return (x1+2*x2);};
//template<class T,class D>
/*
std::vector<double>Df(std::function<double(double,double)>dfx1,std::function<double(double,double)>dfx2,double x1,double x2){
    std::vector<double> res;
    res.reserve(2);
    res[1] = dfx1(x1,x2);
    res[2] = dfx2(x1,x2);
    return res;
}
*/





