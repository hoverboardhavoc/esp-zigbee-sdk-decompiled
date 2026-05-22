/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_bt_record_t * nwk_btr_create(ezb_shortaddr_t src_addr,uint8_t seq_num)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x59 < uVar1) {
      return (nwk_bt_record_t *)0x0;
    }
    if (s_nwk_fwd.btt[uVar1].expire_time == '\0') break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  nwk_btr_setup(s_nwk_fwd.btt + uVar1,src_addr,seq_num);
  return s_nwk_fwd.btt + uVar1;
}

