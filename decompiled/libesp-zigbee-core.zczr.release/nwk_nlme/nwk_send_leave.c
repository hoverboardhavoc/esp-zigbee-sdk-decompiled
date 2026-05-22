/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_send_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_send_leave(ezb_shortaddr_t dst_addr,_Bool rejoin,_Bool remove_children)

{
  zmsg_t *msg;
  
  msg = (zmsg_t *)zmsg_alloc(0x2f);
  if (msg == (zmsg_t *)0x0) {
    remove_children = false;
    msg = (zmsg_t *)__assert_func(0,0);
  }
  nwk_build_leave(msg,dst_addr,rejoin,remove_children);
  nwk_fwd_send_msg_delayed(msg,0);
  return;
}

