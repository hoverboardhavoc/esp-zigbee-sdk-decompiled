/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> comm_api.o -> ezb_app_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined * ezb_app_signal_to_string(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = &s_app_signal_table;
  iVar2 = 0;
  do {
    if (*puVar1 == param_1) break;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0x16);
  return (&PTR__L0_000102e0)[iVar2 * 2];
}

