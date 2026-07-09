/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> log.o -> hexdump_get_next_dataline
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint hexdump_get_next_dataline
               (undefined1 *param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_5 + 0x10 & 0xffff;
  *param_1 = 0x7c;
  uVar5 = 1;
  for (uVar1 = param_5; uVar1 < uVar6; uVar1 = uVar1 + 1 & 0xffff) {
    if (uVar1 < param_4) {
      iVar2 = snprintf(param_1 + uVar5,param_2 - uVar5," %02X");
    }
    else {
      iVar2 = snprintf(param_1 + uVar5,param_2 - uVar5,"   ");
    }
    uVar5 = iVar2 + uVar5 & 0xffff;
    if ((uVar1 & 7) == 7) {
      uVar4 = uVar5 + 1;
      param_1[uVar5] = 0x20;
      uVar5 = uVar5 + 2 & 0xffff;
      param_1[uVar4 & 0xffff] = 0x7c;
    }
  }
  param_1[uVar5] = 0x20;
  for (; uVar5 = uVar5 + 1 & 0xffff, param_5 < uVar6; param_5 = param_5 + 1 & 0xffff) {
    if (param_5 < param_4) {
      bVar3 = *(byte *)(param_3 + param_5);
      if (bVar3 < 0x7f) {
        if (((&_ctype_)[bVar3] & 0x97) == 0) {
          bVar3 = 0x2e;
        }
      }
      else {
        bVar3 = 0x2e;
      }
    }
    else {
      bVar3 = 0x20;
    }
    param_1[uVar5] = bVar3;
  }
  param_1[uVar5] = 0x20;
  param_1[uVar5 + 1 & 0xffff] = 0x7c;
  param_1[uVar5 + 2 & 0xffff] = 0;
  return uVar6;
}

