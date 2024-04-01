/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_group_cluster_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_group_cluster_resp_handler(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined1 uVar9;
  uint auStack_48 [8];
  undefined2 uStack_28;
  byte *pbStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x1b);
  if (iVar4 == 0) {
    return 0;
  }
  if (*(char *)(iVar4 + 0x14) != '\x01') {
    return 0;
  }
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x13);
  bVar2 = true;
  if (bVar1 == 2) {
    zb_buf_begin_func(param_1);
    iVar5 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar5 != 0) goto _L0;
    uVar6 = zb_buf_len_func(param_1);
    if (((uVar6 < 2) ||
        (puVar3 = (undefined1 *)zb_buf_begin_func(param_1), puVar3 == (undefined1 *)0x0)) ||
       (bVar1 = puVar3[1], uVar6 = zb_buf_len_func(param_1), uVar6 < ((bVar1 + 1) * 2 & 0xff))) {
      auStack_48[0] = 1;
      uStack_28._1_1_ = 0;
      uVar6 = 0;
      puVar3 = (undefined1 *)0x0;
      uVar9 = 0;
    }
    else {
      uStack_28._1_1_ = puVar3[1];
      uVar6 = (uint)uStack_28._1_1_;
      auStack_48[0] = 0;
      uVar9 = *puVar3;
    }
    uStack_28 = CONCAT11(uStack_28._1_1_,uVar9);
    pbStack_24 = (byte *)malloc(uVar6 << 1);
    iVar5 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      for (; iVar5 < (int)(uint)(byte)puVar3[1]; iVar5 = iVar5 + 1) {
        *(undefined2 *)(pbStack_24 + iVar5 * 2) = *(undefined2 *)(puVar3 + iVar5 * 2 + 2);
      }
    }
    iVar5 = (*zb_core_action_cb)(0x1012,auStack_48,zb_core_action_cb);
    free(pbStack_24);
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 == 0) goto _L0;
      iVar5 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar5 != 0) goto _L0;
      uVar6 = zb_buf_len_func(param_1);
      if ((uVar6 < 4) ||
         (pbStack_24 = (byte *)zb_buf_begin_func(param_1), pbStack_24 == (byte *)0x0)) {
        auStack_48[0] = 1;
        uStack_28 = 0xffff;
        pbStack_24 = (byte *)0x0;
      }
      else {
        auStack_48[0] = (uint)*pbStack_24;
        uStack_28 = *(undefined2 *)(pbStack_24 + 1);
        pbStack_24 = pbStack_24 + 3;
      }
      uVar7 = 0x1011;
    }
    else {
      if (bVar1 != 3) {
        return 0;
      }
_L0:
      iVar5 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar5 != 0) goto _L0;
      uVar6 = zb_buf_len_func(param_1);
      if ((uVar6 < 3) || (pbVar8 = (byte *)zb_buf_begin_func(param_1), pbVar8 == (byte *)0x0)) {
        auStack_48[0] = 1;
        uStack_28 = 0xffff;
      }
      else {
        auStack_48[0] = (uint)*pbVar8;
        uStack_28 = *(undefined2 *)(pbVar8 + 1);
      }
      uVar7 = 0x1010;
    }
    iVar5 = (*zb_core_action_cb)(uVar7,auStack_48,zb_core_action_cb);
  }
  bVar2 = iVar5 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar4,bVar2);
  return 1;
}

