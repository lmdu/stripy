/*
 * itr.h -- imperfect tandem repeats
 *
 */

#define PY_SSIZE_T_CLEAN
#ifndef PYTRF_ITR_H
#define PYTRF_ITR_H
#include "Python.h"

typedef struct {
	PyObject_HEAD

	//input sequence name
	PyObject *seqname;

	//input sequence object
	PyObject *seqobj;

	//pointer to sequence object
	const char *seq;

	//sequence length
	Py_ssize_t size;

	//next start position for tandem repeat identification
	Py_ssize_t next_start;

	//seed min repeats
	int seed_minrep;

	//seed min length
	int seed_minlen;

	//maximal continuous error
	int max_errors;

	//min motif size
	int min_motif;

	//max motif size
	int max_motif;

	//substitution penalty
	double sub_penalty;

	//insertion penalty
	double ins_penalty;

	//deletion penalty
	double del_penalty;

	//min match ratio
	double min_ratio;

	//maximal extend length
	int extend_maxlen;

	//current motif sequence
	char* motif;

	//dynamic alignment matrix
	int** matrix;

} pytrf_ITRFinder;

extern PyTypeObject pytrf_ITRFinderType;

#endif
