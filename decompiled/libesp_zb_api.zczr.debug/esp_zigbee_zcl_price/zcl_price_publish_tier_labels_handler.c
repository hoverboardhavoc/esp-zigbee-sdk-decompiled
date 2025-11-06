/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_price.o -> zcl_price_publish_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_publish_tier_labels_handler(undefined4 param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uStack_2c;
  ushort uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar6 = *(undefined4 **)(iVar4 + 0x10);
  puVar2 = *(undefined1 **)((int)puVar6 + 0xf);
  uStack_2c = 0;
  pvStack_14 = (void *)0x0;
  _uStack_28 = CONCAT22(0x700,(ushort)*(byte *)(iVar3 + 4));
  uStack_24 = *puVar6;
  uStack_20 = puVar6[1];
  uStack_1c = puVar6[2];
  bVar1 = *(byte *)((int)puVar6 + 0xe);
  uStack_18 = (uint)CONCAT12(bVar1,(ushort)*(byte *)(puVar6 + 3));
  if (bVar1 != 0) {
    pvStack_14 = calloc((uint)bVar1,0xe);
    if (pvStack_14 == (void *)0x0) {
      uVar5 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_PRICE","E (%lu) %s: %s(%d): No memory for tier labels\n",uVar5,
              "ESP_ZIGBEE_ZCL_PRICE","zcl_price_publish_tier_labels_handler",0xdf);
      return 0xffffffea;
    }
    for (iVar3 = 0; iVar3 < (int)(uStack_18 >> 0x10 & 0xff); iVar3 = iVar3 + 1) {
      *(undefined1 *)((int)pvStack_14 + iVar3 * 0xe) = *puVar2;
      memcpy((void *)((int)pvStack_14 + iVar3 * 0xe + 1),puVar2 + 1,(byte)puVar2[1] + 1);
      puVar2 = puVar2 + ((byte)puVar2[1] + 2) * 0xe;
    }
  }
  esp_zb_core_action_handler_schedule(0x18,&uStack_2c);
  uVar5 = esp_err_to_zb_ret();
  free(pvStack_14);
  return uVar5;
}

