/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_ias_ace.o -> zcl_ias_ace_device_cb_handler_cli
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_ace_device_cb_handler_cli(void)

{
  uint *puVar1;
  undefined4 *__ptr;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar3 = *puVar1;
  if (uVar3 == 0x17) {
    __ptr = (undefined4 *)malloc(0xc);
    __ptr[2] = puVar1[4];
  }
  else if (uVar3 < 0x18) {
    if (uVar3 == 0x15) {
      __ptr = (undefined4 *)malloc(0xc);
      __ptr[2] = puVar1[4];
    }
    else if (uVar3 < 0x16) {
      if (uVar3 == 0x13) {
        __ptr = (undefined4 *)malloc(0xc);
        __ptr[2] = puVar1[4];
      }
      else {
        if (uVar3 != 0x14) goto _L0;
        __ptr = (undefined4 *)malloc(0xc);
        __ptr[2] = puVar1[4];
      }
    }
    else {
      if (uVar3 != 0x16) {
_L0:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_ias_ace.c"
                  ,0x9d);
        zb_zcl_ias_ace_init_server();
        zb_zcl_device_cb_register(0xb,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0xc,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0xd,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0xe,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0xf,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0x10,zcl_ias_ace_device_cb_handler_srv);
        zb_zcl_device_cb_register(0x11,zcl_ias_ace_device_cb_handler_srv);
        uVar2 = zb_zcl_device_cb_register(0x12,zcl_ias_ace_device_cb_handler_srv);
        return uVar2;
      }
      __ptr = (undefined4 *)malloc(0xc);
      __ptr[2] = puVar1[4];
    }
  }
  else if (uVar3 == 0x1a) {
    __ptr = (undefined4 *)malloc(0xc);
    __ptr[2] = puVar1[4];
  }
  else if (uVar3 < 0x1b) {
    if (uVar3 == 0x18) {
      __ptr = (undefined4 *)malloc(0xc);
      __ptr[2] = puVar1[4];
    }
    else {
      if (uVar3 != 0x19) goto _L0;
      __ptr = (undefined4 *)malloc(0xc);
      __ptr[2] = puVar1[4];
    }
  }
  else {
    if (uVar3 != 0x1b) goto _L0;
    __ptr = (undefined4 *)malloc(0xc);
    __ptr[2] = puVar1[4];
  }
  *__ptr = 0;
  *(char *)(__ptr + 1) = (char)puVar1[1];
  *(undefined2 *)((int)__ptr + 6) = 0x501;
  convert_to_core_action_id(*puVar1);
  esp_zb_core_action_handler_schedule(__ptr);
  uVar2 = esp_err_to_zb_ret();
  if (__ptr != (undefined4 *)0x0) {
    free(__ptr);
  }
  return uVar2;
}

