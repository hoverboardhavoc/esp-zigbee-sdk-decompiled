/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_sroute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_update_sroute(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  byte bStack_15;
  byte bStack_14;
  byte bStack_13;
  
  if ((param_2 >> 10 & 1) == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x149,
                  "nwk_fwd_update_sroute","nwk_fcf_is_source_routing(fcf)");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x152,
                  "nwk_fwd_update_sroute","sroute.relay_index < sroute.relay_count");
  }
  else {
    iVar1 = nwk_fcf_get_hdr_size(param_2);
    zmsg_read_bytes(param_1,iVar1,2,&bStack_14);
    if (bStack_13 != 0) {
      bStack_15 = bStack_13 - 1;
      bStack_13 = bStack_15;
      if (bStack_15 < bStack_14) {
        zmsg_write_bytes(param_1,iVar1 + 1U & 0xffff,1,&bStack_15);
        zmsg_read_bytes(param_1,(iVar1 + (uint)bStack_13 * 2 & 0xffff) + 2 & 0xffff,2,param_3 + 4);
        goto _L0;
      }
      goto _L0;
    }
  }
  zmsg_read_bytes(param_1,2,param_3 + 4);
_L0:
  *(undefined1 *)(param_3 + 6) = 0;
  return;
}

