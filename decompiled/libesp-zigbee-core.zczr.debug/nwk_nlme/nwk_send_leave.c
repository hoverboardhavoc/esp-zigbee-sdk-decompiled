/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_send_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_send_leave(ezb_shortaddr_t dst_addr,_Bool rejoin,_Bool remove_children)

{
  zmsg_t *msg;
  int iVar1;
  
  msg = (zmsg_t *)zmsg_alloc(0x2f);
  if (msg == (zmsg_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x141,"nwk_send_leave"
                  ,
                  "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((1) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                 );
    iVar1 = nwk_is_joined();
    if (iVar1 != 0) {
      nwk_is_authed();
    }
    return;
  }
  nwk_build_leave(msg,dst_addr,rejoin,remove_children);
  nwk_fwd_send_msg_delayed(msg,0);
  return;
}

