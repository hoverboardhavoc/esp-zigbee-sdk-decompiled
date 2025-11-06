/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_touchlink_commissioning.o -> zcl_touchlink_get_group_identifiers_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_touchlink_get_group_identifiers_req_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  void *__src;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 local_70 [64];
  uint uStack_30;
  undefined1 uStack_2c;
  undefined1 auStack_2b [10];
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined1 uStack_17;
  
  uVar3 = zb_buf_get_out_func();
  uStack_30 = 0;
  __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
  memcpy(&uStack_2c,__src,0x1b);
  iVar4 = zb_buf_len_func(param_1);
  if (iVar4 == 1) {
    puVar5 = (undefined1 *)zb_buf_begin_func(param_1);
    uVar1 = *puVar5;
    zb_apsme_get_groups_by_ep(0x20,local_70,&uStack_30,uStack_20);
    uVar2 = DAT_00012148;
    puVar5 = (undefined1 *)zb_buf_reuse_func(uVar3);
    *puVar5 = 0x19;
    puVar5[1] = uStack_17;
    puVar5[2] = 0x41;
    puVar5[3] = uVar2;
    puVar5[4] = uVar1;
    puVar5[5] = (char)uStack_30;
    puVar5 = puVar5 + 6;
    for (uVar6 = 0; uVar6 < uStack_30; uVar6 = uVar6 + 1 & 0xff) {
      *puVar5 = local_70[uVar6 * 2];
      puVar5[1] = local_70[uVar6 * 2 + 1];
      puVar5[2] = 0;
      puVar5 = puVar5 + 3;
    }
    zb_zcl_finish_and_send_packet(uVar3,auStack_2b,2,uStack_21,uStack_20,0xc05e,0x1000);
    uVar3 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log(1,0x10000,
            "E (%lu) %s: touchlink get group_identifiers request command wrong packet size\n",uVar3,
            0x10000);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

