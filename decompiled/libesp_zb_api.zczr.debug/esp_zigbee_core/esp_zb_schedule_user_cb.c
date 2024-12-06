/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> esp_zb_schedule_user_cb
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
                    0x52a);
  if (iVar2 == 0x104) {
    return -6;
  }
  if (iVar2 < 0x105) {
    if (iVar2 != 0) {
      if (iVar2 != 0x101) {
        return -1;
      }
      return -0x16;
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

