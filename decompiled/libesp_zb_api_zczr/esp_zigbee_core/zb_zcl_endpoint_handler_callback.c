/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
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
  short sVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined2 *puVar9;
  uint uVar10;
  uint *puVar11;
  byte *pbVar12;
  int iVar13;
  undefined1 *puVar14;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 *puVar15;
  int *piVar16;
  uint *puVar17;
  uint *puVar18;
  undefined2 *puVar19;
  uint uVar20;
  bool bVar21;
  uint auStack_5c [8];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uVar20 = param_1 - 1U & 0xff;
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20);
  sVar1 = *(short *)(iVar6 + 4);
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20);
  sVar2 = *(short *)(iVar6 + 6);
  UNRECOVERED_JUMPTABLE = zcl_cli_resp_user_cb;
  if (zcl_cli_resp_user_cb != (code *)0x0) goto _L0;
  iVar6 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar6 + 0x16) == '\0') {
    iVar6 = zb_buf_get_tail_func(param_1,0x1b);
    sVar3 = *(short *)(iVar6 + 0xf);
    piVar16 = s_endpoint_handler_list;
    if (sVar3 < 0) {
      sVar3 = -0x8000;
    }
    for (; piVar16 + -2 != (int *)0xfffffff8; piVar16 = (int *)*piVar16) {
      if (*(short *)(piVar16 + -2) == sVar3) {
        iVar6 = (*(code *)piVar16[-1])(param_1,(code *)piVar16[-1]);
        goto _L0;
      }
    }
    iVar6 = 0;
_L0:
    if (-1 < sVar3) {
      if (iVar6 != 0) {
        return 1;
      }
      if (s_privilege_command_handler == (code *)0x0) goto _L0;
      iVar6 = (*s_privilege_command_handler)(param_1);
    }
    if (iVar6 != 0) {
      return 1;
    }
  }
  else {
    iVar6 = zb_buf_get_tail_func();
    if (((iVar6 != 0) && (*(char *)(iVar6 + 0x14) == '\x01')) && (zb_core_action_cb != (code *)0x0))
    {
      bVar4 = *(byte *)(iVar6 + 0x13);
      bVar21 = true;
      if (bVar4 == 9) {
        iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar8 != 0) goto _L0;
        iVar8 = 0;
        while ((uVar20 = zb_buf_len_func(param_1), 4 < uVar20 &&
               (pbVar12 = (byte *)zb_buf_begin_func(param_1), pbVar12 != (byte *)0x0))) {
          uVar20 = 6;
          if (pbVar12[1] == 0) {
            iVar13 = zb_zcl_is_analog_data_type(pbVar12[4]);
            uVar20 = iVar13 + 9U & 0xffff;
          }
          uVar10 = zb_buf_len_func(param_1);
          if (uVar10 < uVar20) break;
          bVar4 = zb_zcl_zcl8_statuses_conversion(*pbVar12);
          *pbVar12 = bVar4;
          if ((bVar4 & 0x7f) != 0) {
            zb_buf_len_func(param_1);
            uVar20 = 4;
          }
          uVar10 = zb_buf_len_func(param_1);
          if (uVar10 < uVar20) goto _L0;
          zb_buf_cut_left_func(param_1,uVar20);
          auStack_5c[0] = (uint)*pbVar12;
          uStack_3c = (uint *)CONCAT22(*(undefined2 *)(pbVar12 + 2),(undefined2)uStack_3c);
          uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,pbVar12[1]);
          if (auStack_5c[0] == 0) {
            if (pbVar12[1] == 0) {
              uStack_38 = (undefined2 *)CONCAT31(uStack_38._1_3_,pbVar12[4]);
              uStack_38 = (undefined2 *)CONCAT22(*(undefined2 *)(pbVar12 + 5),(undefined2)uStack_38)
              ;
              uStack_34 = CONCAT13(uStack_34._3_1_,*(undefined3 *)(pbVar12 + 7));
            }
            else {
              uStack_38 = (undefined2 *)CONCAT22(uStack_38._2_2_,*(undefined2 *)(pbVar12 + 4));
            }
          }
          else {
            uStack_38 = (undefined2 *)0x0;
            uStack_34 = 0;
          }
          iVar8 = (*zb_core_action_cb)(0x1003,auStack_5c,zb_core_action_cb);
        }
        zb_buf_len_func(param_1);
        zb_buf_cut_left_func(param_1,0);
      }
      else {
        if (9 < bVar4) {
          if (bVar4 == 0xb) {
            if ((*(short *)(iVar6 + 0xf) != 0x19) && (*(short *)(iVar6 + 0xf) != -0x400)) {
              iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
              if (iVar8 == 0) {
                uVar20 = zb_buf_len_func(param_1);
                if (uVar20 < 2) {
                  auStack_5c[0] = 1;
                  uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,0xff);
                  uStack_38 = (undefined2 *)0x1;
                }
                else {
                  auStack_5c[0] = 0;
                  puVar14 = (undefined1 *)zb_buf_begin_func(param_1);
                  uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar14);
                  iVar8 = zb_buf_begin_func(param_1);
                  uStack_38 = (undefined2 *)(uint)*(byte *)(iVar8 + 1);
                }
                iVar8 = (*zb_core_action_cb)(0x1005,auStack_5c,zb_core_action_cb);
              }
              goto _L0;
            }
          }
          else {
            if (bVar4 < 0xc) {
              zb_zcl_report_attr_cmd_handler(param_1);
              return 1;
            }
            if (bVar4 == 0xd) {
              uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
              uStack_38 = (undefined2 *)0x0;
              iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
              if (iVar8 != 0) goto _L0;
              iVar8 = zb_buf_len_func(param_1);
              if (iVar8 == 0) {
                uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
              }
              else {
                puVar14 = (undefined1 *)zb_buf_begin_func(param_1);
                uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar14);
                zb_buf_cut_left_func(param_1,1);
              }
              puVar9 = (undefined2 *)0x0;
              puVar15 = uStack_38;
              while ((uStack_38 = puVar15, puVar19 = puVar9, uVar20 = zb_buf_len_func(param_1),
                     2 < uVar20 &&
                     (puVar15 = (undefined2 *)zb_buf_begin_func(param_1),
                     puVar15 != (undefined2 *)0x0))) {
                zb_buf_cut_left_func(param_1,3);
                puVar9 = (undefined2 *)malloc(0xc);
                if (puVar9 == (undefined2 *)0x0) {
                  iVar8 = 0x101;
                  goto _L0;
                }
                *puVar9 = *puVar15;
                bVar4 = *(byte *)(puVar15 + 1);
                *(undefined4 *)(puVar9 + 4) = 0;
                *(uint *)(puVar9 + 2) = (uint)bVar4;
                puVar15 = puVar9;
                if (puVar19 != (undefined2 *)0x0) {
                  *(undefined2 **)(puVar19 + 4) = puVar9;
                  puVar15 = uStack_38;
                }
              }
              iVar8 = (*zb_core_action_cb)(0x1004,auStack_5c,zb_core_action_cb);
              puVar9 = uStack_38;
              while (puVar9 != (undefined2 *)0x0) {
                puVar15 = *(undefined2 **)(puVar9 + 4);
                free(puVar9);
                puVar9 = puVar15;
              }
              goto _L0;
            }
            if ((bVar4 != 0xc) && ((bVar4 == 0x14 || ((bVar4 & 0xfb) == 0x12)))) {
              uVar7 = esp_log_timestamp();
              esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar7,"ESP_ZIGBEE_CORE",
                            *(undefined1 *)(iVar6 + 0x13));
            }
          }
          goto _L0;
        }
        if (bVar4 != 4) {
          if (bVar4 < 5) {
            if (bVar4 == 0) {
              if (*(short *)(iVar6 + 0xf) == 0x15) {
                esp_zcl_commissioning_sync_with_attributes();
              }
            }
            else if (bVar4 == 1) {
              if ((*(short *)(iVar6 + 0xf) == 10) &&
                 (iVar8 = zb_zcl_time_server_read_attr_handle(param_1), iVar8 != 0)) {
                bVar21 = false;
                goto _L0;
              }
              uStack_3c = (uint *)0x0;
              iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
              if (iVar8 != 0) goto _L0;
              puVar11 = (uint *)0x0;
              puVar17 = uStack_3c;
              while ((uStack_3c = puVar17, puVar18 = puVar11, uVar20 = zb_buf_len_func(param_1),
                     2 < uVar20 &&
                     (puVar9 = (undefined2 *)zb_buf_begin_func(param_1), puVar9 != (undefined2 *)0x0
                     ))) {
                uVar20 = 3;
                iVar8 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar9 + 1));
                *(char *)(puVar9 + 1) = (char)iVar8;
                if (iVar8 == 0) {
                  iVar8 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar9 + 3),puVar9 + 2);
                  uVar20 = iVar8 + 4U & 0xffff;
                  zb_buf_len_func(param_1);
                }
                uVar10 = zb_buf_len_func(param_1);
                if (uVar10 < uVar20) break;
                zb_buf_cut_left_func(param_1,uVar20);
                puVar11 = (uint *)malloc(0x14);
                uVar5 = *puVar9;
                bVar4 = *(byte *)(puVar9 + 1);
                *puVar11 = (uint)bVar4;
                *(undefined2 *)(puVar11 + 1) = uVar5;
                if (bVar4 == 0) {
                  bVar4 = *(byte *)((int)puVar9 + 3);
                  *(undefined2 *)(puVar11 + 2) = 0;
                  *(ushort *)((int)puVar11 + 6) = (ushort)bVar4;
                  uVar5 = esp_zb_zcl_get_attribute_size(puVar9 + 2);
                }
                else {
                  *(undefined2 *)((int)puVar11 + 6) = 0;
                  *(undefined2 *)(puVar11 + 2) = 0;
                  uVar5 = 0;
                }
                *(undefined2 *)((int)puVar11 + 10) = uVar5;
                puVar15 = (undefined2 *)0x0;
                if (*(char *)(puVar9 + 1) == '\0') {
                  puVar15 = puVar9 + 2;
                }
                puVar11[3] = (uint)puVar15;
                puVar11[4] = 0;
                puVar17 = puVar11;
                if (puVar18 != (uint *)0x0) {
                  puVar18[4] = (uint)puVar11;
                  puVar17 = uStack_3c;
                }
              }
              iVar8 = (*zb_core_action_cb)(0x1000,auStack_5c,zb_core_action_cb);
              puVar11 = uStack_3c;
              while (puVar11 != (uint *)0x0) {
                puVar17 = (uint *)puVar11[4];
                free(puVar11);
                puVar11 = puVar17;
              }
              goto _L0;
            }
          }
          else if (bVar4 == 7) {
            uStack_3c = (uint *)0x0;
            iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
            puVar11 = (uint *)0x0;
            puVar17 = uStack_3c;
            if (iVar8 != 0) goto _L0;
            while ((uStack_3c = puVar17, puVar18 = puVar11, iVar8 = zb_buf_len_func(param_1),
                   iVar8 != 0 &&
                   (pbVar12 = (byte *)zb_buf_begin_func(param_1), pbVar12 != (byte *)0x0))) {
              bVar4 = zb_zcl_zcl8_statuses_conversion(*pbVar12);
              *pbVar12 = bVar4;
              uVar20 = 1;
              if ((bVar4 & 0x7f) != 0) {
                zb_buf_len_func(param_1);
                uVar20 = 4;
              }
              uVar10 = zb_buf_len_func(param_1);
              if (uVar10 < uVar20) break;
              zb_buf_cut_left_func(param_1);
              puVar11 = (uint *)malloc(0xc);
              bVar4 = *pbVar12;
              *puVar11 = (uint)bVar4;
              if (bVar4 == 0) {
                *(undefined2 *)((int)puVar11 + 6) = 0xffff;
                bVar4 = 0xff;
              }
              else {
                *(undefined2 *)((int)puVar11 + 6) = *(undefined2 *)(pbVar12 + 2);
                bVar4 = pbVar12[1];
              }
              *(byte *)(puVar11 + 1) = bVar4;
              puVar11[2] = 0;
              puVar17 = puVar11;
              if (puVar18 != (uint *)0x0) {
                puVar18[2] = (uint)puVar11;
                puVar17 = uStack_3c;
              }
            }
            iVar8 = (*zb_core_action_cb)(0x1002,auStack_5c,zb_core_action_cb);
            puVar11 = uStack_3c;
            while (puVar11 != (uint *)0x0) {
              puVar17 = (uint *)puVar11[2];
              free(puVar11);
              puVar11 = puVar17;
            }
            goto _L0;
          }
          goto _L0;
        }
        uStack_3c = (uint *)0x0;
        iVar8 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar8 == 0) {
          puVar11 = (uint *)0x0;
          puVar17 = uStack_3c;
          while ((uStack_3c = puVar17, puVar18 = puVar11, iVar8 = zb_buf_len_func(param_1),
                 iVar8 != 0 &&
                 (pbVar12 = (byte *)zb_buf_begin_func(param_1), pbVar12 != (byte *)0x0))) {
            iVar8 = zb_zcl_zcl8_statuses_conversion(*pbVar12);
            *pbVar12 = (byte)iVar8;
            uVar20 = 1;
            if (iVar8 != 0) {
              zb_buf_len_func(param_1);
              uVar20 = 3;
            }
            uVar10 = zb_buf_len_func(param_1);
            if (uVar10 < uVar20) break;
            zb_buf_cut_left_func(param_1);
            puVar11 = (uint *)malloc(0xc);
            bVar4 = *pbVar12;
            *puVar11 = (uint)bVar4;
            uVar5 = 0xffff;
            if (bVar4 != 0) {
              uVar5 = *(undefined2 *)(pbVar12 + 1);
            }
            *(undefined2 *)(puVar11 + 1) = uVar5;
            puVar11[2] = 0;
            puVar17 = puVar11;
            if (puVar18 != (uint *)0x0) {
              puVar18[2] = (uint)puVar11;
              puVar17 = uStack_3c;
            }
          }
          iVar8 = (*zb_core_action_cb)(0x1001,auStack_5c,zb_core_action_cb);
          puVar11 = uStack_3c;
          while (puVar11 != (uint *)0x0) {
            puVar17 = (uint *)puVar11[2];
            free(puVar11);
            puVar11 = puVar17;
          }
        }
      }
_L0:
      bVar21 = iVar8 != 0;
_L0:
      zb_zcl_send_default_handler(param_1,iVar6,bVar21);
      return 1;
    }
  }
_L0:
  if (zcl_raw_command_cb == (code *)0x0) {
    return 0;
  }
  iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20);
  if ((*(short *)(iVar6 + 4) != sVar1) ||
     (iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20), UNRECOVERED_JUMPTABLE = zcl_raw_command_cb,
     *(short *)(iVar6 + 6) != sVar2)) {
    iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20);
    *(char *)(iVar6 + 4) = (char)sVar1;
    *(char *)(iVar6 + 5) = (char)((ushort)sVar1 >> 8);
    iVar6 = zb_bufpool_storage_bufid_to_buf(uVar20);
    *(char *)(iVar6 + 6) = (char)sVar2;
    *(char *)(iVar6 + 7) = (char)((ushort)sVar2 >> 8);
    UNRECOVERED_JUMPTABLE = zcl_raw_command_cb;
  }
_L0:
                    /* WARNING: Could not recover jumptable at 0x00010b1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar7 = (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return uVar7;
}

