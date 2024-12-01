#include <sstream>
using namespace std;

// abstract class
class Function {
   public:
    static Function* parse(stringstream& ss);
    virtual Function* differential() = 0;
    virtual double eval(double) = 0;
};
#include <cmath>
// your implementation begins here
class Constant : public Function {
   public:
    Constant(double value)
        : value(value) {  // 建構子
    }
    static Constant* create(double value) {
        return new Constant(value);
    }
    Function* differential() override {
        return new Constant(0);  // 常數的導數為 0
    }
    double eval(double x) override {
        return value;  // 常數的值不變
    }

   private:
    double value;
};

class Variable : public Function {
   public:
    Variable(string name)
        : name(name) {
    }
    static Variable* create(string name) {
        return new Variable(name);
    }  // 靜態 create 函式
    Function* differential() override {
        return new Constant(1);  // 變數 x 的導數是 1
    }  // 微分函式
    double eval(double x) override {
        return x;  // 變數 x 的值就是傳入的 x
    }  // 求值函式
   private:
    string name;  // 變數名稱
};

class Arithmetic : public Function {
   public:
    Arithmetic(Function* l, char op, Function* r)
        : l(l), op(op), r(r) {
    }
    static Arithmetic* create(Function* l, char op, Function* r) {
        return new Arithmetic(l, op, r);
    }
    Function* differential() override {
        switch (op) {
            case '+':
                return new Arithmetic(l->differential(), '+', r->differential());
            case '-':
                return new Arithmetic(l->differential(), '-', r->differential());
            case '*':
                return new Arithmetic(new Arithmetic(l->differential(), '*', r), '+',
                                      new Arithmetic(l, '*', r->differential()));
            case '/':
                return new Arithmetic(new Arithmetic(new Arithmetic(l->differential(), '*', r), '-',
                                                     new Arithmetic(l, '*', r->differential())),
                                      '/', new Arithmetic(r, '*', r));
        }
        return nullptr;  // To avoid compiler warning
    }
    double eval(double x) override {
        switch (op) {
            case '+':
                return l->eval(x) + r->eval(x);
            case '-':
                return l->eval(x) - r->eval(x);
            case '*':
                return l->eval(x) * r->eval(x);
            case '/':
                return l->eval(x) / r->eval(x);
        }
        return 0;  // To avoid compiler warning
    }

   private:
    Function* l;
    Function* r;
    char op;
};

class Polynomial : public Function {
   public:
    Polynomial(Function* base, Function* exp)
        : base(base), exp(exp) {
    }
    static Polynomial* create(Function* base, Function* exp) {
        return new Polynomial(base, exp);
    }
    Function* differential() override {
        // (base ** exp)' = exp * base ** (exp - 1) * base'
        return new Arithmetic(new Arithmetic(exp, '*', new Polynomial(base, new Arithmetic(exp, '-', new Constant(1)))),
                              '*', base->differential());
    }
    double eval(double x) override {
        return pow(base->eval(x), exp->eval(x));
    }

   private:
    Function *base, *exp;
};

class Sin : public Function {
   public:
    Sin(Function* base)
        : base(base) {
    }
    static Sin* create(Function* base) {
        return new Sin(base);
    }
    Function* differential() override;
    double eval(double x) override {
        return sin(base->eval(x));
    }

   private:
    Function* base;  // 基底
};

class Cos : public Function {
   public:
    Cos(Function* base)
        : base(base) {
    }
    static Cos* create(Function* base) {
        return new Cos(base);
    }
    Function* differential() override {
        return new Arithmetic(new Constant(-1), '*', new Arithmetic(base->differential(), '*', new Sin(base)));
    }
    double eval(double x) override {
        return cos(base->eval(x));
    }

   private:
    Function* base;  // 基底
};

Function* Sin::differential() {
    return new Arithmetic(new Cos(base), '*', base->differential());
}
// end

#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
Function* Function::parse(stringstream& ss) {
    static auto NUMBER_LITERAL = regex(R"(^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$)");
    static auto ARITHMETIC_OP = regex(R"(^[+\-*\/]$)");
    Function* res;
    string slice, test;
    ss >> slice;
    if (regex_match(slice, NUMBER_LITERAL))  // constant
    {
        res = Constant::create(stod(slice));
    } else if (slice == "x")  // variable
    {
        res = Variable::create(slice);
    } else if (slice == "**")  // Polynomial
    {
        Function* base = parse(ss);
        Function* exp = parse(ss);
        res = Polynomial::create(base, exp);
    } else if (regex_match(slice, ARITHMETIC_OP))  // Arithmetic
    {
        Function* l = parse(ss);
        Function* r = parse(ss);
        res = Arithmetic::create(l, slice[0], r);
    } else if (slice == "sin")  // sin
    {
        Function* base = parse(ss);
        res = Sin::create(base);
    } else if (slice == "cos")  // cos
    {
        Function* base = parse(ss);
        res = Cos::create(base);
    }
    return res;
}

Function* create_function(const string& in) {
    stringstream ss(in);
    return Function::parse(ss);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int q;
    double val;
    getline(cin, str);
    Function* f = create_function(str);
    Function* df = f->differential();
    cin >> q;
    while (q--) {
        cin >> val;
        cout << fixed << setprecision(2) << "f(x)=" << f->eval(val) << ", f'(x)=" << df->eval(val) << '\n';
    }
    return 0;
}