/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> secur_is_key_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool secur_is_key_valid(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + 0xf);
  cVar1 = '\x10';
  do {
    cVar1 = cVar1 + -1;
    if (*pcVar2 != '\0') break;
    pcVar2 = pcVar2 + -1;
  } while (cVar1 != '\0');
  return cVar1 != '\0';
}

