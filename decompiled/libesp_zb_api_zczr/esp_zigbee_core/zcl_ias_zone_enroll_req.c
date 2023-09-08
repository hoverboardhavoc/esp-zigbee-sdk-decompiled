/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ias_zone_enroll_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ias_zone_enroll_req(undefined4 param_1)

{
  undefined2 *__ptr;
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint local_30 [7];
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  __ptr = (undefined2 *)malloc(4);
  uVar1 = zb_buf_len_func(param_1);
  if (3 < uVar1) {
    puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
    *(undefined1 *)__ptr = *puVar3;
    *(undefined1 *)((int)__ptr + 1) = puVar3[1];
    *(undefined1 *)(__ptr + 1) = puVar3[2];
    *(undefined1 *)((int)__ptr + 3) = puVar3[3];
  }
  iVar2 = zb_zcl_basic_message_create(param_1,local_30);
  if (iVar2 == 0) {
    uStack_14 = *__ptr;
    uStack_12 = __ptr[1];
    local_30[0] = (uint)(3 >= uVar1);
    iVar2 = (*zb_core_action_cb)(0x1030,local_30,zb_core_action_cb);
    free(__ptr);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","zcl_ias_zone_enroll_req",0x621);
  }
  return iVar2;
}

