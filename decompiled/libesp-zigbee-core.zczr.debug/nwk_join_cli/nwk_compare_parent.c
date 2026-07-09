/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_compare_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte nwk_compare_parent(int param_1,int param_2)

{
  if (*(char *)(param_1 + 10) != *(char *)(param_2 + 10)) {
    return (byte)(*(char *)(param_2 + 10) - *(char *)(param_1 + 10)) >> 7;
  }
  return 1;
}

