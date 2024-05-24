/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_ace.o -> zcl_ias_ace_device_cb_handler_srv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_ace_device_cb_handler_srv(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar4 = *puVar1;
  if (uVar4 == 0x10) {
    puVar2 = (undefined4 *)malloc(0xc);
    puVar2[2] = puVar1[5];
    goto _L0;
  }
  if (uVar4 < 0x11) {
    if (uVar4 == 0xc) {
      puVar2 = (undefined4 *)malloc(0x10);
      puVar2[2] = puVar1[4];
      puVar2[3] = puVar1[5];
      goto _L0;
    }
    if (uVar4 < 0xd) {
      if (uVar4 == 0xb) {
        puVar2 = (undefined4 *)malloc(0x10);
        puVar2[2] = puVar1[4];
        puVar2[3] = puVar1[5];
        goto _L0;
      }
    }
    else if (uVar4 - 0xd < 3) {
      puVar2 = (undefined4 *)malloc(0x20);
      goto _L0;
    }
  }
  else {
    if (uVar4 == 0x11) {
      puVar2 = (undefined4 *)malloc(0xc);
      puVar2[2] = puVar1[5];
_L0:
      *puVar2 = 0;
      *(char *)(puVar2 + 1) = (char)puVar1[1];
      *(undefined2 *)((int)puVar2 + 6) = 0x501;
      convert_to_core_action_id(*puVar1);
      esp_zb_core_action_handler_schedule(puVar2);
      uVar3 = esp_err_to_zb_ret();
      if (puVar2 != (undefined4 *)0x0) {
        free(puVar2);
      }
      return uVar3;
    }
    if (uVar4 == 0x12) {
      puVar2 = (undefined4 *)malloc(0x10);
      puVar2[2] = puVar1[4];
      puVar2[3] = puVar1[5];
      goto _L0;
    }
  }
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_ias_ace.c"
            ,0x5e);
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar4 = *puVar1;
  if (uVar4 == 0x17) {
    puVar2 = (undefined4 *)malloc(0xc);
    puVar2[2] = puVar1[4];
  }
  else if (uVar4 < 0x18) {
    if (uVar4 == 0x15) {
      puVar2 = (undefined4 *)malloc(0xc);
      puVar2[2] = puVar1[4];
    }
    else if (uVar4 < 0x16) {
      if (uVar4 == 0x13) {
        puVar2 = (undefined4 *)malloc(0xc);
        puVar2[2] = puVar1[4];
      }
      else {
        if (uVar4 != 0x14) goto _L0;
        puVar2 = (undefined4 *)malloc(0xc);
        puVar2[2] = puVar1[4];
      }
    }
    else {
      if (uVar4 != 0x16) {
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
        uVar3 = zb_zcl_device_cb_register(0x12,zcl_ias_ace_device_cb_handler_srv);
        return uVar3;
      }
      puVar2 = (undefined4 *)malloc(0xc);
      puVar2[2] = puVar1[4];
    }
  }
  else if (uVar4 == 0x1a) {
    puVar2 = (undefined4 *)malloc(0xc);
    puVar2[2] = puVar1[4];
  }
  else if (uVar4 < 0x1b) {
    if (uVar4 == 0x18) {
      puVar2 = (undefined4 *)malloc(0xc);
      puVar2[2] = puVar1[4];
    }
    else {
      if (uVar4 != 0x19) goto _L0;
      puVar2 = (undefined4 *)malloc(0xc);
      puVar2[2] = puVar1[4];
    }
  }
  else {
    if (uVar4 != 0x1b) goto _L0;
    puVar2 = (undefined4 *)malloc(0xc);
    puVar2[2] = puVar1[4];
  }
  *puVar2 = 0;
  *(char *)(puVar2 + 1) = (char)puVar1[1];
  *(undefined2 *)((int)puVar2 + 6) = 0x501;
  convert_to_core_action_id(*puVar1);
  esp_zb_core_action_handler_schedule(puVar2);
  uVar3 = esp_err_to_zb_ret();
  if (puVar2 != (undefined4 *)0x0) {
    free(puVar2);
  }
  return uVar3;
}

