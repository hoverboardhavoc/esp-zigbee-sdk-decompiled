/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> secur_is_key_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool secur_is_key_valid(uint8_t *key)

{
  uint8_t *puVar1;
  char cVar2;
  
  if (key == (uint8_t *)0x0) {
    return false;
  }
  puVar1 = key + 0xf;
  cVar2 = '\x10';
  do {
    cVar2 = cVar2 + -1;
    if (*puVar1 != '\0') break;
    puVar1 = puVar1 + -1;
  } while (cVar2 != '\0');
  return cVar2 != '\0';
}

