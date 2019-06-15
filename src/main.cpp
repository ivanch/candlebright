#include "Game.hpp"

int main()
{
    Game game;

    int primeiro=-1;
    int pos;
    cout<<"\nposicao: ";
    cin>>pos;
    int temp[10]= {9,8,7,6,5,4,3,2,1,0};
    primeiro=temp[pos];
    cout<<"Lista inicial: ";
    for(int i=0; i<10; i++)
    {
            cout<<temp[i]<<',';
    }
    cout<<endl;
    if(primeiro == -1)
    {
        cout<<"Lista Vazia"<<endl;
        return 0;
    }
    if(pos == 0)
    {
        primeiro = temp[1];
        temp[0]=-1;
        cout<< "Excluindo na posicao 0"<<endl;

        cout<<"Lista final: ";
        for(int i=0; i<10; i++)
        {
            if(temp[i]!=temp[pos])
                cout<<temp[i]<<',';
        }
        getchar();
        getchar();
        return 0;
    }
    cout<<endl;
    int i=0;
    while(temp[i+1]!=primeiro)
    {
        i++;
    }
    if(primeiro == -1 || temp[pos+1] == -1)
        cout<< "Excluindo em qualquer posicao "<<pos<<endl;

    int next = temp[i+2];
    temp[i+1]=-1;
    temp[i+2] = next;

    cout<<"Lista final: ";
    for(int i=0; i<10; i++)
    {
        if(temp[i]!= temp[pos])
            cout<<temp[i]<<',';
    }

    game.run();
    return 0;
}
