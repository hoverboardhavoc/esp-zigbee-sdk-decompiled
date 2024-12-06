/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zb_zcl_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_scene_resp_handler(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined2 *puVar7;
  void *__dest;
  byte bVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint auStack_4c [8];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte *pbStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (((iVar2 == 0) || (*(char *)(iVar2 + 0x14) != '\x01')) ||
     (iVar3 = esp_zb_has_core_action_handler(), iVar3 == 0)) {
    return 0;
  }
  bVar8 = *(byte *)(iVar2 + 0x13);
  bVar1 = true;
  if (bVar8 == 3) {
    iVar4 = zb_zcl_basic_message_create(param_1,auStack_4c);
    if (iVar4 != 0) goto _L0;
    uVar5 = zb_buf_len_func(param_1);
    if (uVar5 < 3) {
      pbVar6 = (byte *)0x0;
      auStack_4c[0] = 1;
    }
    else {
      pbVar6 = (byte *)zb_buf_begin_func(param_1);
      auStack_4c[0] = 1;
      if (pbVar6 != (byte *)0x0) {
        auStack_4c[0] = (uint)*pbVar6;
      }
    }
    if (pbVar6 == (byte *)0x0) {
      uStack_2c = 0xffff;
    }
    else {
      uStack_2c = *(undefined2 *)(pbVar6 + 1);
    }
    bVar8 = 0xff;
_L0:
    uStack_2a = CONCAT11(uStack_2a._1_1_,bVar8);
    iVar4 = esp_zb_core_action_handler_schedule(0x1020,auStack_4c);
  }
  else {
    if (3 < bVar8) {
      if (bVar8 != 4) {
        if (bVar8 != 6) {
          return 0;
        }
        iVar4 = zb_zcl_basic_message_create(param_1,auStack_4c);
        if (iVar4 == 0) {
          uVar5 = zb_buf_len_func(param_1);
          if (uVar5 < 6) {
            pbStack_24 = (byte *)0x0;
            auStack_4c[0] = 1;
          }
          else {
            pbStack_24 = (byte *)zb_buf_begin_func(param_1);
            auStack_4c[0] = 1;
            if (pbStack_24 != (byte *)0x0) {
              auStack_4c[0] = (uint)*pbStack_24;
            }
          }
          bVar8 = 0;
          if (pbStack_24 != (byte *)0x0) {
            bVar8 = pbStack_24[1];
          }
          uStack_2c = CONCAT11(uStack_2c._1_1_,bVar8);
          if (pbStack_24 == (byte *)0x0) {
            uStack_2a = 0xffff;
          }
          else {
            uStack_2a = *(undefined2 *)(pbStack_24 + 2);
          }
          bVar8 = 0;
          if (pbStack_24 != (byte *)0x0) {
            bVar8 = pbStack_24[4];
          }
          uStack_28 = CONCAT11(uStack_28._1_1_,bVar8);
          if (pbStack_24 != (byte *)0x0) {
            pbStack_24 = pbStack_24 + 5;
          }
          esp_zb_core_action_handler_schedule(0x1022,auStack_4c);
        }
_L0:
        bVar1 = false;
        goto _L0;
      }
_L0:
      iVar4 = zb_zcl_basic_message_create(param_1,auStack_4c);
      if (iVar4 != 0) goto _L0;
      uVar5 = zb_buf_len_func(param_1);
      if (uVar5 < 4) {
        pbVar6 = (byte *)0x0;
        auStack_4c[0] = 1;
      }
      else {
        pbVar6 = (byte *)zb_buf_begin_func(param_1);
        auStack_4c[0] = 1;
        if (pbVar6 != (byte *)0x0) {
          auStack_4c[0] = (uint)*pbVar6;
        }
      }
      if (pbVar6 == (byte *)0x0) {
        uStack_2c = 0xffff;
      }
      else {
        uStack_2c = *(undefined2 *)(pbVar6 + 1);
      }
      bVar8 = 0xff;
      if (pbVar6 != (byte *)0x0) {
        bVar8 = pbVar6[3];
      }
      goto _L0;
    }
    if (bVar8 != 1) goto _L0;
    uVar5 = zb_buf_len_func(param_1);
    if (uVar5 < 4) goto _L0;
    pbVar6 = (byte *)zb_buf_begin_func(param_1);
    if (*pbVar6 == 0) {
      zb_buf_cut_left_func(param_1,pbVar6[6] + 7);
      pbVar6[6] = 0;
    }
    else {
      zb_buf_cut_left_func(param_1,4);
    }
    iVar4 = zb_zcl_basic_message_create(param_1,auStack_4c);
    if (iVar4 != 0) goto _L0;
    auStack_4c[0] = (uint)*pbVar6;
    uStack_2c = *(undefined2 *)(pbVar6 + 1);
    uStack_2a = CONCAT11(uStack_2a._1_1_,pbVar6[3]);
    uStack_28 = *(undefined2 *)(pbVar6 + 4);
    pbStack_24 = (byte *)0x0;
    pbVar6 = (byte *)0x0;
    pbVar9 = pbStack_24;
    while (pbStack_24 = pbVar9, pbVar10 = pbVar6, uVar5 = zb_buf_len_func(param_1), 2 < uVar5) {
      puVar7 = (undefined2 *)zb_buf_begin_func(param_1);
      bVar8 = *(byte *)(puVar7 + 1);
      uVar5 = zb_buf_len_func(param_1);
      if (uVar5 < bVar8 + 3) break;
      zb_buf_cut_left_func(param_1);
      pbVar6 = (byte *)malloc(0xc);
      *(undefined2 *)pbVar6 = *puVar7;
      bVar8 = *(byte *)(puVar7 + 1);
      pbVar6[2] = bVar8;
      __dest = malloc((uint)bVar8);
      *(void **)(pbVar6 + 4) = __dest;
      memcpy(__dest,(void *)((int)puVar7 + 3),(uint)bVar8);
      pbVar6[8] = 0;
      pbVar6[9] = 0;
      pbVar6[10] = 0;
      pbVar6[0xb] = 0;
      pbVar9 = pbVar6;
      if (pbVar10 != (byte *)0x0) {
        *(byte **)(pbVar10 + 8) = pbVar6;
        pbVar9 = pbStack_24;
      }
    }
    iVar4 = esp_zb_core_action_handler_schedule(0x1021,auStack_4c);
    pbVar6 = pbStack_24;
    while (pbVar6 != (byte *)0x0) {
      pbVar9 = *(byte **)(pbVar6 + 8);
      free(pbVar6);
      pbVar6 = pbVar9;
    }
  }
  bVar1 = iVar4 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar2,bVar1);
  return iVar3;
}

