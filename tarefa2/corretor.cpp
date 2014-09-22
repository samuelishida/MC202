#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

#define ever (;;)

using namespace std;

int main(int argc, char *argv[])
{
    string in, arq="", n="", res1="",res2="",cmd="";
    char cstr[127];
    int num;

    in += (argv[1]);

    num = atoi(argv[2]);

    #ifdef __unix__
		cmd += "rm -f FC.log";
	#elif _WIN32
		cmd += "del FC.log";
	#endif

    system(cmd.c_str());
    cmd.erase();
    n.erase();

    for(int i=2; i<=num; i+=2)
    {
        n += (i < 10)?( "0" ):("1");
        n += (i%10)+48;

        arq += "arq";
        arq += n;
        arq += ".in";

        res1 += "arq";
        res1 += n;
        res1 += ".res";

        res2 += "arq";
        res2 += n;
        res2 += ".out";

        cmd = in + "<" + arq + ">" + res2;

        strcpy (cstr, cmd.c_str());

        //cout << cmd << endl;
        system(cstr);

        cmd.erase();

        #ifdef __unix__
            cmd += "diff";
        #elif _WIN32
            cmd += "FC";
        #endif // __unix__

        cmd += ' ' + res1;
        cmd += ' ' + res2;

        #ifdef __unix__
            cmd += " >> FC.log";
        #elif _WIN32
            cmd += " /N";
            cmd += " >>FC.log";
        #endif

        //cout << cmd << endl;
        system(cmd.c_str());

        arq.erase();
        res1.erase();
        res2.erase();
        cmd.erase();
        n.erase();
    }

    #ifdef __unix__
        cmd += "cat FC.log";
    #elif _WIN32
        cmd += "type FC.log";
    #endif

    system(cmd.c_str());

    arq.erase();
    res1.erase();
    res2.erase();
    cmd.erase();
    n.erase();

    return 0;
}

