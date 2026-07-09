/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_formation(void)

{
  int iVar1;
  uint uStack_18;
  uint auStack_14 [3];
  
  uStack_18 = 0;
  auStack_14[0] = 0;
  iVar1 = core_globals_get();
  uStack_18 = *(uint *)(iVar1 + 8);
  auStack_14[0] = CONCAT31(auStack_14[0]._1_3_,3);
  iVar1 = aps_secur_is_centralized();
  if (iVar1 == 0) {
    auStack_14[0] = auStack_14[0] | 0x2000000;
  }
  else {
    auStack_14[0] = auStack_14[0] & 0xfdffffff;
    iVar1 = nwk_is_device_zc();
    if (iVar1 != 0) {
      nwk_get_extended_address();
      aps_secur_set_tc_address();
    }
  }
  zdo_comm_get_scan_duration(auStack_14);
  zdo_comm_get_channel_mask(&uStack_18);
  iVar1 = core_globals_get();
  uStack_18 = uStack_18 & 0xf8000000 | uStack_18 & 0x7ffffff & *(uint *)(iVar1 + 8) & 0x7ffffff;
  nwk_network_formation_request(&uStack_18);
  return;
}

