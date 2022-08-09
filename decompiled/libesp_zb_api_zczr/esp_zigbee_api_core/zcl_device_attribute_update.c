/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_device_attribute_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_device_attribute_update(undefined1 param_1,undefined4 param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  short asStack_22 [5];
  
  sVar1 = *param_3;
  sVar2 = param_3[1];
  if (sVar1 == 8) {
    if (sVar2 == 0) {
      asStack_22[0] = CONCAT11(asStack_22[0]._1_1_,(char)param_3[2]);
      (*zcl_set_attr_user_cb)(param_1,8,0,asStack_22,zcl_set_attr_user_cb);
    }
  }
  else if (sVar1 == 0x300) {
    if (sVar2 == 3) {
      asStack_22[0] = param_3[2];
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,0x300,3,asStack_22);
      }
    }
    if (sVar2 == 4) {
      asStack_22[0] = param_3[2];
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,4,asStack_22);
      }
    }
    if (sVar2 == 8) {
      asStack_22[0] = CONCAT11(asStack_22[0]._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,8,asStack_22);
      }
    }
    if (sVar2 == 0xf) {
      asStack_22[0] = CONCAT11(asStack_22[0]._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0xf,asStack_22);
      }
    }
    if (sVar2 == 0x4001) {
      asStack_22[0] = CONCAT11(asStack_22[0]._1_1_,(char)param_3[2]);
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0x4001,asStack_22);
      }
    }
    if (sVar2 == 0x400a) {
      asStack_22[0] = param_3[2];
      if (zcl_set_attr_user_cb != (code *)0x0) {
        (*zcl_set_attr_user_cb)(param_1,param_2,0x300,0x400a,asStack_22);
      }
    }
  }
  else if (sVar1 == 6) {
    if ((sVar2 == 0) && (zcl_set_attr_user_cb != (code *)0x0)) {
      asStack_22[0] = CONCAT11(asStack_22[0]._1_1_,(char)param_3[2]);
      (*zcl_set_attr_user_cb)(param_1,6,0,asStack_22);
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_API_CORE",&_LC1,uVar3,"ESP_ZIGBEE_API_CORE",sVar1,sVar2);
  }
  return;
}

