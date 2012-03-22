/**
 * @file
 *
 * @ingroup rtems_bsd_rtems
 *
 * @brief TODO.
 */

/*
 *  COPYRIGHT (c) 1989-2012.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 */

#include <freebsd/machine/rtems-bsd-config.h>

#include <freebsd/sys/types.h>

#include <freebsd/sys/smp.h>
#include <freebsd/machine/smp.h>

int mp_ncpus;
int mp_maxcpus;

static void configure(void *dummy)
{
#if defined(RTEMS_SMP)
  mp_ncpus = rtems_smp_get_number_of_processors();
  mp_maxcpus = rtems_configuration_smp_maximum_processors;
#else
  mp_ncpus = 1;
  mp_maxcpus = 1;
#endif
}

/* XXX setup initialization of this */
