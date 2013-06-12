/*
 * gmcmc_model.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_MODEL_H
#define GMCMC_MODEL_H

#include <gmcmc/gmcmc_chain.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_distribution.h>

typedef struct gmcmc_model gmcmc_model;

typedef int (*gmcmc_proposal_function)(const gmcmc_model *, gmcmc_chain *);
typedef int (*gmcmc_likelihood_function)(const gmcmc_model *, gmcmc_chain *);

int gmcmc_model_create(gmcmc_model **, const gmcmc_dataset *, unsigned int,
                       gmcmc_distribution **, gmcmc_proposal_function,
                       gmcmc_likelihood_function);
void gmcmc_model_destroy(gmcmc_model *);

int gmcmc_model_set_params(gmcmc_model *, const double *);
const double * gmcmc_model_get_params(const gmcmc_model *);

int gmcmc_model_set_param_names(gmcmc_model *, const char **);
const char * gmcmc_model_get_param_name(const gmcmc_model *);

int gmcmc_model_set_blocking(gmcmc_model *, int **, const int *, int);
int gmcmc_model_get_block(const gmcmc_model *, int **, int *, int);

void gmcmc_model_set_modelspecific(gmcmc_model *, void *);
const void * gmcmc_model_get_modelspecific(const gmcmc_model *);

#endif /* GMCMC_MODEL_H */
