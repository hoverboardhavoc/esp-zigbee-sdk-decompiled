/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_get_current_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_price_get_current_price_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined2 local_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined2 uStack_6a;
  undefined2 uStack_68;
  undefined1 uStack_66;
  undefined1 uStack_65;
  undefined1 auStack_58 [60];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  
  pvStack_14 = (void *)0x0;
  uStack_1c = *param_1;
  uStack_18 = (uint)*(byte *)(param_1 + 3);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4b,&uStack_1c,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 4) = uVar1;
  }
  if (uStack_18._1_1_ == '\0') {
    *(undefined1 *)(param_1 + 4) = 0x8b;
  }
  else {
    *(undefined1 *)(param_1 + 4) = 0;
    memset(&local_70,0,0x54);
    puVar2 = (undefined2 *)param_1[2];
    local_70 = *puVar2;
    uStack_6e = puVar2[1];
    uStack_6c = puVar2[2];
    uStack_6a = puVar2[3];
    uStack_68 = puVar2[4];
    uStack_66 = *(undefined1 *)(puVar2 + 10);
    uStack_65 = *(undefined1 *)((int)puVar2 + 0x15);
    memcpy(auStack_58,pvStack_14,0x3b);
    ezb_zcl_price_publish_price_cmd_req(&local_70);
  }
  return;
}

