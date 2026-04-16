/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_get_default_keepalive_interval
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t nwk_ed_get_default_keepalive_interval(void)

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  bVar1 = nwk_ed_get_timeout();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = 10;
  }
  else {
    iVar2 = 0x3c << (bVar1 & 0x1f);
  }
  return (uint)(iVar2 * 1000) >> 2;
}

