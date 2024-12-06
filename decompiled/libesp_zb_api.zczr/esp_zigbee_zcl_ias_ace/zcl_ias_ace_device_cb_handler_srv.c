/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_ias_ace.o -> zcl_ias_ace_device_cb_handler_srv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_ace_device_cb_handler_srv(void)

{
  uint *puVar1;
  undefined4 *__ptr;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar4 = *puVar1;
  if (uVar4 == 0x10) {
_L0:
    __ptr = (undefined4 *)malloc(0xc);
    __ptr[2] = puVar1[5];
  }
  else {
    if (uVar4 < 0x11) {
      if (uVar4 == 0xc) {
_L0:
        __ptr = (undefined4 *)malloc(0x10);
        __ptr[2] = puVar1[4];
        __ptr[3] = puVar1[5];
        goto _L0;
      }
      if (uVar4 < 0xd) {
        uVar3 = 0xb;
        goto _L13;
      }
    }
    else {
      if (uVar4 == 0x11) goto _L0;
      uVar3 = 0x12;
_L13:
      if (uVar4 == uVar3) goto _L0;
      zb_assert(0x10000,0x5e);
    }
    __ptr = (undefined4 *)malloc(0x20);
  }
_L0:
  *__ptr = 0;
  *(char *)(__ptr + 1) = (char)puVar1[1];
  *(undefined2 *)((int)__ptr + 6) = 0x501;
  esp_zb_core_action_handler_schedule(uVar4 + 0x14,__ptr);
  uVar2 = esp_err_to_zb_ret();
  free(__ptr);
  return uVar2;
}

