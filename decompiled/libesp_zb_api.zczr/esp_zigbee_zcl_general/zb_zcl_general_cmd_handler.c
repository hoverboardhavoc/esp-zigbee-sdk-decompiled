/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_general.o -> zb_zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_general_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined2 *puVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  uint *puVar15;
  uint *puVar16;
  undefined2 *puVar17;
  undefined4 auStack_48 [8];
  uint *puStack_28;
  undefined2 *puStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x1b);
  if (iVar4 == 0) {
    return 0;
  }
  bVar2 = *(byte *)(iVar4 + 0x13);
  if (bVar2 == 9) {
    puStack_28 = (uint *)0x0;
    iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar7 == 0) {
      puVar11 = (uint *)0x0;
      puVar16 = puStack_28;
      while( true ) {
        puStack_28 = puVar16;
        puVar15 = puVar11;
        uVar8 = zb_buf_len_func(param_1);
        if ((uVar8 < 4) || (pbVar5 = (byte *)zb_buf_begin_func(param_1), pbVar5 == (byte *)0x0)) {
          pbVar5 = (byte *)0x0;
          uVar8 = 0;
        }
        else {
          uVar8 = 6;
          if (pbVar5[1] == 0) {
            iVar7 = zb_zcl_is_analog_data_type(pbVar5[4]);
            uVar8 = iVar7 + 9U & 0xffff;
          }
          bVar2 = zb_zcl_zcl8_statuses_conversion(*pbVar5);
          *pbVar5 = bVar2;
          if ((bVar2 & 0x7f) != 0) {
            uVar8 = 4;
          }
        }
        uVar10 = zb_buf_len_func(param_1);
        if ((uVar10 < uVar8) || (zb_buf_cut_left_func(param_1,uVar8), pbVar5 == (byte *)0x0)) break;
        puVar11 = (uint *)malloc(0x14);
        bVar2 = *pbVar5;
        *puVar11 = (uint)bVar2;
        *(undefined2 *)((int)puVar11 + 6) = *(undefined2 *)(pbVar5 + 2);
        bVar1 = pbVar5[1];
        *(byte *)(puVar11 + 1) = bVar1;
        if (bVar2 == 0) {
          if (bVar1 == 0) {
            *(byte *)(puVar11 + 2) = pbVar5[4];
            *(undefined2 *)((int)puVar11 + 10) = *(undefined2 *)(pbVar5 + 5);
            *(undefined2 *)(puVar11 + 3) = *(undefined2 *)(pbVar5 + 7);
            *(byte *)((int)puVar11 + 0xe) = pbVar5[9];
          }
          else {
            *(undefined2 *)(puVar11 + 2) = *(undefined2 *)(pbVar5 + 4);
          }
        }
        else {
          puVar11[2] = 0;
          puVar11[3] = 0;
        }
        puVar11[4] = 0;
        puVar16 = puVar11;
        if (puVar15 != (uint *)0x0) {
          puVar15[4] = (uint)puVar11;
          puVar16 = puStack_28;
        }
      }
      esp_zb_core_action_handler_schedule(0x1003,auStack_48);
      iVar7 = esp_err_to_zb_ret();
      puVar11 = puStack_28;
      while (puVar11 != (uint *)0x0) {
        puVar16 = (uint *)puVar11[4];
        free(puVar11);
        puVar11 = puVar16;
      }
    }
  }
  else if (bVar2 < 10) {
    if (bVar2 == 4) {
      puStack_28 = (uint *)0x0;
      iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar7 == 0) {
        puVar11 = (uint *)0x0;
        puVar16 = puStack_28;
        while ((puStack_28 = puVar16, puVar15 = puVar11, iVar7 = zb_buf_len_func(param_1),
               iVar7 != 0 && (pbVar5 = (byte *)zb_buf_begin_func(param_1), pbVar5 != (byte *)0x0)))
        {
          iVar7 = zb_zcl_zcl8_statuses_conversion(*pbVar5);
          *pbVar5 = (byte)iVar7;
          uVar8 = 1;
          if (iVar7 != 0) {
            zb_buf_len_func(param_1);
            uVar8 = 3;
          }
          uVar10 = zb_buf_len_func(param_1);
          if (uVar10 < uVar8) break;
          zb_buf_cut_left_func(param_1);
          puVar11 = (uint *)malloc(0xc);
          bVar2 = *pbVar5;
          *puVar11 = (uint)bVar2;
          uVar3 = 0xffff;
          if (bVar2 != 0) {
            uVar3 = *(undefined2 *)(pbVar5 + 1);
          }
          *(undefined2 *)(puVar11 + 1) = uVar3;
          puVar11[2] = 0;
          puVar16 = puVar11;
          if (puVar15 != (uint *)0x0) {
            puVar15[2] = (uint)puVar11;
            puVar16 = puStack_28;
          }
        }
        esp_zb_core_action_handler_schedule(0x1001,auStack_48);
        iVar7 = esp_err_to_zb_ret();
        puVar11 = puStack_28;
        while (puVar11 != (uint *)0x0) {
          puVar16 = (uint *)puVar11[2];
          free(puVar11);
          puVar11 = puVar16;
        }
      }
    }
    else if (bVar2 < 5) {
      if (bVar2 == 0) {
        if (*(short *)(iVar4 + 0xf) == 0x15) {
          esp_zcl_commissioning_sync_with_attributes();
        }
        return 0;
      }
      if (bVar2 != 1) {
        return 0;
      }
      if (*(short *)(iVar4 + 0xf) == 10) {
        iVar12 = zb_zcl_time_server_read_attr_handle(param_1);
        iVar7 = 0;
        if (iVar12 != 0) goto _L0;
      }
      puStack_28 = (uint *)0x0;
      iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar7 == 0) {
        puVar11 = (uint *)0x0;
        puVar16 = puStack_28;
        while ((puStack_28 = puVar16, puVar15 = puVar11, uVar8 = zb_buf_len_func(param_1), 2 < uVar8
               && (puVar9 = (undefined2 *)zb_buf_begin_func(param_1), puVar9 != (undefined2 *)0x0)))
        {
          uVar8 = 3;
          iVar7 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar9 + 1));
          *(char *)(puVar9 + 1) = (char)iVar7;
          if (iVar7 == 0) {
            iVar7 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar9 + 3),puVar9 + 2);
            uVar8 = iVar7 + 4U & 0xffff;
            zb_buf_len_func(param_1);
          }
          uVar10 = zb_buf_len_func(param_1);
          if (uVar10 < uVar8) break;
          zb_buf_cut_left_func(param_1,uVar8);
          puVar11 = (uint *)malloc(0x14);
          uVar3 = *puVar9;
          bVar2 = *(byte *)(puVar9 + 1);
          *puVar11 = (uint)bVar2;
          *(undefined2 *)(puVar11 + 1) = uVar3;
          if (bVar2 == 0) {
            bVar2 = *(byte *)((int)puVar9 + 3);
            *(undefined2 *)(puVar11 + 2) = 0;
            *(ushort *)((int)puVar11 + 6) = (ushort)bVar2;
            uVar3 = esp_zb_zcl_get_attribute_size(puVar9 + 2);
          }
          else {
            *(undefined2 *)((int)puVar11 + 6) = 0;
            *(undefined2 *)(puVar11 + 2) = 0;
            uVar3 = 0;
          }
          *(undefined2 *)((int)puVar11 + 10) = uVar3;
          puVar14 = (undefined2 *)0x0;
          if (*(char *)(puVar9 + 1) == '\0') {
            puVar14 = puVar9 + 2;
          }
          puVar11[3] = (uint)puVar14;
          puVar11[4] = 0;
          puVar16 = puVar11;
          if (puVar15 != (uint *)0x0) {
            puVar15[4] = (uint)puVar11;
            puVar16 = puStack_28;
          }
        }
        esp_zb_core_action_handler_schedule(0x1000,auStack_48);
        iVar7 = esp_err_to_zb_ret();
        puVar11 = puStack_28;
        while (puVar11 != (uint *)0x0) {
          puVar16 = (uint *)puVar11[4];
          free(puVar11);
          puVar11 = puVar16;
        }
      }
    }
    else {
      if (bVar2 != 7) {
        return 0;
      }
      puStack_28 = (uint *)0x0;
      iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar7 == 0) {
        puVar11 = (uint *)0x0;
        puVar16 = puStack_28;
        while ((puStack_28 = puVar16, puVar15 = puVar11, iVar7 = zb_buf_len_func(param_1),
               iVar7 != 0 && (pbVar5 = (byte *)zb_buf_begin_func(param_1), pbVar5 != (byte *)0x0)))
        {
          bVar2 = zb_zcl_zcl8_statuses_conversion(*pbVar5);
          *pbVar5 = bVar2;
          uVar8 = 1;
          if ((bVar2 & 0x7f) != 0) {
            zb_buf_len_func(param_1);
            uVar8 = 4;
          }
          uVar10 = zb_buf_len_func(param_1);
          if (uVar10 < uVar8) break;
          zb_buf_cut_left_func(param_1);
          puVar11 = (uint *)malloc(0xc);
          bVar2 = *pbVar5;
          *puVar11 = (uint)bVar2;
          if (bVar2 == 0) {
            *(undefined2 *)((int)puVar11 + 6) = 0xffff;
            bVar2 = 0xff;
          }
          else {
            *(undefined2 *)((int)puVar11 + 6) = *(undefined2 *)(pbVar5 + 2);
            bVar2 = pbVar5[1];
          }
          *(byte *)(puVar11 + 1) = bVar2;
          puVar11[2] = 0;
          puVar16 = puVar11;
          if (puVar15 != (uint *)0x0) {
            puVar15[2] = (uint)puVar11;
            puVar16 = puStack_28;
          }
        }
        esp_zb_core_action_handler_schedule(0x1002,auStack_48);
        iVar7 = esp_err_to_zb_ret();
        puVar11 = puStack_28;
        while (puVar11 != (uint *)0x0) {
          puVar16 = (uint *)puVar11[2];
          free(puVar11);
          puVar11 = puVar16;
        }
      }
    }
  }
  else if (bVar2 == 0xb) {
    if (*(short *)(iVar4 + 0xf) == 0x19) {
      return 0;
    }
    if (*(short *)(iVar4 + 0xf) == -0x400) {
      return 0;
    }
    iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar7 == 0) {
      uVar8 = zb_buf_len_func(param_1);
      puStack_24 = (undefined2 *)0x1;
      if (uVar8 < 2) {
        auStack_48[0] = 1;
        puStack_28 = (uint *)CONCAT31(puStack_28._1_3_,0xff);
      }
      else {
        auStack_48[0] = 0;
        puVar13 = (undefined1 *)zb_buf_begin_func(param_1);
        puStack_28 = (uint *)CONCAT31(puStack_28._1_3_,*puVar13);
        iVar7 = zb_buf_begin_func(param_1);
        puStack_24 = (undefined2 *)(uint)*(byte *)(iVar7 + 1);
      }
      esp_zb_core_action_handler_schedule(0x1005,auStack_48);
      iVar7 = esp_err_to_zb_ret();
    }
  }
  else {
    if (bVar2 < 0xc) {
      zb_zcl_report_attr_cmd_handler(param_1);
      return 1;
    }
    if (bVar2 != 0xd) {
      if (bVar2 == 0xc) {
        return 0;
      }
      if ((bVar2 != 0x14) && ((bVar2 & 0xfb) != 0x12)) {
        return 0;
      }
      uVar6 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Unsupported ZCL common command(0x%x)\n",uVar6,0x10000,
              *(undefined1 *)(iVar4 + 0x13));
      return 0;
    }
    puStack_28 = (uint *)((uint)puStack_28 & 0xffffff00);
    puStack_24 = (undefined2 *)0x0;
    iVar7 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar7 == 0) {
      iVar7 = zb_buf_len_func(param_1);
      if (iVar7 == 0) {
        puStack_28 = (uint *)((uint)puStack_28 & 0xffffff00);
      }
      else {
        puVar13 = (undefined1 *)zb_buf_begin_func(param_1);
        puStack_28 = (uint *)CONCAT31(puStack_28._1_3_,*puVar13);
        zb_buf_cut_left_func(param_1,1);
      }
      puVar9 = (undefined2 *)0x0;
      puVar14 = puStack_24;
      while ((puStack_24 = puVar14, puVar17 = puVar9, uVar8 = zb_buf_len_func(param_1), 2 < uVar8 &&
             (puVar14 = (undefined2 *)zb_buf_begin_func(param_1), puVar14 != (undefined2 *)0x0))) {
        zb_buf_cut_left_func(param_1,3);
        puVar9 = (undefined2 *)malloc(0xc);
        if (puVar9 == (undefined2 *)0x0) {
          iVar7 = 0x101;
          goto _L0;
        }
        *puVar9 = *puVar14;
        bVar2 = *(byte *)(puVar14 + 1);
        *(undefined4 *)(puVar9 + 4) = 0;
        *(uint *)(puVar9 + 2) = (uint)bVar2;
        puVar14 = puVar9;
        if (puVar17 != (undefined2 *)0x0) {
          *(undefined2 **)(puVar17 + 4) = puVar9;
          puVar14 = puStack_24;
        }
      }
      esp_zb_core_action_handler_schedule(0x1004,auStack_48);
      iVar7 = esp_err_to_zb_ret();
      puVar9 = puStack_24;
      while (puVar9 != (undefined2 *)0x0) {
        puVar14 = *(undefined2 **)(puVar9 + 4);
        free(puVar9);
        puVar9 = puVar14;
      }
    }
  }
_L0:
  zb_zcl_send_default_handler(param_1,iVar4,iVar7 != 0);
  return 1;
}

