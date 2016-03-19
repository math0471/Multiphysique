#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include "fem.h"
#include "gmm/gmm.h"
#include "gmshio.h"
#include "physicalio.h"

void NewtonRaphson(std::vector<Node*> &nodes, std::vector<Element*> &elements, std::vector<Physical*> &physicals, std::vector<Parameter*> &parameters,
					std::map<Node*, std::vector<double> > &solution, std::vector<double> &theta_k,gmm::row_matrix< gmm::wsvector<double> > Tmp,
					std::vector<double> &qext,FemFlag method, std::map<Node*, Node*> &NodesCorresp,
					std::vector<double> &delta_theta_k,std::map<int, Parameter*> &region,std::vector<double> &RHS);

void Internal_flux(std::vector<double> &theta_k, std::map<int, Parameter*> &region, std::vector<Element*> &elements, std::vector<double> &qint);

void Tangent_Stiffness_Matrix(std::vector<double> &theta_k,std::map<int, Parameter*> &region,
                              std::vector<Element*> &elements, gmm::row_matrix< gmm::wsvector<double> >&KT, std::map<Node*, Node*> &NodesCorresp,std::vector<Node*> &nodes);

bool End_Criterion(std::vector<double> &RHS,double normRHS0);
#endif // NEWTON_RAPHSON_H
