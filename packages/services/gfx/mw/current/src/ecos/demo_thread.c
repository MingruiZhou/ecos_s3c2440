#include <pkgconf/system.h>     /* which packages are enabled/disabled */
#ifdef CYGPKG_KERNEL
# include <pkgconf/kernel.h>
#endif
#ifdef CYGPKG_LIBC
# include <pkgconf/libc.h>
#endif
#ifdef CYGPKG_IO_SERIAL
# include <pkgconf/io_serial.h>
#endif

#ifndef CYGFUN_KERNEL_API_C
# error Kernel API must be enabled to build this application
#endif

#ifndef CYGPKG_LIBC_STDIO
# error C library standard I/O must be enabled to build this application
#endif

#ifndef CYGPKG_IO_SERIAL_HALDIAG
# error I/O HALDIAG pseudo-device driver must be enabled to build this application
#endif

/* INCLUDES */

#include <stdio.h>                      /* printf */
#include <stdlib.h>                      /* printf */
#include <string.h>                     /* strlen */
#include <cyg/kernel/kapi.h>            /* All the kernel specific stuff */
#include <cyg/infra/diag.h>        

#define MWINCLUDECOLORS
#include "nano-X.h"

#include <microwin/ecos_mw_app.h>
_mw_app("demo", demo, ECOS_MW_APP_PRIORITY, 0);

//
// Component interfaces
//

externC int demo_main(int argc, char *argv[]);

/*static*/ void
demo_thread(CYG_ADDRWORD data)
{
    int argc = 1;
    char *argv[] = {"demo" };

    cyg_thread_delay(10*100);
    INIT_PER_THREAD_DATA();
    demo_main(argc, argv);
}
