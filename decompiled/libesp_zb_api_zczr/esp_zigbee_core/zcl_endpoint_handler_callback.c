/*
 * Last changed at upstream commit e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * https://github.com/espressif/esp-zigbee-sdk/commit/e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * Upstream date: 2023-05-15 14:58:37 +0800
 * Upstream subject: esp-zigbee-lib: Support customized attribute read and command(225be55)
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
  int iVar5;
  uint uVar6;
  undefined4 *__ptr;
  undefined2 *puVar7;
  
  iVar3 = zb_buf_get_tail_func(0x1a);
  if (zcl_cli_resp_user_cb == (code *)0x0) {
    if (*(char *)(iVar3 + 0x13) == '\x01') {
      cVar2 = *(char *)(iVar3 + 0x15);
      if (cVar2 == '\0') {
        if (*(short *)(iVar3 + 0xe) == 4) {
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
          uVar4 = zb_buf_len_func(param_1);
          if (uVar4 < 3) {
            puVar7 = (undefined2 *)0x0;
          }
          else {
            puVar7 = (undefined2 *)zb_buf_begin_func(param_1);
            if (puVar7 == (undefined2 *)0x0) {
              return '\0';
            }
            iVar5 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar7 + 1));
            *(char *)(puVar7 + 1) = (char)iVar5;
            if (iVar5 == 0) {
              iVar5 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar7 + 3),puVar7 + 2);
              uVar4 = iVar5 + 4U & 0xff;
              zb_buf_len_func(param_1);
            }
            else {
              uVar4 = 3;
            }
            uVar6 = zb_buf_len_func(param_1);
            if (uVar6 < uVar4) {
              return '\0';
            }
            zb_buf_cut_left_func(param_1,uVar4);
          }
          if (puVar7 == (undefined2 *)0x0) {
            cVar2 = '\0';
          }
          else {
            (*zcl_read_attr_user_cb)
                      (*(undefined1 *)(puVar7 + 1),*(undefined2 *)(iVar3 + 0xe),*puVar7,
                       *(undefined1 *)((int)puVar7 + 3),puVar7 + 2,zcl_read_attr_user_cb);
            zb_buf_free_func(param_1);
          }
        }
      }
      else {
        cVar2 = '\0';
      }
    }
    else if (*(char *)(iVar3 + 0x13) == '\0') {
      uVar4 = esp_zb_get_global_custom_cluster_id();
      if (uVar4 == *(ushort *)(iVar3 + 0xe)) {
        if (*(char *)(iVar3 + 0x15) == '\0') {
          cVar2 = '\0';
          if (zcl_custom_cluster_cmd_cb != (code *)0x0) {
            __ptr = (undefined4 *)malloc(9);
            esp_zb_custom_cluster_get_cmd_req(param_1,__ptr);
            (*zcl_custom_cluster_cmd_cb)(*__ptr,(int)__ptr + 5,zcl_custom_cluster_cmd_cb);
            free(__ptr);
          }
        }
        else {
          cVar2 = '\0';
        }
      }
      else {
        cVar2 = '\0';
      }
    }
    else {
      cVar2 = '\0';
    }
  }
  else {
    iVar3 = (*zcl_cli_resp_user_cb)(param_1);
    cVar2 = iVar3 != 0;
  }
  return cVar2;
}

