/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_group_cluster_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_group_cluster_resp_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar2 + 0x14) != '\x01') {
    return 0;
  }
  if (zb_core_action_cb == 0) {
    return 0;
  }
  bVar1 = *(byte *)(iVar2 + 0x13);
  if (bVar1 == 2) {
    iVar3 = zcl_groups_get_group_membership_res(param_1);
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      iVar3 = zcl_groups_get_add_group_res(param_1);
    }
    else {
      if (bVar1 != 1) goto _L0;
      iVar3 = zcl_groups_get_view_group_res(param_1);
    }
  }
  else {
    if (bVar1 != 3) {
_L0:
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC16,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar2 + 0x13)
                   );
      return 0;
    }
    iVar3 = zcl_groups_get_remove_group_res(param_1);
  }
  zb_zcl_send_default_handler(param_1,iVar2,iVar3 != 0);
  return 1;
}

