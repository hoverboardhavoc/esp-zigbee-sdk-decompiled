/*
 * Last changed at upstream commit 2472f337c160837a43a3b2545ff1f91e67f9b446
 * https://github.com/espressif/esp-zigbee-sdk/commit/2472f337c160837a43a3b2545ff1f91e67f9b446
 * Upstream date: 2025-02-21 02:56:04 +0000
 * Upstream subject: esp-zigbee-sdk: (fd3e0871)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_endpoint_handler_callback(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  int iVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  undefined1 *puVar15;
  ushort uVar16;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 *puVar17;
  int *piVar18;
  uint *puVar19;
  undefined2 *puVar20;
  uint *puVar21;
  uint uVar22;
  undefined4 auStack_58 [8];
  uint *puStack_38;
  undefined2 *puStack_34;
  
  uVar22 = param_1 - 1U & 0xff;
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22);
  sVar2 = *(short *)(iVar7 + 4);
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22);
  sVar3 = *(short *)(iVar7 + 6);
  UNRECOVERED_JUMPTABLE = zcl_cli_resp_user_cb;
  if (zcl_cli_resp_user_cb != (code *)0x0) goto _L0;
  iVar7 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar7 + 0x16) == '\0') {
    iVar7 = zb_buf_get_tail_func(param_1,0x1b);
    sVar4 = *(short *)(iVar7 + 0xf);
    piVar18 = s_endpoint_handler_list;
    if (sVar4 < 0) {
      sVar4 = -0x8000;
    }
    for (; piVar18 + -2 != (int *)0xfffffff8; piVar18 = (int *)*piVar18) {
      if (*(short *)(piVar18 + -2) == sVar4) {
        iVar7 = (*(code *)piVar18[-1])(param_1,(code *)piVar18[-1]);
        goto _L0;
      }
    }
    iVar7 = 0;
_L0:
    if (-1 < sVar4) {
      if (iVar7 != 0) {
        return 1;
      }
      if (s_privilege_command_handler == (code *)0x0) goto _L0;
      iVar7 = (*s_privilege_command_handler)(param_1);
    }
    if (iVar7 != 0) {
      return 1;
    }
  }
  else {
    iVar7 = zb_buf_get_tail_func();
    if ((iVar7 != 0) && (zb_core_action_cb != (code *)0x0)) {
      bVar5 = *(byte *)(iVar7 + 0x13);
      if (bVar5 == 9) {
        puStack_38 = (uint *)0x0;
        iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
        if (iVar10 == 0) {
          puVar13 = (uint *)0x0;
          puVar19 = puStack_38;
          while( true ) {
            puStack_38 = puVar19;
            puVar21 = puVar13;
            uVar22 = zb_buf_len_func(param_1);
            if ((uVar22 < 4) || (pbVar9 = (byte *)zb_buf_begin_func(param_1), pbVar9 == (byte *)0x0)
               ) {
              pbVar9 = (byte *)0x0;
              uVar22 = 0;
            }
            else {
              uVar22 = 6;
              if (pbVar9[1] == 0) {
                iVar10 = zb_zcl_is_analog_data_type(pbVar9[4]);
                uVar22 = iVar10 + 9U & 0xffff;
              }
              bVar5 = zb_zcl_zcl8_statuses_conversion(*pbVar9);
              *pbVar9 = bVar5;
              if ((bVar5 & 0x7f) != 0) {
                uVar22 = 4;
              }
            }
            uVar12 = zb_buf_len_func(param_1);
            if ((uVar12 < uVar22) || (zb_buf_cut_left_func(param_1,uVar22), pbVar9 == (byte *)0x0))
            break;
            puVar13 = (uint *)malloc(0x14);
            bVar5 = *pbVar9;
            *puVar13 = (uint)bVar5;
            *(undefined2 *)((int)puVar13 + 6) = *(undefined2 *)(pbVar9 + 2);
            bVar1 = pbVar9[1];
            *(byte *)(puVar13 + 1) = bVar1;
            if (bVar5 == 0) {
              if (bVar1 == 0) {
                *(byte *)(puVar13 + 2) = pbVar9[4];
                *(undefined2 *)((int)puVar13 + 10) = *(undefined2 *)(pbVar9 + 5);
                *(undefined2 *)(puVar13 + 3) = *(undefined2 *)(pbVar9 + 7);
                *(byte *)((int)puVar13 + 0xe) = pbVar9[9];
              }
              else {
                *(undefined2 *)(puVar13 + 2) = *(undefined2 *)(pbVar9 + 4);
              }
            }
            else {
              puVar13[2] = 0;
              puVar13[3] = 0;
            }
            puVar13[4] = 0;
            puVar19 = puVar13;
            if (puVar21 != (uint *)0x0) {
              puVar21[4] = (uint)puVar13;
              puVar19 = puStack_38;
            }
          }
          iVar10 = (*zb_core_action_cb)(0x1003,auStack_58,zb_core_action_cb);
          puVar13 = puStack_38;
          while (puVar13 != (uint *)0x0) {
            puVar19 = (uint *)puVar13[4];
            free(puVar13);
            puVar13 = puVar19;
          }
        }
_L0:
        zb_zcl_send_default_handler(param_1,iVar7,iVar10 != 0);
        return 1;
      }
      if (bVar5 < 10) {
        if (bVar5 == 4) {
          puStack_38 = (uint *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
          if (iVar10 == 0) {
            puVar13 = (uint *)0x0;
            puVar19 = puStack_38;
            while ((puStack_38 = puVar19, puVar21 = puVar13, iVar10 = zb_buf_len_func(param_1),
                   iVar10 != 0 &&
                   (pbVar9 = (byte *)zb_buf_begin_func(param_1), pbVar9 != (byte *)0x0))) {
              iVar10 = zb_zcl_zcl8_statuses_conversion(*pbVar9);
              *pbVar9 = (byte)iVar10;
              uVar22 = 1;
              if (iVar10 != 0) {
                zb_buf_len_func(param_1);
                uVar22 = 3;
              }
              uVar12 = zb_buf_len_func(param_1);
              if (uVar12 < uVar22) break;
              zb_buf_cut_left_func(param_1);
              puVar13 = (uint *)malloc(0xc);
              bVar5 = *pbVar9;
              *puVar13 = (uint)bVar5;
              uVar6 = 0xffff;
              if (bVar5 != 0) {
                uVar6 = *(undefined2 *)(pbVar9 + 1);
              }
              *(undefined2 *)(puVar13 + 1) = uVar6;
              puVar13[2] = 0;
              puVar19 = puVar13;
              if (puVar21 != (uint *)0x0) {
                puVar21[2] = (uint)puVar13;
                puVar19 = puStack_38;
              }
            }
            iVar10 = (*zb_core_action_cb)(0x1001,auStack_58,zb_core_action_cb);
            puVar13 = puStack_38;
            while (puVar13 != (uint *)0x0) {
              puVar19 = (uint *)puVar13[2];
              free(puVar13);
              puVar13 = puVar19;
            }
          }
          goto _L0;
        }
        if (bVar5 < 5) {
          if (bVar5 == 0) {
            if (*(short *)(iVar7 + 0xf) == 0x15) {
              esp_zcl_commissioning_sync_with_attributes();
            }
          }
          else if (bVar5 == 1) {
            if (*(short *)(iVar7 + 0xf) == 10) {
              iVar14 = zb_zcl_time_server_read_attr_handle(param_1);
              iVar10 = 0;
              if (iVar14 != 0) goto _L0;
            }
            puStack_38 = (uint *)0x0;
            iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
            if (iVar10 == 0) {
              puVar13 = (uint *)0x0;
              puVar19 = puStack_38;
              while ((puStack_38 = puVar19, puVar21 = puVar13, uVar22 = zb_buf_len_func(param_1),
                     2 < uVar22 &&
                     (puVar11 = (undefined2 *)zb_buf_begin_func(param_1),
                     puVar11 != (undefined2 *)0x0))) {
                uVar22 = 3;
                iVar10 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar11 + 1));
                *(char *)(puVar11 + 1) = (char)iVar10;
                if (iVar10 == 0) {
                  iVar10 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar11 + 3),puVar11 + 2);
                  uVar22 = iVar10 + 4U & 0xffff;
                  zb_buf_len_func(param_1);
                }
                uVar12 = zb_buf_len_func(param_1);
                if (uVar12 < uVar22) break;
                zb_buf_cut_left_func(param_1,uVar22);
                puVar13 = (uint *)malloc(0x14);
                uVar22 = (uint)*(byte *)(puVar11 + 1);
                *(undefined2 *)(puVar13 + 1) = *puVar11;
                *puVar13 = uVar22;
                uVar16 = 0;
                if (uVar22 == 0) {
                  uVar16 = (ushort)*(byte *)((int)puVar11 + 3);
                }
                *(ushort *)((int)puVar13 + 6) = uVar16;
                *(undefined2 *)(puVar13 + 2) = 0;
                uVar6 = 0;
                if (uVar22 == 0) {
                  uVar6 = esp_zb_zcl_get_attribute_size
                                    (*(undefined1 *)((int)puVar11 + 3),puVar11 + 2);
                }
                *(undefined2 *)((int)puVar13 + 10) = uVar6;
                puVar17 = (undefined2 *)0x0;
                if (*(char *)(puVar11 + 1) == '\0') {
                  puVar17 = puVar11 + 2;
                }
                puVar13[3] = (uint)puVar17;
                puVar13[4] = 0;
                puVar19 = puVar13;
                if (puVar21 != (uint *)0x0) {
                  puVar21[4] = (uint)puVar13;
                  puVar19 = puStack_38;
                }
              }
              iVar10 = (*zb_core_action_cb)(0x1000,auStack_58,zb_core_action_cb);
              puVar13 = puStack_38;
              while (puVar13 != (uint *)0x0) {
                puVar19 = (uint *)puVar13[4];
                free(puVar13);
                puVar13 = puVar19;
              }
            }
            goto _L0;
          }
        }
        else if (bVar5 == 7) {
          puStack_38 = (uint *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
          if (iVar10 == 0) {
            puVar13 = (uint *)0x0;
            puVar19 = puStack_38;
            while ((puStack_38 = puVar19, puVar21 = puVar13, iVar10 = zb_buf_len_func(param_1),
                   iVar10 != 0 &&
                   (pbVar9 = (byte *)zb_buf_begin_func(param_1), pbVar9 != (byte *)0x0))) {
              bVar5 = zb_zcl_zcl8_statuses_conversion(*pbVar9);
              *pbVar9 = bVar5;
              uVar22 = 1;
              if ((bVar5 & 0x7f) != 0) {
                zb_buf_len_func(param_1);
                uVar22 = 4;
              }
              uVar12 = zb_buf_len_func(param_1);
              if (uVar12 < uVar22) break;
              zb_buf_cut_left_func(param_1);
              puVar13 = (uint *)malloc(0xc);
              uVar22 = (uint)*pbVar9;
              *puVar13 = uVar22;
              uVar6 = 0xffff;
              if (uVar22 != 0) {
                uVar6 = *(undefined2 *)(pbVar9 + 2);
              }
              *(undefined2 *)((int)puVar13 + 6) = uVar6;
              bVar5 = 0xff;
              if (uVar22 != 0) {
                bVar5 = pbVar9[1];
              }
              *(byte *)(puVar13 + 1) = bVar5;
              puVar13[2] = 0;
              puVar19 = puVar13;
              if (puVar21 != (uint *)0x0) {
                puVar21[2] = (uint)puVar13;
                puVar19 = puStack_38;
              }
            }
            iVar10 = (*zb_core_action_cb)(0x1002,auStack_58,zb_core_action_cb);
            puVar13 = puStack_38;
            while (puVar13 != (uint *)0x0) {
              puVar19 = (uint *)puVar13[2];
              free(puVar13);
              puVar13 = puVar19;
            }
          }
          goto _L0;
        }
      }
      else if (bVar5 == 0xb) {
        if ((*(short *)(iVar7 + 0xf) != 0x19) && (*(short *)(iVar7 + 0xf) != -0x400)) {
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
          if (iVar10 == 0) {
            uVar22 = zb_buf_len_func(param_1);
            if (uVar22 < 2) {
              auStack_58[0] = 1;
              puStack_38 = (uint *)CONCAT31(puStack_38._1_3_,0xff);
              puStack_34 = (undefined2 *)0x1;
            }
            else {
              auStack_58[0] = 0;
              puVar15 = (undefined1 *)zb_buf_begin_func(param_1);
              puStack_38 = (uint *)CONCAT31(puStack_38._1_3_,*puVar15);
              iVar10 = zb_buf_begin_func(param_1);
              puStack_34 = (undefined2 *)(uint)*(byte *)(iVar10 + 1);
            }
            iVar10 = (*zb_core_action_cb)(0x1005,auStack_58,zb_core_action_cb);
          }
          goto _L0;
        }
      }
      else {
        if (bVar5 < 0xc) {
          zb_zcl_report_attr_cmd_handler(param_1);
          return 1;
        }
        if (bVar5 == 0xd) {
          puStack_38 = (uint *)((uint)puStack_38 & 0xffffff00);
          puStack_34 = (undefined2 *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_58);
          if (iVar10 == 0) {
            iVar10 = zb_buf_len_func(param_1);
            if (iVar10 == 0) {
              puStack_38 = (uint *)((uint)puStack_38 & 0xffffff00);
            }
            else {
              puVar15 = (undefined1 *)zb_buf_begin_func(param_1);
              puStack_38 = (uint *)CONCAT31(puStack_38._1_3_,*puVar15);
              zb_buf_cut_left_func(param_1,1);
            }
            puVar11 = (undefined2 *)0x0;
            puVar17 = puStack_34;
            while ((puStack_34 = puVar17, puVar20 = puVar11, uVar22 = zb_buf_len_func(param_1),
                   2 < uVar22 &&
                   (puVar17 = (undefined2 *)zb_buf_begin_func(param_1), puVar17 != (undefined2 *)0x0
                   ))) {
              zb_buf_cut_left_func(param_1,3);
              puVar11 = (undefined2 *)malloc(0xc);
              if (puVar11 == (undefined2 *)0x0) {
                iVar10 = 0x101;
                goto _L0;
              }
              *puVar11 = *puVar17;
              bVar5 = *(byte *)(puVar17 + 1);
              *(undefined4 *)(puVar11 + 4) = 0;
              *(uint *)(puVar11 + 2) = (uint)bVar5;
              puVar17 = puVar11;
              if (puVar20 != (undefined2 *)0x0) {
                *(undefined2 **)(puVar20 + 4) = puVar11;
                puVar17 = puStack_34;
              }
            }
            iVar10 = (*zb_core_action_cb)(0x1004,auStack_58,zb_core_action_cb);
            puVar11 = puStack_34;
            while (puVar11 != (undefined2 *)0x0) {
              puVar17 = *(undefined2 **)(puVar11 + 4);
              free(puVar11);
              puVar11 = puVar17;
            }
          }
          goto _L0;
        }
        if ((bVar5 != 0xc) && ((bVar5 == 0x14 || ((bVar5 & 0xfb) == 0x12)))) {
          uVar8 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC3,uVar8,"ESP_ZIGBEE_CORE",
                        *(undefined1 *)(iVar7 + 0x13));
        }
      }
    }
  }
_L0:
  if (zcl_raw_command_cb == (code *)0x0) {
    return 0;
  }
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22);
  if ((*(short *)(iVar7 + 4) != sVar2) ||
     (iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22), UNRECOVERED_JUMPTABLE = zcl_raw_command_cb,
     *(short *)(iVar7 + 6) != sVar3)) {
    iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22);
    *(char *)(iVar7 + 4) = (char)sVar2;
    *(char *)(iVar7 + 5) = (char)((ushort)sVar2 >> 8);
    iVar7 = zb_bufpool_storage_bufid_to_buf(uVar22);
    *(char *)(iVar7 + 6) = (char)sVar3;
    *(char *)(iVar7 + 7) = (char)((ushort)sVar3 >> 8);
    UNRECOVERED_JUMPTABLE = zcl_raw_command_cb;
  }
_L0:
                    /* WARNING: Could not recover jumptable at 0x00010b38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar8 = (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return uVar8;
}

