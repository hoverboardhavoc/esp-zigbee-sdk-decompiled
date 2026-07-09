/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> addr_table_ref_redirect.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void addr_table_ref_redirect_isra_0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = param_2 * 0x12 + param_1;
  cVar1 = *(char *)(iVar2 + 0x10);
  param_1 = param_1 + param_3 * 0x12;
  *(short *)(param_1 + 0xe) = (short)param_2;
  *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + cVar1;
  *(short *)(iVar2 + 0xe) = (short)param_3;
  *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) | 4;
  return;
}

