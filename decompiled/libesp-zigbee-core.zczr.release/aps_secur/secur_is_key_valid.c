/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> secur_is_key_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool secur_is_key_valid(uint8_t *key)

{
  char cVar1;
  uint8_t *puVar2;
  
  puVar2 = key + 0xf;
  cVar1 = '\x10';
  do {
    cVar1 = cVar1 + -1;
    if (*puVar2 != '\0') break;
    puVar2 = puVar2 + -1;
  } while (cVar1 != '\0');
  return cVar1 != '\0';
}

