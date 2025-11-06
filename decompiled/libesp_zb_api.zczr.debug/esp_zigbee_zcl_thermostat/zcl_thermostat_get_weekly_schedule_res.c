/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_thermostat.o -> zcl_thermostat_get_weekly_schedule_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_thermostat_get_weekly_schedule_res(int param_1)

{
  int unaff_s0;
  uint uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  void *__src;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  uint unaff_s3;
  uint unaff_s4;
  undefined4 uStack_54;
  undefined2 uStack_50;
  byte bStack_4c;
  byte bStack_4b;
  byte bStack_4a;
  uint auStack_48 [8];
  undefined4 uStack_28;
  undefined2 *puStack_24;
  
  if (param_1 == 0) {
    zb_assert(0x10000,0x7b);
  }
  else {
    auStack_48[0] = 0;
    auStack_48[1] = 0;
    auStack_48[2] = 0;
    auStack_48[3] = 0;
    auStack_48[4] = 0;
    auStack_48[5] = 0;
    auStack_48[6] = 0;
    auStack_48[7] = 0;
    uStack_28 = 0;
    puStack_24 = (undefined2 *)0x0;
    unaff_s0 = zb_zcl_basic_message_create();
    if (unaff_s0 == 0) {
      uVar1 = zb_buf_len_func(param_1);
      if ((uVar1 < 3) || (pbVar4 = (byte *)zb_buf_begin_func(param_1), pbVar4 == (byte *)0x0)) {
        auStack_48[0] = 1;
      }
      else {
        bStack_4c = *pbVar4;
        bStack_4b = pbVar4[1];
        bStack_4a = pbVar4[2];
        if (10 < bStack_4c) {
          zb_assert(0x10000,0x82);
          puVar2 = (undefined2 *)0x0;
          goto _L0;
        }
        auStack_48[0] = 0;
        zb_buf_cut_left_func(param_1,3);
      }
      if (auStack_48[0] == 0) {
        uVar1 = (uint)bStack_4c;
        unaff_s4 = (uint)bStack_4a;
        uStack_28 = CONCAT22(CONCAT11(uStack_28._3_1_,bStack_4a),CONCAT11(bStack_4b,bStack_4c));
        puVar2 = (undefined2 *)calloc(uVar1,6);
        unaff_s3 = 0;
        uVar3 = extraout_a1;
        puStack_24 = puVar2;
        if ((uVar1 != 0) && (puVar2 == (undefined2 *)0x0)) {
          uVar3 = esp_log_timestamp();
          esp_log(1,"ESP_ZIGBEE_ZCL_THERMOSTAT",
                  "E (%lu) %s: %s(%d): No memory for Get Thermostat Weekly Schedule response\n",
                  uVar3,"ESP_ZIGBEE_ZCL_THERMOSTAT","zcl_thermostat_get_weekly_schedule_res",0x88);
          return 0x101;
        }
        while ((iVar6 = zb_buf_len_func(param_1,uVar3), iVar6 != 0 && (unaff_s3 == 0))) {
          uStack_54 = 0;
          uStack_50 = 0;
          if (unaff_s4 == 3) {
_L0:
            uVar1 = 6;
          }
          else {
            uVar1 = 4;
          }
          uVar5 = zb_buf_len_func(param_1);
          if (uVar5 < uVar1) {
            unaff_s3 = 1;
            uVar3 = extraout_a1_00;
          }
          else {
            __src = (void *)zb_buf_begin_func(param_1);
            if (__src == (void *)0x0) {
              unaff_s3 = 1;
              uVar3 = 0;
            }
            else {
              memcpy(&uStack_54,__src,uVar1);
              if (unaff_s4 == 2) {
                uStack_50 = uStack_54._2_2_;
              }
              uVar3 = zb_buf_cut_left_func(param_1,uVar1);
            }
          }
          *puVar2 = (undefined2)uStack_54;
          puVar2[2] = uStack_50;
          puVar2[1] = uStack_54._2_2_;
          puVar2 = puVar2 + 3;
        }
        auStack_48[0] = unaff_s3 & 1;
      }
      iVar6 = esp_zb_core_action_handler_schedule(0x1070,auStack_48);
      if (puStack_24 == (undefined2 *)0x0) {
        return iVar6;
      }
      free(puStack_24);
      return iVar6;
    }
  }
  uVar3 = esp_log_timestamp();
  esp_log(1,"ESP_ZIGBEE_ZCL_THERMOSTAT",
          "E (%lu) %s: %s(%d): Failed to create Get Thermostat Weekly Schedule Response message\n",
          uVar3,"ESP_ZIGBEE_ZCL_THERMOSTAT","zcl_thermostat_get_weekly_schedule_res",0x81);
  return unaff_s0;
}

