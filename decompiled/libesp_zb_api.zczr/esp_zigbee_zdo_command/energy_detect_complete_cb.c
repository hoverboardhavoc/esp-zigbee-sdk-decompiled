/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> energy_detect_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void energy_detect_complete_cb(int param_1)

{
  code *pcVar1;
  byte *__ptr;
  undefined1 uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  
  pbVar3 = (byte *)zb_buf_get_tail_func(0x97);
  uVar2 = zb_buf_get_status_func(param_1);
  pcVar1 = zdo_energy_detect_user_cb;
  uVar4 = (uint)*pbVar3;
  if (zdo_energy_detect_user_cb != (code *)0x0) {
    __ptr = (byte *)0x0;
    if (uVar4 != 0) {
      __ptr = (byte *)malloc(uVar4 << 1);
      if (__ptr == (byte *)0x0) {
        uVar2 = 0x8a;
      }
      else {
        iVar8 = 0;
        pbVar7 = __ptr;
        pbVar6 = pbVar3;
        do {
          pbVar6 = pbVar6 + 2;
          iVar5 = iVar8 * 2;
          iVar8 = iVar8 + 1;
          *pbVar7 = pbVar3[iVar5 + 1] >> 3;
          pbVar7[1] = *pbVar6;
          pbVar7 = pbVar7 + 2;
        } while (iVar8 < (int)uVar4);
      }
    }
    (*pcVar1)(uVar2,__ptr);
    if (__ptr != (byte *)0x0) {
      free(__ptr);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
    return;
  }
  return;
}

