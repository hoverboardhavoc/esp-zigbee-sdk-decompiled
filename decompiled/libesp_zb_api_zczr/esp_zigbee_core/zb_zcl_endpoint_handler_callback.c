/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_endpoint_handler_callback(int param_1)

{
  short sVar1;
  short sVar2;
  uint *puVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  uint uVar11;
  uint *puVar12;
  byte *pbVar13;
  int iVar14;
  bool bVar15;
  short *psVar16;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 *puVar17;
  char *pcVar18;
  uint *puVar19;
  undefined2 *puVar20;
  uint uVar21;
  uint auStack_5c [5];
  char cStack_45;
  short sStack_44;
  byte bStack_40;
  char cStack_3f;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uVar21 = param_1 - 1U & 0xff;
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21);
  sVar1 = *(short *)(iVar6 + 4);
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21);
  sVar2 = *(short *)(iVar6 + 6);
  UNRECOVERED_JUMPTABLE = zcl_cli_resp_user_cb;
  if (zcl_cli_resp_user_cb != (code *)0x0) goto _L0;
  iVar6 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar6 + 0x16) == '\0') {
    iVar6 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(short *)(iVar6 + 0xf) < 0) {
      iVar6 = zb_buf_get_tail_func(param_1,0x1b);
      iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
      if (iVar9 != 0) {
        return 1;
      }
      if ((sStack_44 < 0) && (zb_core_action_cb != (code *)0x0)) {
        auStack_5c[0] = (uint)(iVar6 == 0);
        uVar5 = zb_buf_len_func(param_1);
        uStack_3c = (uint *)CONCAT22(uStack_3c._2_2_,uVar5);
        uStack_38 = (undefined2 *)zb_buf_begin_func(param_1);
        iVar9 = esp_zb_zcl_get_cluster(cStack_45,sStack_44,2);
        iVar14 = esp_zb_zcl_get_cluster(cStack_45,sStack_44,1);
        if (iVar9 == 0) {
          if (iVar14 != 0) {
            if (cStack_3f == '\0') goto _L0;
            if (cStack_3f == '\x01') {
_L0:
              if (zb_core_action_cb == (code *)0x0) goto _L0;
              uVar7 = 0x1041;
              goto _L0;
            }
          }
_L0:
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC2,uVar7,"ESP_ZIGBEE_CORE",sStack_44,cStack_45);
          bVar15 = true;
        }
        else {
          if (cStack_3f != '\x01') {
            if (iVar14 == 0) {
              if (cStack_3f == '\0') goto _L0;
            }
            else if (cStack_3f == '\0') goto _L0;
            goto _L0;
          }
_L0:
          if (zb_core_action_cb != (code *)0x0) {
            uVar7 = 0x1040;
_L0:
            iVar9 = (*zb_core_action_cb)(uVar7,auStack_5c);
            if (iVar6 == 0) {
              return 1;
            }
            bVar15 = iVar9 != 0;
            goto _L0;
          }
_L0:
          bVar15 = false;
        }
        if (iVar6 == 0) {
          return 1;
        }
_L0:
        zb_zcl_send_default_handler(param_1,iVar6,bVar15);
        return 1;
      }
    }
    else {
      psVar16 = &s_endpoint_handler_table;
      iVar9 = 0;
      do {
        if (*psVar16 == *(short *)(iVar6 + 0xf)) {
          iVar6 = (*(code *)(&PTR_zb_zcl_group_cluster_resp_handler_00015900)[iVar9 * 2])
                            (param_1,(&PTR_zb_zcl_group_cluster_resp_handler_00015900)[iVar9 * 2]);
          if (iVar6 != 0) {
            return 1;
          }
          break;
        }
        iVar9 = iVar9 + 1;
        psVar16 = psVar16 + 4;
      } while (iVar9 != 4);
      iVar6 = zb_buf_get_tail_func(param_1,0x1b);
      iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
      if (iVar9 != 0) {
        return 1;
      }
      for (pcVar18 = s_zcl_privilege_cluster_list; pcVar18 != (char *)0x0;
          pcVar18 = *(char **)(pcVar18 + 8)) {
        if (((*pcVar18 == cStack_45) && (*(short *)(pcVar18 + 2) == sStack_44)) &&
           (*(ushort *)(pcVar18 + 4) == (ushort)bStack_40)) {
          uVar5 = zb_buf_len_func(param_1);
          uStack_3c = (uint *)CONCAT22(uStack_3c._2_2_,uVar5);
          uStack_38 = (undefined2 *)zb_buf_begin_func(param_1);
          if (zb_core_action_cb == (code *)0x0) goto _L0;
          if (cStack_3f == '\x01') {
            uVar7 = 0x1051;
          }
          else {
            uVar7 = 0x1050;
          }
          goto _L0;
        }
      }
    }
  }
  else {
    iVar6 = zb_buf_get_tail_func();
    if (((iVar6 != 0) && (*(char *)(iVar6 + 0x14) == '\x01')) && (zb_core_action_cb != (code *)0x0))
    {
      bVar4 = *(byte *)(iVar6 + 0x13);
      bVar15 = true;
      if (bVar4 == 9) {
        iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar9 != 0) goto _L0;
        iVar9 = 0;
        while ((uVar21 = zb_buf_len_func(param_1), 4 < uVar21 &&
               (pbVar13 = (byte *)zb_buf_begin_func(param_1), pbVar13 != (byte *)0x0))) {
          uVar21 = 6;
          if (pbVar13[1] == 0) {
            iVar14 = zb_zcl_is_analog_data_type(pbVar13[4]);
            uVar21 = iVar14 + 9U & 0xffff;
          }
          uVar11 = zb_buf_len_func(param_1);
          if (uVar11 < uVar21) break;
          bVar4 = zb_zcl_zcl8_statuses_conversion(*pbVar13);
          *pbVar13 = bVar4;
          if ((bVar4 & 0x7f) != 0) {
            zb_buf_len_func(param_1);
            uVar21 = 4;
          }
          uVar11 = zb_buf_len_func(param_1);
          if (uVar11 < uVar21) goto _L0;
          zb_buf_cut_left_func(param_1,uVar21);
          auStack_5c[0] = (uint)*pbVar13;
          uStack_3c = (uint *)CONCAT22(*(undefined2 *)(pbVar13 + 2),(undefined2)uStack_3c);
          uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,pbVar13[1]);
          if (auStack_5c[0] == 0) {
            if (pbVar13[1] == 0) {
              uStack_38 = (undefined2 *)CONCAT31(uStack_38._1_3_,pbVar13[4]);
              uStack_38 = (undefined2 *)CONCAT22(*(undefined2 *)(pbVar13 + 5),(undefined2)uStack_38)
              ;
              uStack_34 = CONCAT13(uStack_34._3_1_,*(undefined3 *)(pbVar13 + 7));
            }
            else {
              uStack_38 = (undefined2 *)CONCAT22(uStack_38._2_2_,*(undefined2 *)(pbVar13 + 4));
            }
          }
          else {
            uStack_38 = (undefined2 *)0x0;
            uStack_34 = 0;
          }
          iVar9 = (*zb_core_action_cb)(0x1003,auStack_5c,zb_core_action_cb);
        }
        zb_buf_len_func(param_1);
        zb_buf_cut_left_func(param_1,0);
      }
      else if (bVar4 < 10) {
        if (bVar4 == 4) {
          uStack_3c = (uint *)0x0;
          iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
          if (iVar9 != 0) goto _L0;
          puVar12 = (uint *)0x0;
          puVar19 = uStack_3c;
          while ((uStack_3c = puVar19, puVar3 = puVar12, iVar9 = zb_buf_len_func(param_1),
                 iVar9 != 0 &&
                 (pbVar13 = (byte *)zb_buf_begin_func(param_1), pbVar13 != (byte *)0x0))) {
            iVar9 = zb_zcl_zcl8_statuses_conversion(*pbVar13);
            *pbVar13 = (byte)iVar9;
            uVar21 = 1;
            if (iVar9 != 0) {
              zb_buf_len_func(param_1);
              uVar21 = 3;
            }
            uVar11 = zb_buf_len_func(param_1);
            if (uVar11 < uVar21) break;
            zb_buf_cut_left_func(param_1);
            puVar12 = (uint *)malloc(0xc);
            bVar4 = *pbVar13;
            *puVar12 = (uint)bVar4;
            uVar5 = 0xffff;
            if (bVar4 != 0) {
              uVar5 = *(undefined2 *)(pbVar13 + 1);
            }
            *(undefined2 *)(puVar12 + 1) = uVar5;
            puVar12[2] = 0;
            puVar19 = puVar12;
            if (puVar3 != (uint *)0x0) {
              puVar3[2] = (uint)puVar12;
              puVar19 = uStack_3c;
            }
          }
          iVar9 = (*zb_core_action_cb)(0x1001,auStack_5c,zb_core_action_cb);
          puVar12 = uStack_3c;
          while (puVar12 != (uint *)0x0) {
            puVar19 = (uint *)puVar12[2];
            free(puVar12);
            puVar12 = puVar19;
          }
        }
        else if (bVar4 == 7) {
          uStack_3c = (uint *)0x0;
          iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
          puVar12 = (uint *)0x0;
          puVar19 = uStack_3c;
          if (iVar9 != 0) goto _L0;
          while ((uStack_3c = puVar19, puVar3 = puVar12, iVar9 = zb_buf_len_func(param_1),
                 iVar9 != 0 &&
                 (pbVar13 = (byte *)zb_buf_begin_func(param_1), pbVar13 != (byte *)0x0))) {
            bVar4 = zb_zcl_zcl8_statuses_conversion(*pbVar13);
            *pbVar13 = bVar4;
            uVar21 = 1;
            if ((bVar4 & 0x7f) != 0) {
              zb_buf_len_func(param_1);
              uVar21 = 4;
            }
            uVar11 = zb_buf_len_func(param_1);
            if (uVar11 < uVar21) break;
            zb_buf_cut_left_func(param_1);
            puVar12 = (uint *)malloc(0xc);
            bVar4 = *pbVar13;
            *puVar12 = (uint)bVar4;
            if (bVar4 == 0) {
              *(undefined2 *)((int)puVar12 + 6) = 0xffff;
              bVar4 = 0xff;
            }
            else {
              *(undefined2 *)((int)puVar12 + 6) = *(undefined2 *)(pbVar13 + 2);
              bVar4 = pbVar13[1];
            }
            *(byte *)(puVar12 + 1) = bVar4;
            puVar12[2] = 0;
            puVar19 = puVar12;
            if (puVar3 != (uint *)0x0) {
              puVar3[2] = (uint)puVar12;
              puVar19 = uStack_3c;
            }
          }
          iVar9 = (*zb_core_action_cb)(0x1002,auStack_5c,zb_core_action_cb);
          puVar12 = uStack_3c;
          while (puVar12 != (uint *)0x0) {
            puVar19 = (uint *)puVar12[2];
            free(puVar12);
            puVar12 = puVar19;
          }
        }
        else {
          if (bVar4 != 1) goto _L0;
          if ((*(short *)(iVar6 + 0xf) == 10) &&
             (iVar9 = zb_zcl_time_server_read_attr_handle(param_1), iVar9 != 0)) {
            bVar15 = false;
            goto _L0;
          }
          uStack_3c = (uint *)0x0;
          iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
          if (iVar9 != 0) goto _L0;
          puVar12 = (uint *)0x0;
          puVar19 = uStack_3c;
          while ((uStack_3c = puVar19, puVar3 = puVar12, uVar21 = zb_buf_len_func(param_1),
                 2 < uVar21 &&
                 (puVar10 = (undefined2 *)zb_buf_begin_func(param_1), puVar10 != (undefined2 *)0x0))
                ) {
            uVar21 = 3;
            iVar9 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar10 + 1));
            *(char *)(puVar10 + 1) = (char)iVar9;
            if (iVar9 == 0) {
              iVar9 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar10 + 3),puVar10 + 2);
              uVar21 = iVar9 + 4U & 0xffff;
              zb_buf_len_func(param_1);
            }
            uVar11 = zb_buf_len_func(param_1);
            if (uVar11 < uVar21) break;
            zb_buf_cut_left_func(param_1,uVar21);
            puVar12 = (uint *)malloc(0x14);
            uVar5 = *puVar10;
            bVar4 = *(byte *)(puVar10 + 1);
            *puVar12 = (uint)bVar4;
            *(undefined2 *)(puVar12 + 1) = uVar5;
            if (bVar4 == 0) {
              bVar4 = *(byte *)((int)puVar10 + 3);
              *(undefined2 *)(puVar12 + 2) = 0;
              *(ushort *)((int)puVar12 + 6) = (ushort)bVar4;
              uVar5 = esp_zb_zcl_get_attribute_size(puVar10 + 2);
            }
            else {
              *(undefined2 *)((int)puVar12 + 6) = 0;
              *(undefined2 *)(puVar12 + 2) = 0;
              uVar5 = 0;
            }
            *(undefined2 *)((int)puVar12 + 10) = uVar5;
            puVar17 = (undefined2 *)0x0;
            if (*(char *)(puVar10 + 1) == '\0') {
              puVar17 = puVar10 + 2;
            }
            puVar12[3] = (uint)puVar17;
            puVar12[4] = 0;
            puVar19 = puVar12;
            if (puVar3 != (uint *)0x0) {
              puVar3[4] = (uint)puVar12;
              puVar19 = uStack_3c;
            }
          }
          iVar9 = (*zb_core_action_cb)(0x1000,auStack_5c,zb_core_action_cb);
          puVar12 = uStack_3c;
          while (puVar12 != (uint *)0x0) {
            puVar19 = (uint *)puVar12[4];
            free(puVar12);
            puVar12 = puVar19;
          }
        }
      }
      else {
        if (bVar4 != 0xd) {
          if (bVar4 < 0xe) {
            if (((bVar4 == 0xb) && (*(short *)(iVar6 + 0xf) != 0x19)) &&
               (*(short *)(iVar6 + 0xf) != -0x400)) {
              iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
              if (iVar9 != 0) goto _L0;
              uVar21 = zb_buf_len_func(param_1);
              if (uVar21 < 2) {
                auStack_5c[0] = 1;
                uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,0xff);
                uStack_38 = (undefined2 *)0x1;
              }
              else {
                auStack_5c[0] = 0;
                puVar8 = (undefined1 *)zb_buf_begin_func(param_1);
                uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar8);
                iVar9 = zb_buf_begin_func(param_1);
                uStack_38 = (undefined2 *)(uint)*(byte *)(iVar9 + 1);
              }
              iVar9 = (*zb_core_action_cb)(0x1005,auStack_5c,zb_core_action_cb);
              goto _L0;
            }
          }
          else if ((bVar4 == 0x14) || ((bVar4 & 0xfb) == 0x12)) {
            uVar7 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC1,uVar7,"ESP_ZIGBEE_CORE",
                          *(undefined1 *)(iVar6 + 0x13));
          }
          goto _L0;
        }
        uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
        uStack_38 = (undefined2 *)0x0;
        iVar9 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar9 != 0) goto _L0;
        iVar9 = zb_buf_len_func(param_1);
        if (iVar9 == 0) {
          uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
        }
        else {
          puVar8 = (undefined1 *)zb_buf_begin_func(param_1);
          uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar8);
          zb_buf_cut_left_func(param_1,1);
        }
        puVar10 = (undefined2 *)0x0;
        puVar17 = uStack_38;
        while ((uStack_38 = puVar17, puVar20 = puVar10, uVar21 = zb_buf_len_func(param_1),
               2 < uVar21 &&
               (puVar17 = (undefined2 *)zb_buf_begin_func(param_1), puVar17 != (undefined2 *)0x0)))
        {
          zb_buf_cut_left_func(param_1,3);
          puVar10 = (undefined2 *)malloc(0xc);
          if (puVar10 == (undefined2 *)0x0) {
            iVar9 = 0x101;
            goto _L0;
          }
          *puVar10 = *puVar17;
          bVar4 = *(byte *)(puVar17 + 1);
          *(undefined4 *)(puVar10 + 4) = 0;
          *(uint *)(puVar10 + 2) = (uint)bVar4;
          puVar17 = puVar10;
          if (puVar20 != (undefined2 *)0x0) {
            *(undefined2 **)(puVar20 + 4) = puVar10;
            puVar17 = uStack_38;
          }
        }
        iVar9 = (*zb_core_action_cb)(0x1004,auStack_5c,zb_core_action_cb);
        puVar10 = uStack_38;
        while (puVar10 != (undefined2 *)0x0) {
          puVar17 = *(undefined2 **)(puVar10 + 4);
          free(puVar10);
          puVar10 = puVar17;
        }
      }
_L0:
      bVar15 = iVar9 != 0;
      goto _L0;
    }
  }
_L0:
  if (zcl_raw_command_cb == (code *)0x0) {
    return 0;
  }
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21);
  if ((*(short *)(iVar6 + 4) != sVar1) ||
     (iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21), UNRECOVERED_JUMPTABLE = zcl_raw_command_cb,
     *(short *)(iVar6 + 6) != sVar2)) {
    iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21);
    *(char *)(iVar6 + 4) = (char)sVar1;
    *(char *)(iVar6 + 5) = (char)((ushort)sVar1 >> 8);
    iVar6 = zb_bufpool_storage_bufid_to_buf(uVar21);
    *(char *)(iVar6 + 6) = (char)sVar2;
    *(char *)(iVar6 + 7) = (char)((ushort)sVar2 >> 8);
    UNRECOVERED_JUMPTABLE = zcl_raw_command_cb;
  }
_L0:
                    /* WARNING: Could not recover jumptable at 0x000107f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return uVar7;
}

