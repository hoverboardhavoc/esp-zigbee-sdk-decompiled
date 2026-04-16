/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_secur_ic_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t * esp_zb_secur_ic_get(uint8_t *ic_type)

{
  int iVar1;
  uint8_t *puVar2;
  
  iVar1 = ezb_secur_ic_get(esp_zb_secur_ic_get::ic,ic_type);
  if (iVar1 == 0) {
    puVar2 = esp_zb_secur_ic_get::ic;
  }
  else {
    puVar2 = (uint8_t *)0x0;
  }
  return puVar2;
}

