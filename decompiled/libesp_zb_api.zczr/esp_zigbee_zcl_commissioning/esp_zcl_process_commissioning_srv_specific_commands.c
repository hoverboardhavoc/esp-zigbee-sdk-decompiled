/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_srv_specific_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zcl_process_commissioning_srv_specific_commands(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined3 *puVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [23];
  byte bStack_29;
  ushort uStack_28;
  byte bStack_24;
  char cStack_23;
  
  if (param_1 == 0xff) {
    iVar5 = zb_zcl_get_ctx();
    *(undefined1 **)(iVar5 + 0x2e0) = s_commissioning_server_cmd_list;
    return 1;
  }
  iVar5 = zb_zcl_basic_message_create(auStack_40);
  if (iVar5 != 0) {
    return 1;
  }
  if (uStack_28 != 0x15) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
              ,0x24b);
  }
  if (cStack_23 != '\0') {
    return 0;
  }
  if (bStack_24 == 2) {
    uStack_50 = (uint)uStack_28 << 0x10;
    uStack_44 = 0x81;
    uStack_54 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_50 = CONCAT31(uStack_50._1_3_,bStack_29);
    iVar5 = zb_buf_begin_func(param_1);
    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(iVar5 + 1));
    uStack_4c = 1;
  }
  else {
    if (2 < bStack_24) {
      if (bStack_24 != 3) {
        return 0;
      }
      uStack_54 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_50 = CONCAT22(uStack_28,(ushort)bStack_29);
      pbVar8 = (byte *)zb_buf_begin_func(param_1);
      bVar1 = *pbVar8;
      bVar2 = pbVar8[1];
      if ((bVar1 & 1) != 0) {
        uVar3 = esp_zb_get_short_address();
        uVar4 = esp_zb_get_pan_id();
        DAT_00010dac = zb_get_channel_mask();
        _DAT_00010da2 = 0xffff;
        _DAT_00010da4 = 0xffffffff;
        _DAT_00010da8 = 0xffff;
        _g_comm_ctx = uVar3;
        DAT_00010daa = uVar4;
        memset(&DAT_00010db0,0,0x40);
        DAT_00010db0 = 0x30202;
        DAT_00010ddb = 1;
        DAT_00010ded = 1;
      }
      if ((bVar1 & 2) == 0) {
        if ((bVar1 & 1) == 0) {
          uStack_4c = ((bVar1 & 4) == 0) + 2;
          uStack_48 = CONCAT31(uStack_48._1_3_,bVar2);
        }
      }
      else {
        uStack_4c = 4;
      }
      esp_zb_core_action_handler_schedule(0x1b,&uStack_54);
      uVar10 = esp_err_to_zcl_status();
      pcVar11 = (code *)0x0;
      uVar10 = uVar10 & 0xff;
      goto _L0;
    }
    if (bStack_24 == 0) {
      uStack_50 = (uint)uStack_28 << 0x10;
      uStack_54 = 0;
      uStack_4c = 0;
      uStack_50 = CONCAT31(uStack_50._1_3_,bStack_29);
      puVar6 = (undefined3 *)zb_buf_begin_func(param_1);
      uStack_4c = CONCAT13(uStack_4c._3_1_,*puVar6);
      iVar5 = esp_zb_has_core_action_handler();
      if (iVar5 != 0) {
        esp_zb_core_action_handler_schedule(0x1a,&uStack_54);
      }
      if ((((DAT_00010db0 >> 8 & 0xff) == 2) && ((DAT_00010db0 & 0xff) == 2)) &&
         ((DAT_00010db0 & 0xffff00) != 0x100)) {
        DAT_00010e04 = 0;
        DAT_00010e00 = (uStack_4c >> 8 & 0xff) * 1000;
        uVar7 = zb_random_jitter();
        pcVar11 = esp_zcl_commissioning_process_restart_device_continue;
        uVar10 = 0;
        uVar7 = uVar7 / (0xffffffff / ((uStack_4c >> 0x10 & 0xff) * 0x50));
        DAT_00010e00 = DAT_00010e00 + uVar7;
        DAT_00010e04 = (uint)(DAT_00010e00 < uVar7) + DAT_00010e04;
        DAT_00010e08 = (byte)uStack_4c & 7;
        DAT_00010e09 = (byte)(uStack_4c >> 3) & 1;
      }
      else {
        uVar9 = esp_log_timestamp();
        esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING","E (%lu) %s: Invalid Startup Parameter Set\n",uVar9
                ,"ESP_ZIGBEE_ZCL_COMMISSIONING");
        pcVar11 = (code *)0x0;
        uVar10 = 1;
      }
      goto _L0;
    }
    uStack_50 = (uint)uStack_28 << 0x10;
    uStack_44 = 0x81;
    uStack_54 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_50 = CONCAT31(uStack_50._1_3_,bStack_29);
    iVar5 = zb_buf_begin_func(param_1);
    uStack_4c = 0;
    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(iVar5 + 1));
  }
  esp_zb_core_action_handler_schedule(0x1b,&uStack_54);
  uVar10 = uStack_44 & 0xff;
  pcVar11 = (code *)0x0;
_L0:
  esp_zcl_commissioning_srv_send_response(param_1,auStack_40,uVar10,pcVar11);
  return 1;
}

