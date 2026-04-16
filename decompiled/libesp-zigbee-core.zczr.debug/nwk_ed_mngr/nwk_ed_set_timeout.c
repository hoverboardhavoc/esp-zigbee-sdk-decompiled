/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_set_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_set_timeout(uint8_t timeout)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = core_globals_get();
  if ((uint)*(byte *)(iVar1 + 0xa29) != CONCAT31(in_register_00002029,timeout)) {
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0xa29) = timeout;
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xaf8) < '\0') {
      nwk_ed_stop_keepalive();
      nwk_ed_start_keepalive();
    }
  }
  return;
}

