/*
 * itr.h -- imperfect tandem repeats
 *
 */

#define PY_SSIZE_T_CLEAN
#ifndef STRIPY_ITR_H
#define STRIPY_ITR_H
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
	float sub_penalty;

	//insertion penalty
	float ins_penalty;

	//deletion penalty
	float del_penalty;

	//min match ratio
	float min_ratio;

	//maximal extend length
	int extend_maxlen;

} stripy_ITRMiner;

typedef struct {
	PyObject_HEAD

	//input sequence name
	PyObject *seqid;

	//imperfect tandem repeat start position
	Py_ssize_t start;

	//imperfect tandem repeat stop position
	Py_ssize_t end;

	//motif sequence
	char *motif;

	//motif length
	int mlen;

	//tandem length
	int length;

	//number of matches
	int matches;

	//number of substitutions
	int substitutions;

	//number of insertion
	int insertions;

	//number of deletion
	int deletions;

	//identity
	float identity;

} stripy_ITR;

extern PyTypeObject stripy_ITRMinerType;
extern PyTypeObject stripy_ITRType;

#endif
