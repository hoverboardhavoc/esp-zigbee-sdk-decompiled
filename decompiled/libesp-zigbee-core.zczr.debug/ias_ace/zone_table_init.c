/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zone_table_init(undefined4 param_1)

{
  byte bVar1;
  uint __nmemb;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = zcl_get_attr_desc(0x501,1,0xeff0,0x131b);
  if (iVar2 == 0) {
    uVar5 = 5;
  }
  else if (*(byte **)(iVar2 + 8) == (byte *)0x0) {
    uVar5 = 5;
  }
  else {
    bVar1 = **(byte **)(iVar2 + 8);
    __nmemb = (uint)bVar1;
    if (__nmemb == 0) {
      log_write(1,"ZCL_IAS_ACE","Zone table size is zero");
      uVar5 = 0;
    }
    else {
      iVar2 = zcl_get_attr_desc(param_1,0x501,1,0xeff1,0x131b);
      if (iVar2 == 0) {
        uVar5 = 5;
      }
      else {
        piVar3 = (int *)calloc(1,8);
        if (piVar3 == (int *)0x0) {
          uVar5 = 1;
        }
        else {
          *(byte *)(piVar3 + 1) = bVar1;
          pvVar4 = calloc(__nmemb,0x1e);
          *piVar3 = (int)pvVar4;
          if (pvVar4 == (void *)0x0) {
            uVar5 = 1;
          }
          else {
            for (iVar6 = 0; iVar6 < (int)__nmemb; iVar6 = iVar6 + 1) {
              *(undefined2 *)(*piVar3 + iVar6 * 0x1e + 2) = 0xffff;
              iVar7 = *piVar3 + iVar6 * 0x1e;
              *(undefined1 *)(iVar7 + 4) = 0xff;
              *(undefined1 *)(iVar7 + 5) = 0xff;
              *(undefined1 *)(iVar7 + 6) = 0xff;
              *(undefined1 *)(iVar7 + 7) = 0xff;
              *(undefined1 *)(iVar7 + 8) = 0xff;
              *(undefined1 *)(iVar7 + 9) = 0xff;
              *(undefined1 *)(iVar7 + 10) = 0xff;
              *(undefined1 *)(iVar7 + 0xb) = 0xff;
            }
            *(char *)((int)piVar3 + 5) = (char)param_1;
            *(int **)(iVar2 + 8) = piVar3;
            uVar5 = 0;
          }
        }
      }
    }
  }
  return uVar5;
}

