/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_tmq_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_tmq_handle_timer(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = micro_timer_get_now();
  puVar1 = (undefined4 *)*param_1;
  while ((puVar1 != param_1 && (-1 < iVar2 - puVar1[6]))) {
    puVar3 = (undefined4 *)puVar1[1];
    zmsg_queue_dequeue(param_1,puVar1);
    if ((code *)param_1[7] == (code *)0x0) {
      zmsg_free(puVar1);
    }
    else {
      (*(code *)param_1[7])(puVar1);
    }
    puVar1 = (undefined4 *)*puVar3;
  }
  iVar2 = zmsg_tmque_get_head(param_1);
  if (iVar2 != 0) {
    micro_timer_fire_at(param_1 + 3,*(undefined4 *)(iVar2 + 0x18));
  }
  return;
}

