/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_touchlink_commissioning.o -> zcl_touchlink_get_endpoint_list_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_touchlink_get_endpoint_list_req_handler(undefined4 param_1)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  void *__src;
  int iVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined1 auStack_3f [10];
  undefined1 uStack_35;
  undefined1 uStack_2b;
  byte bStack_23;
  
  uVar4 = zb_buf_get_out_func();
  __src = (void *)zb_buf_get_tail_func(param_1,0x1b);
  memcpy(&uStack_40,__src,0x1b);
  iVar5 = zb_buf_len_func(param_1);
  if (iVar5 == 1) {
    pbVar6 = (byte *)zb_buf_begin_func(param_1);
    bVar1 = *pbVar6;
    uVar8 = (uint)bVar1;
    bStack_23 = bVar1;
    iVar5 = zb_zcl_get_ctx();
    if (*(int *)(iVar5 + 4) == 0) {
      uVar9 = 0;
    }
    else {
      iVar5 = zb_zcl_get_ctx();
      uVar9 = **(undefined1 **)(iVar5 + 4);
    }
    uVar3 = 0;
    for (; uVar8 < 0x10; uVar8 = uVar8 + 1 & 0xff) {
      if (zb_touchlink_device_endpoint_information_record_list[uVar8 * 0x12 + 0x11] != '\0') {
        uVar3 = uVar3 + 1 & 0xff;
      }
    }
    puVar7 = (undefined1 *)zb_buf_reuse_func(uVar4);
    *puVar7 = 0x19;
    puVar7[1] = uStack_2b;
    puVar7[2] = 0x42;
    puVar7[3] = uVar9;
    puVar7[4] = bVar1;
    puVar7[5] = (char)uVar3;
    puVar7 = puVar7 + 6;
    for (uVar8 = 0; uVar8 < uVar3; uVar8 = uVar8 + 1 & 0xff) {
      iVar5 = uVar8 * 0x12;
      uVar2 = *(undefined2 *)(zb_touchlink_device_endpoint_information_record_list + iVar5 + 8);
      uStack_42 = (undefined1)uVar2;
      *puVar7 = uStack_42;
      uStack_41 = (undefined1)((ushort)uVar2 >> 8);
      puVar7[1] = uStack_41;
      puVar7[2] = zb_touchlink_device_endpoint_information_record_list[iVar5 + 10];
      uVar2 = *(undefined2 *)(zb_touchlink_device_endpoint_information_record_list + iVar5 + 0xc);
      uStack_42 = (undefined1)uVar2;
      puVar7[3] = uStack_42;
      uStack_41 = (undefined1)((ushort)uVar2 >> 8);
      puVar7[4] = uStack_41;
      uVar2 = *(undefined2 *)(zb_touchlink_device_endpoint_information_record_list + iVar5 + 0xe);
      uStack_42 = (undefined1)uVar2;
      puVar7[5] = uStack_42;
      uStack_41 = (undefined1)((ushort)uVar2 >> 8);
      puVar7[6] = uStack_41;
      puVar7[7] = zb_touchlink_device_endpoint_information_record_list[uVar8 * 0x12 + 0x10];
      puVar7 = puVar7 + 8;
    }
    zb_zcl_finish_and_send_packet(uVar4,auStack_3f,2,uStack_35,0,0xc05e,0x1000);
    uVar4 = 0;
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC7,uVar4,0x10000);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

