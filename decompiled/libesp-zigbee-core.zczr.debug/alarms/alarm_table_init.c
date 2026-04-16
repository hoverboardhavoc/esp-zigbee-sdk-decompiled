/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarm_table_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t alarm_table_init(uint8_t ep_id)

{
  byte bVar1;
  uint __nmemb;
  undefined3 in_register_00002029;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  ezb_err_t eVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = ezb_zcl_get_attr_desc(9,1,0xeffe,0x131b);
  if (iVar2 == 0) {
    eVar5 = 5;
  }
  else if (*(byte **)(iVar2 + 8) == (byte *)0x0) {
    eVar5 = 5;
  }
  else {
    bVar1 = **(byte **)(iVar2 + 8);
    __nmemb = (uint)bVar1;
    if (__nmemb == 0) {
      log_write(3,"ZCL_ALARMS","Alarm table size is zero");
      eVar5 = 0;
    }
    else {
      iVar2 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),9,1,0xefff,0x131b);
      if (iVar2 == 0) {
        eVar5 = 5;
      }
      else {
        piVar3 = (int *)calloc(1,0x10);
        if (piVar3 == (int *)0x0) {
          eVar5 = 1;
        }
        else {
          pvVar4 = calloc(__nmemb,0xc);
          *piVar3 = (int)pvVar4;
          if (pvVar4 == (void *)0x0) {
            eVar5 = 1;
          }
          else {
            *(byte *)(piVar3 + 3) = bVar1;
            *(undefined1 *)((int)piVar3 + 0xd) = 0;
            piVar3[2] = 0;
            piVar3[1] = 0;
            for (uVar7 = 0; uVar7 < __nmemb; uVar7 = uVar7 + 1 & 0xff) {
              iVar6 = uVar7 * 0xc + *piVar3;
              *(int *)iVar6 = iVar6;
            }
            *(int **)(iVar2 + 8) = piVar3;
            eVar5 = 0;
          }
        }
      }
    }
  }
  return eVar5;
}

