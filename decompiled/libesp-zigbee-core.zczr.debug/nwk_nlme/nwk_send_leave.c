/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_nlme.c",0x12e,"nwk_send_leave",
                  "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((1) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                 );
    iVar1 = nwk_is_joined();
    if (iVar1 != 0) {
      nwk_is_authed();
    }
    return;
  }
  nwk_build_leave(msg,dst_addr,rejoin,remove_children);
  nwk_fwd_send_msg(msg);
  return;
}

