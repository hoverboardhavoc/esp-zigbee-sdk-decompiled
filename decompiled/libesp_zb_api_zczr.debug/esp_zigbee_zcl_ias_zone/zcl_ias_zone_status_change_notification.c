/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_zone.o -> zcl_ias_zone_status_change_notification
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ias_zone_status_change_notification(undefined4 param_1)

{
  undefined2 *__ptr;
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint auStack_38 [8];
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined2 uStack_14;
  
  __ptr = (undefined2 *)malloc(6);
  uVar1 = zb_buf_len_func(param_1);
  if (5 < uVar1) {
    puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
    *(undefined1 *)__ptr = *puVar3;
    *(undefined1 *)((int)__ptr + 1) = puVar3[1];
    *(undefined1 *)(__ptr + 1) = puVar3[2];
    *(undefined1 *)((int)__ptr + 3) = puVar3[3];
    *(undefined1 *)(__ptr + 2) = puVar3[4];
    *(undefined1 *)((int)__ptr + 5) = puVar3[5];
  }
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar2 == 0) {
    uStack_18 = *__ptr;
    uStack_16 = *(undefined1 *)(__ptr + 1);
    uStack_15 = *(undefined1 *)((int)__ptr + 3);
    uStack_14 = __ptr[2];
    auStack_38[0] = (uint)(5 >= uVar1);
    iVar2 = esp_zb_core_action_handler_schedule(0x1031,auStack_38);
    free(__ptr);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_IAS_ZONE",&_L0,uVar4,"ESP_ZIGBEE_ZCL_IAS_ZONE",
                  "zcl_ias_zone_status_change_notification",0x5d);
  }
  return iVar2;
}

