/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zigbee_task_queue_post(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (s_task_queue != 0) {
    iStack_1c = 0;
    uStack_18 = param_1;
    uStack_14 = param_2;
    if (_DAT_600c2194 < 2) {
      iVar1 = xQueueGenericSend(&uStack_18,10,0);
    }
    else {
      iVar1 = xQueueGenericSendFromISR(&uStack_18,&iStack_1c);
    }
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      ezb_tasklet_signal_pending();
      if (iStack_1c != 0) {
        vPortYieldFromISR();
      }
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x103;
}

