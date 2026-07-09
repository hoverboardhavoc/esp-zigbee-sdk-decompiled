/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_get_entries_capacity
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_nwk_mgmt_rtg_get_entries_capacity(void)

{
  uint uVar1;
  
  uVar1 = zdo_packet_max_available_space(0x8032);
  if (uVar1 < 5) {
    uVar1 = 0;
  }
  else {
    uVar1 = (int)(uVar1 - 4) / 5 & 0xff;
  }
  return uVar1;
}

