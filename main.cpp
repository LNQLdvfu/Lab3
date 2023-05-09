#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>

using namespace std;

void randomize_x(float a, float b, vector<float>& c);
void caculate_y(vector<float>& m,vector<float>& d);
float calculate_Differentiation(vector<float> &a, vector<float> &b, int n);
float factorial(int n);
float Directly_calculate(float x){return 2*x +M_PI*sin(x*M_PI);}


int main(){
    int n{};

    cout<<"input n:";
    cin>>n;
    const float a{0.1},b{0.6};
    vector<float>c(n+1);
    vector<float>d(n+1);
    randomize_x(a,b,c);
    caculate_y(d,c);

    for(int i{}; i<=n;i++){
        cout<<"x["<<i<<"]:"<<c[i]<<", ";
    }
    cout<<endl;
    for(int i{}; i<= n;i++){
        cout<<"f(x"<<i<<"):"<<d[i]<<", ";
    }
    cout<<endl;
    cout<<"Lagrange' interpolation differentiation at x[0] is: "<<calculate_Differentiation(c,d,n)<<endl;
    cout<<"Calculate directly follow the formula is:"<<Directly_calculate(c[0])<<endl;
    cout<<"the difference ratio is between calculating formula and Lagrange'interpolation differentiation is:"<<calculate_Differentiation(c,d,n) -Directly_calculate(c[0])<<endl;
}

void randomize_x(float a, float b, vector<float>& c){
    float h = (b - a)/c.size();
    for(int i {}; i < c.size(); i++){
        c[i] = a + i*h;
    }
}


void caculate_y(vector<float>& m,vector<float>& d){
    for(int i{}; i < m.size(); i++)
    {
        m[i] = pow(d[i],2) - cos(M_PI * d[i]);
    }
}

float calculate_Differentiation( vector<float> &a, vector<float> &b,int n)
{
    float ln{};
    for (int i{}; i <= n; i++)
    {
        float l_i{1};
        float ln_1{};
        for (int j{}; j <= n; j++)
        {
            float g_i{1};
            if (j != i)
            {
                l_i *= 1 / (a[i] - a[j]);
                for (int k{}; k <= n; k++)
                {
                    if (k != i && k != j)
                    {
                        g_i *= (a[0] - a[k]);
                    }
                }
                ln_1 += g_i;
            }
        }
        ln += ln_1 * l_i * b[i];
    }
    return ln;
}
float factorial(int n)
{
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}