/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zigbee_task_queue_process(int param_1)

{
  ssize_t sVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (((s_task_queue_event_fd < 0x40) &&
      ((1 << (s_task_queue_event_fd & 0x1f) &
       *(uint *)(param_1 + ((int)s_task_queue_event_fd >> 5) * 4)) != 0)) &&
     (sVar1 = read(s_task_queue_event_fd,&pcStack_18,8), sVar1 != 8)) {
    __assert_func(0,0,0,0);
  }
  ezb_tasklet_process();
  uVar2 = 0x103;
  if (s_task_queue != 0) {
    while (iVar3 = xQueueReceive(s_task_queue,&pcStack_18,0), iVar3 == 1) {
      (*pcStack_18)(uStack_14,pcStack_18);
    }
    uVar2 = 0;
  }
  return uVar2;
}

