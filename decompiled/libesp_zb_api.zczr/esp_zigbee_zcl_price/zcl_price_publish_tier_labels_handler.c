/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_price.o -> zcl_price_publish_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_publish_tier_labels_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_2c [4];
  undefined1 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  byte bStack_16;
  void *pvStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar4 + 0x10);
  puVar2 = *(undefined1 **)((int)puVar1 + 0xf);
  memset(auStack_2c,0,0x1c);
  uStack_28 = *(undefined1 *)(iVar3 + 4);
  uStack_26 = 0x700;
  uStack_24 = *puVar1;
  uStack_20 = puVar1[1];
  uStack_1c = puVar1[2];
  uStack_18 = *(undefined1 *)(puVar1 + 3);
  bStack_16 = *(byte *)((int)puVar1 + 0xe);
  if (bStack_16 != 0) {
    pvStack_14 = calloc((uint)bStack_16,0xe);
    if (pvStack_14 == (void *)0x0) {
      return 0xffffffea;
    }
    for (iVar3 = 0; iVar3 < (int)(uint)bStack_16; iVar3 = iVar3 + 1) {
      puVar6 = (undefined1 *)((int)pvStack_14 + iVar3 * 0xe);
      *puVar6 = *puVar2;
      memcpy(puVar6 + 1,puVar2 + 1,(byte)puVar2[1] + 1);
      puVar2 = puVar2 + ((byte)puVar2[1] + 2) * 0xe;
    }
  }
  esp_zb_core_action_handler_schedule(0x18,auStack_2c);
  uVar5 = esp_err_to_zb_ret();
  free(pvStack_14);
  return uVar5;
}

