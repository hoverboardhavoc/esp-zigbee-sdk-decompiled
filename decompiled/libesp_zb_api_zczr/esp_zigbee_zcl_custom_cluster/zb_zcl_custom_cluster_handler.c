/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_custom_cluster.o -> zb_zcl_custom_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_custom_cluster_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint auStack_38 [5];
  undefined1 uStack_21;
  short sStack_20;
  char cStack_1b;
  undefined2 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar2 != 0) {
    return 1;
  }
  if ((-1 < sStack_20) || (iVar2 = esp_zb_has_core_action_handler(), iVar2 == 0)) {
    return 0;
  }
  auStack_38[0] = (uint)(iVar1 == 0);
  uStack_18 = zb_buf_len_func(param_1);
  uStack_14 = zb_buf_begin_func(param_1);
  iVar2 = esp_zb_zcl_get_cluster(uStack_21,sStack_20,2);
  iVar3 = esp_zb_zcl_get_cluster(uStack_21,sStack_20,1);
  if (iVar2 == 0) {
    if (iVar3 != 0) {
_L0:
      if (cStack_1b == '\0') goto _L0;
      if (cStack_1b == '\x01') goto _L0;
    }
_L0:
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000,sStack_20,uStack_21);
    iVar2 = -0x1c;
  }
  else {
    if (cStack_1b == '\x01') {
_L0:
      uVar4 = 0x1040;
    }
    else {
      if (iVar3 != 0) goto _L0;
      if (cStack_1b != '\0') goto _L0;
_L0:
      uVar4 = 0x1041;
    }
    iVar2 = esp_zb_core_action_handler_schedule(uVar4,auStack_38);
  }
  if (iVar1 != 0) {
    zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
  }
  return 1;
}

