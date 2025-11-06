/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_groups.o -> zb_zcl_group_cluster_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_group_cluster_resp_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar2 + 0x14) != '\x01') {
    return 0;
  }
  iVar3 = esp_zb_has_core_action_handler();
  if (iVar3 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(iVar2 + 0x13);
  if (bVar1 == 2) {
    iVar4 = zcl_groups_get_group_membership_res(param_1);
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      iVar4 = zcl_groups_get_add_group_res(param_1);
    }
    else {
      if (bVar1 != 1) goto _L0;
      iVar4 = zcl_groups_get_view_group_res(param_1);
    }
  }
  else {
    if (bVar1 != 3) {
_L0:
      uVar5 = esp_log_timestamp();
      esp_log(2,0x10000,"W (%lu) %s: Unsupported group command(0x%x)\n",uVar5,0x10000,
              *(undefined1 *)(iVar2 + 0x13));
      return 0;
    }
    iVar4 = zcl_groups_get_remove_group_res(param_1);
  }
  zb_zcl_send_default_handler(param_1,iVar2,iVar4 != 0);
  return iVar3;
}

