/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_device_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_bind_req(void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined2 uStack_44;
  undefined1 auStack_42 [8];
  undefined1 uStack_3a;
  undefined2 uStack_38;
  char cStack_36;
  undefined2 auStack_34 [4];
  undefined1 uStack_2c;
  code *pcStack_28;
  undefined4 *puStack_24;
  
  memset(&uStack_44,0,0x24);
  if ((param_1 != (void *)0x0) &&
     (puVar1 = (undefined4 *)calloc(1,0xc), puVar1 != (undefined4 *)0x0)) {
    uStack_44 = *(undefined2 *)((int)param_1 + 0x18);
    puVar1[1] = param_3;
    *puVar1 = param_2;
    memcpy(auStack_42,param_1,8);
    uStack_3a = *(undefined1 *)((int)param_1 + 8);
    cStack_36 = *(char *)((int)param_1 + 0xc);
    uStack_38 = *(undefined2 *)((int)param_1 + 10);
    if (cStack_36 == '\x01') {
      auStack_34[0] = *(undefined2 *)((int)param_1 + 0xe);
    }
    else {
      memcpy(auStack_34,(void *)((int)param_1 + 0xe),8);
    }
    uStack_2c = *(undefined1 *)((int)param_1 + 0x16);
    pcStack_28 = esp_zb_zdo_bind_rsp_wrapper;
    puStack_24 = puVar1;
    ezb_zdo_bind_req(&uStack_44);
  }
  return;
}

