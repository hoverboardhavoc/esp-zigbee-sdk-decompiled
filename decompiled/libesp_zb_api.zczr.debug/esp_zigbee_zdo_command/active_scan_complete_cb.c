/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> active_scan_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_scan_complete_cb(int param_1)

{
  byte *pbVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  void *__ptr;
  uint uVar6;
  
  piVar3 = (int *)zb_buf_begin_func();
  if (zdo_active_scan_user_cb != (code *)0x0) {
    if (*piVar3 == 0) {
      pbVar1 = (byte *)((int)piVar3 + 5);
      uVar6 = (uint)*(byte *)(piVar3 + 1);
      __ptr = malloc(uVar6 * 0xe);
      if (__ptr == (void *)0x0) {
        uVar4 = 0x8a;
      }
      else {
        pvVar2 = __ptr;
        for (uVar5 = 0; uVar5 < *(byte *)(piVar3 + 1); uVar5 = uVar5 + 1) {
          zb_address_get_pan_id(*pbVar1 & 0x7f,(int)pvVar2 + 3);
          zb_address_get_short_pan_id(*pbVar1 & 0x7f,pvVar2);
          *(byte *)((int)pvVar2 + 2) = pbVar1[2] >> 4 & 1;
          *(byte *)((int)pvVar2 + 0xb) = (byte)((pbVar1[2] & 3) << 4) | pbVar1[1] >> 4;
          *(byte *)((int)pvVar2 + 0xc) = pbVar1[2] >> 5 & 1;
          *(byte *)((int)pvVar2 + 0xd) = pbVar1[2] >> 6 & 1;
          pvVar2 = (void *)((int)pvVar2 + 0xe);
          pbVar1 = pbVar1 + 4;
        }
        uVar4 = 0;
      }
    }
    else {
      __ptr = (void *)0x0;
      uVar6 = 0;
      uVar4 = 0;
    }
    (*zdo_active_scan_user_cb)(uVar4,uVar6,__ptr,zdo_active_scan_user_cb);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

