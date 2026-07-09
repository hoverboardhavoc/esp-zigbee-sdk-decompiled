/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_get_default_keepalive_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_ed_get_default_keepalive_interval(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = nwk_ed_get_timeout();
  if (uVar1 == 0) {
    iVar2 = 10;
  }
  else {
    iVar2 = 0x3c << (uVar1 & 0x1f);
  }
  return (uint)(iVar2 * 1000) >> 2;
}

