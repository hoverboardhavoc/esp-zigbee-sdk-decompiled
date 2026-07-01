/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_get_entries_capacity
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zdo_nwk_mgmt_rtg_get_entries_capacity(void)

{
  uint8_t uVar1;
  uint uVar2;
  
  uVar2 = zdo_packet_max_available_space(0x8032);
  if (uVar2 < 5) {
    uVar1 = '\0';
  }
  else {
    uVar1 = (uint8_t)((int)(uVar2 - 4) / 5);
  }
  return uVar1;
}

