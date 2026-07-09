/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_api.o -> secur_is_key_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_is_key_valid(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = 0x10;
  do {
    if (uVar1 == 0) break;
    uVar1 = uVar1 - 1 & 0xff;
  } while (*(char *)(param_1 + uVar1) == '\0');
  if (uVar1 != 0) {
    return 1;
  }
  return 0;
}

