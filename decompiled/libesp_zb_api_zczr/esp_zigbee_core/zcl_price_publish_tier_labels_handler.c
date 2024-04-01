/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_price_publish_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_publish_tier_labels_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
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
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar5 + 0x10);
  puVar3 = *(undefined1 **)((int)puVar1 + 0xf);
  memset(auStack_2c,0,0x1c);
  uStack_28 = *(undefined1 *)(iVar4 + 4);
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
    for (iVar4 = 0; iVar4 < (int)(uint)bStack_16; iVar4 = iVar4 + 1) {
      puVar6 = (undefined1 *)((int)pvStack_14 + iVar4 * 0xe);
      *puVar6 = *puVar3;
      memcpy(puVar6 + 1,puVar3 + 1,(byte)puVar3[1] + 1);
      puVar3 = puVar3 + ((byte)puVar3[1] + 2) * 0xe;
    }
  }
  uVar2 = 0;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0x18,auStack_2c);
    uVar2 = esp_err_to_zb_ret();
  }
  free(pvStack_14);
  return uVar2;
}

