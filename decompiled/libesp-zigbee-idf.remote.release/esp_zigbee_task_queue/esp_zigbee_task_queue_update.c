/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_task_queue_update(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = s_task_queue_event_fd;
  if (-1 < (int)s_task_queue_event_fd) {
    if (s_task_queue_event_fd < 0x40) {
      puVar3 = (uint *)(((int)s_task_queue_event_fd >> 5) * 4 + param_1);
      *puVar3 = *puVar3 | 1 << (s_task_queue_event_fd & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  iVar2 = ezb_tasklet_has_pendings();
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}

