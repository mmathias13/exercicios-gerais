#include "tadgen.h"

int main(int argc, char const *argv[])
{
    int tipo = -1, numElem = 0;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");
    scanf("%d %d", &tipo, &numElem);
    tGeneric *gen = CriaGenerico(tipo, numElem);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}
