/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_endpoint_handler_callback(undefined4 param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  
  iVar3 = zb_buf_get_tail_func(0x1a);
  if (zcl_cli_resp_user_cb != (code *)0x0) {
    iVar3 = (*zcl_cli_resp_user_cb)(param_1);
    return iVar3 != 0;
  }
  if (*(char *)(iVar3 + 0x13) != '\x01') {
    return false;
  }
  uVar5 = (uint)*(ushort *)(iVar3 + 0xe);
  if (uVar5 < 9) {
    if ((0x179U >> (uVar5 & 0x1f) & 1) == 0) {
_L0:
      uVar4 = esp_zb_get_global_custom_cluster_id();
      if (uVar5 != uVar4) {
        return false;
      }
      if (zcl_custom_cluster_cmd_cb != (code *)0x0) {
        esp_zb_custom_cluster_get_cmd_req(param_1,auStack_3c,0);
        (*zcl_custom_cluster_cmd_cb)(uRam00000000,uStack_2c,zcl_custom_cluster_cmd_cb);
        return false;
      }
      return false;
    }
  }
  else if (uVar5 != 0x300) goto _L0;
  cVar2 = *(char *)(iVar3 + 0x15);
  if (cVar2 == '\0') {
    if (uVar5 == 4) {
      bVar1 = *(byte *)(iVar3 + 0x12);
      if (bVar1 == 2) {
        if (zcl_get_group_membership_resp_user_cb != 0) {
          esp_zb_zcl_groups_get_group_membership_res(param_1);
          cVar2 = '\x01';
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          if (zcl_add_group_resp_user_cb != 0) {
            esp_zb_zcl_groups_get_add_group_res(param_1);
            cVar2 = '\x01';
          }
        }
        else if ((bVar1 == 1) && (zcl_view_group_resp_user_cb != 0)) {
          esp_zb_zcl_groups_get_view_group_res(param_1);
          cVar2 = '\x01';
        }
      }
      else if ((bVar1 == 3) && (zcl_remove_group_resp_user_cb != 0)) {
        esp_zb_zcl_groups_get_remove_group_res(param_1);
        cVar2 = '\x01';
      }
    }
  }
  else if (*(char *)(iVar3 + 0x12) == '\x01') {
    if (zcl_read_attr_user_cb == (code *)0x0) {
      cVar2 = '\0';
    }
    else {
      uVar5 = zb_buf_len_func(param_1);
      if (uVar5 < 3) {
        puVar6 = (undefined2 *)0x0;
      }
      else {
        puVar6 = (undefined2 *)zb_buf_begin_func(param_1);
        if (puVar6 != (undefined2 *)0x0) {
          if (*(char *)(puVar6 + 1) == '\0') {
            iVar3 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar6 + 3),puVar6 + 2);
            uVar5 = iVar3 + 4U & 0xff;
            zb_buf_len_func(param_1);
          }
          else {
            uVar5 = 3;
          }
          uVar4 = zb_buf_len_func(param_1);
          if (uVar4 < uVar5) {
            return false;
          }
          zb_buf_cut_left_func(param_1,uVar5);
        }
      }
      if (puVar6 == (undefined2 *)0x0) {
        cVar2 = '\0';
      }
      else {
        (*zcl_read_attr_user_cb)
                  (*(undefined1 *)(puVar6 + 1),*puVar6,*(undefined1 *)((int)puVar6 + 3),puVar6 + 2,
                   zcl_read_attr_user_cb);
        zb_buf_free_func(param_1);
      }
    }
  }
  else {
    cVar2 = '\0';
  }
  return cVar2;
}

