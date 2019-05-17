#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    fstream fin;
    string s;
    stringstream ss;

    fin.open("C:/Users/MatrizD42018/Documents/lul.txt");
    if(!fin.is_open()){
        cout<<"nada funcionou"<<endl;
        exit(0);
    }
    while(fin.good()){
        getline(fin, s);
        ss.str(s);
        ss>>s;
    }

    if(s.compare("dim")){
        int nx, ny, nz;
        ss>>nx>>ny>>nz;
        //Sculptor sculptor(nx, ny, nz);
    }

    else if(s.compare("putbox")){
        int x0, x1, y0, y1, z0, z1;
        float r, g, b, a;
        ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;

        //figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
    }
    else if(s.compare("cutbox")){
        int x0, x1, y0, y1, z0, z1;
        ss>>x0>>x1>>y0>>y1>>z0>>z1;

        //figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
    }


    //for(int i = 0; i< figs.size(); i++){
        //figs[i]->draw(sculptor);
    //}

    return 0;
}
