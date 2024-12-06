/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_thermostat.o -> zb_zcl_thermostat_client_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_thermostat_client_resp_handler(int param_1)

{
  byte unaff_s1;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  void *__src;
  undefined4 uVar9;
  void *extraout_a1;
  void *extraout_a1_00;
  bool bVar10;
  size_t unaff_s3;
  uint unaff_s7;
  undefined4 local_60;
  undefined2 uStack_5c;
  int aiStack_58 [8];
  undefined1 uStack_38;
  byte bStack_37;
  undefined1 uStack_36;
  undefined2 *puStack_34;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if ((((iVar1 == 0) || (*(char *)(iVar1 + 0x14) != '\x01')) ||
      (iVar2 = esp_zb_has_core_action_handler(), iVar2 == 0)) || (*(char *)(iVar1 + 0x13) != '\0'))
  {
    return 0;
  }
  uVar9 = 0x7b;
  bVar10 = true;
  if (param_1 == 0) {
_L53:
    zb_assert(0x10000,uVar9);
_L0:
    aiStack_58[0] = 0;
    zb_buf_cut_left_func(param_1,3);
    iVar3 = aiStack_58[0];
    if (aiStack_58[0] == 0) {
      uStack_38 = (undefined1)unaff_s3;
      uStack_36 = (undefined1)unaff_s7;
      bStack_37 = unaff_s1;
      puVar6 = (undefined2 *)calloc(unaff_s3,6);
      puStack_34 = puVar6;
      if ((unaff_s3 != 0) && (puVar6 == (undefined2 *)0x0)) goto _L0;
      uVar4 = 4;
      __src = extraout_a1;
      if (unaff_s7 == 3) {
        uVar4 = 6;
      }
      while ((iVar7 = zb_buf_len_func(param_1,__src), iVar7 != 0 && (iVar3 == 0))) {
        local_60 = 0;
        uStack_5c = 0;
        uVar8 = zb_buf_len_func(param_1);
        __src = extraout_a1_00;
        if ((uVar8 < uVar4) || (__src = (void *)zb_buf_begin_func(param_1), __src == (void *)0x0)) {
          iVar3 = 1;
        }
        else {
          memcpy(&local_60,__src,uVar4);
          if (unaff_s7 == 2) {
            uStack_5c = local_60._2_2_;
          }
          __src = (void *)zb_buf_cut_left_func(param_1,uVar4);
        }
        *puVar6 = (undefined2)local_60;
        puVar6[2] = uStack_5c;
        puVar6[1] = local_60._2_2_;
        puVar6 = puVar6 + 3;
      }
    }
  }
  else {
    memset(aiStack_58,0,0x28);
    iVar3 = zb_zcl_basic_message_create(param_1,aiStack_58);
    if (iVar3 != 0) goto _L0;
    uVar4 = zb_buf_len_func(param_1);
    if ((2 < uVar4) && (pbVar5 = (byte *)zb_buf_begin_func(param_1), pbVar5 != (byte *)0x0)) {
      unaff_s3 = (size_t)*pbVar5;
      unaff_s1 = pbVar5[1];
      unaff_s7 = (uint)pbVar5[2];
      if (10 < unaff_s3) {
        uVar9 = 0x82;
        goto _L53;
      }
      goto _L0;
    }
    aiStack_58[0] = 1;
    iVar3 = aiStack_58[0];
  }
  aiStack_58[0] = iVar3;
  iVar3 = esp_zb_core_action_handler_schedule(0x1070,aiStack_58);
  if (puStack_34 != (undefined2 *)0x0) {
    free(puStack_34);
  }
  bVar10 = iVar3 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar1,bVar10);
  return iVar2;
}

