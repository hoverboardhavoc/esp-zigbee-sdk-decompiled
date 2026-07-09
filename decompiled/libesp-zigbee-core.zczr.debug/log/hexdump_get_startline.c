/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> hexdump_get_startline
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void hexdump_get_startline(int param_1,int param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  sVar1 = strlen(param_3);
  sVar1 = sVar1 & 0xffff;
  iVar3 = (param_2 - sVar1) + -10;
  if (iVar3 < 6) {
    sVar1 = (iVar3 + sVar1 & 0xffff) - 6 & 0xffff;
    iVar3 = 6;
  }
  uVar4 = iVar3 / 2;
  write_nchar(param_1,0x3d,uVar4 & 0xffff);
  *(undefined1 *)(uVar4 + param_1) = 0x5b;
  memcpy((void *)(param_1 + uVar4 + 1),param_3,sVar1);
  iVar3 = sVar1 + uVar4 + 1;
  iVar2 = snprintf((char *)(param_1 + iVar3),param_2 - iVar3," len=%03u]");
  write_nchar(iVar2 + iVar3 + param_1,0x3d,param_2 - (iVar2 + iVar3) & 0xffff);
  *(undefined1 *)(param_1 + param_2) = 0;
  return;
}

