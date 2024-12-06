/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> active_scan_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_scan_complete_cb(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int *piVar3;
  void *__ptr;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  
  piVar3 = (int *)zb_buf_begin_func();
  if (zdo_active_scan_user_cb == (code *)0x0) goto _L0;
  if (*piVar3 == 0) {
    uVar6 = (uint)*(byte *)(piVar3 + 1);
    uVar7 = 0;
    __ptr = malloc(uVar6 * 0xe);
    uVar4 = 0x8a;
    pbVar2 = (byte *)((int)piVar3 + 5);
    pvVar5 = __ptr;
    if (__ptr != (void *)0x0) {
      for (; uVar7 < *(byte *)(piVar3 + 1); uVar7 = uVar7 + 1) {
        zb_address_get_pan_id(*pbVar2 & 0x7f,(int)pvVar5 + 3);
        zb_address_get_short_pan_id(*pbVar2 & 0x7f,pvVar5);
        bVar1 = pbVar2[1];
        *(byte *)((int)pvVar5 + 2) = pbVar2[2] >> 4 & 1;
        *(byte *)((int)pvVar5 + 0xb) = (byte)((pbVar2[2] & 3) << 4) | bVar1 >> 4;
        *(byte *)((int)pvVar5 + 0xc) = pbVar2[2] >> 5 & 1;
        *(byte *)((int)pvVar5 + 0xd) = pbVar2[2] >> 6 & 1;
        pbVar2 = pbVar2 + 4;
        pvVar5 = (void *)((int)pvVar5 + 0xe);
      }
      goto _L0;
    }
  }
  else {
    __ptr = (void *)0x0;
    uVar6 = 0;
_L0:
    uVar4 = 0;
  }
  (*zdo_active_scan_user_cb)(uVar4,uVar6,__ptr,zdo_active_scan_user_cb);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
_L0:
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
    return;
  }
  return;
}

