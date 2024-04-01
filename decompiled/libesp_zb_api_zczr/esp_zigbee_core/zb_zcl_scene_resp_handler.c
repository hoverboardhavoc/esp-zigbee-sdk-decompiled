/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_scene_resp_handler(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  void *__dest;
  byte *pbVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint auStack_4c [8];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte *pbStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar2 + 0x14) != '\x01') {
    return 0;
  }
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  bVar7 = *(byte *)(iVar2 + 0x13);
  bVar1 = true;
  if (bVar7 == 3) {
    iVar3 = zb_zcl_basic_message_create(param_1,auStack_4c);
    if (iVar3 != 0) goto _L0;
    uVar4 = zb_buf_len_func(param_1);
    if ((uVar4 < 3) || (pbVar6 = (byte *)zb_buf_begin_func(param_1), pbVar6 == (byte *)0x0)) {
      auStack_4c[0] = 1;
      uStack_2c = -1;
    }
    else {
      auStack_4c[0] = (uint)*pbVar6;
      uStack_2c = *(short *)(pbVar6 + 1);
    }
    bVar7 = 0xff;
_L0:
    uStack_2a = CONCAT11(uStack_2a._1_1_,bVar7);
    iVar3 = (*zb_core_action_cb)(0x1020,auStack_4c,zb_core_action_cb);
  }
  else {
    if (3 < bVar7) {
      if (bVar7 != 4) {
        if (bVar7 != 6) {
          return 0;
        }
        iVar3 = zb_zcl_basic_message_create(param_1,auStack_4c);
        if (iVar3 == 0) {
          uVar4 = zb_buf_len_func(param_1);
          if ((uVar4 < 6) ||
             (pbStack_24 = (byte *)zb_buf_begin_func(param_1), pbStack_24 == (byte *)0x0)) {
            auStack_4c[0] = 1;
            uStack_2a = 0xffff;
            uStack_2c = (ushort)uStack_2c._1_1_ << 8;
            bVar7 = 0;
            pbStack_24 = (byte *)0x0;
          }
          else {
            auStack_4c[0] = (uint)*pbStack_24;
            uStack_2c = CONCAT11(uStack_2c._1_1_,pbStack_24[1]);
            uStack_2a = *(undefined2 *)(pbStack_24 + 2);
            bVar7 = pbStack_24[4];
            pbStack_24 = pbStack_24 + 5;
          }
          uStack_28 = CONCAT11(uStack_28._1_1_,bVar7);
          (*zb_core_action_cb)(0x1022,auStack_4c,zb_core_action_cb);
        }
_L0:
        bVar1 = false;
        goto _L0;
      }
_L0:
      iVar3 = zb_zcl_basic_message_create(param_1,auStack_4c);
      if (iVar3 != 0) goto _L0;
      uVar4 = zb_buf_len_func(param_1);
      if ((uVar4 < 4) || (pbVar6 = (byte *)zb_buf_begin_func(param_1), pbVar6 == (byte *)0x0)) {
        auStack_4c[0] = 1;
        uStack_2c = -1;
        bVar7 = 0xff;
      }
      else {
        auStack_4c[0] = (uint)*pbVar6;
        uStack_2c = *(short *)(pbVar6 + 1);
        bVar7 = pbVar6[3];
      }
      goto _L0;
    }
    if (bVar7 != 1) goto _L0;
    uVar4 = zb_buf_len_func(param_1);
    if (uVar4 < 4) goto _L0;
    pbVar6 = (byte *)zb_buf_begin_func(param_1);
    if (*pbVar6 == 0) {
      zb_buf_cut_left_func(param_1,pbVar6[6] + 7);
      pbVar6[6] = 0;
    }
    else {
      zb_buf_cut_left_func(param_1,4);
    }
    iVar3 = zb_zcl_basic_message_create(param_1,auStack_4c);
    if (iVar3 != 0) goto _L0;
    auStack_4c[0] = (uint)*pbVar6;
    uStack_2c = *(short *)(pbVar6 + 1);
    uStack_2a = CONCAT11(uStack_2a._1_1_,pbVar6[3]);
    uStack_28 = *(undefined2 *)(pbVar6 + 4);
    pbStack_24 = (byte *)0x0;
    pbVar6 = (byte *)0x0;
    pbVar8 = pbStack_24;
    while (pbStack_24 = pbVar8, pbVar9 = pbVar6, uVar4 = zb_buf_len_func(param_1), 2 < uVar4) {
      puVar5 = (undefined2 *)zb_buf_begin_func(param_1);
      bVar7 = *(byte *)(puVar5 + 1);
      uVar4 = zb_buf_len_func(param_1);
      if (uVar4 < bVar7 + 3) break;
      zb_buf_cut_left_func(param_1);
      pbVar6 = (byte *)malloc(0xc);
      *(undefined2 *)pbVar6 = *puVar5;
      bVar7 = *(byte *)(puVar5 + 1);
      pbVar6[2] = bVar7;
      __dest = malloc((uint)bVar7);
      *(void **)(pbVar6 + 4) = __dest;
      memcpy(__dest,(void *)((int)puVar5 + 3),(uint)bVar7);
      pbVar6[8] = 0;
      pbVar6[9] = 0;
      pbVar6[10] = 0;
      pbVar6[0xb] = 0;
      pbVar8 = pbVar6;
      if (pbVar9 != (byte *)0x0) {
        *(byte **)(pbVar9 + 8) = pbVar6;
        pbVar8 = pbStack_24;
      }
    }
    iVar3 = (*zb_core_action_cb)(0x1021,auStack_4c,zb_core_action_cb);
    pbVar6 = pbStack_24;
    while (pbVar6 != (byte *)0x0) {
      pbVar8 = *(byte **)(pbVar6 + 8);
      free(pbVar6);
      pbVar6 = pbVar8;
    }
  }
  bVar1 = iVar3 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar2,bVar1);
  return 1;
}

