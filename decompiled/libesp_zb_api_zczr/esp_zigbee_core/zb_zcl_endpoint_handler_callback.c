/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
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
  uint *puVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint *puVar13;
  byte *pbVar14;
  int iVar15;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 *puVar16;
  int *piVar17;
  uint *puVar18;
  undefined2 *puVar19;
  uint uVar20;
  bool bVar21;
  uint auStack_5c [8];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uVar20 = param_1 - 1U & 0xff;
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20);
  sVar1 = *(short *)(iVar7 + 4);
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20);
  sVar2 = *(short *)(iVar7 + 6);
  UNRECOVERED_JUMPTABLE = zcl_cli_resp_user_cb;
  if (zcl_cli_resp_user_cb != (code *)0x0) goto _L0;
  iVar7 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar7 + 0x16) == '\0') {
    iVar7 = zb_buf_get_tail_func(param_1,0x1b);
    sVar3 = *(short *)(iVar7 + 0xf);
    piVar17 = s_endpoint_handler_list;
    if (sVar3 < 0) {
      sVar3 = -0x8000;
    }
    for (; piVar17 + -2 != (int *)0xfffffff8; piVar17 = (int *)*piVar17) {
      if (*(short *)(piVar17 + -2) == sVar3) {
        iVar7 = (*(code *)piVar17[-1])(param_1,(code *)piVar17[-1]);
        goto _L0;
      }
    }
    iVar7 = 0;
_L0:
    if (-1 < sVar3) {
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
    if (((iVar7 != 0) && (*(char *)(iVar7 + 0x14) == '\x01')) && (zb_core_action_cb != (code *)0x0))
    {
      bVar5 = *(byte *)(iVar7 + 0x13);
      bVar21 = true;
      if (bVar5 == 9) {
        iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar10 != 0) goto _L0;
        iVar10 = 0;
        while ((uVar20 = zb_buf_len_func(param_1), 4 < uVar20 &&
               (pbVar14 = (byte *)zb_buf_begin_func(param_1), pbVar14 != (byte *)0x0))) {
          uVar20 = 6;
          if (pbVar14[1] == 0) {
            iVar15 = zb_zcl_is_analog_data_type(pbVar14[4]);
            uVar20 = iVar15 + 9U & 0xffff;
          }
          uVar12 = zb_buf_len_func(param_1);
          if (uVar12 < uVar20) break;
          bVar5 = zb_zcl_zcl8_statuses_conversion(*pbVar14);
          *pbVar14 = bVar5;
          if ((bVar5 & 0x7f) != 0) {
            zb_buf_len_func(param_1);
            uVar20 = 4;
          }
          uVar12 = zb_buf_len_func(param_1);
          if (uVar12 < uVar20) goto _L0;
          zb_buf_cut_left_func(param_1,uVar20);
          auStack_5c[0] = (uint)*pbVar14;
          uStack_3c = (uint *)CONCAT22(*(undefined2 *)(pbVar14 + 2),(undefined2)uStack_3c);
          uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,pbVar14[1]);
          if (auStack_5c[0] == 0) {
            if (pbVar14[1] == 0) {
              uStack_38 = (undefined2 *)CONCAT31(uStack_38._1_3_,pbVar14[4]);
              uStack_38 = (undefined2 *)CONCAT22(*(undefined2 *)(pbVar14 + 5),(undefined2)uStack_38)
              ;
              uStack_34 = CONCAT13(uStack_34._3_1_,*(undefined3 *)(pbVar14 + 7));
            }
            else {
              uStack_38 = (undefined2 *)CONCAT22(uStack_38._2_2_,*(undefined2 *)(pbVar14 + 4));
            }
          }
          else {
            uStack_38 = (undefined2 *)0x0;
            uStack_34 = 0;
          }
          iVar10 = (*zb_core_action_cb)(0x1003,auStack_5c,zb_core_action_cb);
        }
        zb_buf_len_func(param_1);
        zb_buf_cut_left_func(param_1,0);
      }
      else if (bVar5 < 10) {
        if (bVar5 == 4) {
          uStack_3c = (uint *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
          if (iVar10 != 0) goto _L0;
          puVar13 = (uint *)0x0;
          puVar18 = uStack_3c;
          while ((uStack_3c = puVar18, puVar4 = puVar13, iVar10 = zb_buf_len_func(param_1),
                 iVar10 != 0 &&
                 (pbVar14 = (byte *)zb_buf_begin_func(param_1), pbVar14 != (byte *)0x0))) {
            iVar10 = zb_zcl_zcl8_statuses_conversion(*pbVar14);
            *pbVar14 = (byte)iVar10;
            uVar20 = 1;
            if (iVar10 != 0) {
              zb_buf_len_func(param_1);
              uVar20 = 3;
            }
            uVar12 = zb_buf_len_func(param_1);
            if (uVar12 < uVar20) break;
            zb_buf_cut_left_func(param_1);
            puVar13 = (uint *)malloc(0xc);
            bVar5 = *pbVar14;
            *puVar13 = (uint)bVar5;
            uVar6 = 0xffff;
            if (bVar5 != 0) {
              uVar6 = *(undefined2 *)(pbVar14 + 1);
            }
            *(undefined2 *)(puVar13 + 1) = uVar6;
            puVar13[2] = 0;
            puVar18 = puVar13;
            if (puVar4 != (uint *)0x0) {
              puVar4[2] = (uint)puVar13;
              puVar18 = uStack_3c;
            }
          }
          iVar10 = (*zb_core_action_cb)(0x1001,auStack_5c,zb_core_action_cb);
          puVar13 = uStack_3c;
          while (puVar13 != (uint *)0x0) {
            puVar18 = (uint *)puVar13[2];
            free(puVar13);
            puVar13 = puVar18;
          }
        }
        else if (bVar5 == 7) {
          uStack_3c = (uint *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
          puVar13 = (uint *)0x0;
          puVar18 = uStack_3c;
          if (iVar10 != 0) goto _L0;
          while ((uStack_3c = puVar18, puVar4 = puVar13, iVar10 = zb_buf_len_func(param_1),
                 iVar10 != 0 &&
                 (pbVar14 = (byte *)zb_buf_begin_func(param_1), pbVar14 != (byte *)0x0))) {
            bVar5 = zb_zcl_zcl8_statuses_conversion(*pbVar14);
            *pbVar14 = bVar5;
            uVar20 = 1;
            if ((bVar5 & 0x7f) != 0) {
              zb_buf_len_func(param_1);
              uVar20 = 4;
            }
            uVar12 = zb_buf_len_func(param_1);
            if (uVar12 < uVar20) break;
            zb_buf_cut_left_func(param_1);
            puVar13 = (uint *)malloc(0xc);
            bVar5 = *pbVar14;
            *puVar13 = (uint)bVar5;
            if (bVar5 == 0) {
              *(undefined2 *)((int)puVar13 + 6) = 0xffff;
              bVar5 = 0xff;
            }
            else {
              *(undefined2 *)((int)puVar13 + 6) = *(undefined2 *)(pbVar14 + 2);
              bVar5 = pbVar14[1];
            }
            *(byte *)(puVar13 + 1) = bVar5;
            puVar13[2] = 0;
            puVar18 = puVar13;
            if (puVar4 != (uint *)0x0) {
              puVar4[2] = (uint)puVar13;
              puVar18 = uStack_3c;
            }
          }
          iVar10 = (*zb_core_action_cb)(0x1002,auStack_5c,zb_core_action_cb);
          puVar13 = uStack_3c;
          while (puVar13 != (uint *)0x0) {
            puVar18 = (uint *)puVar13[2];
            free(puVar13);
            puVar13 = puVar18;
          }
        }
        else {
          if (bVar5 != 1) goto _L0;
          if ((*(short *)(iVar7 + 0xf) == 10) &&
             (iVar10 = zb_zcl_time_server_read_attr_handle(param_1), iVar10 != 0)) {
            bVar21 = false;
            goto _L0;
          }
          uStack_3c = (uint *)0x0;
          iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
          if (iVar10 != 0) goto _L0;
          puVar13 = (uint *)0x0;
          puVar18 = uStack_3c;
          while ((uStack_3c = puVar18, puVar4 = puVar13, uVar20 = zb_buf_len_func(param_1),
                 2 < uVar20 &&
                 (puVar11 = (undefined2 *)zb_buf_begin_func(param_1), puVar11 != (undefined2 *)0x0))
                ) {
            uVar20 = 3;
            iVar10 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar11 + 1));
            *(char *)(puVar11 + 1) = (char)iVar10;
            if (iVar10 == 0) {
              iVar10 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar11 + 3),puVar11 + 2);
              uVar20 = iVar10 + 4U & 0xffff;
              zb_buf_len_func(param_1);
            }
            uVar12 = zb_buf_len_func(param_1);
            if (uVar12 < uVar20) break;
            zb_buf_cut_left_func(param_1,uVar20);
            puVar13 = (uint *)malloc(0x14);
            uVar6 = *puVar11;
            bVar5 = *(byte *)(puVar11 + 1);
            *puVar13 = (uint)bVar5;
            *(undefined2 *)(puVar13 + 1) = uVar6;
            if (bVar5 == 0) {
              bVar5 = *(byte *)((int)puVar11 + 3);
              *(undefined2 *)(puVar13 + 2) = 0;
              *(ushort *)((int)puVar13 + 6) = (ushort)bVar5;
              uVar6 = esp_zb_zcl_get_attribute_size(puVar11 + 2);
            }
            else {
              *(undefined2 *)((int)puVar13 + 6) = 0;
              *(undefined2 *)(puVar13 + 2) = 0;
              uVar6 = 0;
            }
            *(undefined2 *)((int)puVar13 + 10) = uVar6;
            puVar16 = (undefined2 *)0x0;
            if (*(char *)(puVar11 + 1) == '\0') {
              puVar16 = puVar11 + 2;
            }
            puVar13[3] = (uint)puVar16;
            puVar13[4] = 0;
            puVar18 = puVar13;
            if (puVar4 != (uint *)0x0) {
              puVar4[4] = (uint)puVar13;
              puVar18 = uStack_3c;
            }
          }
          iVar10 = (*zb_core_action_cb)(0x1000,auStack_5c,zb_core_action_cb);
          puVar13 = uStack_3c;
          while (puVar13 != (uint *)0x0) {
            puVar18 = (uint *)puVar13[4];
            free(puVar13);
            puVar13 = puVar18;
          }
        }
      }
      else {
        if (bVar5 != 0xd) {
          if (bVar5 < 0xe) {
            if (((bVar5 == 0xb) && (*(short *)(iVar7 + 0xf) != 0x19)) &&
               (*(short *)(iVar7 + 0xf) != -0x400)) {
              iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
              if (iVar10 != 0) goto _L0;
              uVar20 = zb_buf_len_func(param_1);
              if (uVar20 < 2) {
                auStack_5c[0] = 1;
                uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,0xff);
                uStack_38 = (undefined2 *)0x1;
              }
              else {
                auStack_5c[0] = 0;
                puVar9 = (undefined1 *)zb_buf_begin_func(param_1);
                uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar9);
                iVar10 = zb_buf_begin_func(param_1);
                uStack_38 = (undefined2 *)(uint)*(byte *)(iVar10 + 1);
              }
              iVar10 = (*zb_core_action_cb)(0x1005,auStack_5c,zb_core_action_cb);
              goto _L0;
            }
          }
          else if ((bVar5 == 0x14) || ((bVar5 & 0xfb) == 0x12)) {
            uVar8 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar8,"ESP_ZIGBEE_CORE",
                          *(undefined1 *)(iVar7 + 0x13));
          }
          goto _L0;
        }
        uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
        uStack_38 = (undefined2 *)0x0;
        iVar10 = zb_zcl_basic_message_create(param_1,auStack_5c);
        if (iVar10 != 0) goto _L0;
        iVar10 = zb_buf_len_func(param_1);
        if (iVar10 == 0) {
          uStack_3c = (uint *)((uint)uStack_3c & 0xffffff00);
        }
        else {
          puVar9 = (undefined1 *)zb_buf_begin_func(param_1);
          uStack_3c = (uint *)CONCAT31(uStack_3c._1_3_,*puVar9);
          zb_buf_cut_left_func(param_1,1);
        }
        puVar11 = (undefined2 *)0x0;
        puVar16 = uStack_38;
        while ((uStack_38 = puVar16, puVar19 = puVar11, uVar20 = zb_buf_len_func(param_1),
               2 < uVar20 &&
               (puVar16 = (undefined2 *)zb_buf_begin_func(param_1), puVar16 != (undefined2 *)0x0)))
        {
          zb_buf_cut_left_func(param_1,3);
          puVar11 = (undefined2 *)malloc(0xc);
          if (puVar11 == (undefined2 *)0x0) {
            iVar10 = 0x101;
            goto _L0;
          }
          *puVar11 = *puVar16;
          bVar5 = *(byte *)(puVar16 + 1);
          *(undefined4 *)(puVar11 + 4) = 0;
          *(uint *)(puVar11 + 2) = (uint)bVar5;
          puVar16 = puVar11;
          if (puVar19 != (undefined2 *)0x0) {
            *(undefined2 **)(puVar19 + 4) = puVar11;
            puVar16 = uStack_38;
          }
        }
        iVar10 = (*zb_core_action_cb)(0x1004,auStack_5c,zb_core_action_cb);
        puVar11 = uStack_38;
        while (puVar11 != (undefined2 *)0x0) {
          puVar16 = *(undefined2 **)(puVar11 + 4);
          free(puVar11);
          puVar11 = puVar16;
        }
      }
_L0:
      bVar21 = iVar10 != 0;
_L0:
      zb_zcl_send_default_handler(param_1,iVar7,bVar21);
      return 1;
    }
  }
_L0:
  if (zcl_raw_command_cb == (code *)0x0) {
    return 0;
  }
  iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20);
  if ((*(short *)(iVar7 + 4) != sVar1) ||
     (iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20), UNRECOVERED_JUMPTABLE = zcl_raw_command_cb,
     *(short *)(iVar7 + 6) != sVar2)) {
    iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20);
    *(char *)(iVar7 + 4) = (char)sVar1;
    *(char *)(iVar7 + 5) = (char)((ushort)sVar1 >> 8);
    iVar7 = zb_bufpool_storage_bufid_to_buf(uVar20);
    *(char *)(iVar7 + 6) = (char)sVar2;
    *(char *)(iVar7 + 7) = (char)((ushort)sVar2 >> 8);
    UNRECOVERED_JUMPTABLE = zcl_raw_command_cb;
  }
_L0:
                    /* WARNING: Could not recover jumptable at 0x00010a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar8 = (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return uVar8;
}

