/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_schedule_user_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_schedule_user_cb(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    puVar1 = (undefined4 *)zb_buf_get_tail_func(8);
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)(puVar1[1]);
    }
    iVar2 = zb_buf_free_func(param_1);
    return iVar2;
  }
  iVar2 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_core.c",
                    0x560);
  if (iVar2 == 0x104) {
    return -6;
  }
  if (iVar2 < 0x105) {
    if (iVar2 != 0) {
      if (iVar2 == 0x101) {
        return -0x16;
      }
      return -1;
    }
  }
  else {
    if (iVar2 == 0x107) {
      return -0x1e;
    }
    if (iVar2 == 0x10c) {
      return -2;
    }
    if (iVar2 == 0x105) {
      return -0x1c;
    }
    iVar2 = -1;
  }
  return iVar2;
}

