/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_send_rrec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_send_rrec(ezb_shortaddr_t dst_addr)

{
  ezb_shortaddr_t src_addr;
  zmsg_t *pzVar1;
  
  src_addr = nwk_get_short_address();
  pzVar1 = nwk_mesh_generate_rrec(src_addr,dst_addr);
  if (pzVar1 != (zmsg_t *)0x0) {
    nwk_fwd_send_msg_delayed(0);
    return;
  }
  return;
}

