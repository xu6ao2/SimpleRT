#if !defined(__GLIBC__)
/***************************************************************************
 * resolv_compat.h
 *
 * Mimick GLIBC's res_ninit() and res_nclose() for musl libc
 * Note: res_init() is actually deprecated according to
 * http://docs.oracle.com/cd/E36784_01/html/E36875/res-nclose-3resolv.html
 **************************************************************************/

static inline int res_ninit(res_state statp)
{
        int rc = res_init();
        if (statp != &_res) {
                memcpy(statp, &_res, sizeof(*statp));
        }
        return rc;
}
#endif
