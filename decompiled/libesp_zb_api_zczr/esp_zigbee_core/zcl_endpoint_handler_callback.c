/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
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
  short sVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  code *pcVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
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
  
  pcVar6 = (char *)zb_buf_get_tail_func(0x1b);
  if (zcl_cli_resp_user_cb != (code *)0x0) {
    iVar7 = (*zcl_cli_resp_user_cb)(param_1);
    return (uint)(iVar7 != 0);
  }
  cVar1 = pcVar6[0xc];
  cVar2 = pcVar6[0xb];
  if (*pcVar6 == '\0') {
    cStack_2b = pcVar6[1];
    cStack_2a = pcVar6[2];
    uStack_2c = 0;
  }
  else if (*pcVar6 == '\x03') {
    cStack_2b = pcVar6[1];
    cStack_2a = pcVar6[2];
    cStack_29 = pcVar6[3];
    cStack_28 = pcVar6[4];
    cStack_27 = pcVar6[5];
    cStack_26 = pcVar6[6];
    cStack_25 = pcVar6[7];
    cStack_24 = pcVar6[8];
    uStack_2c = 3;
  }
  cStack_23 = cVar1;
  cStack_22 = cVar2;
  if (pcVar6[0x14] == '\x01') {
    uVar8 = (uint)(byte)pcVar6[0x16];
    if (uVar8 == 0) {
      sVar4 = *(short *)(pcVar6 + 0xf);
      if (sVar4 == 5) {
        esp_zb_zcl_scene_resp_handler(param_1,pcVar6[0x13]);
        uVar8 = 1;
      }
      else if (sVar4 == 0x500) {
        if (pcVar6[0x13] == '\0') {
          uVar8 = esp_zb_handle_ias_zone_status_change_notification(param_1);
        }
        else {
          if (pcVar6[0x13] != '\x01') {
            return 0;
          }
          uVar8 = esp_zb_handle_ias_zone_enroll_request(param_1);
        }
        if (uVar8 == 0) {
          return 0;
        }
      }
      else {
        if (sVar4 != 4) {
          return 0;
        }
        bVar3 = pcVar6[0x13];
        if (bVar3 == 2) {
          if (zcl_get_group_membership_resp_user_cb == 0) {
            return 0;
          }
          esp_zb_zcl_groups_get_group_membership_res(param_1);
          uVar8 = 1;
        }
        else if (bVar3 < 3) {
          if (bVar3 == 0) {
            if (zcl_add_group_resp_user_cb == 0) {
              return 0;
            }
            esp_zb_zcl_groups_get_add_group_res(param_1);
            uVar8 = 1;
          }
          else {
            if (bVar3 != 1) {
              return 0;
            }
            if (zcl_view_group_resp_user_cb == 0) {
              return 0;
            }
            esp_zb_zcl_groups_get_view_group_res(param_1);
            uVar8 = 1;
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
          uVar8 = 1;
        }
      }
    }
    else {
      if (pcVar6[0x13] != '\x01') {
        return 0;
      }
      if (zcl_read_attr_user_cb == (code *)0x0) {
        return 0;
      }
      uVar9 = zb_buf_len_func(param_1);
      if (uVar9 < 3) {
        puVar13 = (undefined2 *)0x0;
      }
      else {
        puVar13 = (undefined2 *)zb_buf_begin_func(param_1);
        if (puVar13 == (undefined2 *)0x0) {
          return 0;
        }
        iVar7 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar13 + 1));
        *(char *)(puVar13 + 1) = (char)iVar7;
        if (iVar7 == 0) {
          iVar7 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar13 + 3),puVar13 + 2);
          uVar9 = iVar7 + 4U & 0xff;
          zb_buf_len_func(param_1);
        }
        else {
          uVar9 = 3;
        }
        uVar10 = zb_buf_len_func(param_1);
        if (uVar10 < uVar9) {
          return 0;
        }
        zb_buf_cut_left_func(param_1,uVar9);
      }
      if (puVar13 == (undefined2 *)0x0) {
        return 0;
      }
      (*zcl_read_attr_user_cb)
                (*(undefined1 *)(puVar13 + 1),*(undefined2 *)(pcVar6 + 0xf),*puVar13,
                 *(undefined1 *)((int)puVar13 + 3),puVar13 + 2,zcl_read_attr_user_cb);
    }
  }
  else {
    if (pcVar6[0x14] != '\0') {
      return 0;
    }
    uVar8 = esp_zb_get_global_custom_cluster_id();
    if (uVar8 == *(ushort *)(pcVar6 + 0xf)) {
      if (pcVar6[0x16] != '\0') {
        return 0;
      }
      if (zcl_custom_cluster_cmd_cb == (code *)0x0) {
        return 0;
      }
      puVar12 = (undefined4 *)malloc(9);
      esp_zb_custom_cluster_get_cmd_req(param_1,puVar12);
      (*zcl_custom_cluster_cmd_cb)(*puVar12,(int)puVar12 + 5,zcl_custom_cluster_cmd_cb);
      free(puVar12);
      uVar8 = 1;
    }
    else {
      if (pcVar6[0x16] != '\0') {
        return 0;
      }
      pcVar11 = (code *)esp_zcl_privilege_command_list_find(cVar1,pcVar6[0x13]);
      if (pcVar11 == (code *)0x0) {
        return 0;
      }
      puVar12 = (undefined4 *)zb_buf_begin_func(param_1);
      uStack_48 = CONCAT13(cStack_2a,
                           CONCAT12(cStack_2b,CONCAT11(uStack_2c,puVar12 == (undefined4 *)0x0)));
      uStack_44 = CONCAT13(cStack_26,CONCAT12(cStack_27,CONCAT11(cStack_28,cStack_29)));
      uStack_40 = CONCAT13(cVar2,CONCAT12(cVar1,CONCAT11(cStack_24,cStack_25)));
      uStack_3c = (uint)CONCAT12(pcVar6[0x13],*(undefined2 *)(pcVar6 + 0xf));
      uStack_60 = *puVar12;
      uVar5 = *(undefined4 *)((int)puVar12 + 5);
      uStack_34 = CONCAT13((char)((uint)uVar5 >> 0x10),
                           CONCAT12((char)((uint)uVar5 >> 8),*(undefined2 *)(puVar12 + 1)));
      uStack_30 = CONCAT11(uStack_30._1_1_,(char)((uint)uVar5 >> 0x18));
      local_70 = uStack_48;
      uStack_6c = uStack_44;
      uStack_68 = uStack_40;
      uStack_64 = uStack_3c;
      uStack_5c = uStack_34;
      uStack_58 = uStack_30;
      uStack_38 = uStack_60;
      (*pcVar11)(&local_70);
      uVar8 = 1;
    }
  }
  zb_buf_free_func(param_1);
  return uVar8;
}

