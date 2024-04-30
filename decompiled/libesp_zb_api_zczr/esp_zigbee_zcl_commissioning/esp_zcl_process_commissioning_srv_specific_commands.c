/*
 * Last changed at upstream commit f681c92f221e08b8a4008d1df363fb1f9960ae64
 * https://github.com/espressif/esp-zigbee-sdk/commit/f681c92f221e08b8a4008d1df363fb1f9960ae64
 * Upstream date: 2024-04-30 13:18:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.1(ce7ce7c1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_srv_specific_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zcl_process_commissioning_srv_specific_commands(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined3 *puVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  uint uVar9;
  code *pcVar10;
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
    iVar4 = zb_zcl_get_ctx();
    *(undefined1 **)(iVar4 + 0x240) = s_commissioning_server_cmd_list;
    return 1;
  }
  iVar4 = zb_zcl_basic_message_create(auStack_40);
  if (iVar4 != 0) {
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
    iVar4 = zb_buf_begin_func(param_1);
    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(iVar4 + 1));
    uStack_4c = 1;
  }
  else {
    if (2 < bStack_24) {
      if (bStack_24 != 3) {
        return 0;
      }
      uStack_50 = CONCAT22(uStack_28,(ushort)bStack_29);
      uStack_54 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      pbVar7 = (byte *)zb_buf_begin_func(param_1);
      bVar1 = *pbVar7;
      if ((bVar1 & 1) == 0) {
        if ((bVar1 & 2) != 0) goto _L0;
        uStack_4c = ((bVar1 & 4) == 0) + 2;
        uStack_48 = CONCAT31(uStack_48._1_3_,pbVar7[1]);
      }
      else {
        uVar2 = esp_zb_get_short_address();
        uVar3 = esp_zb_get_pan_id();
        DAT_00010d9c = zb_get_channel_mask();
        DAT_00010d92 = 0xffff;
        DAT_00010d94 = 0xffffffff;
        DAT_00010d98 = 0xffff;
        _g_comm_ctx = uVar2;
        DAT_00010d9a = uVar3;
        memset(&DAT_00010da0,0,0x40);
        DAT_00010da0 = 0x30202;
        DAT_00010dcb = 1;
        DAT_00010ddd = 1;
        if ((bVar1 & 2) != 0) {
_L0:
          uStack_4c = 4;
        }
      }
      esp_zb_core_action_handler_schedule(0x1b,&uStack_54);
      uVar9 = esp_err_to_zcl_status();
      pcVar10 = (code *)0x0;
      uVar9 = uVar9 & 0xff;
      goto _L0;
    }
    if (bStack_24 == 0) {
      uStack_50 = (uint)uStack_28 << 0x10;
      uStack_54 = 0;
      uStack_4c = 0;
      uStack_50 = CONCAT31(uStack_50._1_3_,bStack_29);
      puVar5 = (undefined3 *)zb_buf_begin_func(param_1);
      uStack_4c = CONCAT13(uStack_4c._3_1_,*puVar5);
      iVar4 = esp_zb_has_core_action_handler();
      if (iVar4 != 0) {
        esp_zb_core_action_handler_schedule(0x1a,&uStack_54);
      }
      if ((((DAT_00010da0 >> 8 & 0xff) == 2) && ((DAT_00010da0 & 0xff) == 2)) &&
         ((DAT_00010da0 & 0xffff00) != 0x100)) {
        DAT_00010df4 = 0;
        DAT_00010df0 = (uStack_4c >> 8 & 0xff) * 1000;
        uVar6 = zb_random_jitter();
        pcVar10 = esp_zcl_commissioning_process_restart_device_continue;
        uVar9 = 0;
        uVar6 = uVar6 / (0xffffffff / ((uStack_4c >> 0x10 & 0xff) * 0x50));
        DAT_00010df0 = DAT_00010df0 + uVar6;
        DAT_00010df4 = (uint)(DAT_00010df0 < uVar6) + DAT_00010df4;
        DAT_00010df8 = (byte)uStack_4c & 7;
        DAT_00010df9 = (byte)(uStack_4c >> 3) & 1;
      }
      else {
        uVar8 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar8,"ESP_ZIGBEE_ZCL_COMMISSIONING");
        pcVar10 = (code *)0x0;
        uVar9 = 1;
      }
      goto _L0;
    }
    uStack_50 = (uint)uStack_28 << 0x10;
    uStack_44 = 0x81;
    uStack_54 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_50 = CONCAT31(uStack_50._1_3_,bStack_29);
    iVar4 = zb_buf_begin_func(param_1);
    uStack_4c = 0;
    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(iVar4 + 1));
  }
  esp_zb_core_action_handler_schedule(0x1b,&uStack_54);
  uVar9 = uStack_44 & 0xff;
  pcVar10 = (code *)0x0;
_L0:
  esp_zcl_commissioning_srv_send_response(param_1,auStack_40,uVar9,pcVar10);
  return 1;
}

