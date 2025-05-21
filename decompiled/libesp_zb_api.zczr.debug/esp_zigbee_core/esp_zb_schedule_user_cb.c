/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
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
                    0x1fd);
  if (iVar2 == 0x104) {
    return -6;
  }
  if (iVar2 < 0x105) {
    if (iVar2 == 0x101) {
      return -0x16;
    }
    if (0x101 < iVar2) {
      if (iVar2 == 0x103) {
        return -0x23;
      }
      return -1;
    }
    if (iVar2 != -1) {
      if (iVar2 == 0) {
        return 0;
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

