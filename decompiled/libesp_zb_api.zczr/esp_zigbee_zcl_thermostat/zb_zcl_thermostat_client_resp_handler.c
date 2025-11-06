/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_thermostat.o -> zb_zcl_thermostat_client_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_thermostat_client_resp_handler(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  void *__src;
  undefined4 uVar10;
  void *extraout_a1;
  void *extraout_a1_00;
  byte unaff_s2;
  uint unaff_s6;
  size_t unaff_s7;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined4 local_60;
  undefined2 uStack_5c;
  int aiStack_58 [8];
  undefined1 uStack_38;
  byte bStack_37;
  undefined1 uStack_36;
  undefined2 *puStack_34;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if ((((iVar2 == 0) || (*(char *)(iVar2 + 0x14) != '\x01')) ||
      (iVar3 = esp_zb_has_core_action_handler(), iVar3 == 0)) || (*(char *)(iVar2 + 0x13) != '\0'))
  {
    return 0;
  }
  uVar10 = 0x7b;
  bVar1 = true;
  if (param_1 == 0) {
_L53:
    zb_assert(0x10000,uVar10);
_L0:
    aiStack_58[0] = 0;
    zb_buf_cut_left_func(param_1,3);
    iVar4 = aiStack_58[0];
    if (aiStack_58[0] == 0) {
      uStack_38 = (undefined1)unaff_s7;
      uStack_36 = (undefined1)unaff_s6;
      bStack_37 = unaff_s2;
      puVar7 = (undefined2 *)calloc(unaff_s7,6);
      puStack_34 = puVar7;
      if ((unaff_s7 != 0) && (puVar7 == (undefined2 *)0x0)) goto _L0;
      uVar5 = (-(uint)(unaff_s6 != 3) & 0xfffffffe) + 6;
      __src = extraout_a1;
      while ((iVar8 = zb_buf_len_func(param_1,__src), iVar8 != 0 && (iVar4 == 0))) {
        local_60 = 0;
        uStack_5c = 0;
        uVar9 = zb_buf_len_func(param_1);
        __src = extraout_a1_00;
        if ((uVar9 < uVar5) || (__src = (void *)zb_buf_begin_func(param_1), __src == (void *)0x0)) {
          uVar12 = 0;
          uVar11 = 0;
          iVar4 = 1;
        }
        else {
          memcpy(&local_60,__src,uVar5);
          uVar11 = local_60._2_2_;
          uVar12 = local_60._2_2_;
          if (unaff_s6 != 2) {
            uVar12 = uStack_5c;
          }
          __src = (void *)zb_buf_cut_left_func(param_1,uVar5);
        }
        puVar7[2] = uVar12;
        puVar7[1] = uVar11;
        *puVar7 = (undefined2)local_60;
        puVar7 = puVar7 + 3;
      }
    }
  }
  else {
    memset(aiStack_58,0,0x28);
    iVar4 = zb_zcl_basic_message_create(param_1,aiStack_58);
    if (iVar4 != 0) goto _L0;
    uVar5 = zb_buf_len_func(param_1);
    if ((2 < uVar5) && (pbVar6 = (byte *)zb_buf_begin_func(param_1), pbVar6 != (byte *)0x0)) {
      unaff_s7 = (size_t)*pbVar6;
      unaff_s2 = pbVar6[1];
      unaff_s6 = (uint)pbVar6[2];
      if (10 < unaff_s7) {
        uVar10 = 0x82;
        goto _L53;
      }
      goto _L0;
    }
    aiStack_58[0] = 1;
    iVar4 = aiStack_58[0];
  }
  aiStack_58[0] = iVar4;
  iVar4 = esp_zb_core_action_handler_schedule(0x1070,aiStack_58);
  if (puStack_34 != (undefined2 *)0x0) {
    free(puStack_34);
  }
  bVar1 = iVar4 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar2,bVar1);
  return iVar3;
}

