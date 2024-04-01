/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_ias_zone_enroll_req
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
  uint auStack_34 [8];
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
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_34);
  if (iVar2 == 0) {
    uStack_14 = *__ptr;
    uStack_12 = __ptr[1];
    auStack_34[0] = (uint)(3 >= uVar1);
    iVar2 = (*zb_core_action_cb)(0x1030,auStack_34,zb_core_action_cb);
    free(__ptr);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","zcl_ias_zone_enroll_req",0x9cd);
  }
  return iVar2;
}

