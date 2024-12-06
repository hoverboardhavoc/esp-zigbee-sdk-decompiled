/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> energy_detect_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void energy_detect_complete_cb(int param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  void *__ptr;
  uint uVar6;
  
  pbVar3 = (byte *)zb_buf_get_tail_func(0x97);
  uVar2 = zb_buf_get_status_func(param_1);
  pcVar1 = zdo_energy_detect_user_cb;
  uVar6 = (uint)*pbVar3;
  if (zdo_energy_detect_user_cb != (code *)0x0) {
    if (uVar6 == 0) {
      __ptr = (void *)0x0;
    }
    else {
      __ptr = malloc(uVar6 << 1);
      if (__ptr == (void *)0x0) {
        uVar2 = 0x8a;
      }
      else {
        for (iVar4 = 0; iVar4 < (int)uVar6; iVar4 = iVar4 + 1) {
          iVar5 = iVar4 * 2;
          *(byte *)((int)__ptr + iVar5) = pbVar3[iVar5 + 1] >> 3;
          ((byte *)((int)__ptr + iVar5))[1] = pbVar3[iVar5 + 2];
        }
      }
    }
    (*pcVar1)(uVar2,uVar6,__ptr);
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

