/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_group_cluster_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_zcl_group_cluster_resp_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
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
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar2 + 0x13));
      return 0;
    }
    iVar3 = zcl_groups_get_remove_group_res(param_1);
  }
  uVar4 = (uint)*(byte *)(iVar2 + 0x17);
  if (uVar4 == 0) {
    uVar4 = zb_zcl_send_default_handler(param_1,iVar2,iVar3 != 0);
  }
  return uVar4;
}

