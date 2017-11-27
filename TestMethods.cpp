//
// Created by ace89 on 13/07/17.
//

#include "TestMethods.h"

namespace OptionPricer
{
    bool TestMethods::TestDataStruct()
    {
        DataStruct<char>* a = new DataStruct<char>('A');
        a->SetHead(NULL);

        DataStruct<char>* w = new DataStruct<char>('P');
        w->SetHead(a);

        DataStruct<char>* _a = new DataStruct<char>('P');
        _a->SetHead(w);

        DataStruct<char>* i = new DataStruct<char>('L');
        i->SetHead(_a);

        DataStruct<char>* s = new DataStruct<char>('E');
        s->SetHead(i);

        // while loop to read the data values

        DataStruct<char>* cont = s;

        std::string output;

        while(cont != NULL)
        {
            output.push_back(cont->GetVariable());
            cont = cont->GetHead();
        }

        std::reverse(output.begin(),output.end());

        if(output == "APPLE")
        {
            return true;
        }else
        {
            return false;
        }

    }


}

