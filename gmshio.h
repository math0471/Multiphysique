#ifndef GMSHIO_H_INCLUDED
#define GMSHIO_H_INCLUDED

//Structure contenant les infos des noeuds
struct Node
{
    int num;
    double x, y, z;
};

//Structure contenant les infos des �l�ments
struct Element
{
    int num, type, region;
    std::vector<Node*> nodes;
};

//Structure contenant les infos "physical" de gmsh
struct Physical
{
    std::string name;
    int num;
    int dim;
};

void readMSH(const char *fileName, std::vector<Node*> &nodes, std::vector<Element*> &elements, std::vector<Physical*> &physicals);
void writeMSH(char *fileName, double time, int step, std::map<Node*, std::vector<double> > &solution);

#endif // GMSHIO_H_INCLUDED
