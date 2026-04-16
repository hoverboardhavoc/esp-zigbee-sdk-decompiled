/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_max_children
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t ezb_nwk_get_max_children(void)

{
  uint8_t uVar1;
  int iVar2;
  
  iVar2 = nwk_is_device_zczr();
  if (iVar2 == 0) {
    uVar1 = '\0';
  }
  else {
    iVar2 = core_globals_get();
    uVar1 = *(uint8_t *)(iVar2 + 0x9db);
  }
  return uVar1;
}

