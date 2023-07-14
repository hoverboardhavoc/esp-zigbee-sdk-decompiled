/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_endpoint_handler_callback(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined2 uStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2c;
  char cStack_2b;
  char cStack_2a;
  char cStack_29;
  char cStack_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  
  pcVar5 = (char *)zb_buf_get_tail_func(0x1a);
  if (zcl_cli_resp_user_cb != (code *)0x0) {
    iVar6 = (*zcl_cli_resp_user_cb)(param_1);
    return (uint)(iVar6 != 0);
  }
  cVar1 = pcVar5[0xc];
  cVar2 = pcVar5[0xb];
  if (*pcVar5 == '\0') {
    cStack_2b = pcVar5[1];
    cStack_2a = pcVar5[2];
    uStack_2c = 0;
  }
  else if (*pcVar5 == '\x03') {
    cStack_2b = pcVar5[1];
    cStack_2a = pcVar5[2];
    cStack_29 = pcVar5[3];
    cStack_28 = pcVar5[4];
    cStack_27 = pcVar5[5];
    cStack_26 = pcVar5[6];
    cStack_25 = pcVar5[7];
    cStack_24 = pcVar5[8];
    uStack_2c = 3;
  }
  cStack_23 = cVar1;
  cStack_22 = cVar2;
  if (pcVar5[0x13] == '\x01') {
    uVar7 = (uint)(byte)pcVar5[0x15];
    if (uVar7 == 0) {
      if (*(short *)(pcVar5 + 0xe) == 4) {
        bVar3 = pcVar5[0x12];
        if (bVar3 == 2) {
          if (zcl_get_group_membership_resp_user_cb == 0) {
            return 0;
          }
          esp_zb_zcl_groups_get_group_membership_res(param_1);
          uVar7 = 1;
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            if (zcl_add_group_resp_user_cb == 0) {
              return 0;
            }
            esp_zb_zcl_groups_get_add_group_res(param_1);
            uVar7 = 1;
          }
          else {
            if (bVar3 != 1) {
              return 0;
            }
            if (zcl_view_group_resp_user_cb == 0) {
              return 0;
            }
            esp_zb_zcl_groups_get_view_group_res(param_1);
            uVar7 = 1;
          }
        }
        else {
          if (bVar3 != 3) {
            return 0;
          }
          if (zcl_remove_group_resp_user_cb == 0) {
            return 0;
          }
          esp_zb_zcl_groups_get_remove_group_res(param_1);
          uVar7 = 1;
        }
      }
      else {
        if (*(short *)(pcVar5 + 0xe) != 0x500) {
          return 0;
        }
        if (pcVar5[0x12] == '\0') {
          uVar7 = esp_zb_handle_ias_zone_status_change_notification(param_1);
        }
        else {
          if (pcVar5[0x12] != '\x01') {
            return 0;
          }
          uVar7 = esp_zb_handle_ias_zone_enroll_request(param_1);
        }
        if (uVar7 == 0) {
          return 0;
        }
      }
    }
    else {
      if (pcVar5[0x12] != '\x01') {
        return 0;
      }
      if (zcl_read_attr_user_cb == (code *)0x0) {
        return 0;
      }
      uVar8 = zb_buf_len_func(param_1);
      if (uVar8 < 3) {
        puVar12 = (undefined2 *)0x0;
      }
      else {
        puVar12 = (undefined2 *)zb_buf_begin_func(param_1);
        if (puVar12 == (undefined2 *)0x0) {
          return 0;
        }
        iVar6 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar12 + 1));
        *(char *)(puVar12 + 1) = (char)iVar6;
        if (iVar6 == 0) {
          iVar6 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar12 + 3),puVar12 + 2);
          uVar8 = iVar6 + 4U & 0xff;
          zb_buf_len_func(param_1);
        }
        else {
          uVar8 = 3;
        }
        uVar9 = zb_buf_len_func(param_1);
        if (uVar9 < uVar8) {
          return 0;
        }
        zb_buf_cut_left_func(param_1,uVar8);
      }
      if (puVar12 == (undefined2 *)0x0) {
        return 0;
      }
      (*zcl_read_attr_user_cb)
                (*(undefined1 *)(puVar12 + 1),*(undefined2 *)(pcVar5 + 0xe),*puVar12,
                 *(undefined1 *)((int)puVar12 + 3),puVar12 + 2,zcl_read_attr_user_cb);
    }
  }
  else {
    if (pcVar5[0x13] != '\0') {
      return 0;
    }
    uVar7 = esp_zb_get_global_custom_cluster_id();
    if (uVar7 == *(ushort *)(pcVar5 + 0xe)) {
      if (pcVar5[0x15] != '\0') {
        return 0;
      }
      if (zcl_custom_cluster_cmd_cb == (code *)0x0) {
        return 0;
      }
      puVar11 = (undefined4 *)malloc(9);
      esp_zb_custom_cluster_get_cmd_req(param_1,puVar11);
      (*zcl_custom_cluster_cmd_cb)(*puVar11,(int)puVar11 + 5,zcl_custom_cluster_cmd_cb);
      free(puVar11);
      uVar7 = 1;
    }
    else {
      if (pcVar5[0x15] != '\0') {
        return 0;
      }
      pcVar10 = (code *)esp_zcl_privilege_command_list_find(cVar1,pcVar5[0x12]);
      if (pcVar10 == (code *)0x0) {
        return 0;
      }
      puVar11 = (undefined4 *)zb_buf_begin_func(param_1);
      uStack_48 = CONCAT13(cStack_2a,
                           CONCAT12(cStack_2b,CONCAT11(uStack_2c,puVar11 == (undefined4 *)0x0)));
      uStack_44 = CONCAT13(cStack_26,CONCAT12(cStack_27,CONCAT11(cStack_28,cStack_29)));
      uStack_40 = CONCAT13(cVar2,CONCAT12(cVar1,CONCAT11(cStack_24,cStack_25)));
      uStack_3c = (uint)CONCAT12(pcVar5[0x12],*(undefined2 *)(pcVar5 + 0xe));
      uStack_60 = *puVar11;
      uVar4 = *(undefined4 *)((int)puVar11 + 5);
      uStack_34 = CONCAT13((char)((uint)uVar4 >> 0x10),
                           CONCAT12((char)((uint)uVar4 >> 8),*(undefined2 *)(puVar11 + 1)));
      uStack_30 = CONCAT11(uStack_30._1_1_,(char)((uint)uVar4 >> 0x18));
      local_70 = uStack_48;
      uStack_6c = uStack_44;
      uStack_68 = uStack_40;
      uStack_64 = uStack_3c;
      uStack_5c = uStack_34;
      uStack_58 = uStack_30;
      uStack_38 = uStack_60;
      (*pcVar10)(&local_70);
      uVar7 = 1;
    }
  }
  zb_buf_free_func(param_1);
  return uVar7;
}

