/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_get_scheduled_prices_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_scheduled_prices_handler(undefined4 *param_1,code *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined2 *puVar3;
  undefined2 uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  undefined1 auStack_5c [60];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  
  iStack_14 = 0;
  uStack_20 = *param_1;
  uStack_1c = param_1[3];
  uStack_18 = (uint)*(byte *)(param_1 + 4);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4c,&uStack_20,param_2);
    uVar2 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 5) = uVar2;
  }
  if (uStack_18._1_1_ == '\0') {
    *(undefined1 *)(param_1 + 5) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 5) = 0;
    memset(&uStack_74,0,0x54);
    puVar3 = (undefined2 *)param_1[2];
    uStack_74 = *puVar3;
    uStack_72 = puVar3[1];
    uStack_70 = puVar3[2];
    uStack_6e = puVar3[3];
    uStack_6c = puVar3[4];
    uStack_6a = *(undefined1 *)(puVar3 + 10);
    uStack_69 = *(undefined1 *)((int)puVar3 + 0x15);
    for (uVar1 = 0; uVar1 < (uStack_18 >> 8 & 0xff); uVar1 = uVar1 + 1 & 0xffff) {
      memcpy(auStack_5c,(void *)(iStack_14 + uVar1 * 0x3b),0x3b);
      ezb_zcl_price_publish_price_cmd_req(&uStack_74);
    }
  }
  return;
}

