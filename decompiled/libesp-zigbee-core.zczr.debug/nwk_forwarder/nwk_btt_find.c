/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_bt_record_t * nwk_btt_find(ezb_shortaddr_t src_addr,uint8_t seq_num)

{
  undefined2 in_register_0000202a;
  undefined3 in_register_0000202d;
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x59 < uVar1) {
      return (nwk_bt_record_t *)0x0;
    }
    if (((uint)s_nwk_fwd.btt[uVar1].src_addr == CONCAT22(in_register_0000202a,src_addr)) &&
       ((uint)s_nwk_fwd.btt[uVar1].seq_num == CONCAT31(in_register_0000202d,seq_num))) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return s_nwk_fwd.btt + uVar1;
}

