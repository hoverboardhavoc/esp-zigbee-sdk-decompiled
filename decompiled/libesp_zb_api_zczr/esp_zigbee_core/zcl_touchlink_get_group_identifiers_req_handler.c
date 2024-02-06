/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_touchlink_get_group_identifiers_req_handler
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
    uVar2 = DAT_0001eac8;
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC29,uVar3,"ESP_ZIGBEE_CORE");
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

