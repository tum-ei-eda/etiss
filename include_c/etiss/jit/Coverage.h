#ifndef __COVERAGE_H__
#define __COVERAGE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ETISS_USE_COREDSL_COVERAGE
void etiss_coverage_count(int count, ...);
#else
#define etiss_coverage_count(...)
#endif

#ifdef __cplusplus
}
#endif

#endif
