#ifndef GMCMC_ION_MODEL_H
#define GMCMC_ION_MODEL_H

typedef struct gmcmc_ion_model gmcmc_ion_model;

int gmcmc_ion_model_create(gmcmc_ion_model **, const int *, int, const int *, int, void (*)(const double *, double *, size_t));
void gmcmc_ion_model_destroy(gmcmc_ion_model *);

int gmcmc_ion_proposal_mh(const gmcmc_model *, gmcmc_chain *);
int gmcmc_ion_likelihood_mh(const gmcmc_model *, gmcmc_chain *);

#endif /* GMCMC_ION_MODEL_H */
